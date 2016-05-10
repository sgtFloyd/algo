#include "../../data_structures/heap.hpp"

namespace heap_test {

  TEST_CASE( "Basic FIFO heap operations", "[heap]" ) {
    Heap<int> h;

    REQUIRE( h.size() == 0 );

    h.insert(3);
    h.insert(5);
    h.insert(7);

    REQUIRE( h.size() == 3 );
    REQUIRE( h.peek() == 3 );
    REQUIRE( h.pop() == 3 );
    REQUIRE( h.peek() == 5 );

    h.insert(9);

    REQUIRE( h.peek() == 5 );
    REQUIRE( h.pop() == 5);
    REQUIRE( h.size() == 2 );
    REQUIRE( h.peek() == 7 );
  }

}
