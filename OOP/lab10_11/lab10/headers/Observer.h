#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
	virtual void update() = 0;
};

class Observable {
protected:
	vector<Observer*> obs;
public:
	void reg(Observer *s) {
		obs.push_back(s);
	}
	void notifyAll() {
		for (auto ob : obs) {
			ob->update();
		}
	}
};

#endif