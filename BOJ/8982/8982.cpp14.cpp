#include "bits/stdc++.h"
using namespace std;
struct Line{
    int x1,x2,y;
    bool k;
    Line(int x1,int x2,int y,bool k):x1(x1),x2(x2),y(y),k(k){}
};
struct Hole{
    int a,b,c,d;
    const bool operator < (const Hole& rhs)const{
        return a<rhs.a;
    }
};
int N,K;
pair<int,int> arr[5000];
vector<Line> line;
Hole hole[2500];
int solve(int left,int right,int hight){
    if(left==right)
        return 0;
    bool flag=false;
    int min_hight=1e9;
    int min_idx;
    for(int i=left;i<right;i++){
        if(line[i].k)
            flag=true;
        if(min_hight>line[i].y){
            min_hight=line[i].y;
            min_idx=i;
        }
    }
    int ret=0;
    if(!flag){
        ret+=(min_hight-hight)*(line[right-1].x2-line[left].x1);
    }
    ret+=solve(left,min_idx,min_hight);
    ret+=solve(min_idx+1,right,min_hight);
    return ret;
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    scanf("%d",&K);
    for(int i=0;i<K;i++)
        scanf("%d%d%d%d",&hole[i].a,&hole[i].b,&hole[i].c,&hole[i].d);
    sort(hole,hole+K);
    int kidx=0;
    for(int i=1;i<N-1;i+=2){
        bool flag=false;
        if(kidx<K&&arr[i].first==hole[kidx].a){
            flag=true;
            kidx++;
        }
        line.push_back({arr[i].first,arr[i+1].first,arr[i].second,flag});
    }
    printf("%d\n",solve(0,line.size(),0));
    return 0;
}
