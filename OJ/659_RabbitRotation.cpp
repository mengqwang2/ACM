/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15958
 * Submitted at:  2015-05-05 19:14:20
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    659
 * Problem Name:  Rabbit Rotation
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 205
#define INF 0x3f3f3f3f
#define LL long long int

int rabq[100005];

int rotate(int i,int k,int n){
    return (i+k)%n;
}


int main(){
    int n,k,q;
    while(scanf("%d %d %d",&n,&k,&q)!=EOF){
        int m;
        for(int i=0;i<n;i++){
            
            scanf("%d",&m);
            
            int pos=rotate(i,k,n);
            
            rabq[pos]=m;
            
        
            
        }
        int qno;
        while(q--){
            scanf("%d",&qno);
            printf("%d\n",rabq[qno]);
        }
    }
    
    
    return 0;  
}