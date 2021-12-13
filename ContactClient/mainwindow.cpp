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
    gc = &bd.gc;
    //init UI
    QHBoxLayout *HL= new QHBoxLayout();
        tabWidgetVisu = new QTabWidget();
    HL->addWidget(tabWidgetVisu);
        QVBoxLayout *VL= new QVBoxLayout();
            LNbContact = new QLabel(QString::fromStdString("Il y a "+to_string(bd.Nombredecontact())+" contacts dans la base de données"));
       VL->addWidget(LNbContact);
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
                        BoutonsSelection->addButton(SelContact,1);
                    HB1->addWidget(SelContact);
                            QRadioButton *SelInteraction = new QRadioButton("Interaction");
                        BoutonsSelection->addButton(SelInteraction,2);
                    HB1->addWidget(SelInteraction);
                            QRadioButton *SelTodo = new QRadioButton("Tâches");
                        BoutonsSelection->addButton(SelTodo,3);
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
                    for (auto& it : gc->getContactList())
                    {
                        cBSelectionContact->addItem(QString::fromStdString(it->getPrenom()+" "+it->getNom()+" de "+it->getEntreprise()));
                        listeContact.append(it);
                    }
                 VL1->addWidget(cBSelectionContact);
            WRechercheAdv->setLayout(VL1);
            WRechercheAdv->setVisible(false);
        VL->addWidget(WRechercheAdv);
            ListeSelection = new QTableView();
            ListeSelection->setSelectionBehavior(QAbstractItemView::SelectRows);
            ListeSelection->setSelectionMode(QAbstractItemView::SingleSelection);
            modifModel(1);
        VL->addWidget(ListeSelection);
            QPushButton *BJSON = new QPushButton("Export en json");
        //VL->addWidget(BJSON);
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
/**
 * @brief accesseur en écriture de gc
 * @param value
 */
void MainWindow::setGc(GestionContact *value)
{
    gc = value;
    for (auto& it : gc->getContactList())
    {
        cBSelectionContact->addItem(QString::fromStdString(it->getPrenom()+" "+it->getNom()+" de "+it->getEntreprise()));
    }
    ajoutDonneesContact();
}

/**
 * @brief Affiche une boîte de dialogue pour ajouter un contact
 */
void MainWindow::on_actionNouveau_Contact_triggered()
{
    FenetreContact* fc = new FenetreContact();
    fc->setModal(true);
    int res = fc->exec();
    if(res == QDialog::Accepted)
    {
        gc->createContact(fc->getNom().toStdString(), fc->getPrenom().toStdString(), fc->getEntreprise().toStdString(), fc->getTel().toStdString(), fc->getCheminPhoto().toStdString(),fc->getMail().toStdString());
    }
    bd.sauvegarder();
    bd.getAllContact();
}
/**
 * @brief Affiche une boîte de dialogue pour ajouter une interaction
 */

void MainWindow::on_actionNouvelle_Interaction_triggered()
{
    FenetreAjoutInter *fai = new FenetreAjoutInter(this, gc);
    fai->exec();
    bd.sauvegarder();
    bd.getAllContact();
}


/**
 * @brief Rempli le model pour le QTableView avec des contacts
 * @author BELLEGUEULLE Mathieu
 */
void MainWindow::ajoutDonneesContact()
{
    if(checkRechAdvDate->isChecked())
    {
        std::string s = "";
        std::list<Contact*> liste = bd.recherchecontact(s,dateEditDebutRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       dateEditFinRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       false, true);


        int index =0;
        if(liste.size()>0)
        for(auto it : liste)
        {
            QStandardItem *item0 = new QStandardItem(QString::number(it->getId()));
            model->setItem(index, 0, item0);
            QStandardItem *item = new QStandardItem(QString::fromStdString(it->getNom()));
            model->setItem(index, 1, item);
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(it->getPrenom()));
            model->setItem(index,2,item1);
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(it->getEntreprise()));
            model->setItem(index,3,item2);
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(it->getDate()));
            model->setItem(index,4,item3);
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(it->getGestionInteraction().getInteractionList().back()->getDate()));
            model->setItem(index,5,item4);
            index++;
        }
    }
    else
    {
        int i=0;
        for(auto it : gc->getContactList())
        {
            QStandardItem *item0 = new QStandardItem(QString::number(it->getId()));
            model->setItem(i, 0, item0);
            QStandardItem *item = new QStandardItem(QString::fromStdString(it->getNom()));
            model->setItem(i, 1, item);
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(it->getPrenom()));
            model->setItem(i,2,item1);
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(it->getEntreprise()));
            model->setItem(i,3,item2);
            QStandardItem *item3 = new QStandardItem(QString::fromStdString(it->getDate()));
            model->setItem(i,4,item3);
            QStandardItem *item4 = new QStandardItem(QString::fromStdString(it->getGestionInteraction().getInteractionList().back()->getDate()));
            model->setItem(i,5,item4);
            i++;
        }
    }
}
/**
 * @brief Rempli le model pour le QTableView avec des interactions
 * @author BELLEGUEULLE Mathieu
 */
