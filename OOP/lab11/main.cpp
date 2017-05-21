#include "Builder.h"
#include <QApplication>
#include <mcheck.h>
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>

using namespace std;

int	main(int argc, char** argv)
{
	(void)argc; (void)argv;
	QApplication a(argc, argv);
	QWidget widget;


	// Builder	builder;
	// UI*		ui = builder.getUI();

	// // ui->start();
	// delete ui;
	widget.setContentsMargins(10, 10, 10, 10);
	QHBoxLayout* main_lay = new QHBoxLayout(&widget);
	QVBoxLayout* left_lay = new QVBoxLayout();
	QVBoxLayout* right_lay = new QVBoxLayout();
	

	QHBoxLayout* title_lay = new QHBoxLayout();
		QLabel* lbl_title = new QLabel(QObject::tr("title"));
		lbl_title->setAlignment(Qt::AlignCenter);
		QLineEdit* txt_title = new QLineEdit();

	QHBoxLayout* desc_lay = new QHBoxLayout();
		QLabel* lbl_desc = new QLabel(QObject::tr("description"));
		lbl_desc->setAlignment(Qt::AlignCenter);
		QLineEdit* txt_desc = new QLineEdit();

	QHBoxLayout* type_lay = new QHBoxLayout();
		QLabel* lbl_type = new QLabel(QObject::tr("type"));
		lbl_type->setAlignment(Qt::AlignCenter);
		QLineEdit* txt_type = new QLineEdit();

	QHBoxLayout* dur_lay = new QHBoxLayout();
		QLabel* lbl_dur = new QLabel(QObject::tr("duration"));
		lbl_dur->setAlignment(Qt::AlignCenter);
		QLineEdit* txt_dur = new QLineEdit();

	QHBoxLayout* op_lay = new QHBoxLayout();
		QPushButton* add_btn = new QPushButton(QObject::tr("&Add"));
		QPushButton* upd_btn = new QPushButton(QObject::tr("Updat&e"));
		QPushButton* rm_btn = new QPushButton(QObject::tr("&Remove"));
	QHBoxLayout* fil_lay = new QHBoxLayout();
		QPushButton* fil_desc = new QPushButton(QObject::tr("FilterBy&Desc"));
		QPushButton* fil_type = new QPushButton(QObject::tr("FilterBy&Type"));
		QPushButton* fil_search = new QPushButton(QObject::tr("&Search"));

	//left

	QListWidget* activities = new QListWidget();
	new QListWidgetItem("Item1", activities);
	new QListWidgetItem("Item2", activities);

	main_lay->addLayout(left_lay);
	main_lay->addLayout(right_lay);

	title_lay->addWidget(lbl_title);
	title_lay->addStretch();
	title_lay->addWidget(txt_title);
	desc_lay->addWidget(lbl_desc);
	desc_lay->addStretch();
	desc_lay->addWidget(txt_desc);
	type_lay->addWidget(lbl_type);
	type_lay->addStretch();
	type_lay->addWidget(txt_type);
	dur_lay->addWidget(lbl_dur);
	dur_lay->addStretch();
	dur_lay->addWidget(txt_dur);
	op_lay->addWidget(add_btn);
	op_lay->addWidget(upd_btn);
	op_lay->addWidget(rm_btn);
	fil_lay->addWidget(fil_desc);
	fil_lay->addWidget(fil_type);
	fil_lay->addWidget(fil_search);

	right_lay->addLayout(title_lay);
	right_lay->addLayout(desc_lay);
	right_lay->addLayout(type_lay);
	right_lay->addLayout(dur_lay);
	right_lay->addLayout(op_lay);
	right_lay->addLayout(fil_lay);

	QHBoxLayout* sort_lay = new QHBoxLayout();
		
		QPushButton* sort_title_btn = new QPushButton(QObject::tr("SortByTit&le"));
		QPushButton* sort_desc_btn = new QPushButton(QObject::tr("SortByDes&c"));
		QPushButton* sort_type_btn = new QPushButton(QObject::tr("SortByT&ype"));

	left_lay->addWidget(activities);
	left_lay->addLayout(sort_lay);

	sort_lay->addWidget(sort_title_btn);
	sort_lay->addWidget(sort_desc_btn);
	sort_lay->addWidget(sort_type_btn);


	widget.show();

	return a.exec();
}
