/**
 * Author: Ben Laube
 * 
 * Date: 2020/08/29
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    
    //define variables
    double lat1, lon1, lat2, lon2, lat1rads, lon1rads, lat2rads, lon2rads, angle;
    
    //prompts user for a latitude value and checks that it is a valid input
    printf("Enter the latitude of your origin: ");
    scanf("%lf", &lat1);
    if((-90 <= lat1 && lat1 <= 90) == 0) {
    		printf("invalid input\n");
			exit(1);
			
    }
    
    //prompts user for a longitude value and checks that it is a valid input
    printf("Enter the longitude of your origin: ");
    scanf("%lf", &lon1);
    if((-180 <= lon1 && lon1 <= 180) == 0) {
			printf("invalid input\n");
			exit(1);
    }
    
    //prompts user for a latitude value and checks that it is a valid input
    printf("Enter the latitude of your destination: ");
    scanf("%lf", &lat2);
    if((-90 <= lat2 && lat2 <= 90) == 0) {
			printf("invalid input\n");
			exit(1);
    }
    
    //prompts user for a longitude value and checks that it is a valid input
    printf("Enter the longitude of your destination: ");
    scanf("%lf", &lon2);
    if((-180 <= lon2 && lon2 <= 180) == 0) {
			printf("invalid input\n");
			exit(1);
    }
    
    //REMOVE
    printf("%lf, %lf, %lf, %lf\n", lat1, lon1, lat2, lon2);
    
    //converts from degrees to radians for all values
    lat1rads = lat1 * M_PI / 180.0;
    lon1rads = lon1 * M_PI / 180.0;
    lat2rads = lat2 * M_PI / 180.0;
    lon2rads = lon2 * M_PI / 180.0;
    
    //REMOVE
    //printf(lat1rads, lon1rads, lat2rads, lon2rads);
    
    //calculates the directional bearing
    angle = atan2(sin(lon2rads - lon1rads) * cos(lat2rads), cos(lat1rads) * sin(lat2rads) - sin(lat1rads) * cos(lat2rads) * cos(lon2rads - lon1rads));
    
    //converts angle from radians to degrees
    angle = angle * 180.0 / M_PI;
    printf("From (%lf, %lf) to (%lf, %lf): bearing %lf degrees\n", lat1, lon2, lat2, lon2, angle);
    
    return(0);
}