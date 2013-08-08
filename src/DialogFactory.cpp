#include "DialogFactory.h"

#include "components/ConfirmationDialog.h"
#include "components/InformationDialog.h"

int DialogFactory::showConfirmationDialog(Surface *screen, const char *message) {
	ConfirmationDialog dlg(screen, message);
	return dlg.showGetSelected();
}

void DialogFactory::showInformationDialog(Surface *screen, const char *message) {
	InformationDialog dlg(screen, message);
	dlg.show();
}

char *DialogFactory::showInputDialog(Surface *screen, const char *message) {
	return NULL;
}

