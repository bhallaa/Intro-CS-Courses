#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "./shape.h"

using namespace std;

class Circle : public Shape {
private:
  int radius;
public:
  Circle();
  int get_radius();
  void set_radius(int);
  int calculate_area();
  //void print_shape_info(const Shape&);
};

#endif
