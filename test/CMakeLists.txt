message("Building Albikar Editor tests")

# Define a function for adding a test suite
function(add_test_suite target_name test_sources library_dependencies include_directories)
  # Create test target
  set(TEST_SUITE_NAME albikar-editor-test-suite-${target_name})
  add_executable(${TEST_SUITE_NAME} ${test_sources})
  target_link_libraries(${TEST_SUITE_NAME} gtest gmock ${library_dependencies})
  target_include_directories(${TEST_SUITE_NAME} PUBLIC ${include_directories})
  gtest_discover_tests(${TEST_SUITE_NAME})

  # Add the target_name to the list
  list(APPEND TEST_EXECUTABLE_LIST ${TEST_SUITE_NAME})
  set(TEST_EXECUTABLE_LIST ${TEST_EXECUTABLE_LIST} CACHE INTERNAL "List of test targets" FORCE)
endfunction()