#include <bits/stdc++.h>
using namespace std;
int n;
int arr[105];
int main(){
	scanf("%d",&n);
	set<int> s[2];
	s[0].insert(1);
	s[0].insert(2);
	s[1].insert(3);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(s[i&1].find(arr[i])==s[i&1].end())
			return !printf("NO\n");
		s[i&1].erase(arr[i]);
		s[(i+1)&1].insert(arr[i]);
	}
	printf("YES\n");
	return 0;
}