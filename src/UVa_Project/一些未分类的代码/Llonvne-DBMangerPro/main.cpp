/*
 * 使用说明书： 请现在下面定义你的用户名 ，默认用户名是 Llonvne ， 用户名就是您的根目录名字，不得与任何项目名字或者
 * 数据库，数据表，数据项等名字发生冲突
 *
 * 入门提示：
 * 当您第一次启动数据库时，您应该会看到 由您的用户名 + 一个冒号 组成等命令提示符号
 * 该提示符号将会自动显示您目前所在的目录
 * 例如 : Llonvne:
 *
 * 该数据库分为五个层级
 * 分别为 UserName（ROOT） DataBase Sheet Item Label
 * 其中 用户名（UserName） 有且仅有一个，作为您等根目录存在，下面可以新建多个数据库
 * 数据库(Database) 一般作为您的第一个层级，你可以用数据库来管理多张数据表
 * 数据表（Sheet） 作为您的第二个分类层级， 在代码实现方面，数据库和数据表的差异不大，但是逻辑层面来说
 * 数据库一般是一个比较综合的范围，而数据表往往相对具体，当然你也可以自定义您的使用方法
 * 数据项（Item） 作为数据库的原子单位，您可以类似于表格中的一行
 * 标签（label） 作为数据项的附属单位也是真正存储数据单位，可以自定义创建，删除。
 * 请注意所有的标签只属于一个数据项目，也就说不同的数据项目不共享标签，每一个数据项目的标签都是独立存在的
 * 如果要添加 所有数据项都存在的项目，请在 Item 配置项中添加
 *
 * 数据库命令介绍
 * 命令 ls 作用列出子目录所有项目的名称（请注意列出的项目名称与您所在的层级相关，如果您处于根目录，则会列出所有数据库
 * 相对的 如果您在某一个特定的数据库中则会列出所有的数据表，如果你在一个数据项中，则会列出所有所属的标签）
 *
 * 命令 new 这个命令允许您自由的创建数据库，数据表，数据项，甚至是标签，
 * 该命令如何生效取决于您处于那个层级的目录中，如果你处于 根目录中使用new
 * 例子 new myFirstDataBase 则会新建一个叫做 myFirstDataBase 一个数据库
 * 相对的 你在某一个数据库中的时候使用则会创建一个数据表
 * 稍有不同的是，如果您处于某一个 项目（item）中 使用 new 命令
 * 您必须提供两个参数 分别是 new Labelname Labelvalue 这个时候new命令的作用是创建一个标签，您必须同时提供
 * 标签名字和标签值才能建立
 * 请注意 new 命令在创建 数据库，表，项目后会自动进入，请注意
 *
 * 命令 cd 则允许您自由在各个项目中切换
 * 如果你处于根目录且存在一个 名为 db1 的数据库
 * 您可以使用如下格式进行切换
 * cd db1 既可以进入到db1 这个数据库
 * 同样的你也可以按照此方法进入 数据表，项目
 * 请注意 标签仅仅是由键值对组成的所以不允许进入
 * 您可以使用 cd ../ 来返回上一级目录
 * 可以直接使用 cd / 直接快速回到根目录
 * 您也可使用 cd 数据库名字\数据表名字\数据项名字 来快速到达
 * 请注意 这个分割符号可以在下面自定义 但请勿使用 / 因为会引发冲突，一般推荐使用 \ 或者 .
 * 如果您忘记了您的数据库，数据项目，数据表在哪里，你也可以通过 search 命令快速到达
 * 请注意如果存在同名，将会优先到达高层目录， 例如存在一个叫做 llonvne 的数据库和数据表，那么只会到达数据库
 * 同时该命令行采用顺序搜索，时间较长。
 *
 *
 *
 *
 *
 */


#include "bits/stdc++.h"
using namespace std;

// --- 数据库配置文件 ---//

// 注意 序号不得超过该类型的最大值！
// 定义 数据库使用到数字类型， 请注意该数字同时控制着 列表和物品的最大值
#define NUMBER_TYPE int
// 该公式会计算出最大允许值
#define MAX_LENGTH numeric_limits<NUMBER_TYPE> ::max()
// 最大数据库限制 该值不可以超过 MAX_LENGTH
#define MAX_DATABASE_COUNT 1024
// 定义 用户名 同时也是根目录的名字
#define USER_NAME "Llonvne"

// 定义索引信息存储位置
#define PROFILE_

/*
 * 在制定完使用的证书类型后，您也可以单独指定项最大值和表最大值，如果不指定默认按照该整形能表示的最大值表示
#define ITEM_MAX_COUNT_IN_LIST 1000000
#define SHEET_MAX_COUNT_IN_DATABASE 1000000
 */

