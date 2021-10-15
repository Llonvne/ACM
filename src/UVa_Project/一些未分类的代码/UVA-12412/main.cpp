#include <bits/stdc++.h>

// Function declarations
void PrintMenu(void);
int Add(void);
int Remove(void);
int Query(void);
int Show_Ranking(void);
int Show_Statistics(void);

// Data struct
struct Score {
    int Chinese;
    int Math;
    int English;
    int Program;
};
struct Student_PersonInfo {
    char SID[11];
    char CID[21];
    char name[11];
    Score s;
};
Student_PersonInfo S[101];

// main Function
int main(){

    // Start System
    PrintMenu();

    // Loop
    int select = -1;
    while(~scanf("%d",&select) && select){
        switch (select) {
            //Add
            case 1:
                Add();
                break;
            //Remove
            case 2:
                Remove();
                break;
            // Query
            case 3:
                Query();
                break;
            // Show Ranking
            case 4:
                Show_Ranking();
                break;
            //show statistics
            case 5:
                Show_Statistics();
                break;
            // Exit
            case 0:
                return 0;
                break;
        }
    }
}

//PrintMenu
void PrintMenu(void){
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    char info[6][40] = {"Add","Remove","Query","Show ranking","Show Statistics","Exit"};
    for (int i = 0; i < 6; ++i) {
        printf("%d - %s\n", i + 1, info[i]);
    }
}
//Add();
int Add(void){
    while(scanf("%s %s",))
}

