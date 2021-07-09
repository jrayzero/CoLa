cmake_minimum_required(VERSION 3.9)
project(CoLa)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

# Note: Codon <-> Seq

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden -pedantic -Wall -Wno-return-type-c-linkage")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fno-limit-debug-info")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
include_directories(.)
include_directories(compiler)

# Stuff copied from Codon
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Get Codon stuff
if (NOT DEFINED CODON_TOP)
   set(CODON_TOP $ENV{CODON_TOP})	
   if (NOT DEFINED CODON_TOP)		
     message(FATAL_ERROR "You must set CODON_TOP environment variable to point to the Codon top level directory.")
   endif ()
endif ()

if (NOT DEFINED CODON_BUILD)
   set(CODON_BUILD $ENV{CODON_BUILD})	
   if (NOT DEFINED CODON_BUILD)
     message(FATAL_ERROR "You must set CODON_BUILD environment variable to point to the Codon build directory.")
   endif ()
endif ()

if (NOT DEFINED CODON_DEP)
   set(CODON_DEP $ENV{CODON_DEP})
   if (NOT DEFINED CODON_DEP)
     message(FATAL_ERROR "You must set CODON_DEP environment variable to point to the Codon dependency directory. In Codon, this is the SEQ_DEP variable.")
   endif ()
endif ()

# DSL
find_library(SEQ seq REQUIRED PATHS ${CODON_BUILD} NO_DEFAULT_PATH)
set (COLA_DSL_CPP cola/compiler/cola.cpp cola/compiler/ptree.cpp)
set (COLA_DSL_HDR cola/compiler/cola.h cola/compiler/ptree.h)
add_library (cola SHARED ${COLA_DSL_CPP} ${COLA_DSL_HDR})
target_include_directories(cola PUBLIC ${CODON_TOP} ${CODON_TOP}/compiler)
target_link_libraries(cola ${STATIC_LIBCPP} ${SEQ} Threads::Threads)

# Cola command-line compiler
add_executable(colac cola/runtime/main.cpp)
target_include_directories(colac PUBLIC ${CODON_DEP}/include)
target_link_libraries(colac ${STATIC_LIBCPP} cola ${SEQ} Threads::Threads)
