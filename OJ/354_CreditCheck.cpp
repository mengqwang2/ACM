/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11216
 * Submitted at:  2015-01-20 19:55:19
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    354
 * Problem Name:  Credit Check (UVa 11743)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int trial=0;
    scanf("%d",&trial);
    for (int i=0;i<trial;++i){
        int input_d=0;
        int undoubled=0;
        int doubled=0;
        int a=0;
        // read & addition
        for (int j=0;j<4;++j){
            scanf("%d",&input_d);
            for (int k=0;k<4;++k){
                if(k%2==0){
                    undoubled+=input_d%10;
                }
                else{
                    a = (input_d%10)*2;
                    doubled+=a/10+a%10;
                }
                input_d/=10;
            }
        }
        
        // validity
        if((doubled+undoubled)%10==0){
            printf("Valid\n");
        }
        else{
            printf("Invalid\n");
        }
        
    }
    
    return 0;
}