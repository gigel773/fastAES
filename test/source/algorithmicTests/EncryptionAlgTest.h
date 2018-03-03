#pragma once

#include <IAlgorithmicTest.h>
#include <iostream>

extern "C" {
#include <fastAES.h>
};

class EncryptionAlgTest : public IAlgorithmicTest<int, const signed char *, signed char *, signed char *, int> {
public:

    explicit EncryptionAlgTest();

    void start() override;

    ~EncryptionAlgTest() override;

private:
    void before() override;

    void after() override;
};