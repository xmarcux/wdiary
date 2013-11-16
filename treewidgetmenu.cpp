#include "treewidgetmenu.h"
#include <QIcon>
#include <QMenu>
#include <QList>
#include <QMessageBox>

#include "edititemdialog.h"

TreeWidgetMenu::TreeWidgetMenu(QWidget *parent)
  : QTreeWidget(parent)
{
  setToolTip(tr("Right click for edit menu"));
  delete_item_act = new QAction(QIcon::fromTheme("edit-delete"), tr("Delete"), this);
  connect(delete_item_act, &QAction::triggered, this, &TreeWidgetMenu::delete_item);
  edit_item_act = new QAction(QIcon::fromTheme("document-open"), tr("Edit item..."), this);
  connect(edit_item_act, &QAction::triggered, this, &TreeWidgetMenu::edit_item);
}

void TreeWidgetMenu::contextMenuEvent(QContextMenuEvent *event)
{
  QList<QTreeWidgetItem *> items = selectedItems();

  bool show_menu;
  if(!items.empty()){
    if(items.first()->text(2) != "")
      show_menu = true;
    else
      show_menu = false;
  }
  else
    show_menu = false;

  if(show_menu){
    QMenu menu;
    menu.addAction(edit_item_act);
    QAction sep(this);
    sep.setSeparator(true);
    menu.addAction(&sep);
    menu.addAction(delete_item_act);
    menu.exec(event->globalPos());
  }
}

void TreeWidgetMenu::delete_item()
{
  QMessageBox del_box(this);
  del_box.setIcon(QMessageBox::Critical);
  del_box.setWindowTitle(tr("Delete"));
  del_box.setText(tr("Do you want to delete selected item?"));
  del_box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  int answer = del_box.exec();
}

void TreeWidgetMenu::edit_item()
{
  EditItemDialog *edit = new EditItemDialog(this);
  edit->exec();
}

TreeWidgetMenu::~TreeWidgetMenu()
{
}
