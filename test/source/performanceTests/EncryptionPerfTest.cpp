#include <x86intrin.h>
#include "EncryptionPerfTest.h"

EncryptionPerfTest::EncryptionPerfTest(signed char *key, TestFunction function)
        : IPerformanceTest(function),
          m_key(key) {
    m_lengths = std::vector<int>(8);
    static int i = 8;
    std::generate(m_lengths.begin(), m_lengths.end(), [] {
        i *= 2;
        return i;
    });
}

void EncryptionPerfTest::before() {
    m_difference = ULONG_LONG_MAX;
    for (int i = 0; i < MAIN_CYCLE; i++) {
        m_startTick = __rdtscp(&m_stub);
        m_endTick = __rdtscp(&m_stub) - m_startTick;
        if (m_endTick < m_difference) m_difference = m_endTick;
    }
}

void EncryptionPerfTest::start() {
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

        /*
         * Here's empty place to write results to file
         * */

        /* Finalizing */
        delete pDst;
        delete pMessage;
    });
    after();
}
