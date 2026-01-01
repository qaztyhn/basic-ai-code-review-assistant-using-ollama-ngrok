cmake_minimum_required(VERSION 3.10)


set(CMAKE_TOOLCHAIN_FILE "D:/OOP/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(CppReviewer)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

include_directories(include)
include_directories(include/model)
include_directories(include/service)
include_directories(include/infra)
include_directories(include/usecase)
include_directories(include/ui)
include_directories(include/common)

include_directories(${CURL_INCLUDE_DIRS}) 


file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(reviewer ${SOURCES})

target_link_libraries(reviewer PRIVATE CURL::libcurl)

if(EXISTS "${CMAKE_SOURCE_DIR}/data")
    add_custom_command(TARGET reviewer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/data"
        "$<TARGET_FILE_DIR:reviewer>/data"
        COMMENT "Copying data directory..."
    )
endif()