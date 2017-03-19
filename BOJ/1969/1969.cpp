// =====================================================================================
// 
//       Filename:  1969.cpp
//        Created:  2017년 03월 19일 19시 59분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char dna[1000][55];
int n, m;
char tt[4]={'A', 'C', 'G', 'T'};
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", dna[i]);
	string ans="";
	int count=0;
	for(int i=0;i<m;i++){
		vector<int> cnt(4, 0);
		for(int j=0;j<n;j++){	
			for(int k=0;k<4;k++)
				if(dna[j][i]==tt[k])
					cnt[k]++;
		}
		ans+=tt[max_element(cnt.begin(), cnt.end())-cnt.begin()];
		count+=n-*max_element(cnt.begin(), cnt.end());
	}
	cout<<ans<<endl<<count<<endl;
	return 0;
}

