#include <bits/stdc++.h>
using namespace std;
class point{
public:
    int x, y;
    point(){}
    point(int x,int y):x(x),y(y){}
    int cross(const point &rhs)const{
        return x*rhs.y-y*rhs.x;
    }
    point operator - (const point &rhs)const{
        return point(x-rhs.x,y-rhs.y);
    }
    bool operator < (const point &rhs)const {
        if(x==rhs.x)
            return y<rhs.y;
        return x<rhs.x;
    }
};
int ccw(const point &a,const point &b){
    return a.cross(b);
}
int ccw(const point &p,const point &a,const point &b){
    return ccw(a-p,b-p);
}
int ccw(const point &p,const point &a,const point &b,const point &c){
    return ccw(a-p,c-b);
}
point arr[100000];
point up[100000];
point down[100000];
vector<point> hull;
int n;
int dist(point a,point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].x,&arr[i].y);
    sort(arr,arr+n);
    int iup,idown;
    iup=idown=-1;
    for(int i=0;i<n;i++){
        while(iup>0&&ccw(up[iup-1],up[iup],arr[i])<=0)
            iup--;
        while(idown>0&&ccw(down[idown-1],down[idown],arr[i])>=0)
            idown--;
        up[++iup]=arr[i];
        down[++idown]=arr[i];
    }
    for(int i=0;i<=iup;i++)
        hull.push_back(up[i]);
    for(int i=idown-1;i>0;i--)
        hull.push_back(down[i]);
    int j=1;
    int m=hull.size();
    int ans=0;
    for(int i=0;i<m;i++){
        int ni=(i+1)%m;
        while(true){
            int nj=(j+1)%m;
            if(ccw(hull[i],hull[ni],hull[j],hull[nj])>0)
                j=nj;
            else{
                break;
            }
        }
        ans=max(ans,dist(hull[i],hull[j]));
    }
    printf("%.10lf\n",sqrt(ans));
    return 0;
}