#include "gui.h"
#include "controller.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>

using namespace std;

GUI::GUI(Controller *_ctrl, QWidget *parent)
	: QWidget(parent)
{
	this->setup_gui();
	this->connect_gui();
	this->ctrl = _ctrl;
}

GUI::~GUI()
{

}

void	GUI::connect_gui()
{
	QObject::connect(ladd_btn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(radd_btn, SIGNAL(clicked()), this, SLOT(add2()));
}

void	GUI::setup_gui()
{
	QHBoxLayout *main_lay = new QHBoxLayout(this);

	this->setLayout(main_lay);

	this->lst1 = new QListWidget();
	main_lay->addWidget(lst1);

	QVBoxLayout *btn_lay = new QVBoxLayout();
	main_lay->addLayout(btn_lay);

	this->id_txt = new QLineEdit();
	this->name_txt = new QLineEdit();
	this->val_txt = new QLineEdit();

	btn_lay->addWidget(id_txt);
	btn_lay->addWidget(name_txt);
	btn_lay->addWidget(val_txt);

	QHBoxLayout *add_lay = new QHBoxLayout();
	QHBoxLayout *mv_lay = new QHBoxLayout();

	btn_lay->addLayout(add_lay);
	btn_lay->addLayout(mv_lay);

	this->ladd_btn = new QPushButton(QObject::tr("&AddL"));
	this->radd_btn = new QPushButton(QObject::tr("A&ddR"));

	this->lmv_btn = new QPushButton(QObject::tr("Move&L"));
	this->rmv_btn = new QPushButton(QObject::tr("Move&R"));

	add_lay->addWidget(ladd_btn);
	add_lay->addWidget(radd_btn);

	mv_lay->addWidget(lmv_btn);
	mv_lay->addWidget(rmv_btn);

	this->lst2 = new QListWidget();
	main_lay->addWidget(lst2);
}

void	GUI::add()
{
	QString name;
	QString id;
	QString val;

	name = this->name_txt->text();
	id = this->id_txt->text();
	val = this->val_txt->text();

	this->ctrl->add(id, name, val);
	this->refresh_lists();
}

void	GUI::add2()
{
	QString name;
	QString id;
	QString val;

	name = this->name_txt->text();
	id = this->id_txt->text();
	val = this->val_txt->text();

	this->ctrl->add2(id, name, val);
	this->refresh_lists();
}

void	GUI::refresh_lists()
{
	vector<Player> _lst;
	vector<Player> _lst2;

	this->lst1->clear();
	this->lst2->clear();

	_lst = this->ctrl->get_lst();
	_lst2 = this->ctrl->get_lst2();

	for (auto elem : _lst)
	{
		QString qs = "";

		qs += QString::number(elem.id);
		qs += " ";
		qs += elem.name;
		qs += " ";
		qs += QString::number(elem.val);
		new QListWidgetItem(qs, this->lst1);
	}
	for (auto elem : _lst2)
	{
		QString qs = "";

		qs += QString::number(elem.id);
		qs += " ";
		qs += elem.name;
		qs += " ";
		qs += QString::number(elem.val);
		new QListWidgetItem(qs, this->lst2);
	}
}