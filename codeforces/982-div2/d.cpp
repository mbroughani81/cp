#include <bits/stdc++.h>

using namespace std;

int T;
int n, m;
int a[300005];
int b[300005];
long long int p[300005];
long long int MO = 1000000007;

int findFrom(int index, long long int x) {
  int l = index;
  int r = n;
  if (a[index] > x) {
    return -1;
  }
  while(r - l > 1) {
    int mid = (l + r) / 2;
    long long int prel = 0;
    if (index > 0) {
      prel = p[index - 1];
    }
    long long int xx = p[mid] - prel;
    // cout << "pmid => " << p[mid] << "\n";
    // cout << "mid l r" << mid << " " << l << " " << r << "  => xx x " << xx << " " << x << "\n";
    if (xx <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

inline long long int check(long long int d1, long long int d2) {
  if (d1 == -1) {
    return d2;
  } else {
    return min(d1 ,d2);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    cin >> n >> m;
    long long int dp[n + 5][m + 5];
    for (int i = 0; i < n + 5; i++) {
      for (int t = 0; t < m + 5; t++) {
        dp[i][t] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[i] = a[i];
      if (i > 0) {
        p[i] += p[i - 1];
      }
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        // cal point
        dp[i][j] = dp[i][j + 1];
        // dp[i][j] can be -1!!!
        int dd = findFrom(i, b[j]);
        // dd == -1 => can not cover shit! DP will not be updated(because more j
        // => less b[j])
        if (dd != -1) {
          if (dd == n - 1) {
            dp[i][j] = (dp[i][j] + 1) % MO;
          } else {
            dp[i][j] = (dp[i][j] + dp[dd + 1][j]) % MO;
          }
        }
      }
    }
    // dd
    // for (int i = 0; i < n; i++) {
    //   cout << i << " => " << dp[i][1] << "\n";
    // }
    // for (int i = 0; i < n; i++) {
    //   cout << i << " => " << dp[i][0] << "\n";
    // }
    // cout << "gg1" << "\n";
    // cout << "gooz => " << findFrom(0, b[0]) << "\n";
    // cout << "gg2" << "\n";
    // 
    cout << dp[0][0] << "\n";
  }
}
