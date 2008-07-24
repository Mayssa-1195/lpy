/* ---------------------------------------------------------------------------
 #
 #       L-Py: L-systems in Python
 #
 #       Copyright 2003-2008 UMR Cirad/Inria/Inra Dap - Virtual Plant Team
 #
 #       File author(s): F. Boudon (frederic.boudon@cirad.fr)
 #
 # ---------------------------------------------------------------------------
 #
 #                      GNU General Public Licence
 #
 #       This program is free software; you can redistribute it and/or
 #       modify it under the terms of the GNU General Public License as
 #       published by the Free Software Foundation; either version 2 of
 #       the License, or (at your option) any later version.
 #
 #       This program is distributed in the hope that it will be useful,
 #       but WITHOUT ANY WARRANTY; without even the implied warranty of
 #       MERCHANTABILITY or FITNESS For A PARTICULAR PURPOSE. See the
 #       GNU General Public License for more details.
 #
 #       You should have received a copy of the GNU General Public
 #       License along with this program; see the file COPYING. If not,
 #       write to the Free Software Foundation, Inc., 59
 #       Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 #
 # ---------------------------------------------------------------------------
 */

#ifndef __plot_string_h__
#define __plot_string_h__

#include "lpy_config.h"
#include "stringmatching.h"
#include <plantgl/scenegraph/scene/scene.h>
#include <plantgl/algo/modelling/pglturtle.h>

PYLSYS_BEGIN_NAMESPACE

class AxialTree;

/*---------------------------------------------------------------------------*/

typedef void (*PlotFunction)(const PGL(ScenePtr)&);
typedef std::vector<uint_t> (*GetSelectFunction)();

void PYLSYS_API registerPglPlotFunction(PlotFunction func);
void PYLSYS_API cleanPglPlotFunction();
void PYLSYS_API registerGetSelectionFunction(GetSelectFunction func);
void PYLSYS_API cleanGetSelectionFunction();

void PYLSYS_API plot(const PGL(ScenePtr)&);
std::vector<uint_t> PYLSYS_API getSelection();

void PYLSYS_API plot(AxialTree& tree);
void PYLSYS_API plot(AxialTree& tree, PGL::PglTurtle& turtle);

void PYLSYS_API plot(AxialTree& tree, StringMatching& matching);
void PYLSYS_API plot(AxialTree& tree, StringMatching& matching, PGL::PglTurtle& turtle);

PGL(ScenePtr) PYLSYS_API scene(AxialTree& tree);
PGL(ScenePtr) PYLSYS_API scene(AxialTree& tree, PGL::PglTurtle& turtle);

PGL(ScenePtr) PYLSYS_API scene(AxialTree& tree, StringMatching& matching);
PGL(ScenePtr) PYLSYS_API scene(AxialTree& tree, StringMatching& matching, PGL::PglTurtle& turtle);

/*---------------------------------------------------------------------------*/

PYLSYS_END_NAMESPACE

#endif

