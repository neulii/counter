#include "mainWindow.h"
#include "functions.h"

#include "newGameWindow.h"

MainWindow::MainWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    //wxPanel* panel = new wxPanel(this, wxID_ANY);

  /*  testButton = new wxButton(panel, ID_EXIT, wxT("Quit"), wxPoint(20, 20));
    newButton = new wxButton(panel, ID_NEWBUTTON, wxT("NewButton"), wxPoint(20, 60));
    inputText = new wxTextCtrl(panel, ID_TEXTINPUT, wxT("super"), wxPoint(100, 100));*/

    playingPanel = NULL;
   


    wxMenu* menuFile = new wxMenu;

    menuFile->Append(ID_NewGame, "Neues Spiel", "Startet ein Neues Spiel");
    menuFile->Append(ID_SaveGame, "Speichern", "Speichert das bestehende Spiel");
    menuFile->Append(ID_OpenGame, "Oeffnen", "oeffnet ein Spiel");


    menuFile->AppendSeparator();
    menuFile->Append(ID_Exit,"Beenden", "Beendet das Programm");

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(ID_Info,"Info", "Blendet das Info Feld ein ;)");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Datei");
    menuBar->Append(menuHelp, "&Info");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("No do schaust ;)");

    Centre();

    game = new Game();
   
}

void MainWindow::OnExit(wxCommandEvent& event)
{

    this->Close(true);
    this->Destroy();


}
void MainWindow::OnAbout(wxCommandEvent& event)
{
    //wxMessageBox("Dieses Programm dient zum Zaehlen von Punkten beim Roemoen ;)", "...nur zur Info...",  wxYES_NO | wxICON_QUESTION);
    wxMessageDialog* dial = new wxMessageDialog(NULL,
        wxT("Error loading file"), wxT("Error"), wxYES_NO );
   
    dial->ShowModal();
}

void MainWindow::SaveGame(wxCommandEvent& event)
{

}

void MainWindow::OpenGame(wxCommandEvent& event)
{

}

void MainWindow::NewGame(wxCommandEvent& event)
{
   
    NewGameWindow* newGameWindow = new NewGameWindow("Neues Spiel",
                                                      wxDefaultPosition,
                                                      wxSize(500, 400));

    if (newGameWindow->ShowModal() == wxID_OK)
    {
   

        if (newGameWindow->getNewGameData())
        {   
            //wxMessageBox("neues spiel wird begonnen", "neue");

            //output playernames for debug to console
            for (int i = 0; i < game->getPlayers().size(); i++)
            {

                std::cout << game->getPlayers().at(i)->getName() << std::endl;

            }

            //when exist a playing panel destroy it
            //TODO must be changed
            if (playingPanel != NULL) {
                playingPanel->Destroy();
            }

            game = new Game(newGameWindow->getNewGameData());
            newGameWindow->Destroy();

            playingPanel = new PlayingPanel(this, *game);

            game->startGame();

            SetStatusText("Jetzt gehts Los!!");
           
           
          this->Layout();
        }
    }
    else
    {
        //anything else
        return;
    }
}

void MainWindow::OnClose(wxCloseEvent& event)
{
    this->Destroy();
}

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_MENU(ID_Exit, MainWindow::OnExit)
    EVT_MENU(ID_Info, MainWindow::OnAbout)
    EVT_MENU(ID_SaveGame, MainWindow::SaveGame)
    EVT_MENU(ID_OpenGame, MainWindow::OpenGame)
    EVT_MENU(ID_NewGame, MainWindow::NewGame)
    EVT_CLOSE(MainWindow::OnClose)


  /*  EVT_BUTTON(ID_NEWBUTTON, MainWindow::QuitButton)
    EVT_BUTTON(ID_EXIT, MainWindow::OnExit)*/
wxEND_EVENT_TABLE()
