#include <iostream>
#include <set>
#include <utility>

using namespace std;

int T;
int n;
int a[3 * 100000 + 5];
int seg[4 * 3 * 100000 + 5];
int lzy[4 * 3 * 100000 + 5];

void seg_set(int idx, int cur = 1, int l = 1, int r = n + 1) {
  if (idx < l || idx >= r) {
    return;
  }
  if (a[idx] > seg[cur]) {
    seg[cur] = a[idx];
  }
  if (r - l == 1) {
    return;
  }
  int m = (l + r) / 2;
  seg_set(idx, cur * 2, l, m);
  seg_set(idx, cur * 2 + 1, m, r);
}

void seg_push(int cur, int l, int r) {
  if (r - l == 1) {
    return;
  }
  seg[cur * 2] += lzy[cur];
  seg[cur * 2 + 1] += lzy[cur];
  lzy[cur * 2] += lzy[cur];
  lzy[cur * 2 + 1] += lzy[cur];
  lzy[cur] = 0;
}

pair<pair<int, int>, bool> seg_get_mx(int cur = 1, int l = 1, int r = n + 1) {
  if (r - l == 1) {
    return make_pair(make_pair(l, a[l * 2]), false);
  }
  int m = (l + r) / 2;
  seg_push(cur, l, r);
  if (seg[cur * 2] > seg[cur * 2 + 1]) {
    return seg_get_mx(2 * cur, l, m);
  } else if (seg[cur * 2] < seg[cur * 2 + 1]) {
    return seg_get_mx(2 * cur + 1, m, r);
  } else {
    pair<pair<int, int>, int> res = seg_get_mx(2 * cur, l, m);
    return make_pair(res.first, true);
  }
}

void seg_add(int st, int en, int val, int cur = 1, int l = 1, int r = n + 1) {
  if (st >= en) {
    return;
  }
  if (st == l && en == r) {
    seg[cur] += val;
    lzy[cur] += val;
  } else {
    int mid = (en + st) / 2;
    int m = (l + r) / 2;
    seg_add(st, min(m, en), val, cur * 2, l, m);
    seg_add(max(m, st), en, val, cur * 2 + 1, m, r);
    seg[cur] = max(seg[cur * 2], seg[cur * 2 + 1]);
  }
}

int seg_get(int idx, int cur = 1, int l = 1, int r = n + 1) {
  if (r - l == 1) {
    return seg[cur];
  }
  int m = (l + r) / 2;
  seg_push(cur, l, r);
  if (idx < m) {
    return seg_get(idx, cur * 2, l, m);
  } else {
    return seg_get(idx, cur * 2 + 1, m, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (int ii = 0; ii < T; ii++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += i;
      seg_set(i);
    }
    int cnt = 0;
    int ptr = n;
    set<int> result;
    while (cnt < n) {
      pair<pair<int, int>, bool> mx;
      mx = seg_get_mx();
      int vv = seg_get(ptr);
      while (mx.first.second != vv) {
        result.insert(vv);
        seg_add(ptr, ptr + 1, -vv);
        cnt++;
        ptr--;
        vv = seg_get(ptr);
      }
      if (mx.second) {
      }
      cout << mx.first.first << " " << mx.first.second << "GG\n";
    }
    for (int i = 0; i < n; i++) {
      cout << result[i] << " ";
    }
    cout << "\n";
  }
}
