#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
    cin>>str;
    int ans=0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            int k=(i+ans)%4;
            if(k!=0)
                ans+=4-k;
        }
    }
    printf("%d\n",ans);
    return 0;
}