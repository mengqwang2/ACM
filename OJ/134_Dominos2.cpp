/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16354
 * Submitted at:  2015-05-08 14:33:19
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    134
 * Problem Name:  Dominos 2 (UVa 11518)
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
#include <bitset>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%lld",&n)
#define S2(m,n) scanf("%lld %lld",&m,&n)
#define MAXN 10005


typedef long long int LL;
bitset<MAXN> vis;

void dfs(int d,const vector<vector <int> > &adj){
	vis.set(d);
	for(int i=0;i<adj[d].size();i++){
		if(!vis.test(adj[d][i]))
			dfs(adj[d][i],adj);
	}

}

int main(){
	int tc,n,m,l;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d %d",&n,&m,&l);
		vector<vector <int> > adj(n);
		vis.reset();
		
		FOR(i,m){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a-1].push_back(b-1);

		}

		FOR(i,l){
			int c;
			scanf("%d",&c);
			if(!vis.test(c-1))
				dfs(c-1,adj);
		}

		printf("%d\n",vis.count());

	}

	return 0;
}