void MainWindow::ajoutDonneesInteraction()
{
    if (checkRechAdvDate->isChecked()||checkRechAdvContact->isChecked())
    {


        int i = listeContact[cBSelectionContact->currentIndex()]->getId();
        std::list<Interaction*> liste = bd.rechercheInterraction(dateEditDebutRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       dateEditFinRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       i, checkRechAdvDate->isChecked(),
                                                       checkRechAdvContact->isChecked());


        int index =0;
        for(auto it : liste)
        {
            QStandardItem *item0 = new QStandardItem(QString::number(it->getID()));
            model->setItem(index, 0, item0);
            QStandardItem *item = new QStandardItem(QString::number(it->getContact()->getId()));
            model->setItem(index, 1, item);
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(it->getContenu()));
            model->setItem(index,2,item1);
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(it->getDate()));
            model->setItem(index,3,item2);
            index++;
        }
    }
    else
    {
        int i =0;
        for ( auto it : gc->getContactList())
        {
            for (auto itt : it->getGestionInteraction().getInteractionList() )
            {
                QStandardItem *item0 = new QStandardItem(QString::number(itt->getID()));
                model->setItem(i, 0, item0);
                QStandardItem *item = new QStandardItem(QString::number(it->getId()));
                model->setItem(i, 1, item);
                QStandardItem *item1 = new QStandardItem(QString::fromStdString(itt->getContenu()));
                model->setItem(i,2,item1);
                QStandardItem *item2 = new QStandardItem(QString::fromStdString(itt->getDate()));
                model->setItem(i,3,item2);
                i++;
            }
        }
    }
}
/**
 * @brief Rempli le model pour le QTableView avec des todos
 * @author BELLEGUEULLE Mathieu
 */
void MainWindow::ajoutDonneesTodo()
{
    if(checkRechAdvDate->isChecked()||checkRechAdvContact->isChecked())
    {
        int i = listeContact[cBSelectionContact->currentIndex()]->getId();
        std::list<toDo*> liste = bd.recherchelistetodo(dateEditDebutRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       dateEditFinRech->date().toString("dd-MM-yyyy").toStdString(),
                                                       i, checkRechAdvDate->isChecked(),
                                                       checkRechAdvContact->isChecked());


        int index =0;
        for(auto it : liste)
        {
            QStandardItem *item0 = new QStandardItem(QString::number(it->getID()));
            model->setItem(index, 0, item0);
            QStandardItem *item = new QStandardItem(QString::number(it->getOwner()->getID()));
            model->setItem(index, 1, item);
            QStandardItem *item1 = new QStandardItem(QString::fromStdString(it->getContenu()));
            model->setItem(index,2,item1);
            QStandardItem *item2 = new QStandardItem(QString::fromStdString(it->getDate()));
            model->setItem(index,3,item2);
            index++;
        }
    }
    else
    {
        int i=0;
        for ( auto it : gc->getContactList())
        {
            for (auto itt : it->getGestionInteraction().getInteractionList() )
            {
                for(auto ittt : itt->getGestionToDo().getToDoList())
                {
                    QStandardItem *item0 = new QStandardItem(QString::number(ittt->getID()));
                    model->setItem(i, 0, item0);
                    QStandardItem *item = new QStandardItem(QString::number(itt->getID()));
                    model->setItem(i, 1, item);
                    QStandardItem *item1 = new QStandardItem(QString::fromStdString(ittt->getContenu()));
                    model->setItem(i,2,item1);
                    QStandardItem *item2 = new QStandardItem(QString::fromStdString(ittt->getDate()));
                    model->setItem(i,3,item2);
                    i++;
                }
            }
        }
    }
}
/**
 * @brief montre ou cache les lignes qui correspondent ou non au texte de la barre de recherche
 * @author BELLEGUEULLE Mathieu
 */
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
/**
 * @brief Déclenche un tri suivant l'option sélectionnéée
 * @author BELLEGUEULLE Mathieu
 */
