// =====================================================================================
// 
//       Filename:  6378.cpp
//        Created:  2017년 02월 04일 20시 37분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

string arr;
int main(){
	while(true){
		cin>>arr;
		if(arr=="0")
			break;
		int num=0;
		for(int i=0;i<arr.size();i++)
			num+=arr[i]-'0';
		while(num>9){
			int temp=0;
			while(num){
				temp+=num%10;
				num/=10;
			}
			num=temp;
		}
		printf("%d\n", num);
	}
	return 0;
}

