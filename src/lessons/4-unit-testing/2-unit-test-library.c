#include "library.h"
#include "utest.h"

UTEST(library, add_positives) {
  float result = add(2.0f, 3.0f);
  ASSERT_NEAR(5.0f, result, 1e-6f);
}

UTEST(library, add_negatives) {
  float result = add(-2.0f, -3.0f);
  ASSERT_NEAR(-5.0f, result, 1e-6f);
}

UTEST(library, Add_mixed) {
  float result = add(-2.0f, 3.0f);
  ASSERT_NEAR(1.0f, result, 1e-6f);
}

UTEST_MAIN()
