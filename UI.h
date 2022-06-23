#pragma once
#include "Service.h"
#include "Service.h"
#include <qwidget.h>
#include <qtablewidget.h>
#include <QAbstractTableModel>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <QModelIndex>

class MyTableModel : public QAbstractTableModel {
	vector<task>& tasks;
public:

	MyTableModel(vector<task>& tasks1) : tasks(tasks1) {

	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return tasks.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 4;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		if (role == Qt::DisplayRole)
		{
			task t = tasks[index.row()];
			if (index.column() == 0)
			{
				return QString::number(t.id);
			}
			else if (index.column() == 1)
			{
				return QString::fromStdString(t.descriere);
			}
			else if (index.column() == 2)
			{
				return QString::number(t.programatori.size());
			}
			else if (index.column() == 3)
			{
				return QString::fromStdString(t.stare);
			}
		}

		return QVariant{};
	}

	void setTasks(vector<task>& tasks1)
	{
		tasks = tasks1;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(tasks.size(), 3);
		emit dataChanged(topLeft, bottomRight);
		emit layoutChanged();
	}
};

class GUI : public QWidget{
	service& srv;

	QTableView* tblV = new QTableView;
	MyTableModel* model;

	QLabel* id_label = new QLabel("ID :");
	QLineEdit* id = new QLineEdit;

	QLabel* descriere_label = new QLabel("descriere :");
	QLineEdit* descriere = new QLineEdit;

	QLabel* programatori_label = new QLabel("progrmatori(fiecare cu virgula intre ei):");
	QLineEdit* programatori = new QLineEdit;

	QLabel* stare_label = new QLabel("stare :");
	QLineEdit* stare = new QLineEdit;

	QPushButton* add = new QPushButton("ADD");

public:
	GUI(service& srv1) : srv(srv1)
	{
		model = new MyTableModel(srv.get_list());
		tblV->setModel(model);
		buid_UI();
		connect_signals();
	}

	void update()
	{
		srv.update();
		model->setTasks(srv.get_list());
	}

	void buid_UI();
	void connect_signals();
};