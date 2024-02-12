#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> divisors(long long n) {
  vector<long long> result;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i * i == n) {
        result.push_back(i);
      } else {
        result.push_back(i);
        result.push_back(n / i);
      }
    }
  }
  return result;
}

vector<long long> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long n, x;
    cin >> n >> x;
    result.clear();
    vector<long long> d_1 = divisors(n - x);
    vector<long long> d_2 = divisors(n + x - 2);
    for (long long l : d_1) {
      int k = (n - x) / l + 1;
      if (l % 2 == 0 && x <= k) {
        result.push_back((n - x) / l);
      }
    }
    for (long long l : d_2) {
      int k = (n + x - 2) / l + 1;
      if (l % 2 == 0 && x <= k) {
        result.push_back((n + x - 2) / l);
      }
    }
    // for (long long dd : d_1) {
    //   cout << "ddd1 => " << dd << "\n";
    // }
    // for (long long dd : d_2) {
    //   cout << "ddd2 => " << dd << "\n";
    // }

    sort(result.begin(), result.end());
    vector<long long>::iterator it = unique(result.begin(), result.end());
    result.resize(distance(result.begin(), it));
    // for (long long gg : result) {
    //   cout << "ggg => " << gg + 1 << "\n";
    // }
    cout << result.size() << "\n";
  }
}
