/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15905
 * Submitted at:  2015-05-04 23:35:29
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    563
 * Problem Name:  Pahom on Water
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 800
#define INF 0x3f3f3f3f


struct node{
    double freq;
    int x,y,r;
    node(){}
    
    void read(){
        scanf("%lf %d %d %d",&freq,&x,&y,&r);
    }
}nd[MAX];

struct edge{
	int from,to,cap,flow;
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


bool isIntersect(int a,int b){
    int dist=(nd[a].x-nd[b].x)*(nd[a].x-nd[b].x)+(nd[a].y-nd[b].y)*(nd[a].y-nd[b].y);
    int rad=(nd[a].r+nd[b].r)*(nd[a].r+nd[b].r);
    if (dist<=rad)
        return true;
    else
        return false;
}


int main() {
    int tc,n,s,t;
    scanf("%d",&tc);
    solver=NULL;
    while(tc--){
        if(solver!=NULL)
            delete solver;
        solver=new dinic;
        
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            nd[i].read();
            if(fabs(nd[i].freq-400)<1e-6){
                s=i;
            }else if(fabs(nd[i].freq-789)<1e-6){
                t=i;
            }
            

        }
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(isIntersect(i,j) && nd[i].freq<nd[j].freq)
                    solver->add(i*2+1,j*2,1);
                if(isIntersect(j,i) && nd[j].freq<nd[i].freq)
                    solver->add(j*2+1,i*2,1);
            }
            solver -> add(i*2,i*2+1,1);
        }
        solver -> add(s*2,s*2+1,1);
        solver -> add(t*2,t*2+1,1);
        solver -> add(775,s*2,2);
        solver -> add(t*2+1,776,2);
        int ans = solver->Maxflow(775,776);
        if(ans==2)
            puts( "Game is VALID" );
        else
            puts( "Game is NOT VALID" );
        
        
    }
    
    
    
    
    return 0;
}
