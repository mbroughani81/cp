#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int a[2005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    cin >> n;
    int result = n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      int c1 = i, c2 = 0;
      for (int t1 = i + 1; t1 < n; t1++) {
        if (a[t1] > a[i]) {
          c2++;
        }
      }
      // cout << i << " " << " " << c1 << " " << c2 << "\n";
      result = min(result, c1 + c2);
    }
    cout << result << "\n";
  }
}
