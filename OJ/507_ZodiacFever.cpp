/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 17184
 * Submitted at:  2015-05-13 17:52:24
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    507
 * Problem Name:  Zodiac Fever
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
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%lf",&n)
#define S2(m,n) scanf("%lf %lf",&m,&n)
#define EPS 1e-6
#define N 10000
#define M 100000000

typedef long long int LL;

struct traps{
    int move;
    char s;
    
    traps() = default;
    
    traps(int m,char a){
        move=m;
        s=a;
    }
    
};

struct pq_node{
    int rid,dist,ring;
    
    pq_node() = default;
    
    pq_node(int a,int b,int c){
        rid=a;
        dist=b;
        ring=c;
    }
    
    bool operator < (const pq_node &n)const{
        return n.dist<dist;
    }
    
};


struct rm{
    int roomid,pos;
    
    rm()=default;
    
    rm(int a,int b){
        roomid=a;
        pos=b;
    }
    
    bool operator < (const rm &r)const{
        if(roomid!=r.roomid)
            return roomid<r.roomid;
        return pos<r.pos;
    }
};

int main(){
    int room,corri,trap,st,st_ring,end,end_ring;
    bool result;
    while(scanf("%d %d %d %d %d %d %d",&room,&corri,&trap,&st,&st_ring,&end,&end_ring)!=EOF){
        result=false;
        
        
        vector <vector <pair<int,int> > > adj(room+1);
        vector <vector <traps> > tp(room+1);
        
        for(int i=0;i<corri;i++){
            int s,e,dist;
            scanf("%d %d %d",&s,&e,&dist);
            adj[s].push_back(make_pair(e,dist));
            adj[e].push_back(make_pair(s,dist));
        }
        
        for(int i=0;i<trap;i++){
            int t,v;
            char type;
            scanf("%d %c %d",&t,&type,&v);
            
            tp[t].push_back(traps(v,type));
        }
        
        
        priority_queue<pq_node> Q;
        Q.push(pq_node(st,0,st_ring));
        
        map<rm,int> visit;
        
        
        while(!Q.empty()){
            pq_node u = Q.top();
            Q.pop();
            
            int roomid=u.rid;
            int ringid=u.ring;
            if(roomid==end && ringid==end_ring){
                result=true;
                printf("%d\n",u.dist);
                break;
            }
            for(int i=0;i<adj[roomid].size();i++){
                int v=adj[roomid][i].first;
                int dist=adj[roomid][i].second;
                int pos=ringid;
                
                if(tp[v].size()!=0){
                    traps rmt=tp[v][0];
                    char c=rmt.s;
                    int m=rmt.move;
                    
                    if(c=='+')
                        pos+=m;
                    else if(c=='-')
                        pos-=m;
                    else if(c=='*')
                        pos*=m;
                    else if(c=='=')
                        pos=m;
                    
                    if(pos>12)
                        pos%=12;
                    while(pos<=0){
                        pos+=12;
                    }
                }
                rm r=rm(v,pos);
                if(visit.find(r)==visit.end()){
                    Q.push(pq_node(v,u.dist+dist,pos));
                    visit[r]=u.dist+dist;
                }else if(u.dist+dist<visit[r]){
                    Q.push(pq_node(v,u.dist+dist,pos));
                    visit[r]=u.dist+dist;
                }
            }
        }
        if(!result)
            printf("Pray!\n");
    }
    
    return 0;
}