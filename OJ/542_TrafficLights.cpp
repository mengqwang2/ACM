/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11244
 * Submitted at:  2015-01-21 19:20:24
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    542
 * Problem Name:  Traffic Lights (UVa 161)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int light[100];
    int duration[100][18000];
    int stop_signal=1;
    while (stop_signal && scanf("%d %d",&light[0],&light[1])){
        if(light[0]!=0 && light[1]!=0){
            int i=2;
            scanf("%d",&light[i]);
            while(light[i]!=0){
                i++;
                scanf("%d",&light[i]);
            }
            
            //sort the arrary
            for (int j=0;j<i;j++){
                for (int k=j;k>0;k--){
                    if(light[k]<light[k-1]){
                        int a=light[k];
                        light[k]=light[k-1];
                        light[k-1]=a;
                    }
                }
            }
            
            //initialization
            for (int j=0;j<i;j++)
            {
                memset(duration[j],0,sizeof(duration[j]));
                int n=0;
                while(2*n*light[j]<18000){
                    int k=2*n*light[j];
                    while(k<2*n*light[j]+light[j]-5){
                        duration[j][k]=1;
                        k++;
                    }
                    n++;
                }
            }

            //calculation
            int sec=0;
            int found=0;
            for(int j=2*light[0];j<18000 && found==0;j++){
                if(duration[0][j]==1){
                    int a=duration[0][j];
                    int k=1;
                    while(k<i && a==1){
                        a=(duration[k][j] && a);
                        k++;
                    }
                    
                    if(k==i && a==1){
                        found=1;
                        sec=j;
                    }
                }
            
            }
            if(found==0){
                printf("Signals fail to synchronise in 5 hours\n");
            }
            else{
                printf("%02d:%02d:%02d\n",sec/3600,(sec/60)%60,sec%60);
            }
            
            
            
            /*
            int j=0;
            while(light[j]!=0){
                printf("%d ",light[j]);
                j++;
            }
            printf("\n");
            */
        }
        
        else{
            stop_signal=0;
        }
        
        memset(light,0,sizeof(light));
    }
    
    
    return 0;
}
