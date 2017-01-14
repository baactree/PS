#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int Case;
    cin>>Case;
    while(Case--)
    {
                 double x1,x2,y1,y2;
                 cin>>x1>>y1>>x2>>y2;
                 int N;
                 cin>>N;
                 int cnt=0;
                 for(int i=0;i<N;i++)
                 {
                        
                         double cx,cy,r;
                         cin>>cx>>cy>>r;
                         double ds,df;
                         ds=sqrt(pow(cx-x1,2)+pow(cy-y1,2));
                         df=sqrt(pow(cx-x2,2)+pow(cy-y2,2));
                         if((ds<r&&df>r)||(ds>r&&df<r))
                         cnt++;
                         }
                 cout<<cnt<<endl;
                 }
    return 0; 
}