/////////////////////////////////////////////////////////////////////////////////////////

#include <array>
#include <cstddef>
#include <list>
#include <memory_resource>

/////////////////////////////////////////////////////////////////////////////////////////

#include <boost/pool/pool_alloc.hpp>

/////////////////////////////////////////////////////////////////////////////////////////

#include <benchmark/benchmark.h>

/////////////////////////////////////////////////////////////////////////////////////////

void test_v1(benchmark::State & state)
{
    for (auto element : state)
    {
        std::list < int > list;

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

void test_v2(benchmark::State & state)
{
    for (auto element : state)
    {
        std::pmr::list < int > list;

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

void test_v3(benchmark::State & state)
{
    for (auto element : state)
    {
        std::pmr::monotonic_buffer_resource resource;

        std::pmr::polymorphic_allocator < int > allocator(&resource);

        std::pmr::list < int > list(allocator);

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

void test_v4(benchmark::State & state)
{
    for (auto element : state)
    {
        std::array < std::byte, 32'000 > array = {};

        std::pmr::monotonic_buffer_resource resource(std::data(array), std::size(array));

        std::pmr::polymorphic_allocator < int > allocator(&resource);

        std::pmr::list < int > list(allocator);

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);    
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

#define BOOST_POOL_NO_MT

/////////////////////////////////////////////////////////////////////////////////////////

void test_v5(benchmark::State & state)
{
    for (auto element : state)
    {
        std::list < int, boost::pool_allocator < int > > list;

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

void test_v6(benchmark::State & state)
{
    for (auto element : state)
    {
        std::list < int, boost::fast_pool_allocator < int > > list;

        for (auto i = 0uz; i < 1'000; ++i) 
        {
            list.push_back(1);
        }

        benchmark::DoNotOptimize(list);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

BENCHMARK(test_v1);

BENCHMARK(test_v2);

BENCHMARK(test_v3);

BENCHMARK(test_v4);

BENCHMARK(test_v5);

BENCHMARK(test_v6);

/////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    benchmark::RunSpecifiedBenchmarks();
}

/////////////////////////////////////////////////////////////////////////////////////////