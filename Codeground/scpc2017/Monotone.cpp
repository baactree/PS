// =====================================================================================
// 
//       Filename:  Monotone.cpp
//        Created:  2017년 07월 01일 00시 07분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

struct point{
	long long x,y;
	point(){}
	point(long long x,long long y):x(x),y(y){}
	point operator - (const point &rhs)const{
		return point(x-rhs.x,y-rhs.y);
	}
	long long cross(const point &rhs)const{
		return x*rhs.y-y*rhs.x;
	}
};
int ccw(point a,point b){
	long long now=a.cross(b);
	if(now>0)
		return 1;
	if(now<0)
		return -1;
	return 0;
}
int ccw(point p,point a,point b){
	return ccw(a-p,b-p);
}
int n;
point arr[50000];
const double pi=acos(-1.0);
vector<pair<double,double> > t;
//안되는 경우에 추가
//안되는 영역 theta2 ~ 180 + theta1 , 180+ theta2 ~ theta1
void calc(point a,point b){
	double t1,t2;
	t1=atan2((double)a.y,(double)a.x);
	t2=atan2((double)b.y,(double)b.x);
	if(t1<0)
		t1+=2*pi;
	if(t2<0)
		t2+=2*pi;
	double pt1,pt2;
	pt1=t1+pi;
	pt2=t2+pi;
	if(pt1>2*pi)
		pt1-=2*pi;
	if(pt2>2*pi)
		pt2-=2*pi;
	if(pt1>t2){
		t.push_back(make_pair(t2,pt2));
	}
	else{
		t.push_back(make_pair(t2,2*pi));
		t.push_back(make_pair(0,pt2));
	}
	if(t1>pt2){
		t.push_back(make_pair(pt2,t1));
	}
	else{
		t.push_back(make_pair(pt2,2*pi));
		t.push_back(make_pair(0,t1));
	}
}
bool possi(){
	double now=0;
	for(int i=0;i<t.size();i++){
		if(now>=t[i].first){
			now=max(now,t[i].second);
		}
		else
			return false;
	}
	return now>=2*pi;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			arr[i].x=a;
			arr[i].y=b;
		}
		t.clear();
		for(int i=0;i<n;i++){
			point p=arr[i];
			point a=arr[(i+1)%n];
			point b=arr[(i+2)%n];
			//a가 오목점임
			if(ccw(p,a,b)==-1){
				calc(p-a,b-a);
			}
		}
		sort(t.begin(),t.end());
		printf("Case #%d\n",tc);
		printf("%s\n", possi()?"NO":"YES");
	}
}

