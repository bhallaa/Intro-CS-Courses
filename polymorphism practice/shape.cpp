#include "./shape.h"

Shape::Shape() {
  name = "";
  color = "";
}

string Shape::get_name() { return name; }
string Shape::get_color() { return color; }

void Shape::set_name(string name) {
    this->name = name;
}

void Shape::set_color(string color) {
    this->color = color;
}
