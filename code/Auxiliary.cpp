#include "Auxiliary.h"

bool Auxiliary::compare_sorted_lists(const std::vector<std::string>& list, const std::vector<std::string>& element) {
    return 1;
}

bool Auxiliary::if_element_is_in_list(const std::list<std::string>& list, const std::string& element) {
    for (const std::string& list_element : list) {
        if (list_element == element) {
            return true;
        }
    }
    return false;
}