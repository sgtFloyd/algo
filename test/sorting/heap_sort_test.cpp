#include "../../sorting/heap_sort.hpp"

namespace heap_sort_test {

  TEST_CASE( "Sort a known list of integers", "[heap_sort]" ) {
    int vals[] = { 12,43,8,0,17,4,13,13,4,0,7,6,1,54 };
    std::vector<int> unsorted(std::begin(vals), std::end(vals));
    std::vector<int> heap_sorted = HeapSort<int>::sort(unsorted);

    REQUIRE( std::is_sorted(heap_sorted.begin(), heap_sorted.end()) );
  }

  TEST_CASE( "Sort an already-sorted list of integers", "[heap_sort]" ) {
    int vals[] = { 0,1,1,2,3,5,8,13,21,34,34,34 };
    std::vector<int> unsorted(std::begin(vals), std::end(vals));
    std::vector<int> heap_sorted = HeapSort<int>::sort(unsorted);
    REQUIRE( std::is_sorted(heap_sorted.begin(), heap_sorted.end()) );
  }

  TEST_CASE( "Sort a random list of integers", "[heap_sort]" ) {
    std::vector<int> unsorted;
    for(int i=0; i<100000; i++){
      unsorted.push_back(rand() % 500);
    }

    std::vector<int> heap_sorted = HeapSort<int>::sort(unsorted);
    REQUIRE( std::is_sorted(heap_sorted.begin(), heap_sorted.end()) );
  }

}
