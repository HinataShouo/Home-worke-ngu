#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

struct TDate {
	int day;
	int month;
	int year;
}; //можно typedef

int CreateDate(struct TDate* Date){
	printf("Enter date: ");
	if (scanf("%d %d %d", &Date->year, &Date->month, &Date->day) == 3) { //странно, что ты вводишь дату в формате yyyy:mm:dd
		return 1;
	}
	else {
		return 0;
	}
    //можешь попробовать использовать assert, чтобы не использовать для проверки 0 и 1
}

int CheckDayInMonths(int* array, struct TDate* Date) {
	if (Date->month > 0 && Date->month < 13) {
		int NumberOfDays = Date->day + array[Date->month - 1];
		return NumberOfDays;
	}
	else {
		return 0;
	}
}

int DateToDay(struct TDate* Date,int NumberOfDays) {
	int sum = Date->year * 365 + NumberOfDays; //можно все константы вынести в enum
	return sum;
}

int EnterNewDay() {
	int NewDay;
	printf("How much to change the date: ");
	if (scanf("%d", &NewDay) == 1) {
		return NewDay;
	}
	else {
		return 0;
	}
}

void AdvanceDate(struct TDate* Date, int* Sum, int n) //зачем тут Date?
{
	*Sum += n;
}

void NewDateToDay(struct TDate* Date, int allday,int* arrayM,int* arrayMOS ) {
	Date->year = allday / 365;
	allday = allday - (allday / 365) /*можно заменить на Date->year*/ * 365;

    //цикл хреново работает
    //Enter date: 2020 1 1  
    //How much to change the date: 31
    //2020 year 2 months 4 day

	for (int i = 0; i < 12; ++i) {
		if (allday > arrayMOS[i]) {
			Date->month = i + 1;
		}
		else {
			Date->day = allday - arrayMOS[i-1];
			break;
		}
	}

}
void PrintDate(struct TDate* Date) {
	printf("%d year %d months %d day", Date->year, Date->month, Date->day);
}

int main(void)
{
	struct TDate Date;

	int MonthOfSet[12] = { 31,59,90,120,151,181,212,243,273,304,334,365 }; //как то странно, что этот массив в ручную вводится
	int Months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	CreateDate(&Date);

	int SumDay = DateToDay(&Date, CheckDayInMonths(MonthOfSet, &Date)); 
	AdvanceDate(&Date, &SumDay, EnterNewDay()); //можно SumDay передавать не как указатель, это бесполезно

	NewDateToDay(&Date, SumDay, Months, MonthOfSet);
	PrintDate(&Date);

	return 0;
}
