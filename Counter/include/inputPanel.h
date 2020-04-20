#ifndef INPUTPANEL_H
#define INPUTPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif



class InputPanel : public wxPanel
{

private:
    wxStaticText* labelPlayer;
    wxTextCtrl* inputName;

       
public:
    InputPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,64 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
    wxTextCtrl& getTextField();
   	std::string getInput(); 
	void setLabelText(std::string labelText);
};

#endif // !INPUTPANEL_H
