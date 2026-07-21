class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startHours = stoi(startTime.substr(0,2));
        int startMinutes = stoi(startTime.substr(3,2));
        int startSeconds = stoi(startTime.substr(6,2));
        
        int endHours = stoi(endTime.substr(0,2));
        int endMinutes = stoi(endTime.substr(3,2));
        int endSeconds = stoi(endTime.substr(6,2));

        int start = startHours*3600 + startMinutes*60 + startSeconds;
        int end = endHours*3600 + endMinutes*60 + endSeconds;

        return abs(end-start);
    }
};
