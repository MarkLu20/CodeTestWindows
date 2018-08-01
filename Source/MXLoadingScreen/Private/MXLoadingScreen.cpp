﻿#include "MXLoadingScreen/Public/MXLoadingScreen.h"
#include "GenericApplication.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include  "Runtime/MoviePlayer/Public/MoviePlayer.h"

struct FMXloadingScreenBrush : public FSlateDynamicImageBrush, public FGCObject
{

	FMXloadingScreenBrush(const FName InTextureName, const FVector2D &InImageSize) :
		FSlateDynamicImageBrush(InTextureName, InImageSize)
	{
	
		ResourceObject = LoadObject<UObject>(NULL,*InTextureName.ToString());
	
	}
	//virtual void AddRe


	virtual void AddReferencedObjects(FReferenceCollector& Collector) override
	{
		if (ResourceObject)
		{
			Collector.AddReferencedObject(ResourceObject);
		}
	}

};
class SMXLoadingScreenWidget :public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SMXLoadingScreenWidget) {}
	SLATE_END_ARGS()
		void Construct(const FArguments &InArgs)
	{
		
		static const FName LoadingScreenName(TEXT("/Game/UI/Menu/LoadingScreen.LoadingScreen"));
		LoadingScreenBrush = MakeShareable(new FMXloadingScreenBrush(LoadingScreenName,FVector2D(1920,1080)));
		ChildSlot
			[  //添加一个Overlay控件 因为这个控件可以放多个子物体所以可以添加多个slot
				//这样的控件加子物体都是先添加一个slot对这个slot设置 然后添加子物体控件
				SNew(SOverlay)
				//添加一个slot放一个子物体（***一边拉umg看一边写slate代码*********）
				+ SOverlay::Slot()
			    .HAlign(HAlign_Fill)
			    .VAlign(VAlign_Fill)
			    [
				SNew(SImage)
				.Image(LoadingScreenBrush.Get())
			    ]
		       
		        +SOverlay::Slot()
                 .HAlign(HAlign_Fill)
		         .VAlign(VAlign_Fill)
				 [
				    SNew(SSafeZone)
				    .VAlign(VAlign_Bottom)
				    .HAlign(HAlign_Right)
                    .Padding(10.0f)
                    .IsTitleSafe(true)
					[
					    SNew(SThrobber)
                    
                        .Visibility(EVisibility::Visible)
					
					
					]
				 ]
				+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Bottom)
					.Padding(50.0f)
					[  
						
						
						//给该变量赋值 同时添加该类型控件
					     SAssignNew(Bar,SProgressBar)
						///直接添加控件
						//SNew(SProgressBar)
						
						.Percent(this,&SMXLoadingScreenWidget::SetParPercent)
				        .FillColorAndOpacity(FSlateColor(FLinearColor( 0.0f,0.5f,1.0f,1.0f)))
				 ]
			];
	
	}
	
private:
	TSharedPtr<FSlateDynamicImageBrush> LoadingScreenBrush;
	//声明一个相应控件的共享指针（方便后面使用）
	TSharedPtr<SProgressBar> Bar;

	 TOptional<float>   SetParPercent() const
	{
		
		return 0.6f;
	
	}

};
class FMXLoadingScreenModule : public IMXLoadingScreenModule
{

public:

	

	// 通过 IMXLoadingScreenModule 继承
	virtual void StartInGameLoadingScreen() override
	{

		//FLoadingScreenAttributes LoadingScreen;
		//LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		//

		////GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		UObject *t= LoadObject<UObject>(NULL, TEXT("/Game/UI/Menu/LoadingScreen.LoadingScreen"));
		if (IsMoviePlayerEnabled())
		{
			FLoadingScreenAttributes LoadingScreen;
			LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
			LoadingScreen.WidgetLoadingScreen = SNew(SMXLoadingScreenWidget);
			/*LoadingScreen.MoviePaths.Add(TEXT("LoadingScreen"));*/
			MoviePlayer = GetMoviePlayer();
			MoviePlayer->SetupLoadingScreen(LoadingScreen);
			
			//MoviePlayer->WaitForMovieToFinish();

		}
		
	}


	virtual void StartupModule() override
	{
		//LoadObject<UObject>(NULL, TEXT("/Game/UI/Menu/LoadingScreen.LoadingScreen"));
		//if (IsMoviePlayerEnabled())
		//{
		//	FLoadingScreenAttributes LoadingScreen;
		//	LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		//	//LoadingScreen.WidgetLoadingScreen = SNew(SMXLoadingScreenWidget);
		//	LoadingScreen.MoviePaths.Add(TEXT("LoadingScreen"));
		//	GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		//	GetMoviePlayer()->WaitForMovieToFinish();
		//	
		//}
	}


	// 通过 IMXLoadingScreenModule 继承
	virtual void ShutDownLoadingScreen() override
	{
		MoviePlayer->Shutdown();
	}
private:
	IGameMoviePlayer *MoviePlayer = nullptr;
};
IMPLEMENT_GAME_MODULE(FMXLoadingScreenModule, MXLoadingScreen);
