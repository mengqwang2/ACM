/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11054
 * Submitted at:  2015-01-17 16:09:35
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    2
 * Problem Name:  Output format
 */

#include <stdio.h>

int main()
{
    int a;
    int i=0;
    while (scanf("%d",&a)!=EOF){
        if (i==0){
            printf("%d\n",a);
        }
        else{
            printf("\n%d\n",a);
        }
        i++;
    }
    
    return 0;
}