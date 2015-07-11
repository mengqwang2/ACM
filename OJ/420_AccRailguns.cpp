/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14818
 * Submitted at:  2015-04-22 17:27:38
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    420
 * Problem Name:  Accelerated Railgun
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

Point origin(0,0);
Point vec(0,0);
Point proj(0,0);

int onSameLine(Point origin,Point vec,Point proj){
    double x1=proj.x;
    double x2=vec.x;
    double x3=origin.x;
    
    double y1=proj.y;
    double y2=vec.y;
    double y3=origin.y;
    
    if (abs((x2-x1)*(y3-y2)-(y2-y1)*(x3-x2))<EPS){
        return 1;
    }
    else if (abs((x2-x1)*(y3-y2)+(y2-y1)*(x3-x2))<EPS){
        return -1;
    }
    return 0;
}

double squareDist(Point a, Point b)  {
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return dx*dx+dy*dy;
}


int main(){
    double range;
    
    while(scanf("%lf",&range) && range){
        double x,y;
        S2(x,y);
        proj=Point(x,y);
        
        S2(x,y);
        vec=Point(x,y);
        
        int direction=onSameLine(origin,vec,proj);
        if (direction==1){
            double d=sqrt(squareDist(origin,proj));
            if (d<range || abs(d-range)<EPS)
                cout << "possible" << endl;
            else
                cout << "impossible" << endl;
        }
        else if(direction==-1){
            double d=2-sqrt(squareDist(origin,proj));
            if (d<range|| abs(d-range)<EPS)
                cout << "possible" << endl;
            else
                cout << "impossible" << endl;
        }
        else{
            cout << "impossible" << endl;
        }
        
        
    }
    
    
    return 0;
}