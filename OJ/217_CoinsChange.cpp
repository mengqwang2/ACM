/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12174
 * Submitted at:  2015-02-17 17:50:21
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    217
 * Problem Name:  Coin Change (UVa 674)
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

using namespace std;

int dp[9999];
int coins[5]={50,25,10,5,1};

void makeChange(int total)
{
    for(int i=0;i<9999;i++)
    {
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<5;i++)
    {
        for(int j=1;j<=total;j++)
        {
            if(j<coins[i])
                continue;
            dp[j]+=dp[j-coins[i]];
        }
    }
}

int main()
{
    int total;
    while (cin >> total)
    {
        makeChange(total);
        cout << dp[total] << endl;
    }
}
