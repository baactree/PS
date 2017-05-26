// =====================================================================================
// 
//       Filename:  2162.cpp
//        Created:  2017년 05월 26일 00시 55분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class point{
public:
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
    point operator - (const point &rhs)const{
        return {x-rhs.x,y-rhs.y};
    }
    bool operator < (const point &rhs)const{
        if(x==rhs.x)
            return y<rhs.y;
        return x<rhs.x;
    }
    int cross(const point &rhs)const{
        return x*rhs.y-y*rhs.x;
    }
};
int ccw(point a,point b){
    int ret = a.cross(b);
    if(ret>0)
        return 1;
    else if(ret<0)
        return -1;
    return ret;
}
int ccw(point p,point a,point b){
    return ccw(a-p,b-p);
}
bool cross(point a,point b,point c,point d){
    int q=ccw(a,b,d)*ccw(a,b,c);
    int w=ccw(c,d,a)*ccw(c,d,b);
    if(q==0&&w==0){
        if(b<a)
            swap(a,b);
        if(d<c)
            swap(c,d);
        return !(b<c||d<a);
    }
    return q<=0&&w<=0;
}
int n;
pair<point,point> arr[3000];
vector<int> adj[3000];
bool trip[3000];
int dfs(int now){
    if(trip[now])
        return 0;
    trip[now]=true;
    int ret=1;
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(!trip[there])
            ret+=dfs(there);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&arr[i].first.x,&arr[i].first.y,&arr[i].second.x,&arr[i].second.y);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(cross(arr[i].first,arr[i].second,arr[j].first,arr[j].second)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!trip[i]){
            cnt++;
            int now=dfs(i);
            ans=max(now,ans);
        }
    }
    printf("%d\n%d\n",cnt,ans);
    return 0;
}
