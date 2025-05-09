#===============================#
# * COMPLEXNUMBER APPLICATION  *
#===============================#

# 要求最低的CMake版本
cmake_minimum_required(VERSION 3.2)

#=====================================#
# * PROJECT DESCRIPTION AND META INFO
#=====================================#
# 设定一些变量
set(COMPLEXNUMBER_PROJECT_NAME        "ComplexNumber")
set(COMPLEXNUMBER_PROJECT_DESCRIPTION "Implementation of a complex numbers class")
set(COMPLEXNUMBER_AUTHOR_DOMAIN       "")
set(COMPLEXNUMBER_AUTHOR_MAINTAINER   "")
set(COMPLEXNUMBER_VERSION_MAJOR       "0")
set(COMPLEXNUMBER_VERSION_MINOR       "0")
set(COMPLEXNUMBER_VERSION_PATCH       "1")
set(COMPLEXNUMBER_VERSION             "${COMPLEXNUMBER_VERSION_MAJOR}.${COMPLEXNUMBER_VERSION_MINOR}.${COMPLEXNUMBER_VERSION_PATCH}")
set(COMPLEXNUMBER_NAME_VERSION        "${COMPLEXNUMBER_PROJECT_NAME} v${COMPLEXNUMBER_VERSION} (${COMPLEXNUMBER_VERSION_REVISION})")

#=====================================#
### DECLARE PROJECT
#=====================================#
# 项目名称
project(${COMPLEXNUMBER_PROJECT_NAME})

# C++ 标准, 如果不注明, 则默认是C++14
#set(CMAKE_CXX_STANDARD 17)

# 设置目录
# ${PROJECT_SOURCE_DIR} 为cmake命令执行时所在的目录
# 下面分别设置源代码目录src和包含目录include

set(COMPLEXNUMBER_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(COMPLEXNUMBER_INC_DIR ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#添加子目录, 注意子目录中必须要有CMakeLists.txt
add_subdirectory(src)