#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	point operator - (const point &rhs)const{
		return point(x-rhs.x,y-rhs.y);
	}
	bool operator <(const point &rhs)const{
		if(x==rhs.x)
			return y<rhs.y;
		return x<rhs.x;
	}
	int cross(const point &rhs)const{
		return x*rhs.y-y*rhs.x;
	}
};
int ccw(point a,point b){
	return a.cross(b);
}
int ccw(point p,point a,point b){
	return ccw(a-p,b-p);
}
vector<point> convex_hull(vector<point> &arr){
	int n=arr.size();
	vector<point> hull,up(n),down(n);
	int iup,idown;
	iup=idown=-1;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		while(iup>0&&ccw(up[iup-1],up[iup],arr[i])>=0)
			iup--;
		up[++iup]=arr[i];
		while(idown>0&&ccw(down[idown-1],down[idown],arr[i])<=0)
			idown--;
		down[++idown]=arr[i];
	}
	for(int i=0;i<=iup;i++)
		hull.push_back(up[i]);
	for(int i=idown-1;i>0;i--)
		hull.push_back(down[i]);
	return hull;
}
int main(){
	int n;
	vector<point> arr;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		arr.push_back({x,y});
	}
	vector<point> hull=convex_hull(arr);
	int ans=0;
	for(int i=1;i+1<hull.size();i++)
		ans+=abs(ccw(hull[0],hull[i],hull[i+1]));
	printf("%d\n",ans/100);
	return 0;
}