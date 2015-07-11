/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12233
 * Submitted at:  2015-02-19 14:40:03
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    216
 * Problem Name:  Longest Common Subsequence (UVa 10405)
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
#include <algorithm>

using namespace std;

int dp[1001][1001];
int bt[1001][1001];

string s1;
string s2;

int main()
{
    while(getline(cin,s1)){
        stack<char> ss;
        getline(cin,s2);
        memset(dp,0,sizeof(dp));
        memset(bt,0,sizeof(bt));
        for (int i=1;i<=s1.length();i++){
            for (int j=1;j<=s2.length();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    bt[i][j]=1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(dp[i-1][j]>=dp[i][j-1]){
                        bt[i][j]=2;
                    }
                    else{
                        bt[i][j]=3;
                    }
                }
            }
        }
        
        //backtracing
        int i=s1.length();
        int j=s2.length();
        
        while(i>0 && j>0){
            if(bt[i][j]==1){
                ss.push(s1[i-1]);
                i--;
                j--;
            }
            else if(bt[i][j]==2){
                i--;
            }
            else if(bt[i][j]==3){
                j--;
            }
        }
        
        int count=0;
        while(!ss.empty()){
            //cout << ss.top() << " ";
            ss.pop();
            count++;
        }
        cout << count << endl;
    }
}
