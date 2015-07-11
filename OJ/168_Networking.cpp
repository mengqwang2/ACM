/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16499
 * Submitted at:  2015-05-08 20:51:13
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    168
 * Problem Name:  Networking
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
int parent[55];

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
    
}E[55005];


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
	char blank[10];
    while (scanf("%d",&n) && (n!=0)){
        scanf("%d",&m);
        
		if(m==0){
			printf("%d\n",0);
		}else{
		int u,v,dist;
        bool findNum=false;

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for (int i=0;i<m;i++){
            scanf ("%d %d %d",&u,&v,&dist);
            E[i]=Edge(u-1,v-1,dist);
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
				printf("%d\n",totalDist);
                
                
                break;
            }

        }
        
		cin.getline(blank,10);
        
        
		}
        
    }
    return 0;
}
