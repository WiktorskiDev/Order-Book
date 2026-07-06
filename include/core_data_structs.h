#pragma once

#include <cstdint>

enum class OrderSide{
    Bid,
    Ask
};

struct limitOrder{
    std::uint64_t orderID;
    std::uint64_t price;
    std::uint64_t quantity;
    std::uint64_t timestampNs;
    OrderSide side;

    limitOrder(std::uint64_t id, std::uint64_t prc, std::uint64_t qty, std::uint64_t timeNs, OrderSide sd)
        :orderID(id),
        price(prc),
        quantity(qty),
        timestampNs(timeNs),
        side(sd)
        {};
};

struct marketOrder{
    
    std::uint64_t orderID;
    std::uint64_t quantity;
    std::uint64_t timestampNs;
    OrderSide side;

    marketOrder(std::uint64_t id, std::uint64_t qty, std::uint64_t timeNs, OrderSide sd)
        :orderID(id),
        quantity(qty),
        timestampNs(timeNs),
        side(sd)
        {};
};