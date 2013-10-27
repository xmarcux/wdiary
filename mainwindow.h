#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QCalendarWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTreeWidget>
#include <QStandardItemModel>
#include <QStandardItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *main_layout;
    QHBoxLayout *top_layout;
    QGridLayout *new_layout;
    QVBoxLayout *calendar_layout;

    QWidget *main_widget;
    QCalendarWidget *calendar;

    QGroupBox *new_group;
    QLabel *date_label;
    QLabel *title_label;
    QLabel *hour_label;
    QLabel *minute_label;
    QLabel *activity_label;
    QLabel *text_label;

    QDateEdit *date_edit;
    QLineEdit *title_edit;
    
    QComboBox *hour_combo;
    QComboBox *minute_combo;
    QComboBox *activity_combo;

    QTextEdit *text_edit;

    QPushButton *add_button;


    QVBoxLayout *bottom_layout;
    QHBoxLayout *radio_button_layout;
    QGroupBox *view_group;

    QRadioButton *today_radio;
    QRadioButton *week_radio;
    QRadioButton *month_radio;

    QTreeWidget *entry_view;

    /**
     * Sets up layout needed
     * for main window.
     */
    void create_layout();

    /**
     * Sets up, creates and lays
     * out widget for the top
     * half of the main window.
     * Input for adding new diary
     * entry and a calendar.
     */
    void create_top_layout();

    /**
     * Sets up, creates and lays
     * out widget for the bottom
     * half of the main window.
     * Filtered view of existing 
     * diary entiries.
     */
    void create_bottom_layout();

    /**
     * Sets up, creates and lays
     * out the tree view for
     * current items.
     */
    void create_tree_view();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
