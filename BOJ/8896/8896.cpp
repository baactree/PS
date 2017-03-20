// =====================================================================================
// 
//       Filename:  8896.cpp
//        Created:  2017년 03월 20일 19시 15분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[10];
int n;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<int> check(n, 0);
		for(int i=0;i<arr[0].size();i++){
			map<char, int> m;
			for(int j=0;j<n;j++){
				if(check[j])
					continue;
				m[arr[j][i]]=1;
			}
			if(m.size()==3||m.size()==1)
				continue;
			else{
				if(m.count('R')!=0&&m.count('P')!=0){
					for(int j=0;j<n;j++){
						if(arr[j][i]=='R')
							check[j]=true;
					}
				}
				else if(m.count('R')!=0&&m.count('S')!=0){
					for(int j=0;j<n;j++){
						if(arr[j][i]=='S')
							check[j]=true;
					}
				}
				else{
					for(int j=0;j<n;j++){
						if(arr[j][i]=='P')
							check[j]=true;
					}
				}
			}
		}
		int cnt=0;
		int idx;
		for(int i=0;i<n;i++){
			if(!check[i]){
				cnt++;
				idx=i;
			}
		}
		if(cnt!=1)
			printf("0\n");
		else
			printf("%d\n", idx+1);

	}
	return 0;
}

