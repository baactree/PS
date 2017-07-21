#include <bits/stdc++.h>
using namespace std;
struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point operator - (const point &rhs)const{
        return point(x-rhs.x,y-rhs.y);
    }
    point operator *(double rhs)const{
        return point(x*rhs,y*rhs);
    }
    point operator +(const point &rhs)const{
        return point(x+rhs.x,y+rhs.y);
    }
    double norm() const{
        return hypot(x,y);
    }
    point normalize()const{
        return point(x/norm(),y/norm());
    }
    double dot(const point& rhs)const{
        return x*rhs.x+y*rhs.y;
    }
    point project(const point& rhs)const{
        point r=rhs.normalize();
        return r*r.dot(*this);
    }
};

int n;
point arr[1000];
point foot(point p,point a,point b){
    return a+(p-a).project(b-a);
}
double calc(point p,point a,point b){
    return (p-foot(p,a,b)).norm();
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&arr[i].x,&arr[i].y);
    double ans=2e9;
    for(int i=0;i<n;i++){
        int a,b,c;
        a=i;
        b=(i+1)%n;
        c=(i+2)%n;
        ans=min(ans,calc(arr[b],arr[a],arr[c])/2);
    }
    printf("%.10lf\n",ans);
    return 0;
}