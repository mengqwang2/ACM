/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15952
 * Submitted at:  2015-05-05 18:41:26
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    176
 * Problem Name:  Internet Bandwidth (UVa 820)
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 205
#define INF 0x3f3f3f3f
#define LL long long int


struct edge{
	int from,to;
    int cap,flow;
	edge()=default;
    edge(int u,int v,int cap,int flow){
        this->from=u;
        this->to=v;
        this->cap=cap;
        this->flow=flow;
    }
};

struct dinic{
    int n,m,s,t;
    int cur[MAX],d[MAX];
    bool vis[MAX];
    vector<edge> edges;
    vector<int> G[MAX];
    
    void add(int u,int v,int cap){
        edges.push_back(edge(u,v,cap,0));
        edges.push_back(edge(v,u,0,0));
        
        m=edges.size();
        
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
    
    bool bfs(){
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        
        d[s]=0;
        vis[s]=1;
        
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            
            for(int i=0;i<G[x].size();i++){
                edge& e=edges[G[x][i]];
                if(!vis[e.to] && e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
        
    }
    
    int dfs(int x,int a){
        if(x==t || a==0)
            return a;
        
        int flow=0;
        int f;
        
        for(int &i=cur[x];i<G[x].size();i++){
            edge &e=edges[G[x][i]];
            
            if(d[x]+1==d[e.to] && (f=dfs(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)
                    break;
            }
        }
        return flow;
    }
    
    int Maxflow(int s, int t){
        this->s=s;
        this->t=t;
        int flow=0;
        
        while(bfs()){
            memset(cur,0,sizeof(cur));
            flow+=dfs(s,INF);
        }
        return flow;
    }
    
}*solver;

int main() {
    int n,tc=1;
    solver=NULL;
    while(scanf("%d",&n) && n){
        if (solver!=NULL)
            delete solver;
        solver=new dinic;
        
        int s,t,c;
        scanf("%d %d %d",&s,&t,&c);
        while(c--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            solver->add(a,b,c);
            solver->add(b,a,c);
        }
        
        int ans=solver->Maxflow(s,t);
        printf("Network %d\nThe bandwidth is %d.\n\n",tc++,ans);
        
    }
            
    return 0;
}
