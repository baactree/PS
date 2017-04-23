// =====================================================================================
// 
//       Filename:  12787.cpp
//        Created:  2017년 04월 21일 11시 57분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		int mode;
		scanf("%d", &mode);
		if(mode==1){
			int arr[8];
			for(int i=0;i<8;i++)
				scanf("%d.", &arr[i]);
			llu ans=0;
			llu perm=1;
			for(int i=7;i>=0;i--){
				ans+=arr[i]*perm;
				perm*=256;
			}
			printf("%llu\n", ans);
		}
		else{
			int arr[8]={0, };
			llu p;
			scanf("%llu", &p);
			for(int i=7;i>=0;i--){
				arr[i]=p%256;
				p/=256;
			}
			for(int i=0;i<8;i++){
				printf("%d", arr[i]);
				if(i!=7)
					printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}

