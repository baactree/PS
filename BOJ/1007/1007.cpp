// =====================================================================================
// 
//       Filename:  1007.cpp
//        Created:  2017년 03월 05일 17시 41분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> p[20];
bool picked[20];
double get_sum(){
	int sx, sy, fx, fy;
	sx=sy=fx=fy=0;
	for(int i=0;i<n;i++){
		if(picked[i]){
			sx+=p[i].first;
			sy+=p[i].second;
		}
		else{
			fx+=p[i].first;
			fy+=p[i].second;
		}
	}
	return hypot(fx-sx, fy-sy);
}
double make_vector(int idx, int pick){
	if(pick==n/2)
		return get_sum();
	if(idx==n)
		return 1e9;
	double ret=make_vector(idx+1, pick);
	picked[idx]=true;
	double temp=make_vector(idx+1, pick+1);
	picked[idx]=false;
	ret=min(ret, temp);
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(picked, 0, sizeof(picked));
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		printf("%.6lf\n", make_vector(0, 0));
	}
	return 0;
}

