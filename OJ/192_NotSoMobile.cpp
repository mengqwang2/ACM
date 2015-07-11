/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 1916
 * Submitted at:  2013-01-25 19:25:02
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    192
 * Problem Name:  Not so Mobile (UVa 839)
 */

#include <iostream>
using namespace std;

bool balance=true;

int testBalance(int a1,int b1,int c1,int d1)
{
		int left,right;
		int a=a1;
		int b=b1;
		int c=c1;
		int d=d1;
		if(a==0&&c==0)
		{
			cin >> a >> b >> c >> d;
			left=testBalance(a,b,c,d);
			cin >> a >> b >> c >> d;
			right=testBalance(a,b,c,d);
			if(left*b1!=right*d1)
				balance=false;
		}
		else if(a!=0&&c==0)
		{
			cin >> a >> b >> c >> d;
			right=testBalance(a,b,c,d);
			if(a1*b1!=right*d1)
				balance=false;
			left=a1;
		}
		else if(a==0&&c!=0)
		{
			cin >> a >> b >> c >> d;
			left=testBalance(a,b,c,d);
			if(left*b1!=c1*d1)
				balance=false;
			right=c1;
		}
		else
		{
			if(a1*b1!=c1*d1)
			{
				balance=false;
			}
			left=a1;
			right=c1;
		}
		return left+right;
}

int main()
{
	int test;
	cin >> test;

	for(int i=0;i<test;i++)
	{	
		balance=true;
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		testBalance(a,b,c,d);
		if(balance==true)
		{
			if(i==test-1)
				cout << "YES" << endl;
			else
				cout << "YES" << endl << endl;
		}
		else
		{
			if(i==test-1)
				cout << "No" << endl;
			else
				cout << "NO" << endl << endl;
		}
	}

	return 0;
}