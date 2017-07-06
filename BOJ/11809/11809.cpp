#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int l=min(a.size(),b.size());
    for(int i=0;i<l;i++){
        if(a[i]==b[i])
            continue;
        if(a[i]<b[i]){
            a[i]='_';
        }
        else{
            b[i]='_';
        }
    }
    string ansa="";
    for(int i=0;i<a.size();i++)
        if(a[i]!='_')
            ansa+=a[i];
    reverse(ansa.begin(),ansa.end());
    
    string ansb="";
    for(int i=0;i<b.size();i++)
        if(b[i]!='_')
            ansb+=b[i];
    reverse(ansb.begin(),ansb.end());
    if(ansa.size()==0)
        printf("YODA\n");
    else
        printf("%d\n",stoi(ansa));
    if(ansb.size()==0)
        printf("YODA\n");
    else
        printf("%d\n",stoi(ansb));
    return 0;
}