#include "OPT.h"

OPT::OPT(int MAX_PAGES)
{
    this->MAX_PAGES = MAX_PAGES;
}

OPT::~OPT(){
    cout << "OPT with " << this->pages.size() << " pages destroyed" << endl;
}

int OPT::check_for_hit(vector<int> reference_string, int index){
    // cout << reference_string[index] << " " << index <<  endl;

    // for (int i = 0; i < this->pages.size(); i++){
    //     cout << this->pages[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < this->pages.size(); i++){
    //     cout << this->next_appearence[i] << " ";
    // }
    // cout << endl;

        
    // cout << endl << endl;

    for (int i = 0; i < this->pages.size(); i++){
        if (this->pages[i] == reference_string[index]) {
            this->next_appearence[i] = this->find_next(reference_string, reference_string[index], index);
            return 1;
        }
    }

    this->replace_page(reference_string, index);
    this->miss++;
    return 0;
}

int OPT::replace_page(vector<int> reference_string, int index){
    if (this->pages.size() >= this->MAX_PAGES) {
        int index_to_erase = this->find_furthest();
        this->pages.erase(this->pages.begin() + index_to_erase);
        this->next_appearence.erase(this->next_appearence.begin() + index_to_erase);
    }

    this->pages.push_back(reference_string[index]);
    this->next_appearence.push_back(this->find_next(reference_string, reference_string[index], index));
    return 0;
}

int OPT::find_next(vector<int> reference_string, int n, int index){
    for (int i = index+1; i < reference_string.size(); ++i) {
        if (reference_string[i] == n) {
            return i;
        }
    }
    return numeric_limits<int>::max();
}

int OPT::find_furthest(){
    int furthest_index = 0;
    int furthest = this->next_appearence[0];
    for (int i = 1; i < this->next_appearence.size(); i++){
        if (this->next_appearence[i] > furthest){
            furthest = this->next_appearence[i];
            furthest_index = i;
        }
    }

    return furthest_index; 
}

int OPT::count_misses(vector<int>& ReferenceString){
    vector<int> reference_string = ReferenceString;

    for (int i = 0; i < ReferenceString.size(); i++)
        this->check_for_hit(reference_string, i);

    return this->miss;
}