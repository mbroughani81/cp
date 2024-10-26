#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    int n;
    cin >> n;
    int resx, resy;
    int x, y;
    cin >> resx >> resy;
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      resx = max(resx, x);
      resy = max(resy, y);
    }
    cout << 2 * (resx + resy) << "\n";
  }
}
