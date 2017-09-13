// =====================================================================================
// 
//       Filename:  13328.cpp
//        Created:  2017년 09월 13일 19시 34분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=31991;
struct Matrix{
	int n, m;
	vector<vector<int> > mat;
	Matrix(){}
	Matrix(int n, int m):n(n), m(m){
		mat=vector<vector<int> >(n, vector<int>(m, 0));
	}
	Matrix operator * (const Matrix &rhs)const{
		Matrix ret(n, rhs.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<rhs.m;j++)
				for(int k=0;k<m;k++)
					ret.mat[i][j]=(ret.mat[i][j]+(mat[i][k]*rhs.mat[k][j])%mod)%mod;
		return ret;
	}
};
int d, t;
int dp[50];
Matrix mpow(Matrix a, int b){
	if(b==1)
		return a;
	Matrix temp=mpow(a, b/2);
	temp=temp*temp;
	if(b&1)
		return temp*a;
	return temp;
}
int main(){
	scanf("%d%d", &d, &t);
	dp[0]=1;
	int s=1;
	for(int i=1;i<d;i++){
		dp[i]=s;
		s=(s+dp[i])%mod;
	}
	Matrix p(d, 1);
	for(int i=0;i<d;i++)
		p.mat[i][0]=dp[i];
	Matrix f(d, d);
	for(int i=0;i<d-1;i++)
		f.mat[i][i+1]=1;
	for(int i=0;i<d;i++)
		f.mat[d-1][i]=1;
	f=mpow(f, t);
	Matrix ans=f*p;
	printf("%d\n", ans.mat[0][0]);
	return 0;
}

