#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ans=0;
	if(a>0||b>0){
		ans+=a;
		if(b==0)
			return !printf("%d\n",ans);
		ans++;
		b--;
		ans+=d;
		int k=min(b,c);
		ans+=k*2;
		b-=k;
		c-=k;
		if(c>0)
			ans++;
	}
	else{
		ans+=d;
		if(c>0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}