// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 17일 02시 23분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
	int x, y;
	point(){}
	point(int x, int y):x(x), y(y){}
	ll cross(const point &rhs)const{
		return (ll)x*rhs.y-(ll)y*rhs.x;
	}
	point operator - (const point &rhs)const{
		return point(x-rhs.x, y-rhs.y);
	}
};
int ccw(point a, point b){
	ll k=a.cross(b);
	if(k>0)
		return 1;
	if(k<0)
		return -1;
	return 0;
}
int ccw(point p, point a, point b){
	return ccw(a-p, b-p);
}
bool operator < (const point &a, const point &b){
	return ccw(a, b)>0;
}
bool operator ==(const point &a, const point &b){
	return ccw(a, b)==0;
}
int n;
vector<point> g[100005];
vector<int> gi[100005];
int pivot;
struct Node{
	int idx;
	Node(){}
	Node(int idx):idx(idx){}
	bool operator < (const Node &rhs)const{
		int t1=upper_bound(gi[idx].begin(), gi[idx].end(), pivot)-gi[idx].begin();
		int t2=upper_bound(gi[rhs.idx].begin(), gi[rhs.idx].end(), pivot)-gi[rhs.idx].begin();
		point a=g[idx][t1-1], b=g[idx][t1], c=g[rhs.idx][t2-1], d=g[rhs.idx][t2];
		if(gi[idx][t1-1]>gi[rhs.idx][t2-1])
			return ccw(c, d, a)>0;
		else
			return ccw(a, b, c)<0;
	}
};
vector<int> st[1000005], ed[1000005];
bool chk[100005];
int main(){
	scanf("%d", &n);
	vector<point> arr;
	for(int i=0;i<n;i++){
		int m;
		scanf("%d", &m);
		vector<point> vec;
		for(int j=0;j<m;j++){
			int a, b;
			scanf("%d%d", &a, &b);
			vec.push_back({a, b});
		}
		int le, ri;
		le=ri=0;
		for(int j=0;j<m;j++){
			if(ccw(vec[le], vec[j])>0||(ccw(vec[le], vec[j])==0&&vec[j].y<vec[le].y))
				le=j;
			if(ccw(vec[ri], vec[j])<0||(ccw(vec[ri], vec[j])==0&&vec[j].y<vec[ri].y))
				ri=j;
		}
		for(int j=le;;j=(j+1)%m){
			g[i].push_back(vec[j]);
			arr.push_back(vec[j]);
			if(j==ri)
				break;
		}
		reverse(g[i].begin(), g[i].end());
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<g[i].size();j++){
			int now=lower_bound(arr.begin(), arr.end(), g[i][j])-arr.begin();
			gi[i].push_back(now);
		}
	}
	for(int i=0;i<n;i++){
		st[gi[i][0]].push_back(i);
		ed[gi[i].back()].push_back(i);
	}
	set<Node> s;
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<ed[i].size();j++){
			int now=ed[i][j];
			s.erase(Node(now));
		}
		pivot=i;
		for(int j=0;j<st[i].size();j++){
			int now=st[i][j];
			s.insert(Node(now));
		}
		if(!s.empty())
			chk[(*s.begin()).idx]=true;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		if(!chk[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}

