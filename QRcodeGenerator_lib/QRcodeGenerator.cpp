#include "pch.h"
#include <iostream>
#include <windows.system.h>
#include "QRCodeGenerator.h"
#include <qrencode.h>
#include <gdiplus.h>
#using <System.Drawing.dll>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace QRcodeGenerator_lib {

    using namespace Gdiplus;
    using namespace msclr::interop;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;


#pragma comment (lib,"Gdiplus.lib")

    System::Drawing::Bitmap^ QRCodeGenerator::generateQRCode(System::String^ text, int imgsize) {
        // Initialize GDI+
        GdiplusStartupInput gdiplusStartupInput;
        ULONG_PTR gdiplusToken;
        GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

        // Convert managed System::String^ to std::string
        std::string nativeText = marshal_as<std::string>(text);

        // Generate QR code using libqrencode
        QRcode* qrcode = QRcode_encodeString(nativeText.c_str(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);
        if (!qrcode) {
            return nullptr;
        }

        int qrSize = qrcode->width;
        int imageSize = qrSize * imgsize;

        Gdiplus::Bitmap nativeBitmap(imageSize, imageSize, PixelFormat24bppRGB);

        // Fill the image with white
        Gdiplus::Graphics graphics(&nativeBitmap);
        Gdiplus::SolidBrush whiteBrush(Gdiplus::Color(255, 255, 255));
        graphics.FillRectangle(&whiteBrush, 0, 0, imageSize, imageSize);

        Gdiplus::SolidBrush blackBrush(Gdiplus::Color(0, 0, 0));
        for (int y = 0; y < qrSize; ++y) {
            for (int x = 0; x < qrSize; ++x) {
                if (qrcode->data[y * qrSize + x] & 1) {
                    graphics.FillRectangle(&blackBrush, x * imgsize, y * imgsize, imgsize, imgsize);
                }
            }
        }

        QRcode_free(qrcode);

        // Convert Gdiplus::Bitmap to System::Drawing::Bitmap
        BitmapData bitmapData;
        Rect rect(0, 0, nativeBitmap.GetWidth(), nativeBitmap.GetHeight());
        nativeBitmap.LockBits(&rect, ImageLockModeRead, nativeBitmap.GetPixelFormat(), &bitmapData);

        System::Drawing::Bitmap^ managedBitmap = gcnew System::Drawing::Bitmap(nativeBitmap.GetWidth(), nativeBitmap.GetHeight(), Imaging::PixelFormat::Format24bppRgb);
        Imaging::BitmapData^ managedBitmapData = managedBitmap->LockBits(System::Drawing::Rectangle(0, 0, managedBitmap->Width, managedBitmap->Height), Imaging::ImageLockMode::WriteOnly, managedBitmap->PixelFormat);

        std::memcpy(managedBitmapData->Scan0.ToPointer(), bitmapData.Scan0, bitmapData.Stride * bitmapData.Height);

        managedBitmap->UnlockBits(managedBitmapData);
        nativeBitmap.UnlockBits(&bitmapData);

        // Shut down GDI+
        GdiplusShutdown(gdiplusToken);

        return managedBitmap;
    }
}