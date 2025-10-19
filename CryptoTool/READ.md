这是一个基于C++17的文件加密工具，使用凯撒密码算法对文件进行加密和解密操作。项目采用面向对象设计，包含完整的CMake构建系统。
文件结构：
CryptoTool/
|----CMakeLists.txt
|----include/                              //这是头文件
|      |--Crypto.h
|      |--Filehandler.h
|      '--EncryptorApp.h             //含有要求中的menu，并承担了集成不同模块的任务以保证main的简洁
|----src/                                    //这是C++
|      |--Crypto.cpp
|      |--Filehandler.cpp
|      |--EncryptorApp.cpp
|      '--main.cpp
'----README.md
设计思路为按要求分开构建不同模块，最终集成至EncryptorApp再以main启动运行，基于C++17运行，要求Cmake3.22及以上版本
● 使用凯撒密码算法加密文件
● 使用相同密钥解密文件
● 支持任意类型的文件加密
构建完成后，可执行文件将生成在build/bin/目录中。

构建步骤
克隆项目
git clone <仓库地址>
cd CryptoTool

创建构建目录
mkdir build
cd build

配置项目
cmake ..

编译项目
cmake --build .
# 或者使用 make
make

运行指令
./bin/CryptoTool


