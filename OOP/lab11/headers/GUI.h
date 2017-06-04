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
	~GUI();
private:
	QLineEdit* txt_title;
	QLineEdit* txt_desc;
	QLineEdit* txt_type;
	QLineEdit* txt_dur;
	QPushButton* add_btn;
	QPushButton* upd_btn;
	QPushButton* rm_btn;
	QPushButton* fil_desc_btn;
	QPushButton* fil_type_btn;
	QPushButton* fil_search_btn;
	QPushButton* sort_title_btn;
	QPushButton* sort_desc_btn;
	QPushButton* sort_type_btn;
	QPushButton* undo_btn;
	QPushButton* refresh_btn;
	QPushButton* shuffle_btn;
	QListWidget* activities;
	Controller* ctrl;
	void	setup_gui();
	void	connect_gui();
	void	add_to_list(Activity&);
	void	update_list();

public slots:
	void	add();
	void	edit();
	void	remove();
	void	search();
	void	undo();
	void	refresh_list();
	void	sort_title();
	void	sort_desc();
	void	sort_type();
	void	filter_desc();
	void	filter_type();
	void	shuffle();

private:
	vector<QListWidgetItem*> act_lst;
};

#endif
