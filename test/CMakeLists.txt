add_executable( connector_test connector_test.cpp )
target_link_libraries( connector_test gmd boost_system pthread )

add_executable( publisher_test publisher_test.cpp )
target_link_libraries( publisher_test gmd boost_system pthread )

add_executable( stress_test stress_test.cpp )
target_link_libraries( stress_test gmd boost_system pthread )

add_executable( conflate_test conflate_test.cpp )
target_link_libraries( conflate_test gmd boost_system pthread )

add_executable( throttle_test throttle_test.cpp )
target_link_libraries( throttle_test gmd boost_system pthread )
