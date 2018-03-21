#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T,typename... Arguments>
auto filter(const vector<T>&ip_pool,Arguments... args);

#include "filter.hpp"

auto compare = [](const void *a, const void *b)->int
{
    std::vector<std::string>_a=*(std::vector<std::string>*)a;
    std::vector<std::string>_b=*(std::vector<std::string>*)b;
    for(size_t i=0;i<_a.size();i++){
        if(atoi(_a.at(i).c_str())>atoi(_b.at(i).c_str()))
            return true;
        else if(atoi(_a.at(i).c_str())==atoi(_b.at(i).c_str()))
            continue;
        else
            return false;
    }
};

vector<vector<string>> filter_any(const vector<vector<string>>&ip_pool, int find_byte);

void printv(vector<vector<string>>&ip_pool);

#endif // FILTER_H
