TEST_CASE( "Basic FIFO heap operations", "[heap]" ) {
  Heap h;

  REQUIRE( h.size() == 0 );

  h.insert(5);
  h.insert(7);

  REQUIRE( h.size() == 2 );
  REQUIRE( h.peek() == 5 );
  REQUIRE( h.pop() == 5 );
  REQUIRE( h.peek() == 7 );

  h.insert(9);

  REQUIRE( h.peek() == 7 );
  REQUIRE( h.pop() == 7);
  REQUIRE( h.size() == 1 );
  REQUIRE( h.peek() == 9 );
}
