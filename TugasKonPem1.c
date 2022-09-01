#include <stdio.h>
#include <math.h>

int main(void){
	unsigned int counter;
	int grade;
	int total;
	int average;
	
	total = 0;
	counter = 0;

	while(counter <= 10){
		printf("%s", "Enter grade: ");
		scanf("%d", &grade);
		total += grade;
		counter++;
	}

	average = total / counter;
  
  printf("%d", average);
  printf(" ");
  printf("your grade is ");
	if(average >= 90){
		printf("A");
	}
	else if(average >= 80){
		printf("B");
	}
	else if(average >= 70){
		printf("C");
	}
	else if(average >= 60){
		printf("D");
	}
	else if(average < 60){
		printf("E");
	}
}

