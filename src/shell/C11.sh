# 使用方法
# 1. 使用 g11 等价替换 g++ -std=c++11
# 2. 使用 c11 编译单个 xxx.cpp 文件，生成a.out 文件直接运行，然后更名为 xxx.out
# 注意 会出现提示： \n\nC11: rename a.out to $filename Done!" 告知文件被重命名为什么东西
# 3. 使用 c11c (c11 clean) 编译单个 xxx.cpp 文件 , 生成 a.out 文件直接运行,然后直接删除
# 4. 使用 c11cc (c11 clean clear) 清空终端，然后运行3

alias g11="g++ -std=c++11" # use g11 replace g++ -std=c++11

c11(){
# The c11 function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# Rename $filename.out at the end of the run

# complie file with g11
g11 $1 &&   

# run             
./a.out &&    

# delete filename of .cpp           
filename=${1%.*cpp} &&   

# add .out to filename
filename+=".out" &&      

# tell user do what
echo "\n\nC11: rename a.out to $filename Done!" &&

# rename a.out to $1.out
`mv -f ./a.out "$filename"`
}

c11c(){

# The C11c ( C11Clear ) function accepts a $filename.cpp file
# compile it into a.out and then run a.out
# The a.out file is deleted at the end of the run

# use g11 complie file
g11 $1 &&

# run a.out
./a.out &&

# remove a.out
rm ./a.out &&
}

c11cc(){

# clean the windows first
clear

# run c11c
c11c $1

}