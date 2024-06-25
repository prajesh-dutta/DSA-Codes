#include <bits/stdc++.h>
using namespace std;

const int NUM_STATIONS = 4;


struct Station {
    int line;
    int time; 
};


int findFastestTime(Station stations[][NUM_STATIONS], int entry[], int exit[]) {
    int T1[NUM_STATIONS], T2[NUM_STATIONS];

    
    T1[0] = entry[0] + stations[0][0].time; 
    T2[0] = entry[1] + stations[1][0].time; 

   
    for (int i = 1; i < NUM_STATIONS; i++) {
        T1[i] = min(T1[i - 1] + stations[0][i].time,
                    T2[i - 1] + stations[0][i].time + stations[1][i - 1].time); 

        T2[i] = min(T2[i - 1] + stations[1][i].time,
                    T1[i - 1] + stations[1][i].time + stations[0][i - 1].time);
    }

    
    return min(T1[NUM_STATIONS - 1] + exit[0], T2[NUM_STATIONS - 1] + exit[1]);
}

int main() {
    
    Station stations[][NUM_STATIONS] = {
        {{1, 7}, {1, 4}, {1, 8}, {1, 9}},
        {{2, 2}, {2, 6}, {2, 1}, {2, 5}}
    };
    int entry[] = {2, 4};
    int exit[]  = {3, 2};

    int minTime = findFastestTime(stations, entry, exit);
    cout<<"Prajesh Dutta 22BCE3187"<<endl;
    cout << "Minimum time through the assembly lines: " << minTime << endl;

    return 0;
}
