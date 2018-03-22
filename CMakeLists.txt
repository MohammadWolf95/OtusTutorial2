cmake_minimum_required(VERSION 3.2)

project(IpFilter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED) 

configure_file(version.h.in version.h)

add_executable(ip_filter main.cpp)

add_library(Filters filter.cpp)

add_executable(test_main test_main.cpp)

set_target_properties(ip_filter test_main PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTIONS -Wpedantic -Wall -Wextra -std=c++11 -std=c++14
)

set_target_properties(test_main PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip_filter Filters)

target_link_libraries(test_main
  ${Boost_LIBRARIES}
  Filters
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT abdulvadudovmagomed@mail.ru)

include(CPack)

enable_testing()

add_test(test_version_valid test_main)