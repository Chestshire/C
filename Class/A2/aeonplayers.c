#include <stdio.h>

//returns true if this year is a leap year
_Bool isLeapYear(int year)
{
  return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))?1:0;
}

//returns true if the info is an invalid date
_Bool isInvalid(int day,int month,int year)
{
  _Bool invalid=0;
  switch (month)
  {
    // with 31 days
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    if (day > 31)
    {
      invalid = 1;
    }
    break;
    //with 28 or 29 days
  case 2:
    if (day > 29)
    {
      invalid = 1;
    }
    if (!isLeapYear(year))
    {
      if (day > 28)
      {
        invalid = 1;
      }
    }
    break;
    // with 30 days
  case 4:
  case 6:
  case 9:
  case 11:
    if (day > 30)
    {
      invalid = 1;
    }
    break;
  default:
    invalid = 1;
  }
  return invalid;
}

//Main operating function (Gate)
void aeon_players_day(int day, int month, int year)
{
  //potential invalid inputs
  _Bool invalid = isInvalid(day,month,year);

  if (day == 0 || month == 0 || year == 0)
  {
    invalid = 1;
  }
  if (invalid)
  {
    printf("Invalid date\n");
    return;
  }

//calculate the days between normal date and the aeon date
  int extraDays = 0;
  int dayC = day, monthC = month, yearC = year;
  if (year < 1756)  //Before 1756, no 29th in Feb
  {
    if (monthC == 2 && dayC == 29)
    {
      printf("Invalid date\n");
      return;
    }
  }
  else
  {
    for (int s = year; s >= 1756; --s)
    {
      if (isLeapYear(s))
      {
        ++extraDays;
      }
    }
    //have not yet been to the extra day in Feburary
    if (monthC < 3 && dayC < 29)
    {
      --extraDays;
    }
  }

  for (int i = extraDays; i > 0; --i)
  {
    ++dayC;
    //when dayC <= 28, there is no need to enter the conditional control statements
    if (dayC > 28)
    {
      switch (monthC)
      {
      // with 28 days
      case 2:
        dayC = 1;
        ++monthC;
        break;
        // with 30 days
      case 4:
      case 6:
      case 9:
      case 11:
        if (dayC > 30)
        {
          dayC = 1;
          ++monthC;
        }
        break;
        // with 31 days
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        if (dayC > 31)
        {
          dayC = 1;
          if (monthC == 12)
          {
            ++yearC;
            monthC = 1;
          }
          else
          {
            ++monthC;
          }
        }
        break;
      // unexpected situation when default is triggered
      default:
        printf("should not reach here.\n");
      }
    }
  }

  printf("%02d/%02d/%d becomes %02d/%02d/%d\n", day, month, year, dayC, monthC, yearC);
  return;
}

/* int main(void)
{
  aeon_players_day(1, 1, 1);
  aeon_players_day(1, 1, 0);
  aeon_players_day(1, 0, 1);
  aeon_players_day(0, 1, 1);
  aeon_players_day(29, 2, 1752);
  aeon_players_day(29, 2, 1756);
  aeon_players_day(31, 12, 1755);
  aeon_players_day(31, 12, 1756);
  aeon_players_day(28, 2, 3260);
  aeon_players_day(29, 2, 3260);
  aeon_players_day(29, 2, 1800);
  return 0;
} */
