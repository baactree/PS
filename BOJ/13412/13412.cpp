#include <bits/stdc++.h>
using namespace std;
bool prime[10005];
vector<int> p;
int main(){
	for(int i=2;i<=10000;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i*i;j<=10000;j+=i)
				prime[j]=true;
		}
	}
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int n;
		scanf("%d",&n);
		if(n==1){
			printf("1\n");
			continue;
		}
		int cnt=0;
		for(int i=0;i<p.size()&&p[i]<n;i++){
			if(n%p[i]==0){
				cnt++;
				while(n%p[i]==0)
					n/=p[i];
			}
		}
		if(n!=1)
			cnt++;
		printf("%d\n",1<<(cnt-1));
	}
	return 0;
}