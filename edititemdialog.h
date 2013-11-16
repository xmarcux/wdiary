#ifndef EDITITEMDIALOG_H
#define EDITITEMDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QDateEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QString>
#include <QDate>

class EditItemDialog : public QDialog
{
  Q_OBJECT

 private:
  QGridLayout *top_layout;
  QVBoxLayout *main_layout;

  QLabel *date_lbl;
  QLabel *hour_lbl;
  QLabel *minute_lbl;
  QLabel *title_lbl;
  QLabel *activity_lbl;
  QLabel *text_edit_lbl;

  QDateEdit *date_edit;
  QComboBox *hour_combo;
  QComboBox *minute_combo;
  QComboBox *title_combo;
  QComboBox *activity_combo;
  QTextEdit *text_edit;

  QPushButton *save_button;
  QDialogButtonBox *button_box;

  bool date_valid;
  bool hour_valid;
  bool min_valid;
  bool title_valid;
  bool activity_valid;

  void create_layout();
  void create_top_items();
  void create_bottom_items();
  void create_buttons();

  void set_save_button_enabled();

private slots:
  void cancel_clicked();
  void save_clicked();

  void is_date_valid(const QDate &d);
  void is_hour_valid(int index);
  void is_min_valid(int index);
  void is_title_valid(const QString &text);
  void is_activity_valid(const QString &text);

 public:
  EditItemDialog(QWidget *parent=0);
  ~EditItemDialog();
};

#endif //EDITITEMDIALOG_H
