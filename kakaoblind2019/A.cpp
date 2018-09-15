#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string,string> mp;
    for(int i=0;i<record.size();i++){
        char a[20],b[20],c[20];
        sscanf(record[i].c_str(),"%s",a);
        if(a[0]=='E'){
            sscanf(record[i].c_str(),"%s%s%s",a,b,c);
            mp[string(b)]=c;
        }
        else if(a[0]=='L'){
            sscanf(record[i].c_str(),"%s%s",a,b);
        }
        else{
            sscanf(record[i].c_str(),"%s%s%s",a,b,c);
            mp[string(b)]=c;
        }
    }
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        char a[20],b[20],c[20];
        sscanf(record[i].c_str(),"%s",a);
        if(a[0]=='E'){
            sscanf(record[i].c_str(),"%s%s%s",a,b,c);
            char output[50];
            sprintf(output,"%s´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.",mp[string(b)].c_str());
            answer.push_back(string(output));
        }
        else if(a[0]=='L'){
            sscanf(record[i].c_str(),"%s%s",a,b);
            char output[50];
            sprintf(output,"%s´ÔÀÌ ³ª°¬½À´Ï´Ù.",mp[string(b)].c_str());
            answer.push_back(string(output));
        }
        else{
            continue;
        }
    }
    return answer;
}