#ifndef FASTAESMODULE_ENCRYPTIONTEST_H
#define FASTAESMODULE_ENCRYPTIONTEST_H


#include "ITest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include "IPerformanceTest.h"
#include <Tests.h>

class EncryptionPerfTest : IPerformanceTest<void, signed char *, signed char *, signed char *, int> {
public:
    EncryptionPerfTest(signed char *key, TestFunction function);

    void start() override;

private:
    void before() override;

    void after() override {};

    signed char *m_key;
};

// REG_PERF_TEST(EncryptionPerfTest, encrypt);

#endif //FASTAESMODULE_ENCRYPTIONTEST_H
