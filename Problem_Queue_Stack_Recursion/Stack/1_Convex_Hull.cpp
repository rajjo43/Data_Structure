// #include <bits/stdc++.h>
// using namespace std;

// struct Point{
//     int x,y;
// };

// int orientation(Point p, Point q, Point r){
//     int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

//     if(val == 0)
//         return 0;
//     else
//         return (val > 0)? 1:2; 
// }   

// void convexHull(Point points[], int n){
//     if(n < 3) return;
//     vector<Point> hull;
//     int l = 0;
//     for(int i = 1; i < n; i++){ //take the leftmost point
//         if(points[i].x < points[l].x){
//             l = i;
//         }
//     }

//     int p = l,q;
//     do{
//         hull.push_back(points[p]);
//         q = (p+1) % n;
//         for(int i = 0; i < n; i++){
//             if(orientation(points[p],points[i],points[q]) == 2){
//                q = i; 
//             }
//         }
//         p = q;
//     }while(p != l);

//     for(int i = 0; i < hull.size(); i++){
//         cout <<"("<<hull[i].x << "," << hull[i].y << ")\n";
//     }
// }

// int main(){
//     Point points[] = {{0,3}, {2,2}, {1,1}, {2,1}, {3,0}, {0,0}, {3,3}};

//     int n = sizeof(points) / sizeof(points[0]);
//     convexHull(points, n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Function to find the orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2;  // Clockwise or Counterclockwise
}

// Sorting points based on polar angle with reference to the lowest point
bool compare(Point p1, Point p2, Point p0) {
    int o = orientation(p0, p1, p2);
    if (o == 0)  // If collinear, sort by distance
        return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) <
               (p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y);
    return (o == 2);  // Counterclockwise order
}

// Function to compute the convex hull using Graham's scan
void convexHull(Point points[], int n) {
    if (n < 3) return;  // Convex hull not possible

    // Step 1: Find the lowest point (smallest y, then smallest x)
    int minYIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minYIdx].y || 
           (points[i].y == points[minYIdx].y && points[i].x < points[minYIdx].x)) {
            minYIdx = i;
        }
    }
    swap(points[0], points[minYIdx]);  // Move lowest point to index 0
    Point p0 = points[0];

    // Step 2: Sort points based on polar angle with respect to p0
    sort(points + 1, points + n, [p0](Point p1, Point p2) {
        return compare(p1, p2, p0);
    });

    // Step 3: Use stack to construct convex hull
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    for (int i = 3; i < n; i++) {
        while (hull.size() > 1) {
            Point second = hull.top();
            hull.pop();
            Point first = hull.top();
            if (orientation(first, second, points[i]) == 2) {
                hull.push(second);
                break;
            }
        }
        hull.push(points[i]);
    }

    // Step 4: Print the convex hull points
    while (!hull.empty()) {
        Point p = hull.top();
        hull.pop();
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
