#include "yield.hpp"
#include <stdio.h>

using namespace boost::asio;
coroutine c;

int double(int i)
{
    return 2*i;
}
int foo(coroutine & c, int i)
{
    reenter(c)
    {
        double(i);
        yield;

        double(i+1)
        yield;
        
        double(i+2);
        yield;
    }

    return 0;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        prinf("%dth call %d", i+1, foo(c, 1));
    }
    return 0;
}
