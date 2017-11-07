cmake_minimum_required(VERSION 3.2.2)

set(WHEREAMI_SOURCES
    whereami.cc
)

# Set compiler-specific flags based on project settings.
set(CMAKE_CXX_FLAGS "${${PROJECT_NAME_UPPER}_CXX_FLAGS} -g")

# Set prefix for logging messages.
leatherman_logging_namespace("puppetlabs.${PROJECT_NAME}")

include_directories(
    ../lib/inc # the libwhereami headers
    ${Boost_INCLUDE_DIRS}
    ${YAMLCPP_INCLUDE_DIRS}
    ${LEATHERMAN_RUBY_INCLUDE}
    ${LEATHERMAN_FILE_UTIL_INCLUDE}
    ${LEATHERMAN_UTIL_INCLUDE}
    ${LEATHERMAN_NOWIDE_INCLUDE}
    ${CPPHOCON_INCLUDE_DIRS}
)

link_directories(
    ${CPPHOCON_LIBRARY_DIRS}
)

add_executable(whereami ${WHEREAMI_SOURCES})

target_link_libraries(${PROJECT_NAME} lib${PROJECT_NAME}
    ${LEATHERMAN_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    )

leatherman_install(${PROJECT_NAME})
