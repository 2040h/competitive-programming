// Custom sorting para un set y pq

struct CustomComparator{
	bool operator()(pair<int, ll> a, pair<int, ll> b) const{
		if (a.fst != b.fst) return a.fst > b.fst;
		return a.snd < b.snd;
	}
};

set<pair<int, ll>, CustomComparator> s;
priority_queue<pair<int, ll>, vector<pair<int, ll>>, CustomComparator> q;
