#include "main.h"
#include "mainWindow.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainWindow* frame = new MainWindow("Points",wxDefaultPosition, wxSize(800, 600));
    frame->Show(true);
    return true;
}