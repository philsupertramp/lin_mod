cmake_minimum_required(VERSION 3.7.2)

project(ccc C)

set(SOURCES
  lib/array.c lib/array.h
  lib/matrix.c lib/matrix.h
  lib/plot.c lib/plot.h
  lib/stat.c lib/stat.h
  lib/vector.c lib/vector.h
  lib/styling.h
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
  )

add_executable(ccc ${SOURCES} ${MAIN_SOURCES})
add_executable(ccc-test ${SOURCES} ${TEST_SOURCES})
