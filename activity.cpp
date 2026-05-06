#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start;
    int finish;
};
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}
void activitySelection(vector<Activity>& activities) {
    int n = activities.size();
    // Step 1: Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);
    cout << "Selected activities:\n";
    int i = 0;
    cout << "(Start: " << activities[i].start
         << ", Finish: " << activities[i].finish << ")\n";
    for (int m = 1; m < n; m++) {
        if (activities[m].start >= activities[i].finish) {
            cout << "(Start: " << activities[m].start
                 << ", Finish: " << activities[m].finish << ")\n";
            i = m;
        }
    }
}
int main() {
    vector<Activity> activities = {
        {1,4}, {3,5}, {0,6}, {5,7}, {3,8},
        {5,9}, {6,10}, {8,11}, {8,12}, {2,13}, {12,14}
    };
    activitySelection(activities);
    return 0;
}
