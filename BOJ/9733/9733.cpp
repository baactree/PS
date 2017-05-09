// =====================================================================================
// 
//       Filename:  9733.cpp
//        Created:  2017년 05월 09일 14시 54분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
string arr[7]={"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
int main(){
	char work[5];
	int cnt=0;
	while(scanf("%s", work)!=EOF){
		string temp=work;
		mp[temp]++;
		cnt++;
	}
	for(int i=0;i<7;i++){
		cout<<arr[i]<<" "<<mp[arr[i]]<<" ";
		printf("%.2lf\n", (double)mp[arr[i]]/cnt);
	}
	printf("Total %d 1.00\n", cnt);
	return 0;
}

