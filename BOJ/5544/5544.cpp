#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[105];
int score[105];
int main(){
    scanf("%d",&n);
    int m=n*(n-1)/2;
    for(int i=1;i<=n;i++)
        arr[i].second=i;
    for(int i=0;i<m;i++){
        int u,v,a,b;
        scanf("%d%d%d%d",&u,&v,&a,&b);
        if(a<b){
            arr[v].first+=3;
        }
        else if(a==b){
            arr[u].first++;
            arr[v].first++;
        }
        else{
            arr[u].first+=3;
        }
    }
    sort(arr+1,arr+1+n);
    reverse(arr+1,arr+1+n);
    for(int i=1;i<=n;i++){
        if(arr[i].first==arr[i-1].first)
            score[arr[i].second]=score[arr[i-1].second];
        else
            score[arr[i].second]=i;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",score[i]);
    return 0;
}