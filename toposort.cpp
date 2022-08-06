#include<iostream>
#include<stack>
#include<vector>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


using namespace std;

void in_out_code()
{
 fast_io;
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 #endif 
}

bool dfs(int node,vector<int> &visited,vector<vector<int>> &adj,stack<int> &ans)
{
 visited[node]=1;

 for(auto child:adj[node])
 {
  if(visited[child]==0)
  {
   if(dfs(child,visited,adj,ans))
   	return true;
  }
  else if(visited[child]==1)
   return true;
 }
 ans.push(node);
 visited[node]=2;
 return false;
}

void toposort(int v,vector<vector<int>> &adj)
{
 vector<int> visited(v,0);
 stack<int> stack;

 for(int i=0;i<v;i++)
  if(visited[i]==0)
   if(dfs(i,visited,adj,stack))
   {
    cout<<"Graph is Cyclic Topological order not possible";
    return;
   }

 cout<<"Topological Sort is : ";
 while(!stack.empty())
  cout<<stack.top()<<" ",stack.pop();
}

int main()
{
 in_out_code();

 int v,e;
 cin>>v>>e;

 vector<vector<int>> adj(v);

 for(int i=0;i<e;i++)
 {
  int u,v;
  cin>>u>>v;
  adj[u].push_back(v);
 }

 toposort(v,adj);
}