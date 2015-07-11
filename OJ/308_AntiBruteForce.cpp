/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13547
 * Submitted at:  2015-03-17 00:25:50
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    308
 * Problem Name:  Anti Brute Force Lock
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

int parent[505];

struct Point {
    int x;
    void read() {
        scanf("%d",&x);
    }
} p[505];

int steps(int a,int b){
    if (abs(b-a)>5){
        return min(a,b)+10-max(a,b);
    }
    else{
        return abs(b-a);
    }
}


int findDist(Point a,Point b){
    int x=steps((a.x)/1000,(b.x)/1000);
    int y=steps(((a.x)/100)%10,((b.x)/100)%10);
    int z=steps(((a.x)/10)%10,((b.x)/10)%10);
    int k=steps((a.x)%10,(b.x)%10);
    //cout << x << " " << y << " " << z << " " << k << endl;
    return x+y+z+k;
}


struct Edge {
    int st,end;
    int dist;
    Edge() {}
    Edge(int i,int j){
        st=i;
        end=j;
        dist=findDist(p[i],p[j]);
        
    }
    
    bool operator < (const Edge & e) const {
        return dist<e.dist;
    }
    
}E[250005];


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
    int tc=0;
    
    scanf("%d",&tc);
    for (int i=0;i<tc;i++){
        int n=0;
        int m=0;
        
        scanf("%d",&n);
        //cout << n << endl;
        p[0].x=0;
        parent[0]=0;
        int minDist=9999;
        int edge1=0;
        int e_dist=0;
        
        for (int j=1;j<n+1;j++){
            parent[j]=j;
            p[j].read();
            //cout << p[j].x << endl;
            
            if ((e_dist=findDist(p[0],p[j]))<minDist){
                edge1=j;
                minDist=e_dist;
            }
            for(int k=1;k<j;k++){
                E[m++]=Edge(j,k);
                //cout << E[m-1].dist << endl;
                
            }
        }
        E[m++]=Edge(0,edge1);
        //cout << edge1 << endl;
        
        sort(E,E+m);
        
        int totalSteps=0;
        
        for (int j=0;j<m;j++) {
            int a = find(E[j].st);
            int b = find(E[j].end);
            //printf("%d %d\n",a,b);
            if (a != b){
                parent[a] = b;
                totalSteps+=E[j].dist;
            }
                
            //cout << E[i].dist << endl;
            if (findAll(n+1)) {
                break;
            }
        }
        
        printf("%d\n",totalSteps);
        
    }
            
        
    
    
    
    return 0;
}
