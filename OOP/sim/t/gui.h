#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "controller.h"
#include <QLineEdit>
#include <QPushButton>
#include <string>
#include <QListWidget>
#include <vector>

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(Controller *ctrl, QWidget *parent = 0);
	~GUI();
private:
	Controller *ctrl;
	void	setup_gui();
	void	connect_gui();
	QPushButton *ladd_btn;
	QPushButton *radd_btn;
	QPushButton *lmv_btn;
	QPushButton *rmv_btn;
	QLineEdit *id_txt;
	QLineEdit *name_txt;
	QLineEdit *val_txt;
	void	refresh_lists();
	QListWidget *lst1;
	QListWidget *lst2;

public slots:
	void	add();
	void	add2();
};

#endif // GUI_H
