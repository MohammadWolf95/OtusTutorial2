#include "filter.h"

vector<vector<string>> filter_any(const vector<vector<string>>&ip_pool, int find_byte){
    vector<vector<string>>vec;
    for(const auto&i:ip_pool){
        auto it = find(i.begin(), i.end(), to_string(find_byte));
        if(it!=i.end())
            vec.emplace_back(i);
    }
    return vec;
}

void printv(vector<vector<string>>&ip_pool){
    auto it_ip_pool = ip_pool.begin();
    for(auto&i:ip_pool){
        auto it_ip_part = i.begin();
        for(auto&j:i){
            if(it_ip_part!=i.cbegin()){
                cout<<".";
            }
            cout<<j;
            ++it_ip_part;
        }
        cout<<endl;
        ++it_ip_pool;
    }
}
