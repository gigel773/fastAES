#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include "ITest.h"
#include "IPerformanceTest.h"
#include "IAlgorithmicTest.h"

class TestRunner {
public:
    TestRunner() = default;

    template<class TestClass, class Ret, class ...Params>
    void registerTest() {
        static_assert(std::is_base_of<ITest, TestClass>::value);
        if (std::is_base_of<IPerformanceTest<Ret, Params...>, TestClass>::value) {
            m_performanceTests.push_back(std::make_shared<TestClass>());
        } else if (std::is_base_of<IAlgorithmicTest<Ret, Params...>, TestClass>::value) {
            m_algorithmicTests.push_back(std::make_shared<TestClass>());
        }
    }

    void runAlgTests() {
        std::for_each(m_algorithmicTests.begin(), m_algorithmicTests.end(), [](std::shared_ptr<ITest> test) {
            test->start();
        });
    }

    void runPerfTests() {
        std::for_each(m_performanceTests.begin(), m_performanceTests.end(), [](std::shared_ptr<ITest> test) {
            test->start();
        });
    }

private:
    std::vector<std::shared_ptr<ITest>> m_algorithmicTests;
    std::vector<std::shared_ptr<ITest>> m_performanceTests;
};