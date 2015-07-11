/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 14896
 * Submitted at:  2015-04-24 00:20:10
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    411
 * Problem Name:  The Movies (1)
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
#define S1(n) scanf("%lld",&n)
#define S2(m,n) scanf("%lld %lld",&m,&n)
typedef long long int LL;

LL n,m;
set<pair <LL,LL> > seats_taken;

LL seats_gap(set<pair<LL,LL> >::iterator s1,set<pair<LL,LL> >::iterator s2){
    if(s1->first==s2->first){
        LL ans=s2->second-s1->second;
        if(ans>2)
            return ans-2;
        else
            return 0;
    }
    else{
        LL ans=0;
        LL gap=m+1-s1->second;
        if(gap>2)
            ans+=gap-2;
        
        gap=s2->second-0;
        if(gap>2)
            ans+=gap-2;
        
        LL j=s2->first-s1->first;

        ans+=(m-1)*(j-1);
        
        return ans;
    }
}

int main(){
    int tc;
    scanf("%d",&tc);
    
    for(int i=1;i<=tc;i++){
        seats_taken.clear();
        S2(n,m);
        
        LL taken;
        S1(taken);
        
        vector<LL> row_taken(taken);
    
        for(LL j=0;j<taken;j++){
            S1(row_taken[j]);
        }
        
        for(LL j=0;j<taken;j++){
            LL col;
            S1(col);
            seats_taken.insert(make_pair(row_taken[j],col));
        }
        
        seats_taken.insert(make_pair(1,0));
        seats_taken.insert(make_pair(n,m+1));
        
        LL cnt=0;
        set<pair<LL,LL> >::iterator it=seats_taken.begin();
        while(it!=seats_taken.end()){
            set<pair<LL,LL> >::iterator it1=it;
            set<pair<LL,LL> >::iterator it2=it;
            ++it;
            if (it==seats_taken.end())
                break;
            else
                it2=it;
            //cout << it1->first << " " << it1->second << endl;
            //cout << it2->first << " " << it2->second << endl;
            cnt+=seats_gap(it1,it2);
        }
       
        printf("Case #%d: %lld\n",i,cnt);
        
    }
    
    return 0;
}