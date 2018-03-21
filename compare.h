#ifndef COMPARE_H
#define COMPARE_H

#include <vector>
#include <string>

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

#endif // COMPARE_H
