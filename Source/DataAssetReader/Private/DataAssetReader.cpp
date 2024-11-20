// Copyright Epic Games, Inc. All Rights Reserved.

#include "DataAssetReader.h"

#include "ISettingsContainer.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Settings/UDataAssetReaderSettings.h"

#define LOCTEXT_NAMESPACE "FDataAssetReaderModule"

void FDataAssetReaderModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("Data Asset Reader Plugin",
			LOCTEXT("RuntimeWDCategoryName", "Data Asset Reader Plugin"),
			LOCTEXT("RuntimeWDCategoryDescription", "Data Asset Reader configuration"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Data Asset Reader Plugin", "Data Asset Reader Configuration",
			LOCTEXT("RuntimeGeneralSettingsName", "Data Asset Reader Configuration"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for Data Asset Reader"),
			GetMutableDefault<UDataAssetReaderSettings>()
			);
	}
}

void FDataAssetReaderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDataAssetReaderModule, DataAssetReader)