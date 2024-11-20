// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UMasterWidget.h"
#include "Components/DetailsView.h"
#include "Engine/DataAsset.h"
#include "Settings/UDataAssetReaderSettings.h"


void UMasterWidget::NativeConstruct()
{
	UDataAssetReaderSettings* Settings = GetMutableDefault<UDataAssetReaderSettings>();
	AssetPath =  Settings->DataAssetPath;
	Super::NativeConstruct();
}

void UMasterWidget::CreateTemplate()
{
		if (!ScrollBox || !CategoryRow || !TemplateForProperty || !DataAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing one of this params :  ScrollBox / CategoryRow / TemplateForProperty / DataAsset"));
	}
	else
	{
		ScrollBox->ClearChildren();
		TArray<FName> CategoryList;
		// to do filter by category -> create a widget category that can be construct with a categorie name
		// Create a new system for unspecified values like FStruct of something maybe here we need to create a new system of edition
		UE_LOG(LogTemp, Warning, TEXT("Iterate property"));
		UUserWidget* NewWidget = CreateWidget(this, TemplateForProperty);
		UParamRow* ParamWidget = Cast<UParamRow>(NewWidget);
		ParamWidget->DetailsView->bAllowFiltering = true;
		ParamWidget->WidgetParent = this;
		ParamWidget->CurrentDataAsset = DataAsset;
		for (TFieldIterator<FProperty> PropIt(DataAsset->GetClass()); PropIt; ++PropIt)
		{
			FString Name = PropIt->GetName();
			if (Name != "NativeClass")
			{
					CategoryList.AddUnique(FName(PropIt->GetMetaData(TEXT("Category"))));
			}
		}
		ParamWidget->SetDetailViewData(CategoryList);
		ScrollBox->AddChild(ParamWidget);
	}
}
