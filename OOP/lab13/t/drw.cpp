#include "drw.h"
#include "ui_drw.h"
#include "tbl.h"

drw::drw(controller *_ctrl, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::drw)
{
	ui->setupUi(this);
	this->ctrl = _ctrl;
	this->ctrl->reg(this);
	setAttribute(Qt::WA_DeleteOnClose);
}

void	drw::update_drw()
{
	this->repaint();
}

drw::~drw()
{
	this->ctrl->rm_lst(this);
	delete ui;
}
