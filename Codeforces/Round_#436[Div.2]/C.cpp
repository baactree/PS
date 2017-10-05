#include <bits/stdc++.h>
using namespace std;
int a,b,f,k;
int main(){
	scanf("%d%d%d%d",&a,&b,&f,&k);
	int cnt=0;
	int now=b;
	for(int i=0;i<k;i++){
		if(i&1){
			if(now<a-f)
				return !printf("-1\n");
			now-=(a-f);
			if(now<f||(i!=k-1&&now<2*f)){
				cnt++;
				now=b;
			}
			if(now<f)
				return !printf("-1\n");
			now-=f;
		}
		else{
			if(now<f)
				return !printf("-1\n");
			now-=f;
			if(now<(a-f)||(i!=k-1&&now<(a-f)*2)){
				cnt++;
				now=b;
			}
			if(now<a-f)
				return !printf("-1\n");
			now-=(a-f);
		}
	}
	
	printf("%d\n",cnt);
	return 0;
}