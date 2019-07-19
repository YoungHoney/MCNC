#define _CRT_SECURE_NO_WANRNIGS
#include <stdio.h>
#define n 0.00001

double f_x(double x, double theta0, double theta1) {
	return theta0 + theta1 * x;
}

double f_theta0(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0;i < 6;i++) {
		sum += (f_x(px[i], theta0, theta1) - py[i]);
	}
	return sum;
}

double f_theta1(double* px, double* py, double theta0, double theta1) {
	double sum = 0;
	int i = 0;

	for (i = 0;i < 6;i++) {
		sum += (f_x(px[i], theta0, theta1) - py[i]) * px[i];
	}
	return sum;
}



int main() {

	double px[6] = { 90, 110, 95, 135, 150, 155 };
	double py[6] = { 0.7, 0.69, 0.85, 1, 0.95, 1.1 };
	double theta0 = 0.27111, theta1 = 0.004984;
	double temp0 = 0, temp1 = 0;
	int i = 0;
	double sigma = 0;

	for (i = 0;;i++) {
		temp0 = theta0 - n * f_theta0(px, py, theta0, theta1);
		temp1 = theta1 - n * f_theta1(px, py, theta0, theta1);
		theta0 = temp0;
		theta1 = temp1;
		printf("%lf  ", theta0);
		printf("%lf\n", theta1);

	}

	/*
	for (i = 0;i < 1000;i++) {
		theta0 = theta0 - n * f_theta0(px, py, theta0, theta1);
		theta1 = theta1 - n * f_theta1(px, py, theta0, theta1);
		printf("%lf  ", theta0);
		printf("%lf\n", theta1);

	}
	*/
}