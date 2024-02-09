#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class OPT {
    private:
        vector<int> pages;
        vector<int> next_appearence;
        int MAX_PAGES;
    public:
        OPT(int MAX_PAGES);
        ~OPT();

        int check_for_hit(vector<int> reference_string){
            cout << reference_string[0] << endl;
            for (int i = 0; i < this->pages.size(); i++)
            {
                cout << this->pages[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < this->pages.size(); i++)
            {
                cout << this->next_appearence[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < reference_string.size(); i++)
            {
                cout << reference_string[i] << " ";
            }
            
            cout << endl;

            for (int i = 0; i < this->pages.size(); i++)
            {
                if (this->pages[i] == reference_string[0])
                {
                    this->next_appearence[i] = this->find_next(reference_string, reference_string[0]);
                    this->subtract_from_next_appearence();
                    return 1;
                }
            }

            this->replace_page(reference_string);
            this->subtract_from_next_appearence();
            return 0;
        };

        int replace_page(vector<int> reference_string){
            if (this->pages.size() >= this->MAX_PAGES) 
            {
                int index_to_erase = this->find_furthest();
                this->pages.erase(this->pages.begin() + index_to_erase);
                this->next_appearence.erase(this->next_appearence.begin() + index_to_erase);
            }
            this->pages.push_back(reference_string.front());
            this->next_appearence.push_back(this->find_next(reference_string, reference_string[0]));

            return 0;
        };

        int find_next(vector<int> reference_string, int n){
            for (int i = 1; i < reference_string.size(); ++i) {
                if (reference_string[i] == n) {

                    return i;
                }
            }

            return std::numeric_limits<int>::max();
        };

        int find_furthest(){
            int max_index = 0;
            int max_int = this->next_appearence[1];
            for (int i = 1; i < this->next_appearence.size(); i++)
            {
                if (this->next_appearence[i] > max_int)
                {
                    max_int = this->next_appearence[i];
                    max_index = i;
                }
            }

            return max_index;    
        };

        void subtract_from_next_appearence(){
            for (int i = 0; i < this->next_appearence.size(); i++)
            this->next_appearence[i]--;
        };
};

OPT::OPT(int MAX_PAGES = 4)
{
    this->MAX_PAGES = MAX_PAGES;
}

OPT::~OPT(){
    cout << "OPT destroyed" << endl;
}

/* 
    EXAMPLE CODE

    vector<int> reference_string;    
    OPT memory(4);
    for (int i = 0; i < array_size(); i++)
    {
        memory.check_for_hit(reference_string) >= 1 ? cout << "hit" : cout << "miss";
        cout << endl << endl;
        
        reference_string.erase(reference_string.begin());
    } 
*/