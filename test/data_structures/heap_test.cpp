
TEST_CASE( "Factorials are computed", "[factorial]" ) {
  Heap h;
  h.insert(5);

  REQUIRE( h.peek() == 5 );
}
