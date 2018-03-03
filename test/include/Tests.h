#ifndef FASTAESMODULE_TESTS_H
#define FASTAESMODULE_TESTS_H

#include <vector>
#include "ITest.h"

// static signed char key[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

//extern std::vector<ITest> algorithmicTests;
//extern std::vector<ITest> performanceTests;

#define REG_ALG_TEST(testClass, enc_function, dec_function)\
    algorithmicTests.push_back(new testClass(enc_function, dec_function))

#define REG_PERF_TEST(testClass, function)\
    performanceTests.push_back(new testClass(key, function))

#endif //FASTAESMODULE_TESTS_H
