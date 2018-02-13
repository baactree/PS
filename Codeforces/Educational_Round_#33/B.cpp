#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int ans=0;
	vector<int> vec;
	for(int i=0;i<20;i++){
		int now=((1<<i)-1)*(1<<(i-1));
		vec.push_back(now);
	}
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			int a=i;
			int b=n/i;
			for(int j=0;j<vec.size();j++){
				if(a==vec[j])
					ans=max(ans,a);
				if(b==vec[j])
					ans=max(ans,b);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}