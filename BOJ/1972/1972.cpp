#include <bits/stdc++.h>
using namespace std;
int main(){
	while(true){
		string str;
		cin>>str;
		if(str=="*")
			break;
		bool flag=false;
		for(int i=1;i<str.size();i++){
			set<int> s;
			for(int j=0;j+i<str.size();j++)
				s.insert((str[j]-'A')*26+str[j+i]-'A');
			if(s.size()!=str.size()-i)
				flag=true;
		}
		cout<<str<<" is ";
		printf("%ssurprising.\n",flag?"NOT ":"");
	}
	return 0;
}