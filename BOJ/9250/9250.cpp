// =====================================================================================
// 
//       Filename:  9250.cpp
//        Created:  2017년 04월 09일 22시 12분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class Trie{
	public:
		Trie *child[26];
		bool ed;
		bool match;
		Trie *fail;
		Trie():ed(0), fail(0), match(0){
			memset(child, 0, sizeof(child));
		}
		~Trie(){
			for(int i=0;i<26;i++)
				delete child[i];
			delete fail;
		}
		void insert(const char *key){
			if(*key==0){
				ed=true;
				return;
			}
			int next=*key-'a';
			if(child[next]==0)
				child[next]=new Trie;
			child[next]->insert(key+1);
		}
};
int n;
char str[101];
int m;
char h[10001];
Trie *root;
int main(){
	scanf("%d", &n);
	root=new Trie;
	for(int i=0;i<n;i++){
		scanf("%s", str);
		root->insert(str);
	}

	queue<Trie*> q;
	q.push(root);
	root->fail=root;
	while(!q.empty()){
		Trie *now=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			Trie *there=now->child[i];
			if(there==0)
				continue;
			if(now==root)
				there->fail=root;
			else{
				Trie *t=now->fail;
				while(t!=root&&t->child[i]==0)
					t=t->fail;
				if(t->child[i])
					t=t->child[i];
				there->fail=t;
			}
			there->match=there->fail->match;
			if(there->ed)
				there->match=true;
			q.push(there);
		}
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%s", h);

		bool flag=false;
		Trie *state=root;
		int len=strlen(h);
		
		for(int i=0;i<len;i++){
			int next=h[i]-'a';
			while(state!=root&&state->child[next]==0)
				state=state->fail;
			if(state->child[next])
				state=state->child[next];
			if(state->match){
				flag=true;
				break;
			}
		}
		printf("%s\n", flag?"YES":"NO");
	}
	return 0;
}

