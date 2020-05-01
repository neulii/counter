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
    wxTextCtrl* pointsInput;

       
public:
    PointInputPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(318, 133), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
    ~PointInputPanel();

    wxTextCtrl& getTextField();
    std::string getInput(); 
    
    void setLabelText(std::string labelText);
};

#endif // POINTINPUTPANEL_H
