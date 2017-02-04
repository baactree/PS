// =====================================================================================
// 
//       Filename:  2529.cpp
//        Created:  2017년 02월 04일 21시 28분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
int arr[10];
int perm[10];
bool possi(){
	for(int i=0;i<k;i++){
		if(arr[i]){
			if(perm[i]>perm[i+1])
				return false;
		}
		else{
			if(perm[i]<perm[i+1])
				return false;
		}
	}
	return true;
}
int main(){
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		string temp;
		cin>>temp;
		arr[i]=temp=="<";
	}
	for(int i=0;i<10;i++)
		perm[i]=i;
	string max_value=string(k+1, '0');
	string min_value=string(k+1, '9');
	do{
		if(possi()){
			string now="";
			for(int i=0;i<k+1;i++)
				now+=to_string(perm[i]);
			max_value=max(max_value, now);
			min_value=min(min_value, now);
		}
	}while(next_permutation(perm, perm+10));
	cout<<max_value<<endl<<min_value<<endl;
	return 0;
}

