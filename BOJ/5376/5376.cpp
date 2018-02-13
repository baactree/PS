#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll r[18];
int main(){
	r[0]=1;
	for(int i=1;i<18;i++)
		r[i]=r[i-1]*10;
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		string str;
		cin>>str;
		int n=str.size();
		int cnt=0;
		int idx=-1;
		for(int i=2;i<n;i++){
			if(str[i]>='0'&&str[i]<='9')
				cnt++;
			else if(str[i]=='(')
				idx=i;
		}
		if(idx==-1){
			ll p=r[cnt];
			string tt=string(str.begin()+2,str.end());
			if(tt.empty())
				tt+="0";
			ll q=stoll(tt);
			ll g=gcd(p,q);
			printf("%lld/%lld\n",q/g,p/g);
		}
		else{
			int len=n-idx-2;
			string qq=string(len,'9')+string(cnt-len,'0');
			if(qq.empty())
				qq+="1";
			ll p=stoll(qq);
			string tt=string(str.begin()+2,str.begin()+idx)
				+string(str.begin()+idx+1,str.begin()+idx+1+len);
			string pp=string(str.begin()+2,str.begin()+idx);
			if(tt.empty())
				tt+="0";
			if(pp.empty())
				pp+="0";
			ll q=stoll(tt)-stoll(pp);
			ll g=gcd(p,q);
			printf("%lld/%lld\n",q/g,p/g);
		}
	}
	return 0;
}