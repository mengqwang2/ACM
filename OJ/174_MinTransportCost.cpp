/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12080
 * Submitted at:  2015-02-11 15:38:13
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    174
 * Problem Name:  Minimum Transport Cost (UVa 523)
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

using namespace std;

  
int findSmallest(const vector< tuple<int, int, int> >& a){
    int dist=9999;
    int index=0;
    for(int i=0;i<a.size();i++){
        if (get<1>(a[i])<=dist){
            dist=get<1>(a[i]);
            index=i;
        }
    }
    return index;
}
    
tuple<int,int,int> relaxation(tuple<int,int,int> rn, const vector< tuple<int, int, int> >& found, const vector< vector<pair<int,int> > >& adj,const vector<int> &tax, int st){
    tuple<int,int,int> x;
    for (int i=0;i<found.size();i++){
        int node=get<0>(found[i]);
        for (int j=0;j<adj[node].size();j++){
            if(adj[node][j].first==get<0>(rn)){
                if(get<1>(rn)>adj[node][j].second+get<1>(found[i])+tax[node]){
                    if (node==st)
                        rn=make_tuple(get<0>(rn), adj[node][j].second+get<1>(found[i]),node);
                    else
                        rn=make_tuple(get<0>(rn), adj[node][j].second+get<1>(found[i])+tax[node],node);
                    
                }
                    
            }
        }
    }
    return rn;
}

vector< tuple<int, int, int> > shortestPath(const vector< vector<pair<int,int> > > &adj,const vector<int> &tax, int n,int st){
    vector< tuple<int, int, int> > found;
    vector< tuple<int, int, int> > unknown(n);
    

    for(int i=0;i<n;i++){
        if (i==st){
            unknown[i]=make_tuple(i,0,i);
        }
            
        else{
            unknown[i]=make_tuple(i,9999,-1);
        }
            
    }

    while(!unknown.empty()){
        int index=findSmallest(unknown);
        tuple<int,int,int> fd=unknown[index];
        found.push_back(fd);
        unknown.erase(unknown.begin()+index);
        
        //relaxation
        for (int i=0;i<unknown.size();i++){
            tuple<int,int,int> new_rn=relaxation(unknown[i],found,adj,tax,st);
            unknown[i]=make_tuple(get<0>(new_rn),get<1>(new_rn),get<2>(new_rn));
        }
        
    }
    return found;
    
}

int findParent(vector<tuple<int, int, int> > result,int a){
    for(int j=0;j<result.size();j++){
        if(get<0>(result[j])==a){
            return get<2>(result[j]);
        }
    }
}


int findDist(vector<tuple<int, int, int> > result,int a){
    for(int j=0;j<result.size();j++){
        if(get<0>(result[j])==a){
            return get<1>(result[j]);
        }
    }
}


int main()
{
    int m;
    char delimiter[5]=" \n";
    scanf("%d",&m);
    char line[1000];
    cin.getline(line,1000);
    cin.getline(line,1000);
    for (int tc=0;tc<m;tc++){
        vector <vector <pair<int, int> > > adj;
        if(tc>0)
            printf("\n");
        
        int row=0;
        int col=0;
        
        vector <int> tax;
        
        
        cin.getline(line,1000);

        vector <pair<int, int> > a;
        adj.push_back(a);
        char *ptr;
        ptr=strtok(line,delimiter);
            
        while(ptr){
            if(atoi(ptr)!=-1 && atoi(ptr)!=0)
               adj[row].push_back(make_pair(col,atoi(ptr)));
            ptr=strtok(NULL,delimiter);
            col++;
                    
        }
        
        
        for (row=1;row<col;row++){
            int j=0;
            cin.getline(line,1000);
            
            vector <pair<int, int> > a;
            adj.push_back(a);
            ptr=strtok(line,delimiter);
            
            while(ptr){
                if(atoi(ptr)!=-1 && atoi(ptr)!=0)
                    adj[row].push_back(make_pair(j,atoi(ptr)));
                ptr=strtok(NULL,delimiter);
                j++;
            }
        }
        

        cin.getline(line,1000);
        ptr=strtok(line,delimiter);
        
        while(ptr){
            tax.push_back(atoi(ptr));
            ptr=strtok(NULL,delimiter);
            
        }
        
        int p=0;
        
        while(cin.getline(line,1000) && (line[0]>='0' && line[0]<='9')){
            if (p!=0)
                printf("\n");
            int i=0;
            int from,to;
            ptr=strtok(line,delimiter);
            
            while(ptr){
                if (i==0)
                    from=atoi(ptr);
                else
                    to=atoi(ptr);
                ptr=strtok(NULL,delimiter);
                i++;
            }
            
            vector<tuple<int, int, int> > result= shortestPath(adj,tax,col,from-1);
            printf("From %d to %d :\n",from,to);
            
            //backtracing
            stack<int> par;
            int k=to-1;
            while(k!=from-1){
                par.push(k);
                k=findParent(result,k);
            }
            par.push(k);
            
            printf("Path: ");
            int y=0;
            while(!par.empty()){
                if (y==0)
                    printf("%d",par.top()+1);
                else
                    printf("-->%d",par.top()+1);
                par.pop();
                y++;
            }
            printf("\n");
         
            printf("Total cost : %d\n",findDist(result,to-1));
            
            //printf("\n");
            p++;
        }
        
        
    }
    return 0;
}

