#pragma once

#include <QWidget>
#include "ui_DefaultVipWidget.h"

class DefaultVipWidget : public QWidget
{
	Q_OBJECT

public:
	DefaultVipWidget(QWidget *parent = Q_NULLPTR);
	~DefaultVipWidget();

private:
	Ui::DefaultVipWidget ui;
};
