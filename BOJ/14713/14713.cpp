#include <bits/stdc++.h>
using namespace std;
void print(){
	printf("Impossible\n");
	exit(0);
}
int n;
vector<string> arr[105];
bool possi(int idx){
	int t=0;
	for(int i=0;i<arr[idx].size();i++){
		while(t<arr[n].size()&&arr[n][t]!=arr[idx][i])
			t++;
		if(t==arr[n].size())
			return false;
	}
	return true;
}
int main(){
	scanf("%d\n",&n);
	for(int i=0;i<=n;i++){
		string str;
		getline(cin,str);
		int st=0;
		for(int j=0;j<str.size();j++)
			if(str[j]==' '){
				arr[i].push_back(string(str.begin()+st,str.begin()+j));
				st=j+1;
			}
		arr[i].push_back(string(str.begin()+st,str.end()));
		set<string> s;
		for(int j=0;j<arr[i].size();j++)
			s.insert(arr[i][j]);
		if(s.size()!=arr[i].size())
			print();
	}
	int sum=0;
	set<string> s;
	for(int i=0;i<n;i++){
		sum+=arr[i].size();
		for(int j=0;j<arr[i].size();j++)
			s.insert(arr[i][j]);
	}
	if(s.size()!=sum)
		print();
	if(sum!=arr[n].size())
		print();
	for(int i=0;i<n;i++){
		if(!possi(i))
			print();
	}
	printf("Possible\n");
	return 0;
}