cmake_minimum_required(VERSION 3.22)
project(fileEncryptor VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(CryptoTool
	src/main.cpp
	src/Crypto.cpp
	src/Filehandler.cpp
	src/EncryptorApp.cpp
	)
set_target_properties(CryptoTool PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	)


