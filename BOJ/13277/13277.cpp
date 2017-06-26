
// =====================================================================================
// 
//       Filename:  13277.cpp
//        Created:  2017년 06월 24일 23시 35분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef complex<double> base;
void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
 
void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res)
{
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
	n*=2;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+0.5);
}


int main(){
	string p, q;
	cin>>p>>q;
	vector<int> a, b, res;
	reverse(p.begin(), p.end());
	for(int i=0;i<p.size();i++)
		a.push_back(p[i]-'0');
	reverse(q.begin(), q.end());
	for(int i=0;i<q.size();i++)
		b.push_back(q[i]-'0');
	multiply(a, b, res);
	for(int i=0;i<res.size();i++){
		int r=res[i]/10;
		if(r>0){
			if(i+1==res.size())
				res.push_back(r);
			else
				res[i+1]+=r;
		}
		res[i]%=10;
	}
	while(!res.empty()&&res.back()==0)
		res.pop_back();
	string ans="";
	for(int i=0;i<res.size();i++)
		ans+=(char)(res[i]+'0');
	reverse(ans.begin(), ans.end());
    if(ans.empty())
        ans+='0';
	cout<<ans<<endl;
	return 0;
}

