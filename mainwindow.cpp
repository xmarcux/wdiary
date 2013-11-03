#include "mainwindow.h"
#include "optionsdialog.h"

#include <QSizePolicy>
#include <Qt>
#include <QStringList>
#include <QTreeWidgetItem>
#include <QMenuBar>
#include <QIcon>
#include <QKeySequence>
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  create_menu();
  create_layout();
  create_top_layout();
  create_bottom_layout();
}

void MainWindow::create_menu()
{
  file_menu = menuBar()->addMenu(tr("&File"));
  exit_act = new QAction(QIcon::fromTheme("application-exit"), tr("&Exit"), this);
  exit_act->setShortcut(QKeySequence::Quit);
  connect(exit_act, &QAction::triggered, this, &MainWindow::app_exit);
  file_menu->addAction(exit_act);

  tools_menu = menuBar()->addMenu(tr("&Tools"));
  export_act = new QAction(tr("E&xport entries..."), this);
  export_act->setShortcut(QKeySequence(tr("Ctrl+X")));
  tools_menu->addAction(export_act);
  QAction *sep = new QAction(this);
  sep->setSeparator(true);
  tools_menu->addAction(sep);
  options_act = new QAction(tr("&Options..."), this);
  options_act->setShortcut(QKeySequence(tr("Ctrl+O")));
  connect(options_act, &QAction::triggered, this, &MainWindow::show_options);
  tools_menu->addAction(options_act);

  help_menu = menuBar()->addMenu(tr("&Help"));
  about_act = new QAction(QIcon::fromTheme("help-about"), tr("&About WDiary..."), this);
  about_act->setShortcut(QKeySequence(tr("Ctrl+A")));
  connect(about_act, &QAction::triggered, this, &MainWindow::show_about);
  help_menu->addAction(about_act);
}

void MainWindow::create_layout()
{
  main_widget = new QWidget;
  main_layout =  new QVBoxLayout;
  top_layout = new QHBoxLayout;
  new_layout = new QGridLayout;

  main_layout->addLayout(top_layout);
  main_widget->setLayout(main_layout);
  setCentralWidget(main_widget);
}

void MainWindow::create_top_layout()
{
  new_group = new QGroupBox(tr("Add new diary entry:"));
  new_group->setLayout(new_layout);
  top_layout->addWidget(new_group);

  date_label = new QLabel(tr("Date:"));
  date_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  title_label = new QLabel(tr("Title:"));
  title_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  hour_label = new QLabel(tr("Hour:"));
  hour_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  minute_label = new QLabel(tr("Minute:"));
  minute_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  activity_label = new QLabel(tr("Activity:"));
  activity_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
  text_label = new QLabel(tr("Description of work performed:"));

  date_edit = new QDateEdit;
  date_edit->setDate(QDate::currentDate());
  date_edit->setToolTip(tr("Enter date for diary entry, or click date on calendar."));

  activity_combo = new QComboBox;
  activity_combo->setEditable(true);
  activity_combo->addItem(tr("Documentation"));
  activity_combo->addItem(tr("Project leading"));
  activity_combo->addItem(tr("Programming"));
  activity_combo->addItem(tr("Graphics"));
  activity_combo->setCurrentText("");

  title_edit = new QComboBox;
  title_edit->setEditable(true);
  title_edit->setToolTip(tr("Enter title for diary entry."));

  hour_combo = new QComboBox;
  hour_combo->setToolTip(tr("Used hours for job entry."));
  hour_combo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  minute_combo = new QComboBox;
  minute_combo->setToolTip(tr("Used minutes for job entry."));
  minute_combo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  for(int i=0; i <= 24; i++){
    hour_combo->addItem(QString::number(i));
  }

  for(int i=0; i < 60; i+=5){
    minute_combo->addItem(QString::number(i));
  }

  text_edit = new QTextEdit;
  add_button = new QPushButton(tr("&Add new entry"));
  add_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  add_button->setDisabled(true);
  add_button->setToolTip(tr("Fill in information before clicking button."));

  new_layout->setColumnStretch(0, -1);
  new_layout->setColumnStretch(1, -1);
  new_layout->setColumnStretch(2, -1);
  new_layout->addWidget(date_label, 0, 0);
  new_layout->addWidget(date_edit, 0, 1, 1, -1);

  new_layout->addWidget(hour_label, 1, 0);
  new_layout->addWidget(hour_combo, 1, 1);
  new_layout->addWidget(minute_label, 1, 2);
  new_layout->addWidget(minute_combo, 1, 3);

  new_layout->addWidget(title_label, 2, 0);
  new_layout->addWidget(title_edit, 2, 1, 1, -1);
  new_layout->addWidget(activity_label, 3, 0);
  new_layout->addWidget(activity_combo, 3, 1, 1, -1);


  new_layout->addWidget(text_label, 4, 0, 1, -1);
  new_layout->addWidget(text_edit, 5, 0, 1, -1);
  new_layout->addWidget(add_button, 6, 4, 1, 1);
  new_layout->setAlignment(add_button, Qt::AlignRight);

  calendar = new QCalendarWidget;
  calendar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  calendar_layout = new QVBoxLayout;
  calendar_layout->setAlignment(Qt::AlignTop);
  calendar_layout->setAlignment(calendar, Qt::AlignTop);
  calendar_layout->addWidget(calendar);
  top_layout->addLayout(calendar_layout);

  connect(calendar, &QCalendarWidget::clicked, 
	  date_edit, &QDateEdit::setDate);
}

