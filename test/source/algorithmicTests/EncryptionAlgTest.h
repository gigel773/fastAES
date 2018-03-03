#ifndef FASTAESMODULE_ENCRYPTIONALGTEST_H
#define FASTAESMODULE_ENCRYPTIONALGTEST_H


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


#endif //FASTAESMODULE_ENCRYPTIONALGTEST_H
