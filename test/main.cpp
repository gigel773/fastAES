#include <vector>
#include <functional>
#include <memory>
#include "source/performance_tests/encryption_performance_test.hpp"
#include "source/algorithmic_tests/encryption_algorithmic_test.hpp"
#include <test_suite.hpp>
#include <iostream>

#define AES_TEST_PARAMS int, const signed char *, signed char *, signed char *, int

int main() {
    auto runner = std::make_shared<TestSuite>();

    // Registering
    std::cout << "Registering tests..." << std::endl;
    runner->registerTest<EncryptionAlgorithmicTest, AES_TEST_PARAMS>();
    runner->registerTest<EncryptionPerformanceTest, AES_TEST_PARAMS>();

    // Testing
    std::cout << "Running tests..." << std::endl;
    runner->runAlgorithmicTests();
    runner->runPerformanceTests();

    return 0;
}