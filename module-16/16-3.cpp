// Intersection: Given two straight line segments (represented as a start point and an end point), compute the point of intersection, if any

// source  http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/


#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef struct point {
	int x, y;
} point_t;

int Intersecting(point_t p1, point_t q1, point_t p2, point_t q2) {
	int slop1 = (q1.y - p1.y)/(q1.x - p1.x);
	int slop2 = (q2.y - p2.y)/(q2.x - p2.x);
	return abs(slop1 - slop2);
}

int main() {
	point_t p1 = {1,1}, q1 = {2,2}, p2 = {2,0}, q2 = {0,2};

	if(Intersecting(p1, q1, p2, q2) != 0 ) cout << "Yes, two points intersect" << endl;
	else cout << "No, dont intersect " << endl;
}
