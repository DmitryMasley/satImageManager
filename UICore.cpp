#include "stdafx.h"
#include "UICore.h"


UICore::UICore(void)
	{
	}
//void UICore::setImageView(Emgu::CV::UI::ImageBox^ area, System::String^ path, System::String^ channel)
//	{
//	area->Image = nullptr;
//	Image<Bgr, UINT8>^ img = gcnew Image<Bgr, UINT8>(path);
//	//array<Image<Gray, UINT8>^>^ m = img->Split();
//	if (channel == nullptr)
//		{
//		area->Image = img;
//		}
//	else
//		{
//		array<Image<Gray, UINT8>^>^ m = img->Split();
//		area->Image = m[atoi(Core::convertToStdString(channel).c_str())];
//		}
//	img->~Image<Bgr, UINT8>();
//	delete img;
//	}
