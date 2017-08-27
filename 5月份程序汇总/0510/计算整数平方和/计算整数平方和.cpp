class CType {
private:
	int value;
public:
	CType(int a = 0) :value(a) {}
	void setvalue(const int & a) {
		value = a;
	}
	CType & operator ++ (int) {
		static CType tmp(0);
		tmp.value = value;
		value *= value;
		return tmp;
	}
	friend ostream& operator << (ostream& o, CType& cType)
	{
		o << cType.value;
		return o;
	}
};