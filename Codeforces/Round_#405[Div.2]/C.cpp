// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 03월 31일 16시 08분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n, k;
string arr[60];
bool check[60];
int input[60];
string ans[50];
int par[60];
int main() {
	for (int i = 0; i < 26; i++)
		arr[i] = i + 'A';
	for (int i = 26; i < 26 + 26; i++) {
		arr[i] = 'A' + i - 26;
		arr[i] += "a";
	}
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - k + 1; i++) {
		string temp;
		cin >> temp;
		if (temp == "NO") {
			input[i] = 0;
		}
		else input[i] = 1;
	}
	int idx = 0;
	for (int i = 0; i < k - 1; i++) {
		ans[i] = arr[idx++];
	}
	memset(par, -1, sizeof(par));
	for (int i = 0; i < n - k + 1; i++) {
		if (input[i]) {
			ans[i + k - 1] = arr[idx++];
		}
		else {
			ans[i + k - 1] = arr[idx++];
			par[i + k - 1] = i;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (par[i] != -1) {
			string s = ans[i];
			int temp = par[i];
			while (temp != -1) {
				par[i] = -1;
				ans[temp] = s;
				temp = par[temp];
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
