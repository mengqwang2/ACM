/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 2554
 * Submitted at:  2013-02-22 12:36:07
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    218
 * Problem Name:  SuperSale (UVa 10130)
 */

#include <iostream>
using namespace std;

int weight[1000]={0};
int value[1000]={0};
int dp[1001][31]={0};

void superSale(int obj)
{
	
    for(int i=0;i<=obj;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=30;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=obj;i++)
	{
		for(int j=0;j<=30;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(weight[i]<=j&&dp[i-1][j-weight[i]]+value[i]>dp[i-1][j])
				dp[i][j]=dp[i-1][j-weight[i]]+value[i];
		}
	}
}

int main()
{
	int test,obj,ppl,max,totalValue;
	cin >> test;
    
    
	for(int count=0;count<test;count++)
	{
		cin >> obj;
		
		for (int i=1;i<=obj;i++)
		{
			cin >> value[i] >> weight[i];
		}
		cin >> ppl;
        totalValue=0;
        superSale(obj);
        for(int i=0;i<ppl;i++)
        {
            cin >> max;
            totalValue+=dp[obj][max];
        }
        cout << totalValue << endl;
	}
	return 0;
}