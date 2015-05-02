typedef vecNum int64_t;
typedef angNum int32_t;

class vec {
	vecNum x;
	vecNum y;
	vecNum Vec::distance(void);
	Vec Vec::distance(Vec base);
	Vec Vec::normalize(vecNum distance);
	Vec Vec::normalize(vecNum distance,Vec base);
}

class ang {
	angNum n;
}