#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Job{
public:
    int job_id;
    int dead_line;
    int profit;

    Job(int a, int b, int c){
        job_id = a;
        dead_line = b;
        profit = c;
    }
};

bool comp_profit(Job& a, Job& b){
    return a.profit > b.profit;
}

int get_max_dead_line(vector<Job> jobs){
    int max_dead_line = jobs[0].dead_line;
    for (int i = 1; i < jobs.size(); ++i){
        max_dead_line = max(max_dead_line, jobs[i].dead_line);
    }
    return max_dead_line;
}

pair<int,int> get_job_sequence_max_profit(vector<Job> jobs){

    int n = jobs.size();

    //step-1: sort the vector based on profit
    sort(jobs.begin(), jobs.end(), comp_profit);

    //step-2: find max deadline out of available jobs
    int max_dead_line = get_max_dead_line(jobs);

    //step-3: prepare the slots to execute the job and initially fill all with empty
    vector<bool> slots(max_dead_line, false);

    int job_count = 0;
    int max_profit = 0;
    
    //step-4: Now loop over the available jobs and fill the slots from the right. I mean execute the job having more dead line at the last.
    for (int i = 0; i < n; ++i){
        for (int j = jobs[i].dead_line-1; j >= 0; --j){
            if (slots[j] == false){
                slots[j] = true;
                job_count++;
                max_profit += jobs[j].profit;
                break;
            }
        }
    }

    // step-5 : return the job count and max profit
    return{ job_count, max_profit };
}

int main(){
    pair<int, int> res = get_job_sequence_max_profit({ { 1, 2, 100 },
    { 2, 1, 19 },
    { 3, 2, 27 },
    { 4, 1, 25 },
    { 5, 1, 15 } });

    cout << res.first << " " << res.second << endl;
    system("pause");
    return 0;
}