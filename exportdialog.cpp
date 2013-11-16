#include "exportdialog.h"
#include <QSizePolicy>
#include <QTreeWidgetItem>
#include <QFileDialog>

ExportDialog::ExportDialog(QWidget *parent) 
  : QDialog(parent)
{
  setWindowTitle(tr("Export"));
  setModal(true);

  create_layout();
  create_file_field();
  create_date_page();
  create_search_page();
  create_dialog_buttons();
}

void ExportDialog::create_layout()
{
  file_layout = new QHBoxLayout;
  main_layout = new QVBoxLayout;
  tab_choose = new QTabWidget;

  setLayout(main_layout);

}

void ExportDialog::create_file_field()
{
  headline_lbl = new QLabel(tr("Export selected options to a specified text file"));
  file_lbl = new QLabel(tr("Enter export file path:"));
  main_layout->addWidget(headline_lbl);
  main_layout->addWidget(file_lbl);
  main_layout->addLayout(file_layout);

  file_edit = new QLineEdit;
  find_file_btn = new QPushButton("&Browse...");
  find_file_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  connect(find_file_btn, &QPushButton::clicked, this, &ExportDialog::open_file_dialog);

  file_layout->addWidget(file_edit);
  file_layout->addWidget(find_file_btn);
}

void ExportDialog::create_date_page()
{
  date_layout = new QVBoxLayout;
  radio_date_layout = new QHBoxLayout;

  date_lbl = new QLabel(tr("Select day/week/month and choose with calendar:"));

  day_radio_btn = new QRadioButton(tr("Day"), this);
  day_radio_btn->setChecked(true);
  week_radio_btn = new QRadioButton(tr("Week"), this);
  month_radio_btn = new QRadioButton(tr("Month"), this);
  
  radio_date_layout->addWidget(day_radio_btn);
  radio_date_layout->addWidget(week_radio_btn);
  radio_date_layout->addWidget(month_radio_btn);

  calendar = new QCalendarWidget;

  date_layout->addWidget(date_lbl);
  date_layout->addLayout(radio_date_layout);
  date_layout->addWidget(calendar);

  date_page = new QWidget;
  date_page->setLayout(date_layout);

  tab_choose->addTab(date_page, tr("&Date"));
  main_layout->addWidget(tab_choose);
}

void ExportDialog::create_search_page()
{
  search_layout = new QVBoxLayout;
  search_field_layout = new QHBoxLayout;
  
  search_lbl = new QLabel(tr("Search for title:"));
  search_edit = new QLineEdit;
  search_btn = new QPushButton(tr("S&earch"));
  search_field_layout->addWidget(search_edit);
  search_field_layout->addWidget(search_btn);

  search_result_lbl = new QLabel(tr("Mark title to export in search result:"));
  search_view = new QTreeWidget;
  search_view->setHeaderLabel(tr("Search results:"));
  search_view->setRootIsDecorated(false);
  QTreeWidgetItem *item = new QTreeWidgetItem(search_view);
  item->setText(0, tr("Enter searched title..."));
  
  search_layout->addWidget(search_lbl);
  search_layout->addLayout(search_field_layout);
  search_layout->addWidget(search_result_lbl);
  search_layout->addWidget(search_view);

  search_page = new QWidget;
  search_page->setLayout(search_layout);

  tab_choose->addTab(search_page, tr("&Search"));
}

void ExportDialog::create_dialog_buttons()
{
  button_box = new QDialogButtonBox;
  button_box->addButton(tr("&Export"), QDialogButtonBox::AcceptRole);
  button_box->addButton(QDialogButtonBox::Cancel);

  connect(button_box, &QDialogButtonBox::accepted, this, &ExportDialog::button_export_clicked);
  connect(button_box, &QDialogButtonBox::rejected, this, &ExportDialog::button_cancel_clicked);

  main_layout->addWidget(button_box);
}

void ExportDialog::open_file_dialog()
{
  QString filename = QFileDialog::getSaveFileName(this, tr("Choose export file"), "",
						  tr("Text files (*.txt)"));
  file_edit->setText(filename);
}

void ExportDialog::button_export_clicked()
{
  //Do export
  delete this;
}

void ExportDialog::button_cancel_clicked()
{
  delete this;
}

ExportDialog::~ExportDialog()
{
}
