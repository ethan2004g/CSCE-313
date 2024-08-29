#include <iostream>
#include <cstring> //for memcpy
#include <cmath> //used for abs() function

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

public:
  
    //Constructor
    Shape(int _vertices) : vertices(_vertices) {

        points = new Point*[vertices +  1];

        for (int i = 0; i <= vertices; ++i) {
            points[i] = new Point();  
        }
    }
    //Destructor
    ~Shape() {

        for (int i = 0; i <= vertices; ++i) {
            delete points[i];  //for memory leaks
        }

        delete[] points;    //for memory leaks
    }

    void addPoints(const Point* pts) { //Fixed parameter

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
   
   //Method 1

    Point tri1;     // Default constructor, initialized to (0,0)
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

    //Using method 3 for easy creation
    Point quad1 = {0,0};
    Point quad2 = {0,2};
    Point quad3 = {2,2};
    Point quad4 = {2,0};

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    //Printing out the Areas for Triangle and Quadrilateral

    // Output area of Triangle
    double* triArea = tri->area();
    std::cout << "The Area of the Triangle is " << *triArea << std::endl;
    delete triArea;
    delete tri;

    // Output area of quadrilateral
    double* quadArea = quad->area();
    std::cout << "The Area of the Quadrilateral is " << *quadArea << std::endl;
    delete quadArea;
    delete quad;

    return 0;
}
