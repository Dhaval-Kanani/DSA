#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void
preprocess(vector<pair<int, int>> &M, vector<vector<int>> &g, int r, int c) {
    queue<pair<pair<int, int>, int>> q;
    for (auto m : M) {
        q.push(make_pair(m, 0));
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int time = p.second;

        for (int k = 0; k < 4; k++) {
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];
            if (dx <= r && dy <= c)
                if (g[dx][dy] == 0 &&
                    (arr[dx][dy] == '.' || arr[dx][dy] == 'A')) {
                    q.push({{dx, dy}, time + 1});
                    g[dx][dy] = time + 1;
                }
        }
    }
}

int
main() {

    int visited[1001][1001] = {0};
    int pre[1001][1001] = {-1};
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> g;
    vector<pair<int, int>> M;
    char C[4] = {'D', 'R', 'U', 'L'};
    int r = 0, c = 0;
    int sx = 0, sy = 0;
    cin >> r >> c;
    g.resize(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
                sx = i, sy = j;
            if (arr[i][j] == 'M')
                M.push_back({i, j});
        }

    preprocess(M, g, r, c);

    // for(auto x:g)
    // {
    //  cout<<endl;
    //  for(auto y: x)
    //  cout<<y<<" ";
    // }cout<<endl;

    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = 1;
    bool check = false;
    int timer = 0, ex = 0, ey = 0;
    while (q.size()) {
        pair<pair<int, int>, int> node = q.front();
        int i = node.first.first;
        int j = node.first.second;
        int t = node.second;
        q.pop();

        if (i <= 1 || i >= r || j <= 1 || j >= c) {
            check = true;
            ex = i, ey = j;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];

            if (dx <= r && dy <= c)
                if (visited[dx][dy] != 1 &&
                    (arr[dx][dy] == '.' && arr[dx][dy] != 'M') &&
                    (g[dx][dy] == 0 || g[dx][dy] > t + 1)) {
                    // cout<<dx<<" "<<dy<<endl;
                    q.push({{dx, dy}, t + 1});

                    pre[dx][dy] = k;
                    visited[dx][dy] = 1;
                }
        }
        timer += 1;
    }

    string s = "";
    if (check) {
        while (ex != sx || ey != sy) {
            int k = pre[ex][ey];
            s.push_back(C[k]);
            ex += dir[k][0] * -1, ey += dir[k][1] * -1;
        }
        reverse(s.begin(), s.end());
        cout << "YES" << endl;
        cout << s.size() << endl;
        cout << s << endl;
    } else
        cout << "NO";
    return 0;
}