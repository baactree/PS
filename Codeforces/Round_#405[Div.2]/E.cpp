// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 03월 31일 16시 09분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<int> V, K, X;
int cache[77][77][77][2];
int calc(int v, int k, int x, int type) {
	int ret = 0;
	if (type == 0) {
		for (int i = v; i < V.size() && V[i] < V[v]; i++)
			ret++;
		for (int i = k; i < K.size() && K[i] < V[v]; i++)
			ret++;
		for (int i = x; i < X.size() && X[i] < V[v]; i++)
			ret++;
	}
	else if (type == 1) {
		for (int i = v; i < V.size() && V[i] < X[x]; i++)
			ret++;
		for (int i = k; i < K.size() && K[i] < X[x]; i++)
			ret++;
		for (int i = x; i < X.size() && X[i] < X[x]; i++)
			ret++;
	}
	else {
		for (int i = v; i < V.size() && V[i] < K[k]; i++)
			ret++;
		for (int i = k; i < K.size() && K[i] < K[k]; i++)
			ret++;
		for (int i = x; i < X.size() && X[i] < K[k]; i++)
			ret++;
	}
	return ret;
}
int solve(int v, int k, int x, int pre) {
	if (v + k + x == n)
		return 0;
	int &ret = cache[v][k][x][pre];
	if (ret != -1)
		return ret;
	ret = 0x3f3f3f3f;
	if(v!=V.size())
		ret = min(ret, solve(v + 1, k, x, 1) + calc(v, k, x, 0));
	if(x!=X.size())
		ret = min(ret, solve(v, k, x + 1, 0) + calc(v, k, x, 1));
	if (pre == 0&&k!=K.size())
		ret = min(ret, solve(v, k + 1, x, 0) + calc(v, k, x, 2));
	return ret;
}
int main() {
	cin >> n >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'V')
			V.push_back(i);
		else if (str[i] == 'K')
			K.push_back(i);
		else
			X.push_back(i);
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}
