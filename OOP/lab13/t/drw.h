#ifndef DRW_H
#define DRW_H

#include <QVBoxLayout>
#include <QWidget>
#include "observer.h"
#include <QPainter>
#include <QImage>

namespace Ui {
class drw;
}

class drw : public QWidget, public Observer, public Observable
{
	Q_OBJECT

public:
	explicit drw(QWidget *parent = 0);
	void paintEvent(QPaintEvent* ev) override
	{
		QPainter p(this);
		// p.drawLine(0, 0, width(), height());
		// p.drawImage(x, 0, QImage("sky.jpg"));
	} 
	void update_draw();
	void update() override {
		update_draw();
	}
	~drw();

private:
	Ui::drw *ui;
	void	setup_gui();
};

#endif // DRW_H
