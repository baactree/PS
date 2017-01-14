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
char input[5005];
int cnt[26];
int main() {
	int max_cnt = 0;
	while (scanf("%s", input) != EOF) {
		int len = strlen(input);
		for (int i = 0; i < len; i++)
			if(input[i]>='a'&&input[i]<='z')
				cnt[input[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		max_cnt = max(max_cnt, cnt[i]);
	for(int i=0;i<26;i++)
		if(cnt[i]==max_cnt)
			printf("%c", i + 'a');
	printf("\n");
	return 0;
}