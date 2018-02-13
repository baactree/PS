#include <bits/stdc++.h>
using namespace std;
int n;
double cache[1000005];
double solve(int idx){
	if(idx>=n)
		return 0;
	double &ret=cache[idx];
	if(ret>=-0.5)
		return ret;
	ret=0;
	for(int i=1;i<=6;i++)
		ret+=(solve(idx+i)+1)/6;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<1000005;i++)
		cache[i]=-1.0;
	printf("%.10lf\n",solve(0));
	return 0;
}