/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 11492
 * Submitted at:  2015-01-28 19:10:02
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    195
 * Problem Name:  Cellular Structure (UVa 620)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int status[100];
int pt=-1;

int isSimple(char* c,int cnt){
    if((c[0]=='A' || c[0]=='B') && cnt==0)
        return 1;
    else
        return 0;
}

int isFullGrow(char* c,int cnt){
    if(c[cnt]=='B' && c[cnt-1]=='A')
        return 1;
    else
        return 0;
}

int isMutaGen(char* c,int cnt){
    if((c[0]=='B' && c[cnt]=='A') && cnt>=2)
        return 1;
    else
        return 0;
}


void isNormal(char* c,int end){

    if(isSimple(c,end)){
        status[++pt]=1;
    }
    else if(isFullGrow(c,end)){
        status[++pt]=2;
        char subStr[end-1];
        memset(subStr,0,sizeof(subStr));
        int k=0;
        int m=-1;
        while(k<=end-2){
            subStr[++m]=c[k++];
        }
        isNormal(subStr,end-2);
    }
    else if(isMutaGen(c,end)){
        status[++pt]=3;
        char subStr[end-1];
        memset(subStr,0,sizeof(subStr));
        int k=1;
        int m=-1;
        while(k<=end-1){
            subStr[++m]=c[k++];
        }

        isNormal(subStr,end-2);
    }
    else{
        status[++pt]=-1;
    }

}


int isMut(int* st,int pt){
    for(int i=0;i<=pt;i++){
        if(st[i]==-1)
            return 1;
    }
    return 0;
    
}


int main(){
    int n=0;
    scanf("%d",&n);
    char c=getchar();
    char seq[100];
    int cnt;
    for(int i=0;i<n;i++){
        cnt=-1;
        pt=-1;
        memset(seq,0,sizeof(seq));
        memset(status,0,sizeof(status));
        while((c=getchar())!='\n'){
            seq[++cnt]=c;
        }
        
        isNormal(seq,cnt);
        
        
        if(isMut(status,pt)){
            printf("MUTANT\n");
        }
        else{
            if(status[0]==1)
                printf("SIMPLE\n");
            else if(status[0]==2)
                printf("FULLY-GROWN\n");
            else if(status[0]==3)
                printf("MUTAGENIC\n");
            else
                printf("MUTANT\n");
        }
    }
    
    
    
    return 0;
}