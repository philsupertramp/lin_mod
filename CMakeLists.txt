cmake_minimum_required(VERSION 3.7.2)

project(ccc C)

set(SOURCES
  lib/typedef.h
  lib/array.c lib/array.h
  lib/styling.h lib/styling.c
  lib/matrix.c lib/matrix.h
  lib/plot.c lib/plot.h
  lib/vector.c lib/vector.h
  lib/stat/stat.c lib/stat/stat.h
  lib/stat/insurance.c lib/stat/insurance.h
  lib/nn/neural_network.c lib/nn/neural_network.h
  )

set(MAIN_SOURCES
  main.c
  )

set(TEST_SOURCES
  tests/test_array.h
  tests/test_main.c
  tests/test_stat.h
  tests/test_styling.h
  tests/test_matrix.h
  tests/test_neural_network.h
  tests/test_insurance.h
  )

add_executable(ccc ${SOURCES} ${MAIN_SOURCES})
add_executable(ccc-test ${SOURCES} ${TEST_SOURCES})

target_link_libraries(ccc m)
target_link_libraries(ccc-test m)

