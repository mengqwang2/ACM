/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14768
 * Submitted at:  2015-04-21 13:47:57
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    248
 * Problem Name:  Intersection (UVa 191)
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

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;
typedef long long int LL;

struct Pt{
    int x;
    int y;
    
    Pt()=default;
    
    Pt(int a,int b){
        x=a;
        y=b;
    }
};

struct line{
    Pt s;
    Pt e;
    
    line()=default;
    
    line(Pt p1,Pt p2){
        s=p1;
        e=p2;
    }
    
    void read(){
        int xs,xe,ys,ye;
        scanf("%d %d %d %d",&xs,&ys,&xe,&ye);
        s=Pt(xs,ys);
        e=Pt(xe,ye);
    }
}l;

struct rec{
    line left;
    line right;
    line top;
    line bottom;
    
    rec()=default;
    
    void read(){
        int xl,yt,xr,yb;
        scanf("%d %d %d %d",&xl,&yt,&xr,&yb);
        
        if(xl>xr) swap(xl,xr);
        if(yb>yt) swap(yb,yt);
        
        Pt plt=Pt(xl,yt);
        Pt plb=Pt(xl,yb);
        Pt prt=Pt(xr,yt);
        Pt prb=Pt(xr,yb);
        
        left=line(plt,plb);
        right=line(prt,prb);
        top=line(plt,prt);
        bottom=line(plb,prb);
    }
}r;

int cw(Pt p1,Pt p2,Pt p3){
    return (p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p3.x*p2.y) + (p3.x*p1.y - p1.x*p3.y);
    
}

bool inSeg(Pt p,line seg){
    int x=p.x;
    int y=p.y;
    
    int x1=seg.s.x;
    int x2=seg.e.x;
    int y1=seg.s.y;
    int y2=seg.e.y;
  
    if(cw(seg.s,seg.e,p)==0){
        if (min(x1,x2)<=x && max(x1,x2)>=x && min(y1,y2)<=y && max(y1,y2)>=y)
            return true;
        else
            return false;
    }
    return false;
}

bool isInterSection(line l1,line l2){
    int a=cw(l1.s,l1.e,l2.s)*cw(l1.s,l1.e,l2.e);
    int b=cw(l2.s,l2.e,l1.s)*cw(l2.s,l2.e,l1.e);
    
    if (a<0 && b<0)
        return true;
    else if(inSeg(l1.s,l2) || inSeg(l1.e,l2) || inSeg(l2.s,l1) || inSeg(l2.e,l1)){
        return true;
    }
    return false;
}

bool isInterSectRec(line test,rec r){
    if (isInterSection(test,r.left) || isInterSection(test,r.right) || isInterSection(test,r.top) || isInterSection(test,r.bottom))
        return true;
    else if (min(test.s.x,test.e.x)>=r.left.s.x && min(test.s.y,test.e.y)>=r.bottom.s.y && max(test.s.x,test.e.x)<=r.right.s.x && max(test.s.y,test.e.y)<=r.top.s.y && min(test.s.x,test.e.x)<=r.right.s.x && max(test.s.x,test.e.x)>=r.left.s.x && min(test.s.y,test.e.y)<=r.top.s.y && max(test.s.y,test.e.y)>=r.bottom.s.y)
        return true;
    return false;
}

int main(){
    int n;
    S1(n);
    
    FOR(i,n){
        l.read();
        r.read();
        
        if (isInterSectRec(l,r))
            cout << "T" << endl;
        else
            cout << "F" << endl;
        
    }
    
    return 0;
}