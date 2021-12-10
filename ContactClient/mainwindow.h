#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QTableView>
#include <QDateEdit>
#include <QComboBox>
#include <QTabWidget>
#include <QButtonGroup>
#include <QStandardItemModel>
#include <QStringList>
#include <QModelIndex>
#include "gestioncontact.h"
#include "basededonnee.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setGc(GestionContact *value);

private:
    Ui::MainWindow *ui;
    GestionContact *gc;
    Basededonnee bd;

    QLineEdit *BarreRecherche;
    QComboBox *cBSelectionTri;
    QComboBox *cBSelectionContact;
    QButtonGroup *BoutonsSelection;
    QCheckBox *checkRechAdvDate;
    QCheckBox *checkRechAdvContact;
    QDateEdit *dateEditDebutRech;
    QDateEdit *dateEditFinRech;
    QTableView *ListeSelection;
    QStandardItemModel *model;
    QStringList *titreCol;
    std::list<Interaction*> resultRechInter;
   std:: list<toDo*> resultRechTodo;

    void ajoutDonneesContact();
    void ajoutDonneesInteraction();
    void ajoutDonneesTodo();
    void modifModel(int);
    int conversion[];
private slots:

    void on_actionNouveau_Contact_triggered();
    void on_actionNouvelle_Interaction_triggered();
    void selection(QString);
    void tri(int);
    void selectionTypeContact();
    void selectionTypeInteraction();
    void selectionTypeTodo();
    void affiche(QModelIndex);

};
#endif // MAINWINDOW_H
