#include <iostream>

using namespace std;

int main()
{
   int n;
   while(cin >> n)
   {
       int cnt = 1;
       int numberConsistOf1 = 1;
       while(numberConsistOf1 % n != 0)
       {
           numberConsistOf1 = (numberConsistOf1 * 10) % n + 1 % n;
           cnt++;
       }
       cout << cnt << "\n";
   }

   return 0;
}