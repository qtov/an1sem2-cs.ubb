#include "UI.h"

using namespace std;

UI::UI(Controller* _controller)
{
	this->controller = _controller;
}

void	UI::show_menu()
{
	cout << "1. Add activity.\n";
	cout << "2. Delete activity.\n";
	cout << "3. Edit activity.\n";
	cout << "4. Display activities.\n";
	cout << "5. Search activity.\n";
	cout << "6. Filter activities.\n";
	cout << "7. Sort activities.\n";
	cout << "8. Exit.\n";
}

void	UI::add()
{
	adsed
}

void	UI::start()
{
	//cout<<"UI\n";
	int		input = 0;
	string	inputline;

	while (input != 8)
	{
		this->show_menu();
		cout << "Input: ";
		getline(cin, inputline);
		if (this->controller->isvalid_input(inputline) && !inputline.empty())
		{
			input = stoi(inputline);
			switch (input)
			{
				case 1 : 
					this->add();
					break;
				case 2 : 
					//
					break;
				case 3 : 
					
					break;
				case 4 : 
					
					break;
				case 5 : 
					
					break;
				case 6 : 
					
					break;
				case 7 : 
					
					break;
				case 8 : 
					
					break;
				default : 
					cout << "\n" << "Invalid input, retry.\n" << "\n";
					break;
			}
		}
		else
		{
			cout << "\n" << "Invalid input, retry.\n" << "\n";
		}
	}
}

UI::~UI()
{
	delete this->controller;
}
