/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14333
 * Submitted at:  2015-03-29 15:34:33
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    314
 * Problem Name:  Extend to Palindromes (UVa 11475)
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
#include <utility>
#include <bitset>
#include <cstring>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%d",&n)
#define S2(m,n) scanf("%d %d",&m,&n)
#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)

typedef vector<int> vi;
typedef vector< pair <int, int> > vii;

void kmp(char str[],int next[],int n)
{
    int i = 0,j = -1;
    next[0]=-1;
    while(i<n)
        if(j == -1 || str[i] == str[j]) next[++i] = ++j;
        else j = next[j];
}

int go_match(char str[],char key[],int next[],int nstr,int nk)
{
    int i = 0,j = 0;
    while(i < nstr && j < nk){
        if(j == -1 || str[i] == key[j])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
            
    }
    return j;
}


int main() {
    char str[100005];
    char str_rev[100005];
    int next[100005];
    while (scanf("%s",str)!=EOF){
        memset(next,0,sizeof(next));
        printf("%s", str);
        int n=strlen(str);
        
        for (int i=0;i<n;i++)
            str_rev[i]=str[i];
        
        reverse(str,str+n);
        kmp(str,next,n);
        
        int k = go_match(str_rev,str,next,n,n);
        //cout << k << endl;
        for (int i=k;i<n;i++)
            printf("%c", str[i]);
        printf("\n");
        
        
    }
    
    return 0;
}