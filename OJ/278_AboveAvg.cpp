/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15753
 * Submitted at:  2015-05-03 15:50:01
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    259
 * Problem Name:  Brackets sequence (easy ver.)
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

int dp[105][105];
char bra[105];
char blank[10];

bool isPair(char a,char b){
    if (a=='(' && b==')')
        return true;
    else if(a=='[' && b==']')
        return true;
    else
        return false;
}

int main(){
    
    int tc;
    scanf("%d",&tc);
    cin.getline(blank,10);
    
    while(tc--){
        //read blank line
        cin.getline(blank,10);
        
        //read brackets line
        cin.getline(bra,105);
        
        int braLen=strlen(bra);
        //initialization
        for (int i=0;i<=braLen;i++){
            for (int j=0;j<=braLen;j++){
                if (i==0)
                    dp[i][j]=2;
                else
                    dp[i][j]=0;
            }
        }
        
        for (int i=1;i<=braLen;i++){
            for (int j=1;j<=braLen-i;j++){
                int a,b;
                dp[i][j]=2*braLen;
                if (i==1){
                    dp[i][j]=isPair(bra[j-1],bra[j])?2:4;
                }
                
                if (i>=2 && isPair(bra[j-1],bra[j+i-1])){
                    dp[i][j]=min(dp[i][j],dp[i-2][j+1]+2);
                }
                
                a=dp[0][j]+dp[i-1][j+1];
                for (int k=1;k<i;k++){
                    a=min(a,dp[k][j]+dp[i-k-1][j+k+1]);
                }
                
                dp[i][j]=min(dp[i][j],a);
                
                
                
            }
        }
        
        if(braLen>0)
            printf("%d\n",dp[braLen-1][1]);
        else
            printf("%d\n",0);
        
        if (tc>=1){
            cout << endl;
        }
    }
    
    
    
    return 0;
}