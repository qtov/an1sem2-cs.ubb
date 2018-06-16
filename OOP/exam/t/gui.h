#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>	
#include <QLabel>
#include "song.h"

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(Controller*, QWidget *parent = 0);
	~GUI();

private:
	Controller* ctrl;
	void	setup_gui();
	void	connect_gui();
	QLineEdit* id_txt;
	QLineEdit* tit_txt;
	QLineEdit* art_txt;
	QLineEdit* rnk_txt;
	QListWidget* lst;
	QPushButton* add_btn;
	QPushButton* upd_btn;
	QPushButton* rm_btn;
	void	update_list();

private slots:
	void	add();
	void	rm();
	void	edit();
	void	upd_txt(QListWidgetItem*);
};

#endif // GUI_H
