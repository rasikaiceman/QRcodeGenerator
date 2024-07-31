#pragma once
#include "MainWindowsForm.h"

namespace SampleTestQR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace QRcodeGenerator;

	/// <summary>
	/// Summary for MainWindowsForm
	/// </summary>
	public ref class MainWindowsForm : public System::Windows::Forms::Form
	{
	public:
		MainWindowsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(0, 39);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(284, 243);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(0, 282);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(284, 36);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindowsForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(0, 7);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(284, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Enter Text Here !";
			this->textBox1->Enter += gcnew System::EventHandler(this, &MainWindowsForm::textBox1_Enter);
			// 
			// MainWindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 318);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainWindowsForm";
			this->Text = L"MainWindowsForm";
			this->Load += gcnew System::EventHandler(this, &MainWindowsForm::MainWindowsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Bitmap^ qrimg = gcnew Bitmap(50,50);
	private: System::Void MainWindowsForm_Load(System::Object^ sender, System::EventArgs^ e) {

		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		System::String^ text = textBox1->Text;
		int imgsize = 5; // Adjust size as needed

		// Use the QRCodeGenerator DLL
		Bitmap^ qrCodeBitmap = QRCodeGenerator::generateQRCode(text, imgsize);
		if (qrCodeBitmap != nullptr) {
			pictureBox1->Image = qrCodeBitmap;
		}
		else {
			MessageBox::Show("Failed to generate QR code.");
		}

	}
	private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Clear();
	}
};
}
