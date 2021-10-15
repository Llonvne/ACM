#include "bits/stdc++.h"
using namespace std;

typedef int memberSerial;
typedef int teamSerial;
#define MAX_MEMBER_COUNT 1005
void createMemberSerialToTeamSerialMap(int numberOfTeam,map<int,int>& memberSerialToTeamSerial){
    for (int teamSerial = 0; teamSerial < numberOfTeam; ++teamSerial) {
        int memberCount;
        cin >> memberCount;

        for (int j = 0; j < memberCount; ++j) {
            int memberSerialBuffer;
            cin >> memberSerialBuffer;

            // 建立映射
            memberSerialToTeamSerial[memberSerialBuffer] = teamSerial;
        }
    }
}
bool getCommandAndProcessInAndOutCommingCommand(map<int,int>& memberSerialToTeamSerial,queue<int>& teamPriority,queue<int> memberPriorityInTeam[]){
    string commandType;
    cin >> commandType;

    if (commandType == "ENQUEUE"){

        int enqueueMemberSerial;
        cin >> enqueueMemberSerial;

        int corespondTeamSerial = memberSerialToTeamSerial[enqueueMemberSerial];

        // 检查团队内优先队列是否为空，如果为空就是该团队第一次出现，就需要添加到团队优先队列中，
        // 否则只需要添加成员优先队列
        if (memberPriorityInTeam[corespondTeamSerial].empty()){
            teamPriority.push(corespondTeamSerial);
        }

        memberPriorityInTeam[corespondTeamSerial].push(enqueueMemberSerial);

    }
    else if(commandType == "DEQUEUE"){

        int dequeueTeamSerial = teamPriority.front();
        int dequeueMemberSerial = memberPriorityInTeam[dequeueTeamSerial].front();

        memberPriorityInTeam[dequeueTeamSerial].pop();
        // 如果团队内优先队列为空 就说明 已经全部出库,就删除团队优先队列
        if (memberPriorityInTeam[dequeueTeamSerial].empty()){
            teamPriority.pop();
        }

        cout << dequeueMemberSerial << endl;

    }
    else if(commandType == "STOP"){
        return false;
    }
    return true;
}

int main(){
    int numberOfTeam;
    int numberOfOperation = 1;
    while(cin >> numberOfTeam && numberOfTeam){

        map<memberSerial,teamSerial> memberSerialToTeamSerial;
        queue<int> teamPriority,memberPriorityInTeam[MAX_MEMBER_COUNT];

        createMemberSerialToTeamSerialMap(numberOfTeam,memberSerialToTeamSerial);

        cout << "Scenario #" << numberOfOperation++ << endl;

        while(getCommandAndProcessInAndOutCommingCommand(memberSerialToTeamSerial,teamPriority,memberPriorityInTeam)){
        }

        cout << endl;
    }
}