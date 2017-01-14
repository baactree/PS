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
pair<string, double> arr[13] = { {"A+",4.3},{"A0",4.0},{"A-",3.7},
{"B+",3.3},{"B0",3.0},{"B-",2.7},{"C+",2.3},{"C0",2.0},{"C-",1.7},{"D+",1.3},{"D0",1.0},{"D-",0.7},{"F",0.0} };
int main() {
	scanf("%d", &N);
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string str;
		int h;
		string score;
		cin >> str >> h >> score;
		cnt += h;
		for (int i = 0; i < 13; i++) {
			if (score == arr[i].first)
				sum += arr[i].second*h;
		}
	}
	printf("%.2f\n", sum / cnt+EOD);
	return 0;
}