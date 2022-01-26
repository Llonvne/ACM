# 使用方法
# 1. 使用 g11 等价替换 g++ -std=c++11
# 2. 使用 c11 编译单个 xxx.cpp 文件，生成a.out 文件直接运行，然后更名为 xxx.out
# 注意 会出现提示： \n\nC11: rename a.out to $filename Done!" 告知文件被重命名为什么东西
# 3. 使用 c11c (c11 clean) 编译单个 xxx.cpp 文件 , 生成 a.out 文件直接运行,然后直接删除
# 4. 使用 c11cc (c11 clean clear) 清空终端，然后运行3

# 使用方法
# c11   1.cpp  // 等价于          编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后 a.out -> 1.out
# c11c  1.cpp  // 等价于          编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后删除 a.out
# c11cc 1.cpp  // 等价于 清空终端  编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后删除 a.out

# 上述所有函数都可以带有单个输入文件 跟在 源文件后面
# 使用方法如下
# c11   1.cpp  1.input   // 等价于         编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后 a.out -> 1.out
# c11c  1.cpp  1.input   // 等价于         编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后删除 a.out
# c11cc 1.cpp  1.input   // 等价于 清空终端 编译 1.cpp -> a.out 然后 ./a.out < 1.input 然后删除 a.out

# 辅助函数
# 6. c11run xxx.cpp input(optional)

# use g11 replace g++ -std=c++11
alias g11="g++ -std=c++11" 

# name : c11runFunction
# brief :  complie SINGLE cpp source file and run with SINGLE optional input file
# param 1 : SINGLE CPP source file
# param 2 OPTIONAL : input file
# compile cpp source file
# if $# == 1 run it directly
# else run it with input file
# based on alias g11 -> g++ -std=c++11
c11run(){

# complie cpp file
g11 $1

# Determine if the input file is included and execute it correctly
if [[ $# == 1 ]] then      
./a.out   
elif [[ $# == 2 ]] then 
./a.out < $2
else 
echo "Parameter is illegal.The function accepts two arguments the first for the CPP source file and the second optional argument for the input file"
exit $#;
fi

}

# name : c11Function
# brief : complie cpp source and run with optional input file,and rename xxx.cpp -> xxx.out
# param : SINGLE cpp file , optional SINGLE input file
# The c11 function accepts a $filename.cpp file and optional input file
# compile it into a.out and then run a.out < (optional) $inputfile
# Rename $filename.out at the end of the run
# based on c11run Function
c11(){

# using c11run function and transfer all the arguments;
c11run $@

# delete filename of .cpp           
filename=${1%.*cpp} &&   

# add .out to filename
filename+=".out" &&      

# tell user do what
echo "\n\nC11: rename a.out to $filename Done!" &&

# rename a.out to $1.out
`mv -f ./a.out "$filename"`
}

# name : C11ClearFunction
# brief :complie cpp source and run with optional input file,and delete a.out (which means Clear)
# The C11c ( C11Clear ) function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# The a.out file is deleted at the end of the run
# based on c11run function
c11c(){

# using c11run function and transfer all the arguments;
c11run $@ 

# remove a.out
rm ./a.out 
}

# name : C11ClearClearFunction
# brief :clear the window first(which means clear),complie cpp source and run with optional input file,and delete a.out (which means Clear)
# The C11cc ( C11ClearClear ) function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# The a.out file is deleted at the end of the run
# based on c11c function
c11cc(){

# clean the windows first
clear

# run c11c with all arguments
c11c $@

}