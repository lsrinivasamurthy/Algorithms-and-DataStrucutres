#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(pair<int,int>a, pair<int,int>b){
    if (a.first == b.first){
        return a.second < b.second;
    }

    return a.first < b.first;
}

// Approach-1 : using TimeLine

int get_min_meeting_rooms_required(vector<vector<int>> times){
    int n = times.size();

    // Frame a Time Line with start Time(+1) and end Time(-1).
    vector<pair<int, int>> timeline;
    for (int i = 0; i < n; ++i){
        timeline.push_back({ times[i][0], +1 });
        timeline.push_back({ times[i][1], -1 });
    }

    // Now sort this timeline.
    sort(timeline.begin(), timeline.end(), comp);

    // Now loop over the timeline and remember the max.
    int max_meetings = 0;
    int current_meetings = 0;
    for (int i = 0; i < timeline.size(); ++i){
        current_meetings += timeline[i].second;
        max_meetings = max(current_meetings, max_meetings);
    }

    return max_meetings;
}


// Approach-2 : Using 2 Pointer Techniquee
int get_min_meeting_rooms_required_2(vector<vector<int>> times){
    int n = times.size();

    // collect all the start times + end times in a vector individually.
    vector<int> startTimes(n);
    vector<int> endTimes(n);
    for (int i = 0; i < times.size(); ++i){
        startTimes.push_back(times[i][0]);
        endTimes.push_back(times[i][1]);
    }

    int meeting_rooms = 1;
    int max_meeting_rooms = 1;
    
    // 2 pointer approach 
    int i = 1; // i=0 not considered because any how 1 room required so meeting and max are already updated with 1.
    int j = 0;

    while (i < n && j < n){
        if (startTimes[i] <= endTimes[j]){
            ++meeting_rooms;
            ++i;
        }
        else if (startTimes[i] >= endTimes[j]){
            --meeting_rooms;
            --j;
        }

        if (meeting_rooms > max_meeting_rooms){
            max_meeting_rooms = meeting_rooms;
        }
    }
    return max_meeting_rooms;
}


int main(){
    cout << "Approach-1 using GFG :" << endl;
    cout << get_min_meeting_rooms_required({    { 0, 30 },
                                                { 5, 10 },
                                                { 15, 20 } }) << endl;



    cout << get_min_meeting_rooms_required({    { 1, 18 },
                                                { 18, 23 },
                                                { 15, 29 },
                                                { 4, 15 },
                                                { 2, 11 },
                                                { 5, 13 } }) << endl;



    cout << get_min_meeting_rooms_required({    { 120, 600 },
                                                { 50, 550 },
                                                { 550, 700 },
                                                { 200, 500 },
                                                { 700, 900 },
                                                { 850, 1000 } }) << endl;

    cout << "Approach-1 using TFT :" << endl;
    cout << get_min_meeting_rooms_required_2({  { 0, 30 },
                                                { 5, 10 },
                                                { 15, 20 } }) << endl;

    cout << get_min_meeting_rooms_required_2({      { 1, 18 },
                                                    { 18, 23 },
                                                    { 15, 29 },
                                                    { 4, 15 },
                                                    { 2, 11 },
                                                    { 5, 13 } }) << endl;

    cout << get_min_meeting_rooms_required_2({ { 120, 600 },
                                                { 50, 550 },
                                                { 550, 700 },
                                                { 200, 500 },
                                                { 700, 900 },
                                                { 850, 1000 } }) << endl;
               

    system("pause");
    return 0;
}