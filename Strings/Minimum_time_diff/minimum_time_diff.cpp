class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (int i = 0; i < timePoints.size(); i++)
        {   
            string currTime = timePoints[i];
            int hour = stoi(currTime.substr(0, 2));
            int minute = stoi(currTime.substr(3, 2));
            int totalMinutes = hour*60 + minute;
            minutes.push_back(totalMinutes);
        }

        // find minimum
        sort(minutes.begin(), minutes.end());
        int n = minutes.size();
        int mini = INT_MAX;
        for (int i = 0; i < n-1; i++ )
        {
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }

        // IMPORTANT ->
        int lastDiff = (minutes[0] + 1440) - minutes[n-1];
        mini = min(mini, lastDiff);

        return mini;
    }
};