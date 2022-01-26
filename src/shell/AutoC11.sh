# 使用方法
# 1. 使用 g11 等价替换 g++ -std=c++11
# 2. 使用 c11 编译单个 xxx.cpp 文件，生成a.out 文件直接运行，然后更名为 xxx.out
# 注意 会出现提示： \n\nC11: rename a.out to $filename Done!" 告知文件被重命名为什么东西
# 3. 使用 c11c (c11 clean) 编译单个 xxx.cpp 文件 , 生成 a.out 文件直接运行,然后直接删除
# 4. 使用 c11cc (c11 clean clear) 清空终端，然后运行3

# 使用方法
# c11   1.cpp  // 等价于          编译 1.cpp -> a.out 然后 ./a.out 然后 a.out -> 1.out
# c11c  1.cpp  // 等价于          编译 1.cpp -> a.out 然后 ./a.out 然后删除 a.out
# c11cc 1.cpp  // 等价于 清空终端  编译 1.cpp -> a.out 然后 ./a.out 然后删除 a.out
# 辅助函数
# 6. c11run xxx.cpp 

# use g11 replace g++ -std=c++11
alias g11="g++ -std=c++11" 

__outputC11FunctionPrefix__(){
    echo -e "\033[32mAutoC11:\c\033[0m" &&
    echo "$*"
}

# name : time measure
# brief : measure time
# param : commands
# return : times of commands
__C11RunTimeCount__() {
  local start=$(date +%s) &&
  $@ &&
  local exit_code=$? &&
__outputC11FunctionPrefix__ "\033[32m----------------程序运行结束----------------------\033[0m" &&
__outputC11FunctionPrefix__ "\033[32m程序花费了 $(($(date +%s)-${start})) 秒. 退出代码 ${exit_code}\033[0m" &&
  return $exit_code
}

# name : c11runFunction
# brief :  complie SINGLE cpp source file
# param 1 : SINGLE CPP source file
# compile cpp source file
# run a.out
# based on alias g11 -> g++ -std=c++11
c11run(){

# complie cpp file
__outputC11FunctionPrefix__ "\033[32m开始编译源文件!\033[0m" &&
g11 $1 && 
__outputC11FunctionPrefix__ "\033[32m源文件编译成功！\033[0m" &&

# Determine if the input file is included and execute it correctly 
__outputC11FunctionPrefix__ "\033[32m----------------开始运行程序----------------------\033[0m" &&
__C11RunTimeCount__ "./a.out"
}

# name : c11Function
# brief : complie cpp source and run,and rename xxx.cpp -> xxx.out
# param : SINGLE cpp file
# The c11 function accepts a $filename.cpp file
# compile it into a.out and then run a.out 
# Rename $filename.out at the end of the run
# based on c11run Function
c11(){

# using c11run function and
c11run $@ && 

# delete filename of .cpp           
filename=${1%.*cpp} &&   

# add .out to filename
filename+=".out" &&      

# tell user do what
__outputC11FunctionPrefix__ "\033[32m输出文件：$filename\033[0m" &&

# rename a.out to $1.out
`mv -f ./a.out "$filename"`
}

# name : C11ClearFunction
# brief :complie cpp source and runand delete a.out (which means Clear)
# The C11c ( C11Clear ) function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# The a.out file is deleted at the end of the run
# based on c11run function
c11c(){

# using c11run function
c11run $@ && 

# remove a.out
rm ./a.out 
}

# name : C11ClearClearFunction
# brief :clear the window first(which means clear),complie cpp source and run ,and delete a.out (which means Clear)
# The C11cc ( C11ClearClear ) function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# The a.out file is deleted at the end of the run
# based on c11c function
c11cc(){

# clean the windows first
clear &&

# run c11c 
c11c $@
}
