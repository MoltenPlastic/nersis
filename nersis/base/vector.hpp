typedef vecNum int64_t;
typedef angNum int32_t;

class vec {
	vecNum x;
	vecNum y;
	vecNum distance(void);
	vec distance(vec base);
	vec normalize(vecNum distance);
	vec normalize(vecNum distance,vec base);
	ang vec::angle();
}

vec operator+(vec a,vec b);
vec operator+(vec a,vecNum b);
vec operator-(vec a,vec b);
vec operator-(vec a,vecNum b);
vec operator*(vec a,vec b);
vec operator*(vec a,vecNum b);
vec operator/(vec a,vec b);
vec operator/(vec a,vecNum b);

class ang {
	angNum n;
}