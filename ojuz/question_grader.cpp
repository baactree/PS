
#include <algorithm>
#include <vector>
using namespace std;

vector<int> perm[921];
bool flag=false;

int decode (int n, int q, int h) {
    if(!flag){
        flag=true;
        for(int i=0;i<12;i++)
            perm[1].push_back(i>5);
        for(int i=2;i<921;i++){
            perm[i]=perm[i-1];
            next_permutation(perm[i].begin(),perm[i].end());
        }
    }
    return perm[q][h-1];
}

#include <algorithm>
#include <vector>
using namespace std;

vector<int> perm[921];
bool flag=false;
int encode (int n, int x, int y) {
    if(!flag){
        flag=true;
        for(int i=0;i<12;i++)
            perm[1].push_back(i>5);
        for(int i=2;i<921;i++){
            perm[i]=perm[i-1];
            next_permutation(perm[i].begin(),perm[i].end());
        }
    }
    for(int i=0;i<12;i++)
        if(perm[x][i]==1&&perm[y][i]==0)
            return i+1;
    return 0;
}