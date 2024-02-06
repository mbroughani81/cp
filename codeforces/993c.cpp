#include <iostream>
#include <math.h>
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
ftype norm(point2d a) { return dot(a, a); }
//

int n;
point2d p[3];
ftype r[3];
vector<point2d> intersect_points[3], all_intersect_points;
bool has_intersection[3];
ftype EPS = 10e-9;

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

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> r[i];
  }
  for (int i = 0; i < n; i++) {
    for (int t = i + 1; t < n; t++) {
      vector<point2d> points = get_two_circles_i_points(p[i], r[i], p[t], r[t]);
      if (points.size() > 0) {
        has_intersection[i] = true;
        has_intersection[t] = true;
      }
      for (point2d p : points) {
        bool f = false;
        for (point2d pp : intersect_points[i]) {
          if (norm(point2d(p.x - pp.x, p.y - pp.y)) < EPS) {
            f = true;
          }
        }
        if (!f) {
          intersect_points[i].push_back(p);
        }
      }
      for (point2d p : points) {
        bool f = false;
        for (point2d pp : intersect_points[t]) {
          if (norm(point2d(p.x - pp.x, p.y - pp.y)) < EPS) {
            f = true;
          }
        }
        if (!f) {
          intersect_points[t].push_back(p);
        }
      }
      for (point2d p : points) {
        bool f = false;
        for (point2d pp : all_intersect_points) {
          if (norm(point2d(p.x - pp.x, p.y - pp.y)) < EPS) {
            f = true;
          }
        }
        if (!f) {
          all_intersect_points.push_back(p);
        }
      }
    }
  }
  int e = 0;
  for (int i = 0; i < n; i++) {
    e += intersect_points[i].size();
  }
  if (n == 2) {
    if (!has_intersection[0]) {
      e += 1;
    }
  } else if (n == 3) {
    if (!has_intersection[0] || !has_intersection[1] || !has_intersection[2]) {
      if (!has_intersection[0] && !has_intersection[1] && !has_intersection[2]) {
        e += 2;
      } else {
        e += 1;
      }
    }
  }

  // cout << e << " " << all_intersect_points.size() << "\n";
  cout << 2 + e - all_intersect_points.size() << "\n";
}
