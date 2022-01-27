# AutoC11 脚本
# 安装方法 ： 将所有内容放到终端配置文件 例如 .zshrc 或者 .bashrc 等
# 使用方法 ：
# 1. 使用 g11 代替 g++ std=c++11 来指定C11编译器 （非函数）
# 2. 使用 c11 函数来自动完成编译xxx.cpp->a.out,运行程序a.out，将a.out->xxx.cpp程序文件改为与源文件同名字
# 3. 使用 c11c (c11Clean)函数 来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
# 4. 使用 c11c (c11CleanClear)函数 首先清空终端，然后来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
# 5. 在前面所有的函数后面补上一个n 来使用无提示的模式，可以保留纯净的输出流,例如 c11n,c11cn,c11ccn

### alias

# alias g11 = g++ -std=c++11
alias g11="g++ -std=c++11" 

### function 

# PrintPrefix
__AutoC11PrintWithPrefix__(){
    echo -e "\033[32mAutoC11:\c\033[0m" &&
    echo "$*"
}

# Run Program and Count Time
__AutoC11TimeCount__() {
  local start=$(date +%s) &&
  $@ &&
  local exit_code=$? &&
__AutoC11PrintWithPrefix__ "\033[32m----------------程序运行结束----------------------\033[0m" &&
__AutoC11PrintWithPrefix__ "\033[32m程序花费了 $(($(date +%s)-${start})) 秒. 退出代码 ${exit_code}\033[0m" &&
  return $exit_code
}

# Run Program without Print
__AutoC11TimeCountWithoutPrint__() {
  $@ &&
}

# Complie CPP Source and Run Program
c11run(){
# complie cpp file
__AutoC11PrintWithPrefix__ "\033[32m开始编译源文件!\033[0m" &&
g11 $1 && 
__AutoC11PrintWithPrefix__ "\033[32m源文件编译成功！\033[0m" &&
# Determine if the input file is included and execute it correctly 
__AutoC11PrintWithPrefix__ "\033[32m----------------开始运行程序----------------------\033[0m" &&
__AutoC11TimeCount__ "./a.out"
}

# c11run without Print
c11runWithoutPrint() {
g11 $1 && 
__AutoC11TimeCountWithoutPrint__ "./a.out"
}

# Complie CPP Source and Run Program and rename a.out -> xxx.cpp
c11(){
# using c11run function and
c11run $@ && 
# delete filename of .cpp           
filename=${1%.*cpp} &&   
# add .out to filename
filename+=".out" &&      
# tell user do what
__AutoC11PrintWithPrefix__ "\033[32m输出文件：$filename\033[0m" &&
# rename a.out to $1.out
`mv -f ./a.out "$filename"`
}

# c11 without Print
c11n(){
c11runWithoutPrint $@ &&
# delete filename of .cpp           
filename=${1%.*cpp} &&   
# add .out to filename
filename+=".out" &&
# rename a.out to $1.out
`mv -f ./a.out "$filename"`
}

# Complie CPP Source and Run Program and Delete a.out
c11c(){
# using c11run function
c11run $@ && 
# remove a.out
rm ./a.out 
}

# c11c without Print
c11cn(){
# using c11run function
c11runWithoutPrint $@ && 
# remove a.out
rm ./a.out 
}

# Complie CPP Source and Clear the Window Then Run the Program.
c11cc(){
# clean the windows first
clear &&
# run c11c 
c11c $@
}

# c11cc without Print
c11ccn(){
# clean the windows first
clear &&
# run c11c 
c11cn $@
}
