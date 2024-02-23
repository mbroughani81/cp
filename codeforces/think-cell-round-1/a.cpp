#include <algorithm>
#include <iostream>

using namespace std;

int T;
int a[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(a, a + 2 * n);
    int result = 0;
    for (int i = 0; i < n; i++) {
      result += a[2 * i];
    }
    cout << result << "\n";
  }
}
