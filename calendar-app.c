//calendar app
#include<stdio.h>

//find first day of year
int getFirstDayOfYear(int year){
    int day = (year*365 + ((year-1)/4)-((year-1)/100)+((year-1)/400)) % 7;
    return day;
}

int main(){
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, weekDay = 0, spaceCounter = 0, year;

    //input year
    printf("Enter Year: ");
    scanf("%d",&year);
    printf("\n\n=================== YEAR: %d ==================\n\n", year);

    //check leap year
    if(year%4 == 0 && year%100 != 0 || year%400 == 0){
        daysOfMonth[1]=29;
    }

    //get first day of year.
    weekDay = getFirstDayOfYear(year);

    //print months and days name.
    for(i=0; i<12; i++){
        printf("\n\n-------------------- %s ------------------\n\n", months[i]);
        printf("    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n\n");

        //print space
        for(spaceCounter = 1; spaceCounter <= weekDay; spaceCounter++){
            printf("       ");
        }

        //print date of month
        for(j=1; j<= daysOfMonth[i]; j++){
            printf("%7d",j);
            weekDay++;

            if(weekDay > 6){
                printf("\n");
                weekDay = 0;
            }
        }
    }

    printf("\n\n=================== Thank You ====================\n\n");
    return 0;
}
