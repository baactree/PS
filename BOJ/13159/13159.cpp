#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Splay_tree{
	struct node{
		node *l,*r,*p;
		int cnt,minv,maxv,value;
		ll sum;
		bool inv;
	};
	node *root;
	node *arr[300005];
	Splay_tree(int n){
		root=0;
		memset(arr,0,sizeof(arr));
		init(n);
	}
	~Splay_tree(){
		for(int i=0;i<300005;i++)
			if(arr[i])
				delete arr[i];
	}
	void push(node *x){
		if(!x->inv)
			return;
		node *t=x->l;
		x->l=x->r;
		x->r=t;
		x->inv=false;
		if(x->l)
			x->l->inv=!x->l->inv;
		if(x->r)
			x->r->inv=!x->r->inv;
	}
	void update(node *x){
		x->cnt=1;
		x->sum=x->minv=x->maxv=x->value;
		if(x->l){
			x->cnt+=x->l->cnt;
			x->sum+=x->l->sum;
			x->minv=min(x->minv,x->l->minv);
			x->maxv=max(x->maxv,x->l->maxv);
		}
		if(x->r){
			x->cnt+=x->r->cnt;
			x->sum+=x->r->sum;
			x->minv=min(x->minv,x->r->minv);
			x->maxv=max(x->maxv,x->r->maxv);
		}
	}
	void rotate(node *x){
		node *p=x->p;
		node *b;
		if(x==p->l){
			p->l=b=x->r;
			x->r=p;
		}
		else{
			p->r=b=x->l;
			x->l=p;
		}	
		x->p=p->p;
		p->p=x;
		if(b) b->p=p;
		(x->p?p==x->p->l?x->p->l:x->p->r:root)=x;
		update(p);
		update(x);
	}
	void ppush(node *x){
		if(!x)
			return;
		ppush(x->p);
		push(x);
	}
	void splay(node *x){
		ppush(x);
		while(x->p){
			node *p=x->p;
			node *g=p->p;
			if(g) {
				rotate((x==p->l)==(p==g->l)?p:x);
			}
			rotate(x);
		}
	}
	//0-based
	void find_kth(int idx){
		node *x=root;
		push(x);
		while(true){
			while(x->l&&x->l->cnt>idx){
				x=x->l;
				push(x);
			}
			if(x->l)
				idx-=x->l->cnt;
			if(!idx--) break;
			x=x->r;
			push(x);
		}
		splay(x);
	}
	void init(int n){
		n+=2;
		node *x=new node;
		x->p=x->l=x->r=NULL;
		x->value=x->sum=x->maxv=x->minv=x->inv=0;
		x->cnt=n;
		root=x;
		int idx=0;
		arr[idx++]=x;
		for(int i=1;i<n;i++){
			x->r=new node;
			x->r->p=x;
			x=x->r;
			x->l=x->r=NULL;
			x->value=x->sum=x->maxv=x->minv=x->inv=0;
			x->cnt=n-i;
			arr[idx++]=x;
		}
	}
	//1-based
	void interval(int l,int r){
		find_kth(l-1);
		node *x=root;
		root=x->r;
		root->p=NULL;
		find_kth(r-l+1);
		x->r=root;
		root->p=x;
		root=x;
	}
	void add(int idx, int val){
		find_kth(idx);
		node *x=root;
		x->value+=val;
		x->sum+=val;
		x->minv+=val;
		x->maxv+=val;
	}
	pair<ll,pair<int,int> > query(int l,int r){
		interval(l,r);
		node *x=root->r->l;
		return {x->sum,{x->minv,x->maxv}};
	}
	void reverse(int l,int r){
		interval(l,r);
		node *x=root->r->l;
		x->inv=!x->inv;
	}
	void shift(int l,int r,int x){
		int len=r-l+1;
		x=(x%len+len)%len;
		if(x==0)
			return;
		int idx=r-x;
		reverse(l,idx);
		reverse(idx+1,r);
		reverse(l,r);
	}
	int get_idx(int val){
		splay(arr[val]);
		int ret=0;
		if(root->l)
			ret+=root->l->cnt;
		return ret;
	}
	int get_val(int idx){
		find_kth(idx);
		return root->value;
	}
};
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	Splay_tree spt(n);
	for(int i=1;i<=n;i++)
		spt.add(i,i);
	while(q--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int a,b;
			scanf("%d%d",&a,&b);
			auto ans=spt.query(a,b);
			spt.reverse(a,b);
			printf("%d %d %lld\n",ans.second.first,ans.second.second,ans.first);
		}
		else if(type==2){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			auto ans=spt.query(a,b);
			spt.shift(a,b,c);
			printf("%d %d %lld\n",ans.second.first,ans.second.second,ans.first);
		}
		else if(type==3){
			int a;
			scanf("%d",&a);
			printf("%d\n",spt.get_val(a));
		}
		else{
			int a;
			scanf("%d",&a);
			printf("%d\n",spt.get_idx(a));
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",spt.get_val(i));
	printf("\n");
	return 0;
}