// =====================================================================================
// 
//       Filename:  2596.cpp
//        Created:  2017년 03월 07일 16시 54분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[8]={"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
string c[8]={"A", "B", "C", "D", "E", "F", "G", "H"};
int n;
string str;
string ans;
int main(){
	cin>>n>>str;
	for(int i=0;i<str.size();i+=6){
		for(int j=0;j<8;j++){
			int cnt=0;
			for(int k=0;k<6;k++)
				if(arr[j][k]!=str[i+k])
					cnt++;
			if(cnt<=1){
				ans+=c[j];
				break;
			}
		}
		if(ans.size()<=i/6){
			printf("%d\n", i/6+1);
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}