// --- 数据库配置文件 END ---//
// 定义 ID 和 数字 类型
typedef NUMBER_TYPE number;
typedef unsigned NUMBER_TYPE DB_ID;
// 判断是否自定义限制
#ifndef ITEM_MAX_COUNT_IN_LIST
#define ITEM_MAX_COUNT_IN_LIST MAX_LENGTH
#endif
#ifndef SHEET_MAX_COUNT_IN_DATABASE
#define SHEET_MAX_COUNT_IN_DATABASE MAX_LENGTH
#endif
// 定义 路径未表示 和 未找到项目 标识
#define OUT NULL
#define NOT_FOUND NULL
// CD 路径分割符号
#define SPLIT_SYMBOL '\\'
// 未定义值
#define UNDEFINED "UNDEFINED"
// 路径检测返回值
#define ROOT (-1)
#define IN_DATABASE 0
#define IN_SHEET 1
#define IN_ITEM 2
// 定义退出标识
#define EXIT 1
#define NOT_EXIT 0

struct label{

    string name;
    string value;

    bool enable = true;

};
struct item {
    DB_ID ID;
    string name;
    /*
        string phoneNumber;
        number age;
        您可以在这里配置所有数据项目都存在的标签
        并且使用和访问他们
    */

    bool enable = true;

    // 自定义标签指针
    number labelCount = 0;
    label * labelAddress[MAX_LENGTH];
};
struct sheet {
    DB_ID ID;
    string name;
    number itemCount = 0;
    item *itemAddress[ITEM_MAX_COUNT_IN_LIST];

    bool enable = true;
};
struct database {
    DB_ID ID;
    string name;
    number sheetCount = 0;
    sheet *sheetAddress[SHEET_MAX_COUNT_IN_DATABASE];

    bool enable = true;
};

//初始化数据库指针数组
database *databaseAddress[MAX_DATABASE_COUNT];
number databaseCount = 0;

//控制记录信息：
database * nowDatabase = OUT;
sheet * nowSheet = OUT;
item * nowItem = OUT;
DB_ID global_ID = 0;


//屏幕大方框
void clearScreen(){
    printf("**************************\n");
    printf("*    LlonvneDBMangerPro  *\n");
    printf("*                        *\n");
    printf("*                        *\n");
    printf("*                        *\n");
    printf("**************************\n");
}

// 函数声明 //
void ls();
void cd(const string& value);
void pathPrompt();
int pathDetection();
// 函数声明 END//

//新建数据库
bool newDatabase(const string& databasename = UNDEFINED){

    if (databaseCount >= MAX_DATABASE_COUNT){
        printf("ERROR: 您所创建的数据库已经达到上线，请删除无用的数据库，或者提高限制！\n");
        return false;
    }

    auto * p = new database;

    string databaseNameBuffer;
    if (databasename == UNDEFINED){
        cout << endl ;
        cout << "请输入该数据库名称" << endl;
        cout << ">>> ";
        cin >> databaseNameBuffer;
    }else {
        databaseNameBuffer = databasename;
    }
    p->name = databaseNameBuffer;

    databaseAddress[databaseCount] = p;
    databaseCount++;
    p->ID = global_ID++;

    cd(p->name);

    return true;
}

//新建数据表
bool newSheet(database& d,const string& sheetname = UNDEFINED){

    if (d.sheetCount >= SHEET_MAX_COUNT_IN_DATABASE){
        cout << "本数据库的数据表数量已经到达可用上限，请删除无用数据表，或者调整上限" <<endl;
        return false;
    }

    auto * p = new sheet;
    d.sheetAddress[d.sheetCount] = p;

    string sheetNameBuffer;
    if(sheetname == UNDEFINED){
        cout << endl ;
        cout << "请输入该数据表的名字" << endl;
        cout << ">>> ";
        cin >> sheetNameBuffer;
    }else {
        sheetNameBuffer = sheetname;
    }
    p->name = sheetNameBuffer;

    d.sheetCount++;
    p->ID = global_ID++;

    cd(p->name);

    return true;
}

//新建数据项
bool newItem(database& d,sheet& s,const string& itemname = UNDEFINED){

    if (s.itemCount >= ITEM_MAX_COUNT_IN_LIST){
        cout << "该表内数据项已满，请清空无用的数据项，或者提高上限" << endl;
        return false;
    }
    auto * p = new struct item;

    string itemNameBuffer;
    if (itemname == UNDEFINED){
        cout << endl ;
        cout << "请输入项目的名称" << endl;
        cout << ">>> ";
        cin >> itemNameBuffer;
    }else {
        itemNameBuffer = itemname;
    }
    p->name = itemNameBuffer;

    s.itemAddress[s.itemCount] = p;
    s.itemCount++;
    p->ID = global_ID++;

    cd(p->name);

    return true;

}

