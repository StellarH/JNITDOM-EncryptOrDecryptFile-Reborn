#最低CMake版本
cmake_minimum_required(VERSION 3.5)

# 工程名 Project name
project (indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE release)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

if(MSVC)
	add_compile_options(/W4 /Zc:__cplusplus /utf-8)
else()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "11")
			message(FATAL_ERROR "GNU CXX compiler version is too small !")
		endif()
		add_compile_options(-fsigned-char -finput-charset=UTF-8 -fexec-charset=UTF-8)
	endif()
endif()

add_library(${PROJECT_NAME} SHARED indi_blazing_stellar_jni_TDOMEncryptOrDecryptFileReborn.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/../source-code
	PRIVATE ${PROJECT_SOURCE_DIR}/../include
	PRIVATE ${PROJECT_SOURCE_DIR}/../extra/mio/include
	PRIVATE ${PROJECT_SOURCE_DIR}/../extra/mio/single_include
	PRIVATE ${PROJECT_SOURCE_DIR}/../extra/eigen
	${PROJECT_SOURCE_DIR}/JNIinclude
)
