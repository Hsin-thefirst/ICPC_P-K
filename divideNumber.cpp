#include <iostream>
#include <set>
#include <vector>

using namespace std;
template <typename T>

void print(T container) {
    for (auto c : container) {
        cout << c << " ";
    }
}

void print(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int sum(vector<int> v) {
    int result = 0;
    for (int i : v) result+=i;
    return result;
}

vector<vector<int>> re;
vector<int> cas;

void call(int n, int k, int de) {
    if (k == 0) {
        if (n == 0 && sum(cas) == de) re.push_back(cas);
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        cas.push_back(i);
        call(n - i, k - 1, de);
        cas.pop_back();
    }
}


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

void sort2DVector (vector<vector<int>> & v) {
    for (vector<int> & vec : v) {
        mergesort(vec, 0, vec.size()-1);
    }
}

void deleteRepeat (vector<vector<int>> & v) {
    sort2DVector(v);
    set<vector<int>> s(v.begin(), v.end());
    v.assign(s.begin(), s.end());
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << "All possible ways:\n";
    call(n,k,n);
    deleteRepeat(re);
    print(re);
    cout << "Number of ways: " << re.size();
    return 0;
}