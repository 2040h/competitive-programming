using matrix_t = int;

struct Mat {
	int n, m;
	vector<vector<matrix_t>> a;
	
	Mat() { }
	// Inicializa matriz de nxm con todos 0.
	Mat(int _n, int _m){
		n = _n; m = _m;
		a.assign(n, vector<matrix_t>(m, 0));
	}
	// Inicializa una matriz a partir de un vector.
	Mat(vector< vector<matrix_t> > v){
		n = v.size();
		m = n ? v[0].size() : 0;
		a = v;
	}
	
	// Constructor de la identidad.  (Puedo hacer Mat I = Mat::identity(4);)
	static Mat identity(int _n) {
		Mat res(_n, _n);
		for (int i = 0; i < _n; ++i){
			res.a[i][i] = 1;
		}
		return res;
	}
		
	// Constructores de matrices vectores columnas.
	static Mat crearVectorColumna(vector<matrix_t> v) {  // ej: Mat inicial = Mat::crearVectorColumna(vector<int> {1, 1});
		Mat res(SIZE(v), 1);
		for (int i=0; i<SIZE(v); i++){
			res.a[i][0] = v[i];
		}
		return res;
	}
	
	inline Mat operator + (const Mat &b) {
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] + b.a[i][j]) % MOD;
			}
		}
		return ans;
    }
    
    inline Mat operator - (const Mat &b) {
		assert(n == b.n && m == b.m);
		Mat ans = Mat(n, m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans.a[i][j] = (a[i][j] - b.a[i][j]) % MOD;
			}
		}
		return ans;
    }
    
    inline Mat operator * (const Mat &b) {
		assert(m == b.n);
		Mat ans = Mat(n, b.m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < b.m; j++) {
				for(int k = 0; k < m; k++) {
					ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % MOD) % MOD;
				}
			}
		}
		return ans;
	}
	
	inline Mat pow(long long expo) {
		assert(n == m);
		Mat ans = identity(n);
		Mat t(a);
		
		while (expo) {
			if (expo & 1){
				ans = ans * t;
			}
			t = t * t;
			expo >>= 1;
		}
		return ans;
	}
	
	inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
	inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
	inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
	inline bool operator == (const Mat& b) { return a == b.a; }
	inline bool operator != (const Mat& b) { return a != b.a; }
	
	// Sobrecarga del operador <<
	friend ostream& operator<<(ostream& os, const Mat& mat) {
		for (int i = 0; i < mat.n; i++) {
			cout << "[";
			for (int j = 0; j < mat.m; j++) {
				os << mat.a[i][j] << ' ';
			}
			cout << "]";
			os << '\n';
		}
		return os;
	}
	
	// Acceso como M[i][j]
	inline vector<matrix_t>& operator[](int i) { return a[i]; }
	inline const vector<matrix_t>& operator[](int i) const { return a[i]; }
};
