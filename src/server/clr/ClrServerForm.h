#pragma once

namespace ClrServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ClrServerForm の概要
	/// </summary>
	public ref class ClrServerForm : public System::Windows::Forms::Form
	{
	public:
		ClrServerForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~ClrServerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  MainMenuStrip;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  QuitToolStripMenuItem;

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ClrServerForm::typeid));
			this->MainMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->QuitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainMenuStrip
			// 
			this->MainMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			resources->ApplyResources(this->MainMenuStrip, L"MainMenuStrip");
			this->MainMenuStrip->Name = L"MainMenuStrip";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->QuitToolStripMenuItem });
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			resources->ApplyResources(this->FileToolStripMenuItem, L"FileToolStripMenuItem");
			// 
			// QuitToolStripMenuItem
			// 
			this->QuitToolStripMenuItem->Name = L"QuitToolStripMenuItem";
			resources->ApplyResources(this->QuitToolStripMenuItem, L"QuitToolStripMenuItem");
			this->QuitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ClrServerForm::QuitToolStripMenuItem_Click);
			// 
			// ClrServerForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->MainMenuStrip);
			this->MainMenuStrip = this->MainMenuStrip;
			this->Name = L"ClrServerForm";
			this->MainMenuStrip->ResumeLayout(false);
			this->MainMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void QuitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
	};
}
