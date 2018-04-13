#pragma once

#include <vector>
#include <memory>
#include <type_traits>

#include "test.hpp"
#include "performance_test_base.hpp"
#include "algorithmic_test_base.hpp"

class TestSuite {
public:
    TestSuite() = default;

    template<class TestClass, class Ret, class ...Params>
    void registerTest() {
        static_assert(std::is_base_of<ITest, TestClass>::value{});
        if (std::is_base_of<PerformanceTestBase<Ret, Params...>, TestClass>::value) {
            m_performanceTests.push_back(std::make_shared<TestClass>());
        } else if (std::is_base_of<AlgorithmicTestBase<Ret, Params...>, TestClass>::value) {
            m_algorithmicTests.push_back(std::make_shared<TestClass>());
        }
    }

    void runAlgorithmicTests() {
        std::for_each(m_algorithmicTests.begin(), m_algorithmicTests.end(), [](std::shared_ptr<ITest> test) {
            test->start();
        });
    }

    void runPerformanceTests() {
        std::for_each(m_performanceTests.begin(), m_performanceTests.end(), [](std::shared_ptr<ITest> test) {
            test->start();
        });
    }

private:
    std::vector<std::shared_ptr<ITest>> m_algorithmicTests;
    std::vector<std::shared_ptr<ITest>> m_performanceTests;
};
