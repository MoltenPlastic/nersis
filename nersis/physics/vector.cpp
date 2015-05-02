// Vector library
// Provides determenistic vector and angle calculations

#include "physics/vector.hpp"

class Vec {
	vecNum x;
	vecNum y;
}

class Ang {
	angNum n;
}

vecNum sqrt(vecNum a) {
	vecNum op=a;
	vecNum res=0;
	vecNum one=1<<((sizeof(vecNum)*8)-2); // second to top bit
	while (one>op) {
		one>>=2;
	}
	while (one!=0){
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

vecNum Vec::distance(void) {
	return sqrt((abs(a)^2)+(abs(b)^2)) // TODO: reduce accuracy to allow larger distances
}

Vec Vec::distance(Vec base) {
	return (this-base)->distance();
}

Vec Vec::normalize(vecNum distance) {
	return (this*distance)/this->distance();
}

Vec Vec::normalize(vecNum distance,Vec base) {
	return ((this-base)->normalize(distance))+base;
}