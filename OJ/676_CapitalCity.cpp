/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12964
 * Submitted at:  2015-03-06 22:41:15
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    676
 * Problem Name:  Capital City
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

using namespace std;

class Comparator
{
public:
    int operator() ( const pair<int,long>& p1, const pair<int,long> &p2)
    {
        return p1.second>p2.second;
    }
};


long shortestPath(const vector< vector<pair<int,long> > > &adj, int n,int st){
    vector<long> d(n);
    
    for(int i=0;i<n;i++)
    {
        d[i] = 100000000;
    }
    
    priority_queue<pair<int,long>, vector<pair<int,long> >, Comparator> Q;
    d[st] = 0;
    Q.push(make_pair(st,d[st]));
    
    while(!Q.empty())
    {
        int u = Q.top().first;
    
        Q.pop();
        for(int i=0; i < adj[u].size(); i++)
        {
            int v= adj[u][i].first;
            long w = adj[u][i].second;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                Q.push(make_pair(v,d[v]));
            }
        }
    }

    long sum=0;
    for (int i=0;i<n;i++){
        sum+=d[i];
    }
    
    return sum;
    
}



int main()
{
    int n,m;
    
    while(scanf("%d %d",&n, &m)!=EOF){
        vector< vector< pair<int,long> > > adj(n);
        for (int i=0;i<m;i++){
            int a,b;
            long c;
            scanf("%d %d %ld",&a,&b,&c);
            adj[a-1].push_back(make_pair(b-1,c));
            adj[b-1].push_back(make_pair(a-1,c));
            
        }
        
        long sum=100000000;
        int city=0;
        for (int i=0;i<n;i++){
            long result=shortestPath(adj,n,i);
            if (result<sum){
                city=i+1;
                sum=result;
            }
        }
        
        cout << city << endl;
        
    }
        
    
    
}