void MainWindow::tri(int index)
{
    model->sort(index);
}

/**
 * @brief Modifie le model et la comboBox suivant l'option sélectionné
 * @author BELLEGUEULLE Mathieu
 * @param index valeur(1,2,3) pour (contact, interaction, todo)
 */
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
    //ListeSelection->hideColumn(0);
    model->sort(cBSelectionTri->currentIndex());
}
/**
 * @brief Déclenche le changement de modle pour les contacts
 * @author BELLEGUEULL MATHIEU
 */
void MainWindow::selectionTypeContact()
{
    modifModel(1);
}
/**
 * @brief Déclenche le changement de modle pour les interactions
 * @author BELLEGUEULL MATHIEU
 */
void MainWindow::selectionTypeInteraction()
{
    modifModel(2);
}
/**
 * @brief Déclenche le changement de modle pour les todos
 * @author BELLEGUEULL MATHIEU
 */
void MainWindow::selectionTypeTodo()
{
    modifModel(3);
}

/**
 * @brief Déclenche l'affichage de l'objet demandée(contact, interaction, todo) dans la partie gauche de l'application par la création éventuel d'instance de visucontactwidget/interaction/todo
 * @param MI Elément sélectionné dans le QTableView
 */
void MainWindow::affiche(QModelIndex MI)
{
    int row = MI.row();
    int i = model->index(row, 0).data().toInt();
    VisuContactWidget * VCW = nullptr;
    VisuInteractionWidget * VIW = nullptr;
    tabWidgetVisu->clear();
    switch (BoutonsSelection->checkedId()) {
        case 1 :
                 VCW = new VisuContactWidget(gc->getContactByID(i));
                 tabWidgetVisu->addTab(VCW, "Contact");
                 break;
        case 2 :
                 VCW = new VisuContactWidget(gc->getInterractionByID(i)->getContact());
                 tabWidgetVisu->addTab(VCW, "Contact");
                 VIW = new VisuInteractionWidget(gc->getInterractionByID(i));
                 tabWidgetVisu->addTab(VIW, "Interaction");
                 tabWidgetVisu->setCurrentIndex(1);
                 break;
        case 3 : VCW = new VisuContactWidget(gc->gettoDoByID(i)->getOwner()->getContact());
                 tabWidgetVisu->addTab(VCW, "Contact");
                 VIW = new VisuInteractionWidget(gc->gettoDoByID(i)->getOwner());
                 tabWidgetVisu->addTab(VIW, "Interaction");
                 VisuTodoWidget *VTW = new VisuTodoWidget(gc->gettoDoByID(i));
                 tabWidgetVisu->addTab(VTW, "Tâche");
                 tabWidgetVisu->setCurrentIndex(2);
    }
    if (VCW != nullptr)
    {
        connect(VCW, SIGNAL(sauv()), this, SLOT(sauvegarde()));
        connect(VCW, SIGNAL(efface(Contact*)), this, SLOT(effaceContact(Contact*)));
    }
    if (VIW != nullptr)
        connect(VIW, SIGNAL(afficheToDo(toDo*)), this, SLOT(afficheTabTodo(toDo*)));
}
/**
 * @brief slot pour effacer un contact
 * @param c Contact à effacer
 */
void MainWindow::effaceContact(Contact * c)
{

    gc->removeContact(c);
    modifModel(BoutonsSelection->checkedId());
    bd.SupprimeContact(c);
    bd.sauvegarder();
    bd.getAllContact();
}
/**
 * @brief slot pour afficher un todo depuis le visuinteractionwidget
 * @param t Todo à afficher
 */
void MainWindow::afficheTabTodo(toDo* t)
{
    if(tabWidgetVisu->count()==3)
        tabWidgetVisu->removeTab(2);
    VisuTodoWidget *VTW = new VisuTodoWidget(t);
    tabWidgetVisu->addTab(VTW, "Tâche");
    tabWidgetVisu->setCurrentIndex(2);
}

void MainWindow::sauvegarde()
{
    bd.sauvegarder();
    bd.getAllContact();
}
