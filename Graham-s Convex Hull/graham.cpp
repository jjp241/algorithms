#include <bits/stdc++.h>

// <! The Graham's Convex Hull !> //

struct Point{
    int x;
    int y;
    int d;
    double alfa;

    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void update(){
        if (x == 0 && y == 0)
            alfa = 0;
        else if (x == 0 && y != 0)
            alfa = 1000000; // a big number
        else
            alfa = y/x;
    }
};

bool comparator(Point p1, Point p2){
    // result
    if (p1.alfa == p2.alfa){
        if (p1.x <= p2.x)
            return true;
        else
            return false;
    }
    else if (p1.alfa < p2.alfa)
        return true;
    else
        return false;
}

int det(Point a, Point b, Point c){
    return a.x*b.y + a.y*c.x + b.x*c.y - b.y*c.x - a.x*c.y - a.y*b.x;
}

void graham(std::vector <Point> &hull, std::vector <Point> points){
    hull.push_back(points[0]);
    hull.push_back(points[1]);
    hull.push_back(points[2]);
    int x; // the det
    for (int i = 3; i < points.size(); i++){
        x = det(hull[hull.size()-2], hull[hull.size()-1], points[i]);
        while (x < 0){
            hull.pop_back();
            x = det(hull[hull.size()-2], hull[hull.size()-1], points[i]);
        }
        hull.push_back(points[i]);
    }
}

int main(){
    int n = -1; // number of points
    std::cout << "Input the number of points (greater than 3): ";
    do {
        std::cin >> n;
    }
    while (n <= 3);

    std::vector <Point> points;
    int x, y; // for inputing points
    Point first(INT_MAX, INT_MAX); // for the first
    std::cout << "Now input the points (x, y):\n";
    for (int i = 0; i < n; i++){
        std::cin >> x >> y;
        Point p1(x, y);
        if (p1.y < first.y)
            first = p1;
        else if (p1.y == first.y && p1.x < first.x)
            first = p1;
        points.push_back(p1);
    }  

    // substracting the first point from others
    for (int i = 0; i < n; i++){
        points[i].x -= first.x;
        points[i].y -= first.y;
        points[i].update();
    }

    // sorting the points
    std::sort(points.begin(), points.end(), comparator);

    // convex hull
    std::vector <Point> hull;
    graham(hull, points);  
    
    // output
    std::cout << "The following points create the convex hull:\n";
    for (int i = 0; i < hull.size(); i++)
        std::cout << i+1 << ". (" << hull[i].x+first.x << ", " << hull[i].y+first.y << ")\n";
}
