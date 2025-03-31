// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/SubWidget/UParamRow.h"
#include "UObject/UnrealTypePrivate.h"

void UParamRow::SetData(FString Name)
{
	PropertyName = Name;
	Property = CurrentObject->GetClass()->FindPropertyByName(FName(PropertyName));
	setProperty();
}

void UParamRow::setProperty()
{
	if (PropertyView)
	{
		TArray<FName> PropertyToShow;
		PropertyToShow.Add(FName(PropertyName));
		PropertyView->SetObject(CurrentObject);
		PropertyView->SetPropertyName(FName(PropertyName));
		PropertyView->SetNameOverride(FText::FromString(" "));
		if (Property)
		{
			if (Property->IsA(FArrayProperty::StaticClass()) || Property->IsA((FMapProperty::StaticClass())))
			{
				DetailsView->SetObject(CurrentObject);
				DetailsView->PropertiesToShow = PropertyToShow;
				bDisplayDetailView = true;
			}
		}
	}
}

void UParamRow::PreviewProperty()
{
	
}

void UParamRow::SetDetailViewData(TArray<FName> Category)
{
	DetailsView->SetObject(CurrentObject);
	DetailsView->CategoriesToShow = Category;
	bDisplayDetailView = true;
	bHideText = true;
}

