// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 20일 00시 52분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int pos0, pos1;
int main(){
	int kk=1;
	scanf("%d", &n);
	string q=string(n, '0');
	cout<<"? "<<q<<endl;
	fflush(stdout);
	int cnt;
	scanf("%d", &cnt);
	int le, ri;
	le=1;
	ri=n;
	while(le<=ri){
		kk++;
		int mid=(le+ri)/2;	
		int len=ri-le+1;
		if(len==1){
			int now;
			if(q[le-1]=='1'){
				q[le-1]='0';
				cout<<"? "<<q<<endl;
				fflush(stdout);
				scanf("%d", &now);
				if(now==cnt-1){
					if(!pos0)
						pos0=le;
					break;
				}
				else{
					if(!pos1)
						pos1=le;
					break;
				}
			}
			else{
				q[le-1]='1';
				cout<<"? "<<q<<endl;
				fflush(stdout);
				scanf("%d", &now);
				if(now==cnt-1){
					if(!pos1)
						pos1=le;
					break;
				}
				else{
					if(!pos0)
						pos0=le;
					break;
				}
			}
		}
		if(len==2){
			int now;
			if(q[le-1]=='1'){
				q[le-1]='0';
				cout<<"? "<<q<<endl;
				fflush(stdout);
				scanf("%d", &now);
				if(now==cnt-1){
					if(!pos0)
						pos0=le;
					if(!pos1)
						pos1=le+1;
					break;
				}
				else{
					if(!pos1)
						pos1=le;
					if(!pos0)
						pos0=le+1;
					break;
				}
			}
			else{
				q[le-1]='1';
				cout<<"? "<<q<<endl;
				fflush(stdout);
				scanf("%d", &now);
				if(now==cnt-1){
					if(!pos1)
						pos1=le;
					if(!pos0)
						pos0=le+1;
					break;
				}
				else{
					if(!pos0)
						pos0=le;
					if(!pos1)
						pos1=le+1;
					break;
				}
			}
		}
		char pre=q[le-1];
		char next=(pre=='1'?'0':'1');
		int mlen=mid-le+1;
		for(int i=le-1;i<mid;i++)
			q[i]=next;
		cout<<"? "<<q<<endl;
		fflush(stdout);
		int now;
		scanf("%d", &now);
		if(now==cnt+mlen){
			if(pre=='1'){
				if(!pos1)
					pos1=le;
			}
			else{
				if(!pos0)
					pos0=le;
			}
			le=mid+1;
		}
		else if(now==cnt-mlen){
			if(next=='1'){
				if(!pos1)
					pos1=le;
			}
			else{
				if(!pos0)
					pos0=le;
			}
			le=mid+1;
		}
		else{
			ri=mid;
		}
		cnt=now;
	}
	assert(kk<=14);
	assert(pos0!=0);
	assert(pos1!=0);
	printf("! %d %d\n", pos0, pos1);
	fflush(stdout);
	return 0;
}

