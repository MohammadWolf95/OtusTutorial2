#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T,typename... Arguments>
auto filter(const vector<T>&ip_pool,Arguments... args){
    T vec={to_string(args)...};
    vector<T>vec_ip;
    multimap<T,T>multimap_ip;
    for(auto el:ip_pool){
        T str_vec;
        for(int i=0;i<sizeof...(args);i++){
            str_vec.push_back(el.at(i));
        }
        multimap_ip.insert(pair<T,T>(str_vec,el));
    }
    auto ret = multimap_ip.equal_range(vec);
    for(auto it=ret.first;it!=ret.second;++it){
        vec_ip.emplace_back(it->second);
    }
    return vec_ip;
}

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
