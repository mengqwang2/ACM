/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 12787
 * Submitted at:  2015-03-02 12:50:19
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    207
 * Problem Name:  Minimum Effort
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

class Comparator
{
public:
    int operator() ( const pair<int,float>& p1, const pair<int,float> &p2)
    {
        return p1.second>p2.second;
    }
};


int shortestPath(const vector< vector<pair<int,int> > > &adj, int n,int st,int dest, vector<int> &path){
    vector<int> d(n);
    vector<int> parent(n);
    
    for(int i=0;i<n;i++)
    {
        d[i] = 9999;
        parent[i] = -1;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int> >, Comparator> Q;
    d[st] = 0;
    Q.push(make_pair(st,d[st]));
    
    while(!Q.empty())
    {
        int u = Q.top().first;
        if(u==dest)
            break;
        Q.pop();
        for(int i=0; i < adj[u].size(); i++)
        {
            int v= adj[u][i].first;
            float w = adj[u][i].second;
            if(d[v] > d[u]+w)
            {
                d[v] = d[u]+w;
                parent[v] = u;
                Q.push(make_pair(v,d[v]));
            }
        }
    }
    
    path.clear();
    int p = dest;
    path.push_back(dest);
    while(p!=st)
    {
        p = parent[p];
        path.push_back(p);
    }
    
    return d[dest];
}



string findName(map<string,int> places,int a){
    for(map <string,int>::iterator it=places.begin();it!=places.end();++it){
        if(it->second==a)
            return it->first;
    }
}


int main()
{
    int n=0;
    string line;
    int e;
    while(scanf("%d\n",&n)!=EOF){
        map <string,int> places;
        vector < vector<pair<int, int> > > adj(n);
        for (int i=0;i<n;i++){
            getline(cin,line);
            places[line]=i;
            
        }
        scanf("%d\n",&e);
        for (int i=0;i<e;i++){
            getline(cin,line);
            pair<int,int> position;
            
            
            bool place1=false;
            bool place2=false;
            int f=0;
            for (int j=0;j<line.length();j++){
                if(line[j]==':'){
                    string s1(line,0,j);
                    position.first=places[s1];
                    place1=true;
                    f=j+1;
                }
                else if (place1 && !place2){
                    if(line[j]==' '){
                        string s2(line,f,j-f);
                        if(places.find(s2)!=places.end()){
                            position.second=places[s2];
                            place2=true;
                        }
                    }
                     
                }
                else if (place1 && place2){
                    string s3(line,j,line.length()-j);
                    //cout << s3 << endl;
                    stringstream ss(s3);
                    char a[100];
                    int q=0;
                    while(ss >> a){
                        if (q==0)
                            adj[position.first].push_back(make_pair(position.second,atoi(a)));
                        else
                            adj[position.second].push_back(make_pair(position.first,atoi(a)));
                        q++;
                    }
                    break;
                }
                
            }
            
        }
        
 
        int from=places["office"];
        int to=places["hall"];
        vector<int> path;
        vector<int> finalPath;
        int result1=shortestPath(adj,n,from,to,path);
        for(int i=(int)path.size()-1;i>=0;i--){
            finalPath.push_back(path[i]);
        }
        
        int result2=shortestPath(adj,n,to,from,path);
        
        for(int i=(int)path.size()-2;i>=0;i--){
            finalPath.push_back(path[i]);
        }
        
        cout << result1+result2 << endl;
        
        for(int i=0;i<finalPath.size()-1;i++){
            cout << findName(places,finalPath[i]) << " -> ";
        }
        cout << findName(places,finalPath[finalPath.size()-1]) << endl;
        
        cout << endl;
        
    }
    
    return 0;
}
