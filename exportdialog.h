#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QCalendarWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeView>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QDialogButtonBox>

class ExportDialog : public QDialog
{
  Q_OBJECT
  
 private:
  QVBoxLayout *main_layout;
  QHBoxLayout *file_layout;

  QLabel *headline_lbl;

  QLabel *file_lbl;
  QLineEdit *file_edit;
  QPushButton *find_file_btn;

  QTabWidget *tab_choose;
  QWidget *date_page;
  QVBoxLayout *date_layout;
  QHBoxLayout *radio_date_layout;
  QWidget *search_page;
  QVBoxLayout *search_layout;
  QHBoxLayout *search_field_layout;

  QLabel *date_lbl;
  QRadioButton *month_radio_btn;
  QRadioButton *week_radio_btn;
  QRadioButton *day_radio_btn;
  QCalendarWidget *calendar;
  
  QLabel *search_lbl;
  QLineEdit *search_edit;
  QPushButton *search_btn;

  QLabel *search_result_lbl;
  QTreeWidget *search_view;

  QDialogButtonBox *button_box;

  void create_layout();
  void create_file_field();
  void create_date_page();
  void create_search_page();
  void create_dialog_buttons();

 private slots:
  void open_file_dialog();
  void button_export_clicked();
  void button_cancel_clicked();

 public:
  ExportDialog(QWidget *parent);
  ~ExportDialog();
};

#endif //EXPORTDIALOG_H
