#ifndef FILTER_IMPL_HPP
#define FILTER_IMPL_HPP

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

#endif //FILTER_IMPL_HPP
