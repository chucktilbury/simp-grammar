cmake_minimum_required(VERSION 3.18)
project(simp)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

BISON_TARGET(PARSER
    parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.c
    COMPILE_FLAGS "--report=all --graph=parser.dot -tvdo"
)

FLEX_TARGET(SCANNER
    scanner.l
    ${CMAKE_CURRENT_BINARY_DIR}/scanner.c
    COMPILE_FLAGS "-i"
)

ADD_FLEX_BISON_DEPENDENCY(SCANNER PARSER)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ./)

add_executable(${PROJECT_NAME}
    ${BISON_PARSER_OUTPUTS}
    ${FLEX_SCANNER_OUTPUTS}
    main.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
)

target_link_libraries(${PROJECT_NAME}
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wno-sign-compare
        -Wno-unused-variable
        -Wno-parentheses-equality
        #$<$<CONFIG:DEBUG>:-g3 >
        $<$<CONFIG:DEBUG>:-g >
        #$<$<CONFIG:DEBUG>:-Og >
        #$<$<CONFIG:DEBUG>:-DMEMORY_DEBUG >
        $<$<CONFIG:DEBUG>:-DENA_TRACE >
        #$<$<CONFIG:DEBUG>:-DENABLE_TRACE >
        $<$<CONFIG:DEBUG>:-DENABLE_DUMP >
        $<$<CONFIG:RELEASE>:-Ofast >
        $<$<CONFIG:PROFILE>:-pg -O0 >
)

set_property(DIRECTORY APPEND PROPERTY 
    ADDITIONAL_MAKE_CLEAN_FILES
        parser.h 
        parser.output
        parser.dot)
