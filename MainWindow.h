#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>

#include <QMainWindow>
#include <QToolBar>

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
	public:
		MainWindow();
		void addDocument(const QString &filename);
		
	private slots:
		void newAction();
		void openAction();
		void saveAction();
		
	private:
		QTabWidget* tabs;
		QToolBar* toolbar;
		void createToolbar();
};

#endif
