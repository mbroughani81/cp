#include <bits/stdc++.h>

using namespace std;

int T;
vector<pair<long long int, long long int>> st;
map<long long int, int> mp;
map<int, long long int> mp_inv;
vector<int> g[600005];
bool visited[600005];

long long int dfs(int id) {
  long long int result = mp_inv[id];
  // cout << "id =>  " << id << "\n";
  // cout << "RRR" << result << "\n";
  visited[id] = true;
  for (auto x : g[id]) {
    if (!visited[x]) {
      result = max(result, dfs(x));
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      long long int x;
      cin >> x;
      long long int ss1 = x + i - 1;
      long long int ss2 = x + i - 1 + i - 1;
      st.push_back(make_pair(ss1, ss2));
    }
    // hash this shit
    int id = 0;
    for (auto x : st) {
      if (mp.count(x.first) == 0) {
        mp_inv[id] = x.first;
        mp[x.first] = id++;
      }
      if (mp.count(x.second) == 0) {
        mp_inv[id] = x.second;
        mp[x.second] = id++;
      }
    }

    // create the graph
    for (auto x : st) {
      int x1, x2;
      x1 = mp[x.first];
      x2 = mp[x.second];

      // cout << "x1 x2 => " << x1 << " " << x2 << "\n";
      g[x1].push_back(x2);
    }
    // dfs
    if (mp.count(n) == 0) {
      cout << n << "\n";
    } else {
      cout << dfs(mp[n]) << "\n";
    }

    // clear
    for (int i = 0; i < id; i++) {
      g[i].clear();
      visited[i] = false;
    }
    mp.clear();
    mp_inv.clear();
    st.clear();
  }
}
