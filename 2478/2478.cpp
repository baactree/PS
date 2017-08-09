// =====================================================================================
// 
//       Filename:  2478.cpp
//        Created:  2017년 08월 10일 02시 30분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
deque<int> arr;
int n;
int possi(){
	int idx;
	for(idx=n-1;idx>0;idx--)
		if(arr[idx-1]!=(arr[idx]+1)%n)
			break;
	if(idx==n-1)
		return -1;
	if(idx==0)
		return arr[idx]==n-1?0:-1;
	for(int i=idx-1;i>0;i--)
		if((arr[i-1]+1)%n!=arr[i])
			return -1;
	if((arr[idx]+1)%n!=arr[0])
		return -1;
	return idx;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		x--;
		arr.push_back(x);
	}
	for(int i=1;i<=n;i++){
		arr.push_front(arr.back());
		arr.pop_back();
		int idx=possi();
		if(idx!=-1){
			reverse(arr.begin()+idx, arr.end());
			for(int j=0;j<n;j++)
				if(arr[j]==0)
					return !printf("%d \n%d %d\n%d\n", n-j, idx+1, n, i);
			reverse(arr.begin()+idx, arr.end());
		}
	}
	return 0;
}

