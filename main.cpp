#include <iostream>
#include <math.h>

#define G 6.674E-11
#define MO 1.9891E30
#define pc 3.08567758E16
#define yr 31536000


#define dt 1000000
#define m1 1
#define m2 1

double Gmod = G*MO*yr*yr/(pc*pc*pc);

double rad(double a[2], double b[2]) {
	return sqrt((b[1]-a[1])*(b[1]-a[1])+(b[2]-a[2])*(b[2]-a[2]));
}

double r1[2], r2[2];
double v1[2], v2[2];
double a[2];

int main(int argc, char **argv)
{	
	r1[1] = -20; r1[2] = 1;
	r2[1] = 0; r2[2] = 0;

	v1[1] = 1*sqrt(2*Gmod*m2/(rad(r1,r2))); v1[2] = 0;
	v2[1] = 0; v2[2] = 0;
	
	a[1] = Gmod*(r2[1]-r1[1])/pow(3,rad(r1,r2));
	a[2] = Gmod*(r2[2]-r1[2])/pow(3,rad(r1,r2));
		
	v1[1] -= a[1]*m2*dt/2; v1[2] -= a[2]*m2*dt/2;
	v2[1] += a[1]*m1*dt/2; v2[2] += a[2]*m1*dt/2;
	
	std::cout << "# " << "	r1x	r1y	v1x	v1y	r2x	r2y	v2x	v2y"<< std::endl;
	std::cout << "0" << "	" << r1[1] << "	" << r1[2] << "	" << v1[1] << "	" << v1[2] << "	" << r2[1] << "	" << r2[2] << "	" << v2[1] << "	" << v2[2] << std::endl;
	
	for (int i=1; i<2000; i++) {
		a[1] = Gmod*(r2[1]-r1[1])/pow(3,rad(r1,r2));
		a[2] = Gmod*(r2[2]-r1[2])/pow(3,rad(r1,r2));
		
		v1[1] += a[1]*m2*dt; v1[2] += a[2]*m2*dt;
		v2[1] -= a[1]*m1*dt; v2[2] -= a[2]*m1*dt;
		
		r1[1] += v1[1]*dt; r1[2] += v1[2]*dt;
		r2[1] += v2[1]*dt; r2[2] += v2[2]*dt;
		
		std::cout << i << "	" << r1[1] << "	" << r1[2] << "	" << v1[1] << "	" << v1[2] << "	" << r2[1] << "	" << r2[2] << "	" << v2[1] << "	" << v2[2] << std::endl;
	}
		
	return 0;
}
