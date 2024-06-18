// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyHUD::DrawHUD()
{
    Super::DrawHUD();
}

void AMyHUD::ShowGameOverMessage()
{
    bIsGameOver = true;
    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        PC->bShowMouseCursor = true;
        PC->SetInputMode(FInputModeUIOnly());
        if (GameOverWidgetClass) {
            GameOverWidget = CreateWidget<UUserWidget>(this->GetGameInstance(), GameOverWidgetClass);
        }
        if (GameOverWidget) {
            GameOverWidget->AddToViewport();
       }
        
    }
}
