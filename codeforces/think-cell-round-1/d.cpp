#include <iostream>
#include <string.h>

using namespace std;

int T;
int c[200005];
long long cnt[200005];
long long bond[200005];

long long count(long long c, int t) {
  long long result = 0;
  result += 1LL * t * (t - 1) / 2 * (c / t) * (c / t);
  long long m = c % t;
  result += m * (m - 1) / 2 + m * (t - 1) * (c / t);
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    int n;
    long long b, x;
    cin >> n >> b >> x;
    memset(cnt, 0, sizeof(cnt));
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      cnt[c[i]]++;
      mx = max(mx, c[i]);
    }
    long long result = 0;
    for (int i = 1; i <= mx; i++) {
      bond[i] = bond[i - 1];
      if (cnt[i] == 0) {
        continue;
      }
      for (int t = 1; t <= i; t++) {
        bond[t] += cnt[i] * count(i, t) * b;
      }
    }
    for (int i = 1; i <= mx; i++) {
      result = max(result, bond[i] - 1LL * (i - 1) * x);
    }
    cout << result << "\n";
  }
}
