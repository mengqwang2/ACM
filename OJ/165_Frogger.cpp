/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13505
 * Submitted at:  2015-03-14 18:51:49
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    165
 * Problem Name:  Frogger (UVa 534) (Precision)
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

const int SZ = 300;
int parent[SZ];

struct Point {
    int x, y;
    void read() {
        scanf("%d %d", &x, &y);
    }
} p[SZ];


double findDist(Point a,Point b){
    int d1=a.x-b.x;
    int d2=a.y-b.y;
    return sqrt(d1*d1+d2*d2);
}

struct Edge {
    int st,end;
    double dist;
    Edge() {}
    Edge(int i,int j){
        st=i;
        end=j;
        dist=findDist(p[i],p[j]);
        
    }
    
    bool operator < (const Edge & e) const {
        return dist<e.dist;
    }
    
}E[SZ*SZ];


int find(int x) {
    if (x==parent[x])
        return x;
    return parent[x] = find(parent[x]);
    
}

int main()
{
    int n=0;
    int m=0;
    
    int tc=0;
    while (scanf("%d",&n) && (n!=0)){
        m=0;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            p[i].read();
            for (int j = 0; j < i; j++){
                E[m++] = Edge(i,j);
                //cout << E[m-1].dist << endl;
            }
        }
        
        sort(E,E+m);
        
        for (int i = 0; i < m; i++) {
            int a = find(E[i].st);
            int b = find(E[i].end);
            //printf("%d %d\n",a,b);
            if (a != b)
                parent[a] = b;
            
            //cout << E[i].dist << endl;
            if (find(0) == find(1)) {
                printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++tc, E[i].dist);
                break;
            }
        }
    }
    
    
    return 0;
}
