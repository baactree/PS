// =====================================================================================
// 
//       Filename:  1528.cpp
//        Created:  2017년 08월 01일 14시 02분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cache[1000005];
vector<int> vec({4, 7});
vector<int> ans;
int solve(int idx){
	if(idx==0)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	for(int i=0;i<vec.size()&&vec[i]<=idx;i++)
		ret=min(ret, solve(idx-vec[i])+1);
	return ret;
}
void get_ans(int idx){
	if(idx==0)
		return;
	int k=-1;
	int min_value=0x3f3f3f3f;
	for(int i=0;i<vec.size()&&vec[i]<=idx;i++){
		int now=solve(idx-vec[i])+1;
		if(now<min_value){
			min_value=now;
			k=i;
		}
	}
	ans.push_back(vec[k]);
	get_ans(idx-vec[k]);
}
int main(){
	scanf("%d", &n);
	int pre=0;
	for(int i=0;i<5;i++){
		int npre=vec.size();
		for(int j=pre;j<npre;j++){
			vec.push_back(vec[j]*10+4);
			vec.push_back(vec[j]*10+7);
		}
		pre=npre;
	}
	memset(cache, -1, sizeof(cache));
	int cnt=solve(n);
	if(cnt==0x3f3f3f3f)
		return !printf("-1\n");
	get_ans(n);
	for(auto x:ans)
		printf("%d ", x);
	printf("\n");
	return 0;
}

