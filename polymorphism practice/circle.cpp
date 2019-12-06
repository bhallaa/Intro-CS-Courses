#include "./circle.h"

Circle::Circle() {
  name = "Circle";
  color = "Purple";
  radius = 3;
}

int Circle::get_radius() { return radius; }

void Circle::set_radius (int radius) {
  this->radius = radius;
}

int Circle::calculate_area() {
  int area = ( ((get_radius())^2) * (3.1415926535) );
  return area;
}

/*
void print_shape_info(const Shape& c) {
  cout << "Name of Shape: " << c.get_name() << endl;
  cout << "Color of Shape: " << c.get_color() << endl;
  cout << "Radius of Shape: " << c.get_radius() << endl;
} */
