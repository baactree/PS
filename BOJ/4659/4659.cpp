#include <bits/stdc++.h>
using namespace std;
char input[30];
int len;
char vowel[5]={'a','e','i','o','u'};
bool possi(){
    int cnt=0;
    int vcnt=0;
    int wcnt=0;
    bool flag=true;
    for(int i=0;i<len;i++){
        if(i!=0&&input[i]!='e'&&input[i]!='o'){
            if(input[i]==input[i-1])
                flag=false;
        }
        bool fv=false;
        for(int j=0;j<5;j++)
            if(input[i]==vowel[j])
                fv=true;
        if(fv){
            cnt++;
            vcnt++;
            wcnt=0;
        }
        else{
            vcnt=0;
            wcnt++;
        }
        if(wcnt==3||vcnt==3)
            flag=false;
    }
    return cnt>0&&flag;
}
int main(){
    while(scanf("%s",input)){
        if(strcmp(input,"end")==0)
            break;
        len=strlen(input);
        printf("<%s> is %sacceptable.\n",input,possi()?"":"not ");        
    }
    return 0;
}