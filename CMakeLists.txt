include(CheckCXXCompilerFlag)

project("CppProj" CXX)

cmake_minimum_required(VERSION 3.5)

CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
if (COMPILER_SUPPORTS_CXX14)
    add_compile_options("-std=c++14")
else()
    message(FATAL_ERROR "Compiler ${CMAKE_CXX_COMPILER} has no C++14 support.")
endif()

# Build modes
IF (CMAKE_BUILD_TYPE STREQUAL "Debug")  # 'Debug' mode
    ADD_COMPILE_OPTIONS("-g")
    ADD_COMPILE_OPTIONS("-O1")
    IF (CMAKE_COMPILER_IS_GNUCXX)
        ADD_COMPILE_OPTIONS("-ggdb3")
    ELSEIF (CMAKE_CXX_COMPILER_ID EQUAL "Clang")
        ADD_COMPILE_OPTIONS("-fsanitize=address")
        ADD_COMPILE_OPTIONS("-fno-omit-frame-pointer")
ENDIF()
ELSEIF (CMAKE_BUILD_TYPE STREQUAL "Release") # "Release" mode
    ADD_COMPILE_OPTIONS("-O2")
ENDIF()


set(CMAKE_CXX_COMPILER "clang++")

# Flag aggiuntive
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
add_definitions("${GCC_COVERAGE_COMPILE_FLAGS}")

SET(WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/lib)


INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

FILE(GLOB_RECURSE SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp" )
FILE(GLOB_RECURSE testing_sources "${PROJECT_SOURCE_DIR}/test/*.cpp")


ADD_EXECUTABLE(CppProj ${SRCS}) # compile command
ADD_EXECUTABLE(Test ${testing_sources}) # compile command
target_link_libraries(Test Catch)


# Documentazione
ADD_CUSTOM_TARGET( doc
    
    COMMAND doxygen ${PROJECT_SOURCE_DIR}/doxygen.cfg 
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/doc"
    COMMENT "Generazione documentazione"
)

# Remove
ADD_CUSTOM_TARGET(rm 
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/bin/CppProj
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/CppProj
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/bin/Test
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/doc/*
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/CMakeCache.txt
    COMMAND rm -rf ${PROJECT_SOURCE_DIR}/.clang-format
    
    COMMENT "Puliti CMAKE, Documentazione e build"
)


INSTALL (   
    FILES ${PROJECT_SOURCE_DIR}/build/bin/Test ${PROJECT_SOURCE_DIR}/build/bin/CppProj
    DESTINATION ${PROJECT_SOURCE_DIR}/bin/
)


# Valgrind
ADD_CUSTOM_TARGET(valgrind 
    COMMAND valgrind ${PROJECT_SOURCE_DIR}/bin/CppProj ${ARGS}
        ${PROJECT_SOURCE_DIR}/matA
        ${PROJECT_SOURCE_DIR}/matB
        ${PROJECT_SOURCE_DIR}/matC
    COMMENT "Valgrind..."
)

ADD_CUSTOM_TARGET(format
    COMMAND clang-format -style=llvm -dump-config > .clang-format
    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/src/*.cpp
    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/include/*.hpp
    COMMAND clang-format -i ${PROJECT_SOURCE_DIR}/test/*.cpp
    COMMENT "Clang-format eseguito"
)

ENABLE_TESTING()

ADD_TEST(NAME Test
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test
    COMMAND ${PROJECT_SOURCE_DIR}/build/bin/Test -r xml -o ${PROJECT_SOURCE_DIR}/test/test_report.xml
)