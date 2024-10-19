#include <bits/stdc++.h>

using namespace std;

int N, Q, T;
string H;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> Q;
  int L, R;
  L = 1;
  R = 2;
  int result = 0;
  for (int i = 0; i < Q; i++) {
    cin >> H >> T;
    int x, y;
    if (H == "L") {
      x = L;
      y = R;
      if (L == T) {
        continue;
      }
    } else {
      x = R;
      y = L;
      if (R == T) {
        continue;
      }
    }
    // go from x to T, without passing y
    if (x < y) {
      if (T > x && T < y) {
        result += T - x;
      } else {
        if (x > T) {
          result += x - T;
        } else {
          result += x + (N - T);
        }
      }
    } else {
      if (T < x && T > y) {
        result += x - T;
      } else {
        if (T > x) {
          result += T - x;
        } else {
          result += T + (N - x);
        }
      }
    }

    if (H == "L") {
      L = T;
    } else {
      R = T;
    }
    // cout << "RRR => " << result << "\n";
  }
  cout << result << "\n";
}
