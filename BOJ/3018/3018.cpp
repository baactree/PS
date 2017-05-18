// =====================================================================================
// 
//       Filename:  3018.cpp
//        Created:  2017년 05월 19일 01시 18분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool song[101][100];
int n, e;
int main(){
	scanf("%d%d", &n, &e);
	int cnt=0;
	for(int i=0;i<e;i++){
		int k;
		scanf("%d", &k);
		bool flag=false;
		vector<int> a;
		for(int j=0;j<k;j++){
			int in;
			scanf("%d", &in);
			a.push_back(in);
			if(in==1)
				flag=true;
		}
		if(flag){
			for(int j=0;j<a.size();j++)
				song[a[j]][cnt]=true;
			cnt++;
		}
		else{
			bool check[100]={0, };
			for(int j=0;j<a.size();j++)
				for(int k=0;k<100;k++)
					check[k]|=song[a[j]][k];
			for(int j=0;j<a.size();j++)
				for(int k=0;k<100;k++)
					song[a[j]][k]|=check[k];
		}
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=0;j<100;j++)
			if(song[i][j])
				k++;
		if(k==cnt)
			printf("%d\n", i);
	}
	return 0;
}

