#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROGRAM_NAME "printdate"
#define CORRECT_INPUT_COUNT 4

typedef struct
{
  int year;
  int month;
  int day;
} Date;

const char *MONTH_NAMES[] = {
  "Invalid month",
  "January", "February", "March", "April",
  "May", "June", "July", "August",
  "September", "October", "November", "December"
};

const int DAYS_PER_MONTH[] = {
  0,
  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

 // Checks whether the correct number of command line arguments have been supplied.
 // If not, prints the usage message and exits the program.
void check_input_count(int count)
{
  void print_usage();
  if (count != CORRECT_INPUT_COUNT)
  {
    print_usage();
    exit(0);
  }
}

// Prints the usage message.
void print_usage(void)
{
  printf("Usage: %s year month day \n",PROGRAM_NAME);
}

// Prints the supplied Date structure.
void print_date(Date *d)
{
  printf("%s %d, %d \n",MONTH_NAMES[d->month],d->day, d->year);
}
// Checks whether the supplied date is a leap year.
bool is_leap_year(Date *d)
{
  if ((d->year %400 ==0) || ((d->year %4 == 0) && (d->year % 100 != 0)))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks whether the supplied date has a valid year.
bool check_year(Date *d)
{
  if ((d->year > 0) && (d->year <= 9999))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks whether the supplied date has a valid month.
bool check_month(Date *d)
{
  if ((d->month >= 1) && (d->month <= 12))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks whether the supplied date has a valid day.
bool check_day(Date *d)
{
  bool leap_flag = is_leap_year(d);
  int count = d->month;
  if ((d->day >= 1) && (d->day <= DAYS_PER_MONTH[count]))
  {
    return true;
  }
  else if ((leap_flag == true) && ((d->month == 2) && (d->day == 29)))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Checks whether the supplied date is valid.
bool check_date(Date *d)
{

  bool year_flag = check_year(d);
  bool month_flag = check_month(d);
  bool day_flag = check_day(d);
  if ((year_flag == true) && (month_flag == true) && (day_flag == true))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Sets the fields of the supplied date structure from the command line parameters.
bool get_date(Date* d, char** arr)
{
  if ((d->year = atoi(arr[1])) && (d->month = atoi(arr[2])) && (d->day = atoi(arr[3])))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// The main program
int main(int argc, char *argv[])
{
  check_input_count(argc);
// set pointer to structure
  Date input_date;
  Date *d;
  d = &input_date;

//first stage check check only numbers , no other character, digits, mix of digits and characters are present
int counter[3] = {0, 0, 0};
// take argv[1], argv[2], argv[3]

for (int i = 1; i < argc; i++)
{
  for (int j = 0; (argv[i][j]) !='\0'; j++)
  {
    if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
    counter[i-1]++;
  }
}

if (counter[0] != 0)
{
  printf("year must be a number. \n");
}
else if (counter[1] != 0)
{
  printf("month must be a number. \n");
}
else if (counter[2] != 0)
{
  printf("day must be a number. \n");
}
else
{
  //get all parameters
  bool get_date_success = get_date(d, argv);
  bool year_check = check_year(d);
  bool month_check = check_month(d);
  bool day_check = check_day(d);
  bool date_check = check_date(d);

  if (get_date_success = true)
  {
    if (date_check == true)
    {
      print_date(d);
    }
    else
    {
      if (year_check == false)
      {
        printf("Error: invalid year. \n");
      }
      else if (month_check == false)
      {
        printf("Error: invalid month. \n");
      }
      else
      {
        printf("Error: invalid day. \n");
// De Morgan's law ~(A&B&C)== ~A V ~B V ~C
      }
    }
  }
}


return 0;
}

