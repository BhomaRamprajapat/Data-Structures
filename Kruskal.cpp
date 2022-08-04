 #include<bits/stdc++.h>
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

struct Node
{
 int parent;
 int rank;
};

struct Edge
{
 int u,v;
 int w;
};

bool cmp(Edge a,Edge b)
{
 return a.w<b.w;
}

vector<Node> p;
vector<Edge> Mst;

void Union(int src,int dst)
{
 if(p[src].rank>p[dst].rank)
  p[dst].parent=src;
 else if(p[src].rank<p[dst].rank)
  p[src].parent=dst;
 else
  p[src].parent=dst,p[dst].rank++;
}

int find(int v)
{
 if(p[v].parent==-1)
   return v;
 return p[v].parent=find(p[v].parent); // path compression
} 

void Kruskal(vector<Edge> &EdgeList,int n)
{
 sort(EdgeList.begin(),EdgeList.end(),cmp);

 int cnt=0;
 
 for(auto edge:EdgeList)
 {
  int src=find(edge.u);
  int dst=find(edge.v);

  if(src==dst) continue;
  
  Union(src,dst);
  cnt++;
  Mst.push_back(edge);
  cout<<edge.u<<"->"<<edge.v<<" : "<<edge.w<<endl;
  if(cnt==n-1) break;
 }
}

int main()
{
 in_out_code();

 int v,e;
 cin>>v>>e;
 
 vector<Edge> EdgeList;

 p.resize(v+1);

 for(int i=0;i<=v;i++)
 {
  p[i].rank=0;
  p[i].parent=-1;
 }

 while(e--)
 {
  Edge tmp;
  cin>>tmp.u>>tmp.v>>tmp.w;
  EdgeList.push_back(tmp);
 }
 
 Kruskal(EdgeList,v);
}
  