// =====================================================================================
// 
//       Filename:  1064.cpp
//        Created:  2017년 05월 08일 17시 23분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[3];
vector<long double> ans;
long double calc(int x){
	long double ret=0;
	for(int i=0;i<3;i++){
		if(i==x)
			continue;
		int dx=arr[x].first-arr[i].first;
		int dy=arr[x].second-arr[i].second;
		ret+=2*sqrt((long double)dx*dx+dy*dy);
	}
	return ret;
}
bool possi(){
	int x1, x2, y1, y2;
	x1=arr[1].first-arr[0].first;
	y1=arr[1].second-arr[0].second;
	x2=arr[2].first-arr[0].first;
	y2=arr[2].second-arr[0].second;
	return abs(x1*y2-x2*y1)>0;
}
int main(){
	for(int i=0;i<3;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	if(!possi()){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<3;i++)
		ans.push_back(calc(i));
	sort(ans.begin(), ans.end());
	printf("%.10Lf\n", ans[2]-ans[0]);
	return 0;
}

