#include <iostream>
#include <chrono>
#include <thread>

int main()
{
   std::string s = "this is 1";
   std::cout << s;
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "\rthis is 2" << std::endl;

   return 0;

}
