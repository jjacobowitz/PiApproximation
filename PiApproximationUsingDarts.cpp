/*
Jared Jacobowitz
June 2020

Approximates Pi using random "darts" and computing the ratio of the number
of darts that land within the circle compared to how many were thrown
*/

#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main(){
	cout << "Beginning Pi Calculation." << endl;
	cout << "Enter how many darts to be thrown: ";
	int darts;
	cin >> darts;

	int r = 10; // radius/sidelength of circle/square
	int min = -r;
	int max = r;

	random_device rd; // obtain a random number from hardware
	mt19937 gen(rd()); // seed the generator
	uniform_real_distribution<> distr(min, max); // define the range

	long double x, y;
	int inCircle = 0;

	for (int i = 0; i <= darts; i++) {
		x = distr(gen);
		y = distr(gen);

		long double dist = x * x + y * y; // distance from (0,0), where the circle is centered
		
		// if the point lands within the circle, increment the counter of darts within the circle
		if (dist < r*r) {
			inCircle++;
		}
	}

	cout.precision(17); // set 17 decimals of precision

	long double approxPi = (long double)4.0 * (long double)inCircle / (long double)darts; // calculates pi; 4 * pi*r^2 / 4 * r^2 = pi
	long double actualPi = 2 * asin(1.0); // actual pi value for comparison

	long double perDiff = abs(actualPi - approxPi) / actualPi * 100; // percent difference

	cout << "Approx Pi = " << approxPi << endl;
	cout << "Actual Pi = " << actualPi << endl;

	cout.precision(5); // change the precision for the percent difference value
	cout << "Percent Diff. = " << perDiff << "%\n\n\n\n\n";


	return 0;
}