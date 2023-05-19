#pragma once

using namespace System;
using namespace Autodesk::Revit::UI::Selection;
namespace RevitAddIn {
	[Autodesk::Revit::Attributes::Transaction(
		Autodesk::Revit::Attributes::TransactionMode::Manual)]
	[Autodesk::Revit::Attributes::Regeneration(
		Autodesk::Revit::Attributes::RegenerationOption::Manual)]
	public ref class Command
		: Autodesk::Revit::UI::IExternalCommand
	{
	public:
		virtual Autodesk::Revit::UI::Result Execute(
			Autodesk::Revit::UI::ExternalCommandData^ commandData,
			String^% message,
			Autodesk::Revit::DB::ElementSet^ elements);
	};

	public ref class SelectionFilter : ISelectionFilter
	{
	public:
		virtual bool AllowElement(Autodesk::Revit::DB::Element^ elem);
		virtual bool AllowReference(Autodesk::Revit::DB::Reference^ reference,
		                            Autodesk::Revit::DB::XYZ^ position);
	};
}
