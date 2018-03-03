#ifndef FASTAESMODULE_PERFORMANCETEST_H
#define FASTAESMODULE_PERFORMANCETEST_H

#include "ITest.h"
#include <climits>
#include <functional>

template<class Ret, class ...Params>
class IPerformanceTest : public ITest {
public:
    using TestFunction = std::function<Ret(Params...)>;

    explicit IPerformanceTest(const TestFunction &m_function) : m_function(std::move(m_function)) {}

    ~IPerformanceTest() = default;

protected:
    std::vector<int> m_lengths;

    virtual long test(Params... params) {
        m_function(params...);
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

#endif //FASTAESMODULE_PERFORMANCETEST_H
