#ifndef PCH_H
#define PCH_H

#include <array>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>
#include <unordered_map>

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

#endif // PCH_H
