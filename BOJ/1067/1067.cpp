#include <bits/stdc++.h>
using namespace std;
namespace fft{
    #define sz(v) ((int)(v).size())
    #define all(v) (v).begin(),(v).end()
    typedef complex<double> base;
    const double pi=acos(-1.0);
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
            double ang = 2*pi/len*(invert?-1:1);
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
        for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
    }
};
int n;
int main(){
	scanf("%d",&n);
	vector<int> a(n),b(n),ret;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		a.push_back(a[i]);
	}
	reverse(b.begin(),b.end());
	fft::multiply(a,b,ret);
	int ans=0;
	for(int i=b.size()-1;i<=a.size();i++)
		ans=max(ans,ret[i]);
	printf("%d\n",ans);
	return 0;
}