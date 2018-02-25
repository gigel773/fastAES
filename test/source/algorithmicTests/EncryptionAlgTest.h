#ifndef FASTAESMODULE_ENCRYPTIONALGTEST_H
#define FASTAESMODULE_ENCRYPTIONALGTEST_H


#include <IAlgorithmicTest.h>
#include <iostream>

class EncryptionAlgTest : IAlgorithmicTest<void, signed char *, signed char *, signed char *, int> {
public:

    explicit EncryptionAlgTest(const TestFunction &m_enc_function, const TestFunction &m_dec_function);

    void start() override;

    ~EncryptionAlgTest() override;

private:
    void before() override;

    void after() override;
};


#endif //FASTAESMODULE_ENCRYPTIONALGTEST_H
