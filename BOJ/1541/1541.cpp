#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
    cin>>str;
    vector<int> arr;
    int now=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='-'){
            arr.push_back(now);
            now=0;
            arr.push_back(-1);
        }
        else if(str[i]=='+'){
            arr.push_back(now);
            now=0;
            arr.push_back(-2);
        }
        else{
            now*=10;
            now+=str[i]-'0';
        }
    }
    arr.push_back(now);
    vector<int> temp;
    now=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]==-1){
            temp.push_back(now);
            now=arr[i+1];
        }
        else if(arr[i]==-2)
            now+=arr[i+1];
    }
    temp.push_back(now);
    int ans=temp[0];
    for(int i=1;i<temp.size();i++){
       ans-=temp[i];
    }
    printf("%d\n",ans);
    return 0;
}
