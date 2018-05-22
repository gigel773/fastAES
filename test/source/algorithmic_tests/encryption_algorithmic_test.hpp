#pragma once

#include <algorithmic_test_base.hpp>
#include <iostream>
#include <algorithm>

extern "C" {
#include <fastaes.h>
};

class EncryptionAlgorithmicTest
        : public AlgorithmicTestBase<int, const signed char *, signed char *, signed char *, int> {
public:

    explicit EncryptionAlgorithmicTest();

    void start() override;

    ~EncryptionAlgorithmicTest() override;

private:
    void before() override;

    void after() override;
};
