#define _CRT_SECURE_NO_WANRNIGS
#include <stdio.h>
#define theta0 0 
#define n 0.000001

double f_x(double x,double theta1) {
	return theta0 + theta1 * x;
}

double f_theta1(double* px, double* py, double theta1) {
	double sum = 0;
	int i = 0;
	
	for(i=0;i<6;i++){
		sum += (f_x(px[i], theta1) - py[i]) * px[i];
	}
	return sum;
}

int main() {

	double px[6] = { 90, 110, 95, 135, 150, 155 };
	double py[6] = { 0.7, 0.69, 0.85, 1, 0.95, 1.1 };
	double theta1 = 0.01;
	double temp1 = 0;
	int i = 0;
	double sigma = 0;

	for(i=0;i<1000;i++){
		temp1 = theta1 - n * f_theta1(px, py, theta1);
		theta1 = temp1;
		printf("%lf\n", theta1);

	}

}