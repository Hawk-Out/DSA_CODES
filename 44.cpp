#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Edge
{
      int u,v,w;
};
    bool compareEdge(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}
class Disjoint_Set
{
    vector<int> parent,rank;
    public:
     Disjoint_Set(int n)
    {
           parent.resize(n);
           rank.resize(n,0);

       int i=0;
       while(i< n)
     {
          parent[i]=i;
         i++;
    }
    }
    int find(int x)
    {
      if (parent[x]!=x)
    {
            parent[x]=find(parent[x]);
    }
        return parent[x];
    }
    void union_Sets(int x,int y)
    {
      int root_x=find(x);
      int root_y=find(y);
        if (root_x==root_y)
       {
          return;
        }
       if(rank[root_x]<rank[root_y])
      {
           parent[root_x]=root_y;
       }
       else if(rank[root_x]>rank[root_y])
        {
           parent[root_y]=root_x;
       }
        else
      {
         parent[root_y]=root_x;
         rank[root_x]++;
        }
    }
    bool connected(int x,int y)
    {
         return find(x)==find(y);
    
    }
  };
    int main()
{
        int n;
       cin>>n;
       vector<pair<int,int>> points(n);
        int i=0;
      while(i<n){
          int x,y;
          cin>>x>>y;
            points[i]={x,y};
        i++;
    }
      vector<Edge> edges;
      i=0;
       while (i<n){
           int j=i+1;
          while (j<n){
              int dist=abs(points[i].first-points[j].first)+  abs(points[i].second-points[j].second);
                 edges.push_back({i,j,dist});
            j++;
    }
        i++;
    }
    sort(edges.begin(),edges.end(),compareEdge);
     Disjoint_Set dsu(n);
       int totalCost=0;
         int edgesUsed=0;
           i=0;

    while(i<edges.size()){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;

    if(!dsu.connected(u,v)){
        dsu.union_Sets(u,v);
          totalCost+=w;
         edgesUsed++;

     if(edgesUsed==n-1)
      {
       break;
     }
    }
       i++;
    }
      cout<<totalCost<<endl;
      return 0;
}        