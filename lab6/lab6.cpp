#include <stdio.h>

class Shape {
    public:
        ~Shape();
        virtual void draw();
};
class Circle : public Shape {
    public:
        ~Circle();
        void draw();
};
Shape::~Shape() {
    printf("shape destructor\n");
}
void Shape::draw() {
    printf("Shape::draw\n");
}
Circle::~Circle() {
    printf("circle destructor\n");
}
void Circle::draw() {
    printf("Circle::draw\n");
}
int main() {
    Shape *c = new Circle;
    // Shape c;
    c->draw();
    delete c;
    return 0;
}

