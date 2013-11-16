#ifndef TREEWIDGETMENU_H
#define TREEWIDGETMENU_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QAction>
#include <QContextMenuEvent>

class TreeWidgetMenu : public QTreeWidget
{
  Q_OBJECT

 private:
  QAction *delete_item_act;
  QAction *edit_item_act;

 private slots:
   void delete_item();
   void edit_item();

 protected:
  void contextMenuEvent(QContextMenuEvent *event);

 public:
  TreeWidgetMenu(QWidget *parent=0);
  ~TreeWidgetMenu();
};

#endif //TREEWIDGETMENU_H
