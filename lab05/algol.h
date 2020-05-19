#pragma once

#include <vector>

class algol {
private:
    explicit algol() {}

    static void merge(std::vector<int>& v, std::vector<int>& tmp, int l, int m, int r);
    static void merge_sort_internal(std::vector<int>& v, std::vector<int>& tmp, int l, int r);
    static void swap(int& a, int& b);
    static int partition(std::vector<int>& v, int l, int r);
    static void quick_sort_internal(std::vector<int>& v, int l, int r);
    static void count_keys_equal(std::vector<int>& v, std::vector<int>& e);
    static void count_keys_less(std::vector<int>& e, std::vector<int>& l);
    static void rearrange(std::vector<int>& v, std::vector<int>& l, std::vector<int>& w);

public:
    static int binary_search(std::vector<int>& v, int x);
    static void insertion_sort(std::vector<int>& v);
    static void merge_sort(std::vector<int>& v);
    static void quick_sort(std::vector<int>& v);
    static void count_sort(std::vector<int>& v);
};
