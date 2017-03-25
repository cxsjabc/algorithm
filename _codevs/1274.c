#include <stdio.h> 

int main()
{
	int limit, speed;
	int diff;
	int money;
	
	printf("Enter the speed limit: ");
	scanf("%d", &limit);

	printf("Enter the recorded speed of the car: ");
	scanf("%d", &speed);

	diff = speed - limit;
	if(diff <= 0)
		printf("Congratulations, you are within the speed limit\n");
	else if(diff >= 1 && diff <= 20)
		money = 100;
	else if(diff >= 21 && diff <= 30)
		money = 270;
	else if(diff >= 31)
		money = 500;
	if(diff > 0)
		printf("You are speeding and your fine is $ %d\n", money);
    return 0;
}
