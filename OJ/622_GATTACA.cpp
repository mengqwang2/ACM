/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14980
 * Submitted at:  2015-04-25 00:46:44
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    622
 * Problem Name:  GATTACA
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
#include <set>
#include <stack>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define MEM(arr,x) memset(arr,x,sizeof(arr))
#define S1(n) scanf("%d",&n)
#define S2(m,n) scanf("%d %d",&m,&n)
#define MAXN 1010
char str[MAXN];
int wa[MAXN],wb[MAXN],wv[MAXN],ws1[MAXN];
int sa[MAXN],height[MAXN],ranks[MAXN];

inline bool cmp(int *r,int a,int b,int L)
{
    return r[a]==r[b]&&r[a+L]==r[b+L];
}

void SA(int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)
        ws1[i]=0;
    for(i=0;i<n;i++)
        ws1[x[i]=str[i]]++;
    for(i=1;i<m;i++)
        ws1[i]+=ws1[i-1];
    for(i=n-1;i>=0;i--)
        sa[--ws1[x[i]]]=i;
    
    
    for(j=p=1;p<n;j<<=1,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
        {
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        }
        for(i=0;i<m;i++)
            ws1[i]=0;
        for(i=0;i<n;i++)
            ws1[wv[i]=x[y[i]]]++;
        for(i=1;i<m;i++)
            ws1[i]+=ws1[i-1];
        for(i=n-1;i>=0;i--)
            sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

void Height(int len)
{
    int i,j,k;
    for(i=1;i<=len;i++)
        ranks[sa[i]]=i;
    
    i=k=0;

    while(i<len){
        if(k>0)
            k--;
        else
            k=0;
        j=sa[ranks[i]-1];
        while(str[i+k]==str[j+k]){
            k++;
        }
        height[ranks[i]]=k;
        i++;
    }
    

}

int main(){
    int tc;
    S1(tc);
    FOR(i,tc){
        scanf("%s",str);
        int l=(int)strlen(str);
        SA(l+1,'z');
        Height(l);
        int result=0;
        int index=0;
        
        for(int j=0;j<=l;j++){
            if(height[j]>result){
                result=height[j];
                index=j;
            }
        }
        
        if (result){
            int freq=1;
            for (int j=index;j<=l && height[j]>=result;j++){
                freq++;
            }
                
            for (int j=sa[index];j<sa[index]+result;j++){
                printf("%c",str[j]);
            }
            
            printf(" %d\n",freq);
        }
        else{
            printf("No repetitions found!\n");
        }
        
        
        
    }
    
    
    
    
    return 0;
}