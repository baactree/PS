// =====================================================================================
// 
//       Filename:  12460.cpp
//        Created:  2017년 06월 26일 22시 17분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<string> arr;
vector<int> par;
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
int main(){
	int idx=0;
	while(true){
		string str;
		cin>>str;
		if(str=="--")
			break;
		mp[str]=idx++;
		arr.push_back(str);
	}
	par=vector<int>(idx);
	for(int i=0;i<idx;i++)
		par[i]=i;
	for(int i=0;i<idx;i++){
		for(int j=0;j<arr[i].size();j++){
			int temp=arr[i][j];
			for(int k=0;k<26;k++){
				arr[i][j]=k+'a';
				if(mp.count(arr[i])!=0)
					merge(i, mp[arr[i]]);
			}
			arr[i][j]=temp;
		}
	}
	string a, b;
	while(cin>>a>>b){
		int p=mp[a];
		int q=mp[b];
		p=find(p);
		q=find(q);
		printf("%s\n", p==q?"Yes":"No");
	}
	return 0;
}

