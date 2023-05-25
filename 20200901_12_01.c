#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
}POINTER;

double pointer_dist(POINTER *p1, POINTER *p2) {
	double result;
	double d_x = (p1->x) - (p2->x);
	d_x = pow(d_x, 2.0);
	double d_y = (p1->y) - (p2->y);
	d_y = pow(d_y, 2.0);
	result = sqrt(d_x + d_y);
	return result;
}

int main() {
	POINTER XY[10];
	for (int i = 0; i < 10; i++) {
		printf("%d - Enter x, y coordinate values : ", i + 1);
		scanf("%lf %lf", &XY[i].x, &XY[i].y);
	}
	printf("******************************************************************\n");
	for (int i = 0; i < 10;) {
		double result = pointer_dist(&XY[i], &XY[i + 1]);
		printf("The distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) pointers : %.2lf\n", XY[i].x, XY[i].y, XY[i + 1].x, XY[i + 1].y, result);
		i = i + 2;
	}

}