#include <bits/stdc++.h>
using namespace std;
int w,h,x,y,p;
int r;
bool possi(int a,int b){
	if(a<x){
		a-=x;
		b-=y+r;
		return a*a+b*b<=r*r;
	}
	if(a<=x+w)
		return a>=x&&a<=x+w&&b>=y&&b<=y+h;
	a-=x+w;
	b-=y+r;
	return a*a+b*b<=r*r;
}
int main(){
	scanf("%d%d%d%d%d",&w,&h,&x,&y,&p);
	r=h/2;
	int ans=0;
	while(p--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(possi(a,b))
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}