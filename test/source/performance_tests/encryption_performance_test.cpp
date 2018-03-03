#include <x86intrin.h>
#include <iostream>
#include "encryption_performance_test.hpp"
#include <fstream>

EncryptionPerformanceTest::EncryptionPerformanceTest() : PerformanceTestBase(encrypt) {
    m_lengths = std::vector<int>(8);
    static int i = 8;
    std::generate(m_lengths.begin(), m_lengths.end(), [] {
        i *= 2;
        return i;
    });
    std::ofstream logs;
    logs.open(PERF_TEST_OUTPUT_FILE_NAME, std::ios::app);
    logs << "Function name,Length,CPE" << std::endl;
    logs.close();
}

void EncryptionPerformanceTest::before() {
    m_difference = ULONG_LONG_MAX;
    for (int i = 0; i < MAIN_CYCLE; i++) {
        m_startTick = __rdtscp(&m_stub);
        m_endTick = __rdtscp(&m_stub) - m_startTick;
        if (m_endTick < m_difference) m_difference = m_endTick;
    }
}

void EncryptionPerformanceTest::start() {
    before();
    std::for_each(m_lengths.begin(), m_lengths.end(), [this](int &length) {
        /* Variables */
        auto pDst = new signed char[length];
        auto pMessage = new signed char[length];
        unsigned long long min = ULONG_LONG_MAX;

        /* Preparation */
        generate(pMessage, length);

        /* Test */
        for (int i = 0; i < MAIN_CYCLE; i++) {
            m_startTick = __rdtscp(&m_stub);
            for (int j = 0; j < CYCLE; j++) {
                test(m_key, pMessage, pDst, length);
            }
            m_endTick = __rdtscp(&m_stub) - m_startTick - m_difference;
            if (min > m_endTick) min = m_endTick;
        }

        std::ofstream logs;
        logs.open(PERF_TEST_OUTPUT_FILE_NAME, std::ios::app);

        logs << "encrypt," << length << ',' << (double) min / (double) MAIN_CYCLE / (double) CYCLE << std::endl;

        logs.close();

        /* Finalizing */
        delete pDst;
        delete pMessage;
    });
    after();
}
