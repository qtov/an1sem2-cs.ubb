#ifndef DRW_H
#define DRW_H

#include <QVBoxLayout>
#include <QWidget>
#include "observer.h"
#include <QPainter>
#include <QImage>
#include "controller.h"

namespace Ui {
class drw;
}

class drw : public QWidget, public Observer
{
	Q_OBJECT

public:
	explicit drw(controller *ctrl, QWidget *parent = 0);

	void paintEvent(QPaintEvent* ev) override
	{
		QPainter p {this};
		auto lst = this->ctrl->get_list();

		for (auto elem : lst)
		{
			if (elem[2] == 0)
				p.drawImage(elem[0], elem[1], QImage("potato2.png"));
			else if (elem[2] == 1)
				p.drawEllipse(elem[0], elem[1], 20, 20);
			else if (elem[2] == 2)
				p.drawImage(elem[0], elem[1], QImage("cabbage2.png"));
		}
	}

	void update() override {
		update_drw();
	}

	~drw();

private:
	controller *ctrl;
	Ui::drw *ui;
	void	setup_gui();
	void	update_drw();
};

#endif // DRW_H
