int & value() {
		return num;
	}
	void operator +(const Number & a) {
		this->num += a.num;
	}