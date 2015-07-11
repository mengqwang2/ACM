/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 17243
 * Submitted at:  2015-05-13 21:50:13
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    446
 * Problem Name:  Economic phone calls (UVa 11052)
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
#include <utility>
#include <bitset>
#include <cstring>
#include <typeinfo>
#include <climits>
#include <numeric>
#include <cmath>

using namespace std;

int call_time[1024];
int yr[1024];
int dp[1014];
char s[1024][4];
int e;

void calPhoneCall(int n,int y){
    int last=-1;
    
    for (int i=n-1;i>=0;i--) {
        if (last==-1 && yr[i]==y)
            dp[i]=1; 		
        else
            dp[i]=n-i;
        
        if (s[i][0]=='+')
            e=i;
        
        if (last==-1 && (s[i][0] == '+' || yr[i]!= y))
            last=i;
        
        
    }
    
    for (int i=last;i>=e;i--) {
        for (int j=i+1;j<n;j++) {
            if (yr[i]==yr[j])
                dp[i]=min(dp[i],dp[j]+1);
            else if (call_time[i] >= call_time[j] && yr[j]-yr[i]==1)
                dp[i]=min(dp[i],dp[j]+1);
            else
                break;
            
            if (s[j][0]=='+')
                break;
        }
    }
}

int main(){
    int n;
	while (scanf("%d",&n)==1 && n) {
        memset(call_time,0,sizeof(call_time));
        memset(dp,0,sizeof(dp));
        memset(yr,0,sizeof(call_time));
        memset(s,0,sizeof(s));
        
		int mm, dd, HH, MM;
		for (int i=0;i<n;i++) {
			scanf("%d:%d:%d:%d %*s %s", &mm, &dd, &HH, &MM, s[i]);
			call_time[i]=((mm*31+dd)*24+HH)*60+MM;
		}
        
        
		int cur;
		for (int i=1;i<n;i++) {
			if (call_time[i]<=call_time[i-1])
				yr[i]=yr[i-1]+1;
			else
				yr[i]=yr[i-1];
			cur=yr[i];
        }
		
		e=-1;
        calPhoneCall(n,cur);
        
		printf("%d\n", dp[e]);
	}
	return 0;
}