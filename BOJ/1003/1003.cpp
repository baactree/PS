#include <iostream>
//#include <cmath>
using namespace std;
int main()
{
    int Case;
    int pibo[40];
    pibo[0]=pibo[1]=1;
    for(int i=2;i<40;i++)
    pibo[i]=pibo[i-1]+pibo[i-2];
    cin>>Case;
    while(Case--)
    {
                 int N;
                 cin>>N;
                 if(N<2)
                 {
                        if(N==0)
                        {
                                cout<<"1 0"<<endl;
                                }
                        else if(N==1)
                             cout<<"0 1"<<endl;
                        }
                 else
                 {
                     cout<<pibo[N-2]<<" "<<pibo[N-1]<<endl;
                 }
                 }
    return 0; 
}