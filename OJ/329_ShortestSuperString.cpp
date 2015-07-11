/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12241
 * Submitted at:  2015-02-19 20:00:36
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    329
 * Problem Name:  Super string? Shortest?
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dp[1001][1001];


int main()
{
    int test;
    cin >> test;
    char buf[2][1001];
    gets(buf[0]);
    for (int i=0;i<test;i++)
    {
        memset(dp,0,sizeof(dp));
        gets(buf[0]);
        gets(buf[1]);
        int m=strlen(buf[0]);
        int n=strlen(buf[1]);
        for(int i = 1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if( buf[0][i-1] == buf[1][j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    if( dp[i][j-1] < dp[i-1][j])
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        cout << m-dp[m][n]+n-dp[m][n]+dp[m][n] << endl;
    }
    
    return 0;
}