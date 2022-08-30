#include <stdio.h>

int main(void){
	unsigned int counter;
	int grade;
	int total;
	int average;
	
	total = 0;
	counter = 1;

	while(counter <= 10){
		printf("%s", "Enter grade: ");
		scanf("%d", &grade);
		total += grade;
		counter++;
	}

	average = total / counter;
  
  printf("your grade is ");
	if(average >= 90){
		print("A");
	}
	else if(average >= 80){
		print("B");
	}
	else if(average >= 70){
		print("C");
	}
	else if(average >= 60){
		print("D");
	}
	else if(average < 60){
		print("E");
	}
}
