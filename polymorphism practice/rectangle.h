#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include "./shape.h"

using namespace std;

class Rectangle : public Shape {
  private:
    int length;
    int width;
  public:
    Rectangle();
    int get_length();
    int get_width();
    void set_length(int);
    void set_width(int);
    int calculate_area();
    //void print_shape_info(const Shape&);
};

#endif
