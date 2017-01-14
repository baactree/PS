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
int arr[8];
int incre[8] = { 1,2,3,4,5,6,7,8 };
int decre[8] = { 8,7,6,5,4,3,2,1 };
bool inc() {
	for (int i = 0; i < 8; i++)
		if (arr[i] != incre[i])
			return false;
	return true;
}
bool dec() {
	for (int i = 0; i < 8; i++)
		if (arr[i] != decre[i])
			return false;
	return true;
}
int main() {
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);
	if (inc())
		printf("ascending\n");
	else if (dec())
		printf("descending\n");
	else
		printf("mixed\n");
	return 0;
}
