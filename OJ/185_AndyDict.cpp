/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14697
 * Submitted at:  2015-04-19 22:13:23
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    185
 * Problem Name:  Andy's First Dictionary (UVa 10815)
 */

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <tuple>
#include <map>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cstring>
#include <sstream>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%d",&n)
#define S2(m,n) scanf("%d %d",&m,&n)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;

int main(){
	string line;
	string tok;
	string buf;
	std::set<std::string> dic;
	while (cin >> tok){
			string newS="";
			for (int i=0;i<tok.length();i++){
				if(isalpha(tok[i])){
					newS+=tolower(tok[i]);
				}
				else{
					newS+=' ';
				}

			}

			stringstream s1(newS);
			while(s1 >> buf){
				dic.insert(buf);
			}
		
	}

	for (std::set<string>::iterator it=dic.begin();it!=dic.end();++it){
		cout << *it << endl;
	}

	return 0;
}