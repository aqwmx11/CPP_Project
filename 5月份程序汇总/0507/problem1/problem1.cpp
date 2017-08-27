template <class T>
class CArray3D {
public:
	template <class T1>
	class CArray2D {
	public:
		template <class T2>
		class CArray1D {
		public:
			CArray1D() {
				a = NULL;
			}
			void set(int n) {
				a = new T[n];
			}
			T2 & operator[](int i) {
				return a[i];
			}
			~CArray1D() {
				delete[]a;
			}
		private:
			T2 * a;
		};
		CArray2D() {
			a1 = NULL;
		}
		void set(int m, int n) {
			a1 = new CArray1D<T1>[m];
			for (int i = 0; i < m; i++)
				a1[i].set(n);
		}
		CArray1D<T1> & operator[](int i) {
			return a1[i];
		}
		~CArray2D() {
			delete[]a1;
		}
	private:
		CArray1D<T1> * a1;
	};
	CArray3D(int p,int m, int n) {
		a2 = new CArray2D<T> [p];
		for (int i = 0; i < p; i++)
			a2[i].set(m, n);
	}
	CArray2D<T>& operator[](int i) {
		return a2[i];
	}
	~CArray3D() {
		delete[]a2;
	}
private:
	CArray2D<T> * a2;
};