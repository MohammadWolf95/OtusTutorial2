#include <printv.h>

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
