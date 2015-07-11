/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11776
 * Submitted at:  2015-02-02 17:35:20
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    126
 * Problem Name:  Risk (UVa 567)
 */


#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int input_map[20][20];
int visit[20];

struct NodeDepth{
    int n;
    int d;
};


int bfs(int s,int e,int depth){
    queue<NodeDepth> wl;
    visit[s]=1;
    for(int i=0;i<20;i++){
        if(input_map[s][i]==1 && visit[i]==0){
            wl.push(NodeDepth{i,depth+1});
        }
    }
    while(!wl.empty()){
        NodeDepth cur=wl.front();
        //printf("%d %d\n",cur.n,cur.d);
        if(cur.n==e){
            return cur.d;
        }
        else{
            for(int j=0;j<20;j++){
                if(input_map[cur.n][j]==1 && visit[j]==0){
                    wl.push(NodeDepth{j,cur.d+1});
                }
            }
        }
        visit[cur.n]=1;
        wl.pop();
    }

    return -1;
}


int main()
{
    int testcase=0;
    int testset=0;
    int buffer=0;
    int cnt=0;
    memset(input_map,0,sizeof(input_map));
    
    while(scanf("%d",&buffer)!=EOF){
        while (cnt<19){
            
            int b;
            for (int i=0;i<buffer;i++){
                scanf("%d",&b);
                input_map[cnt][b-1]=1;
                input_map[b-1][cnt]=1;
            
            }
            cnt++;
            if(cnt<=18){
                scanf("%d",&buffer);
            }
            
        }
        
        memset(visit,0,sizeof(visit));
        scanf("%d",&testset);
        
        
        printf("Test Set #%d\n",testcase+1);
        
        for(int i=0;i<testset;i++){
            int s,e;
            scanf("%d %d",&s,&e);
            printf("%2d to %2d: %d\n",s,e,bfs(s-1,e-1,0));
            memset(visit,0,sizeof(visit));
        }
        
        memset(input_map,0,sizeof(input_map));
        cnt=0;
        printf("\n");
        testcase++;
    }
    
    
    return 0;
}

