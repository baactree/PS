#include<iostream>
using namespace std;
int main()
{
    int N,M,output;
    cin>>N>>M;
    output=0;
    while(true)
    if(N>M)
        N%=M;
    else if(N==M||N==0)
    {
        cout<<output<<endl;
        break;
    }
    else
    {
        M-=N;
        output+=N;
    }
    return 0;
}