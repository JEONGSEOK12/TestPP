// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeHead.h"
#include "SnakeGameMode.h"

// Sets default values
ASnakeHead::ASnakeHead()
{
	// 언리얼에서 프레임마다 Tick을 돌려야 하는 액터는
	// PrimaryActorTick.bCanEverTick = true; 로 만들어줘야 Tick을 돌릴수가 있습니다.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 생성자에서 보통 설정해주는게 일반적인데. 
	// 틱을 돌릴거냐 말거냐
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;


}

// Called when the game starts or when spawned
void ASnakeHead::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASnakeHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASnakeHead::LeftMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector);
}


void ASnakeHead::RightMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector);
}
void ASnakeHead::UpMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::UpVector);
}
void ASnakeHead::DownMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::DownVector);
}







void ASnakeHead::LeftAction()
{
	FTransform Trans;
	Trans.SetLocation(GetActorLocation());
	
	FVector MovePos = FVector::LeftVector * 100.0f;

	FTransform Trans2;
	Trans2.SetLocation(GetActorLocation()+MovePos);

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(MovePos);
	// 여기에 Body가 있는지 확인해야 한다.
	
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();


		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody.Add(MyBody);
		
		MyBody->Destroy();
		NewBody[0] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);

		++BodyCounter;
	}

	for (int i = 0; i < BodyCounter; i++)
	{
		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody[i]->Destroy();
		NewBody[i] = MyBody;
		MyBody->Destroy();
		NewBody[i] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
	}

}














void ASnakeHead::RightAction()
{
	FTransform Trans;
	Trans.SetLocation(GetActorLocation());

	FVector MovePos = FVector::RightVector * 100.0f;

	FTransform Trans2;
	Trans2.SetLocation(GetActorLocation() + MovePos);

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(MovePos);
	// 여기에 Body가 있는지 확인해야 한다.

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();


		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody.Add(MyBody);

		MyBody->Destroy();
		NewBody[0] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);

		++BodyCounter;
	}

	for (int i = 0; i < BodyCounter; i++)
	{
		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody[i]->Destroy();
		NewBody[i] = MyBody;
		MyBody->Destroy();
		NewBody[i] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
	}

}











void ASnakeHead::UpAction()
{
	FTransform Trans;
	Trans.SetLocation(GetActorLocation());

	FVector MovePos = FVector::UpVector * 100.0f;

	FTransform Trans2;
	Trans2.SetLocation(GetActorLocation() + MovePos);

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(MovePos);
	// 여기에 Body가 있는지 확인해야 한다.

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();


		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody.Add(MyBody);

		MyBody->Destroy();
		NewBody[0] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);

		++BodyCounter;
	}

	for (int i = 0; i < BodyCounter; i++)
	{
		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody[i]->Destroy();
		NewBody[i] = MyBody;
		MyBody->Destroy();
		NewBody[i] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
	}

}




void ASnakeHead::DownAction()
{
	FTransform Trans;
	Trans.SetLocation(GetActorLocation());

	FVector MovePos = FVector::DownVector * 100.0f;

	FTransform Trans2;
	Trans2.SetLocation(GetActorLocation() + MovePos);

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		return;
	}

	AddActorLocalOffset(MovePos);
	// 여기에 Body가 있는지 확인해야 한다.

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();


		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody.Add(MyBody);

		MyBody->Destroy();
		NewBody[0] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);

		++BodyCounter;
	}

	for (int i = 0; i < BodyCounter; i++)
	{
		AActor* MyBody = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
		NewBody[i]->Destroy();
		NewBody[i] = MyBody;
		MyBody->Destroy();
		NewBody[i] = GetWorld()->SpawnActor<AActor>(BPBody, Trans);
	}

}








//NewBody[0] = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
//
//for (int i = 1; i < BodyCounter; i++)
//{
//	NextBody = NewBody[i];
//	NewBody[i] = NewBody[0];
//	NewBody[0] = NextBody;
//}