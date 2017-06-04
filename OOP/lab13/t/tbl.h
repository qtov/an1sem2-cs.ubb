#ifndef TBL_H
#define TBL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include "observer.h"

namespace Ui {
class tbl;
}

class tbl : public QWidget, public Observable, public Observer
{
	Q_OBJECT

public:
	explicit tbl(QWidget *parent = 0);
	void update() override
	{
		update_list();
	}
	~tbl();

private:
	Ui::tbl *ui;
	void	setup_gui();
	void	update_list();
	QListWidget *lst;
	QPushButton *gen_btn;
	QPushButton *em_btn;
	QPushButton *add_btn;
	QPushButton *list_btn;
	QPushButton *paint_btn;
};

#endif // TBL_H
