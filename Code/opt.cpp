#include <iostream>
#include <vector>
using namespace std;


class OPT {
    private:
        vector<int> pages;
        int MAX_PAGES;
    public:
        OPT(int MAX_PAGES);

        int check_for_hit(vector<int> reference_string);
        int replace_page(vector<int> reference_string);
};

OPT::OPT(int MAX_PAGES = 4)
{
    this->MAX_PAGES = MAX_PAGES;
}

int OPT::check_for_hit(vector<int> reference_string){
    for (int i = 0; i < this->pages.size(); i++)
    {
        if (this->pages[i] == reference_string[0])
        {
            return 1;
        }
    }

    this->replace_page(reference_string);
    return 0;
}

int OPT::replace_page(vector<int> reference_string){
    if (this->pages.size() >= this->MAX_PAGES) 
    {
        this->pages.erase(this->pages.begin()); // working as a LRU, just checking the ways to use a vector
    }
    this->pages.push_back(reference_string.front());
    for (int i = 0; i < this->pages.size(); i++)
    {
        cout<< this->pages[i] << " ";
    }
    cout << endl;
    return 0;
}

int main(){
    vector<int> reference_string;
    reference_string.push_back(1);
    reference_string.push_back(8);
    reference_string.push_back(1);
    reference_string.push_back(6);
    reference_string.push_back(2);
    reference_string.push_back(4);
    reference_string.push_back(3);
    reference_string.push_back(4);

    OPT memory(4);
    for (int i = 0; i < 8; i++)
    {
        memory.check_for_hit(reference_string);
        reference_string.erase(reference_string.begin());
    }
    
}