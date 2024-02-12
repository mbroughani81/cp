#include <iostream>
#include <type_traits>

using namespace std;

int T;

bool same(int a, int b, int x, int y) {
  if (a > b) {
    int t = a;
    a = b;
    b = t;
  }
  if (x > y) {
    int t = x;
    x = y;
    y = t;
  }
  return (a != x) || (b != y);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;
    bool result = false;
    if (a % 2 == 0) {
      result = result || same(a, b, a / 2, b * 2);
    }
    if (b % 2 == 0) {
      result = result || same(a, b, a * 2, b / 2);
    }
    if (result) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
