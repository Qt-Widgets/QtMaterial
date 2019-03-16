#include "qtmaterialradiobutton.h"
#include "qtmaterialradiobutton_p.h"
#include <QStateMachine>
#include <QState>
#include <QPropertyAnimation>
#include <QColor>
#include "components/lib/qtmaterialcheckable_internal.h"

/*!
 *  \class QtMaterialRadioButtonPrivate
 *  \internal
 */

QtMaterialRadioButtonPrivate::QtMaterialRadioButtonPrivate(QtMaterialRadioButton *q)
    : QtMaterialCheckablePrivate(q)
{
}

QtMaterialRadioButtonPrivate::~QtMaterialRadioButtonPrivate()
{
}

void QtMaterialRadioButtonPrivate::init()
{
    Q_Q(QtMaterialRadioButton);

    q->setAutoExclusive(true);

    q->setCheckedIcon(QIcon(":/Images/radioBtn_selected.png"));
    q->setUncheckedIcon(QIcon(":/Images/radioBtn_deselect.png"));

    uncheckedState->assignProperty(checkedIcon, "iconSize", 0);
    uncheckedState->assignProperty(uncheckedIcon, "iconSize", 24);

    disabledUncheckedState->assignProperty(checkedIcon, "iconSize", 0);
    disabledUncheckedState->assignProperty(uncheckedIcon, "iconSize", 24);

    checkedState->assignProperty(uncheckedIcon, "iconSize", 0);
    checkedState->assignProperty(checkedIcon, "iconSize", 24);

    disabledCheckedState->assignProperty(uncheckedIcon, "iconSize", 0);
    disabledCheckedState->assignProperty(checkedIcon, "iconSize", 24);

    uncheckedState->assignProperty(checkedIcon, "opacity", 0);
    uncheckedState->assignProperty(uncheckedIcon, "opacity", 1);

    checkedState->assignProperty(uncheckedIcon, "opacity", 0);
    checkedState->assignProperty(checkedIcon, "opacity", 1);

    checkedIcon->setIconSize(0);

    //

    checkedState->assignProperty(checkedIcon, "color", q->checkedColor());
    checkedState->assignProperty(uncheckedIcon, "color", q->uncheckedColor());
    uncheckedState->assignProperty(uncheckedIcon, "color", q->uncheckedColor());

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(checkedIcon, "iconSize", q);
    animation->setDuration(250);
    stateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(uncheckedIcon, "iconSize", q);
    animation->setDuration(250);
    stateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(uncheckedIcon, "opacity", q);
    animation->setDuration(250);
    stateMachine->addDefaultAnimation(animation);

    animation = new QPropertyAnimation(checkedIcon, "opacity", q);
    animation->setDuration(250);
    stateMachine->addDefaultAnimation(animation);
}

/*!
 *  \class QtMaterialRadioButton
 */

QtMaterialRadioButton::QtMaterialRadioButton(QWidget *parent)
    : QtMaterialCheckable(*new QtMaterialRadioButtonPrivate(this), parent)
{
    d_func()->init();
}

QtMaterialRadioButton::~QtMaterialRadioButton()
{
}

void QtMaterialRadioButton::setupProperties()
{
    QtMaterialCheckable::setupProperties();

    Q_D(QtMaterialRadioButton);

    d->checkedState->assignProperty(d->checkedIcon, "color", checkedColor());
    d->checkedState->assignProperty(d->uncheckedIcon, "color", uncheckedColor());
    d->uncheckedState->assignProperty(d->uncheckedIcon, "color", uncheckedColor());
}
