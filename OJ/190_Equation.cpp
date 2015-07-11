/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11487
 * Submitted at:  2015-01-28 15:04:27
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    190
 * Problem Name:  Equation (UVa 727)
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

stack<char> sign;

bool isHigher(char s1,char s2)
{
	if((s1=='+'&&s2=='-')||(s1=='-'&&s2=='+'))
		return false;
	else if((s1=='*'&&s2=='/')||(s1=='/'&&s2=='*'))
		return false;
	else if((s1=='+'&&s2=='*')||(s1=='+'&&s2=='/')||(s1=='-'&&s2=='*')||(s1=='-'&&s2=='/'))
		return true;
	else
		return false;
}

void checkSign(char sn)
{
	if(sign.empty()||isHigher(sign.top(),sn)||sign.top()=='(')
	{
		sign.push(sn);
	}
	else
	{
		cout << sign.top();
		sign.pop();
		checkSign(sn);
	}
}

int main()
{
	int test;
	cin >> test;
    string blank;
    getline(cin,blank);
    getline(cin,blank);
    char a;
    int term=1;
	for(int i=0;i<test;i++)
	{
        cin.get(a);
        while (a!='\n'&&term==1)
		{
            if(a<='9'&&a>='0')
			{
				cout << a;
			}
			else if(a=='+'||a=='-'||a=='*'||a=='/')
			{
				checkSign(a);
			}
			else if(a=='(')
			{
				sign.push(a);
			}
			else if(a==')')
			{
				while(sign.top()!='(')
				{
					cout << sign.top();
					sign.pop();
				}
				sign.pop();
			}
            getline(cin,blank);
			if(!(cin.get(a)))
                term=0;
		}
		while(!sign.empty())
		{
			cout << sign.top();
			sign.pop();
		}
        if(i==test-1)
            cout << endl;
        else
            cout << endl << endl;
        
	}
	
	return 0;
}