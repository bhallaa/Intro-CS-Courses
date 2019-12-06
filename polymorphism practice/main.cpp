#include "./circle.h"
#include "./rectangle.h"

void print_shape_info(Shape& s) {
  cout << "Name of Shape: " << s.get_name() << endl;
  cout << "Color of Shape: " << s.get_color() << endl;
  cout << "Area of Shape: " << s.calculate_area() << endl;
}

int main() {
  //Circle c;
  //Rectangle r;
  Shape *s;
  s = new Circle;

  cout << "CIRCLE INFO:" << endl;
  print_shape_info(*s);

  delete s;
  cout << endl << endl;

  s = new Rectangle;
  cout << "RECTANGLE INFO:" << endl;
  print_shape_info(*s);

  cout << endl << endl;

  return 0;
}
