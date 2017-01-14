/////////////////////////////////////////////////////
#ifdef _DEBUG
#include "bits_stdc++.h"
#else
#include "bits/stdc++.h"
#endif
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<pii > > Edge;
typedef unsigned long long llu;
typedef long long ll;
typedef priority_queue<pii > Pq;
typedef vector<int>::iterator It;
#define INF 0x3f3f3f3f
#define UINF 0xffffffffu
#define LINF 0x3f3f3f3f3f3f3f3fll
#define MOD 1000000007
#define EOD 1e-9
#define all(x) x.begin(),x.end()
const double PI = acos(0.0)*2.0;
/////////////////////////////////////////////////////
int N;
string pivot;
int alpa[26];
string cmp;
extern inline bool possi(string str) {
	if (pivot.size()  <= cmp.size() + 1 && cmp.size() <= pivot.size() + 1) {
		int now[26];
		memset(now, 0, sizeof(now));
		for (int i = 0; i < cmp.size(); i++)
			now[cmp[i] - 'A']++;
		//걍 일치하는 경우
		bool flag = true;
		for (int i = 0; i < 26; i++)
			if (now[i] != alpa[i])
				flag = false;
		if (flag)
			return true;
		//글자 하나 추가 해서 가능한 경우
		if (pivot.size() + 1 == cmp.size()) {
			int temp[26];
			for (int i = 0; i < 26; i++)
				temp[i] = now[i];
			for(int i = 0; i < 26; i++)
				temp[i] -= alpa[i];
			int cnt = 0;
			bool flag = true;
			for (int i = 0; i < 26; i++)
				if (temp[i] != 0 && temp[i] != 1)
					flag = false;
				else if (temp[i] == 1)
					cnt++;
			if (cnt == 1 && flag)
				return true;
		}
		//글자 하나 제거 해서 가능한 경우
		if (pivot.size() == cmp.size() + 1) {
			int temp[26];
			for (int i = 0; i < 26; i++)
				temp[i] = alpa[i];
			for (int i = 0; i < 26; i++)
				temp[i] -= now[i];
			int cnt = 0;
			bool flag = true;
			for (int i = 0; i < 26; i++)
				if (temp[i] != 0 && temp[i] != 1)
					flag = false;
				else if (temp[i] == 1)
					cnt++;
			if (cnt == 1 && flag)
				return true;
		}
		//글자 하나 바꿔서 가능한 경우
		if (pivot.size() == cmp.size()) {
			int minus, plus;
			minus = plus = 0;
			for (int i = 0; i < 26; i++) {
				now[i] -= alpa[i];
				if (now[i] < -1 || now[i]>1)
					return false;
				if (now[i] == -1)
					minus++;
				if (now[i] == 1)
					plus++;
			}
			if (minus == 1 && plus == 1)
				return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &N);
	cin >> pivot;
	for (int i = 0; i < pivot.size(); i++)
		alpa[pivot[i] - 'A']++;
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		cin >> cmp;
		if (possi(cmp))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}