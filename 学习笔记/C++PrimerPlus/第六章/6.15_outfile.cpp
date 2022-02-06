// 6.15_outfile.cpp -- writing to a file
#include <iostream>
#include <fstream>

int main(){
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    // 向标准输出流输出/输入
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile,50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter original asking price: ";
    cin >> a_price;

    d_price = a_price * 0.913;

    // 定义文件输出流
    ofstream outfile;
    // 打开文件
    outfile.open("carinfo.txt");
    // 向文件流输出
    outfile << fixed;
    outfile.precision(2);
    outfile.setf(ios_base::showpoint);
    outfile << "Make and model " << automobile << endl;
    outfile << "Year: " << year << endl;
    outfile << "Was asking $" << a_price << endl;
    outfile << "Now asking $" << d_price << endl;

    outfile.close();
    return 0;
}
