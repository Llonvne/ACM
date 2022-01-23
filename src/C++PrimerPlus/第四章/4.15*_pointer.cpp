// * pointer.cpp -- 指针

// 在 C++中 int* 为复合类型 即为 int类型的指针

// C-style Pointer
int *intPtr; // 更强调 *intPtr 是一个int类型的值 而 intPtr则隐式表达
// C++-style Pointer
int* intPtr; // 更强调 intPtr 是一个指向int类型的指针，而*intPtr是int则隐式表达

// 注意如果按照如下 C++-Style 声明会有一定问题
int* p,a;
// 其中 p 为 指针 ，而 a 为 int 类型

// 解决方法 如果一定要用 C++风格 int* 这样的方式，请一次声明一个指针
// 例如
int* b;
int* c;
// 或者使用 C 风格 
int *b,*c;

// 需要注意的是其中 * 中间的空格可有可无，以下都是合法的声明
int*d;
int *e;
int* e;
int * e;
int *e, * f;