//新建项目内标签
bool newLabel(item& i,const string& labelname,const string& value = UNDEFINED){
    if (i.labelCount >= MAX_LENGTH){
        cout << "标签已满，请删除一些标签，或者调整上限";
    }

    auto * p = new label;

    p->name = labelname;
    p->value = value;

    i.labelAddress[i.labelCount++] = p;
}

// 数据库名字查找
database * databaseSearchByName(const string& name){
    for (int i = 0; i < databaseCount; ++i) {
        if(databaseAddress[i]->name == name){
            return databaseAddress[i];
        }
    }

    return NOT_FOUND;
}

// 数据表名字查找
sheet * sheetSearchByName(const database& d,const string& name){

    for (int i = 0; i < d.sheetCount; ++i) {
        if(d.sheetAddress[i]->name == name){
            return d.sheetAddress[i];
        }
    }

    return NOT_FOUND;
}

// 项目名字查找
item * itemSearchByName(const sheet& s,const string& name){

    for (int i = 0; i < s.itemCount; ++i) {
        if (s.itemAddress[i]->name == name){
            return s.itemAddress[i];
        }
    }

    return NOT_FOUND;
}

// 项目名称全局搜索
item * itemSearchOverAll(const string& name){
    for (int i = 0; i < databaseCount; ++i) {
        auto * dataPtr = databaseAddress[i];
        nowDatabase = dataPtr;
        if (nowDatabase->name == name) {
            return NOT_FOUND;
        }

        for (int j = 0; j < dataPtr->sheetCount;j++) {
            auto * sheetPtr = dataPtr->sheetAddress[j];
            nowSheet = sheetPtr;

            if (nowSheet->name == name){
                return NOT_FOUND;
            }

            for (int k = 0; k < sheetPtr->itemCount;k++){
                auto * itemPtr = sheetPtr->itemAddress[k];

                if (itemPtr->name == name) {
                    nowItem = itemPtr;
                    return itemPtr;
                }
            }
        }
    }

    return NOT_FOUND;
}

// 输出数据库列表
void printDatabaseList(){
    for (int i = 0; i < databaseCount; ++i) {
        if (!databaseAddress[i]->enable){
            continue;
        }
        cout << databaseAddress[i]->name << "   " ;
    }
    cout << endl;
}

// 输出数据表到列表
void printSheetList(){
    for (int i = 0; i < nowDatabase->sheetCount; ++i) {
        if(!nowDatabase->sheetAddress[i]->enable){
            continue;
        }
        cout << nowDatabase->sheetAddress[i]->name << "    ";
    }
    cout << endl;
}

// 输出项目列表
void printItemList(){
    for (int i = 0; i < nowSheet->itemCount; ++i) {

        if (!nowSheet->itemAddress[i]->enable) {
            continue;
        }
        cout << nowSheet->itemAddress[i]->name << "   ";
    }
    cout << endl;
}

// 输出所有标签
void printLabelList()
{
    for (int i = 0; i < nowItem->labelCount; ++i) {

        if (!nowItem->labelAddress[i]->enable) {
            continue;
        }

        cout << nowItem->labelAddress[i]->name << " = "<< nowItem->labelAddress[i]->value << endl;
    }
}

// 展示目录
void ls(){

    //顶层目录
    if (pathDetection() == ROOT){
        printDatabaseList();
        return;
    }
    //数据表视图
    if (pathDetection() == IN_DATABASE){
        printSheetList();
        return;
    }
    //项目视图
    if (pathDetection() == IN_SHEET){
        printItemList();
        return;
    }

    if (pathDetection() == IN_ITEM){
        printLabelList();
        return;
    }
}

