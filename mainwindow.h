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
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMenu>
#include <QAction>
#include <QDate>
#include "treewidgetmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /** File menu */
    QMenu *file_menu;
    QAction *exit_act;
    
    /** Tools menu */
    QMenu *tools_menu;
    QAction *export_act;
    QAction *options_act;

    /** Help menu */
    QMenu *help_menu;
    QAction *about_act;

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
    QComboBox *title_edit;
    
    QComboBox *hour_combo;
    QComboBox *minute_combo;
    QComboBox *activity_combo;

    QTextEdit *text_edit;

    /*
     * Sets booleans if input
     * is valid. If all inputs
     * are valid add button 
     * will be enabled.
     */
    bool date_valid;
    bool hour_valid;
    bool min_valid;
    bool title_valid;
    bool activity_valid;

    QPushButton *add_button;


    QVBoxLayout *bottom_layout;
    QHBoxLayout *radio_button_layout;
    QGroupBox *view_group;

    QRadioButton *today_radio;
    QRadioButton *week_radio;
    QRadioButton *month_radio;

    TreeWidgetMenu *entry_view;

    /**
     * Sets up the menubar.
     */
    void create_menu();

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

    /*
     * If all inputs are valid 
     * add item button wil then 
     * be enabled.
     */
    void set_add_button_enabled();

private slots:
    void show_about();
    void app_exit();
    void show_options();
    void show_export();

    void is_date_valid(const QDate &d);
    void is_hour_valid(int index);
    void is_min_valid(int index);
    void is_title_valid(const QString &text);
    void is_activity_valid(const QString &text);


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
