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

        int replace_page(vector<int> reference_string);
        int find_next(vector<int> reference_string, int n);
        int find_furthest();
        void subtract_from_next_appearence();        
        int check_for_hit(vector<int> reference_string);

    public:
        OPT(int MAX_PAGES = 4);
        ~OPT();

        int count_misses(vector<int>& ReferenceString);
};

#endif