#pragma once

#include "test.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include "performance_test_base.hpp"

extern "C" {
#include <fastAES.h>
};

const std::string PERF_TEST_OUTPUT_FILE_NAME = "./ps_tests_results.csv";

class EncryptionPerformanceTest
        : public PerformanceTestBase<int, const signed char *, signed char *, signed char *, int> {
public:
    EncryptionPerformanceTest();

    void start() override;

private:
    void before() override;

    void after() override {};

    const signed char m_key[16] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
};