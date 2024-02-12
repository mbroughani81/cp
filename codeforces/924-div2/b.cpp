#include <algorithm>
#include <iostream>

using namespace std;

int T;
int n;
int a[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> a[t];
    }
    sort(a, a + n);
    int nn = unique(a, a + n) - a;

    // cout << "nn => " << nn << "\n";
    // cout << "AN\n";
    int result = 1;
    int ptr = 0;
    for (int t = 0; t < nn; t++) {
      int x = a[t] + 1;
      while (x - a[ptr] > n) {
        ptr++;
      }
      // cout << "ptr => " << ptr << "\n";
      result = max(result, t - ptr + 1);
    }
    cout << result << "\n";
  }
}
