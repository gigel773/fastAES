#pragma once

class ITest {
public:
    virtual void start() = 0;

private:
    virtual void before() = 0;

    virtual void after() = 0;

protected:
    virtual void generate(signed char *pDst, int length) = 0;
};
