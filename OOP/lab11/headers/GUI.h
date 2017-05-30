#ifndef GUI_H
#define GUI_H

#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "Controller.h"

class GUI : public QWidget
{
	Q_OBJECT
public:
	GUI(Controller* ctrl);
	void	start();
private:
	QLineEdit* txt_title;
	QLineEdit* txt_desc;
	QLineEdit* txt_type;
	QLineEdit* txt_dur;
	QPushButton* add_btn;
	QPushButton* upd_btn;
	QPushButton* rm_btn;
	QPushButton* fil_desc;
	QPushButton* fil_type;
	QPushButton* fil_search;
	QPushButton* sort_title_btn;
	QPushButton* sort_desc_btn;
	QPushButton* sort_type_btn;
	QListWidget* activities;
	Controller* ctrl;
	QApplication* app;
	void		setup_gui();
	void		connect_gui();
	void		update_list();

public slots:
	void	add();
	void	edit();
	void	remove();
};

#endif
