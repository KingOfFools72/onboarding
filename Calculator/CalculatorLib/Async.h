#pragma once

template<typename Container>
struct aggregate_values
{
    typedef Container result_type;

    template<typename InputIterator>
    Container operator()(InputIterator first, InputIterator last) const
    {
        Container values;
        std::pair<int, int> res;
        int id = 0;
        while (first != last) {
            res = std::pair<int, int>{ id,*first };
            values.push_back(res);
            ++first;
        }
        return values;
    }
};