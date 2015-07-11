/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16122
 * Submitted at:  2015-05-07 02:18:48
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    378
 * Problem Name:  Monster Synthesis
 */

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tuple>
#include <map>
#include <sstream>

#define INF 0x3f3f3f3f

using namespace std;

class Comparator
{
public:
    int operator() ( const pair<int,int>& p1, const pair<int,int> &p2)
    {
        return p1.second>p2.second;
    }
};


int shortestPath(const vector< vector<pair<int,int> > > &adj, int n,int st,int dest, vector<int> &level,int m,int lmin,int lmax){
    vector<int> d(n);
    
    for(int i=0;i<n;i++)
    {
        d[i]=INF;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int> >, Comparator> Q;
    d[st]=0;
    Q.push(make_pair(st,d[st]));
    
    while(!Q.empty())
    {
        int u=Q.top().first;
        if(u==dest)
            break;
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            
            if(level[v]<lmin || level[v]>lmax){
                continue;
            }
            
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                Q.push(make_pair(v,d[v]));
            }
        }
    }
    
    
    return d[dest];
}

int main()
{
    int n,m;
    while(scanf("%d %d",&m,&n)!=EOF){
        vector <vector <pair<int,int> > > mon(n+1);
        vector <int> level(n+1);
        vector <int> price(n+1);
        for(int i=1;i<=n;i++){
            int p,l,x;
            scanf("%d %d %d",&p,&l,&x);
            level[i]=l;
            price[i]=p;
            while(x--){
                int mid,fee;
                scanf("%d %d",&mid,&fee);
                mon[i].push_back(make_pair(mid,fee));
            }
        }
        level[0]=level[1];
        price[0]=0;
        for(int i=1;i<=n;i++){
            mon[i].push_back(make_pair(0,price[i]));
        }
        
        int lmin=level[1]-m;
        int lmax=level[1];
        
        int ans=shortestPath(mon,n+1,1,0,level,m,lmin,lmax);
        
        while(lmin<=level[1])
		{	lmin++;
            lmax++;
			ans=min(ans,shortestPath(mon,n+1,1,0,level,m,lmin,lmax));
		}
        
		printf("%d\n",ans);
        
    }
    
    return 0;
}