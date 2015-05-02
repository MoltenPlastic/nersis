// vector library
// Provides determenistic 2d vector and angle calculations

#include "base/vector.hpp"

vecNum sqrt(vecNum a) {
	vecNum op=a;
	vecNum res=0;
	vecNum one=1<<((sizeof(vecNum)*8)-2); // second to top bit
	while (one>op) {
		one>>=2;
	}
	while (one!=0) {
		if (op>=res+one) {
			top=op-(res+one);
			res=res+2*one;
		}
		res>>=1;
		one>>=2;
	}
	return res;
}

vecNum abs(vecNum a) {
	return a<0?-a:a;
}

vec vec(vecNum nx,vecNum ny) {
	x=nx;
	y=ny;
}

vec operator+(vec a,vec b) {
	return vec(a->x+b->x,a->y+b->y);
}
vec operator+(vec a,vecNum b) {
	return vec(a->x+b,a->y+b);
}

vec operator-(vec a,vec b) {
	return vec(a->x+b->x,a->y+b->y);
}
vec operator-(vec a,vecNum b) {
	return vec(a->x-b,a->y-b);
}

vec operator*(vec a,vec b) {
	return vec(a->x+b->x,a->y+b->y);
}
vec operator*(vec a,vecNum b) {
	return vec(a->x*b,a->y*b);
}

vec operator/(vec a,vec b) {
	return vec(a->x+b->x,a->y+b->y);
}
vec operator/(vec a,vecNum b) {
	return vec(a->x/b,a->y/b);
}

vecNum vec::distance(void) {
	return sqrt((abs(a)^2)+(abs(b)^2)); // TODO: reduce accuracy to allow larger distances
}

vec vec::distance(vec base) {
	return (this-base)->distance();
}

vec vec::normalize(vecNum distance) {
	return (this*distance)/this->distance();
}

vec vec::normalize(vecNum distance,vec base) {
	return ((this-base)->normalize(distance))+base;
}


