// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 05월 21일 22시 16분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int a, b;
void check(int a, int b){
	//assert(a>=1&&a<=n);
	//assert(b>=1&&b<=n);
}
int find(int le, int ri){
	if(le>ri)
		return -1;
	if(le==ri){
		check(le, le-1);
		printf("1 %d %d\n", le, le-1);
		string temp;
		cin>>temp;
		if(temp=="TAK"){
			check(le, le+1);
			printf("1 %d %d\n", le, le+1);
			cin>>temp;
			if(temp=="TAK")
				return le;
		}
		return -1;
	}
	int mid=(le+ri)/2;
	string temp;
	printf("1 %d %d\n", mid, mid+1);
	cin>>temp;
	if(temp=="TAK")
		return find(le, mid);
	return find(mid+1, ri);
}
int main(){
	scanf("%d%d", &n, &k);
	printf("1 1 2\n");
	string temp;
	cin>>temp;
	if(temp=="NIE"){
		a=find(2, n-1);
	}
	else{
		a=1;
	}
	cout<<a<<endl;
	printf("1 %d %d\n", n, n-1);
	cin>>temp;
	if(temp=="NIE"){
		b=find(2, a-1);
		if(b==-1)
			b=find(a+1, n-1);
	}
	else{
		b=n;
	}
	printf("2 %d %d\n", a, b);
	return 0;
}

