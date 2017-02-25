// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 02월 24일 19시 35분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr[100000];
int k;
pair<int, int> q[100000];
int max_t[100000];
vector<vector<int> > mat;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int in;
			scanf("%d", &in);
			arr[i].push_back(in);
		}
	}
	scanf("%d", &k);
	mat = vector<vector<int> > (n, vector<int>(m, 0));
	for(int i=0;i<m;i++){
		int now=0;
		int cnt=0;
		for(int j=0;j<n;j++){
			if(now<=arr[j][i]){
				now=arr[j][i];
				cnt++;
			}
			else{
				for(int k=0;k<cnt;k++){
					mat[j-1-k][i]=k;
				}
				now=arr[j][i];
				cnt=1;
			}
		}
		for(int k=0;k<cnt;k++)
			mat[n-1-k][i]=k;
	}
	for(int i=0;i<n;i++){
		int temp=-1;
		for(int j=0;j<m;j++){
			temp=max(temp, mat[i][j]);
		}
		max_t[i]=temp;
	}
	for(int i=0;i<k;i++){
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		if(max_t[l]>=r-l){
			printf("Yes\n");
		}else
			printf("No\n");
	}
	return 0;
}

