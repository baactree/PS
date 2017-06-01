// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 06월 01일 23시 24분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
string arr[105];
int le[105];
int ri[105];
int cache[105][2];
int fi;
const int inf=0x3f3f3f3f;
int solve(int idx, int mode){
	int &ret=cache[idx][mode];
	if(ret!=-1)
		return ret;
	ret=inf;
	if(mode){
		if(idx==fi){
			return ret=m+1-le[idx];
		}
		else{
			ret=min(ret, solve(idx-1, 0)+m+1+1);
			if(le[idx]!=inf){
				ret=min(ret, solve(idx-1, 1)+(m+1-le[idx])*2+1);
			}
			else{
				ret=min(ret, solve(idx-1, 1)+1);
			}
		}
	}
	else{
		if(idx==fi)
			return ret=ri[idx];
		else{
			if(ri[idx]!=-1){
				ret=min(ret, solve(idx-1, 0)+ri[idx]*2+1);
			}
			else{
				ret=min(ret, solve(idx-1, 0)+1);
			}
			ret=min(ret, solve(idx-1, 1)+m+1+1);
		}
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	memset(le, 0x3f, sizeof(le));
	memset(ri, -1, sizeof(ri));
	scanf("%d%d", &n, &m);
	fi=inf;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<arr[i].size();j++){
			if(arr[i][j]=='1'){
				le[i]=min(le[i], j);
				ri[i]=max(ri[i], j);
				fi=min(fi, i);
			}
		}
	}
	if(fi==inf){
		printf("0\n");
		return 0;
	}
	printf("%d\n", solve(n-1, 0));
	return 0;
}

