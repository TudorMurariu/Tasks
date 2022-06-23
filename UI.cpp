#include "UI.h"
#include <qlayout.h>
#include <qmessagebox.h>

void GUI::buid_UI()
{
	QHBoxLayout* mainly = new QHBoxLayout;
	mainly->addWidget(tblV);

	QWidget* w = new QWidget;
	QVBoxLayout* vl = new QVBoxLayout;
	w->setLayout(vl);

	vl->addWidget(id_label);
	vl->addWidget(id);

	vl->addWidget(descriere_label);
	vl->addWidget(descriere);

	vl->addWidget(programatori_label);
	vl->addWidget(programatori);

	vl->addWidget(stare_label);
	vl->addWidget(stare);

	vl->addWidget(add);

	mainly->addWidget(w);

	this->setLayout(mainly);
}

void GUI::connect_signals()
{
	QObject::connect(add, &QPushButton::clicked, [&]() {

		string id_txt = id->text().toStdString();
		int id_;
		try {
			id_ = stoi(id_txt);
		}
		catch (exception e) {
			QMessageBox::warning(this, "id-ul trebuie sa fie un numar", "id-ul trebuie sa fie un numar");
			return;
		}

		string descriere_ = descriere->text().toStdString();
		string programatori_ = programatori->text().toStdString();
		string stare_ = stare->text().toStdString();

		string err = srv.add(id_, descriere_, programatori_, stare_);
		if (err != "")
		{
			QMessageBox::warning(this, QString::fromStdString(err), QString::fromStdString(err));
			return;
		}

		this->update();

		});
}