// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "SubWidget/UCategoryRow.h"
#include "SubWidget/UParamRow.h"
#include "UMasterWidget.generated.h"

class UDataAsset;
/**
 * 
 */
UCLASS()
class DATAASSETREADER_API UMasterWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable,category="DataAsset Reader")
	virtual void CreateTemplate();

	
private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader",meta=(AllowPrivateAccess))
	FString AssetPath;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader",meta=(AllowPrivateAccess))
	TSubclassOf<UParamRow> TemplateForProperty;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader",meta=(AllowPrivateAccess))
	TSubclassOf<UCategoryRow> CategoryRow;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader",meta=(AllowPrivateAccess))
	UDataAsset* DataAsset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader",meta=(AllowPrivateAccess))
	UScrollBox* ScrollBox;
	
};
