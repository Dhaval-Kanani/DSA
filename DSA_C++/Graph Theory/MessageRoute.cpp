#include <bits/stdc++.h>
using namespace std;

int main()
{

 int n, m;
 cin >> n >> m;
 vector<int> adj[n + 1];
 for (int i = 1; i <= m; i++)
 {
  int u, v;
  cin >> u >> v;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }

 vector<int> vis(n + 1);
 vector<int> pre(n + 1);
 queue<int> q;
 q.push(1);
 vis[1] = 1;
 bool check = false;

 while (q.size())
 {
  int u = q.front();
  q.pop();

  if (u == n)
  {
   check = true;
   break;
  }

  for (auto x : adj[u])
  {
   if (vis[x] != 1)
   {
    q.push(x);
    pre[x] = u;
    vis[x] = 1;
   }
  }
 }

 vector<int> ans;
 if (check)
 {
  int x = n;
  ans.push_back(n);
  while (x != 1)
  {
   ans.push_back(pre[x]);
   x = pre[x];
  }
  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; i--)
   cout << ans[i] << " ";
  cout << endl;
 }
 else
  cout << "IMPOSSIBLE" << endl;

 return 0;
}