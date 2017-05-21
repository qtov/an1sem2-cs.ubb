#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Repository.h"
#include "Undo_Action.h"
#include "Undo_Add.h"
#include "Undo_Edit.h"
#include "Undo_Delete.h"
#include "File_Repository.h"
#include "Validator.h"
#include <random>
#include <chrono>

class Controller : public Observable
{
public:
	Controller(File_Repository*, Validator*);
	~Controller();
	bool						isvalid_number(const std::string&) const;
	bool						isvalid_title(const std::string&) const;
	bool						isvalid_type(const std::string&) const;
	bool						isvalid_filename(const std::string&) const;
	bool						isvalid_description(const string&) const;
	std::vector<Activity>*		get_list() const;
	std::vector<Activity>*		get_list_shuffled() const;
	std::vector<Activity>*		get_list_filtered(const string&, const string&);
	std::vector<Activity>*		get_list_sorted(const string&);
	void						add(const std::string&, const std::string&, const std::string&, const int&);
	void						remove(const std::string&);
	bool						exists(const std::string&);
	void						edit(std::string&, std::string&, std::string&, std::string&);
	Activity&					get_elem(const std::string&);
	void						delete_list();
	void						undo();
	void						save_another(const std::string&);
	void						add_to_undo(const std::string&);

private:
	Validator*					validator;
	File_Repository*			frepo;
	vector<Undo_Action*>		undo_list;
};

#endif
