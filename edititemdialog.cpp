#include "edititemdialog.h"

#include <QString>

EditItemDialog::EditItemDialog(QWidget *parent)
  : QDialog(parent)
{
  setWindowTitle(tr("Edit item"));
  setModal(true);
  create_layout();
  create_top_items();
  create_bottom_items();
  create_buttons();
}

void EditItemDialog::create_layout()
{
  top_layout = new QGridLayout;
  main_layout = new QVBoxLayout;
  main_layout->addLayout(top_layout);
  setLayout(main_layout);
}

void EditItemDialog::create_top_items()
{
  date_lbl = new QLabel(tr("Date:"));
  top_layout->addWidget(date_lbl, 0, 0);
  date_edit = new QDateEdit;
  connect(date_edit, &QDateEdit::dateChanged, this, &EditItemDialog::is_date_valid);
  top_layout->addWidget(date_edit, 0, 1, 1, -1);

  hour_lbl = new QLabel(tr("Hour:"));
  minute_lbl = new QLabel(tr("Minute:"));

  hour_combo = new QComboBox;
  connect(hour_combo, SIGNAL(activated(int)), this, SLOT(is_hour_valid(int)));
  for(int i=0; i<=24; i++){
    hour_combo->addItem(QString::number(i));
  }

  minute_combo = new QComboBox;
  connect(minute_combo, SIGNAL(activated(int)), this, SLOT(is_min_valid(int)));
  for(int i=0; i!=60; i+=5){
    minute_combo->addItem(QString::number(i));
  }

  top_layout->addWidget(hour_lbl, 1, 0);
  top_layout->addWidget(hour_combo, 1, 1);
  top_layout->addWidget(minute_lbl, 1, 2);
  top_layout->addWidget(minute_combo, 1, 3);
  
  title_lbl = new QLabel(tr("Title:"));
  top_layout->addWidget(title_lbl, 2, 0);
  title_combo = new QComboBox;
  title_combo->setEditable(true);
  connect(title_combo, &QComboBox::currentTextChanged, this, &EditItemDialog::is_title_valid);
  top_layout->addWidget(title_combo, 2, 1, 1, -1);

  activity_lbl = new QLabel(tr("Activity:"));
  top_layout->addWidget(activity_lbl, 3, 0);
  activity_combo = new QComboBox;
  activity_combo->setEditable(true);
  connect(activity_combo, &QComboBox::currentTextChanged, this, &EditItemDialog::is_activity_valid);
  top_layout->addWidget(activity_combo, 3, 1, 1, -1);
}

void EditItemDialog::create_bottom_items()
{
  text_edit_lbl = new QLabel(tr("Description of work performed:"));
  main_layout->addWidget(text_edit_lbl);
  text_edit = new QTextEdit;
  main_layout->addWidget(text_edit);
}

void EditItemDialog::create_buttons()
{
  save_button = new QPushButton;
  save_button->setText(tr("Save"));
  save_button->setEnabled(false);

  button_box = new QDialogButtonBox;
  button_box->addButton(save_button, QDialogButtonBox::AcceptRole);
  button_box->addButton(QDialogButtonBox::Cancel);
  connect(button_box, &QDialogButtonBox::accepted, this, &EditItemDialog::save_clicked);
  connect(button_box, &QDialogButtonBox::rejected, this, &EditItemDialog::cancel_clicked);

  main_layout->addWidget(button_box);
}

void EditItemDialog::cancel_clicked()
{
  delete this;
}

void EditItemDialog::save_clicked()
{
  //save to file and list in main window
  delete this;
}

void EditItemDialog::is_date_valid(const QDate &d)
{
  if(d.isValid())
     date_valid = true;
  else
    date_valid = false;

  set_save_button_enabled();
}

void EditItemDialog::is_hour_valid(int index)
{
  if(index)
    hour_valid = true;
  else
    hour_valid = false;

  set_save_button_enabled();
}

void EditItemDialog::is_min_valid(int index)
{
  if(index)
    min_valid = true;
  else
    min_valid = false;

  set_save_button_enabled();
}

void EditItemDialog::is_title_valid(const QString &text)
{
  bool valid = false;
  for(auto pos = text.begin(); pos != text.end(); pos++){
    if(pos->isPrint() && !pos->isSpace()){
      valid = true;
      break;
    }
  }

  title_valid = valid;
  set_save_button_enabled();
}

void EditItemDialog::is_activity_valid(const QString &text)
{
  bool valid = false;
  for(auto pos = text.begin(); pos != text.end(); pos++){
    if(pos->isPrint() && !pos->isSpace()){
      valid = true;
      break;
    }
  }

  activity_valid = valid;
  set_save_button_enabled();
}

void EditItemDialog::set_save_button_enabled()
{
  if(date_valid && (hour_valid || min_valid) && title_valid && activity_valid)
    save_button->setEnabled(true);
  else
    save_button->setEnabled(false);
}

EditItemDialog::~EditItemDialog()
{
}
