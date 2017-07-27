#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(){}
    point(int x,int y):x(x),y(y){}
    point operator - (const point &rhs)const{
        return point(x-rhs.x,y-rhs.y);
    }
};
set<pair<int,int> > s;
int m,n;
point a[205];
bool possi(int x,int y){
    for(int i=0;i<m;i++){
        int nx=x+a[i].x;
        int ny=y+a[i].y;
        if(s.find({nx,ny})==s.end())
            return false;
    }
    return true;
}
int main(){
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    int sx,sy;
    sx=a[0].x;
    sy=a[0].y;
    for(int i=0;i<m;i++)
        a[i]=point(a[i].x-sx,a[i].y-sy);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        s.insert({x,y});
    }
    int ansx,ansy;
    ansx=ansy=-1;
    for(auto it=s.begin();it!=s.end();it++){
        int x=(*it).first;
        int y=(*it).second;
        if(possi(x,y)){
            ansx=x-sx;
            ansy=y-sy;
        }
    }
    printf("%d %d\n",ansx,ansy);
    return 0;
}