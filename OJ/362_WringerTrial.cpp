/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15947
 * Submitted at:  2015-05-05 17:43:30
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    362
 * Problem Name:  Winger Trial (UVa 11757)
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


struct node{
    int x,y;
    
    node(){}
    
    void read(){
        scanf("%d %d",&x,&y);
    }
    
}nd[105];

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

bool isIntersect(node a,node b,int d){
    if((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<4*d*d)
        return true;
    else
        return false;
}


int main() {
    int l,w,n,d;
    int tc=1;
    solver=NULL;
    while(scanf("%d %d %d %d",&l,&w, &n, &d) && l && w && n && d){
        if(solver!=NULL)
            delete solver;
        solver=new dinic;
        
        
        for(int i=0;i<n;i++){
            nd[i].read();
            solver->add(2*i+2,2*i+3,1);
            if(nd[i].y<=d)
                solver->add(2*i+3,1,INF);
            if(w-nd[i].y<=d)
                solver->add(0,2*i+2,INF);
            
            for(int j=0;j<i;j++){
                if(isIntersect(nd[i],nd[j],d)){
                    solver->add(2*i+3,2*j+2,INF);
                    solver->add(2*j+3,2*i+2,INF);
                }
            }
        }
        
        int ans=solver->Maxflow(0,1);
        
        printf("Case %d: %d\n",tc++,ans);
        
        
        
        
        
        
    }
    
    return 0;
}
