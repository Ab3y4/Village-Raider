#include "howtoplay.h"
#include "mainmenu.h"
#include "ui_howtoplay.h"

HowToPlay::HowToPlay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HowToPlay)
{
    ui->setupUi(this);
}

HowToPlay::~HowToPlay()
{
    delete ui;
}

void HowToPlay::on_btnBack_clicked()
{
    // Goes back to the Main Menu window when the Back Button is clicked.
    MainMenu *menu = new MainMenu;
    menu->show();
    hide();
}
