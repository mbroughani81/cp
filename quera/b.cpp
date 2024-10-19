#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    int result = 0;
    for (int j = 1; j * j < n; j++) {
      if (n % j != 0) {
        continue;
      }
      int cur = n / j;
      if ((cur - j) % 2 == 0) {
        result++;
      }
    }
    cout << result << "\n";
  }
}
