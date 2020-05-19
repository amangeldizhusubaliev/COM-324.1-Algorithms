#include "algol.h"

// Binary Search ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int algol::binary_search(std::vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == x) {
            return m;
        } else if (v[m] > x) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

// Insertion Sort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void algol::insertion_sort(std::vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int key = v[i], j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// Merge Sort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void algol::merge(std::vector<int>& v, std::vector<int>& tmp, int l, int m, int r) {
    for (int a = l, b = m + 1, c = l; a <= m || b <= r; ) {
        if (a <= m && (b > r || v[a] <= v[b])) {
            tmp[c++] = v[a++];
        } else {
            tmp[c++] = v[b++];
        }
    }
    for (int i = l; i <= r; i++) {
        v[i] = tmp[i];
    }
}

void algol::merge_sort_internal(std::vector<int>& v, std::vector<int>& tmp, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort_internal(v, tmp, l, m);
    merge_sort_internal(v, tmp, m + 1, r);
    algol::merge(v, tmp, l, m, r);
}

void algol::merge_sort(std::vector<int>& v) {
    std::vector<int> tmp(v.size());
    algol::merge_sort_internal(v, tmp, 0, v.size() - 1);
}

// Quick Sort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void algol::swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int algol::partition(std::vector<int>& v, int l, int r) {
    int p = l;
    for (int i = l; i < r; i++) {
        if (v[i] <= v[r]) {
            algol::swap(v[p], v[i]);
            p++;
        }
    }
    algol::swap(v[p], v[r]);
    return p;
}

void algol::quick_sort_internal(std::vector<int>& v, int l, int r) {
    if (l >= r) {
        return;
    }
    int p = partition(v, l, r);
    quick_sort_internal(v, l, p - 1);
    quick_sort_internal(v, p + 1, r);
}

void algol::quick_sort(std::vector<int>& v) {
    quick_sort_internal(v, 0, v.size() - 1);
}

// Count Sort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void algol::count_keys_equal(std::vector<int>& v, std::vector<int>& e) {
    for (int i : v) {
        e[i]++;
    }
}

void algol::count_keys_less(std::vector<int>& e, std::vector<int>& l) {
    for (int i = 1; i < e.size(); i++) {
        l[i] = l[i - 1] + e[i];
    }
}

void algol::rearrange(std::vector<int>& v, std::vector<int>& l, std::vector<int>& w) {
    std::vector<int> nxt(l.size());
    for (int i = 0; i < l.size(); i++) {
        nxt[i] = l[i];
    }
    for (int i : v) {
        w[nxt[i]++] = i;
    }
}

void algol::count_sort(std::vector<int>& v) {
    int m = 0;
    for (int i : v) {
        if (i > m) {
            m = i;
        }
    }
    m++;
    std::vector<int> e(m, 0);
    algol::count_keys_equal(v, e);
    std::vector<int> l(m, 0);
    algol::count_keys_less(e, l);
    std::vector<int> w(v.size());
    algol::rearrange(v, l, w);
    v = w;
}