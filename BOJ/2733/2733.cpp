#include <bits/stdc++.h>
using namespace std;
char p[7]={'>','<','+','-','.','[',']'};
int idx[130000];
int arr[33000];
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        memset(arr,0,sizeof(arr));
        string order="";
        while(true){
            string now;
            getline(cin,now);
            if(now=="end")
                break;
            for(int i=0;i<now.size();i++){
                if(now[i]=='%')
                    break;
                bool flag=false;
                for(int j=0;j<7;j++)
                    if(now[i]==p[j])
                        flag=true;
                if(flag)
                    order.push_back(now[i]);
            }
        }
        printf("PROGRAM #%d:\n",tc);
        stack<int> st;
        int point=0;
        for(int i=0;i<order.size();i++){
            if(order[i]=='['){
                st.push(i);
            }
            else if(order[i]==']'){
                if(st.empty())
                    goto next;
                idx[st.top()]=i;
                idx[i]=st.top();
                st.pop();
            }
        }
        if(!st.empty())
            goto next;
        for(int i=0;i<order.size();i++){
            if(order[i]=='>'){
                if(point==32767)
                    point=0;
                else
                    point++;
            }
            else if(order[i]=='<'){
                if(point==0)
                    point=32767;
                else
                    point--;
            }
            else if(order[i]=='+'){
                if(arr[point]==255)
                    arr[point]=0;
                else
                    arr[point]++;
            }
            else if(order[i]=='-'){
                if(arr[point]==0)
                    arr[point]=255;
                else
                    arr[point]--;
            }
            else if(order[i]=='.')
                printf("%c",arr[point]);
            else if(order[i]=='['&&arr[point]==0)
                i=idx[i];
            else if(order[i]==']'&&arr[point])
                i=idx[i];
        }
        printf("\n");
        if(false){
            next:
            printf("COMPILE ERROR\n");
        }
    }
    return 0;
}