#include<bits/stdc++.h>
#include<cmath>
using namespace std;

struct Point {
    int x, y;
};

Point reff; // Global reference point for sorting

// Function to find the reference point (lowest y, then lowest x)
Point findRef(vector<Point> &points) {
    Point minPoint = points[0]; // Assume first point is the minimum

    for (int i = 1; i < points.size(); i++) {
        if ((points[i].y < minPoint.y) || (points[i].y == minPoint.y && points[i].x < minPoint.x)) {
            minPoint = points[i]; // Update reference point
        }
    }
    return minPoint;
}

// Returns the second-to-top element of the stack
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p); // Restore the popped element
    return res;
}

// Computes the squared Euclidean distance between two points
int squaredDist(Point p1, Point p2) {
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Calculates the angle of a point relative to the reference point
double getAngle(Point p) {
    return atan2(p.y - reff.y, p.x - reff.x);
}

// Comparator function for sorting points based on polar angle
bool compare(Point p1, Point p2) {
    double angle1 = getAngle(p1);
    double angle2 = getAngle(p2);
    if (angle1 == angle2) {
        return squaredDist(reff, p1) < squaredDist(reff, p2); // Tie-break by distance
    }
    return angle1 < angle2;
}

/* Alternative function to determine the orientation of three points:
   0 -> Collinear, 1 -> Clockwise, 2 -> Counterclockwise */
/*
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}
*/

// Implements the Graham Scan algorithm to find the convex hull
stack<Point> GrahamScan(vector<Point> &p) {
    Point ref = findRef(p); // Find reference point (lowest y, then x)
    sort(p.begin(), p.end(), compare); // Sort points based on polar angle

    /* If only the furthest collinear point be counted:
        // If two or more points make same angle with p0,
        // Remove all but the one that is farthest from p0
        // Remember that, in above sorting, our criteria was
        // to keep the farthest point at the end when more than
        // one points have same angle.
        int m = 1; // Initialize size of modified array
        for (int i=1; i<n; i++){
            // Keep removing i while angle of i and i+1 is same
            // with respect to p0
        while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0){
          i++;
        }

        points[m] = points[i];
        m++;  // Update size of modified array
   }
*/

    stack<Point> s;
    s.push(p[0]);
    s.push(p[1]);

    for (int i = 2; i < p.size(); i++) {
        // Remove points that make a right turn (not part of the convex hull)
        while (s.size() > 1 && 
              ((s.top().x - nextToTop(s).x) * (p[i].y - nextToTop(s).y) - 
               (s.top().y - nextToTop(s).y) * (p[i].x - nextToTop(s).x)) < 0) {
            s.pop();
        }
        s.push(p[i]);
    }

    /* Alternative loop using orientation function:
    for (int i = 3; i < m; i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    */
    
    return s;
}

int main() {
    vector<Point> points = {{0, 0}, {4, 0}, {4, 3}, {2, 5}, {0, 3}};

    stack<Point> s = GrahamScan(points);

    cout << "Points in anti-clockwise order:\n";
    for (auto p : points) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    // Reverse stack to print in correct order
    stack<Point> t;
    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }

    cout << "Points in Convex Hull\n";
    while (!t.empty()) {
        cout << "(" << t.top().x << ", " << t.top().y << ")\n";
        t.pop();
    }

    return 0;
}