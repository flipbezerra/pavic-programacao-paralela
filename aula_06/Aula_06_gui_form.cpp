// Aula 05 PAVIC Progrmação Paralela 2024

#include "gui_form.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    pavicgui2024::Pavic_gui_2024_Form form;
 
    Application::Run(% form);

}