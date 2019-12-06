#include "./property.h"

int main() {
  Property p1(5, 5000);
  Property p2(3, 3000);

  if ( p1 > p2 ) { cout << " Property 1 is bigger than Property 2" << endl; }
  if ( p1 < p2 ) { cout << " Property 1 is smaller than Property 2" << endl; }

  return 0;
}
