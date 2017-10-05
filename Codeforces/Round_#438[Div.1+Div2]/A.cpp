#include <bits/stdc++.h>
using namespace std;
string str;
int n;
string arr[105];
int main(){
	cin>>str;
	cin>>n;
	bool flag1,flag2;
	flag1=flag2=false;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==str)
			return !printf("YES\n");
		if(arr[i][0]==str[1])
			flag2=true;
		if(arr[i][1]==str[0])
			flag1=true;
	}
	if(flag1&&flag2)
		return !printf("YES\n");
	printf("NO\n");
	return 0;
}