#include <bits/stdc++.h>
using namespace std;
int main(){
	long long ans=0;
	int n;
	multiset<int> s;
	s.insert(0x3f3f3f3f);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(*s.begin()<x){
			ans+=x-*s.begin();
			s.erase(s.begin());
			s.insert(x);
		}
		s.insert(x);
	}
	printf("%lld\n",ans);
	return 0;
}