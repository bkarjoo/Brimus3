
add_executable(CParse builtin-features.cpp catch.hpp catch.hpp functions.cpp objects.cpp packToken.cpp shunting-yard.cpp test-shunting-yard.cpp)

add_subdirectory(builtin-features)