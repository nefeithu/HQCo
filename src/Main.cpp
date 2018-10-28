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

int goo(coroutine & c, int i)
{
    int iRet = 0;
    reenter(c)
    {
        iRet = i;
        yield;

        iRet = i+1;
        yield;
        
        iRet = i+2;
        yield;
    }

    return iRet;
}


int loo(coroutine & c, int i)
{
    int iRet = 0;
    reenter(c)
    {
        iRet = i*i;
        yieldn(1);

        iRet = (i+1)(i+1);
        yieldn(2);
        
        iRet = (i+2)(i+2);
        yieldn(3);
    }

    return iRet;
}

int moo(coroutine & c, int i)
{
    int iRet = 0;
    reenter(c)
    {
        iRet = i*3;
        yieldn(1);

        iRet = (i+1)*3;
        yieldn(2);
        
        iRet = (i+2)*3;
        yieldn(3);
    }

    return iRet;
}





int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n%dth call %d, co stat(%d)\n", i+1, foo(c, 1), c.GetValue());
    }

    c.setValue(0);
    printf("co reset to init stat 0\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%dth call %d, co stat(%d)\n", i+1, goo(c, 1), c.GetValue());
    }

    c.setValue(0);
    printf("co reset to illegal stat 1\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%dth call %d, co stat(%d)\n", i+1, loo(c, 1), c.GetValue());
    }

    c.setValue(0);
    printf("co reset to illegal stat 1\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%dth call %d, co stat(%d)\n", i+1, moo(c, 1), c.GetValue());
    }
    return 0;
}
