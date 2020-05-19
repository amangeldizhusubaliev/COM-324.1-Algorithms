#include <bits/stdc++.h>
#include "algol.h"

using namespace std;

void print_vector(const vector<int>& a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    srand(time(0));
    vector<int> v, w;
    for (int i = 0; i < 10; i++) {
        v.emplace_back(rand() % 100);
    }
    cout << "random vector:\n";
    print_vector(v);

    w = v;
    algol::insertion_sort(w);
    cout << "insertion sort:\n";
    print_vector(w);

    w = v;
    algol::merge_sort(w);
    cout << "merge sort:\n";
    print_vector(w);
    
    w = v;
    algol::quick_sort(w);
    cout << "quick sort:\n";
    print_vector(w);
    
    w = v;
    algol::count_sort(w);
    cout << "count sort:\n";
    print_vector(w);
}