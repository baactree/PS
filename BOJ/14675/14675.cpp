#include <bits/stdc++.h>
using namespace std;
int n,q;
int degree[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		degree[a]++;
		degree[b]++;		
	}
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==2)
			printf("yes\n");
		else{
			printf("%s\n",degree[b]==1?"no":"yes");
		}
	}
	return 0;
}