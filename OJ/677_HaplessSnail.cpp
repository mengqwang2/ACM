/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12951
 * Submitted at:  2015-03-06 21:10:43
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    677
 * Problem Name:  Hapless Snail
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

using namespace std;


int main()
{
    unsigned long h;
    unsigned long u;
    unsigned long d;
    int f;
    
    while (scanf("%lu %lu %lu %d",&h,&u,&d,&f)!=EOF){
        double dist=0;
        int day=0;
        double p=f/100.0;
        double climb=u;
        double actual=0;
        
        dist+=climb;
        day++;
        while (dist<h){
            dist-=d;
            day++;
            actual=climb-d;
            if(actual<0){
                break;
            }
            else{
                climb*=p;
                dist+=climb;
            }
        }
        
        if(dist>=h){
            cout << "succeeded on day " << day << endl;
        }
        else{
            cout << "failed on day " << day << endl;
        }
        
    }
    
}
