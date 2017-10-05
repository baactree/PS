#include <bits/stdc++.h>
using namespace std;
int h,m,s,t1,t2;
int main(){
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	t1=(t1*60*60)%43200;
	t2=(t2*60*60)%43200;
	s=(s*60*12)%43200;
	m=(m*60*12+s/60)%43200;
	h=(h*60*60+s/60/12)%43200;
	for(int i=1;i<43200;i++){
		int next=(t1+i)%43200;
		if(next==t2)
			return !printf("YES\n");
		if(next==h||next==m||next==s)
			break;
	}
	for(int i=1;i<43200;i++){
		int next=(t1-i+43200)%43200;
		if(next==t2)
			return !printf("YES\n");
		if(next==h||next==m||next==s)
			break;
	}
	printf("NO\n");
	return 0;
}