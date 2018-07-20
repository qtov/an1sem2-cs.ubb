#include "GUI.h"

GUI::GUI(Controller* _ctrl)
{
	this->ctrl = _ctrl;
	this->setup_gui();
	this->connect_gui();
	setAttribute(Qt::WA_DeleteOnClose);
}

void	GUI::add_to_list(Activity& activity)
{
	string	str = "";

	str += activity.get_title() + "; " + activity.get_description() + "; " + activity.get_type() + "; " + std::to_string(activity.get_duration());

	new QListWidgetItem(QString::fromStdString(str), this->activities);
}

void	GUI::setup_gui()
{
	this->setContentsMargins(10, 10, 10, 10);
	QHBoxLayout* main_lay = new QHBoxLayout(this);
	QVBoxLayout* left_lay = new QVBoxLayout();
	QVBoxLayout* right_lay = new QVBoxLayout();


	QHBoxLayout* title_lay = new QHBoxLayout();
	QLabel* lbl_title = new QLabel(QObject::tr("title"));
	lbl_title->setAlignment(Qt::AlignCenter);
	this->txt_title = new QLineEdit();

	QHBoxLayout* desc_lay = new QHBoxLayout();
	QLabel* lbl_desc = new QLabel(QObject::tr("description"));
	lbl_desc->setAlignment(Qt::AlignCenter);
	this->txt_desc = new QLineEdit();

	QHBoxLayout* type_lay = new QHBoxLayout();
	QLabel* lbl_type = new QLabel(QObject::tr("type"));
	lbl_type->setAlignment(Qt::AlignCenter);
	this->txt_type = new QLineEdit();

	QHBoxLayout* dur_lay = new QHBoxLayout();
	QLabel* lbl_dur = new QLabel(QObject::tr("duration"));
	lbl_dur->setAlignment(Qt::AlignCenter);
	this->txt_dur = new QLineEdit();

	QHBoxLayout* op_lay = new QHBoxLayout();
	this->add_btn = new QPushButton(QObject::tr("&Add"));
	this->upd_btn = new QPushButton(QObject::tr("Updat&e"));
	this->rm_btn = new QPushButton(QObject::tr("&Remove"));

	QHBoxLayout* fil_lay = new QHBoxLayout();
	this->fil_desc_btn = new QPushButton(QObject::tr("FilterBy&Desc"));
	this->fil_type_btn = new QPushButton(QObject::tr("FilterBy&Type"));
	this->fil_search_btn = new QPushButton(QObject::tr("&Search"));

	QHBoxLayout* undo_lay = new QHBoxLayout();
	this->undo_btn = new QPushButton(QObject::tr("U&ndo"));
	this->shuffle_btn = new QPushButton(QObject::tr("S&huffle"));
	this->refresh_btn = new QPushButton(QObject::tr("Re&fresh"));

	this->activities = new QListWidget();

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
	fil_lay->addWidget(fil_desc_btn);
	fil_lay->addWidget(fil_type_btn);
	fil_lay->addWidget(fil_search_btn);
	undo_lay->addWidget(refresh_btn);
	undo_lay->addWidget(shuffle_btn);
	undo_lay->addWidget(undo_btn);

	right_lay->addLayout(title_lay);
	right_lay->addLayout(desc_lay);
	right_lay->addLayout(type_lay);
	right_lay->addLayout(dur_lay);
	right_lay->addLayout(op_lay);
	right_lay->addLayout(fil_lay);
	right_lay->addLayout(undo_lay);

	QHBoxLayout* sort_lay = new QHBoxLayout();
	this->sort_title_btn = new QPushButton(QObject::tr("SortByTit&le"));
	this->sort_desc_btn = new QPushButton(QObject::tr("SortByDes&c"));
	this->sort_type_btn = new QPushButton(QObject::tr("SortByT&ype"));

	left_lay->addWidget(activities);
	left_lay->addLayout(sort_lay);

	sort_lay->addWidget(sort_title_btn);
	sort_lay->addWidget(sort_desc_btn);
	sort_lay->addWidget(sort_type_btn);

	this->refresh_list();
}

