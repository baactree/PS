#include <bits/stdc++.h>
using namespace std;
int n;
string arr[100];
int main(){
	scanf("%d",&n);
	set<string> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(s.insert(arr[i]).second)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}