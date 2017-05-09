#include "Controller.h"

using namespace std;

Controller::Controller(File_Repository* _frepo, Validator* _validator)
{
	this->validator = _validator;
	this->frepo = _frepo;
}

bool						Controller::isvalid_number(const string& s) const
{
	return this->validator->isvalid_number(s);
}

bool						Controller::isvalid_title(const string& s) const
{
	return this->validator->isvalid_title(s);
}

bool						Controller::isvalid_type(const string& s) const
{
	return this->validator->isvalid_type(s);
}

bool						Controller::isvalid_description(const string& s) const
{
	return this->validator->isvalid_description(s);
}

bool						Controller::isvalid_filename(const string& s) const
{
	return this->validator->isvalid_filename(s);
}

void						Controller::add_to_undo(const std::string& add_what)
{
	vector<Activity>*	list;
	Undo_Action*		undo_action = nullptr;

	list = this->frepo->get_list();
	undo_action = new Undo_Action(list);

	this->undo_list.insert(undo_list.begin(), undo_action);
}

void						Controller::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	this->add_to_undo("add");
	this->frepo->add(_title, _description, _type, _duration);
}

void						Controller::remove(const std::string& _title)
{
	this->add_to_undo("remove");
 	this->frepo->remove(_title);
}

bool						Controller::exists(const std::string& _title)
{
	return this->frepo->exists(_title);
}

std::vector<Activity>*		Controller::get_list() const
{
	std::vector<Activity>*	list;

	list = this->frepo->get_list();
	return list;
}

std::vector<Activity>*		Controller::get_list_filtered(const string& filter_what, const string& input)
{
	std::vector<Activity>*	list;
	list = this->frepo->get_list();
	std::vector<Activity>*	new_list = new std::vector<Activity>(list->size());

	if (filter_what == "description")
	{
		auto it = std::copy_if(list->begin(), list->end(), new_list->begin(), [input](auto elem) {
			return elem.get_description() == input;
		});
		new_list->resize(std::distance(new_list->begin(), it));
	}
	else if (filter_what == "type")
	{
		auto it = std::copy_if(list->begin(), list->end(), new_list->begin(), [input](auto elem) {
			return elem.get_type() == input;
		});
		new_list->resize(std::distance(new_list->begin(), it));
	}
	delete list;

	return new_list;
}

std::vector<Activity>*		Controller::get_list_sorted(const string& sort_by)
{
	std::vector<Activity> 	*list;

	list = this->frepo->get_list();
	if (sort_by == "title")
		std::sort(list->begin(), list->end(), [](const auto lelem, const auto relem) {
			return lelem.get_title() < relem.get_title();
		});
	else if (sort_by == "description")
		std::sort(list->begin(), list->end(), [](const auto lelem, const auto relem) {
			return lelem.get_description() < relem.get_description();
		});
	else if (sort_by == "type+duration")
		std::sort(list->begin(), list->end(), [](const auto lelem, const auto relem) {
			if (lelem.get_type() < relem.get_type())
				return true;
			else if (lelem.get_type() == relem.get_type())
				if (lelem.get_duration() < relem.get_duration())
					return true;
			return false;
		});
	return list;
}

std::vector<Activity>*		Controller::get_list_shuffled() const
{
	std::vector<Activity> 	*list;

	list = this->frepo->get_list();
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(list->begin(), list->end(), std::default_random_engine(seed));
	return list;
}

void						Controller::edit(std::string& _title, std::string& _description, std::string& _type, std::string& _duration)
{
	if (!this->validator->isvalid_description(_description))
		_description = "";
	if (!this->validator->isvalid_type(_type))
		_type = "";
	if (!this->validator->isvalid_number(_duration))
		_duration = "";
	this->add_to_undo("edit");
	this->frepo->edit(_title, _description, _type, _duration);
}

void						Controller::delete_list()
{
	this->add_to_undo("delete_list");
	this->frepo->delete_list();
}

void						Controller::undo()
{
	if (!this->undo_list.empty())
	{
		this->frepo->delete_list();
		for (auto elem : *this->undo_list[0]->get_list())
			this->frepo->add(elem.get_title(), elem.get_description(), elem.get_type(), elem.get_duration());

		delete this->undo_list[0];
		this->undo_list.erase(this->undo_list.begin());
	}
}

void						Controller::save_another(const std::string& s)
{
	this->frepo->push_to_specific_file(s);
}

Activity&					Controller::get_elem(const std::string& _title)
{
	return this->frepo->get_elem(_title);
}

Controller::~Controller()
{
	delete this->validator;
	delete this->frepo;
	for (Undo_Action* mini_list : this->undo_list)
		delete mini_list;
}