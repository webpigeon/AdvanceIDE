#include <QFile>
#include <QMenu>
#include <QFileDialog>
#include <QToolButton>
#include <QAction>
#include <QIcon>
#include <QTextStream>

#include <iostream>

#include "CodeEditor.h"
#include "MainWindow.h"
#include "highlighter.h"

using namespace std;

MainWindow::MainWindow() : QMainWindow(){
	tabs = new QTabWidget();
	tabs->setDocumentMode(true);
	this->setCentralWidget(tabs);
	this->createToolbar();
}

void MainWindow::createToolbar(){
	this->toolbar = addToolBar(tr("File"));
	this->toolbar->setFloatable(false);
	this->toolbar->setMovable(false);
	
	QAction *newAct = new QAction(QIcon("./images/document-new.png"), tr("&New..."), this);
	newAct->setStatusTip(tr("Create a new file"));
	connect(newAct, SIGNAL(triggered()), this, SLOT(newAction()));
	this->toolbar->addAction(newAct);
	
	QAction *openAct = new QAction(QIcon("./images/document-open.png"), tr("&Open..."), this);
	openAct->setStatusTip(tr("Open an existing file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(openAction()));
	this->toolbar->addAction(openAct);
	
	QAction *saveAct = new QAction(QIcon("./images/document-save.png"), tr("&Save..."), this);
	saveAct->setStatusTip(tr("Create a new file"));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveAction()));
	this->toolbar->addAction(saveAct);
	
	QAction *saveAllAct = new QAction(QIcon("./images/document-save-all.png"), tr("&Save all..."), this);
	saveAct->setStatusTip(tr("Create a new file"));
	this->toolbar->addAction(saveAllAct);
	
	this->toolbar->addSeparator();
	
	QMenu *menu = new QMenu();
	
	QAction *buildAct = new QAction(QIcon("./images/document-build.png"), tr("&Build"), this);
	buildAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildAct);
	menu->addSeparator();
	
	QAction *buildAllAct = new QAction(QIcon("./images/document-build.png"), tr("&Build All"), this);
	buildAllAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildAllAct);
	
	QAction *buildCleanAct = new QAction(QIcon("./images/document-build.png"), tr("&Build Clean"), this);
	buildCleanAct->setStatusTip(tr("Create a new file"));
	menu->addAction(buildCleanAct);

	QToolButton* toolButton = new QToolButton();
	toolButton->setMenu(menu);
	toolButton->setDefaultAction(buildAct);
	this->toolbar->addWidget(toolButton);
}

void MainWindow::newAction(){
	addDocument("new document");
}

void MainWindow::openAction(){	
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open File"), "/home/webpigeon", tr("C++ Files (*.cpp *.c *.h)"));
	if(!fileName.isEmpty()){
		addDocument(fileName);
	}
}

void MainWindow::saveAction(){
	int index = tabs->currentIndex();
	QString filename = tabs->tabText(index);
	CodeEditor* ce = (CodeEditor*)tabs->widget(index);
	
	QFile file(filename);
	if (file.open(QFile::WriteOnly | QFile::Text)){
		QTextStream out(&file);
		out << ce->toPlainText();
		out.flush();
	}
	file.close();
}

void MainWindow::addDocument(const QString &filename){
	CodeEditor* doc = new CodeEditor();
	
	QFile file(filename);
    if (file.open(QFile::ReadOnly | QFile::Text))
        doc->setPlainText(file.readAll());
    file.close();

	Highlighter *highlighter = new Highlighter(doc->document());
	tabs->addTab(doc, filename);
}
