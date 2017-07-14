#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<a.size();i++)
        if(a[i]=='1')
            cnt++;
    if(cnt&1)
        cnt++;
    int cnt2=0;
    for(int i=0;i<b.size();i++)
        if(b[i]=='1')
            cnt2++;
    if(cnt2<=cnt)
        printf("VICTORY\n");
    else
        printf("DEFEAT\n");
    return 0;
}