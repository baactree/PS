// =====================================================================================
// 
//       Filename:  1092.cpp
//        Created:  2017년 04월 12일 11시 40분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int w[50];
int m;
int b[10000];
bool used[10000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &w[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
		scanf("%d", &b[i]);
	sort(w, w+n);
	sort(b, b+m);
	int ans=0;
	int cnt=0;
	while(true){
		bool update=false;
		int bidx=m-1;
		for(int i=n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				if(!used[j]&&w[i]>=b[j]){
					used[j]=true;
					cnt++;
					update=true;
					break;
				}
			}
		}
		if(!update)
			break;
		ans++;
	}
print:
	printf("%d\n", cnt!=m?-1:ans);
	return 0;
}

