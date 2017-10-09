/*
ID: bsj02061
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string a,b;
	cin>>a>>b;
	int p,q;
	p=q=1;
	for(int i=0;i<a.size();i++)
		p*=a[i]-'A'+1;
	for(int i=0;i<b.size();i++)
		q*=b[i]-'A'+1;
	printf("%s\n",p%47==q%47?"GO":"STAY");
	return 0;
}