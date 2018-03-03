#ifndef FASTAESMODULE_ENCRYPTIONTEST_H
#define FASTAESMODULE_ENCRYPTIONTEST_H


#include "ITest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include "IPerformanceTest.h"

extern "C" {
#include <fastAES.h>
};

const std::string PERF_TEST_OUTPUT_FILE_NAME = "./ps_tests_results.csv";

class EncryptionPerfTest : public IPerformanceTest<int, const signed char *, signed char *, signed char *, int> {
public:
    EncryptionPerfTest();

    void start() override;

private:
    void before() override;

    void after() override {};

    const signed char m_key[16] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
};

#endif //FASTAESMODULE_ENCRYPTIONTEST_H
