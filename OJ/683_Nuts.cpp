/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16501
 * Submitted at:  2015-05-08 21:22:49
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    683
 * Problem Name:  Nuts
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

using namespace std;

int putNuts(int k,int a,int b,int v){
	if(b<k-1){
		if((b+1)*v>=a)
			return 1;
		else
			return 1+ceil((a-(b+1)*v*1.0)/v);

	}else{
		if(k*v>=a)
			return 1;
		else{
			a=a-k*v;
			b=b-(k-1);
			return putNuts(k,a,b,v)+1;
		}
	}
}


int main()
{
    int k,a,b,v;

	while(scanf("%d %d %d %d",&k,&a,&b,&v)!=EOF){
		printf("%d\n",putNuts(k,a,b,v));

	}

    return 0;
}
