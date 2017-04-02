#include <bits/stdc++.h>

using namespace std;

class PingPongQueue {
public:
	vector <int> whoPlaysNext(vector <int>, int, int);
};

vector <int> PingPongQueue::whoPlaysNext(vector <int> skills, int N, int K) {
	queue<int> q;
	for(int i=0;i<skills.size();i++)
		q.push(skills[i]);
	queue<int> table;
	int cnt[55]={0,};
	int a,b;
	for(int i=0;i<K;i++){
		while(table.size()<2){
			table.push(q.front());
			q.pop();
		}
		a=table.front();
		table.pop();
		b=table.front();
		table.pop();
		vector<int> ret;
		if(a>b){
			cnt[a]++;
			cnt[b]=0;
			q.push(b);
			if(cnt[a]==N){
							q.push(a);
							cnt[a]=0;
							}
			else
				table.push(a);
			if(i==K-1){
				ret.push_back(b);
				ret.push_back(a);
				return ret;
			}
		}
		else{
			cnt[b]++;
			cnt[a]=0;
			if(cnt[b]==N){
				q.push(b);
				cnt[b]=0;
			}
			else
				table.push(b);
			q.push(a);
			if(i==K-1){
				ret.push_back(a);
				ret.push_back(b);
				return ret;
			}
		}
		
	}	
}


//Powered by [KawigiEdit] 2.0!
