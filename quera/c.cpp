#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long int x;
    cin >> x;
    long long result = 1;
    while (x != 1) {
      if (x % 2 != 1) {
        result *= 2;
      } else {
        break;
      }
      x /= 2;
    }
    cout << result << "\n";
  }
}
