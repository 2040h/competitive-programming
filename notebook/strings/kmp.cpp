// PI_S[i] := max{k | 1<=k<i and S[0:k-1] = S[i-(k-1):i]}
vi prefix_function_kmp(const string &s) {
	int n = SIZE(s); vi pi_s(n);
	for (int i=1, j=0; i<n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}