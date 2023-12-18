#include "useprivilegebuttonView.h"

usePrivilegeButtonView::usePrivilegeButtonView(QWidget *parent) : QPushButton(parent) {
    setText("Utiliser Privilège");
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}
