#include "../src/objects/obstracle.h"

#test two_equal_obstracles
    Hindernis *a = createHindernis(80, 20);
    int expected = 1;
    int result = equals(a, 80, 20);
    ck_assert_int_eq(result, expected);

#test one_different_coordinate
    Hindernis *a = createHindernis(80, 20);
    int expected = 0;
    int result = equals(a, 70, 20);
    ck_assert_int_eq(result, expected);

#test two_different_coordinates
    Hindernis *a = createHindernis(80, 20);
    int expected = 0;
    int result = equals(a, 70, 10);
    ck_assert_int_eq(result, expected);
