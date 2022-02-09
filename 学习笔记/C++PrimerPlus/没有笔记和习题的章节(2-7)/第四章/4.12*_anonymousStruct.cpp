// anonymousStruct.cpp -- 匿名结构
// 你可以缺省类型名称来创建实例，这样的话，只存在实例，但是不存在名字，即以后不能再创建这种实例
struct {
    int x;
    int y;
} Postion;
int main(){
    Postion.x = 1;

}