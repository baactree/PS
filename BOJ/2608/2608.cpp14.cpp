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
int roman[255];
string A, B;
int a, b;
int roma_to_num(string &str) {
	int len = str.size();
	vector<int> arr(len);
	for (int i = 0; i < len; i++) 
		arr[i] = roman[str[i]];
	for(int i=len-1;i>0;i--)
		if (arr[i - 1] < arr[i]) {
			arr[i] -= arr[i - 1];
			arr[i - 1] = 0;
		}
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}
string num_to_roma(int num) {
	string ret = "";
	while (num >= 1000) {
		ret += "M";
		num -= 1000;
	}
	int CM = 0;
	if (num >= 900) {
		ret += "CM";
		CM++;
		num -= 900;
	}
	if (num >= 500) {
		ret += "D";
		num -= 500;
	}
	if (CM != 1 && num >= 400) {
		ret += "CD";
		num -= 400;
	}
	while (num >= 100) {
		ret += "C";
		num -= 100;
	}
	int XC = 0;
	if (num >= 90) {
		ret += "XC";
		XC++;
		num -= 90;
	}
	if (num >= 50) {
		ret += "L";
		num -= 50;
	}
	if (XC != 1 && num >= 40) {
		ret += "XL";
		num -= 40;
	}
	while (num >= 10) {
		ret += "X";
		num -= 10;
	}
	int IX = 0;
	if (num >= 9) {
		ret += "IX";
		IX++;
		num -= 9;
	}
	if (num >= 5) {
		ret += "V";
		num -= 5;
	}
	if (IX != 1 && num >= 4) {
		ret += "IV";
		num -= 4;
	}
	while (num >= 1) {
		ret += "I";
		num -= 1;
	}
	return ret;
}
int main() {
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
	cin >> A >> B;
	a=roma_to_num(A);
	b=roma_to_num(B);
	cout<< a + b<<'\n'<< num_to_roma(a + b)<<'\n';
	return 0;
}