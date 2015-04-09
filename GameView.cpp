#include "GameView.h"

//rien

using namespace std;



// Constructors/Destructors
//

GameView::GameView ()
{
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR GAMEVIEW" << endl;
}

GameView::~GameView ()
{
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR GAMEVIEW" << endl;
}

//
// Methods
//


// Accessor methods
//


// Other methods
//


void GameView::showMenu () const
{
    bool quit = false;
    while (!quit)
    {
        cout << "\n=====================" << endl;
        cout << "MENU" << endl;
        cout << "=====================" << endl;
        cout << "\t - (1) Play" << endl;
        cout << "\t - (2) Shop" << endl;
        cout << "\t - (3) Setting" << endl;
        cout << "\t - (4) Quit" << endl;
        int answer;
        cin >> answer;

        switch (answer)
        {
        case 1 :
            showGame();
            break;
        case 2 :
            showShop();
            break;
//        case 3 :
//            break;
        case 4:
            quit=true;
            break;
        default :
            cout << "raté"<<endl;

        }
    }
}


void GameView::showShop () const
{
}


/**
 */
void GameView::showLanguage () const
{
    // plus tard
}

/**
 */
void GameView::showStore () const
{
    // plus tard
}

/**
 */
void GameView::showBestScore () const
{
    // plus tard
    // gestion de fichiers
}

/**
 */
void GameView::showScore () const
{
    // on verra plus ytard pour le moment on s'en fout
}

/**
 */
void GameView::showGame () const
{
    // affichage de tous les éléments et d'un petit menu qui proôse de se déplacer et de tirer
    bool quit = false ;
    int tour =0;
    while (!quit)
    {
        tour++;
        cout << "\n=====================" << endl;
        cout << "TOUR N°" << tour << endl;
        cout << "=====================" << endl;

        cout << _model->getPlayer()->toString() << endl;

        for (auto enemy : *_model->getLevel()->getEnemy())
        {
            cout << enemy->toString() << endl;
        }

        cout << endl;

        for (auto bullet : *_model->getLevel()->getBullet())
        {
            cout << bullet->toString() << endl;
        }

        cout << "\n Actions :" << endl;
        cout << "\t - (1) Se deplacer" << endl;
        cout << "\t - (2) Tirer" << endl;
        cout << "\t - (3) Rien" << endl;
        cout << "\t - (4) Abandonner" << endl;
        int reponse ;
        cin >> reponse ;

        switch (reponse)
        {
        case 1:
            cout << "Deplacement X : " ;
            float dx;
            cin >> dx;
            cout << "Deplacement Y : " ;
            float dy;
            cin >> dy;

            _model->getPlayer()->Position::move(dx, dy);
            break;

        case 2:
            _model->getPlayer()->shoot("standart", "NORTH", _model->getLevel()->getBullet());
            break;

        case 3 :
            break;

        case 4:
            cout << "\nVous avez perdu" << endl;;
            quit = true;
            break;


        default:
            cout << "Entre 1 et 4_, ça passe au tour suivant" << endl;
            break;
        }

        _model->nextStep();
        _model->nextStep();
    }


}


/**
 */
void GameView::showIntroduction () const
{

}


//ACCESSEURS

void GameView::setModel(GameModel * model)
{
    _model = model ;
};


