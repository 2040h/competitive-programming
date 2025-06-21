vector<int> merge(vector<int> &arr1, vector<int> &arr2){
    int n = SIZE(arr1);
    int m = SIZE(arr2);
    int t = n + m;
    vector<int> res(t);

    int j = 0;
    int h = 0;

    forn(i, t){
        if (j < n && h < m){
            if (arr1[j] <= arr2[h]){
                res[i] = arr1[j];
                j++;
            } else {
                res[i] = arr2[h];
                h++;
            }
        } else if (j < n) {
            res[i] = arr1[j];
            j++;
        } else {
            res[i] = arr2[h];
            h++;
        }
    }

    return res;
}

vector<int> mergeSort(vector<int> &arr){   
    // Worst and best case: O(n * log n)
    // The algorithm is stable but not in place

    int n = SIZE(arr);

    if (n <= 1) return arr;
    
    int mid = n / 2;
    vector<int> leftHalf, rightHalf;

    forn(i, mid) leftHalf.push_back(arr[i]);
    forsn(i, mid, n) rightHalf.push_back(arr[i]);
    
    vector<int> res1 = mergeSort(leftHalf);
    vector<int> res2 = mergeSort(rightHalf);
    return merge(res1, res2);
}

