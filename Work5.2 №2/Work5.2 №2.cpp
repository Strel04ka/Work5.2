#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, double a);

int main()
{
	double x, xp, xk, dx, eps, s = 0;
	int n;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << "   |" << setw(10) << "ln 1+x/1-x" << " |"
		<< setw(6) << "S" << "     |" << setw(5) << "n" << " |" << endl;
	cout << "-----------------------------------------" << endl;

	x = xp;
	while (x <= xk && abs(x) < 1)
	{
		s = S(x, eps, n, s);

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << log((1 + x) / (1 - x)) << " |"
			<< setw(10) << setprecision(5) << s << " |"
			<< setw(5) << n << " |"

			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	cin.get();
	return 0;
}
double S(const double x, const double eps, int& n, double s)
{
	n = 0;
	double a = x;
	s = a;
	do {
		n++;
		a = A(x, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}
double A(const double x, double a)
{
	double R = 0.6 * x * x;
	a *= R;
	return a;
}
