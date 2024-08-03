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

    /// <summary>
    /// A class to generate QR codes.
    /// </summary>

    public ref class QRCodeGenerator {
    public:

        /// <summary>
    /// Generates a QR code from the provided text.
    /// </summary>
    /// <param name="text">The text to encode in the QR code.</param>
    /// <param name="imgsize">The size of each QR code module.</param>
    /// <returns>A bitmap image of the generated QR code.</returns>

        static System::Drawing::Bitmap^ generateQRCode(System::String^ text, int imgsize);
    };
}
#endif // QRCODEGENERATOR_H
