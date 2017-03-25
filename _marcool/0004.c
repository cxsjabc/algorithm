#include <stdio.h> 

int YEAR_DAYS[2] = {365, 366};
int MONTH_DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // no leap year
int LEAP_MONTH_DAYS[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // leap year

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);	
}

int get_days_of_year(int year)
{
	if(is_leap_year(year))
		return YEAR_DAYS[1];
	else
		return YEAR_DAYS[0];
}

int get_remain_days_of_year(int y, int m, int d)
{
	int leap = is_leap_year(y);
	int i = m + 1;
	int days = 0;
	int *p_month_days = leap ? LEAP_MONTH_DAYS : MONTH_DAYS;

	days += p_month_days[m] - d;	
	while(i <= 12) {
		days += p_month_days[i];
		++i;
	}
	return days;
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

int get_days_from_to(int fy, int fm, int fd, int ty, int tm, int td)
{
	int full_ys = ty - fy - 1;
	int days = 0;
	int y;
	
	if(ty > fy) {	
		days += get_remain_days_of_year(fy, fm, fd);
		days += get_exist_days_of_year(ty, tm, td);
	} else if(ty == fy) {
		int leap = is_leap_year(fy);
		int *p_month_days = leap ? LEAP_MONTH_DAYS : MONTH_DAYS;
		if(tm > fm) {
			days += p_month_days[fm] - fd;
			days += td;
		} else if(tm == fm)
			days += td - fd;
		++fm;
		while(fm < tm) {
			days += p_month_days[fm];
			++fm;
		}	
	}

	for(y = fy + 1; y <= ty - 1; ++y) {
		days += get_days_of_year(y);
	}
	return days;
}

int main()
{
	int sy = 1900, sm = 1, sd = 1;
	int weekday = 1;  // 1900-1-1 is Monday.
	int ny;
	int weekday_cnt[8] = {0};
	int i;
	int ty = sy, tm = sm, td = sd;

	scanf("%d", &ny);
	
	if(ny <= 0)
		return -1;
	for(; ty < sy + ny; ++ty) {
		for(i = 1; i <= 12; ++i) {
			int days = get_days_from_to(sy, sm, sd, ty, i, 13);
			int weekday = days % 7 + 1;
			//printf("days:%d, weekday:%d\n", days, weekday);
			weekday_cnt[weekday]++;
		}
	}	

	for(i = 1; i <= 7; ++i)
		if(i != 7)
			printf("%d ", weekday_cnt[i]);
		else
			printf("%d", weekday_cnt[i]);
    return 0;
}
