#ifndef FILTER_H
#define FILTER_H

#include <vector>
using namespace std;

template <typename T,typename... Arguments>
auto filter(const vector<T>&ip_pool,Arguments... args);

#include "filter.hpp"

#endif // FILTER_H
