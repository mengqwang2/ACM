/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 15676
 * Submitted at:  2015-05-02 16:34:32
 *
 * User ID:       66
 * Username:      52209388
 * Problem ID:    508
 * Problem Name:  DNA Search
 */
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include <math.h>
#include<iomanip>
#include<map>
#define N 100005
using namespace std;
char s[N], pattern[N];
int sa[N], t1[N], t2[N], c[N], n, pn;
void build_sa(int m){
 int i, *x = t1, *y = t2;
 for(i=0; i<m; i++) c[i]=0;
 for(i=0; i<n; i++) c[x[i]=s[i]]++;  
 for(i=1; i<m; i++) c[i]+=c[i-1]; 
 for(i=n-1; i>=0; i--) sa[--c[x[i]]] = i;
 for(int k=1; k<n; k<<=1){
  int p=0;
  for(i=n-k; i<n; i++) y[p++]=i;
  for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
  for(i=0; i<m; i++) c[i]=0;
  for(i=0; i<n; i++) c[x[y[i]]]++;  
  for(i=1; i<m; i++) c[i]+=c[i-1]; 
  for(i=n-1; i>=0; i--) sa[--c[x[y[i]]]] = y[i];
  swap(x,y);
  p=1; x[sa[0]]=0;
  for(i=1;i<n;i++)
   x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
  if(p>=n) break;
  m=p;
 }
}
int cmp(int p){
 return strncmp(pattern, s+sa[p], pn); 
}
int find(){
 int l=1, r=n,m,MIN;
 while(l<r){
  m=(l+r)/2;
  if(cmp(m)>0) l=m+1;
  else r=m;
 }
 MIN=l;r=n;
 while(l<r){
  m = (l+r)/2;
  if (cmp(m)<0) r = m;
  else l = m+1;
 }
 return r-MIN;
}
int main(){
 int t,K;
 scanf("%d", &t);
 for(int i=1; i<=t; i++){  
  scanf("%s", s);
  n=strlen(s)+1;
  build_sa('T'+1);
  printf("Case #%d\n", i);
  scanf("%d", &K);
  for(int j=0; j<K; j++){
   scanf("%s", pattern);
   pn=strlen(pattern);
   printf("%d\n", find());
  }
 }  
}