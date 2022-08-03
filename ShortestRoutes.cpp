#include<bits/stdc++.h>
#define mod 1000000007
#define INF 1e17
#define ff first
#define ss second
#define ll  long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define vi vector<int>
#define vll vector<ll>
#define umap unordered_map
#define uset unordered_set
#define mp make_pair
#define nl '\n'
#define setBitsCount(x) __builtin_popcount(x) 
#define cmpstr [&](const string &s,const string &t){return s.size() < t.size();}
 
 
using namespace std;
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPowerOfTwo(int n){if(n==0) return false;return (ceil(log2(n))==floor(log2(n)));}
//bool cmp(int a,int b){if(a>b) return true;else return false;}
ll gcd(ll a,ll b){if(b==0) return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}
int min(int a,int b,int c){return min(a,min(b,c));}
int max(int a,int b,int c){return max(a,max(b,c));}
bool isPrime(int n){if(n==0 || n==1){return false;}int d,root;for(d=2,root=sqrt(n);d<=root && n%d!=0;d++);if(d>root) return true;return false;}
void debug(vi &v){for(int i=0;i<(int)v.size();i++)cout<<v[i]<<" ";cout<<nl;}
void input(vi &v){for(int i=0;i<(int)v.size();i++)cin>>v[i];}
ll setBitCount(ll n){int cnt=0;while(n>0){cnt++;n=n&(n-1);}return cnt;}
bool kthBitSetOrNot(ll n,ll k){return n&(1<<(k-1));}
 
void in_out_code()
{
 fast_io;
 #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 #endif 
}
 
void solve()
{
 int n,e;
 cin>>n>>e;
 
 vector<vector<pair<ll,ll>>> adj(n+1);
 
 while(e--)
 {
  ll u,v,w;
  cin>>u>>v>>w;
  adj[u].push_back({v,w});
 }
 
 priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
 
 q.push({0,1});
 vector<ll> dist(n+1);
 for(int i=1;i<=n;i++)
  dist[i]=INF;
 dist[1]=0;
 
 while(!q.empty())
 {
  int node=q.top().ss;
  ll cur_cost=q.top().ff;
  q.pop();
  if(dist[node]<cur_cost) continue;
  for(auto child:adj[node])
  {
   if(cur_cost+child.ss<dist[child.ff])
   {
    dist[child.ff]=cur_cost+child.ss;
    q.push({dist[child.ff],child.ff});
   }
  }
 }
 
 for(int i=1;i<=n;i++)
  cout<<dist[i]<<" ";
 cout<<nl;
}
 
int main()
{
 in_out_code();
  solve();
}