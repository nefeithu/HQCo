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
        printf("%dth call %d, co stat(%d)\n", i+1, foo(c, 1), c.GetValue());
    }

    c.setValue(0);
    printf("co reset to init stat 0");
    for (int i = 0; i < 5; i++)
    {
        printf("%dth call %d, co stat(%d)\n", i+1, foo(c, 1), c.GetValue());
    }

    c.setValue(1);
    printf("co reset to illegal stat 1");
    for (int i = 0; i < 5; i++)
    {
        printf("%dth call %d, co stat(%d)\n", i+1, foo(c, 1), c.GetValue());
    }
    return 0;
}
