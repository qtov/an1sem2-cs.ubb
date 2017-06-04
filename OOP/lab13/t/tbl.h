#ifndef TBL_H
#define TBL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include "observer.h"
#include "controller.h"
#include <stdio.h> //delete
#include <cstdlib>
#include <ctime>

namespace Ui {
	class tbl;
}

class tbl : public QWidget, public Observer
{
	Q_OBJECT

public:
	explicit tbl(controller *ctrl, QWidget *parent = 0);
	void update() override {
		update_tbl();
	}
	~tbl();

private:
	Ui::tbl *ui;
	controller *ctrl;
	void	setup_gui();
	void	connect_gui();
	void	update_tbl();
	QListWidget *lst;
	QPushButton *gen_btn;
	QPushButton *em_btn;
	QPushButton *rm_btn;
	QPushButton *add_btn;
	QPushButton *list_btn;
	QPushButton *paint_btn;

public slots:
	void	add();
	void	copy();
	void	empty_list();
	void	gen_list();
	void	copy_paint();
	void	remove_last();
};

#endif // TBL_H
