#ifndef FASTAESMODULE_IALGORITHMICTEST_H
#define FASTAESMODULE_IALGORITHMICTEST_H

#include "ITest.h"
#include <functional>
#include <stdlib.h>
#include <time.h>

template<class Ret, class ...Params>
class IAlgorithmicTest : public ITest {
public:
    using TestFunction = std::function<Ret(Params...)>;

    explicit IAlgorithmicTest(const TestFunction &m_enc_function, const TestFunction &m_dec_function) : m_enc_function(
            std::move(m_enc_function)), m_dec_function(std::move(m_dec_function)) {}

    virtual ~IAlgorithmicTest() = default;

protected:

    std::vector<int> m_lengths;

    virtual long enc_function(Params... params) {
        m_enc_function(params...);
    }

    virtual long dec_function(Params... params) {
        m_dec_function(params...);
    }

    void generate(signed char *pDst, int length) override {
        srand((unsigned int) time(NULL));
        for (int i = 0; i < length; i++) {
            *(pDst + i) = (signed char) ((rand() % 26) + 'a');
        }
    }

private:
    TestFunction m_enc_function;
    TestFunction m_dec_function;
};

#endif //FASTAESMODULE_IALGORITHMICTEST_H
