#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	while(getline(cin,str)){
		if(str=="#")
			break;
		int cnt=0;
		for(int i=0;i<str.size();i++){
			if(str[i]==str[0]||str[i]==str[0]-'a'+'A')
				cnt++;
		}
		printf("%c %d\n",str[0],cnt-1);
	}
	return 0;
}