#include "activity.h"

Activity::Activity() : 
  _year{0}, _month{0}, _day{0}, _hours{0}, _minutes{0},
  _title(""), _activity(""), _description("")
{
}

Activity::Activity(int y, int m, int d) :
  _year{y}, _month{m}, _day{d}, _hours{0}, _minutes{0},
  _title(""), _activity(""), _description("")
{
}

Activity::Activity(int y, int m, int d, int h, int min) :
  _year{y}, _month{m}, _day{d}, _hours{h}, _minutes{min},
  _title(""), _activity(""), _description("")
{
}

int Activity::year() const
{
  return _year;
}

int Activity::month() const
{
  return _month;
}

int Activity::day() const
{
  return _day;
}

int Activity::hours() const
{
  return _hours;
}

int Activity::minutes() const
{
  return _minutes;
}

QDate Activity::date() const
{
  return QDate(_year, _month, _day);
}

QString Activity::title() const
{
  return _title;
}

QString Activity::activity() const
{
  return _activity;
}

QString Activity::description() const
{
  return _description;
}

void Activity::setYear(int y)
{
  _year = y;
}

void Activity::setMonth(int m)
{
  _month = m;
}

void Activity::setDay(int d)
{
  _day = d;
}

void Activity::setHours(int h)
{
  _hours = h;
}

void Activity::setMinutes(int min)
{
  _minutes = min;
}

void Activity::setTitle(QString t)
{
  _title = t;
}

void Activity::setActivity(QString a)
{
  _activity = a;
}

void Activity::setDescription(QString d)
{
  _description = d;
}

