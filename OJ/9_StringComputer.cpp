/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15630
 * Submitted at:  2015-05-01 22:28:10
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    9
 * Problem Name:  String Computer
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
#define S1(n) scanf("%s",n)
#define S2(m,n) scanf("%d %d",&m,&n)
#define N 25
#define INF 0x3f3f3f3f

char a[N],b[N];
int dist[N][N],p[N][N];

void print_edit(int i,int j){
    if(i==0 && j==0){
        return;
    }
    else if(p[i][j]==3){
        print_edit(i-1,j-1);
        printf("C%c%02d",b[j-1],j);
    }else if(p[i][j]==2){
        print_edit(i-1,j);
        printf("D%c%02d",a[i-1],j+1);
    }else if(p[i][j]==1){
        print_edit(i,j-1);
        printf("I%c%02d",b[j-1],j);
    }else{
        print_edit(i-1,j-1);
    }
}

int main(){
    while(S1(a)){
        if(a[0]!='#'){
            S1(b);
            int l1=strlen(a);
            int l2=strlen(b);
      
            
            //initialization
            for (int i=0;i<=l1;i++){
                for (int j=0;j<=l2;j++){
                    dist[i][j]=400;
                    p[i][j]=0;
                }
            }
            
            
            
            for (int i=0;i<=l1;i++){
                dist[i][0]=i;
                p[i][0]=2;
            }
            
            
            for (int i=0;i<=l2;i++){
                dist[0][i]=i;
                p[0][i]=1;
            }
            
            for(int i=1;i<=l1;i++){
                for (int j=1;j<=l2;j++){
                    int x=dist[i-1][j]+1;
                    int y=dist[i][j-1]+1;
                    int z=dist[i-1][j-1]+(a[i-1]==b[j-1]?0:1);
   
                    if(z<=y && z<=x){
                        dist[i][j]=z;
                        if (a[i-1]!=b[j-1])
                            p[i][j]=3;
                    }else if(y<=x && y<=z){
                        dist[i][j]=y;
                        p[i][j]=1;
                    }else if(x<=y && x<=z){
                        dist[i][j]=x;
                        p[i][j]=2;
                    }
                    
                    
                    
                }
            }
            
            print_edit(l1,l2);
            printf("E\n");
            
        }else{
            break;
        }
        
        
    }
    
    return 0;
}