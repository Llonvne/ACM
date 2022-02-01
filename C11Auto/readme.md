# AutoC11 脚本
## 安装方法 ： 将所有内容放到终端配置文件 例如 .zshrc 或者 .bashrc 等

# 使用方法 ：

1. 使用 g11 代替 g++ std=c++11 来指定C11编译器 （非函数）
1. 使用 c11 函数来自动完成编译xxx.cpp->a.out,运行程序a.out，将a.out->xxx.cpp程序文件改为与源文件同名字
1.  使用 c11c (c11Clean)函数 来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
1.  使用 c11c (c11CleanClear)函数 首先清空终端，然后来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
1.  在前面所有的函数后面补上一个n 来使用无提示的模式，可以保留纯净的输出流,例如 c11n,c11cn,c11ccn
1. 注意：使用__function__ 的函数均为内部函数，请勿直接调用