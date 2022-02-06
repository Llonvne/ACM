#include <iostream>
#include <array>
using namespace std;

struct Donations{
    const static int SIZE = 10;
    array<double,SIZE> numbers;

    double average = 0;
    double sum = 0;
    int count = 0;
};
int main()
{
    Donations donations;
    printf("Enter donations (less than 10):\n");
    while (cin >> donations.numbers[donations.count] && donations.count < donations.SIZE ){
        donations.sum +=donations.numbers[donations.count];
        ++donations.count;
    }

    cin.clear();
    donations.average = donations.sum / donations.count;

    printf("donations count: %d",donations.count);
    printf("donations sum: %f\n",donations.sum);
    printf("donations average: %f\n",donations.average);
    return 0;
}