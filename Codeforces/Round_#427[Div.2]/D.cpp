// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 08월 01일 00시 12분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
bool p[2][5005][5005];
int ans[5005];
int main(){
	cin>>str;
	int n=str.size();
	for(int k=1, q=1;q<=n;q*=2, k++){
		int now=k&1;
		int pre=(k-1)&1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				p[now][i][j]=0;
		if(k==1){
			for(int i=0;i<n;i++){
				int le, ri;
				le=ri=i;
				while(le>=0&&ri<n&&str[le]==str[ri]){
					p[now][le][ri]=true;
					le--;
					ri++;
					ans[k]++;
				}
				le=i;
				ri=i+1;
				while(le>=0&&ri<n&&str[le]==str[ri]){
					p[now][le][ri]=true;
					le--;
					ri++;
					ans[k]++;
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				for(int j=i+q-1;j<n;j++){
					int mid=i+(j-i+1)/2-1;
					if(p[pre][i][j]&&p[pre][i][mid]){
						p[now][i][j]=true;
						ans[k]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

