#include "Auxiliary.h"
#include <map>
#include <iostream>

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

void Auxiliary::print_matrix(const std::vector<std::vector<double>>& matrix) {
    for (std::vector<double> row : matrix) {
        for (double element : row) { std::cout << element << " "; }
        std::cout << "\n";
    }
}
