#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MYFILE "Driving Diary.txt"
#define SIZE 18
#define SIZE2 9
void new_trip();
void save();
void print();
void erase();
int i = 1;


struct drivingDiary 	{
	int order;
	char start[SIZE];
	char start_time[SIZE2];
	int odometer_start;
	char end[SIZE];
	char end_time[SIZE2];
	int odometer_stop;						
};
struct drivingDiary data[20];

void print_m();
void displayDiary(struct drivingDiary);
struct drivingDiary inputData(void);


int main(void)
{
	
	FILE *myfile = NULL;
	
	int a, b;
	int c[20];
	int l, k;
	char line[SIZE];
	char str[10];
	int selection;

	while (SIZE!=8)
	{
		print_m();
		scanf("%d", &selection);
		switch(selection) {
		case 1:
			printf("You choose 1 .\n ");
			erase();
			printf("All data in the %s file erased! \n", MYFILE);
			break;
		case 2:
			printf("You choose 2 .\n The data is saved to the diary successfully!\n ");
			save();

			break;
		case 3:
			printf("Data is being loaded from the disk! .\n ");

			myfile = fopen(MYFILE, "rb");

			if (myfile == NULL) {
				printf("Cannot open %s\n", MYFILE);
				fclose(myfile);
				break; }
			else { i=1;
			while(i !=20)
			{
				fread(&data[i],sizeof(struct drivingDiary),i,myfile);
				i++;}
			}
			fclose(myfile);
			break;
		case 4:
			printf("You choose 4 .\n ");
			i=1;
			while (data[i].odometer_start!=0)
			{i++;}
			data[i].order=i;
			printf("\nEnter the name of the start location: \n");
			scanf("%s", data[i].start);
			printf("\nEnter the time when you started the trip: \n");
			scanf("%s", data[i].start_time);
			printf("\nEnter the odometer value at the start of the trip: \n");
			scanf("%d", &data[i].odometer_start);
			printf("\nEnter the name of the final destination of the trip: \n");
			scanf("%s", data[i].end);
			printf("\nEnter the arrival time at the destination: \n");
			scanf("%s", data[i].end_time);
			printf("\nEnter the odometer value after the trip: \n");
			scanf("%d", &data[i].odometer_stop);
			break;
		case 5:
			printf("Type in order the number of the record(s) you want to remove: \n ");
			scanf("%d", &k);
			memset(data[k].start, 0, sizeof(data[k].start));
			memset(data[k].start_time, 0, sizeof(data[k].start_time));
			data[k].odometer_start='\0';
			memset(data[k].end, 0, sizeof(data[k].end));
			memset(data[k].end_time, 0, sizeof(data[k].end_time));
			data[k].odometer_stop='\0';

			break;
		case 6:
			printf("Driving Diary's report:\n ");
			print();
			break;
		case 7:
			l=0;
			k=0;
			printf("Enter the shortest desired trip length in km: \n ");
			scanf("%i", &a);
			printf("Enter the longest desired trip length in km: \n ");
			scanf("%i", &b);
			for (i=0; i<20; i++)
			{
				if (data[i].odometer_start!=0) {
					k = i;
				}}
			i=1;
			while (i!=k+1)
			{
				if (data[i].odometer_stop - data[i].odometer_start >= a && data[i].odometer_stop - data[i].odometer_start <= b) {
					c[l]=i;
					l++;}
				i++;
			}
			i=0;
			printf("\n%-5s %-10s %-10s %-10s %-10s %-10s %-10s","No", "Start","Time","Odometer","Destination", "Arrived", "km at end"); 
			while (i!=l)
			{ k=c[i];
			//printf("\n %i", k);
			printf("\n%-5d %-10s %-10s %-10d %-10s %-10s %-10d", data[k].order, data[k].start, data[k].start_time, data[k].odometer_start, data[k].end, data[k].end_time, data[k].odometer_stop);
			i++;

			}
			printf("\n\n");
			c[i]='\0';
			break;
		case 8:
			printf("Thank you for using driving diary! \n ");
			return 0;
			break;
		}
	}
}


struct drivingDiary inputData()
{

	struct drivingDiary y;
	printf("\nEnter the name of the start location: \n");
	scanf("%s", y.start);
	printf("\nEnter the time when you started the trip: \n");
	scanf("%s", y.start_time);
	printf("\nEnter the odometer value at the start: \n");
	scanf("%d", &y.odometer_start);
	printf("\nEnter the name of the final destination of the trip: \n");
	scanf("%s", y.end);
	printf("\nEnter the arrival time at the destination: \n");
	scanf("%s", y.end_time);
	printf("\nEnter the odometer value after the trip: \n");
	scanf("%d", &y.odometer_stop);
	return y;
}
void displayDiary(struct drivingDiary w)
{
	printf("Enter the trip information: \n");
}

void save()
{
	FILE *outfile = NULL; 
	erase();
	outfile = fopen(MYFILE, "ab");

	if(outfile == NULL) {printf("Cannot open %s\n", MYFILE); }
	else { 
		i=1;
		while (i!=20){		
			fwrite(&data[i],sizeof(struct drivingDiary),i,outfile);
			i++;}
		fclose(outfile);
	}

}

void print()
{
	int i=1;
	int l=0;
	printf("\n%-5s %-10s %-10s %-10s %-10s %-10s %-10s","No", "Start","Time","Odometer","Destination", "Arrived", "km at end"); 
	for (i=1; i<20; i++)
	{
		if (data[i].odometer_start!=0) {
			l = i;
		}
	}
	i=1;
	while (i!=l+1) {
		printf("\n%-5d %-10s %-10s %-10d %-10s %-10s %-10d", data[i].order, data[i].start, data[i].start_time, data[i].odometer_start, data[i].end, data[i].end_time, data[i].odometer_stop);
		i++;}
	printf("\n\n");
}
void print_m()
{
	printf("\nDriving Diary\n");
	printf("Menu: \n");
	printf("(1) Initialize (erase all data from file) \n");
	printf("(2) Save trip data to memory \n");
	printf("(3) Read trip data from memory \n");
	printf("(4) Add a new trip \n");
	printf("(5) Remove a trip \n");
	printf("(6) Print a report \n");
	printf("(7) Display trips for the desired distance (km) \n");
	printf("(8) Exit the program \n");
}

void erase() {
	FILE *outfile1 = NULL;
	outfile1 = fopen(MYFILE, "w");
	fputs("\0", outfile1);
	fclose(outfile1);
}