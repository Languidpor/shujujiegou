#======================================#
# * SQUARE_NUMBER APPLICATION  *
#======================================#
#  path: src/CMakeLists.txt 
#--------------------------------------#

# 将当前目录下所有源码文件添加到变量 SQUARE_NUMBER_src
#aux_source_directory(. SQUARE_NUMBER_src)

# 生成可执行文件
#add_executable(${SQUARE_NUMBER_PROJECT_NAME} ${SQUARE_NUMBER_src})

# 或者使用下面的方式
add_executable(${SQUARE_NUMBER_PROJECT_NAME}
        ${SQUARE_NUMBER_SRC_DIR}/main.cpp)
#        ${SQUARE_NUMBER_SRC_DIR}/otherfiles.cpp
#        )   # Don't forget the closing parenthesis at the end.
# -------------------------------------------

# 头文件搜索的路径
include_directories(${SQUARE_NUMBER_INC_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)