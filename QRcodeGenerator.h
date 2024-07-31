#pragma once
#ifndef QRCODEGENERATOR_H
#define QRCODEGENERATOR_H
#include "pch.h"
#include <string>
#include <windows.h>
#include <gdiplus.h>
#using <System.Drawing.dll>

namespace QRcodeGenerator {

    using namespace Gdiplus;
    using namespace System;
    using namespace System::Collections;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    public ref class QRCodeGenerator {
    public:
        static System::Drawing::Bitmap^ generateQRCode(System::String^ text, int imgsize);
    };
}
#endif // QRCODEGENERATOR_H
