// D&C version

ll maximumContiguosSumFromMiddle(vector<ll> &A){
    ll res = 0;
    int n = SIZE(A);
    int middle = n/2;
    ll currentLeftSum = A[middle];
    ll currentRightSum = 0;
    ll maximumLeft = A[middle];
    ll maximumRight = 0;

    dforn(j, middle){ 
        currentLeftSum += (ll) A[j];
        maximumLeft = max(maximumLeft, currentLeftSum);
    }

    forsn(j, middle+1, n){
        currentRightSum += (ll) A[j];
        maximumRight = max(maximumRight, currentRightSum);
    }

    res = maximumLeft;
    if (maximumRight > 0) res += maximumRight;

    return res;
}

ll maximumSubArraySum(vector<ll> &A){
    ll res = 0;
    int n = A.size();

    if (A.size() == 1) return A[0];
    else if (A.size() == 0) return NEG_INF; // Esto es para no permitir array vacío

    int middle = n/2;
    vector<ll> left, right;

    forn(i, middle) left.push_back(A[i]);
    forsn(i, middle, n) right.push_back(A[i]);
    
    ll middleSum = maximumContiguosSumFromMiddle(A); 
    ll leftSum = maximumSubArraySum(left);
    ll rightSum = maximumSubArraySum(right);
    res = max(middleSum, max(leftSum, rightSum));
    return res;
}

// ###########################################################################
// DP version
ll maximumSubArraySum(int i, vector<ll> &A, vector<ll> &memo){
    if (i == -1) return 0; 
    if (memo[i] == UNDEFINED) memo[i] = max(A[i], A[i] + maximumSubArraySum(i-1, A, memo));
    return memo[i];
} // res = max(memo[j])

