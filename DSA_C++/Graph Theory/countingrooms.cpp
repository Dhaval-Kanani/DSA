#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int visited[1001][1001];
int ans = 0, r, c;

bool check(int x, int y)
{
 if (x < 1 || x > r || y < 1 || y > c)
  return false;
 if (arr[x][y] == '#')
  return false;
 if (visited[x][y] == 1)
  return false;
 return true;
}

void dfs(int x, int y)
{
 visited[x][y] = 1;
 if (check(x - 1, y))
  dfs(x - 1, y);
 if (check(x, y - 1))
  dfs(x, y - 1);
 if (check(x + 1, y))
  dfs(x + 1, y);
 if (check(x, y + 1))
  dfs(x, y + 1);
}

int main()
{
 cin >> r >> c;
 for (int i = 1; i <= r; i++)
  for (int j = 1; j <= c; j++)
   cin >> arr[i][j];
 for (int i = 1; i <= r; i++)
 {
  for (int j = 1; j <= c; j++)
  {
   if (visited[i][j] == 0 && arr[i][j] == '.')
   {
    ans++;
    dfs(i, j);
   }
  }
 }
 cout << ans;
}