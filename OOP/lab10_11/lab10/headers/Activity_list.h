#ifndef ACTIVITY_LIST_H
#define ACTIVITY_LIST_H

class Activity_list : public QWidget, public Observer {
private:
	Controller &controller;
	QListWidget *activity_list;
public:
	Activity_list(Controller &controller) : controller{ controller } {
		activity_list = new QListWidget;
		QHBoxLayout *lay = new QHBoxLayout(this);
		lay->addWidget(activity_list);
		updateStud();
		controller.reg(this);
	};
	void updateStud() {
		activity_list->clear();

		for (auto el : controller.allSt()) {
			activity_list->addItem(QString::number( el.id) +" " + QString{ el.nume.c_str() } +" " + QString::number(el.nota));
		}
	}
	void update() override {
		updateStud();
	}
};

#endif