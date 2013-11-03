#include "optionsdialog.h"
#include <QMessageBox>

OptionsDialog::OptionsDialog(QWidget *parent)
  : QDialog(parent)
{
  setWindowTitle(tr("Options"));
  setFixedSize(minimumSize());
  create_layout();
  create_options();
  create_dialog_buttons();
}

void OptionsDialog::create_layout()
{
  options_layout = new QGridLayout;
  button_box = new QDialogButtonBox;
  main_layout = new QVBoxLayout;
  main_layout->addLayout(options_layout);

  setLayout(main_layout);
}

void OptionsDialog::create_options()
{
  no_title_combo = new QComboBox;
  no_title_combo->addItem(tr("Infinity"));
  no_title_combo->insertSeparator(1);

  for(int i=0; i <= 35; i+=5)
    no_title_combo->addItem(QString::number(i));

  for(int i=40; i<=100; i+=10)
    no_title_combo->addItem(QString::number(i));

  save_title_lbl = new QLabel(tr("Number of titles saved for reuse:"));
  save_title_lbl->setToolTip(tr("The latest number of titles shown in drop down menu"));
  save_title_lbl->setBuddy(no_title_combo);

  clear_title_btn = new QPushButton(tr("Clear titles"));
  clear_title_btn->setToolTip(tr("Clears all buffered titles shown in drop down menu"));
  connect(clear_title_btn, &QPushButton::clicked, this, &OptionsDialog::clear_title_clicked);

  clear_title_lbl = new QLabel(tr("Clear all buffered titles:"));
  clear_title_lbl->setToolTip(tr("Clears all bffered titles shown in drop down menu"));
  clear_title_lbl->setBuddy(clear_title_btn);

  no_act_combo = new QComboBox;
  no_act_combo->addItem(tr("Infinity"));
  no_act_combo->insertSeparator(1);

  for(int i=0; i <= 35; i+=5)
    no_act_combo->addItem(QString::number(i));

  for(int i=40; i<=100; i+=10)
    no_act_combo->addItem(QString::number(i));

  save_act_lbl = new QLabel(tr("Number of activities saved for reuse:"));
  save_act_lbl->setToolTip(tr("The latest number of activities shown in drop down menu"));

  clear_act_btn = new QPushButton(tr("Clear activities"));
  clear_act_btn->setToolTip(tr("Clears all buffered activities shown in drop down menu"));
  connect(clear_act_btn, &QPushButton::clicked, this, &OptionsDialog::clear_act_clicked);

  clear_act_lbl = new QLabel(tr("Clear all buffered activities:"));
  clear_act_lbl->setToolTip(tr("Clears all buffered activities shown in drop down menu"));
  clear_act_lbl->setBuddy(clear_act_btn);

  options_layout->addWidget(save_title_lbl, 0, 0);
  options_layout->addWidget(no_title_combo, 0, 1);
  options_layout->addWidget(clear_title_lbl, 1, 0);
  options_layout->addWidget(clear_title_btn, 1, 1);
  options_layout->addWidget(save_act_lbl, 2, 0);
  options_layout->addWidget(no_act_combo, 2, 1);
  options_layout->addWidget(clear_act_lbl, 3, 0);
  options_layout->addWidget(clear_act_btn, 3, 1);
}

void OptionsDialog::create_dialog_buttons()
{
  line = new QFrame();
  line->setFrameShape(QFrame::HLine);
  line->setFrameShadow(QFrame::Sunken);
  options_layout->addWidget(line, 4, 0, 1, -1);

  button_box = new QDialogButtonBox(QDialogButtonBox::Ok |
				    QDialogButtonBox::Cancel);
  connect(button_box, &QDialogButtonBox::accepted, this, &OptionsDialog::ok_clicked);
  connect(button_box, &QDialogButtonBox::rejected, this, &OptionsDialog::cancel_clicked);
  options_layout->addWidget(button_box, 5, 0, 1, -1);
}

void OptionsDialog::clear_title_clicked()
{
  QMessageBox msg_box{this};
  msg_box.setWindowTitle(tr("Delete"));
  msg_box.setText(tr("Are you sure you want to delete all buffered titles?"));
  msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msg_box.setIcon(QMessageBox::Critical);
  int answer = msg_box.exec();
}

void OptionsDialog::clear_act_clicked()
{
  QMessageBox msg_box{this};
  msg_box.setWindowTitle(tr("Delete"));
  msg_box.setText(tr("Are you sure you want to delete all buffered activities?"));
  msg_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  msg_box.setIcon(QMessageBox::Critical);
  int answer = msg_box.exec();
}


void OptionsDialog::ok_clicked()
{
  delete this;
}

void OptionsDialog::cancel_clicked()
{
  delete this;
}

OptionsDialog::~OptionsDialog()
{
}
