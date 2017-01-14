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
pair<int, string> arr[25] = { { 1967,"DavidBowie" },{ 1969,"SpaceOddity" },{ 1970,"TheManWhoSoldTheWorld" },{ 1971,"HunkyDory" },{ 1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars" },{ 1973,"AladdinSane" },{ 1973,"PinUps" },{ 1974,"DiamondDogs" },{ 1975,"YoungAmericans" },{ 1976,"StationToStation" },{ 1977,"Low" },{ 1977,"Heroes" },{ 1979,"Lodger" },{ 1980,"ScaryMonstersAndSuperCreeps" },{ 1983,"LetsDance" },{ 1984,"Tonight" },{ 1987,"NeverLetMeDown" },{ 1993,"BlackTieWhiteNoise" },{ 1995,"1.Outside" },{ 1997,"Earthling" },{ 1999,"Hours" },{ 2002,"Heathen" },{ 2003,"Reality" },{ 2013,"TheNextDay" },{ 2016,"BlackStar" } };
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int cnt = 0;
		for (int j = 0; j < 25; j++) {
			if (arr[j].first >= a&&arr[j].first <= b)
				cnt++;
		}
		printf("%d\n", cnt);
		for (int j = 0; j < 25; j++)
			if (arr[j].first >= a&&arr[j].first <= b)
				cout << arr[j].first << " " << arr[j].second << endl;
	}
	return 0;
}