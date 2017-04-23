// =====================================================================================
// 
//       Filename:  10882.cpp
//        Created:  2017년 04월 23일 11시 48분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int h, m;
	char str[10];
	scanf("%d:%d%s", &h, &m, str);
	int now=h*60+m;
	if(str[3]=='+'){
		double temp;
		sscanf(&str[4], "%lf", &temp);
		now=(now-(int)(60*temp)+24*60)%(24*60);
	}
	else{
		double temp;
		sscanf(&str[4], "%lf", &temp);
		now=(now+(int)(60*temp)+24*60)%(24*60);
	}
	while(n--){
		scanf("%s", str);
		if(str[3]=='+'){
			double temp;
			sscanf(&str[4], "%lf", &temp);
			int ans=(now+(int)(60*temp))%(24*60);
			printf("%02d:%02d\n", ans/60, ans%60);
		}
		else{
			double temp;
			sscanf(&str[4], "%lf", &temp);
			int ans=(now-(int)(60*temp)+24*60)%(24*60);
			printf("%02d:%02d\n", ans/60, ans%60);
		}
	}
	return 0;
}

