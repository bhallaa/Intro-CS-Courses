#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using std::cout;
using std::endl;

int fib_iter(int n);
int fib_recurs(int n);

int main() {

	typedef struct timeval time;
	time stop, start;

	gettimeofday(&start, NULL);
	//Time your iterative or recursive function here.
	int fib = fib_recurs(45);
	cout << fib << endl;

	gettimeofday(&stop, NULL);

	if(stop.tv_sec > start.tv_sec) {
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	}
	else {
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	}

	return 0;

}

int fib_iter(int n) {

	int i = 1, val1 = 0, val2 = 1, val3 = 0;

	if (n == 0) {
		return val3;
	}
	if (n == 1) {
		return val2;
	}

	while (i <= n) {
		val3 = val1 + val2;
		val2 = val1;
		val1 = val3;

		i++;
	}
	return val1;
}


int fib_recurs(int n) {

	if (n <= 1) {
		return n;
	}
	return fib_recurs(n-1) + fib_recurs(n-2);

}
