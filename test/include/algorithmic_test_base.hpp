#pragma once

#include "test.hpp"
#include <functional>
#include <cstdlib>
#include <ctime>

template<class Ret, class ...Params>
class AlgorithmicTestBase : public ITest {
public:
    using TestFunction = std::function<Ret(Params...)>;

    explicit AlgorithmicTestBase(const TestFunction &m_enc_function, const TestFunction &m_dec_function)
            : m_enc_function(
            std::move(m_enc_function)), m_dec_function(std::move(m_dec_function)) {}

    virtual ~AlgorithmicTestBase() = default;

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
