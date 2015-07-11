/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11062
 * Submitted at:  2015-01-17 16:17:08
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    674
 * Problem Name:  Odd number
 */

#include <stdio.h>

int main()
{
    int a,b;
    int cnt;
    while (scanf("%d %d",&a,&b)!=EOF){
        cnt = 0;
        for (int i=a;i<=b;++i){
            if(i%2!=0){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    
    return 0;
}