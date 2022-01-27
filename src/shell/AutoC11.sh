# AutoC11 脚本
# 安装方法 ： 将所有内容放到终端配置文件 例如 .zshrc 或者 .bashrc 等
# 使用方法 ：
# 1. 使用 g11 代替 g++ std=c++11 来指定C11编译器 （非函数）
# 2. 使用 c11 函数来自动完成编译xxx.cpp->a.out,运行程序a.out，将a.out->xxx.cpp程序文件改为与源文件同名字
# 3. 使用 c11c (c11Clean)函数 来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
# 4. 使用 c11c (c11CleanClear)函数 首先清空终端，然后来自动完成编译xxx.cpp->a.out,运行a.out,删除a.out
# 5. 在前面所有的函数后面补上一个n 来使用无提示的模式，可以保留纯净的输出流,例如 c11n,c11cn,c11ccn

# 注意：使用__function__ 的函数均为内部函数，请勿直接调用

### alias

# alias g11 = g++ -std=c++11
alias g11="g++ -std=c++11" 

### function of Print

# Print Prefix
__AutoC11PrintWithPrefix__(){
    echo -e "\033[32mAutoC11:\c\033[0m" &&
    echo "$*" &&
}

# Print Program Exit and Time Count
__AutoC11PrintExitCodeAndTimeCount__(){
__AutoC11PrintWithPrefix__ "\033[32m----------------程序运行结束----------------------\033[0m" &&
__AutoC11PrintWithPrefix__ "\033[32m程序花费了 $(($(date +%s)-${start})) 秒. 退出代码 ${exit_code}\033[0m" &&
}

### function of Complie and Run

## Complie and Run directly

# Run Program
__AutoC11ProgramRunner__() {
  $@ &&
}

# Complie CPP source to a.out (xxx.cpp->a.out)
__AutoC11ComplieCppSource__() {
  g11 $1 &&
}

## Runtime Controller

# Run Program and Count Time
__AutoC11RunController__() {

  # start time
  start=$(date +%s) &&

  # Run Program
  __AutoC11ProgramRunner__ "a.out" &&

  # exit code
  exit_code=$? &&
}

# Run Program With Print
__AutoC11RunControllerWithPrint__() {
# Start Run Program
__AutoC11PrintWithPrefix__ "\033[32m----------------开始运行程序----------------------\033[0m" &&
# Run Controller
__AutoC11RunController__ $@ &&
# Print Infomation
__AutoC11PrintExitCodeAndTimeCount__ &&
}

## Complie Controller

# Complie CPP with Print
__AutoC11ComplieControllerWithPrint__(){
__AutoC11PrintWithPrefix__ "\033[32m开始编译源文件!\033[0m" &&
# Complie 
__AutoC11ComplieCppSource__ $@ && 
__AutoC11PrintWithPrefix__ "\033[32m源文件编译成功！\033[0m" &&
# Run Controller
__AutoC11RunControllerWithPrint__ "./a.out" &&
}

# Complie CPP with Print
__AutoC11ComplieController__(){
  __AutoC11ComplieCppSource__ $@ &&
  __AutoC11RunController__ "./a.out" &&
}

### User Command Function

# Complie CPP Source and Run Program and rename a.out -> xxx.cpp
c11(){
# complie and run 
__AutoC11ComplieControllerWithPrint__ $@ && 
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
__AutoC11ComplieController__ $@ &&
# delete filename of .cpp           
filename=${1%.*cpp} &&   
# add .out to filename
filename+=".out" &&
# rename a.out to $1.out
`mv -f ./a.out "$filename"` &&
}

# Complie CPP Source and Run Program and Delete a.out
c11c(){
# complie and run
__AutoC11ComplieControllerWithPrint__ $@ && 
# remove a.out
rm ./a.out 
}

# c11c without Print
c11cn(){
# complie and run
__AutoC11ComplieController__ $@ && 
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
# run c11cn
c11cn $@
}
