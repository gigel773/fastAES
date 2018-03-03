#include <vector>
#include <functional>
#include <memory>
#include "source/performanceTests/EncryptionPerfTest.h"
#include "source/algorithmicTests/EncryptionAlgTest.h"
#include <TestRunner.hpp>

#define AES_TEST_PARAMS int, const signed char *, signed char *, signed char *, int

int main() {
    auto runner = std::make_shared<TestRunner>();

    /* Registering */
    runner->registerTest<EncryptionAlgTest, AES_TEST_PARAMS>();
    runner->registerTest<EncryptionPerfTest, AES_TEST_PARAMS>();

    /* Testing */
    runner->runAlgTests();
    runner->runPerfTests();

    return 0;
}