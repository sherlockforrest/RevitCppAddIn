#include "pch.h"

#include "RevitAddIn.h"

#include <vcruntime_typeinfo.h>

Autodesk::Revit::UI::Result RevitAddIn::Command::Execute(
	Autodesk::Revit::UI::ExternalCommandData^ commandData,
	String^% message,
	Autodesk::Revit::DB::ElementSet^ elements)
{
	auto uiDoc = commandData->Application->ActiveUIDocument;
	auto doc = uiDoc->Document;
	auto selection = uiDoc->Selection;
	auto refer = selection->PickObject(ObjectType::Element, gcnew SelectionFilter, "select");
	auto ele = doc->GetElement(refer);
	auto wall = static_cast<Autodesk::Revit::DB::Wall^>(ele);
	Autodesk::Revit::UI::TaskDialog::Show("Revit", wall->Name);
	return Autodesk::Revit::UI::Result::Succeeded;
}

bool RevitAddIn::SelectionFilter::AllowElement(Autodesk::Revit::DB::Element^ elem)
{
	return safe_cast<Autodesk::Revit::DB::Wall^>(elem) != nullptr;
}

bool RevitAddIn::SelectionFilter::AllowReference(Autodesk::Revit::DB::Reference^ reference,
                                                 Autodesk::Revit::DB::XYZ^ position)
{
	return true;
}
