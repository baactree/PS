#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		string str;
		cin>>str;
		if(str=="0")
			break;
		int a,b;
		a=b=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='0')
				a++;
			if(str[i]=='1')
				b++;
		}
		int n=str.size();
		printf("%d\n",(n-1)+2+a*4+b*2+(n-a-b)*3);
	}
	return 0;
}