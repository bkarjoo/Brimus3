cmake_minimum_required(VERSION 3.6)
project(Brimus3)

set(CMAKE_CXX_STANDARD 14)

#set(BOOST_ROOT /Users/SuperMac/devel/cpp/boost_1_63_0/build)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} C:/Users/b.karjoo/Documents/boost_1_63_0/lib64-msvc-14.0)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /Users/SuperMac/devel/cpp/boost_1_63_0/build/lib)
set(Boost_INCLUDE_DIR C:/Users/b.karjoo/Documents/boost_1_63_0)
#set(Boost_INCLUDE_DIR /Users/SuperMac/devel/cpp/boost_1_63_0/build/include)
set(BOOST_LIBRARYDIR C:/Users/b.karjoo/Documents/boost_1_63_0/lib64-msvc-14.0)
#set(BOOST_LIBRARYDIR /Users/SuperMac/devel/cpp/boost_1_63_0/build/lib)
set (Boost_USE_STATIC_LIBS OFF)
find_package(Boost 1.63.0 COMPONENTS program_options system filesystem thread REQUIRED)

set(SOURCE_FILES main.cpp)

add_executable(Brimus3 ${SOURCE_FILES} cparse/shunting-yard.cpp cparse/packToken.cpp cparse/functions.cpp cparse/objects.cpp cparse/builtin-features.cpp)

include_directories(cparse cparse/builtin-features)
include_directories(${Boost_INCLUDE_DIR})
include_directories(Brimus)

add_subdirectory(cparse)
add_subdirectory(Brimus)
add_subdirectory(Brimus-Test)

target_link_libraries(Brimus3 Brimus ${Boost_FILESYSTEM_LIBRARY} ${Boost_LIBRARIES})
