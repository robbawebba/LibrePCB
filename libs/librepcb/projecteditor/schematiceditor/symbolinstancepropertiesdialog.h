/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * http://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBREPCB_PROJECT_SYMBOLINSTANCEPROPERTIESDIALOG_H
#define LIBREPCB_PROJECT_SYMBOLINSTANCEPROPERTIESDIALOG_H

/*******************************************************************************
 *  Includes
 ******************************************************************************/
#include <QtCore>
#include <QtWidgets>

/*******************************************************************************
 *  Namespace / Forward Declarations
 ******************************************************************************/
namespace librepcb {

class UndoStack;
class UndoCommand;

namespace project {

class Project;
class ComponentInstance;
class SI_Symbol;

namespace editor {

namespace Ui {
class SymbolInstancePropertiesDialog;
}

/*******************************************************************************
 *  Class SymbolInstancePropertiesDialog
 ******************************************************************************/

/**
 * @brief The SymbolInstancePropertiesDialog class
 */
class SymbolInstancePropertiesDialog final : public QDialog {
  Q_OBJECT

public:
  // Constructors / Destructor
  SymbolInstancePropertiesDialog() = delete;
  SymbolInstancePropertiesDialog(const SymbolInstancePropertiesDialog& other) =
      delete;
  SymbolInstancePropertiesDialog(Project& project, ComponentInstance& cmp,
                                 SI_Symbol& symbol, UndoStack& undoStack,
                                 QWidget* parent) noexcept;
  ~SymbolInstancePropertiesDialog() noexcept;

  // Operator Overloadings
  SymbolInstancePropertiesDialog& operator       =(
      const SymbolInstancePropertiesDialog& rhs) = delete;

private:  // Methods
  void keyPressEvent(QKeyEvent* e);
  void accept();
  bool applyChanges() noexcept;

private:  // Data
  Project&                                           mProject;
  ComponentInstance&                                 mComponentInstance;
  SI_Symbol&                                         mSymbol;
  UndoStack&                                         mUndoStack;
  QScopedPointer<Ui::SymbolInstancePropertiesDialog> mUi;
};

/*******************************************************************************
 *  End of File
 ******************************************************************************/

}  // namespace editor
}  // namespace project
}  // namespace librepcb

#endif  // LIBREPCB_PROJECT_SYMBOLINSTANCEPROPERTIESDIALOG_H