void	GUI::connect_gui()
{
	QObject::connect(add_btn, SIGNAL(clicked()), this, SLOT(add()));
	QObject::connect(upd_btn, SIGNAL(clicked()), this, SLOT(edit()));
	QObject::connect(rm_btn, SIGNAL(clicked()), this, SLOT(remove()));
	QObject::connect(undo_btn, SIGNAL(clicked()), this, SLOT(undo()));
	QObject::connect(refresh_btn, SIGNAL(clicked()), this, SLOT(refresh_list()));
	QObject::connect(fil_search_btn, SIGNAL(clicked()), this, SLOT(search()));
	QObject::connect(sort_title_btn, SIGNAL(clicked()), this, SLOT(sorting_something()));
	QObject::connect(sort_type_btn, SIGNAL(clicked()), this, SLOT(sort_type()));
	QObject::connect(sort_desc_btn, SIGNAL(clicked()), this, SLOT(sort_desc()));
	QObject::connect(shuffle_btn, SIGNAL(clicked()), this, SLOT(shuffle()));
	QObject::connect(fil_desc_btn, SIGNAL(clicked()), this, SLOT(filter_desc()));
	QObject::connect(fil_type_btn, SIGNAL(clicked()), this, SLOT(filter_type()));
}

void	GUI::add()
{
	string	title;
	string	desc;
	string	type;
	int		dur;
	string	input;

	title = this->txt_title->displayText().toStdString();
	desc = this->txt_desc->displayText().toStdString();
	type = this->txt_type->displayText().toStdString();
	input = this->txt_dur->displayText().toStdString();

	if (!(this->ctrl->isvalid_title(title) && this->ctrl->isvalid_number(input) && this->ctrl->isvalid_type(type) && this->ctrl->isvalid_description(desc) && !input.empty()))
		return;

	dur = stoi(input);
	try
	{
		this->ctrl->add(title, desc, type, dur);
	}
	catch (const not_unique& e)
	{
		return;
	}

	this->txt_title->clear();
	this->txt_dur->clear();
	this->txt_type->clear();
	this->txt_desc->clear();

	string	str = "";

	str += title + "; " + desc + "; " + type + "; " + input;

	this->refresh_list();
}

void	GUI::edit()
{
	string	title;
	string	type;
	string	dur;
	string	desc;

	title = this->txt_title->displayText().toStdString();
	desc = this->txt_desc->displayText().toStdString();
	type = this->txt_type->displayText().toStdString();
	dur = this->txt_dur->displayText().toStdString();

	if (!this->ctrl->exists(title) || !this->ctrl->isvalid_title(title))
	{
		return;
	}

	this->ctrl->edit(title, desc, type, dur);

	this->txt_title->clear();
	this->txt_dur->clear();
	this->txt_type->clear();
	this->txt_desc->clear();

	this->refresh_list();
}

void	GUI::remove()
{
	string	title;

	title = this->txt_title->displayText().toStdString();
	if (!this->ctrl->isvalid_title(title))
		return;
	try
	{
 		this->ctrl->remove(title);
		this->txt_title->clear();
	}
	catch (const invalid_argument& e)
	{}

	this->refresh_list();
}

void	GUI::refresh_list()
{
	vector<Activity>* lst;

	this->activities->clear();

	lst = ctrl->get_list();

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;
}

void	GUI::search()
{
	string	title;

	title = this->txt_title->displayText().toStdString();
	this->activities->clear();
	Activity act = this->ctrl->get_elem(title);
	this->txt_title->clear();

	this->add_to_list(act);
}

void	GUI::undo()
{
	this->ctrl->undo();
	this->refresh_list();
}

void	GUI::sorting_something()
{
	vector<Activity>* lst;

	this->activities->clear();

	lst = ctrl->get_list_sorted("title");

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;
}

void	GUI::sort_desc()
{
	vector<Activity>* lst;

	this->activities->clear();

	lst = ctrl->get_list_sorted("description");

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;
}

void	GUI::sort_type()
{
	vector<Activity>* lst;

	this->activities->clear();

	lst = ctrl->get_list_sorted("type+duration");

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;
}

void	GUI::filter_desc()
{
	vector<Activity>* lst;
	string	input;

	input = this->txt_desc->displayText().toStdString();
	this->activities->clear();

	lst = ctrl->get_list_filtered("description", input);

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;

	this->txt_desc->clear();
}

void	GUI::filter_type()
{
	vector<Activity>* lst;
	string	input;

	input = this->txt_type->displayText().toStdString();
	this->activities->clear();

	lst = ctrl->get_list_filtered("type", input);

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;

	this->txt_type->clear();
}

void	GUI::shuffle()
{
	vector<Activity>* lst;

	this->activities->clear();

	lst = ctrl->get_list_shuffled();

	for (auto& elem:*lst)
	{
		this->add_to_list(elem);
	}

	delete lst;
}


GUI::~GUI()
{
	this->activities->clear();
	delete this->ctrl;
}
