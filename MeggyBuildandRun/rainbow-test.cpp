#include "MeggyJrSimple.h"

int main (void)
{
    MeggyJrSimpleSetup();

    // From enum in MeggyJrSimple.h    
    //   Dark, Red, Orange, Yellow, Green, Blue, Violet, White, 

    while (1) {
        DrawPx(2, 6, 1);    // should display red LED
        DrawPx(3, 5, 2);    // should display orange LED
        DrawPx(4, 4, 3);    // should display yellow LED
        DrawPx(5, 3, 0);    // should display DARK LED
        DrawPx(6, 2, 4);    // should display green LED
        DrawPx(7, 1, 5);    // should display blue LED
        DrawPx(0, 0, 6);    // should display violet LED
        DrawPx(1, 1, 7);    // should display white LED
        DisplaySlate();

    }

    return 0;
}

