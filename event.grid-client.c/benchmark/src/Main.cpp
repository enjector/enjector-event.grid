#include <benchmark/benchmark.h>

#include <event.grid/client/node_client.h>

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state) std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state) std::string copy(x);
}
BENCHMARK(BM_StringCopy);

static void BM_Node(benchmark::State& state) {
  std::string x = "hello1";
  for (auto _ : state) std::string copy(x);
}

BENCHMARK(BM_Node);

BENCHMARK_MAIN();