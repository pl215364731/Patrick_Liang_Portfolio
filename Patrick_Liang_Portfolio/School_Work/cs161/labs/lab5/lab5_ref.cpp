#include <iostream>
using namespace std;


/*******************************************************************
 * ** Function: plus_10_value
 * ** Description:plus 10 to a value
 * ** Parameters:number
 * ** Pre-Conditions:an integer
 * ** Post-Conditions:plus 10
 * *******************************************************************/ 
int plus_10_value(int n)
{
   n += 10;
   return n;
}
/*******************************************************************
 * ** Function: plus_10_value
 * ** Description:plus 10 to a value
 * ** Parameters:number
 * ** Pre-Conditions:number is an integer
 * ** Post-Conditions:plus 10 to the integer
 * *******************************************************************/ 
void plus_10_ref (int& n)
{
   n += 10;
}
int main()
{
   int number;
   cout << "Enter an integer:";
   cin >> number;

   plus_10_ref (number);

   cout << "Your number is: " << number << endl;

   return 0;

}
