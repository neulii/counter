#ifndef POINTINPUTPANEL_H
#define POINTINPUTPANEL_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif



class PointInputPanel : public wxPanel
{

private:
    wxStaticText* playerName;
    wxTextCtrl* inputPoints;

       
public:
    PointInputPanel( wxWindow* parent,
					 const std::string& nameOfPlayer, 
					 wxWindowID id = wxID_ANY, 
					 const wxPoint& pos = wxDefaultPosition, 
					 const wxSize& size = wxSize( 250,80 ), 
					 long style = wxTAB_TRAVERSAL, 
					 const wxString& name = wxEmptyString );

    wxTextCtrl& getTextField();
    std::string getInput(); 
    
    void setLabelText(std::string labelText);
};

#endif // POINTINPUTPANEL_H
