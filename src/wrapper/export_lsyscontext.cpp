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

#include "lsyscontext.h"
#include <boost/python/make_constructor.hpp>

using namespace boost::python;
PYLSYS_USING_NAMESPACE
PGL_USING_NAMESPACE

PglTurtle * lsc_turtle(LsysContext * l){
  return &(l->turtle);
}

void py_backward() { LsysContext::currentContext()->backward(); }
void py_forward() { LsysContext::currentContext()->forward(); }
bool py_isForward() { return LsysContext::currentContext()->isForward(); }

std::string getInitialisationFunctionName() { return LsysContext::InitialisationFunctionName; }

LsysContext * create_a_context() { return new LocalContext(); }

void export_LsysContext(){

    class_<LsysContext,boost::noncopyable>
	("LsysContext", no_init ) // <>("LsysContext()"))
	.def( "__init__", make_constructor( &create_a_context ), "LsysContext()" ) 
	.add_property("turtle",make_getter(&LsysContext::turtle,return_value_policy<reference_existing_object>()))
	.add_static_property("InitialisationFunctionName",&getInitialisationFunctionName)
	.add_property("animation_timestep",&LsysContext::get_animation_timestep,&LsysContext::set_animation_timestep)
	.add_property("options",make_getter(&LsysContext::options,return_value_policy<reference_existing_object>()))
    .def("is_animation_timestep_to_default",&LsysContext::is_animation_timestep_to_default)
	.def("__str__",        &LsysContext::str)
	.def("__repr__",        &LsysContext::str)
	.def("clear",          &LsysContext::clear)
	.def("empty",          &LsysContext::empty)
	.def("consider",       &LsysContext::consider)
	.def("ignore",         &LsysContext::ignore)
	.def("isConsidered",   
	(bool (LsysContext::*)(const std::string& module) const)
						   &LsysContext::isConsidered)
	.def("isIgnored",      
	(bool (LsysContext::*)(const std::string& module) const)
						   &LsysContext::isIgnored)
	.def("isConsidered",   
	(bool (LsysContext::*)(const Module& module) const)
						   &LsysContext::isConsidered)
	.def("isIgnored",      
	(bool (LsysContext::*)(const Module& module) const)
						   &LsysContext::isIgnored)
	.def("ignoring",       &LsysContext::ignoring)
	.def("keyword",        &LsysContext::keyword)
	.def("declare",        (void(LsysContext::*)(const std::string&))&LsysContext::declare)
	.def("updateNamespace",&LsysContext::updateNamespace)
	.def("getNamespace",   
	(void (LsysContext::*)(dict&) const)&LsysContext::getNamespace)
	.def("start",          &LsysContext::start)
	.def("end",            &LsysContext::end)
	.def("startEach",      &LsysContext::startEach)
	.def("endEach",        &LsysContext::endEach)
	.def("initialise",     &LsysContext::initialise)
	.def("setStart",       &LsysContext::setStart)
	.def("setEnd",         &LsysContext::setEnd)
	.def("setStartEach",   &LsysContext::setEndEach)
	.def("execute",        &LsysContext::execute)
	.def("evaluate",       &LsysContext::evaluate)
	.def("compile",        &LsysContext::compile)
	.def("__contains__",   &LsysContext::hasObject)
	.def("has_key",        &LsysContext::hasObject)
	.def("__getitem__",    &LsysContext::getObject)
	.def("__setitem__",    &LsysContext::setObject)
	.def("__delitem__",    &LsysContext::delObject)
	.def("makeCurrent",    &LsysContext::makeCurrent)
	.def("isCurrent",      &LsysContext::isCurrent)
	.def("done",           &LsysContext::done)
	.def("currentContext", &LsysContext::currentContext,return_value_policy<reference_existing_object>())
	.staticmethod("currentContext")
	.def("defaultContext", &LsysContext::defaultContext,return_value_policy<reference_existing_object>())
	.staticmethod("defaultContext")
	.def("globalContext", &LsysContext::globalContext,return_value_policy<reference_existing_object>())
	.staticmethod("globalContext")
	.def("backward",      &LsysContext::backward)
	.def("forward",      &LsysContext::forward)
	.def("isForward",      &LsysContext::isForward)
	.def("nproduce",  (void (LsysContext::*)(const AxialTree&) )&LsysContext::nproduce)
    .def("nproduce",  (void (LsysContext::*)(const boost::python::list&) )&LsysContext::nproduce)
	.def("useGroup",  &LsysContext::useGroup)
    .def("getGroup",  &LsysContext::getGroup)
    .def("isSelectionRequired", &LsysContext::isSelectionRequired)
    .def("setSelectionRequired", &LsysContext::setSelectionRequired)
    .def("getIterationNb", &LsysContext::getIterationNb)
	;
	def("consider",      &consider);
	def("ignore",      &ignore);
	def("context", &LsysContext::currentContext,return_value_policy<reference_existing_object>());
	def("backward",      &py_backward);
	def("forward",      &py_forward);
	def("isForward",      &py_isForward);
	def("nproduce",  (void (*)(const AxialTree&) )&nproduce);
    def("nproduce",  (void (*)(const boost::python::list&) )&nproduce);
    def("nproduce",  (void (*)(const std::string&) )&nproduce);
	def("useGroup",  &useGroup);
    def("getGroup",  &getGroup);
    def("isSelectionRequired", &isSelectionRequired);
    def("setSelectionRequired", &setSelectionRequired);
    def("getIterationNb", &getIterationNb);
	def("declare", &declare);

}