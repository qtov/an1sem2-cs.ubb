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
}

void	drw::update_drw()
{
	this->repaint();
}

drw::~drw()
{
	delete ui;
}
