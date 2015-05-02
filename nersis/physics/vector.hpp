class Vec;
class Ang;
#define vecNum int64_t
#define angNum int32_t

class Vec {
	vecNum x;
	vecNum y;
	vecNum Vec::distance(void);
	Vec Vec::distance(Vec base);
	Vec Vec::normalize(vecNum distance);
	Vec Vec::normalize(vecNum distance,Vec base);
}

class Ang {
	angNum n;
}