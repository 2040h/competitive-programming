// Custom sorting para un set

struct CustomComparator{
	bool operator()(pair<int, ll> a, pair<int, ll> b) const{
		if (a.fst != b.fst) return a.fst > b.fst;
		return a.snd < b.snd;
	}
};

set<pair<int, ll>, CustomComparator> s;