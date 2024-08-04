#include "mbed.h"
#include <cstdio>

/*This programme will print button pressed on cool-term compiler when the blue button is pressed on the mbed microcontroller. 
On the first Commit this did not work correctly because the swich case statement was stuck on case 2 and
Did not reset. This updated program below uses a volatile Int and Int_trig = 0 to reset the button when
Pressed. The volatile means the value can change unexpectedly & when used with the interrupt in which 
interrupts the current action the button can be pressed and only one print F statement appears which 
is "Button pressed". 
*/

// interrupts the current action to excute the bluebutton when called. 
InterruptIn bluebtn(PC_13);
// volatile means the value can change unexpectedly. 
volatile int int_trig = 0;
// void loop for the button going from high to low. when this happens int_trig is 1. 
void bttnFall(){
    int_trig = 1;
}

// main() runs in its own thread in the OS
int main()
{
// when the blue button is pressed going from high to low the void loop is called. 
    bluebtn.fall(&bttnFall);

    //while loop that executes the loop when the value is true. 
    while (true) {
//if function calling the void loop for int_trig. when the int_trig is 1 print bttnFall on the screen. 
        if(int_trig == 1){
// set the int_trig back to 0
        int_trig = 0;
// print button pressed when the blue button has been pressed. 
        printf("Button Pressed \r\n");
        }
    }
}