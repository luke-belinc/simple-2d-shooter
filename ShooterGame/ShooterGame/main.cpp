#include <iostream>
#include "BreakOut.h"

int main()
{
    BreakOut demo;
    // Construct(window width, window height, pixel width, pixel height, full screen flag default false, vsync flag default false)
    if (demo.Construct(620, 480, 2, 2, false, true))
        demo.Start();
    return 0;
}