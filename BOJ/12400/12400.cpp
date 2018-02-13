#include <bits/stdc++.h>
using namespace std;
int trans[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
int main(){
	int testcase;
	scanf("%d\n",&testcase);
	for(int tc=1;tc<=testcase;tc++){
		string str;
		getline(cin,str);
		for(int i=0;i<str.size();i++)
			if(str[i]>='a'&&str[i]<='z')
				str[i]=trans[str[i]-'a']+'a';

		cout<<"Case #"<<tc<<": "<<str<<endl;
	}
	return 0;
}