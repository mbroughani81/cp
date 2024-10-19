#include <bits/stdc++.h>

using namespace std;

int N, C, T[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  int result = 1;
  int last = T[0];
  for (int i = 1; i < N; i++) {
    if (T[i] - last >= C) {
      last = T[i];
      result++;
    }
  }
  cout << result << "\n";
}
