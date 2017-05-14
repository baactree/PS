// =====================================================================================
// 
//       Filename:  10273.cpp
//        Created:  2017년 05월 13일 23시 40분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int t[1000];
int mat[1000][10];
bool died[1000];
int gcd(int a, int b){
	while(b){
		int temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
int get_lcm(){
	vector<int> temp;
	for(int i=0;i<n;i++)
		if(!died[i])
			temp.push_back(t[i]);
	if(temp.empty())
		return -1;
	int g=temp[0];
	int l=temp[0];
	for(int i=1;i<temp.size();i++){
		g=gcd(l, temp[i]);
		l=l/g*temp[i];
	}
	return l;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &t[i]);
			for(int j=0;j<t[i];j++)
				scanf("%d", &mat[i][j]);
		}
		memset(died, 0, sizeof(died));
		int l=get_lcm();
		int c, d;
		c=0;
		d=-1;
		int k=-1;
		while(true){
			bool flag=false;
			for(int i=0;i<l;i++){
				k++;
				int count=0;
				int min_value=1000;
				int idx=0;
				for(int j=0;j<n;j++){
					if(died[j])
						continue;
					if(min_value>mat[j][k%t[j]]){
						min_value=mat[j][k%t[j]];
						count=1;
						idx=j;
					}
					else if(min_value==mat[j][k%t[j]])
						count++;
				}
				if(count==1){
					flag=true;
					died[idx]=true;
					c++;
					d=k;
				}
			}
			if(!flag){
				break;
			}
		}
		printf("%d %d\n", n-c, d+1);
	}
	return 0;
}

