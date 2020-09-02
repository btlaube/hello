/**
 * Author: Ben Laube
 *
 *Date: 2020/08/29
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    
    //checks if the current day variable is within [1,30]
    if((1 <= atoi(argv[2]) && atoi(argv[2]) <= 30) == 0) {
        printf("ERROR: invalid value for current day in 30 day period.\n");
        exit(1);
    }
    
    //define command line arguments
    int gbPerMonth = atoi(argv[1]);
    int currentDay = atoi(argv[2]);
    int gbUsed = atoi(argv[3]); 
    
    //calculates necessary values: Days remaining in billing cycle, 
	//current average daily use, and recommended daily use
	int daysRemaining = 30 - currentDay;
	double avgDailyUse = (double) gbUsed / currentDay;
	double recDailyUse = (double) gbPerMonth / 30;
	
	//prints a summary of data usage
	printf("%d days used, %d days remaining.\n", currentDay, daysRemaining);
	printf("Average daily use: %f GB/day\n", avgDailyUse);
	printf("\n");
	
	//checks to see if all the data has been used
	if(gbUsed >= gbPerMonth) {
		printf("You've used all data for this month.\n");
	}	
    
    //checks if the daily data usage is equal to the recommended daily usage.
	else if(avgDailyUse == recDailyUse ) {
		printf("You are using your data at the recommended rate (%f).\n", recDailyUse);
	}
	
	else {
	    
	    //calculates how many GB's you'll go over or under your GB's per month
		//if current average daily use is continued.
		int gbAwayFromGbPerMonth = abs((((int)(avgDailyUse * daysRemaining) + gbUsed) - gbPerMonth));
	    
	    //calculates a new recommended daily data usage based on remaining data and days
		double newRecDailyUse = fabs((double)(gbUsed - gbPerMonth) / daysRemaining);
			
	    //checks if data is being used to fast, in which case it tells how much it'll go over
		//by and the new rate at which they should use data to not exceed the monthly data
		if(avgDailyUse > recDailyUse) {
			printf("You are EXCEEDING your average daily use (%f) GB/day).\n" 
			    "Continuing this high usage, you'll exceed your data plan by %d GB.\n"
			    "To stay below your data plan, use no more than %f GB/day.\n", recDailyUse, gbAwayFromGbPerMonth, newRecDailyUse);
		}
		
		//check if data is being used too slow, in which case it tells how much it'll go under
		//by and the new rate at which they should use data to use all the data.
		else if (avgDailyUse < recDailyUse) {
			printf("You are BELOW your average daily use (%f) GB/day.\n"
				"Continuing this low usage, you'll undershoot your data plan by %d GB.\n"
			    "To use all of your data, try to use at least %f GB/day.\n", avgDailyUse, gbAwayFromGbPerMonth, newRecDailyUse);
		}
	
	}
    
}