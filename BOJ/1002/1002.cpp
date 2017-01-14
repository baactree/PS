
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int Case;
    cin>>Case;
    while(Case--)
    {
                 double x1,y1,x2,y2,r1,r2;
                 cin>>x1>>y1>>r1>>x2>>y2>>r2;
                 double d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
                 int cnt;
                 if(r1>r2)
                 {
                          if(r1+r2<d)
                          cnt=0;
                          else if(r1+r2==d)
                          cnt=1;
                          else if(r1+r2>d&&r1-r2<d)
                          cnt=2;
                          else if(r1-r2==d)
                          cnt=1;
                          else if(r1-r2>d)
                          cnt=0;
                          }
                 else if(r2>r1)
                 {
                      if(r1+r2<d)
                          cnt=0;
                          else if(r1+r2==d)
                          cnt=1;
                          else if(r1+r2>d&&r2-r1<d)
                          cnt=2;
                          else if(r2-r1==d)
                          cnt=1;
                          else if(r2-r1>d)
                          cnt=0;
                  }
                  else if(r2==r1)
                  {
                       if(r1+r2<d)
                          cnt=0;
                          else if(r1+r2==d)
                          cnt=1;
                          else if(r1+r2>d&&0<d)
                          cnt=2;
                          else if(0==d)
                          cnt=-1;
                   }
                   cout<<cnt<<endl;
                 }
    return 0; 
}