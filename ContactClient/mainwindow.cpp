#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fenetrecontact.h"
#include "fenetreajoutinter.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initgc
    gc = new GestionContact();
    gc->createContact("Barnier", "Michel", "LR", "0625457852",":/anonyme.jpg","MB@LR.fr");

    //init UI
    QHBoxLayout *HL= new QHBoxLayout();
        QTabWidget *tabWidgetVisu = new QTabWidget();
            QWidget *VisuContact = new QWidget();
            tabWidgetVisu->addTab(VisuContact, "Contact");
            QWidget *VisuInteraction = new QWidget();
            tabWidgetVisu->addTab(VisuInteraction, "Interaction");
    HL->addWidget(tabWidgetVisu);
        QVBoxLayout *VL= new QVBoxLayout();
            BarreRecherche = new QLineEdit;
            BarreRecherche->setPlaceholderText("Recherche");
        VL->addWidget(BarreRecherche);
            QHBoxLayout *HLSelection = new QHBoxLayout();
                QCheckBox *checkRechAdv = new QCheckBox("Recherche avancée");
            HLSelection->addWidget(checkRechAdv);
                QLabel *LTri = new QLabel("Trié par :");
            HLSelection->addWidget(LTri);
                cBSelectionTri = new QComboBox();
                    titreCol = new QStringList();
                    titreCol->append("Nom");
                    titreCol->append("Prenom");
                    titreCol->append("Entreprise");
                    titreCol->append("Date de création");
                    titreCol->append("Date de dernière modification");
                cBSelectionTri->addItems(*titreCol);
            HLSelection->addWidget(cBSelectionTri);
        VL->addLayout(HLSelection);
            QWidget *WRechercheAdv = new QWidget();
                QVBoxLayout *VL1 = new QVBoxLayout();
                    QHBoxLayout *HB1 = new QHBoxLayout();
                        BoutonsSelection = new QButtonGroup();
                            QRadioButton *SelContact = new QRadioButton("Contact");
                            SelContact->setChecked(true);
                        BoutonsSelection->addButton(SelContact,0);
                    HB1->addWidget(SelContact);
                            QRadioButton *SelInteraction = new QRadioButton("Interaction");
                        BoutonsSelection->addButton(SelInteraction,1);
                    HB1->addWidget(SelInteraction);
                            QRadioButton *SelTodo = new QRadioButton("Tâches");
                        BoutonsSelection->addButton(SelTodo,2);
                    HB1->addWidget(SelTodo);
                VL1->addLayout(HB1);
                    checkRechAdvDate = new QCheckBox("Recherche par date");
                VL1->addWidget(checkRechAdvDate);
                    QHBoxLayout *HL2 = new QHBoxLayout();
                        QLabel *Debut = new QLabel("Du :");
                    HL2->addWidget(Debut);
                        dateEditDebutRech = new QDateEdit();
                        dateEditDebutRech->setEnabled(false);
                    HL2->addWidget(dateEditDebutRech);
                        QLabel *Fin = new QLabel("au :");
                    HL2->addWidget(Fin);
                        dateEditFinRech = new QDateEdit();
                        dateEditFinRech->setEnabled(false);
                    HL2->addWidget(dateEditFinRech);
                VL1->addLayout(HL2);
                    checkRechAdvContact = new QCheckBox("Recherche par contact");
                VL1->addWidget(checkRechAdvContact);
                    cBSelectionContact = new QComboBox();
                    cBSelectionContact->setEnabled(false);
                 VL1->addWidget(cBSelectionContact);
            WRechercheAdv->setLayout(VL1);
            WRechercheAdv->setVisible(false);
        VL->addWidget(WRechercheAdv);
            ListeSelection = new QTableView();
            ListeSelection->setSelectionBehavior(QAbstractItemView::SelectRows);
            ListeSelection->setSelectionMode(QAbstractItemView::SingleSelection);
            modifModel(1);
        VL->addWidget(ListeSelection);
    HL->addLayout(VL);

    QWidget *cw = new QWidget();
    cw->setLayout(HL);

    this->setCentralWidget(cw);

    //connections
    connect(checkRechAdv, SIGNAL(clicked(bool)), WRechercheAdv, SLOT(setVisible(bool)));
    connect(checkRechAdvDate, SIGNAL(clicked(bool)), dateEditFinRech, SLOT(setEnabled(bool)));
    connect(checkRechAdvDate, SIGNAL(clicked(bool)), dateEditDebutRech, SLOT(setEnabled(bool)));
    connect(checkRechAdvContact, SIGNAL(clicked(bool)), cBSelectionContact, SLOT(setEnabled(bool)));
    connect(BarreRecherche, SIGNAL(textEdited(QString)), this, SLOT(selection(QString)));
    connect(cBSelectionTri, SIGNAL(currentIndexChanged(int)), this, SLOT(tri(int)));
    connect(SelContact, SIGNAL(clicked()) , this,SLOT(selectionTypeContact()));
    connect(SelInteraction, SIGNAL(clicked()) , this,SLOT(selectionTypeInteraction()));
    connect(SelTodo, SIGNAL(clicked()) , this,SLOT(selectionTypeTodo()));
    connect(ListeSelection, SIGNAL(clicked(QModelIndex)), this, SLOT(affiche(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGc(GestionContact *value)
{
    gc = value;
    for (auto& it : gc->getContactList())
    {
        cBSelectionContact->addItem(QString::fromStdString(it.getPrenom()+" "+it.getNom()+" de "+it.getEntreprise()));
    }
    ajoutDonneesContact();
}

void MainWindow::on_actionNouveau_Contact_triggered()
{
    FenetreContact* fc = new FenetreContact();
    fc->setModal(true);
    int res = fc->exec();
    if(res == QDialog::Accepted)
    {
        gc->createContact(fc->getNom().toStdString(), fc->getPrenom().toStdString(), fc->getEntreprise().toStdString(), fc->getTel().toStdString(), fc->getCheminPhoto().toStdString(),fc->getMail().toStdString());
        std::list<Contact> liste = gc->getContactList();
        for (auto & it : liste)
        {
            std::cout<<it<<std::endl;
        }
    }
}

void MainWindow::on_actionNouvelle_Interaction_triggered()
{
    FenetreAjoutInter *fai = new FenetreAjoutInter(this, gc);
    fai->exec();
}

void MainWindow::ajoutDonneesContact()
{
    int i=0;
    for(auto it : gc->getContactList())
    {
        QStandardItem *item0 = new QStandardItem(QString::number(it.getId()));
        model->setItem(i, 0, item0);
        QStandardItem *item = new QStandardItem(QString::fromStdString(it.getNom()));
        model->setItem(i, 1, item);
        QStandardItem *item1 = new QStandardItem(QString::fromStdString(it.getPrenom()));
        model->setItem(i,2,item1);
        QStandardItem *item2 = new QStandardItem(QString::fromStdString(it.getEntreprise()));
        model->setItem(i,3,item2);
        QStandardItem *item3 = new QStandardItem(QString::fromStdString(it.getDate()));
        model->setItem(i,4,item3);
        QStandardItem *item4 = new QStandardItem(QString::fromStdString(it.getGestionInteraction().getInteractionList().back().getDate()));
        model->setItem(i,5,item4);
        i++;
    }
}

void MainWindow::ajoutDonneesInteraction()
{

}

void MainWindow::ajoutDonneesTodo()
{

}

void MainWindow::selection(QString texte)
{
    for (int i=0; i<model->rowCount(); i++)
    {
        bool flag = false;
        int j = 0;
        while(!flag && j<model->columnCount())
        {
            if (model->item(i,j)->text().contains(texte, Qt::CaseInsensitive))
                flag = true;
            j++;
        }
        if (!flag)
            ListeSelection->hideRow(i);
        else
            ListeSelection->showRow(i);
    }
}

void MainWindow::tri(int index)
{
    model->sort(index);
}
void MainWindow::modifModel(int index)
{
    titreCol->clear();
    cBSelectionTri->clear();
    switch(index)
    {
    case 1: model = new QStandardItemModel((int)gc->getSize(), 6);
            titreCol->append("Id");
            titreCol->append("Nom");
            titreCol->append("Prenom");
            titreCol->append("Entreprise");
            titreCol->append("Date de création");
            titreCol->append("Date de dernière modification");
            cBSelectionTri->addItems(*titreCol);
            model->setHorizontalHeaderLabels(*titreCol);
            ajoutDonneesContact();
            break;
    case 2: model = new QStandardItemModel((int)resultRechInter.size(), 4);
            titreCol->append("Id");
            titreCol->append("N°Contact");
            titreCol->append("Contenu");
            titreCol->append("Date");
            cBSelectionTri->addItems(*titreCol);
            model->setHorizontalHeaderLabels(*titreCol);
            ajoutDonneesInteraction();
            break;
    case 3: model = new QStandardItemModel((int)resultRechTodo.size(), 4);
            titreCol->append("Id");
            titreCol->append("N°Interaction");
            titreCol->append("Contenu");
            titreCol->append("Date");
            cBSelectionTri->addItems(*titreCol);
            model->setHorizontalHeaderLabels(*titreCol);
            ajoutDonneesTodo();
            break;
    }
    ListeSelection->setModel(model);
    ListeSelection->hideColumn(0);
    model->sort(cBSelectionTri->currentIndex());
}

void MainWindow::selectionTypeContact()
{
    modifModel(1);
}

void MainWindow::selectionTypeInteraction()
{
    modifModel(2);
}

void MainWindow::selectionTypeTodo()
{
    modifModel(3);
}

void MainWindow::affiche(QModelIndex MI)
{
    int row = MI.row();
    Contact c = *gc->getContactByID(conversion[row]);
}
