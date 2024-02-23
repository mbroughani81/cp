#include <algorithm>
#include <iostream>

using namespace std;

int T;
int a[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n / 2; i++) {
      a[2 * i] = i + 1;
      a[2 * i + 1] = n - i;
    }
    if (n % 2 == 1) {
      a[n - 1] = n / 2 + 1;
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    // return 0;
    // cout << "\n";
    // for (int i = 0; i < n - 1; i++) {
    //   for (int j = 0; j < n - 1; j++) {
    //     if (i == j)
    //       continue;
    //     if (a[j] % a[i] == 0 && a[j + 1] % a[i + 1] == 0) {
    //       cout << i << " " << j << "\n";
    //     }
    //   }
    // }
  }
}
