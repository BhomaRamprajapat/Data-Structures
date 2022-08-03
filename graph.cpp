#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INF 1e6
#define ff first
#define ss second
#define nl '\n'
#define pb push_back
using namespace std;

struct Node
{
 int parent;
 int rank;
};

void in_out_code()
{
 fast_io;
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 #endif 
}

int visited[100];
vector<pair<int,int>> adjList[101];
vector<int> adj[101];
int timer;
int desc[101],reach[101];
bool apoint[101];
vector<int> parent(100,-1);
vector<Node> Parent;

void dfs(int);
bool dfsIsCycleDirected(int);
bool dfsIsCycleInDirected(int,int);
void aPoint(int,int);
void dijsktra(int,int);
int find_rank(int);
void Union_by_Rank(int,int);
int find(int);
void Union(int,int);
bool DSU(vector<pair<int,int>>&);
bool DSU_by_Rank(vector<pair<int,int>>&);

int find_rank(int v)
{
 if(Parent[v].parent==-1)
  return v;
 return Parent[v].parent=find_rank(Parent[v].parent);
}

void Union_by_Rank(int src,int dst)
{
 if(Parent[src].rank>Parent[dst].rank)
  Parent[dst].parent=src;
 else if(Parent[src].rank<Parent[dst].rank)
  Parent[src].parent=dst;
 else
 {
  Parent[src].parent=dst;
  Parent[dst].rank+=1;
 }
}

bool DSU_by_Rank(vector<pair<int,int>> &EdgeList)
{
 for(auto edge:EdgeList)
 {
  int src=find_rank(edge.ff);
  int dst=find_rank(edge.ss);

  if(src==dst)
   return true;
  Union_by_Rank(src,dst);
 }
 return false;
}

vector<int> path;

int main()
{
 in_out_code();
 
 int v,e;
 cin>>v>>e;
 path.assign(v+1,-1);

 while(e--)
 {
  int u,v,w;
  cin>>u>>v>>w;
  adjList[u].push_back({v,w});
  adjList[v].push_back({u,w});
 }

 dijsktra(0,v);

 vector<int> ans;
 v=v-1;

 while(path[v]!=-1)
  ans.push_back(v),v=path[v];
 ans.push_back(0);
 reverse(ans.begin(),ans.end());
 for(auto x:ans) cout<<x<<" ";
 cout<<nl;
}
//-------------------------------------DFS------------------------------------------------
void dfs(int node)
{
 visited[node]=true;
 cout<<node<<" ";
 for(auto child : adj[node])
 {
  if(visited[child]==0)
   dfs(child);
 }
}


//-----------------------------DFS Cycle Detection in Directed Graph--------------------------
bool dfsIsCycleDirected(int node)
{
 visited[node]=1;
 for(auto child:adj[node])
 {
  if(visited[child]==0)
  {
   if(dfsIsCycleDirected(child))
    return true;
  }
  else if(visited[child]==1)
   return true;
 }
 visited[node]=2;
 return false;
}

bool dfsIsCycleInDirected(int node,int parent)
{
 visited[node]=true;
 for(auto child :adj[node])
 {
  if(visited[child]==0)
  {
   if(dfsIsCycleInDirected(child,node));
  }
  else if(child!=parent)
    return true;
 }
 return false;
}

void aPoint(int node,int parent)
{
 desc[node]=reach[node]=timer++;
 visited[node]=1;

 int childrens=0;

 for(auto child : adj[node])
 {
  if(child==parent) continue;
  if(visited[child]==1)
   reach[node]=min(reach[node],desc[child]);
  else
  {
   aPoint(child,node);
   childrens++;
   if(reach[child]>=desc[node] && parent!=-1)
    apoint[node]=true;
   reach[node]=min(reach[node],reach[child]);
  }
 }
 if(parent==-1 && childrens>1)
  apoint[node]=1;
}

void dijsktra(int src,int n)
{
 vector<int> dist(n,INF);
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

 q.push({0,src});
 dist[src]=0;
 path[src]=-1;

 while(!q.empty())
 {
  int node=q.top().ss;
  int cur_dist=q.top().ff;
  q.pop();
  
  for(auto child:adjList[node])
  {
   if(cur_dist+child.ss<dist[child.ff])
   {
    dist[child.ff]=cur_dist+child.ss;
    path[child.ff]=node;
    q.push({dist[child.ff],child.ff});
   }
  }
 }

 for(int i=0;i<n;i++)
  cout<<dist[i]<<" ";
 cout<<nl;
}

int find(int v)
{
 if(parent[v]==-1)
   return v;
 return find(parent[v]);
}

void Union(int src,int dst)
{
 int psrc=find(src);
 int pdst=find(dst);
 parent[src]=dst; 
}

bool DSU(vector<pair<int,int>> &EdgeList)
{
 for(auto edge:EdgeList)
 {
  int src=find(edge.ff);
  int dst=find(edge.ss);

  if(src==dst)
   return true;
  //Union(src,dst);
  parent[src]=dst;
 }
 return false;
}
