#include "gui.h"
#include <iostream>

using namespace std;

GUI::GUI(Controller *_ctrl, QWidget *parent)
	: QWidget(parent)
{
	this->ctrl = _ctrl;
	this->setup_gui();
	this->connect_gui();
	this->update_list();
}

void	GUI::connect_gui()
{
	QObject::connect(this->add_btn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(this->upd_btn, SIGNAL(clicked()), this, SLOT(edit()));
	QObject::connect(this->rm_btn, SIGNAL(clicked()), this, SLOT(rm()));
	QObject::connect(this->lst, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(upd_txt(QListWidgetItem*)));
}

void	GUI::setup_gui()
{
	/*
		Seteaza layout-ul gui
	*/

	QHBoxLayout* main_lay = new QHBoxLayout();
	this->setLayout(main_lay);

	this->lst = new QListWidget();

	QLabel* id_lbl = new QLabel(QObject::tr("id"));
	QLabel* tit_lbl = new QLabel(QObject::tr("title"));
	QLabel* art_lbl = new QLabel(QObject::tr("artist"));
	QLabel* rnk_lbl = new QLabel(QObject::tr("rank"));
	this->id_txt = new QLineEdit();
	this->tit_txt = new QLineEdit();
	this->art_txt = new QLineEdit();
	this->rnk_txt = new QLineEdit();
	QVBoxLayout* inp_lay = new QVBoxLayout();

	QHBoxLayout* id_lay = new QHBoxLayout();
	QHBoxLayout* tit_lay = new QHBoxLayout();
	QHBoxLayout* art_lay = new QHBoxLayout();
	QHBoxLayout* rnk_lay = new QHBoxLayout();

	inp_lay->addLayout(id_lay);
	inp_lay->addLayout(tit_lay);
	inp_lay->addLayout(art_lay);
	inp_lay->addLayout(rnk_lay);

	id_lay->addWidget(id_lbl);
	id_lay->addWidget(id_txt);

	tit_lay->addWidget(tit_lbl);
	tit_lay->addWidget(tit_txt);

	art_lay->addWidget(art_lbl);
	art_lay->addWidget(art_txt);

	rnk_lay->addWidget(rnk_lbl);
	rnk_lay->addWidget(rnk_txt);

	QHBoxLayout* btn_lay = new QHBoxLayout();
	inp_lay->addLayout(btn_lay);

	this->add_btn = new QPushButton(QObject::tr("&Add"));
	this->upd_btn = new QPushButton(QObject::tr("Up&date"));
	this->rm_btn = new QPushButton(QObject::tr("&Remove"));

	btn_lay->addWidget(add_btn);
	btn_lay->addWidget(upd_btn);
	btn_lay->addWidget(rm_btn);

	main_lay->addWidget(this->lst);
	main_lay->addLayout(inp_lay);
}

void	GUI::add()
{
	/*
		Trimite la controller pt a adauga
	*/
	int id;
	string tit;
	string art;
	int rnk;

	id = this->id_txt->text().toInt();
	tit = this->tit_txt->text().toStdString();
	art = this->art_txt->text().toStdString();
	rnk = this->rnk_txt->text().toInt();

	this->ctrl->add(id, tit, art, rnk);
	this->update_list();
}

void	GUI::edit()
{
	/*
		Trimite la controller pt a edita
	*/
	int id;
	string tit;
	string art;
	int rnk;

	id = this->id_txt->text().toInt();
	tit = this->tit_txt->text().toStdString();
	art = this->art_txt->text().toStdString();
	rnk = this->rnk_txt->text().toInt();

	this->ctrl->edit(id, tit, art, rnk);
	this->update_list();
}

void	GUI::rm()
{
	/*
		Trimite la controller pt a sterge
	*/
	int id;

	id = this->id_txt->text().toInt();

	this->ctrl->rm(id);
	this->update_list();
}

void	GUI::upd_txt(QListWidgetItem* song)
{
	this->id_txt->setText(song->text());
	// this->tit_txt->setText(QString::fromStdString(song.get_title()));
	// this->art_txt->setText(QString::fromStdString(song.get_artist()));
	// this->rnk_txt->setText(QString::number(song.get_rank()));
}

void	GUI::update_list()
{
	this->lst->clear();

	vector<Song> list = this->ctrl->get_lst();
	sort(list.begin(), list.end(), [](Song a, Song b){
		return a.get_rank() < b.get_rank();
	});
	for (auto el : list)
	{
		QString qs = QString::fromStdString(el.get_print());
		new QListWidgetItem(qs, this->lst);
	}
}

GUI::~GUI()
{

}
