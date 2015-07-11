/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13568
 * Submitted at:  2015-03-17 13:07:55
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    143
 * Problem Name:  Slim Span - Tokyo Regional 07 (LA 3887)
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
    int st,end;
    int dist;
    Edge() {}
    Edge(int i,int j,int k){
        st=i;
        end=j;
        dist=k;
        
    }
    
    bool operator < (const Edge & e) const {
        return dist<e.dist;
    }
    
}E[60005];


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
        //cout << n << " " << m << " " << endl;
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            parent[x-1]=x-1;
            parent[y-1]=y-1;
            E[i]=Edge(x-1,y-1,z);
        }
        
        sort(E,E+m);
        
        int minEdge=0;
        int maxEdge=0;
        int gap=99999;
        
        bool minTree=false;
        
        
        for (int sn=0;sn<m;sn++){
            bool findTree=false;
            for (int i=0;i<n;i++){
                parent[i]=i;
            }
            
            for (int i=sn;i<m;i++) {
                int a = find(E[i].st);
                int b = find(E[i].end);
                
                if (a != b){
                    parent[a] = b;
                }
                
                if (i==sn){
                    minEdge=E[i].dist;
                }
                if (findAll(n)) {
                    maxEdge=E[i].dist;
                    //cout << maxEdge << endl;
                    minTree=true;
                    findTree=true;
                    break;
                }
            }
            
            //cout << maxEdge << " " <<  minEdge << endl;
            if (findTree)
                gap=min(gap,maxEdge-minEdge);
        }
        
        
        if(minTree){
            //cout << 1 << endl;
            cout << gap << endl;
        }
        else{
            cout << -1 << endl;
        }
        
        
        
    }  
    
    return 0;
}
