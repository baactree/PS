#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        double a,b;
        int k;
        scanf("%lf%lf%d",&a,&b,&k);
        double c=hypot(a,b);
        double r=(a+b-c)/2;
        if(k==1){
            printf("%.10lf\n",pi*r*r);
            continue;
        }
        k--;
        priority_queue<pair<double,double> > pq;
        vector<double> vec;
        vec.push_back(b-r);
        vec.push_back(a-r);
        vec.push_back(r);
        for(int i=0;i<vec.size();i++){
            double w=vec[i];
            double h=hypot(w,r);
            double cost=w/h;
            h-=r;
            double n=h/cost;
            double m=sqrt(n*n-h*h);
            double r=(m*h)/(n+m);
            pq.push({r,h});
        }
        double ans=0;
        while(!pq.empty()){
            double r=pq.top().first;
            double h=pq.top().second;
            pq.pop();
            k--;
            if(k==0){
                ans=r;
                break;
            }
            double nh=h-2*r;
            double nr=nh*r/h;
            pq.push({nr,nh});
        }
        printf("%.10lf\n",ans*ans*pi);
    }
    return 0;
}