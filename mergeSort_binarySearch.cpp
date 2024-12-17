#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, int p, int q, int r) {
    int nL = q - p +1;
    int nR = r - q;
    vector<int> L(nL, -1);
    vector<int> R(nR, -1);
    for (int i = 0; i < nL; i++) {
        L[i] = A[p+i];
    }
    for (int j = 0; j < nR; j++) {
        R[j] = A[q+j+1];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while ((i < nL) && (j < nR)) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &v, int p, int r) {
    if (p >= r) return;
    int q = p + (r-p)/ 2 ;
    mergesort(v, p ,q);
    mergesort(v, q+1, r);
    merge(v,p,q,r);
}

template <typename T>

void print(T container) {
    for (auto c : container) {
        cout << c << " ";
    }
}

int binarysearch(vector<int> v, int target) {
    int mid = (v.size() /2);
    if (v.size() == 2) {
        if (v[0] == target) return v[0];
        else if (v[1] == target) return v[1];
        else {
            cout << "\nNOT FOUND";
            return -1;
        }
    }
    if (v[mid] == target) return v[mid];
    else if (v[mid] < target) {
        vector<int> tempv(v.size() - mid - 1);
        for (int i = 0; i < v.size() - mid - 1 ; i++) {
            tempv[i] = v[i+mid+1];
        }
        return binarysearch(tempv, target);
    } else {
        vector<int> tempv(mid+1);
        for (int i = 0; i < mid+1; i++) {
            tempv[i] = v[i];
        }
        return binarysearch(tempv, target);
    }
}

int main() {
    vector<int> v = {12, 3, 7, 9, 14, 6 , 11, 2};
    int r = v.size()-1;
    mergesort(v, 0, r);
    print(v);
    int result = binarysearch(v, 0);
    cout << endl << result;
    return 0;
}