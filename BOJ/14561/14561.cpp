#include <bits/stdc++.h>
using namespace std;
bool possi(vector<int> &vec){
	int le=0;
	int ri=(int)vec.size()-1;
	while(le<=ri){
		if(vec[le]!=vec[ri])
			return false;
		le++;
		ri--;
	}
	return true;
}
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		long long x;
		int n;
		scanf("%lld%d",&x,&n);
		vector<int> vec;
		while(x){
			vec.push_back(x%n);
			x/=n;
		}
		printf("%d\n",possi(vec));
	}
	return 0;
}