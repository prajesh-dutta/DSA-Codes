#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; 


    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }

    int p = leftmost, q;
    vector<Point> hull;

  
    do {
        hull.push_back(points[p]); 
        q = (p + 1) % n;         

        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;
    } while (p != leftmost);

    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0},
                            {0, 0}, {3, 3}, {4, 4}};
    
    vector<Point> hull = convexHull(points);

    cout << "Convex Hull Points:" << endl;
    for (Point p : hull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
