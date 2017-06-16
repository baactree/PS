// =====================================================================================
// 
//       Filename:  11332.cpp
//        Created:  2017년 06월 16일 17시 02분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a;
int b, c, d;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		cin>>a>>b>>c>>d;
		a=string(a.begin()+2, a.end()-1);
		if(a=="N"){
			long long t=b;
			if(t*c<=d*1e8)
				printf("May Pass.\n");
			else
				printf("TLE!\n");
		}
		else if(a=="N^2"){
			long long t=(long long)b*b;
			if(t*c<=d*1e8)
				printf("May Pass.\n");
			else
				printf("TLE!\n");
		}
		else if(a=="N^3"){
			if(b>2000)
				printf("TLE!\n");
			else{
				long long t=(long long)b*b*b;
				if(t*c<=d*1e8)
					printf("May Pass.\n");
				else
					printf("TLE!\n");
			}

		}
		else if(a=="2^N"){
			if(b>30)
				printf("TLE!\n");
			else{
				long long t=1ll<<b;
				if(t*c<=d*1e8)
					printf("May Pass.\n");
				else
					printf("TLE!\n");
			}
		}
		else{
			if(b>15)
				printf("TLE!\n");
			else{
				long long t=1;
				for(int i=1;i<=b;i++)
					t*=i;
				if(t*c<=d*1e8)
					printf("May Pass.\n");
				else
					printf("TLE!\n");
			}
		}
	}
	return 0;
}

