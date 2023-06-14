/*****************************************************
 ** Program:Fortune Teller
 ** Author:Patrick Liang
 ** Date:1/8/2020
 ** Input: five value
 ** Output: Three sentences with the fortune filled in
 *****************************************************/
#include <iostream>

using namespace std;

unsigned short year() 
/*I used unsigned short because I wanted a positive integer that is small.
 The data type "unsigned short" can take a number from 0 to 65535.*/
{
    unsigned short firstInput;
    bool done = false;
    while (!done)
    {
        cout << "Give me an integer between 2 and 50" << endl;
        cin >> firstInput;
        done = firstInput <= 50 && firstInput >= 2;
    }
    
    return firstInput;
}

float size()
/*Float is used here because I want a number with 2 decimal places that's below 5000.
The data type "float" can store */

{
    float secondInput;
    cout << "Give me a number with 2 decimal places between 10 and 5000" << endl;
    cin >> secondInput;
    return secondInput;
}

unsigned short underground()
/*Unsigned short is used here because I need an integer from 10 to 35.
The data type "unsigned short" can take a number from 0 to 65535.*/
{
    unsigned short thirdInput;
    bool done = false;
    while (!done)
    {
        cout << "Type an integer between 10 and 35" << endl;
        cin >> thirdInput;
        done = thirdInput <= 35 && thirdInput >= 10;
    }
    
    return thirdInput;
}

unsigned int money()
/*I am using unsigned int here because I want a 6 digit number, unsign short cannot do that.
unsigned int can take integers from 0 to 4,294,967,295*/
{
    unsigned int forthInput;
    bool done = false;
    while (!done)
    {
        cout << "Please provide a 6 digit integer." << endl;
        cin >> forthInput;
        done = forthInput >= 100000 && forthInput <= 999999;
    }

        return forthInput;
}

unsigned short neighbor()
/*Unsigned short is used here because I need a positive integer from 0 to 10.
The data type "unsigned short" can take a number from 0 to 65535.*/
{
    unsigned short fifthInput;
    bool done = false;
    while (!done)
    {
        cout << "Give me an integer between 0 and 10" << endl;
        cin >> fifthInput;
        done = fifthInput <= 10 && fifthInput >= 0;
    }

    return fifthInput;
}

int main()
{
    unsigned short firstInput = year();
    float secondInput = size();
    unsigned short thirdInput = underground();
    unsigned int forthInput = money();
    unsigned short fifthInput = neighbor();

    cout << "In " << firstInput << " years, you will be living in a house that is " << secondInput << " square feet." << endl;
  
    cout << thirdInput << " feet under that house, you will find a box with a diamond worth " << forthInput << " dollars." << endl;

    cout << fifthInput << " of your neighbors will try to steal it from you." << endl;
    
    return 0;
}
