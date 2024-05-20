#include <bits/stdc++.h>
using namespace std;

char arr[1001][1001];

int
main() {
    int visited[1001][1001] = {0};
    int pre[1001][1001] = {-1};
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char C[4] = {'D', 'R', 'U', 'L'};
    int r = 0, c = 0;
    int sx = 0, sy = 0, ex = 0, ey = 0;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
                sx = i, sy = j;
            if (arr[i][j] == 'B')
                ex = i, ey = j;
        }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    bool check = false;
    while (q.size()) {
        pair<int, int> node = q.front();
        q.pop();

        if (arr[node.first][node.second] == 'B') {
            check = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int dx = node.first + dir[k][0];
            int dy = node.second + dir[k][1];

            if (visited[dx][dy] != 1 &&
                (arr[dx][dy] == '.' || arr[dx][dy] == 'B')) {
                q.push({dx, dy});
                pre[dx][dy] = k;
                visited[dx][dy] = 1;
            }
        }
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