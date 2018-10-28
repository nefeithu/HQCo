#include "yield.hpp"
#include <stdio.h>

using namespace boost::asio;
coroutine c;

int Double(int i)
{
    return 2*i;
}
int foo(coroutine & c, int i)
{
    int iRet = 0;
    reenter(c)
    {
        iRet = Double(i);
        yield;

        iRet = Double(i+1);
        yield;
        
        iRet = Double(i+2);
        yield;
    }

    return iRet;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%dth call %d", i+1, foo(c, 1));
    }
    return 0;
}
