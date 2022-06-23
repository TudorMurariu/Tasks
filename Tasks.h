#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tasks.h"

class Tasks : public QMainWindow
{
    Q_OBJECT

public:
    Tasks(QWidget *parent = Q_NULLPTR);

private:
    Ui::TasksClass ui;
};
