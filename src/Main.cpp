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
    reenter(c)
    {
        Double(i);
        yield;

        Double(i+1);
        yield;
        
        Double(i+2);
        yield;
    }

    return 0;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%dth call %d", i+1, foo(c, 1));
    }
    return 0;
}
