#pragma once

#include <cstdint>

enum class OrderSide : std::uint8_t{
    Bid,
    Ask
};

struct incomingLimitOrder{
    std::uint64_t orderID; //Id of order max            8 Bytes
    std::uint32_t price;    //price of incoming order   4 Bytes
    std::uint32_t quantity; //amount of items for order 4 Bytes
    OrderSide side; //If its buy or sell order          1 Byte

    //17 Bytes total rounded to 24 Bytes

    incomingLimitOrder(std::uint64_t id, std::uint32_t prc, std::uint32_t qty, OrderSide sde)
        :orderID(id),
        price(prc),
        quantity(qty),
        side(sde)
        {};
};

struct restLimitOrder{
    std::uint64_t orderID;  //8 Bytes
    std::uint32_t quantity; //4 Bytes
    std::uint16_t prev;     //2 Bytes
    std::uint16_t next;     //2 Bytes

    //Total size is 16 Bytes allowing up to 4 rest limit orders to be loaded per 64Byte Cache line to increase cache friendliness

    restLimitOrder(std::uint64_t id, std::uint32_t qty, std::uint16_t prv, std::uint16_t nxt)
        :orderID(id),
        quantity(qty),
        prev(prv),
        next(nxt)
        {};

    restLimitOrder(incomingLimitOrder incomingOrder, std::uint16_t nxt, std::uint16_t prv)
        :orderID(incomingOrder.orderID),
        quantity(incomingOrder.quantity),
        prev(prv),
        next(nxt)
        {};
};



struct marketOrder{
    
    std::uint64_t orderID;      //8 Bytes
    std::uint32_t quantity;     //4 Bytes
    OrderSide side;             //1 Byte

    //13 Bytes rounded to 16 Bytes to allow up to 4 market orders to be loaded per 64 Byte cache line to increase cache friendliness

    marketOrder(std::uint64_t id, std::uint64_t qty, OrderSide sd)
        :orderID(id),
        quantity(qty),
        side(sd)
        {};
};