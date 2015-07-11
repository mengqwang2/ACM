/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12021
 * Submitted at:  2015-02-10 20:09:39
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    172
 * Problem Name:  Rough Roads (UVa 10356)
 */

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
    
int findSmallest(const vector< pair<int, int> >& a){
    int dist=500;
    int index=0;
    for(int i=0;i<a.size();i++){
        if (a[i].first<=dist){
            dist=a[i].first;
            index=i;
        }
    }
    return index;
}
    
pair<int,int> relaxation(pair<int,int> rn, const vector< pair<int, int> >& found, const vector< vector<pair<int,int> > >& adj){
    for (int i=0;i<found.size();i++){
        int node=found[i].second;
        for (int j=0;j<adj[node].size();j++){
            if(adj[node][j].first==rn.second){
                if(rn.first>adj[node][j].second+found[i].first)
                    rn.first=adj[node][j].second+found[i].first;
            }
        }
    }
    return rn;
}

vector< pair<int, int> > shortestPath(const vector< vector<pair<int,int> > > &adj,int n,int r,int st,int x){
    vector< pair<int, int> > found;
    vector< pair<int, int> > unknown(2*n);
    

    for(int i=0;i<2*n;i++){
        if (i==st*2+x)
            unknown[i]=make_pair(0,i);
        else
            unknown[i]=make_pair(100,i);
    }
    

    while(!unknown.empty()){
        int index=findSmallest(unknown);
        pair<int,int> fd=unknown[index];
        found.push_back(fd);
        unknown.erase(unknown.begin()+index);
        
        //relaxation
        for (int i=0;i<unknown.size();i++){
            pair<int,int> new_rn=relaxation(unknown[i],found,adj);
            unknown[i].first=new_rn.first;
            unknown[i].second=new_rn.second;
        }
        
    }
    return found;
    
    
}


int main()
{
    int n,r;
    int from;
    int to;
    int len;
    int setNo=1;
    while (scanf("%d %d",&n,&r)!=EOF){
        vector< vector<pair<int,int> > > adj(2*n);
        vector< pair<int, int> > arr;
        for (int i=0;i<r;i++){
            scanf("%d",&from);
            scanf("%d",&to);
            scanf("%d",&len);
            adj[2*from].push_back(make_pair(2*to+1,len));
            adj[2*from+1].push_back(make_pair(2*to,len));
            adj[2*to].push_back(make_pair(2*from+1,len));
            adj[2*to+1].push_back(make_pair(2*from,len));
            
        }
        arr=shortestPath(adj,n,r,0,0);
        for (int i=0;i<arr.size();i++){
            if(arr[i].second==2*n-2){
                if (arr[i].first<100)
                    printf("Set #%d\n%d\n",setNo,arr[i].first);
                else
                    printf("Set #%d\n%s\n",setNo,"?");
            }
        }
        
        setNo++;
        
        
    }
    
    return 0;
}