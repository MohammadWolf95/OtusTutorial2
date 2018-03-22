#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include "filter.h"

using namespace std;

vector<string> split(const string&str, char d){
    vector<string> r;

    string::size_type start = 0;
    string::size_type stop = str.find_first_of(d);

    while(stop!=string::npos){
        r.push_back(str.substr(start, stop-start));

        start = stop+1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int main(int argc, char *argv[])
{
    try{
        vector<vector<string>> ip_pool;

        for(string line; getline(cin, line);){
            vector<string> v=split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        qsort(&ip_pool[0], ip_pool.size(), sizeof(vector<string>), compare);
        reverse(ip_pool.begin(), ip_pool.end());
        cout<<endl<<"Sorted ip addresses in reverse order"<<endl;
        printv(ip_pool);

        auto vec = filter(ip_pool,1);
        cout<<"TODO filter by first byte and output"<<endl;
        printv(vec);

        cout<<"TODO filter by first and second bytes and output"<<endl;
        auto vec1 = filter(ip_pool, 46, 70);
        printv(vec1);

        cout<<"TODO filter by any byte and output"<<endl;
        auto vec2 = filter_any(ip_pool, 46);
        printv(vec2);
    }

    catch(const exception&e){
        cerr<<e.what()<<endl;
    }
}
