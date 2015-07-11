/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 13022
 * Submitted at:  2015-03-07 14:16:09
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    678
 * Problem Name:  Find the Thief
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
#include <math.h> 

using namespace std;

void isThief(int n){
        int sum=0;
        
		while (n>1){
			sum+=ceil(n/2.0);
			n=n/2;

		}

        cout << sum << endl;
}

int main()
{
    int n;
    
    while(scanf("%d",&n)!=EOF){
        isThief(n);
    }
    
    
}
