#include <bits/stdc++.h>
using namespace std;
int n;
pair<string,string> arr[1000];
string lower_case(const string &str){
    string ret="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            char now=str[i]-'A'+'a';
            ret+=now;
        }
        else
            ret+=str[i];
    }
    return ret;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        for(int i=0;i<n;i++){
            cin>>arr[i].second;
            arr[i].first=lower_case(arr[i].second);
        }
        cout<<(*min_element(arr,arr+n)).second<<'\n';
    }
    return 0;
}