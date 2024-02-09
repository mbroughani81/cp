#include <iostream>

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

ftype x_0, y_0, v, T;
int n;
point2d p[100005];
ftype r[100005];

int main() {
  cin >> x_0 >> y_0 >> v >> T;
  cin >> n;
}
