#include <bits/stdc++.h>

using namespace std;

int N;
int A[200005], B[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  B[0] = A[0];
  for (int i = 1; i < N; i++) {
    cin >> B[i];
  }
  sort(B, B + N);

  int result = A[0];
  if (B[0] < A[0]) {
    cout << "-1\n";
    return 0;
  }

  // for (int i = 0; i < N; i++) {
  //   cout << A[i] << " ";
  // }
  // cout << "gg\n";
  // for (int i = 0; i < N; i++) {
  //   cout << B[i] << " ";
  // }
  // cout << "gg\n";

  int ptr = 0;
  for (int i = 0; i < N; i++) {
    while (ptr + 1 < N && A[ptr + 1] <= B[i]) {
      ptr++;
    }
    // cout << i << " " << ptr << "gg\n";
    // two cases
    if (ptr >= i) {
      continue;
    } else {
      result = A[ptr + 1];
    }
  }

  // cout << "result => " << result << "\n";
  // check if result is ok
  B[0] = result;
  sort(B, B + N);

  ptr = 0;
  for (int i = 0; i < N; i++) {
    while (ptr + 1 < N && A[ptr + 1] <= B[i]) {
      ptr++;
    }
    // cout << i << " " << ptr << "gg\n";
    // two cases
    if (ptr >= i) {
      continue;
    } else {
      cout << "-1\n";
      return 0;
    }
  }

  cout << result << "\n";
}
