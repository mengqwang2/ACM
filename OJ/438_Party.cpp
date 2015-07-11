/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15415
 * Submitted at:  2015-04-27 23:06:19
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    438
 * Problem Name:  Party
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
#include <stack>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%d",&n)
#define S2(m,n) scanf("%d %d",&m,&n)



int main(){
    int n;
    S1(n);
    
    while(n--){
        int m;
        S1(m);
        
        if (m<=2){
            printf("0\n");
        }else{
            printf("%d\n",m-2);
        }
        
        
    }
    
    
    return 0;
}