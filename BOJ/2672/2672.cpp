// =====================================================================================
// 
//       Filename:  2672.cpp
//        Created:  2017년 04월 25일 00시 47분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line{
	ll x, y1, y2;
	bool mode;
	Line(){}
	Line(ll x, ll y1, ll y2, bool mode):x(x), y1(y1), y2(y2), mode(mode){}
	bool operator < (const Line &rhs)const{
		if(x==rhs.x){
			if(y1==rhs.y1){
				if(y2==rhs.y2){
					return mode<rhs.mode;
				}
				return y2<rhs.y2;
			}
			return y1<rhs.y1;
		}
		return x<rhs.x;
	}
};
ll get_int(){
	double in;
	scanf("%lf", &in);
	return in*10;
}
int n;
vector<ll> y;
vector<Line> arr;
vector<pair<ll, ll> >tree;
void update(int le, int ri, ll val, int nodele, int noderi, int node){
	if(noderi<le||ri<nodele)
		return;
	if(le<=nodele&&noderi<=ri){
		tree[node].second+=val;
		if(tree[node].second==0){
			if(nodele!=noderi){
				tree[node].first=tree[node*2].first+tree[node*2+1].first;
			}
			else
				tree[node].first=0;
		}
		else{
			tree[node].first=y[noderi+1]-y[nodele];
		}
		return;
	}
	int mid=(nodele+noderi)/2;
	update(le, ri, val, nodele, mid, node*2);
	update(le, ri, val, mid+1, noderi, node*2+1);
	if(tree[node].second==0){
		tree[node].first=tree[node*2].first+tree[node*2+1].first;
	}
	else{
		tree[node].first=y[noderi+1]-y[nodele];
	}
	return;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		ll a, b, c, d;
		a=get_int();
		b=get_int();
		c=get_int();
		d=get_int();
		c=abs(c);
		d=abs(d);
		arr.push_back({a, b, b+d, 0});
		arr.push_back({a+c, b, b+d, 1});
		y.push_back(b);
		y.push_back(b+d);
	}
	sort(arr.begin(), arr.end());
	sort(y.begin(), y.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	tree=vector<pair<ll, ll> >(y.size()*4, {0, 0});
	ll ans=0;
	ll x=-0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<arr.size();i++){
		ans+=(arr[i].x-x)*tree[1].first;
		x=arr[i].x;
		if(arr[i].y1==arr[i].y2)
			continue;
		int le=lower_bound(y.begin(), y.end(), arr[i].y1)-y.begin();
		int ri=lower_bound(y.begin(), y.end(), arr[i].y2)-y.begin()-1;
		update(le, ri, arr[i].mode?-1:1, 0, y.size()-1, 1);
	}
	if(ans%100==0)
		printf("%lld\n", ans/100);
	else
		printf("%.2lf\n", ans/100.);
	return 0;
}

