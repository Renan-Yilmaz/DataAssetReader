#include "Settings/UDataAssetReaderSettings.h"


UDataAssetReaderSettings::UDataAssetReaderSettings(const FObjectInitializer& ObjectInitializer)
{
	DataAssetPath = TEXT("/Game/Data");
}
#if WITH_EDITOR

void UDataAssetReaderSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
		// Try to Rebuild editor menu to handle change in settings but not seems to work
		// if (PropertyChangedEvent.Property == nullptr)
		// {
		// 	return;
		// }
		// IBHHEditorModule Editor = FModuleManager::Get().GetModuleChecked<IBHHEditorModule>("BigHelmetHeroesEditor");
		// Editor.BindCommands();
		// Editor.BuildMenu();
}

#endif	
