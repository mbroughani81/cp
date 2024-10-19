#include <bits/stdc++.h>

using namespace std;

long long int a[100005];
long long int g[100005];
multiset<long long int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int nn, ww;
    cin >> nn >> ww;

    st.clear();
    for (int t = 0; t < nn; t++) {
      cin >> a[t];
      st.insert(-a[t]);
    }
    for (int t = 0; t < ww; t++) {
      cin >> g[t];
    }
    // for (int t = 0; t < ww; t++) {
    //   long long result = 0; 
    //   for (int i = 0; i < nn; i++) {
    //     result += (a[i] / g[t]) * g[t];
    //     a[i]= a[i] % g[t];
    //   }
    //   cout << result << " ";
    // }
    for (int t = 0; t < ww; t++) {
      long long int result = 0;
      while (true) {
        long long int cur = -*st.begin();
        // cout << "cur =>" << cur << "\n";
        if (cur < g[t]) {
          break;
        }
        result += (cur / g[t]) * g[t];
        st.erase(st.lower_bound(-cur));
        // st.extract(-cur);
        st.insert(-(cur % g[t]));
      }
      cout << result << " ";
    }
    cout << "\n";
  }
}
