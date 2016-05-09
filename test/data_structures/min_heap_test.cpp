#include "../../data_structures/min_heap.hpp"

namespace min_heap_test {

  TEST_CASE( "Basic FIFO operations maintains min ordering", "[min_heap]" ) {
    MinHeap<int> h;

    REQUIRE( h.size() == 0 );

    h.insert(5);
    REQUIRE( h.peek() == 5 );

    h.insert(4);
    REQUIRE( h.peek() == 4 );

    h.insert(6);
    REQUIRE( h.peek() == 4 );

    REQUIRE( h.pop() == 4 );
    REQUIRE( h.pop() == 5 );
    REQUIRE( h.pop() == 6 );

    for(int i=0; i<500; i++){
      h.insert(rand() % 100);
    }
    for(int i=0; i<h.size(); i++){
      REQUIRE( h.pop() <= h.peek() );
    }
  }

}
