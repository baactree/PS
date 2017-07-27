#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-10;
struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    point operator - (const point &rhs)const{
        return point(x-rhs.x,y-rhs.y);
    }
    point operator * (const double rhs)const{
        return point(x*rhs,y*rhs);
    }
    point operator + (const point &rhs)const{
        return point(x+rhs.x,y+rhs.y);
    }
    bool operator ==(const point &rhs)const{
        return std::fabs(x-rhs.x)<=eps&&std::fabs(y-rhs.y)<=eps;
    }
    bool operator < (const point &rhs)const{
        if(x==rhs.x)
            return y<rhs.y;
        return x<rhs.x;
    }
    double cross(const point &rhs)const{
        return x*rhs.y-y*rhs.x;
    }
    double polar()const{
        double ret=atan2(y,x);
        if(ret<0)
            ret+=2*pi;
        return ret;
    }
};
string in;
point arr[3];
vector<double> theta;
double calc(const point &p,const point &a,const point &b){
    double ret=fabs((a-p).polar()-(b-p).polar());
    if(ret>=pi)
        ret=2*pi-ret;
    return ret;
}
bool possi(int k){
    double r=pi/k;
    int cnt=0;
    for(int i=0;i<3;i++)
        cnt+=theta[i]/r+eps;
    return cnt==k;
}
int main(){
    while(true){
        for(int i=0;i<3;i++){
            getline(cin,in);
            if(in=="END")
                return 0;
            sscanf(in.c_str(),"%lf%lf",&arr[i].x,&arr[i].y);
        }
        theta.clear();
        double sum=0;
        for(int i=0;i<3;i++){
            int p=i;
            int a=(i+1)%3;
            int b=(i+2)%3;
            theta.push_back(calc(arr[p],arr[a],arr[b]));
            sum+=theta[i];
        }
        if(fabs(sum-pi)>eps)
            while(true);
        for(int i=3;i<=1000;i++)
            if(possi(i)){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}