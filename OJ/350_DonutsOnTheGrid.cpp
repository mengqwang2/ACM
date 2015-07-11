/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 17235
 * Submitted at:  2015-05-13 21:17:07
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    350
 * Problem Name:  DonutsOnTheGridEasy
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
#include <utility>
#include <bitset>
#include <cstring>
#include <typeinfo>
#include <climits>
#include <numeric>
#include <cmath>

using namespace std;


int memo[51][51][51][51];


bool isDonut(int x1, int y1, int x2, int y2,vector<string> & donut) {
    for (int x=x1;x<x2;x++)
        if (donut[x][y1]!='0')
            return false;
    for (int x=x1;x<x2;x++)
        if (donut[x][y2-1]!='0')
            return false;
    for (int y=y1;y<y2;y++)
        if (donut[x1][y]!= '0')
            return false;
    for (int y=y1;y<y2;y++)
        if (donut[x2-1][y]!='0')
            return false;
    return true;
}

int findDonut(int x1, int y1, int x2, int y2,vector<string> & donut) {
    if (memo[x1][y1][x2][y2]!=-1)
        return memo[x1][y1][x2][y2];
    if (x2-x1<3)
        return 0;
    if (y2-y1<3)
        return 0;
    
    if (isDonut(x1,y1,x2,y2,donut))
        return memo[x1][y1][x2][y2]=findDonut(x1+1,y1+1,x2-1,y2-1,donut)+1;
    int result=0;
    result = max(result,findDonut(x1 + 1, y1, x2, y2,donut));
    result = max(result,findDonut(x1, y1 + 1, x2, y2,donut));
    result = max(result,findDonut(x1, y1, x2 - 1, y2,donut));
    result = max(result,findDonut(x1, y1, x2, y2 - 1,donut));
    return memo[x1][y1][x2][y2]=result;
}



int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        int row,col;
        scanf("%d",&row);
        string line;
        
        vector<string> donut(row);
        getline(cin,line);
        
        for(int j=0;j<row;j++){
            getline(cin,line);
            donut[j]=line;
            //cout << line << endl;
            
        }
        
        col=line.length();
        //cout << col << endl;
        
        for (int i=0;i<51;i++){
            for (int j=0;j<51;j++){
                for (int k=0;k<51;k++){
                    for (int l=0;l<51;l++){
                        memo[i][j][k][l]=-1;
                    }
                }
            }
        }
              
        
      printf("Case #%d: %d\n",t,findDonut(0,0,row,col,donut));
        
    
    }
    
    
    
        
    return 0;
}