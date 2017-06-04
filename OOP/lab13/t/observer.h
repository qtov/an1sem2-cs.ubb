#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
};

class Observable
{
protected:
	vector<Observer*> obs;

public:
	void reg(Observer *s)
	{
		obs.push_back(s);
	}

	void notify_all()
	{
		for (auto ob : obs) {
			ob->update();
		}
	}
};

#endif // OBSERVER_H
