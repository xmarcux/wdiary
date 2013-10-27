#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QDate>

class Activity
{
private:
    int _year;
    int _month;
    int _day;

    int _hours;
    int _minutes;

    QString _title;
    QString _activity;
    QString _description;

public:
    Activity();
    Activity(int y, int m, int d);
    Activity(int y, int m, int d, int h, int min);

    int year() const;
    int month() const;
    int day() const;
    int hours() const;
    int minutes() const;
    QDate date() const;

    QString title() const;
    QString activity() const;
    QString description() const;

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHours(int h);
    void setMinutes(int min);
    void setTitle(QString t);
    void setActivity(QString a);
    void setDescription(QString d);
};

#endif // ACTIVITY_H
