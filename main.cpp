#include "mbed.h"
#include <cstdio>

/*This programme will print bttnFall on cool term compiler when the blue button is pressed on the mbed. 
*/

// interrupts the current action to excute the bluebutton when called. 
InterruptIn bluebtn(PC_13);
// volatile means the value can change unexpectedly. 
int int_trig = 0;
// void loop for the button going from high to low. when this happens int_trig is 1. 
void bttnFall(){
    int_trig = 1;
}
void bttnRise(){
    int_trig = 2;
}


// main() runs in its own thread in the OS
int main()
{
// when the blue button is pressed going from high to low the void loop is called. 
    bluebtn.fall(&bttnFall);
    bluebtn.rise(&bttnRise);

    //while loop that executes the loop when the value is true. 
    while (true) {
        switch (int_trig){
        case 1:
            printf("bttnFall\r\n");
            break;
        case 2:
            printf("bttnRise\r\n");
            break;

        int_trig = 0;
        }
        }
        }
    