#===============================#
# * SQUARE_NUMBER APPLICATION  *
#===============================#

# 要求最低的CMake版本
cmake_minimum_required(VERSION 3.2)

#=====================================#
# * PROJECT DESCRIPTION AND META INFO
#=====================================#
# 设定一些变量
set(SQUARE_NUMBER_PROJECT_NAME        "square_number")
set(SQUARE_NUMBER_PROJECT_DESCRIPTION "Find square number which consist of ten different digits.")
set(SQUARE_NUMBER_AUTHOR_DOMAIN       "")
set(SQUARE_NUMBER_AUTHOR_MAINTAINER   "")
set(SQUARE_NUMBER_VERSION_MAJOR       "0")
set(SQUARE_NUMBER_VERSION_MINOR       "0")
set(SQUARE_NUMBER_VERSION_PATCH       "1")
set(SQUARE_NUMBER_VERSION             "${SQUARE_NUMBER_VERSION_MAJOR}.${SQUARE_NUMBER_VERSION_MINOR}.${SQUARE_NUMBER_VERSION_PATCH}")
set(SQUARE_NUMBER_NAME_VERSION        "${SQUARE_NUMBER_PROJECT_NAME} v${SQUARE_NUMBER_VERSION} (${SQUARE_NUMBER_VERSION_REVISION})")

#=====================================#
### DECLARE PROJECT
#=====================================#
# 项目名称
project(${SQUARE_NUMBER_PROJECT_NAME})

# C++ 标准, 如果不注明, 则默认是C++14
#set(CMAKE_CXX_STANDARD 17)

# 设置目录
# ${PROJECT_SOURCE_DIR} 为cmake命令执行时所在的目录
# 下面分别设置源代码目录src和包含目录include

set(SQUARE_NUMBER_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(SQUARE_NUMBER_INC_DIR ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#添加子目录, 注意子目录中必须要有CMakeLists.txt
add_subdirectory(src)