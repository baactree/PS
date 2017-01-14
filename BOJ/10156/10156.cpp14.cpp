#include <iostream>
using namespace std;
int main()
    {
    int K,N,M;
    cin>>K>>N>>M;
    M-=N*K;
    if(M>=0)
        cout<<"0"<<endl;
    else
        cout<<M*-1<<endl;
    
}
