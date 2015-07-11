/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11233
 * Submitted at:  2015-01-20 23:43:46
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    548
 * Problem Name:  Magic binary dot card
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned long long a=0;
    unsigned long long b=0;
    int a_bit[64];
    int b_bit[64];
    
    while(scanf("%lld %lld",&a,&b)!=EOF){
        memset(a_bit,0,sizeof(a_bit));
        memset(b_bit,0,sizeof(b_bit));
        
        int i=0;
        int j=0;
        
        while(a!=0){
            a_bit[i]=a%2;
            a>>=1;
            i++;
        }
        
        while(b!=0){
            b_bit[j]=b%2;
            b>>=1;
            j++;
        }
        
        int d=0;
        d=j;
        
        if (d==64){
            d--;
        }
        
        unsigned long long sum=0;
        unsigned long long m=1;
        m<<=d;
        int k=d;
        while(a_bit[k]==b_bit[k] && k>=0){
            sum+=a_bit[k]*m;
            k--;
            m>>=1;
        }
        
        long long c =1;
        c<<=k+1;
        c--;
        
        sum+=c;
        printf("%lld\n",sum);
    }
    
    return 0;
}