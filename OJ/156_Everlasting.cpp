/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14944
 * Submitted at:  2015-04-24 18:21:53
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    156
 * Problem Name:  Everlasting...?
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
#define S2(m,n) scanf("%ld %ld",&m,&n)
typedef long long int LL;
#define N 100000
#define M 1000000

set<long> primeList;
void prime_factorization(long x){
	long i,c;

	c=x;
	while((c%2)==0){
		primeList.insert(2);
		c/=2;
	}

	i=3;
	while(i<=(sqrtl(c)+1)){
		if((c%i)==0){
			primeList.insert(i);
			c/=i;
		}
		else{
			i+=2;
		}

		
	}
	if(c>1)
		primeList.insert(c);
}

long getKey(){
	set<long>::iterator it=primeList.begin();
	long sum=0;
	while(it!=primeList.end()){
		sum+=*it;
		it++;
	}
	it--;
	sum-=(*it);

	return *it-sum;
}

int main(){

	long a,b;
	long k1,k2;
	while(S2(a,b) && a && b){
		primeList.clear();
		prime_factorization(a);
		k1=getKey();
		primeList.clear();
		prime_factorization(b);
		k2=getKey(); 

		if(k1>k2)
			printf("a\n");
		else
			printf("b\n");
	}
	
	return 0;
}