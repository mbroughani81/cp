#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005], ginv[200005];
vector<int> v1;
queue<int> qin, qout;
int N, M;
int status[200005];
set<int> ss;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    ginv[y].push_back(x);
  }
  // bfs
  qin.push(0);
  qout.push(0);
  status[0] = -1;
  int result;
  for (int i = 0; i < N; i++) {
    ss.clear();
    v1.clear();

    // cout << "II" << "\n";
    int cnt = qin.size();
    for (int t = 0; t < cnt; t++) {
      int x = qin.front();
      // cout << "in => " << x << "\n";
      qin.pop();
      // add the inwards
      for (auto y : ginv[x]) {
        if (status[y] == 0) {
          qin.push(y);
          ss.insert(y);
          status[y] = 1;
          v1.push_back(y);
        }
        if (status [y] == 2) {
          cout << 2 * i + 1 << "\n";
          return 0;
        }
      }
    }
    for (auto x : v1) {
      status[x] = 0;
    }

    cnt = qout.size();
    for (int t = 0; t < cnt; t++) {
      int x = qout.front();
      // cout << "out => " << x << "\n";
      qout.pop();
      // add the outwards
      for (auto y : g[x]) {
        if (status[y] == 0) {
          qout.push(y);
          status[y] = 2;
          if (ss.count(y) == 1) {
            cout << 2 * i + 2 << "\n";
            return 0;
          }
        }
      }
    }

    for (auto x : v1) {
      status[x] = 1;
    }
  }
  cout << "-1\n";
}
