#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> vec;
bool comp(const string &a,const string &b){
	if(b.size()!=a.size())
		return false;
	string temp=a+a;
	return temp.find(b)!=string::npos;
}
bool distinct(const string &str){
	for(int i=0;i<vec.size();i++)
		if(comp(vec[i],str))
			return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(distinct(str))
			vec.push_back(str);
	}
	cout<<vec.size()<<endl;
	return 0;
}