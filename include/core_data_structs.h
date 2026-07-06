#pragma once

#include <cstdint>

enum class orderSide{
    Bid,
    Ask
};

struct order{
    std::uint64_t orderID;
    std::uint64_t priceLevel;
    std::uint64_t quantity;
    
};

struct limitOrder : order{

};

struct marketOrder : order{

};