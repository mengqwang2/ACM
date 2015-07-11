/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14805
 * Submitted at:  2015-04-22 15:51:23
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    385
 * Problem Name:  Useless Tile Packers
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
#define S2(m,n) scanf("%lf %lf",&m,&n)
#define EPS 0.0000000001

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;
typedef long long int LL;

struct Point{
    double x;
    double y;
    
    Point()=default;
    
    Point(double a,double b){
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
    double test=(p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p3.x*p2.y) + (p3.x*p1.y - p1.x*p3.y);
    return fabs(test)<EPS;
    
}

bool cw(Point p1,Point p2,Point p3){
    double a=(p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p3.x*p2.y) + (p3.x*p1.y - p1.x*p3.y);
    return a>0;
}

double squareDist(Point a, Point b)  {
    double dx=a.x-b.x;
    double dy=a.y-b.y;
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
            S.push(P[i++]);
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

double polygon_area(const vector<Point> & ptSet){
    int n=ptSet.size()-1;
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=(ptSet[i].x*ptSet[i+1].y-ptSet[i].y*ptSet[i+1].x);
    }
    
    return fabs(0.5*sum);
}

int main(){
    int tc=1;
    int n;
    while (S1(n) && n){
        vector<Point> ptSet(n+1);
        for(int i=0;i<n;i++){
            p.read();
            ptSet[i]=p;
        }
        ptSet[n]=ptSet[0];
        //sort(ptSet.begin(),ptSet.end(),ANGLE_ORDER);
        double tile_area=polygon_area(ptSet);
        vector<Point> cont=grahamScan(ptSet);
        double cont_area=polygon_area(cont);
        
        double answer=(cont_area-tile_area)/cont_area;
        printf("Tile #%d\nWasted Space = %.2lf %%\n\n",tc,answer*100);
        
        
        tc++;
    }
    
    return 0;
}