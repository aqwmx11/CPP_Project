template <class T>
class CMyistream_iterator {
private:
	istream & i;
	T a;
public:
	CMyistream_iterator(istream& input) :i(input)
	{
		i >> a;
	}
	T operator * () {
		return a;
	}
	void operator ++ (int) {
		i >> a;
	}
};