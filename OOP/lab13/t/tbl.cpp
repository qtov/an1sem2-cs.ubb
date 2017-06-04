#include "tbl.h"
#include "drw.h"
#include "ui_tbl.h"

tbl::tbl(controller *_ctrl, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::tbl)
{
	ui->setupUi(this);
	this->ctrl = _ctrl;
	this->ctrl->reg(this);
	this->setup_gui();
	this->connect_gui();
	this->update_tbl();
	setAttribute(Qt::WA_DeleteOnClose);
}

void	tbl::setup_gui()
{
	QVBoxLayout *main_lay = new QVBoxLayout(this);
	QHBoxLayout *btn_lay = new QHBoxLayout();
	QHBoxLayout *btn2_lay = new QHBoxLayout();

	this->setLayout(main_lay);

	this->lst = new QListWidget();
	main_lay->addWidget(this->lst);

	this->gen_btn = new QPushButton(QObject::tr("&Generate"));
	this->em_btn = new QPushButton(QObject::tr("&Empty"));
	this->add_btn = new QPushButton(QObject::tr("&Add"));
	this->rm_btn = new QPushButton(QObject::tr("&Remove"));

	btn_lay->addWidget(this->add_btn);
	btn_lay->addWidget(this->rm_btn);
	btn_lay->addWidget(this->em_btn);
	btn_lay->addWidget(this->gen_btn);

	this->paint_btn = new QPushButton(QObject::tr("Open Pain&t"));
	this->list_btn = new QPushButton(QObject::tr("Open Li&st"));

	btn2_lay->addWidget(this->list_btn);
	btn2_lay->addWidget(this->paint_btn);

	main_lay->addLayout(btn_lay);
	main_lay->addLayout(btn2_lay);
}

void	tbl::connect_gui()
{
	QObject::connect(this->add_btn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(this->list_btn, SIGNAL(clicked()), this, SLOT(copy()));
	QObject::connect(this->rm_btn, SIGNAL(clicked()), this, SLOT(remove_last()));
	QObject::connect(this->em_btn, SIGNAL(clicked()), this, SLOT(empty_list()));
	QObject::connect(this->gen_btn, SIGNAL(clicked()), this, SLOT(gen_list()));
	QObject::connect(this->paint_btn, SIGNAL(clicked()), this, SLOT(copy_paint()));
}

void	tbl::update_tbl()
{
	int size = this->ctrl->get_size();
	int i = 0;

	this->lst->clear();
	for (i = 0; i < size; i++)
	{
		QString str;
		str = "item " + QString::number(i);
		new QListWidgetItem(str, this->lst);
	}
}

void	tbl::add()
{
	this->ctrl->add(rand() % (this->width() - 20), rand() % (this->height() - 20), rand() % 3);
}

void	tbl::copy()
{
	tbl* o = new tbl(this->ctrl);

	o->show();
}

void	tbl::empty_list()
{
	this->lst->clear();
	this->ctrl->empty_list();
}

void	tbl::gen_list()
{
	// this->empty_list();
	int r = std::rand();

	int i = 0;
	for (i = 0; i < r % 50; i++)
		this->add();
}

void	tbl::copy_paint()
{
	drw* o = new drw(this->ctrl);

	o->show();
}


void	tbl::remove_last()
{
	this->ctrl->remove_last();
}

tbl::~tbl()
{
	this->lst->clear();
	delete ui;
	this->ctrl->rm_lst(this);
}
