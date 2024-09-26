class Solution {
public:
    const int monthDays[12] = { 31, 28, 31, 30, 31, 30,  
                                31, 31, 30, 31, 30, 31 }; 
    int leapYears(int year, int month){
        if(month <= 2){
            year--;
        }
        return year/4 - year/100 + year/400;
    }
    int f(string date){
        int numOfDays = 0;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        numOfDays = year * 365 + day;

        numOfDays += leapYears(year, month);
        for(int i = 0; i < month-1; i++){
            numOfDays+= monthDays[i];
        }
        

        return numOfDays;
    }
    int daysBetweenDates(string date1, string date2) {
        int days = abs(f(date1) - f(date2));
        return days;
    }
};