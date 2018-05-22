#pragma once

#include "test.hpp"
#include <climits>
#include <functional>

template<class Ret, class ...Params>
class PerformanceTestBase : public ITest {
public:
    using TestFunction = std::function<Ret(Params...)>;

    explicit PerformanceTestBase(const TestFunction &m_function) : m_function(std::move(m_function)) {}

    ~PerformanceTestBase() = default;

protected:
    std::vector<int> m_lengths;

    virtual long test(Params... params) {
        return m_function(params...);
    }

    void generate(signed char *pDst, int length) override {
        for (int i = 0; i < length; i++) {
            *(pDst + i) = 'b';
        }
    }

    const int MAIN_CYCLE = 10000;
    const int CYCLE = 100;
    unsigned long long m_difference, m_startTick, m_endTick;
    unsigned int m_stub;

private:
    TestFunction m_function;
};
