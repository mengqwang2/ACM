/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11762
 * Submitted at:  2015-02-02 01:18:02
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    27
 * Problem Name:  Gems in the maze
 */

#include <iostream>
using namespace std;

const int MN=500;
int adj[MN][MN];
int par[MN];
bool vis[MN];
int maxLength=0;

void gems(int u,int n)
{
    vis[u] = true;
    for(int v = 0; v < n; v++) {
        if(adj[u][v] && !vis[v]) {
            gems(v, n);
            par[v] = u;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    int a,b,c,n;
    for(int i=0;i<test;i++)
    {
        cin >> a >> b >> c >> n;
        maxLength=1;
       
        for (int j=0;j<MN;j++)
        {
            for(int k=0;k<MN;k++)
            {
                adj[j][k]=0;
            }
        }
        
        for (int j=0;j<n;j++)
        {
            adj[j][(a*j*j+b*j+c)%n]++;
        }
        
        for (int u=0;u<n;u++)
        {
            for (int j=0;j<MN;j++)
            {
                vis[j]=false;
                par[j]=-1;
            }
            
            if(!vis[u])
                gems(u,n);
            
            
            for (int j=0;j<n;j++)
            {
                int length=0;
                int k=j;
                while (k!=-1)
                {
                    k=par[k];
                    length++;
                }
                if (length>maxLength)
                {
                    maxLength=length;
                }
            }
        }
        cout << maxLength << endl;
    }
    return 0;
}