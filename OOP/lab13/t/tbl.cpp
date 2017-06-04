#include "tbl.h"
#include "ui_tbl.h"

tbl::tbl(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::tbl)
{
	ui->setupUi(this);
	this->setup_gui();
}

void	tbl::setup_gui()
{
	QVBoxLayout *main_lay = new QVBoxLayout(this);
	QHBoxLayout *btn_lay = new QHBoxLayout();
	QHBoxLayout *btn2_lay = new QHBoxLayout();

	this->lst = new QListWidget();
	main_lay->addWidget(this->lst);

	this->gen_btn = new QPushButton(QObject::tr("&Generate"));
	this->em_btn = new QPushButton(QObject::tr("&Empty"));
	this->add_btn = new QPushButton(QObject::tr("&Add"));

	btn_lay->addWidget(this->add_btn);
	btn_lay->addWidget(this->em_btn);
	btn_lay->addWidget(this->gen_btn);

	this->paint_btn = new QPushButton(QObject::tr("Open Pain&t"));
	this->list_btn = new QPushButton(QObject::tr("Open Li&st"));

	btn2_lay->addWidget(this->list_btn);
	btn2_lay->addWidget(this->paint_btn);

	main_lay->addLayout(btn_lay);
	main_lay->addLayout(btn2_lay);
}

void	tbl::update_list()
{
	
}

tbl::~tbl()
{
	delete ui;
}
