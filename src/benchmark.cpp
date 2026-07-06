#include <benchmark/benchmark.h>

static void BM_Benchmark(benchmark::State& state) {
    //Setup here isnt measured

    for (auto _ : state) {
        //Inside the loop is measured

    }
}

BENCHMARK(BM_Benchmark);

BENCHMARK_MAIN();