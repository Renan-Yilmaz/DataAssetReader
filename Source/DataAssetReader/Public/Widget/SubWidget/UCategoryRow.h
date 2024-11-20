// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "UCategoryRow.generated.h"

class UMasterWidget;
/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class DATAASSETREADER_API  UCategoryRow : public UEditorUtilityWidget
{
	GENERATED_BODY()



public:
	UPROPERTY(BlueprintReadWrite,Category="DataAsset Reader")
	FString CategName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget),Category="DataAsset Reader")
	class UVerticalBox* ParamList;

	UPROPERTY(BlueprintReadOnly,Category="DataAsset Reader")
     UMasterWidget* WidgetParent;
};
