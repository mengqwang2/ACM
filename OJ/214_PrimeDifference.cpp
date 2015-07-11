/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14885
 * Submitted at:  2015-04-23 19:25:45
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    214
 * Problem Name:  Prime difference
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
#define N 100005
#define M 1299715

int prime[N];
int primeGap[M];
bool flag[M];
int cnt=0;


int main(){
    int n;
    prime[0]=2;
    
    
    memset(flag,true,sizeof(flag));
    for(int i=2;i<=M;i++)
	{
        if (flag[i]){
            prime[++cnt]=i;
            for (int j=prime[cnt-1]+1;j<prime[cnt];j++)
                primeGap[j]=prime[cnt]-prime[cnt-1];
        }
        
		for(int j=1;j<=cnt && i*prime[j]<=M;j++)
        {
			flag[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
            
		}
	}
    
    while(scanf("%d",&n),n){
            if(flag[n])
                printf("%d\n",0);
            else{
                printf("%d\n",primeGap[n]);
            }
    }
    
    return 0;
}