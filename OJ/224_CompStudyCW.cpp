/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15955
 * Submitted at:  2015-05-05 18:58:56
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    224
 * Problem Name:  Computer Studies Homework
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 205
#define INF 0x3f3f3f3f
#define LL long long int

char hexa[10005];

int hex2dec(char a){
    if(a>='A' && a<='F')
        return 10+a-'A';
    else
        return a-'0';
}

int main(){
    while(scanf("%s",hexa)!=EOF){
        int len=strlen(hexa);
        //cout << len << endl;
        //printf("%s\n",hexa);
        LL base=1;
        LL result=0;
        for(int i=len-1;i>=1;i--){
            result+=base*hex2dec(hexa[i]);
            base*=16;
        }
        
        if(hexa[0]=='-')
            printf("%lld\n",-1*result);
        else
            printf("%lld\n",result+base*hex2dec(hexa[0]));
    }
    
    
    return 0;  
}