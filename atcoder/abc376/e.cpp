#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[200005];
int N, K;
int A[200005], B[200005];
multiset<int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int gg = 0; gg < T; gg++) {
    cin >> N >> K;
    st.clear();
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      p[i].first = A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
      p[i].second = B[i];
    }
    sort(p, p + N);

    long long int result = 1e18;

    long long int sum = 0;
    for (int t = 0; t < K - 1; t++) {
      sum += p[t].second;
      st.insert(-p[t].second);
    }
    for (int i = K - 1; i < N; i++) {
      // keep smallest k ones
      result = min(result, (sum + p[i].second) * p[i].first);
      // update sum
      int cur = -*st.begin();
      // cout << "cc => " << cur << "\n";
      if (p[i].second < cur) {
        // cout << "cur => " << cur << " " << p[i].second << "\n";
        st.erase(st.find(-cur));
        st.insert(-p[i].second);
        sum -= cur;
        sum += p[i].second;
      }
      // cout << result << "Ggg \n";
    }
    cout << result << "\n";
  }
}
