Number operator*(Number a) {
		Number b(num*a.num);
		return b;
	}
	operator int() {
		return num;
	}