// CD命令
void command_cd_return(){
    if (pathDetection() == IN_ITEM){
        //物品检测
        nowItem = OUT;
        return;
    }

    if (pathDetection() == IN_SHEET){
        //退出数据表
        nowSheet = OUT;
        nowItem = OUT;
        return;
    }

    if (pathDetection() == IN_DATABASE){
        //退出数据库
        nowDatabase = OUT;
        nowSheet = OUT;
        nowItem = OUT;
        return;
    }

    if (pathDetection() == ROOT){
        cout << "您已经处于根目录无法后退了" << endl;
        return;
    }
}
void command_cd(const string& value){

    //处理返回cd指令
    if (value == "../"){
        command_cd_return();
        return;
    }
    //判断返回根目录
    if (value == "/"){
        nowDatabase = OUT;
        nowSheet = OUT;
        nowItem = OUT;
        return;
    }

    //处理数据库cd指令
    auto * dataPtr = databaseSearchByName(value);
    if (pathDetection() == ROOT && dataPtr != NOT_FOUND){
        nowDatabase = dataPtr;
        return;
    }
    if (nowDatabase == OUT){
        return;
    }

    //处理数据表cd指令
    auto * sheetPtr = sheetSearchByName(*nowDatabase,value);
    if (pathDetection() == IN_DATABASE && sheetPtr != NOT_FOUND){
        nowSheet = sheetPtr;
        return;
    }
    if (nowSheet == OUT){
        return;
    }

    //处理项目cd指令
    auto * itemPtr = itemSearchByName(*nowSheet,value);
    if (itemPtr != NOT_FOUND){
        nowItem = itemPtr;
        return;
    }
}
void cd(const string& value){
    int spilt[2] = {-1,-1};

    for (int i = 0; i < value.length(); ++i) {
        if (value[i] == SPLIT_SYMBOL && spilt[0] == -1){
            spilt[0] = i;
            continue;
        }
        if (value[i] == SPLIT_SYMBOL && spilt[0] != -1 && spilt[1] == -1){
            spilt[1] = i;
            break;
        }
    }

    if (spilt[0] == -1){
        command_cd(value);
        return;
    }else if(spilt[0] != -1 && spilt[1] == -1){
        string front = value.substr(0,spilt[0]);
        string back = value.substr(spilt[0]+1,value.length() - spilt[0] -1);
        command_cd(front);
        command_cd(back);
        return;
    }else if(spilt[0] != -1 && spilt[1] != -1){
        command_cd(value.substr(0,spilt[0]));
        command_cd(value.substr(spilt[0]+1,spilt[1] - spilt[0] -1));
        command_cd(value.substr(spilt[1]+1,value.length() - spilt[1] - 1));
        return;
    }
}

// 路径提示器
void pathPrompt(){
    //顶层目录
    if (pathDetection() == ROOT){

        cout << USER_NAME << ":";
        return;
    }
    //数据表视图
    if (pathDetection() == IN_DATABASE){

        cout << USER_NAME << "/" << nowDatabase->name << ":";
        return;
    }
    //项目视图
    if (pathDetection() == IN_SHEET){
        cout << USER_NAME << "/" << nowDatabase->name << "/" << nowSheet->name <<":";
        return;
    }

    // 项目内部视图
    if (pathDetection() == IN_ITEM){
        cout << USER_NAME << "/" << nowDatabase->name << "/" << nowSheet->name <<"/" << nowItem->name << ":";
    }
}

// 判断当前所处位置
int pathDetection(){
    if (nowItem != OUT){
        return IN_ITEM;
    }
    if (nowSheet != OUT){
        return IN_SHEET;
    }
    if (nowDatabase != OUT){
        return IN_DATABASE;
    }
    if (nowDatabase == OUT){
        return ROOT;
    }
}

// new命令
void command_new(const string& value){
    if (pathDetection() == ROOT){
        newDatabase(value);
        return;
    }
    if (pathDetection() == IN_DATABASE){
        newSheet(*nowDatabase,value);
        return;
    }
    if (pathDetection() == IN_SHEET){
        newItem(*nowDatabase,*nowSheet,value);
        return;
    }
    if (pathDetection() == IN_ITEM){

        string labelvalue;
        cin >> labelvalue;

        newLabel(*nowItem,value,labelvalue);
    }
}

// del命令
void command_del(label * l){
    l->enable = false;
}
void command_del(item * l){
    l->enable = false;
}
void command_del(sheet * l){
    l->enable = false;
}
void command_del(database * l){
    l->enable = false;
}

// 输入监测函数
int keyboardInput(){

    string command_type;
    cin >> command_type;

    if (command_type == "exit"){
        return EXIT;
    }else if(command_type == "cd"){
        string value;
        cin >> value;
        cd(value);
    }else if(command_type == "ls"){
        ls();
    }else if(command_type == "new"){
        string value;
        cin >> value;
        command_new(value);
    }else if(command_type == "search"){
        string value;
        cin >> value;
        itemSearchOverAll(value);
    }else if(command_type == "del"){
        string value;
        cin >> value;

        // 全局搜索物品
        itemSearchOverAll(value);
        // 判断当前路径
        int pathValue = pathDetection();
    }

    pathPrompt();

    return NOT_EXIT;
}

int main(){
    pathPrompt();
    while(keyboardInput() != EXIT){

    }
}


