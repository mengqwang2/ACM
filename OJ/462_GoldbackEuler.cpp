/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 17040
 * Submitted at:  2015-05-11 23:51:27
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    462
 * Problem Name:  Goldbach and Euler (UVa 10311)
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
#define N 10000
#define M 100000000

typedef long long int LL;

int flag[(M>>6)+1];
int cnt=0;

bool isComposite(int n){
    return flag[n>>6]&(1<<((n>>1)&31));
}

void setComposite(int n){
    flag[n>>6]|=(1<<((n>>1)&31));
}

bool isPrime(int n){
    if(n<2 || (n>2 && n%2==0))
        return false;
    else
        return !isComposite(n);
}

int main(){
    int n;
    
	//memset(flag,1,sizeof(flag));
	
    for(int i=3;i<=N;i+=2)
	{
		if(!isComposite(i)){
            for(int j=i*i;j<=M;j+=i+i)
                setComposite(j);
        }
		
        
	}
    
    
    for(int tc=0;tc<100000;tc++){
        scanf("%d",&n);
		int a=0;
		int b=0;
		if(n==0){
			a=0;b=0;
		}else if(n==1){
			a=0;b=0;
		}else if(n==2){
			a=0;b=2;
		}else if(n & 1){
			if(isPrime(n-2)){
				a=2;
				b=n-2;
			}
		}else{
			int i=n/2;
			
			for(int j=i;j>=2;j--){
				if(isPrime(j) && isPrime(n-j) && j!=n-j){
					a=j;
					b=n-j;
					break;
				}
			}
            
		}
        
		if (a)
			printf("%d is the sum of %d and %d.\n", n, a, b);
		else
			printf("%d is not the sum of two primes!\n", n);
        
    }
    
    return 0;
}