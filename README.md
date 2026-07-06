# Order Book

This is a C++17 order book project I am starting as a follow-up to my memory allocator project.

The goal is to build a simple but clean order book implementation while learning more about data structures, matching logic, memory layout and benchmarking.

I want this project to help me understand how orders can be stored, matched, cancelled and processed in a predictable way.

## Goals

- Build a basic limit order book
- Use integer prices/ticks instead of floating point prices
- Support adding and cancelling orders
- Preserve price-time priority
- Add matching logic
- Add tests with GoogleTest
- Add benchmarks with Google Benchmark
- Later experiment with custom allocators and ring buffers

## Current status

Initial project setup.

## Planned work

- Define the basic order types
- Add buy and sell side storage
- Add order insertion
- Add cancel support
- Add basic matching
- Add tests
- Add benchmarks
- Add allocator-backed storage and command queues

## Why I am building this

I am using this project to improve my C++ skills and get more comfortable with performance-focused code.

I am especially interested in how data structure choices affect speed, memory use and complexity.