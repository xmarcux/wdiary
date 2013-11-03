#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFrame>

class OptionsDialog : public QDialog
{
  Q_OBJECT

 private:
  QVBoxLayout *main_layout;
  QGridLayout *options_layout;
  QFrame *line;
  QDialogButtonBox *button_box;

  QLabel *save_act_lbl;
  QLabel *save_title_lbl;
  QLabel *clear_act_lbl;
  QLabel *clear_title_lbl;

  QComboBox *no_act_combo;
  QComboBox *no_title_combo;

  QPushButton *clear_act_btn;
  QPushButton *clear_title_btn;

  void create_layout();
  void create_options();
  void create_dialog_buttons();

 public slots:
   void clear_title_clicked();
   void clear_act_clicked();

   void ok_clicked();
   void cancel_clicked();

 public:
  OptionsDialog(QWidget *parent=0);
  ~OptionsDialog();

};

#endif  //OPTIONSDIALOG_H
