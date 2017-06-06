// =====================================================================================
// 
//       Filename:  10885.cpp
//        Created:  2017년 06월 06일 16시 24분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
const int mod=1e9+7;
struct Node{
	int sign, zero, two;
	Node(){
		sign=zero=two=0;
	}
	Node(int sign, int zero, int two):sign(sign), zero(zero), two(two){}
	bool operator < (const Node &rhs)const{
		if(sign==rhs.sign){
			if(sign==1){
				if(rhs.zero){
					return false;
				}
				if(zero){
					return true;
				}
				return two<rhs.two;
			}
			else{
				if(zero){
					return false;
				}
				if(rhs.zero){
					return true;
				}
				return two>rhs.two;
			}
		}
		return sign<rhs.sign;
	}
};
Node calc(const Node &a,  const Node &b){
	if(a.zero||b.zero)
		return Node(1, 1, 0);
	return Node(a.sign*b.sign, 0, a.two+b.two);
}
Node solve(int le, int ri){
	if(le==ri){
		if(arr[le]<0){
			if(arr[le]==-2)
				return Node(-1, 0, 1);
			return Node(-1, 0, 0);
		}
		if(arr[le]>0){
			if(arr[le]==2)
				return Node(1, 0, 1);
			return Node(1, 0, 0);
		}
		return Node(1, 1, 0);
	}
	int mid=(le+ri)/2;
	vector<Node> vec;
	Node left_ret=solve(le, mid);
	Node right_ret=solve(mid+1, ri);
	Node now=Node(1, 0, 0);
	for(int i=mid;i>=le;i--){
		if(arr[i]<0){
			now.sign*=-1;
			if(arr[i]==-2)
				now.two++;
		}
		else if(arr[i]>0){
			if(arr[i]==2)
				now.two++;
		}
		else if(arr[i]==0)
			now.zero++;
		vec.push_back(now);
	}
	sort(vec.begin(), vec.end());
	now=Node(1, 0, 0);
	Node ret=Node(-1, 0, 200000);
	for(int i=mid+1;i<=ri;i++){
		if(arr[i]<0){
			now.sign*=-1;
			if(arr[i]==-2)
				now.two++;
		}
		else if(arr[i]>0){
			if(arr[i]==2)
				now.two++;
		}
		else if(arr[i]==0)
			now.zero++;
		Node temp=calc(now, vec[0]);
		ret=max(ret, temp);
		temp=calc(now, vec.back());
		ret=max(ret, temp);
	}
	return max(max(left_ret, right_ret), ret);
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		Node ans=solve(0, n-1);
		if(ans.zero){
			printf("0\n");
			continue;
		}
		int answer=1;
		for(int i=0;i<ans.two;i++){
			answer*=2;
			answer%=mod;
		}
		answer*=ans.sign;
		printf("%d\n", answer);
	}
	return 0;
}

