#include "drw.h"
#include "ui_drw.h"

drw::drw(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::drw)
{
	ui->setupUi(this);
}

void	drw::setup_gui()
{
	QVBoxLayout *main_lay = new QVBoxLayout(this);

}

void	drw::update_draw()
{
	
}

drw::~drw()
{
	delete ui;
}
