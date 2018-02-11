#ifndef FASTAESMODULE_ENCRYPTIONTEST_H
#define FASTAESMODULE_ENCRYPTIONTEST_H


#include "ITest.h"
#include <vector>
#include <algorithm>
#include <functional>
#include "IPerformanceTest.h"

class EncryptionTest : IPerformanceTest<void, signed char *, signed char *, signed char *, int> {
public:
    EncryptionTest(signed char *key, TestFunction function);

    void start() override;

private:
    void before() override;

    void after() override {};

    signed char *m_key;
};


#endif //FASTAESMODULE_ENCRYPTIONTEST_H
