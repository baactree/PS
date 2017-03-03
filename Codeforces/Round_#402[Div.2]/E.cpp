// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 03월 02일 16시 02분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
map<string, string> h;
vector<pair<int, string> > arr;
string calc(string a, string b, string op){
	string ret="";
	for(int i=0;i<m;i++){
		if(op=="XOR"){
			if(a[i]!=b[i])
				ret+="1";
			else
				ret+="0";
		}
		else if(op=="OR"){
			if(a[i]=='1'||b[i]=='1')
				ret+="1";
			else
				ret+="0";
		}
		else{
			if(a[i]=='1'&&b[i]=='1')
				ret+="1";
			else
				ret+="0";
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		string name, op, val, val2;
		cin>>name>>op>>val;
		if(val[0]!='0'&&val[0]!='1'){
			cin>>op>>val2;
			if(val!="?"&&val2!="?")
				h[name]=calc(h[val], h[val2], op);
			else if(val=="?"&&val2=="?"){
				if(op=="XOR"){
				}
				else if(op=="OR"){
					arr.push_back({1, "?"});
				}
				else{
					arr.push_back({2, "?"});
				}
			}
			else{
				if(val=="?"){
					if(op=="XOR"){
						arr.push_back({0, h[val2]});
					}
					else if(op=="OR"){
						arr.push_back({1, h[val2]});		
					}
					else{
						arr.push_back({2, h[val2]});
					}
				}
				else if(val2=="?"){
					if(op=="XOR"){
						arr.push_back({0, h[val]});
					}
					else if(op=="OR"){
						arr.push_back({1, h[val]});		
					}
					else{
						arr.push_back({2, h[val]});
					}
				}
			}
		}
		else{
			h[name]=val;
		}
	}
	//find max
	string max_ans="";
	string min_ans="";
	for(int i=0;i<m;i++){
		int cnt=0;
		//pick_zero
		for(int j=0;j<arr.size();j++){
			string now=arr[j].second;
			int op=arr[j].first;
			if(now=="?"){
				continue;
			}
			if(op==0){
				cnt+=now[i]=='1';
			}
			else if(op==1){
				cnt+=now[i]=='1';
			}
			else{
				
			}
		}
		//pick_one
		for(int j=0;j<arr.size();j++){
			string now=arr[j].second;
			int op=arr[j].first;
			if(now=="?"){
				if(op!=0)
					cnt--;
				continue;
			}
			if(op==0)
				cnt-=now[i]=='0';
			else if(op==1)
				cnt--;
			else
				cnt-=now[i]=='1';
		}
		if(cnt>0){
			max_ans+="0";
			min_ans+="1";
		}
		else if(cnt==0){
			max_ans+="0";
			min_ans+="0";
		}
		else{
			max_ans+="1";
			min_ans+="0";
		}
	}
	cout<<min_ans<<endl<<max_ans<<endl;
	return 0;
}

