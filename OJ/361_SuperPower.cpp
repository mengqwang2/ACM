/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14846
 * Submitted at:  2015-04-23 13:26:10
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    361
 * Problem Name:  The Super Power (UVa 11752)
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
#include <set>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%lf",&n)
#define S2(m,n) scanf("%lf %lf",&m,&n)
#define EPS 1e-6
#define N 100005
#define M 1299709
#define LIMIT 2e64
#define P_LIMIT 2e16

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;
typedef unsigned long long LL;


int cnt=0;
set<LL> res;

const int composite[100] =
{
    4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26,
    27, 28, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46,
    48, 49, 50, 51, 52, 54, 55, 56, 57, 58, 60, 62, 63, 64 
};



int main(){
    LL i;
    LL maxbase=1<<16;
    
    LL j;
    LL maxpower;
    
    LL ins;
    res.insert(1);
    for(i=2;i<maxbase;i++){
        ins=i*i*i*i;
        
        res.insert(ins);
        
        maxpower=ceil(64*log(2)/log(i))-1;
        
        for (j=1;composite[j]<=maxpower;j++)
        {
            if(composite[j] - composite[j-1]==1)
                ins=ins*i;
            else
                ins=ins*i*i;
                
            res.insert(ins);
        }
        
    }
    
    for(set<LL>::iterator it=res.begin();it!=res.end();it++){
        cout << *it << endl;
    }
    

    
    
    return 0;
}