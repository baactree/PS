// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 29일 12시 06분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = 2.0 * acos(0.0);
struct point{
	ll x, y;
	point(){}
	point(ll x, ll y) :x(x), y(y) {}
	bool operator == (const point& rhs)const {
		return x == rhs.x&&y == rhs.y;
	}
	bool operator < (const point& rhs)const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	point operator + (const point&rhs)const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator - (const point&rhs)const {
		return point(x - rhs.x, y - rhs.y);
	}
	point operator * (int rhs)const {
		return point(x*rhs, y*rhs);
	}
	point operator / (int rhs)const{
		return point(x/rhs, y/rhs);
	}
	//외적
	ll cross(const point&rhs)const {
		return x*rhs.y - rhs.x*y;
	}
};
int ccw(point a, point b){
	ll ret=a.cross(b);
	if(ret>0)
		return 1;
	if(ret<0)
		return -1;
	return 0;
}
int ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}
int calc(point a, point b, point c, point d){
	int ab=ccw(a, b, c)*ccw(a, b, d);
	int cd=ccw(c, d, a)*ccw(c, d, b);
	if(ab==0&&cd==0){
		if(b<a)swap(a, b);
		if(d<c)swap(c, d);
		if(!(b<c||d<a))
			return 1;
		return 0;
	}
	if(ab<=0&&cd<=0){
		if(ab<0&&cd<0)
			return 2;
		return 1;
	}
	return 0;
}
int n, k;
vector<point> arr;
vector<point> t;
bool inside(point q, const vector<point> &p){
	int ret=0;
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		if((p[i].y>q.y)!=(p[j].y>q.y)){
			if(p[j].y-p[i].y>0){
				if((q.x-p[i].x)*(p[j].y-p[i].y)<(p[j].x-p[i].x)*(q.y-p[i].y))
					++ret;
			}
			else{
				if((q.x-p[i].x)*(p[j].y-p[i].y)>(p[j].x-p[i].x)*(q.y-p[i].y))
					++ret;
			}
		}
	}
	return ret%2>0;
}
bool onside(point q, const vector<point> &p){
	for(int i=0;i<p.size();i++){
		int j=(i+1)%p.size();
		if(ccw(p[i], p[j], q)==0)
			return true;
	}
	return false;
}
int solve(){
	int cnt1=0, cnt2=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			int temp=calc(t[i], t[(i+1)%3], arr[j], arr[(j+1)%n]);
			if(temp==1)
				cnt1++;
			if(temp==2)
				cnt2++;
		}
	}
	if(cnt2)
		return 4;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(inside(arr[i], t)||onside(arr[i], t))
			cnt++;
	}
	if(cnt==n)
		return 4;
	point p=(t[0]+t[1]+t[2])/3;
	if(inside(p, arr))
		return 1;
	if(cnt1)
		return 3;
	return 2;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		arr.clear();
		arr.resize(n);
		for(int i=0;i<n;i++){
			scanf("%lld%lld", &arr[i].x, &arr[i].y);
			arr[i]=arr[i]*3;
		}
		vector<int> ans;
		scanf("%d", &k);
		for(int i=0;i<k;i++){
			t.clear();
			t.resize(3);
			for(int j=0;j<3;j++){
				scanf("%lld%lld", &t[j].x, &t[j].y);
				t[j]=t[j]*3;
			}
			ans.push_back(solve());
		}
		for(int i=0;i<k;i++)
			printf("%d%s", ans[i], (i==k-1?"\n":" "));
	}
	return 0;
}

