#include <bits/stdc++.h>
using namespace std;

class Kmp {
public:
	vector<int> get_pi(const string& N) {
		int m = N.length();
		vector<int> pi(m, 0);
		int begin = 1, matched = 0;
		while (begin+matched < m) {
			if (N[begin + matched] == N[matched]) {
				matched++;
				pi[begin + matched - 1] = matched;
			}
			else {
				if (matched == 0) {
					begin++;
				}
				else {
					begin = begin + matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		return pi;
	}
	vector<int> get_kmp(const string& H,const string& N) {
		int n = H.length();
		int m = N.length();
		vector<int> ret;
		vector<int> pi = get_pi(N);
		int begin = 0, matched = 0;
		while (begin <= n - m) {
			if (matched < m&&H[begin + matched] == N[matched]) {
				matched++;
				if (matched == m)
					ret.push_back(begin);
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin = begin + matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		return ret;
	}

};

int n;
int a[360000],b[360000];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		b[x]++;
	}
	string as(360000,'0'),bs(360000,'0');
	for(int i=0;i<360000;i++){
		if(a[i])
			as[i]='1';
		else
			as[i]='0';
		if(b[i])
			bs[i]='1';
		else
			bs[i]='0';
	}
	as=as+as;
	Kmp kmp;
	printf("%s\n",kmp.get_kmp(as,bs).size()?"possible":"impossible");
	return 0;
}