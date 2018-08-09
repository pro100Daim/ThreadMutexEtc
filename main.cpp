#include <iostream>
#include "timer.h"


int main()
{
    IClient* cl1 = new IClient(1);
    IClient* cl2 = new IClient(2);
    IClient* cl3 = new IClient(3);
    IClient* cl4 = new IClient(4);

    Timer *tim = new Timer();
    tim->runTimer(5, cl1);
    tim->runTimer(10, cl2);
    tim->runTimer(15, cl3);
    tim->runTimer(10, cl4);
    tim->check();
    return 0;
}
