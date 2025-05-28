// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	float Speed = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	float RotationSpeed = 200;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Components", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	void Move(float Value);
	void Rotate(float Rotation);

	APlayerController* PlayerControllerRef;
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
