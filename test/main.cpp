#include <vector>
#include <functional>
#include "source/performanceTests/EncryptionPerfTest.h"
#include "source/algorithmicTests/EncryptionAlgTest.h"

extern "C" {
#include <fastAES.h>
};

//std::vector<ITest> algorithmicTests;
//std::vector<IPerformanceTest> performanceTests;

static signed char key[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

int main() {
    // EncryptionPerfTest(key, encrypt).start();
    EncryptionAlgTest(encrypt, decrypt).start();

//    std::for_each(algorithmicTests.begin(), algorithmicTests.end(), [](ITest &test) {
//        test.start();
//    });
//    std::for_each(performanceTests.begin(), performanceTests.end(), [](IPerformanceTest &test) {
//        test.start();
//    });

    return 0;
}