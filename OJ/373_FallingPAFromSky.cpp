/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15829
 * Submitted at:  2015-05-04 11:00:41
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    373
 * Problem Name:  Falling Pineapple From Sky
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

using namespace std;
int parent[1005];

struct Edge {
    int st,end,dist;
    Edge() {}
    Edge(int i,int j,int d){
        st=i;
        end=j;
        dist=d;
    }
    
    bool operator < (const Edge & e) const {
        return dist<e.dist;
    }
    
}E[25005];


int find(int x) {
    if (x==parent[x])
        return x;
    return parent[x] = find(parent[x]);
    
}

bool findAll(int n){
	int ans=find(0);
    
	for (int i=1;i<n;i++){
		if (find(i)!=ans)
			return false;
	}
    
	return true;
}

int main()
{
    int n,m;
    
    while (scanf("%d %d",&n,&m) && (n || m)){
        int u,v,dist;
        bool findNum=false;
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for (int i=0;i<m;i++){
            scanf ("%d %d %d",&u,&v,&dist);
            E[i]=Edge(u,v,dist);
        }
        
        sort(E,E+m);
        
        vector <int> unused;
        int totalDist=0;
        
        for (int i=0;i<m;i++) {
            int a=find(E[i].st);
            int b=find(E[i].end);
            if (a!=b){
                parent[a] = parent[b];
                totalDist+=E[i].dist;
            }
            else
                unused.push_back(E[i].dist);
            
            if (findAll(n)) {
                findNum=true;
				printf("Min cost: %d\n",totalDist);
                
                for (int k=i+1;k<m;k++){
                    unused.push_back(E[k].dist);
                }
                
                for (int j=0;j<unused.size();j++){
                    printf("%d",unused[j]);
                    if (j!=unused.size()-1)
                        printf(" ");
                }
                
                printf("\n");
                
                break;
            }
        }
        
        if (!findNum)
            printf("\\(^o^)/ pray to god\n");
        
        
        
    }
    return 0;
}
