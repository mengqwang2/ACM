/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14791
 * Submitted at:  2015-04-22 01:58:53
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    210
 * Problem Name:  Convex Hull Finding (maybe wrong) (UVa 681)
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
#define S1(n) scanf("%d",&n)
#define S2(m,n) scanf("%d %d",&m,&n)
#define EPS 0.0000000001

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;
typedef long long int LL;

struct Point{
    int x;
    int y;
    
    Point()=default;
    
    Point(int a,int b){
        x=a;
        y=b;
    }
    
    void read(){
        S2(x,y);
    }
    
    bool operator < (Point b){
        if (y!=b.y){
            return y<b.y;
        }else{
            return x<b.x;
        }
    }
}p;

Point anchor(0,0);

bool colinear(Point &p1,Point &p2,Point &p3)
{
    int test=(p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p3.x*p2.y) + (p3.x*p1.y - p1.x*p3.y);
    return test==0;
    
}

bool cw(Point p1,Point p2,Point p3){
    int a=(p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p3.x*p2.y) + (p3.x*p1.y - p1.x*p3.y);
    return a>0;
}

int squareDist(Point a, Point b)  {
    int dx=a.x-b.x;
    int dy=a.y-b.y;
    return dx*dx+dy*dy;
}

bool ANGLE_ORDER(Point a,Point b)  {
    if (colinear(anchor,a,b))
        return squareDist(anchor,a)<squareDist(anchor,b);
    return cw(anchor,a,b);
}

vector<Point> grahamScan(vector<Point> &P)    {
    int N=(int)P.size();
    int po=0;
    for (int i=0;i<N-1;i++)
        if(P[i]<P[po])
            po=i;
    anchor=P[po];
    
    sort(P.begin(),P.end(),ANGLE_ORDER);
    
    Point prev(0,0),now(0,0);
    stack<Point> S;
    S.push(anchor);
    int i=1;
    while(i<N)
    {
        if(S.size()<2)
        {
            S.push(P[i++]);
        }
        else{
            now = S.top();
            S.pop();
            prev=S.top();
            S.push(now);
            if(cw(prev,now,P[i]))
                S.push(P[i++]);
            else
                S.pop();
        }
    }
    
    vector<Point> hull;
    hull.push_back(anchor);
    while(!S.empty())
    {
        hull.push_back(S.top());
        S.pop();
    }
    return hull;
}

int main(){
    int k;
    S1(k);
    cout << k << endl;
    FOR(i,k){
        int n;
        S1(n);
        
        vector<Point> ptSet(n);
        FOR(j,n){
            p.read();
            ptSet[j]=p;
        }
        
        if (i<k-1){
            int del;
            S1(del);
        }
        
        vector<Point> hull = grahamScan(ptSet);
        cout << hull.size() << endl;
        
        for (int j=hull.size()-1;j>=0;j--){
            cout << hull[j].x << " " << hull[j].y << endl;
        }
        
        
        if (i<k-1)
            cout << -1 << endl;
        
    }
    
    return 0;
}