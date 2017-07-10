#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[100000];
int n,l;
int main(){
    scanf("%d%d",&n,&l);
    int t;
    t=-1;
    int cnt=0;
    bool flag=false;
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        arr[i]={abs(in),i};
        if(in>0){
            if(t<l-in){
                t=l-in;
                flag=true;
            }
        }
        else{
            cnt++;
            if(t<-in){
                t=-in;
                flag=false;
            }
        }
    }
    sort(arr,arr+n);
    printf("%d %d\n",flag?arr[cnt].second+1:arr[cnt-1].second+1,t);
    return 0;
}