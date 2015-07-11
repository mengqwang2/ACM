/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16490
 * Submitted at:  2015-05-08 20:02:51
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    375
 * Problem Name:  Making Okonomiyaki
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

int c1,c2,c3,c4,dest;
bool vis[26][26][26][26];
int cap[4];


struct Cup{
	int volu[4];
	int level;

	Cup() {}

	Cup(int x,int y,int z,int e,int l){
		volu[0]=x;
		volu[1]=y;
		volu[2]=z;
		volu[3]=e;
		level=l;
	}
	
	Cup(const Cup & cup2) {
		for(int i=0;i<4;i++){
			volu[i]=cup2.volu[i];
		}
		level=cup2.level;
	}


	bool vol(){
		for(int i=0;i<4;i++){
			if(volu[i]==dest)
				return true;
		}
		return false;
	}

};

queue<Cup> Q;

void traverse(Cup given){
		int water[4];

		for(int i=0;i<4;i++){
			water[i]=given.volu[i];
		}
	
		int level=given.level;
		int arr[4];

		// single-bucket
		for(int i=0;i<4;i++){
			//bucket i
			if(water[i]<cap[i]){
				for(int j=0;j<4;j++){
					if(j!=i)
						arr[j]=water[j];
					else
						arr[j]=cap[i];
				}
				
				if(!vis[arr[0]][arr[1]][arr[2]][arr[3]]){
					Q.push(Cup(arr[0],arr[1],arr[2],arr[3],level+1));
					vis[arr[0]][arr[1]][arr[2]][arr[3]]=1;
				}
			}
			if(water[i]>0){
				for(int j=0;j<4;j++){
					if(j!=i)
						arr[j]=water[j];
					else
						arr[j]=0;
				}

				if(!vis[arr[0]][arr[1]][arr[2]][arr[3]]){
					Q.push(Cup(arr[0],arr[1],arr[2],arr[3],level+1));
					vis[arr[0]][arr[1]][arr[2]][arr[3]]=1;
				}
			}
				

				
		}
		
		//cross-bucket i->j
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(j!=i){
					arr[i]=water[i]+water[j]-min(cap[j],water[i]+water[j]);
					arr[j]=min(cap[j],water[i]+water[j]);
					for(int k=0;k<4;k++){
						if(k!=i && k!=j){
							arr[k]=water[k];
						}
					}

					if(!vis[arr[0]][arr[1]][arr[2]][arr[3]]){
						Q.push(Cup(arr[0],arr[1],arr[2],arr[3],level+1));
						vis[arr[0]][arr[1]][arr[2]][arr[3]]=1;
					}

				}

			}

		}
			
	}

int main(){
	
	while(scanf("%d %d %d %d %d",&c1,&c2,&c3,&c4,&dest)!=EOF){
		while(!Q.empty())
			Q.pop();

		cap[0]=c1;
		cap[1]=c2;
		cap[2]=c3;
		cap[3]=c4;

		memset(vis,0,sizeof(vis));

		Cup st(0,0,0,0,0);
		vis[0][0][0][0]=1;
		Q.push(st);


		Cup cur=Q.front();
		Q.pop();

		while(!cur.vol()){
			traverse(cur);

			if (!Q.empty()){
				cur=Q.front();
				vis[cur.volu[0]][cur.volu[1]][cur.volu[2]][cur.volu[3]]=1;
				Q.pop();
			}
				
			else
				break;

		}

		if(cur.vol())
			cout << cur.level << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}