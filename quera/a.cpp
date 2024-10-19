#include <bits/stdc++.h>

using namespace std;

int T;
string s[50];
int cnt[30];
int cnt_cur[30];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    for (int tt = 'a'; tt <= 'z'; tt++) {
      cnt[tt - 'a'] = 0;
    }
    for (int t = 0; t < n; t++) {
      cin >> s[t];
      for (int tt = 'a'; tt <= 'z'; tt++) {
        cnt_cur[tt - 'a'] = 0;
      }
      for (int tt = 0; tt < s[t].size(); tt++) {
        cnt_cur[s[t][tt] - 'a']++;
      }
      // cout << cnt_cur[0] <<  " " << cnt_cur[1] << "\n";
      for (int tt = 'a'; tt <= 'z'; tt++) {
        cnt[tt - 'a'] = max(cnt[tt - 'a'], cnt_cur[tt - 'a']);
      }
    }
    int result = 0;
    for (int tt = 'a'; tt <= 'z'; tt++) {
      result += cnt[tt - 'a'];
      // cout << "kir " << cnt[tt - 'a'] << "\n";
    }
    cout << result << "\n";
  }
}
