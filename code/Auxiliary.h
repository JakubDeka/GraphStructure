#pragma once
#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <vector>
#include <string>
#include <list>
#include <map>
#include <iostream>

class Auxiliary
{
public:
    static bool compare_sorted_lists(const std::vector<std::string>&, const std::vector<std::string>&);
    static bool if_element_is_in_list(const std::list<std::string>&, const std::string&);
    //static std::string argminMap(std::map<std::string, double>);
    static void print_matrix(const std::vector<std::vector<double>>&);
};

#endif