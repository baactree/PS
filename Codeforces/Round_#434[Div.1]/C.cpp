// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 17일 23시 14분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int chk[100005];
int idx[100005];
pair<string, int> arr[100005];
int calc(string str){
	bool flag=false;
	for(int i=0;i<str.size();i++)
		if(!(str[i]>='0'&&str[i]<='9'))
			flag=true;
	if(flag)
		return -1;
	int ret=stoi(str);
	if(to_string(ret)!=str)
		return -1;
	if(ret>=1&&ret<=n)
		return ret;
	return -1;
}
int main(){
	memset(chk, -1, sizeof(chk));
	memset(idx, -1, sizeof(idx));
	scanf("%d", &n);
	int cnt=0;
	int sz=0;
	for(int i=0;i<n;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	for(int i=0;i<n;i++){
		if(arr[i].second)
			cnt++;
		int k=calc(arr[i].first);
		if(k!=-1){
			chk[k]=i;
			idx[i]=k;
			sz++;
		}
	}
	// 1 0~cnt
	// 0 cnt~n
	int ans=0;
	vector<pair<string, int> > out;
	if(sz==n){
		int t=-1;
		for(int i=0;i<n;i++){
			int k=idx[i];
			if(arr[i].second){
				if(k>cnt){
					t=i;
					break;
				}
			}
			else{
				if(k<=cnt){
					t=i;
					break;
				}
			}
		}
		if(t==-1)
			return !printf("0\n");
		chk[idx[t]]=-1;
		idx[t]=-1;
		out.push_back({arr[t].first, n+1});
		arr[t].first=to_string(n+1);
	}
	queue<int> t, b;
	for(int i=1;i<=cnt;i++)
		if(chk[i]==-1)
			t.push(i);
	for(int i=cnt+1;i<=n;i++)
		if(chk[i]==-1)
			b.push(i);
	queue<int> gt, gb;
	for(int i=0;i<n;i++){
		if(idx[i]!=-1){
			if(arr[i].second){
				if(idx[i]>cnt){
					gt.push(i);
				}
			}
			else{
				if(idx[i]<=cnt){
					gb.push(i);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(idx[i]==-1){
			if(arr[i].second){
				gt.push(i);
			}
			else{
				gb.push(i);
			}
		}
	}
	while(!t.empty()||!b.empty()){
		if(!b.empty()){
			int now=gb.front();
			gb.pop();
			if(idx[now]!=-1){
				t.push(idx[now]);
				chk[idx[now]]=-1;
			}
			int k=b.front();
			b.pop();
			chk[k]=now;
			idx[now]=k;
			out.push_back({arr[now].first, k});
		}
		if(!t.empty()){
			int now=gt.front();
			gt.pop();
			if(idx[now]!=-1){
				b.push(idx[now]);
				chk[idx[now]]=-1;
			}
			int k=t.front();
			t.pop();
			chk[k]=now;
			idx[now]=k;
			out.push_back({arr[now].first, k});
		}
	}
	printf("%d\n", out.size());
	for(int i=0;i<out.size();i++){
		cout<<"move "<<out[i].first<<" "<<out[i].second<<'\n';
	}
	return 0;
}
