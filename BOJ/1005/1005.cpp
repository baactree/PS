
#include <iostream>
#include <vector> 
#define MAX(x,y) (x)>(y)?x:y
using namespace std;
int time2[1000];
int sumtime[1000];
int N,K;
vector<vector<int> > row;
vector<int> col;
int delay(int W)
{
    if(W==1)
    sumtime[0]==time2[0];
    if(sumtime[W-1]!=-1)
    return sumtime[W-1];
    int Mtime=0;
    for(int i=0;i<row[W-1].size();i++)
    {
    Mtime=MAX(Mtime,delay(row[W-1][i]+1));
    }
    sumtime[W-1]=time2[W-1]+Mtime;
    return sumtime[W-1];
    
}
int main()
{
    int Case;
    cin>>Case;
    while(Case--)
    {
                 
                 cin>>N>>K;
                
                 for(int i=0;i<N;i++)
                 cin>>time2[i];
    
                 for(int i=0;i<N;i++)
                 sumtime[i]=-1;
                 
                 for(int i=0;i<N;i++)
                 row.push_back(col);
                 for(int i=0;i<K;i++)
                 {
                         int q,w;
                         cin>>q>>w;
                         row[w-1].push_back(q-1);
                         }
                 int W;
                 cin>>W;        
                 cout<<delay(W)<<endl;       
                         
                 for(int i=0;i<N;i++)
                 row[i].clear();
                 row.clear();
    }
    //system("PAUSE");
    return 0;
}