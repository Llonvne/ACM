//waiting.cpp -- using clock() function in a time-delay loop
#include <ctime>
#include <iostream>
void wait(int time){
    clock_t start = clock();    
    clock_t delay = time * CLOCKS_PER_SEC;
    clock_t dest = start + delay;
    while (clock() != dest){

    }
}
int main(){
    using namespace std;
    cout << "Enter the delay time, in seconds:" << endl;
    float secs;
    cin >> secs;
    wait(secs);
    cout << "Stating\a\n";
    /*
    clock_t delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();
    while(clock() - start < delay){
        ;
    }
    */
    cout << "Done" << endl;
    return 0;
}
