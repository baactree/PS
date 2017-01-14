#include <iostream>
#include <cmath>
  
using namespace std;
  
int main()
{
    long n = (cin >> n, n);
    cout << ceil((pow(12LL*n-3,0.5)+3)/6) << endl;
   return 0;
}