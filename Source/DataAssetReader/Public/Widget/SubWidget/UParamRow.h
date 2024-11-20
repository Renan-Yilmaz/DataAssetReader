// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Components/DetailsView.h"
#include "Components/SinglePropertyView.h"
#include "UParamRow.generated.h"

class UDataAsset;
/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class DATAASSETREADER_API UParamRow : public UEditorUtilityWidget
{
	GENERATED_BODY()
	
	FProperty* Property;
public:
	
	UPROPERTY(BlueprintReadOnly,Category="DataAsset Reader")
	FString PropertyName;
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget),Category="DataAsset Reader")
	class UTextBlock* VariableTitle = nullptr;

	UPROPERTY(BlueprintReadOnly,Category="DataAsset Reader")
	UDataAsset* CurrentDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget),Category="DataAsset Reader")
	USinglePropertyView* PropertyView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget),Category="DataAsset Reader")
	UDetailsView* DetailsView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="DataAsset Reader")
	bool bDisplayDetailView = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="DataAsset Reader")
	bool bHideText = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DataAsset Reader")
	class UMasterWidget* WidgetParent;
	
	UFUNCTION(BlueprintCallable,Category="DataAsset Reader")
	void SetData(FString Name);

	UFUNCTION(BlueprintCallable,Category="DataAsset Reader")
	void setProperty();

	UFUNCTION(BlueprintCallable,Category="DataAsset Reader")
	void PreviewProperty();

	UFUNCTION(BlueprintCallable,Category="DataAsset Reader")
	void SetDetailViewData(TArray<FName> Category);
	
};
