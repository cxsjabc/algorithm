#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int MONTH_DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // no leap year
int LEAP_MONTH_DAYS[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // leap year

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);	
}

int get_exist_days_of_year(int y, int m, int d)
{
	int leap = is_leap_year(y);
	int i = 1;
	int days = 0;
	int *p_month_days = leap ? LEAP_MONTH_DAYS : MONTH_DAYS;

	days += d;	
	while(i < m) {
		days += p_month_days[i];
		++i;
	}
	return days;
}

int main()
{
	int y, m, d;
	scanf("%d-%d-%d", &y, &m, &d);
	printf("%d\n", get_exist_days_of_year(y, m, d));
	return 0;
}
