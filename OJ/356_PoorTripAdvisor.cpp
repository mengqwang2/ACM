/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13517
 * Submitted at:  2015-03-14 21:55:17
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    356
 * Problem Name:  Poor Trade Advisor (UVa 11749)
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

using namespace std;
#define INF 2147483648

const int N_SIZE = 505;
const int M_SIZE = 1000005;

int adj[N_SIZE][N_SIZE];
bool visited[N_SIZE];
int highest;
int cnt;

void dfs(int n,int g_size){
	cnt++;
	visited[n]=true;
	for (int i=0;i<g_size;i++){
		if(adj[i][n]==highest && !visited[i]){
			dfs(i,g_size);	
		}
	}
}

int main()
{
    int n=0;
    int m=0;
	int result=-INF;
	while (scanf("%d %d",&n,&m) && n && m){
		cnt=0;
		highest=-INF;
		for (int i=0;i<N_SIZE;i++){
			memset(adj[i],-INF,sizeof(adj[i]));
		}
		memset(visited,false,sizeof(visited));
		int st,end;
		int dist;
		for (int i=0;i<m;i++){
			scanf("%d %d %d",&st,&end,&dist);
			adj[st-1][end-1]=dist;
			adj[end-1][st-1]=dist;
			highest=max(highest,dist);
			
		}

		for (int i=0;i<n;i++){
			cnt=0;
			if (!visited[i]){
				dfs(i,n);
				result=max(result,cnt);

			}
				

		}

		printf("%d\n",result);

	}


	
    return 0;
}
