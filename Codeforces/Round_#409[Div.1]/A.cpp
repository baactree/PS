#include <bits/stdc++.h>
using namespace std;
int n;
double p;
pair<int,int> arr[100000];
//double e=1e-6;
double inf=1e10;
bool possi(double x){
    double sum=0;
    for(int i=0;i<n;i++){
        double temp=arr[i].second/p-arr[i].first/p*x;
        if(temp<0)
            sum-=temp;
        if(sum>=x)
            return false;
    }
    return true;
}
int main(){
    scanf("%d%lf",&n,&p);
    long long sum=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        sum+=arr[i].first;
    }
    if(p>=sum){
        printf("-1\n");
        return 0;
    }
    double le,ri,mid;
    le=0;
    ri=inf;
    for(int i=0;i<100;i++){
        mid=(le+ri)/2;
        if(possi(mid)){
            le=mid;
        }
        else
            ri=mid;
    }
    printf("%.6lf\n",le);
    return 0;
}