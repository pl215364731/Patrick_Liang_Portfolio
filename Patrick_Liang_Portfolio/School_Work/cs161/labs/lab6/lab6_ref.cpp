#include <iostream>
#include <string>

using namespace std;

void count_punctuation(string s, int& n_periods, int& n_commas)
{
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
            n_periods++;
        if (s[i] == ',')
            n_commas++;
    }  
}

void count_punctuation2(string s, int* n_periods, int* n_commas)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
            (*n_periods)++;
        if (s[i] == ',')
            (*n_commas)++;
    }
}
int main()
{

    int periods = 0;
    int commas = 0;

   string s;
   getline(cin, s);
   count_punctuation2(s, &periods, &commas);

   cout << "periods:" << periods << endl;
   cout << "commas:" << commas << endl;
   return 0;
}

