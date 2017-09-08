// =====================================================================================
// 
//       Filename:  colony.cpp
//        Created:  2017년 09월 07일 16시 06분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100005], b[100005];
int tree[300005];
void update(int idx, int val){
	idx++;
	while(idx<300005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	idx++;
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
bool possi(int k){
	//x = y-x
	//y = y+x
	vector<int> yidx;
	vector<pair<pair<int, int>, pair<int, int> > > vec;
	for(int i=1;i<=k;i++){
		int x1=b[i].second-b[i].first;
		int y1=b[i].first+b[i].second;
		yidx.push_back(y1);
		vec.push_back({{x1, 0}, {y1, y1}});
		int d=k-i;
		x1=a[i].second-a[i].first+d;
		int x2=a[i].second-a[i].first-d;
		y1=a[i].second+a[i].first-d;
		int y2=a[i].second+a[i].first+d+1;
		yidx.push_back(y1);
		yidx.push_back(y2);
		vec.push_back({{x2, -1}, {y1, y2}});
		vec.push_back({{x1, 1}, {y1, y2}});
	}
	sort(yidx.begin(), yidx.end());
	yidx.erase(unique(yidx.begin(), yidx.end()), yidx.end());
	memset(tree, 0, sizeof(tree));
	sort(vec.begin(), vec.end());
	for(int i=0;i<vec.size();i++){
		int type=vec[i].first.second;
		int y1=vec[i].second.first;
		int y2=vec[i].second.second;
		y1=lower_bound(yidx.begin(), yidx.end(), y1)-yidx.begin();
		y2=lower_bound(yidx.begin(), yidx.end(), y2)-yidx.begin();
		if(type==-1){
			update(y1, 1);
			update(y2, -1);
		}
		else if(type==0){
			if(query(y1))
				return true;
		}
		else{
			update(y1, -1);
			update(y2, 1);
		}
	}
	return false;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d", &a[i].first, &a[i].second, &b[i].first, &b[i].second);
		int le, ri, mid, ans;
		le=1;
		ri=n;
		ans=-1;
		while(le<=ri){
			mid=(le+ri)/2;
			if(possi(mid)){
				ans=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}

