#include <bits/stdc++.h>
using namespace std;
bool possi(int x){
	if(x<2)
		return false;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	int a,b;
	cin>>a>>b;
	printf("%s\n",(possi(a)&&possi(stoi(to_string(b)+to_string(a))))?"Yes":"No");
	return 0;
}