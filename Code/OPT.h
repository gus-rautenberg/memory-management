#ifndef OPT_H
#define OPT_H

#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class OPT {
    private:
        vector<int> pages;
        vector<int> next_appearence;
        int miss = 0;
        int MAX_PAGES;

        int replace_page(vector<int> reference_string, int index);
        int find_next(vector<int> reference_string, int n, int index);
        int find_furthest();
        int check_for_hit(vector<int> reference_string, int index);

    public:
        OPT(int MAX_PAGES = 4);
        ~OPT();

        int count_misses(vector<int>& ReferenceString);
};

#endif