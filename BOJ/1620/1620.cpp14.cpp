/////////////////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;
typedef vector<vector<pair<int, int> > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pair<int, int> > Pq;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int N, M;
map<string, string> arr1;
map<string, string> arr2;
char input[21];
string str;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		//cin >> str;
		scanf("%s", input);
		str = input;
		arr1[str] = to_string(i);
		arr2[to_string(i)] = str;
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", input);
		str = input;
		//cin >> str;
		if (str[0] >= 'A'&&str[0] <= 'Z') {
			cout << arr1[str] << '\n';
		}
		else {
			cout << arr2[str] << '\n';
		}
	}
	return 0;
}