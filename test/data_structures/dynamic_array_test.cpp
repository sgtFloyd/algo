#include "../../data_structures/dynamic_array.hpp"

namespace dynamic_array_test {

  TEST_CASE( "Basic array access", "[dynamic_array]" ) {
    DynamicArray<int> int_array;

    int_array[0] = 22;
    REQUIRE( int_array[0] == 22 );
    int_array[0] = 33;
    REQUIRE( int_array[0] == 33 );
    int_array[1] = 11;
    REQUIRE( int_array[1] == 11 );

    int_array[45] = 222;
    REQUIRE(int_array[45] == 222);
    REQUIRE(int_array[0] == 33);
    REQUIRE(int_array[1] == 11);

    DynamicArray<std::string> string_array;
    string_array[42] = "Hello World!";
    REQUIRE( string_array[42] == "Hello World!" );
  }

  TEST_CASE( "Nested arrays", "[dynamic_array]" ) {
    DynamicArray<DynamicArray<int>> nested_array;
    nested_array[0][0] = 25;
    nested_array[0][1] = 20;
    nested_array[1][0] = 50;
    REQUIRE(nested_array[0][0] == 25);
    REQUIRE(nested_array[0][1] == 20);
    REQUIRE(nested_array[1][0] == 50);

    DynamicArray<int> new_arr;
    new_arr[0] = -25;
    new_arr[1] = -20;
    nested_array[1] = new_arr;
    REQUIRE(nested_array[0][0] == 25);
    REQUIRE(nested_array[0][1] == 20);
    REQUIRE(nested_array[1][0] == -25);
    REQUIRE(nested_array[1][1] == -20);
  }

}
