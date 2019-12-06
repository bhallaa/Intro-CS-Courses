#include "./rectangle.h"

Rectangle::Rectangle() {
  name = "Rectangle";
  color = "Green";
  length = 5;
  width = 7;
}

int Rectangle::get_length() { return length; }
int Rectangle::get_width() { return width; }

void Rectangle::set_length (int length) {
  this->length = length;
}

void Rectangle::set_width (int width) {
  this->width = width;
}

int Rectangle::calculate_area() {
  int area = ( get_width() * get_length() );
  return area;
}

/*
void print_shape_info(const Shape& r) {
  cout << "Name of Shape: " << r.get_name() << endl;
  cout << "Color of Shape: " << r.get_color() << endl;
  cout << "Length of Shape: " << r.get_legnth() << endl;
  cout << "Width of Shape: " << r.get_width() << endl;
} */
