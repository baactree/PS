// =====================================================================================
// 
//       Filename:  14584.cpp
//        Created:  2017년 05월 26일 00시 55분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int n;
string arr[20];
int main(){
    cin>>str>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<26;i++){
        for(int j=0;j<str.size();j++)
            str[j]=(str[j]-'a'+1)%26+'a';
        int cnt=0;
        for(int j=0;j<n;j++)
            if(str.find(arr[j])!=string::npos)
                cnt++;
        if(cnt!=0){
            cout<<str<<endl;
            return 0;
        }
    }
    return 0;
}
