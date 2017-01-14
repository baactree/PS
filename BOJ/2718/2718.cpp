#include<iostream>
using namespace std;
int main()
{
    int dp1[1000];
    int dp2[1000];
    for(int i=0;i<1000;i++)
       dp1[i]=dp2[i]=0;
    dp1[0]=1;
    dp1[1]=1;
    dp2[1]=1;
    dp1[2]=5;
    dp2[2]=4;
    for(int i=3;i<1000;i++)
    {
       
        for(int j=1;j<i;j++)
        {
            dp1[i]+=dp2[j]*dp1[i-j];
        }
        if(i%2==0)
        {
            dp2[i]=3;
            dp1[i]+=3;
        }
        else
        {
            dp2[i]=2;
            dp1[i]+=2;
        }
    }
    int T;
    cin>>T;
    while(T--)
{
    int N;
        cin>>N;
        cout<<dp1[N]<<endl;
    }
    return 0;
}