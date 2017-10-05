#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			string str(x,'=');
			cout<<str<<'\n';
		}
	}
	return 0;
}