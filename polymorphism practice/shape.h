#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

using namespace std;

class Shape {
  protected:
    string name;
    string color;
  public:
    Shape();
    string get_name();
    string get_color();
    void set_name(string);
    void set_color(string);
    virtual int calculate_area() = 0;
    //virtual void print_shape_info(const Shape &) = 0;
};

#endif
