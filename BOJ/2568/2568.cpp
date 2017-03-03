// =====================================================================================
// 
//       Filename:  2568.cpp
//        Created:  2017년 02월 25일 20시 39분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100000];
int n;
vector<int> lis;
vector<int> ans;
pair<int, int> tree[500005];
int p[500005];
pair<int, int> query(int x){
	x++;
	pair<int, int> ret={0, 0};
	while(x){
		ret=max(ret, tree[x]);
		x-=x&(-x);
	}
	return ret;
}
void update(int x, pair<int, int> val){
	x++;
	while(x<500005){
		tree[x]=max(tree[x], val);
		x+=x&(-x);
	}
}
bool chk[500005];
int main(){
	memset(p, -1, sizeof(p));
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &arr[i].first, &arr[i].second);
		chk[arr[i].first]=true;
	}
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		pair<int, int> now=query(arr[i].second);
		update(arr[i].second, {now.first+1, arr[i].first});
		if(now.first!=0)
			p[arr[i].first]=now.second;
	}
	pair<int, int> ans=query(500000);
	printf("%d\n",n-ans.first);
	int temp=ans.second;
	while(temp!=-1){
		chk[temp]=false;
		temp=p[temp];
	}
	for(int i=0;i<500005;i++)
		if(chk[i])
			printf("%d\n", i);
	return 0;
}

