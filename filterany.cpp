#include <filterany.h>

vector<vector<string>> filter_any(const vector<vector<string>>&ip_pool, int find_byte){
    vector<vector<string>>vec;
    for(const auto&i:ip_pool){
        auto it = find(i.begin(), i.end(), to_string(find_byte));
        if(it!=i.end())
            vec.emplace_back(i);
    }
    return vec;
}
