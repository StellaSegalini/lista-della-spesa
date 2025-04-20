cmake_minimum_required(VERSION 3.14)
project(lista_spesa)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)
enable_testing()

#codice sorgente
add_executable(lista_spesa Item.cpp ShoppingList.cpp User.cpp main.cpp)

#test
add_executable(lista_spesa_tests test/test_shopping_list.cpp test/UserTest.cpp test/ItemTest.cpp ShoppingList.cpp Item.cpp User.cpp)

target_link_libraries(lista_spesa_tests gtest gtest_main pthread)
target_include_directories(lista_spesa_tests PRIVATE ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/test
${gtest_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(lista_spesa_tests)