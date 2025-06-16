#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll UNDEFINED = -1;
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ll zero = 0;
const ld EPSILON = 1e-10;
const double PI = acos(-1.0);

#define pb push_back
#define fst first
#define snd second
#define esta(x,c) ((c).find(x) != (c).end())  // Devuelve true si x es un elemento de c.
#define all(c) (c).begin(),(c).end()
#define SIZE(c) int((c).size())

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "----------" << endl

#define forn(i,n) for (int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for (int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(int)((n)-1);i>=0;i--)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=(int)(s);i--)
#define forall(i,c) for(auto i=(c).begin(), i != (c).end(); i++)
#define dforall(i,c) for(auto i=(c).rbegin(), i != (c).rend(); i--)

// Show vector
template <typename T>
ostream & operator <<(ostream &os, const vector<T> &v) {
    os << "[";
    forn(i, v.size()) {
        if (i > 0) os << ",";
        os << v[i];
    }
    return os << "]";
}

// Show pair
template <typename T1, typename T2>
ostream & operator <<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << "," << p.second << "}";
    return os;
}

// Show set
template <typename T>
ostream & operator <<(ostream &os, const set<T> &s) {
    os << "{";
    for(auto it = s.begin(); it != s.end(); it++){
        if(it != s.begin()) os << ",";
        os << *it;
    }
    return os << "}";
}

// ############################################################### //

int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
	
	int t = 50; // Assign the number of tests that you want
	cout << t << "\n";
	
	mt19937 rng(time(0));

    uniform_int_distribution<long long> dist_x(1000, 1e7); // Chose the range [a,b] that you will generate the numbers
    uniform_int_distribution<int> dist_sum(2, 23); // n+m must be at least 2
    uniform_int_distribution<int> dist_n;

    for (int i = 0; i < t; i++) {
        // Generate x in [1000, 1e9]
        long long x = dist_x(rng);

        // Generate a total sum of n + m <= 40
        int total = dist_sum(rng);

        // Now generate n in [1, total-1], m = total - n
        dist_n = uniform_int_distribution<int>(1, total - 1);
        int n = dist_n(rng);
        int m = total - n;

        // Output test case
        cout << x << " " << n << " " << m << "\n";
    }
}
