#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;
typedef double ftype;

// Point Struct
struct point2d {
  ftype x, y;
  point2d() : x(0), y(0) {}
  point2d(ftype x, ftype y) : x(x), y(y) {}
};
ftype dot(point2d a, point2d b) { return a.x * b.x + a.y * b.y; }
ftype norm(point2d a) { return sqrt(dot(a, a)); }
ftype dis(point2d a, point2d b) { return norm(point2d(a.x - b.x, a.y - b.y)); }
//

#define PI 3.14159265

ftype x_0, y_0, v, T;
int n;
point2d p[100005];
ftype r[100005];
vector<pair<ftype, ftype>> covered_ranges;
vector<pair<ftype, ftype>> dup_ranges;
vector<pair<ftype, ftype>> uncovered_range;
stack<ftype> st;
ftype EPS = 10e-4;

vector<point2d> get_line_circle_i_points(ftype l_a, ftype l_b, ftype l_c, ftype r) {
  ftype x0 = -l_a * l_c / (l_a * l_a + l_b * l_b);
  ftype y0 = -l_b * l_c / (l_a * l_a + l_b * l_b);
  if (l_c * l_c > r * r * (l_a * l_a + l_b * l_b) + EPS) {
    return vector<point2d>(0);
  } else if (abs(l_c * l_c - r * r * (l_a * l_a + l_b * l_b)) < EPS) {
    return vector<point2d>{point2d(x0, y0)};
  } else {
    ftype d = r * r - l_c * l_c / (l_a * l_a + l_b * l_b);
    ftype mult = sqrt(d / (l_a * l_a + l_b * l_b));
    ftype ax, ay, bx, by;
    ax = x0 + l_b * mult;
    bx = x0 - l_b * mult;
    ay = y0 - l_a * mult;
    by = y0 + l_a * mult;
    return vector<point2d>{point2d(ax, ay), point2d(bx, by)};
  }
}

vector<point2d> get_two_circles_i_points(point2d p1, ftype r1, point2d p2, ftype r2) {
  // move circle 1 to origin (+transition)
  point2d d = point2d(-p1.x, -p1.y);
  point2d p1_1 = point2d(0, 0);
  point2d p2_1 = point2d(p2.x + d.x, p2.y + d.y);
  // cout << "gggg " << p1_1.x << " " << p1_1.y << " " << p2_1.x << " " << p2_1.y << "\n";
  // reduce to find line intersection
  ftype l_a = -2 * p2_1.x;
  ftype l_b = -2 * p2_1.y;
  ftype l_c = p2_1.x * p2_1.x + p2_1.y * p2_1.y + r1 * r1 - r2 * r2;
  vector<point2d> points = get_line_circle_i_points(l_a, l_b, l_c, r1);
  // (-transition)
  vector<point2d> result;
  for (point2d p : points) {
    result.push_back(point2d(p.x - d.x, p.y - d.y));
  }
  return result;
}

bool pair_of_ftype_cmp(pair<ftype, ftype> p1, pair<ftype, ftype> p2) { return dis(point2d(p1.first, p1.second), point2d(p2.first, p2.second)) < EPS; }

int main() {
  cin >> x_0 >> y_0 >> v >> T;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> r[i];
  }
  point2d d = point2d(-x_0, -y_0);
  for (int i = 0; i < n; i++) {
    p[i].x += d.x;
    p[i].y += d.y;
  }
  ftype r_0 = v * T;
  x_0 = 0;
  y_0 = 0;
  // check if center is covered by some circle
  for (int i = 0; i < n; i++) {
    if (abs(dis(point2d(x_0, y_0), p[i]) - r[i]) <= EPS) {
      cout << 1 << "\n";
      return 0;
    }
  }
  // calculating the covered angle for each circle
  for (int i = 0; i < n; i++) {
    ftype theta = PI / 2 - atan(p[i].y / p[i].x);
    if (p[i].x < 0) {
      theta += PI;
    }
    ftype dd;
    if (abs((dis(p[i], point2d(0, 0)) + r[i]) - r_0) <= EPS) {
      dd = asin(r[i] / dis(p[i], point2d(0, 0)));
    } else {
      vector<point2d> i_points = get_two_circles_i_points(point2d(x_0, y_0), r_0, p[i], r[i]);
      if (i_points.size() != 2) {
        continue;
      }
      point2d i_point_1 = i_points.at(0);
      point2d i_point_2 = i_points.at(1);
      cout << "1 => " << i_point_1.x << " " << i_point_1.y << "\n";
      cout << "2 => " << i_point_2.x << " " << i_point_2.y << "\n";
      dd = acos(dot(i_point_1, i_point_2) / norm(i_point_1) / norm(i_point_2)) / 2;
      cout << "FKN => " << dd << "\n";
    }
    covered_ranges.push_back(make_pair(theta - dd, theta + dd));
  }
  // calculate the union of ranges
  for (pair<ftype, ftype> r : covered_ranges) {
    dup_ranges.push_back(make_pair(r.first - 2 * PI, r.second - 2 * PI));
    dup_ranges.push_back(make_pair(r.first, r.second));
    dup_ranges.push_back(make_pair(r.first + 2 * PI, r.second + 2 * PI));
  }
  sort(dup_ranges.begin(), dup_ranges.end());
  if (!dup_ranges.empty()) {
    ftype mx = dup_ranges.front().first;
    for (pair<ftype, ftype> r : dup_ranges) {
      while (!st.empty() && st.top() < r.first) {
        st.pop();
      }
      if (st.empty()) {
        pair<ftype, ftype> p = make_pair(mx, r.first);
        while (p.first < 0) {
          p.first += 2 * PI;
          p.second += 2 * PI;
        }
        while (p.first >= 2 * PI) {
          p.first -= 2 * PI;
          p.second -= 2 * PI;
        }
        uncovered_range.push_back(p);
      }
      st.push(r.second);
      mx = max(mx, r.second);
    }
    sort(uncovered_range.begin(), uncovered_range.end());
    for (pair<ftype, ftype> r : uncovered_range) {
      cout << "AAA => " << r.first << " " << r.second << "\n";
    }
    cout << "GOOOZZZZ\n";
    vector<pair<ftype, ftype>>::iterator it = unique(uncovered_range.begin(), uncovered_range.end(), pair_of_ftype_cmp);
    uncovered_range.resize(distance(uncovered_range.begin(), it));
    for (pair<ftype, ftype> r : uncovered_range) {
      cout << "BBB => " << r.first << " " << r.second << "\n";
    }
  }
  ftype sum = 0;
  for (pair<ftype, ftype> r : uncovered_range) {
    // cout << "GGG => " << r.first << " " << r.second << "\n";
    sum += r.second - r.first;
  }
  cout << "GGGGGGGG\n";
  cout << fixed << setprecision(10) << 1 - sum / (2 * PI) << "\n";
  return 0;
}
