#include <iostream>
#include <algorithm>
using namespace std;
int N;
unsigned long long H[100000];
unsigned long long search(int le, int ri)
{
	if (le == ri)
		return H[ri];
	unsigned long long _max = 0;
	int mid = (le + ri )/ 2;
	_max = max(_max, search(le, mid));
	_max = max(_max, search(mid + 1, ri));

	int lo, hi;
	lo = mid;
	hi = mid + 1;
	unsigned long long height = min(H[lo], H[hi]);
	_max = max(_max, height * 2);
	while (le < lo || hi < ri)
	{
		if (hi < ri && (lo == le || H[lo - 1] < H[hi + 1]))
		{
			hi++;
			height = min(height, H[hi]);
		}
		else
		{
			lo--;
			height = min(height, H[lo]);
		}
		_max = max(_max, height*(hi - lo + 1));
	}
	return _max;
}
int main() {
	while (true)
	{
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			cin >> H[i];
		cout << search(0, N - 1) << endl;
	}
	return 0;
}