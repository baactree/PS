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
int main() {
	string str1, str2;
	int N;
	cin >> N >> str1 >> str2;
	if (N & 1) {
		for (int i = 0; i < str1.size(); i++)
			if (str1[i] == '0')
				str1[i] = '1';
			else
				str1[i] = '0';

		if (str1 == str2)
			cout << "Deletion succeeded" << endl;
		else
			cout << "Deletion failed" << endl;

	}
	else {
		if (str1 == str2)
			cout << "Deletion succeeded" << endl;
		else
			cout << "Deletion failed" << endl;
	}
	return 0;
}
