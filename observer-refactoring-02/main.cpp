/**
    Project     : Observer Example

    Author      : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
**/

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <iostream>

#include "include/ClockTimer.h"
#include "include/AnalogClock.h"
#include "include/DigitalClock.h"

using namespace std;

/*************************************************************************************************/
/**MAIN**/
int main()
{
    ClockTimer* timer = new ClockTimer;

    new AnalogClock(timer);
    new DigitalClock(timer);

//    timer->Tick();
//    timer->Tick();
//    timer->Tick();

    while(1)
    {
        timer->Tick();
        #ifdef __unix__
            sleep(1);
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            Sleep( 1000 );
            system("cls");
        #endif // defined
    }

    return 0;
}

/********************************************************************************************/
