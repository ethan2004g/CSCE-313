#include <iostream>
#include <cstring>
#include <cmath>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

public:
  
    Shape(int _vertices) : vertices(_vertices) {

        points = new Point*[vertices +  1];

        for (int i = 0; i <= vertices; ++i) {
            points[i] = new Point();  
        }
    }

    ~Shape() {

        for (int i = 0; i <= vertices; ++i) {
            delete points[i];  
        }

        delete[] points;  
    }

    void addPoints(const Point* pts) {

        for (int i = 0; i < vertices; ++i) {
            memcpy(points[i], &pts[i], sizeof(Point));  
            
        }
    }

    double* area () {

        int temp = 0;
        double* area = new double;

        for (int i = 0; i < vertices; ++i) {

            int cont = (i + 1) % vertices;  // make sure the points wrap around to each other
            int lhs = points[i]->x * points[cont]->y;
            int rhs = points[cont]->x * points[i]->y;
            temp += (lhs - rhs);
        }

        *area = abs(temp)/2.0;
        return area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)

   //Method 1

    Point tri1;       // Default constructor, initialized to (0,0)
    tri1.x = 0;
    tri1.y = 0;

   //Method 2
     
    Point tri2(1, 2); 
    
   //Method 3

    Point tri3 = {2,0};

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    tri->addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)
    Point quad1 = {0,0};
    Point quad2 = {0,2};
    Point quad3 = {2,2};
    Point quad4 = {2,0};

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    // FIXME: print out area of tri and area of quad
    double* triArea = tri->area();
    std::cout << "Area of triangle: " << *triArea << std::endl;
    delete triArea;
    delete tri;

    // Output area of quadrilateral
    double* quadArea = quad->area();
    std::cout << "Area of quadrilateral: " << *quadArea << std::endl;
    delete quadArea;
    delete quad;

    return 0;
}
