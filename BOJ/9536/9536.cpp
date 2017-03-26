// =====================================================================================
// 
//       Filename:  9536.cpp
//        Created:  2017년 03월 26일 18시 30분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
string in;
char a[200], b[200], c[200];
int main(){
	int tc;
	scanf("%d\n", &tc);
	while(tc--){
		getline(cin, str);
		vector<string> vec;
		int st, ed;
		for(st=0, ed=0; ed<str.size();){
			if(str[ed]==' '){
				vec.push_back(string(str.begin()+st, str.begin()+ed));
				st=ed+1;
				ed=st;
			}
			else
				ed++;
		}
		vec.push_back(string(str.begin()+st, str.begin()+ed));
		while(true){
			scanf("%s%s%s", a, b, c);
			if(strcmp(b, "goes")!=0){
				scanf("%s%s\n", a, b);
				break;
			}
			string temp=c;
			for(int i=0;i<vec.size();i++){
				if(temp==vec[i]){
					vec[i]="";
				}
			}
		}
		for(int i=0;i<vec.size();i++){
			if(vec[i]=="")
				continue;
			cout<<vec[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