void MainWindow::create_bottom_layout()
{
  view_group = new QGroupBox(tr("Current diary entries:"));
  main_layout->addWidget(view_group);

  bottom_layout = new QVBoxLayout;
  view_group->setLayout(bottom_layout);

  radio_button_layout = new QHBoxLayout;
  bottom_layout->addLayout(radio_button_layout);

  today_radio = new QRadioButton(tr("&Todays entries:"), view_group);
  today_radio->setChecked(true);
  today_radio->setToolTip(tr("Choose date in calendar."));
  radio_button_layout->addWidget(today_radio);
  radio_button_layout->setAlignment(today_radio, Qt::AlignHCenter);
  week_radio = new QRadioButton(tr("This &weeks entries:"), view_group);
  week_radio->setToolTip(tr("Click on date in calender, that week will be shown."));
  radio_button_layout->addWidget(week_radio);
  radio_button_layout->setAlignment(week_radio, Qt::AlignHCenter);
  month_radio = new QRadioButton(tr("This &months entries:"), view_group);
  month_radio->setToolTip(tr("Current month in calendar will be shown."));
  radio_button_layout->addWidget(month_radio);
  radio_button_layout->setAlignment(month_radio, Qt::AlignHCenter);

  create_tree_view();
}

void MainWindow::create_tree_view()
{
  QStringList headers;
  headers << tr("Date") << tr("Time") << tr("Title") << tr("Description");
  entry_view = new QTreeWidget;
  entry_view->setHeaderLabels(headers);

  bottom_layout->addWidget(entry_view);

  QTreeWidgetItem *item1 = new QTreeWidgetItem(entry_view);
  item1->setText(0, "2013");

  QTreeWidgetItem *item2 = new QTreeWidgetItem(item1);
  item2->setText(0, "October");
  item2->setText(1, "146:30");

  QTreeWidgetItem *item3 = new QTreeWidgetItem(item2);
  item3->setText(0, "Week 43");
  item3->setText(1, "42:00");
}

void MainWindow::show_about()
{
  QString msg = tr("<center><b>WDiary Version 1.0.0</b><br/><br/>");
  msg += tr("A work diary to keep track of what you have done when.<br/>");
  msg += tr("Copyright (C) 2013  Marcus Pedersén<br/></center>");
  msg += tr("This program is free software: you can redistribute it and/or modify<br/>");
  msg += tr("it under the terms of the GNU General Public License as published by<br/>");
  msg += tr("the Free Software Foundation, either version 3 of the License, or<br/>");
  msg += tr("(at your option) any later version.<br/><br/>");
  msg += tr("This program is distributed in the hope that it will be useful,<br/>");
  msg += tr("but WITHOUT ANY WARRANTY; without even the implied warranty of<br/>");
  msg += tr("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the<br/>");
  msg += tr("GNU General Public License for more details.<br/><br/>");
  msg += tr("You should have received a copy of the GNU General Public License<br/>");
  msg += tr("along with this program.  If not, see http://www.gnu.org/licenses/<br/><br/>");
  msg += tr("Contact: marcux@marcux.org<br/>");
  msg += tr("Repro: https://github.com/xmarcux/wdiary");

  QMessageBox::about(this, tr("About WDiary"), msg);
}

void MainWindow::app_exit()
{
  QApplication::quit();
}

void MainWindow::show_options()
{
  OptionsDialog *opt = new OptionsDialog(this);
  opt->show();
}

MainWindow::~MainWindow()
{
}
