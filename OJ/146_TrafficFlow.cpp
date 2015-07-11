/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13520
 * Submitted at:  2015-03-14 22:25:29
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    146
 * Problem Name:  Traffic Flow (UVa 10842)
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

int parent[105];

struct Edge {
    int st,end,dist;
    Edge() {}
    Edge(int i,int j,int d){
        st=i;
        end=j;
        dist=d;
    }
    
    bool operator < (const Edge & e) const {
        return dist>e.dist;
    }
    
}E[10000];


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
    int n,m,tc;

	scanf("%d",&tc);
	for (int i=0;i<tc;i++){
		scanf("%d %d",&n,&m);
		for (int j=0;j<m;j++){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			E[j]=Edge(a,b,c);
			parent[a]=a;
			parent[b]=b;

		}

		sort(E,E+m);
        
        for (int j=0;j<m;j++) {
            int a=find(E[j].st);
            int b=find(E[j].end);
            if (a!=b)
                parent[a] = b;
            
            if (findAll(n)) {
				printf("Case #%d: %d\n",i+1, E[j].dist);
                break;
            }
        }

	}
    return 0;
}
