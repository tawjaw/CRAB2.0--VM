#ifndef UI_CRAB_H
#define UI_CRAB_H
#include "VM\VirtualMachine.h"

#include <Wt/WAbstractTableModel>
#include <Wt/Utils>
#include <Wt/WFileResource>
#include <Wt/WContainerWidget>
#include <Wt/WNavigationBar>
#include <Wt/WMenu>
#include <Wt/WLayout>
#include <Wt/WStackedWidget>
#include <Wt/WMenuItem>
#include <Wt/WPushButton>
#include <Wt/WPanel>
#include <Wt/WTable>
#include <Wt/WText>
#include <Wt/WBootstrapTheme>
#include <Wt/WJavaScript>
#include <Wt/WMessageBox>
#include <Wt/WImage>
#include <Wt/WFileResource>
#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WPanel>
#include <Wt/WText>
#include <Wt/WVideo>
#include <Wt/WTable>
#include <Wt/WPushButton>
#include <Wt/WBootstrapTheme>
#include <Wt/WFlashObject>
#include <Wt/WGoogleMap>
#include <Wt/WHBoxLayout>
#include <Wt/WInPlaceEdit>
#include <Wt/WButtonGroup>
#include <Wt/WRadioButton>
#include <Wt/WTextArea>
#include <Wt/WLineEdit>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <Wt/WTableView>
#include <Wt/WStandardItemModel>
#include <Wt/WStandardItem>


using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

class Ui_CRAB
{
private:
	crab::VirtualMachine* vm;
	crab::ProgramGenerator pg;
public:

	int currentBreakpointRow;

	Wt::WContainerWidget *wt_root;
	Wt::WContainerWidget *container;
	Wt::WNavigationBar *navbar;
	Wt::WMenu *nv_menu;
	Wt::WContainerWidget * nv_menu_item1;
	Wt::WMenuItem * nv_menu_item1_mi;
	Wt::WContainerWidget * nv_menu_item2;
	Wt::WMenuItem * nv_menu_item2_mi;
	Wt::WContainerWidget * menuitem;
	Wt::WMenuItem * menuitem_mi;
	Wt::WContainerWidget * menuitem_cp;
	Wt::WMenuItem * menuitem_cp_mi;

	//NEW
	Wt::WNavigationBar *navigation;

	//editor left side
	Wt::WContainerWidget *container_editor;
	Wt::WContainerWidget *container_editor_buttons;
	Wt::WContainerWidget *editor;
	Wt::WPushButton *button_run;
	Wt::WPushButton *button_next;
	Wt::WPushButton *button_stop;

	//vm component right side
	Wt::WContainerWidget *container_vm;
	//memory table
	Wt::WPanel *panel_memory;
	Wt::WTable *table_memory;
	//registers 
	Wt::WPanel *panel_registers;
	//registers 1 and 2
	Wt::WContainerWidget *container_registers_group1;
	Wt::WContainerWidget *container_registers1;
	Wt::WContainerWidget *container_register1_label;
	Wt::WText *register1_label_text;
	Wt::WContainerWidget *container_register1_value;
	Wt::WText *register1_value_text;
	Wt::WContainerWidget *container_registers2;
	Wt::WContainerWidget *container_register1_label_cp;
	Wt::WText *register2_label_text_cp;
	Wt::WContainerWidget *container_register2_value;
	Wt::WText *register2_value_text;
	//registers 3 and 4
	Wt::WContainerWidget *container_registers_group2;
	Wt::WContainerWidget *container_registers3;
	Wt::WContainerWidget *container_register3_label;
	Wt::WText *register3_label_text;
	Wt::WContainerWidget *container_register3_value;
	Wt::WText *register3_value_text;
	Wt::WContainerWidget *container_registers4;
	Wt::WContainerWidget *container_register4_label;
	Wt::WText *register4_label_text;
	Wt::WContainerWidget *container_registe4_value;
	Wt::WText *register4_value_text;
	//array registers table
	Wt::WPanel *panel_arrayRegisters;
	Wt::WTable *table_arrayRegisters;
	//control flags
	Wt::WContainerWidget *container_control_flags;
	Wt::WPanel *panel_control_flags;
	Wt::WContainerWidget *container_flag_logical;
	Wt::WContainerWidget *container_flag_logical_inner;
	Wt::WContainerWidget *container_flag_if_container;
	Wt::WText *label_flag_if;
	Wt::WContainerWidget *container_flag_if_value;
	Wt::WText *flag_if_value;
	Wt::WContainerWidget *container_flag_while;
	Wt::WContainerWidget *container_flag_while_label;
	Wt::WText *label_flag_while;
	Wt::WContainerWidget *container_register1_value_cp_cp;
	Wt::WText *flag_while_value;
	Wt::WContainerWidget *container_flag_control;
	Wt::WContainerWidget *container_flag_logical_inner_cp_cp;
	Wt::WContainerWidget *container_register1_label_cp_cp_cp_cp;
	Wt::WText *label_flag_logical;
	Wt::WContainerWidget *container_logical_flag_value;
	Wt::WText *flag_logical_value;
	//control registers
	Wt::WContainerWidget *container_control_registers;
	Wt::WContainerWidget *container_other_components_cp;
	Wt::WPanel *panel_other_components_cp;
	Wt::WContainerWidget *container_flag_logical_cp;
	Wt::WContainerWidget *container_flag_logical_inner_cp;
	Wt::WContainerWidget *container_flag_if_container_cp;
	Wt::WText *control_register1_label;
	Wt::WContainerWidget *container_flag_if_value_cp_cp;
	Wt::WText *control_register1_value;
	Wt::WContainerWidget *container_flag_while_cp;
	Wt::WContainerWidget *container_flag_while_label_cp;
	Wt::WText *control_register2_label;
	Wt::WContainerWidget *container_register1_value_cp_cp_cp;
	Wt::WText *control_register2_value;
	Wt::WContainerWidget *container_flag_control_cp;
	Wt::WContainerWidget *container_flag_logical_inner_cp_cp_cp;
	Wt::WContainerWidget *container_register1_label_cp_cp_cp_cp_cp;
	Wt::WText *control_registe3_label;
	Wt::WContainerWidget *container_logical_flag_value_cp;
	Wt::WText *control_register3_value;
	Wt::WContainerWidget *container_control_registers_cp;

	//I/O buffers table
	Wt::WPanel *panel_IOBuffer;
	Wt::WTable *table_IOBuffer;


	//**EXTRA ELEMENT DESIGN PAGE**
	Wt::WContainerWidget *container_vmpage;
	Wt::WContainerWidget *container_tutorialpage;
	Wt::WContainerWidget *container_aboutus;
	Wt::WContainerWidget *container_input;
	Wt::WContainerWidget *container_emulator;
	Wt::WImage *top_banner_vm;
	Wt::WImage *top_banner_tutorial;
	Wt::WImage *top_banner_home;
	Wt::WImage *assembly;
	Wt::WImage *separator;
	Wt::WImage *intro;
	Wt::WImage *intro1;
	Wt::WImage *Participant;
	Wt::WImage *intro2;
	Wt::WPanel *panel1;
	Wt::WPanel *panel2;
	Wt::WPanel *panel3;
	Wt::WPanel *panel01;
	Wt::WPanel *panel02;
	//Wt::WPanel *panel_stack;
	Wt::WPanel *panel_input_buffer;
	//Wt::WTable *table_stack;
	Wt::WText *text1;
	Wt::WText *text2;
	Wt::WText *text3;
	Wt::WText *text4;
	Wt::WText *text5;
	Wt::WText *text6;
	Wt::WText *textEmulator;
	Wt::WTable *table;
	Wt::WPushButton *moreinfo;
	Wt::WPushButton *inputbuffer;
	Wt::WSlider *slider;
	Wt::WFlashObject *flash;
	Wt::WVideo *video;
	Wt::WGoogleMap *map;
	Wt::WHBoxLayout *layoutmap;
	Wt::WInPlaceEdit *textarea;
	Wt::WButtonGroup *group; //= new Wt::WButtonGroup(container);
	Wt::WRadioButton *buttonDouble;
	Wt::WRadioButton *buttonInt;
	Wt::WRadioButton *buttonChar;
	Wt::WTextArea *TextBox;
	Wt::WPushButton *button_emulate;
	Wt::WPushButton *accept_value;
	Wt::WPushButton *goeditor;
	Wt::WLineEdit *user_input;
	string value_passed;
	bool transfercode = false;
	bool valuevalidation = false;
	Wt::WContainerWidget *container_html;
	Wt::WAnchor *anchor;
	//FOR COMMA.
	char Filename[100];
	int TempNumOne;
	Wt::WTableView *tableView;
	Wt::WTableView *tableView1;
	Wt::WTableView *tableView2;

	int displayBuffers; //1 for float, 2 for int and 3 for char

	std::string cleanNumber(double f)
	{
		if (ceilf(f) == f)
			return std::to_string((int)f);
		else
		{

			std::stringstream ss;
			if (f > 10000)
			{

				ss << std::scientific << std::setprecision(5) << f;
				return ss.str();
			}
			else
			{
				ss << std::fixed << std::setprecision(2) << f;
				return ss.str();
			}
		}
	}


	void updateUi()
	{
		//memory table
		{
			table_memory->clear();


			std::array<double, MAX_ARRAY_SIZE> tempMemory = vm->getMemory();
			for (int i = 0; i < tempMemory.size(); i++)
			{
				if (vm->getMp() != i)
					table_memory->elementAt(0, i)->addWidget(new Wt::WText(cleanNumber(tempMemory[i])));
				else
					table_memory->elementAt(0, i)->addWidget(new Wt::WText("<span style=\"color: #ff0000; \"><strong>"
						+ cleanNumber(tempMemory[i]) + "</strong></span>"));
			}

			int rows = 0;
			int columns = 200;
			Wt::WStandardItemModel *model = new Wt::WStandardItemModel(rows, columns, tableView); tableView->setModel(model);
			for (int column = 0; column < columns; ++column)
			{
				Wt::WStandardItem *item = new Wt::WStandardItem();

				tableView->setColumnWidth(column, 35);

				if (vm->getMp() != column)
					item->setText(cleanNumber(tempMemory[column]));
				else
				{
					item->setText(cleanNumber(tempMemory[column]));

					item->setStyleClass("red");

				}
				model->setItem(0, column, item);
			}


		}
		//registers
		{
			register1_value_text->setText(cleanNumber(vm->getRegister0()));
			register2_value_text->setText(cleanNumber(vm->getRegister1()));
			register3_value_text->setText(cleanNumber(vm->getRegister2()));
			register4_value_text->setText(cleanNumber(vm->getRegister3()));
		}

		//array registers
		{
			table_arrayRegisters->clear();


			table_arrayRegisters->elementAt(0, 0)->addWidget(new Wt::WText(" "));
			table_arrayRegisters->elementAt(1, 0)->addWidget(new Wt::WText("A0"));
			table_arrayRegisters->elementAt(2, 0)->addWidget(new Wt::WText("A1"));
			table_arrayRegisters->elementAt(3, 0)->addWidget(new Wt::WText("A2"));
			table_arrayRegisters->elementAt(4, 0)->addWidget(new Wt::WText("A3"));

			int maxSize = 0;
			crab::ArrayData arrayRegister0 = vm->getArrayRegister0();
			maxSize = arrayRegister0.size;
			for (int i = 0; i < arrayRegister0.size; i++)
			{
				table_arrayRegisters->elementAt(1, i + 1)->addWidget(new Wt::WText(cleanNumber(arrayRegister0.arrayValue.at(i))));
			}


			crab::ArrayData arrayRegister1 = vm->getArrayRegister1();
			if (arrayRegister1.size > maxSize)	maxSize = arrayRegister1.size;
			for (int i = 0; i < arrayRegister1.size; i++)
			{
				table_arrayRegisters->elementAt(2, i + 1)->addWidget(new Wt::WText(cleanNumber(arrayRegister1.arrayValue.at(i))));
			}



			crab::ArrayData arrayRegister2 = vm->getArrayRegister2();
			if (arrayRegister2.size > maxSize)	maxSize = arrayRegister2.size;
			for (int i = 0; i < arrayRegister2.size; i++)
			{
				table_arrayRegisters->elementAt(3, i + 1)->addWidget(new Wt::WText(cleanNumber(arrayRegister2.arrayValue.at(i))));
			}



			crab::ArrayData arrayRegister3 = vm->getArrayRegister3();
			if (arrayRegister3.size > maxSize)	maxSize = arrayRegister3.size;
			for (int i = 0; i < arrayRegister3.size; i++)
			{
				table_arrayRegisters->elementAt(4, i + 1)->addWidget(new Wt::WText(cleanNumber(arrayRegister3.arrayValue.at(i))));
			}

			for (int i = 0; i < maxSize; i++)
				table_arrayRegisters->elementAt(0, i + 1)->addWidget(new Wt::WText(std::to_string(i)));


			//**********************************************************************************************************************
			int rows = 4;
			int columns = 200;
			Wt::WStandardItemModel *model = new Wt::WStandardItemModel(rows, columns, tableView1); tableView1->setModel(model);
			{
				//FOR ARRAY #0.
				int maxSize = 0;
				crab::ArrayData arrayRegister0 = vm->getArrayRegister0();
				maxSize = arrayRegister0.size;
				for (int i = 0; i < arrayRegister0.size; i++)
				{
					Wt::WStandardItem *item = new Wt::WStandardItem();
					item->setText(cleanNumber(arrayRegister0.arrayValue.at(i)));
					model->setItem(1, i + 1, item); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
				}
				//FOR ARRAT #1.
				crab::ArrayData arrayRegister1 = vm->getArrayRegister1();
				if (arrayRegister1.size > maxSize)	maxSize = arrayRegister1.size;
				for (int i = 0; i < arrayRegister1.size; i++)
				{
					Wt::WStandardItem *item1 = new Wt::WStandardItem();
					item1->setText(cleanNumber(arrayRegister1.arrayValue.at(i)));
					model->setItem(2, i + 1, item1); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
				}

				//FOR ARRAT #2.
				crab::ArrayData arrayRegister2 = vm->getArrayRegister2();
				if (arrayRegister2.size > maxSize)	maxSize = arrayRegister2.size;
				for (int i = 0; i < arrayRegister2.size; i++)
				{
					Wt::WStandardItem *item2 = new Wt::WStandardItem();
					item2->setText(cleanNumber(arrayRegister2.arrayValue.at(i)));
					model->setItem(3, i + 1, item2); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
				}

				//FOR ARRAT #3.
				crab::ArrayData arrayRegister3 = vm->getArrayRegister3();
				if (arrayRegister3.size > maxSize)	maxSize = arrayRegister3.size;
				for (int i = 0; i < arrayRegister3.size; i++)
				{
					Wt::WStandardItem *item3 = new Wt::WStandardItem();
					item3->setText(cleanNumber(arrayRegister3.arrayValue.at(i)));
					model->setItem(4, i + 1, item3); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
				}

				//FOR THE HEADER FILE, THE NUMBERS.
				for (int i = 0; i < 200; i++)
				{
					Wt::WStandardItem *item4 = new Wt::WStandardItem();
					item4->setText(to_wstring(i));
					model->setItem(0, i + 1, item4); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
				}

				//FOR THE ROW NAMES.
				Wt::WStandardItem *item5 = new Wt::WStandardItem();
				item5->setText("A0");
				model->setItem(1, 0, item5);
				Wt::WStandardItem *item6 = new Wt::WStandardItem();
				item6->setText("A1");
				model->setItem(2, 0, item6);
				Wt::WStandardItem *item7 = new Wt::WStandardItem();
				item7->setText("A2");
				model->setItem(3, 0, item7);
				Wt::WStandardItem *item8 = new Wt::WStandardItem();
				item8->setText("A3");
				model->setItem(4, 0, item8);


			}










		}

		//I/O buffers table
		{
			table_IOBuffer->clear();
			table_IOBuffer->elementAt(0, 0)->addWidget(new Wt::WText(" "));
			table_IOBuffer->elementAt(1, 0)->addWidget(new Wt::WText("I"));
			table_IOBuffer->elementAt(2, 0)->addWidget(new Wt::WText("O"));

			if (displayBuffers < 2)
			{
				int maxSize = 0;
				crab::ArrayData inputBuffer = vm->getInputBuffer();
				maxSize = inputBuffer.size;
				for (int i = 0; i < inputBuffer.size; i++)
				{
					table_IOBuffer->elementAt(1, i + 1)->addWidget(new Wt::WText(cleanNumber(inputBuffer.arrayValue.at(i))));
				}
				crab::ArrayData outputBuffer = vm->getOutputbuffer();
				if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
				for (int i = 0; i < outputBuffer.size; i++)
				{
					table_IOBuffer->elementAt(2, i + 1)->addWidget(new Wt::WText(cleanNumber(outputBuffer.arrayValue.at(i))));
				}
				for (int i = 0; i < maxSize; i++)
					table_IOBuffer->elementAt(0, i + 1)->addWidget(new Wt::WText(std::to_string(i)));
			}
			else if (displayBuffers == 2)
			{
				int maxSize = 0;
				crab::ArrayData inputBuffer = vm->getInputBuffer();
				maxSize = inputBuffer.size;
				for (int i = 0; i < inputBuffer.size; i++)
				{
					table_IOBuffer->elementAt(1, i + 1)->addWidget(new Wt::WText(cleanNumber((int)inputBuffer.arrayValue.at(i))));
				}
				crab::ArrayData outputBuffer = vm->getOutputbuffer();
				if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
				for (int i = 0; i < outputBuffer.size; i++)
				{
					table_IOBuffer->elementAt(2, i + 1)->addWidget(new Wt::WText(cleanNumber((int)outputBuffer.arrayValue.at(i))));
				}
				for (int i = 0; i < maxSize; i++)
					table_IOBuffer->elementAt(0, i + 1)->addWidget(new Wt::WText(std::to_string(i)));
			}
			else
			{
				int maxSize = 0;
				crab::ArrayData inputBuffer = vm->getInputBuffer();
				maxSize = inputBuffer.size;
				for (int i = 0; i < inputBuffer.size; i++)
				{
					std::stringstream ss;
					std::string s;
					char c = static_cast<char>(inputBuffer.arrayValue.at(i));
					ss << c;
					ss >> s;
					table_IOBuffer->elementAt(1, i + 1)->addWidget(new Wt::WText(s));
				}
				crab::ArrayData outputBuffer = vm->getOutputbuffer();
				if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
				for (int i = 0; i < outputBuffer.size; i++)
				{
					std::stringstream ss;
					std::string s;
					char c = static_cast<char>(outputBuffer.arrayValue.at(i));
					ss << c;
					ss >> s;
					table_IOBuffer->elementAt(2, i + 1)->addWidget(new Wt::WText(s));
				}
				for (int i = 0; i < maxSize; i++)
					table_IOBuffer->elementAt(0, i + 1)->addWidget(new Wt::WText(std::to_string(i)));
			}

			//**********************************************************************************************************************
			int rows = 2;
			int columns = 200;
			Wt::WStandardItemModel *model = new Wt::WStandardItemModel(rows, columns, tableView2); tableView2->setModel(model);
			{

				Wt::WStandardItem *item11 = new Wt::WStandardItem();
				item11->setText("I");
				model->setItem(1, 0, item11);

				Wt::WStandardItem *item12 = new Wt::WStandardItem();
				item12->setText("O");
				model->setItem(2, 0, item12);

				for (int i = 0; i < 200; i++)
				{
					Wt::WStandardItem *itemb4 = new Wt::WStandardItem();
					itemb4->setText(to_string(i));
					model->setItem(0, i + 1, itemb4); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
					tableView2->setColumnWidth(i, 35); //RIGHT SIZE.
				}

				if (displayBuffers < 2)
				{
					int maxSize = 0;
					crab::ArrayData inputBuffer = vm->getInputBuffer();
					maxSize = inputBuffer.size;
					for (int i = 0; i < inputBuffer.size; i++)
					{
						Wt::WStandardItem *itemb1 = new Wt::WStandardItem();
						itemb1->setText(cleanNumber(inputBuffer.arrayValue.at(i)));
						model->setItem(1, i + 1, itemb1); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					crab::ArrayData outputBuffer = vm->getOutputbuffer();
					if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
					for (int i = 0; i < outputBuffer.size; i++)
					{
						Wt::WStandardItem *itemb2 = new Wt::WStandardItem();
						itemb2->setText(cleanNumber(outputBuffer.arrayValue.at(i)));
						model->setItem(2, i + 1, itemb2); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					for (int i = 0; i < maxSize; i++)
					{
						Wt::WStandardItem *itemb4 = new Wt::WStandardItem();
						itemb4->setText(to_string(i));
						model->setItem(0, i + 1, itemb4); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}

				}
				else if (displayBuffers == 2)
				{
					int maxSize = 0;
					crab::ArrayData inputBuffer = vm->getInputBuffer();
					maxSize = inputBuffer.size;
					for (int i = 0; i < inputBuffer.size; i++)
					{
						Wt::WStandardItem *itemb3 = new Wt::WStandardItem();
						itemb3->setText(cleanNumber((int)inputBuffer.arrayValue.at(i)));
						model->setItem(1, i + 1, itemb3); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					crab::ArrayData outputBuffer = vm->getOutputbuffer();
					if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
					for (int i = 0; i < outputBuffer.size; i++)
					{
						Wt::WStandardItem *itemb5 = new Wt::WStandardItem();
						itemb5->setText(cleanNumber((int)outputBuffer.arrayValue.at(i)));
						model->setItem(2, i + 1, itemb5); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					for (int i = 0; i < maxSize; i++)
					{
						Wt::WStandardItem *itemb4 = new Wt::WStandardItem();
						itemb4->setText(to_string(i));
						model->setItem(0, i + 1, itemb4); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
				}
				else
				{
					int maxSize = 0;
					crab::ArrayData inputBuffer = vm->getInputBuffer();
					maxSize = inputBuffer.size;
					for (int i = 0; i < inputBuffer.size; i++)
					{
						std::stringstream ss;
						std::string s;
						char c = static_cast<char>(inputBuffer.arrayValue.at(i));
						ss << c;
						ss >> s;

						Wt::WStandardItem *itemb6 = new Wt::WStandardItem();
						itemb6->setText(s);
						model->setItem(1, i + 1, itemb6); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					crab::ArrayData outputBuffer = vm->getOutputbuffer();
					if (outputBuffer.size > maxSize)	maxSize = outputBuffer.size;
					for (int i = 0; i < outputBuffer.size; i++)
					{
						std::stringstream ss;
						std::string s;
						char c = static_cast<char>(outputBuffer.arrayValue.at(i));
						ss << c;
						ss >> s;


						Wt::WStandardItem *itemb7 = new Wt::WStandardItem();
						itemb7->setText(s);
						model->setItem(2, i + 1, itemb7); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
					for (int i = 0; i < maxSize; i++)
					{
						Wt::WStandardItem *itemb4 = new Wt::WStandardItem();
						itemb4->setText(to_string(i));
						model->setItem(0, i + 1, itemb4); //+1 SINCE THE FIRST SPOT IS FOR THE NAME OF THE ARRAY.
						tableView1->setColumnWidth(i, 35); //RIGHT SIZE.
					}
				}

			}

		}

		Wt::WString tempStringBool;
		if (vm->getFlagIf())	tempStringBool = "TRUE";
		else tempStringBool = "FALSE";

		flag_if_value->setText(tempStringBool);

		if (vm->getFlagWhile())	tempStringBool = "TRUE";
		else tempStringBool = "FALSE";

		flag_while_value->setText(tempStringBool);

		if (vm->getFlagLogical())	tempStringBool = "TRUE";
		else tempStringBool = "FALSE";

		flag_logical_value->setText(tempStringBool);

		if (vm->getFlagControl1())	control_register1_value->setText(std::to_string(vm->getControlRegister1()));
		else control_register1_value->setText("none");

		if (vm->getFlagControl2())	control_register2_value->setText(std::to_string(vm->getControlRegister2()));
		else control_register2_value->setText("none");

		if (vm->getFlagControl3())	control_register3_value->setText(std::to_string(vm->getControlRegister3()));
		else control_register3_value->setText("none");

		highlightLine();


	}

	//FUNCTION TO RUN/EXECUTE THE WRITTINGS.
	void runVM(std::string incoming)
	{
		ci_istringstream iss; iss.str(incoming.data());

		try {

			vm->loadProgram(iss);
		}
		catch (crab::InstructionException &e)
		{
			std::string errorMessage = e.getTokenError(); //+ "at line: " + e.getLineNumber();
			errorMessage += "at line: ";
			errorMessage += std::to_string(e.getLineNumber());
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", errorMessage, Wt::Information, Wt::Ok);
			messageBox->setModal(false);
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			messageBox->show();

		}

		try {
			vm->runVm();
		}
		catch (std::exception &e)
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", e.what(), Wt::Information, Wt::Ok);
			messageBox->setModal(false);
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			messageBox->show();
		}


		updateUi();


	}


	//FUNCTION EXECUTE THE NEXT ISNTRUCTION.
	void executeNextInstruction(std::string incoming)
	{

		if (!vm->isProgramLoaded())
		{
			ci_istringstream iss; iss.str(incoming.data());
			try {

				vm->loadProgram(iss);
			}
			catch (crab::InstructionException &e)
			{
				std::string errorMessage = e.getTokenError(); //+ "at line: " + e.getLineNumber();
				errorMessage += "at line: ";
				errorMessage += std::to_string(e.getLineNumber());
				Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", errorMessage, Wt::Information, Wt::Ok);
				messageBox->setModal(false);
				messageBox->buttonClicked().connect(std::bind([=]() {
					delete messageBox;
				}));
				messageBox->show();

			}
		}

		try {
			vm->executeNextInstruction();
		}
		catch (std::exception &e)
		{
			Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", e.what(), Wt::Information, Wt::Ok);
			messageBox->setModal(false);
			messageBox->buttonClicked().connect(std::bind([=]() {
				delete messageBox;
			}));
			messageBox->show();
		}


		updateUi();
	}

	//FUNCTION TO RESET THE EDITOR.
	void resetVM()
	{
		//setEditorValue(vm->printProgram(pg.generateRandomProgram(1, 10)));

		//editor->doJavaScript(command2);
		vm->initializeComponenets();
		removeHighlightLine();
		updateUi();
	}


	//DESIGN OF THE PAGE STARTS HERE.
	void setupUi(Wt::WContainerWidget *PageRoot)
	{

		displayBuffers = 1;
		vm = new crab::VirtualMachine();
		vm->initializeComponenets();

		Wt::WBootstrapTheme * p_wtTheme = new Wt::WBootstrapTheme();
		p_wtTheme->setVersion(Wt::WBootstrapTheme::Version3);
		Wt::WApplication::instance()->setTheme(p_wtTheme);
		Wt::WApplication::instance()->setTitle("CRAB VM");

		addAllStyleSheets();

		wt_root = (PageRoot);
		wt_root->setId("wt_root");
		wt_root->setStyleClass(Wt::WString::fromUTF8("container container-main centered"));
		wt_root->setInline(0);
		wt_root->setPositionScheme(Wt::PositionScheme::Relative);
		{

			//NAVIGATION BAR FOR THE UI.
			Wt::WNavigationBar *navigation = new Wt::WNavigationBar(wt_root);
			navigation->setTitle("<font color = \"red\"> CRAB</font><font   color = \"white\"> 2.0 </font>");
			navigation->setResponsive(true);
			navigation->setStyleClass(Wt::WString::fromUTF8("navbar navbar-default navbar-inverse navbar navbar-default"));

			//navigation->setWidth(1020);
			Wt::WStackedWidget *contentsStack = new Wt::WStackedWidget(wt_root);
			contentsStack->addStyleClass("contents");



			//CONTAINER TO BE USED FOR THE VM PAGE.
			container_vmpage = new Wt::WContainerWidget(wt_root);
			container_vmpage->setId("container_vmpage");
			container_vmpage->setStyleClass(Wt::WString::fromUTF8("col-xs-12 container-fluid row"));
			container_vmpage->setInline(0);
			container_vmpage->setHtmlTagName("div");
			{

				container_editor = new Wt::WContainerWidget(container_vmpage);
				container_editor->setId("container_editor");
				container_editor->setStyleClass(Wt::WString::fromUTF8("container-fluid col-xs-6 container-vm"));
				container_editor->setInline(1);
				container_editor->setHtmlTagName("div");
				{
					container_editor_buttons = new Wt::WContainerWidget(container_editor);
					container_editor_buttons->setId("container_editor_buttons");
					container_editor_buttons->setStyleClass(Wt::WString::fromUTF8(""));
					container_editor_buttons->setInline(0);
					container_editor_buttons->setHtmlTagName("div");
					{
						button_run = new Wt::WPushButton(container_editor_buttons);
						button_run->setId("button_run");
						button_run->setStyleClass(Wt::WString::fromUTF8("btn-default with-label btn  btn btn-default with-label"));
						button_run->setInline(1);
						button_run->setEmptyText(Wt::WString::fromUTF8(""));
						button_run->setText(Wt::WString::fromUTF8("Run"));
						button_run->setLink(Wt::WLink(""));
						button_next = new Wt::WPushButton(container_editor_buttons);
						button_next->setId("button_next");
						button_next->setStyleClass(Wt::WString::fromUTF8("btn-default with-label btn btn btn-default with-label"));
						button_next->setInline(1);
						button_next->setEmptyText(Wt::WString::fromUTF8(""));
						button_next->setText(Wt::WString::fromUTF8("Next"));
						button_next->setLink(Wt::WLink(""));
						button_stop = new Wt::WPushButton(container_editor_buttons);
						button_stop->setId("button_stop");
						button_stop->setStyleClass(Wt::WString::fromUTF8("btn-default with-label btn btn btn-default with-label"));
						button_stop->setInline(1);
						button_stop->setEmptyText(Wt::WString::fromUTF8(""));
						button_stop->setText(Wt::WString::fromUTF8("Reset"));
						button_stop->setLink(Wt::WLink(""));


					}


					//Wt::WApplication::instance()->require("ace-editor/ace.js");
					editor = new Wt::WContainerWidget(container_editor);
					editor->setStyleClass(Wt::WString::fromUTF8("container-fluid col-xs-12 container-vm"));
					std::string editor_ref = editor->jsRef(); // is a text string that will be the element when executed in JS
					std::string command =
						editor_ref + ".editor = ace.edit(" + editor_ref + ");" +
						editor_ref + ".editor.setTheme(\"ace/theme/monokai\");" +
						editor_ref + ".editor.getSession().setValue(\"assn r0 72\\nputm\\nmovp\\nassn r0 69\\nputm\\nmovp\\nassn r0 76\\nputm\\nmovp\\nassn r0 76\\nputm\\nmovp\\nassn r0 79\\nputm\\nmovp\\nassn r0 0\\nputm\\nmovp\\nassn r0 87\\nputm\\nmovp\\nassn r0 69\\nputm\\nmovp\\nassn r0 73\\nputm\\nmovp\\nassn r0 82\\nputm\\nmovp\\nassn r0 68\\nputm\\nmovp\\nassn r0 79\\nputm\\nmovp\\nsetp r1\\ngetm a0\\nputb a0\\n  \");" +
						editor_ref + ".editor.getSession().setMode(\"ace/mode/assembly_x86\");" +
						editor_ref + ".editor.setOption(\"showPrintMargin\", false);" +
						editor_ref + ".editor.setOption(\"fontSize\", \"16px\");";
					editor->doJavaScript(command);
					editor->setHeight(600);
					//editor->setWidth(450);




					// TODO
					Wt::JSignal <std::string> *jsignal = new Wt::JSignal<std::string>(editor, "textChanged");
					jsignal->connect(this, &Ui_CRAB::runVM);



					//WPushButton *b = new WPushButton("Save", root());

					command = "function(object, event) {" +
						jsignal->createCall(editor_ref + ".editor.getValue()") +
						";}";

					button_run->clicked().connect(command);



					Wt::JSignal <std::string> *jsignal2 = new Wt::JSignal<std::string>(editor, "textChanged2");
					jsignal2->connect(this, &Ui_CRAB::executeNextInstruction);
					command = "function(object, event) {" +
						jsignal2->createCall(editor_ref + ".editor.getValue()") +
						";}";

					button_next->clicked().connect(command);

					button_stop->clicked().connect(std::bind([=]() {
						resetVM();
					}));

					command = "var marker_id = 0;";

					editor->doJavaScript(command);
					editor->setInline(0);
					//var Range = ace.require('ace/range').Range;
					//editor.session.addMarker(new Range(from, 0, to, 1), "myMarker", "fullLine");



				}

				container_vm = new Wt::WContainerWidget(container_vmpage);
				container_vm->setId("container_vm");
				container_vm->setStyleClass(Wt::WString::fromUTF8("container-fluid row col-xs-6 container-vm"));
				container_vm->setInline(0);
				container_vm->setHtmlTagName("div");
				{
					Wt::WContainerWidget *cw_panel_memory = new Wt::WContainerWidget(container_vm);
					panel_memory = new Wt::WPanel(container_vm);
					panel_memory->setId("panel_memory");
					panel_memory->setStyleClass(Wt::WString::fromUTF8("panel panel  panel panel-default container-vm"));
					panel_memory->setInline(0);
					panel_memory->setTitle(Wt::WString::fromUTF8("Memory"));
					panel_memory->setCollapsible(1);
					panel_memory->setCentralWidget(cw_panel_memory);
					{
						table_memory = new Wt::WTable(cw_panel_memory);
						table_memory->setId("table");
						table_memory->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 table table-responsive table-bordered  table-striped table-hover container-vm"));
						table_memory->setInline(0);
						table_memory->setHeaderCount(3, Wt::Orientation::Horizontal);
						table_memory->setHeaderCount(1, Wt::Orientation::Vertical);
						table_memory->setHidden(1);

						tableView = new Wt::WTableView(cw_panel_memory);
						tableView->setSortingEnabled(false);
						tableView->setAlternatingRowColors(true);
						tableView->setRowHeight(20);
						tableView->setHeaderHeight(0);
						tableView->setSelectionMode(Wt::ExtendedSelection);
						tableView->setEditTriggers(Wt::WAbstractItemView::NoEditTrigger);
						//tableView->setHidden(1);
					}
					Wt::WContainerWidget *cw_panel_registers = new Wt::WContainerWidget(container_vm);
					panel_registers = new Wt::WPanel(container_vm);
					panel_registers->setId("panel_registers");
					panel_registers->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default container-vm"));
					panel_registers->setInline(0);
					panel_registers->setTitle(Wt::WString::fromUTF8("Registers"));
					panel_registers->setCollapsible(1);
					panel_registers->setCentralWidget(cw_panel_registers);
					{
						container_registers_group1 = new Wt::WContainerWidget(cw_panel_registers);
						container_registers_group1->setId("container_registers_group1");
						container_registers_group1->setStyleClass(Wt::WString::fromUTF8("container-fluid container-vm"));
						container_registers_group1->setInline(0);
						container_registers_group1->setHtmlTagName("div");
						{
							container_registers1 = new Wt::WContainerWidget(container_registers_group1);
							container_registers1->setId("container_registers1");
							container_registers1->setStyleClass(Wt::WString::fromUTF8("container-fluid  col-xs-6"));
							container_registers1->setInline(0);
							container_registers1->setHtmlTagName("div");
							{
								container_register1_label = new Wt::WContainerWidget(container_registers1);
								container_register1_label->setId("container_register1_label");
								container_register1_label->setStyleClass(Wt::WString::fromUTF8("container-fluid contaner-reg textreg col-xs-3 "));
								container_register1_label->setInline(0);
								container_register1_label->setHtmlTagName("div");
								{
									register1_label_text = new Wt::WText(container_register1_label);
									register1_label_text->setId("register1_label_text");
									register1_label_text->setStyleClass(Wt::WString::fromUTF8("textreg"));
									register1_label_text->setInline(0);
									register1_label_text->setTextFormat((Wt::TextFormat)0);
									register1_label_text->setText(Wt::WString::fromUTF8("R0"));
								}
								container_register1_value = new Wt::WContainerWidget(container_registers1);
								container_register1_value->setId("container_register1_value");
								container_register1_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9 container-fluid contaner-reg "));
								container_register1_value->setInline(0);
								container_register1_value->setHtmlTagName("div");
								{
									register1_value_text = new Wt::WText(container_register1_value);
									register1_value_text->setId("register1_value_text");
									register1_value_text->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
									register1_value_text->setInline(0);
									register1_value_text->setTextFormat((Wt::TextFormat)0);
									register1_value_text->setText(Wt::WString::fromUTF8("0.0"));
								}
							}
							container_registers2 = new Wt::WContainerWidget(container_registers_group1);
							container_registers2->setId("container_registers2");
							container_registers2->setStyleClass(Wt::WString::fromUTF8("container-fluid  col-xs-6"));
							container_registers2->setInline(0);
							container_registers2->setHtmlTagName("div");
							{
								container_register1_label_cp = new Wt::WContainerWidget(container_registers2);
								container_register1_label_cp->setId("container_register1_label_cp");
								container_register1_label_cp->setStyleClass(Wt::WString::fromUTF8("container-fluid contaner-reg textreg col-xs-3 "));
								container_register1_label_cp->setInline(0);
								container_register1_label_cp->setHtmlTagName("div");
								{
									register2_label_text_cp = new Wt::WText(container_register1_label_cp);
									register2_label_text_cp->setId("register2_label_text_cp");
									register2_label_text_cp->setStyleClass(Wt::WString::fromUTF8("textreg"));
									register2_label_text_cp->setInline(0);
									register2_label_text_cp->setTextFormat((Wt::TextFormat)0);
									register2_label_text_cp->setText(Wt::WString::fromUTF8("R1"));
								}
								container_register2_value = new Wt::WContainerWidget(container_registers2);
								container_register2_value->setId("container_register2_value");
								container_register2_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9 container-fluid contaner-reg "));
								container_register2_value->setInline(0);
								container_register2_value->setHtmlTagName("div");
								{
									register2_value_text = new Wt::WText(container_register2_value);
									register2_value_text->setId("register2_value_text");
									register2_value_text->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
									register2_value_text->setInline(0);
									register2_value_text->setTextFormat((Wt::TextFormat)0);
									register2_value_text->setText(Wt::WString::fromUTF8("0.0"));
								}
							}
						}
						container_registers_group2 = new Wt::WContainerWidget(cw_panel_registers);
						container_registers_group2->setId("container_registers_group2");
						container_registers_group2->setStyleClass(Wt::WString::fromUTF8("container-fluid"));
						container_registers_group2->setInline(0);
						container_registers_group2->setHtmlTagName("div");
						{
							container_registers3 = new Wt::WContainerWidget(container_registers_group2);
							container_registers3->setId("container_registers3");
							container_registers3->setStyleClass(Wt::WString::fromUTF8("container-fluid  col-xs-6"));
							container_registers3->setInline(0);
							container_registers3->setHtmlTagName("div");
							{
								container_register3_label = new Wt::WContainerWidget(container_registers3);
								container_register3_label->setId("container_register3_label");
								container_register3_label->setStyleClass(Wt::WString::fromUTF8("container-fluid contaner-reg textreg col-xs-3 "));
								container_register3_label->setInline(0);
								container_register3_label->setHtmlTagName("div");
								{
									register3_label_text = new Wt::WText(container_register3_label);
									register3_label_text->setId("register3_label_text");
									register3_label_text->setStyleClass(Wt::WString::fromUTF8("textreg"));
									register3_label_text->setInline(0);
									register3_label_text->setTextFormat((Wt::TextFormat)0);
									register3_label_text->setText(Wt::WString::fromUTF8("R2"));
								}
								container_register3_value = new Wt::WContainerWidget(container_registers3);
								container_register3_value->setId("container_register3_value");
								container_register3_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9 container-fluid contaner-reg "));
								container_register3_value->setInline(0);
								container_register3_value->setHtmlTagName("div");
								{
									register3_value_text = new Wt::WText(container_register3_value);
									register3_value_text->setId("register3_value_text");
									register3_value_text->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
									register3_value_text->setInline(0);
									register3_value_text->setTextFormat((Wt::TextFormat)0);
									register3_value_text->setText(Wt::WString::fromUTF8("0.0"));
								}
							}
							container_registers4 = new Wt::WContainerWidget(container_registers_group2);
							container_registers4->setId("container_registers4");
							container_registers4->setStyleClass(Wt::WString::fromUTF8("container-fluid  col-xs-6"));
							container_registers4->setInline(0);
							container_registers4->setHtmlTagName("div");
							{
								container_register4_label = new Wt::WContainerWidget(container_registers4);
								container_register4_label->setId("container_register4_label");
								container_register4_label->setStyleClass(Wt::WString::fromUTF8("container-fluid contaner-reg textreg col-xs-3 "));
								container_register4_label->setInline(0);
								container_register4_label->setHtmlTagName("div");
								{
									register4_label_text = new Wt::WText(container_register4_label);
									register4_label_text->setId("register4_label_text");
									register4_label_text->setStyleClass(Wt::WString::fromUTF8("textreg"));
									register4_label_text->setInline(0);
									register4_label_text->setTextFormat((Wt::TextFormat)0);
									register4_label_text->setText(Wt::WString::fromUTF8("R3"));
								}
								container_registe4_value = new Wt::WContainerWidget(container_registers4);
								container_registe4_value->setId("container_registe4_value");
								container_registe4_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9 container-fluid contaner-reg "));
								container_registe4_value->setInline(0);
								container_registe4_value->setHtmlTagName("div");
								{
									register4_value_text = new Wt::WText(container_registe4_value);
									register4_value_text->setId("register4_value_text");
									register4_value_text->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
									register4_value_text->setInline(0);
									register4_value_text->setTextFormat((Wt::TextFormat)0);
									register4_value_text->setText(Wt::WString::fromUTF8("0.0"));
								}
							}
						}
					}
					Wt::WContainerWidget *cw_panel_arrayRegisters = new Wt::WContainerWidget(container_vm);
					panel_arrayRegisters = new Wt::WPanel(container_vm);
					panel_arrayRegisters->setId("panel_arrayRegisters");
					panel_arrayRegisters->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default container-vm"));
					panel_arrayRegisters->setInline(0);
					panel_arrayRegisters->setTitle(Wt::WString::fromUTF8("Array Registers"));
					panel_arrayRegisters->setCollapsible(1);
					panel_arrayRegisters->setCentralWidget(cw_panel_arrayRegisters);
					{
						table_arrayRegisters = new Wt::WTable(cw_panel_arrayRegisters);
						table_arrayRegisters->setId("table_cp");

						table_arrayRegisters->setStyleClass("table-bordered table table-striped table-hover ");
						//	table_arrayRegisters->setHtmlTagName("div");
						table_arrayRegisters->setInline(0);
						table_arrayRegisters->setHeaderCount(1, Wt::Orientation::Horizontal);
						table_arrayRegisters->setHeaderCount(1, Wt::Orientation::Vertical);
						table_arrayRegisters->setHidden(1);


						tableView1 = new Wt::WTableView(cw_panel_arrayRegisters);
						tableView1->setSortingEnabled(false);
						tableView1->setAlternatingRowColors(true);
						tableView1->setRowHeight(20);
						tableView1->setHeaderHeight(0);
						tableView1->setSelectionMode(Wt::ExtendedSelection);
						tableView1->setEditTriggers(Wt::WAbstractItemView::NoEditTrigger);
						tableView1->setRowHeaderCount(1);
					}
					container_control_flags = new Wt::WContainerWidget(container_vm);
					container_control_flags->setId("container_other_components");
					container_control_flags->setStyleClass(Wt::WString::fromUTF8(""));
					container_control_flags->setInline(0);
					container_control_flags->setHtmlTagName("div");
					{
						Wt::WContainerWidget *cw_panel_other_components = new Wt::WContainerWidget(container_control_flags);
						panel_control_flags = new Wt::WPanel(container_control_flags);
						panel_control_flags->setId("panel_other_components");
						panel_control_flags->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
						panel_control_flags->setInline(0);
						panel_control_flags->setTitle(Wt::WString::fromUTF8("Control Flow Flags"));
						panel_control_flags->setCollapsible(1);
						panel_control_flags->setCentralWidget(cw_panel_other_components);
						{
							container_flag_logical = new Wt::WContainerWidget(cw_panel_other_components);
							container_flag_logical->setId("container_flag_logical");
							container_flag_logical->setStyleClass(Wt::WString::fromUTF8(""));
							container_flag_logical->setInline(0);
							container_flag_logical->setHtmlTagName("div");
							{
								container_flag_logical_inner = new Wt::WContainerWidget(container_flag_logical);
								container_flag_logical_inner->setId("container_flag_logical_inner");
								container_flag_logical_inner->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_logical_inner->setInline(0);
								container_flag_logical_inner->setHtmlTagName("div");
								{
									container_flag_if_container = new Wt::WContainerWidget(container_flag_logical_inner);
									container_flag_if_container->setId("container_flag_if_container");
									container_flag_if_container->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_flag_if_container->setInline(0);
									container_flag_if_container->setHtmlTagName("div");
									{
										label_flag_if = new Wt::WText(container_flag_if_container);
										label_flag_if->setId("label_flag_if");
										label_flag_if->setStyleClass(Wt::WString::fromUTF8("textreg"));
										label_flag_if->setInline(0);
										label_flag_if->setTextFormat((Wt::TextFormat)0);
										label_flag_if->setText(Wt::WString::fromUTF8("ifel"));
									}
									container_flag_if_value = new Wt::WContainerWidget(container_flag_logical_inner);
									container_flag_if_value->setId("container_flag_if_value_cp");
									container_flag_if_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_flag_if_value->setInline(0);
									container_flag_if_value->setHtmlTagName("div");
									{
										flag_if_value = new Wt::WText(container_flag_if_value);
										flag_if_value->setId("flag_if_value");
										flag_if_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										flag_if_value->setInline(0);
										flag_if_value->setTextFormat((Wt::TextFormat)0);
										flag_if_value->setText(Wt::WString::fromUTF8("false"));
									}
								}
								container_flag_while = new Wt::WContainerWidget(container_flag_logical);
								container_flag_while->setId("container_flag_while");
								container_flag_while->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_while->setInline(0);
								container_flag_while->setHtmlTagName("div");
								{
									container_flag_while_label = new Wt::WContainerWidget(container_flag_while);
									container_flag_while_label->setId("container_flag_while_label");
									container_flag_while_label->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_flag_while_label->setInline(0);
									container_flag_while_label->setHtmlTagName("div");
									{
										label_flag_while = new Wt::WText(container_flag_while_label);
										label_flag_while->setId("label_flag_while");
										label_flag_while->setStyleClass(Wt::WString::fromUTF8("textreg"));
										label_flag_while->setInline(0);
										label_flag_while->setTextFormat((Wt::TextFormat)0);
										label_flag_while->setText(Wt::WString::fromUTF8("whil"));
									}
									container_register1_value_cp_cp = new Wt::WContainerWidget(container_flag_while);
									container_register1_value_cp_cp->setId("container_register1_value_cp_cp");
									container_register1_value_cp_cp->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_register1_value_cp_cp->setInline(0);
									container_register1_value_cp_cp->setHtmlTagName("div");
									{
										flag_while_value = new Wt::WText(container_register1_value_cp_cp);
										flag_while_value->setId("flag_logical_value_cp");
										flag_while_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										flag_while_value->setInline(0);
										flag_while_value->setTextFormat((Wt::TextFormat)0);
										flag_while_value->setText(Wt::WString::fromUTF8("false"));
									}
								}
							}
							container_flag_control = new Wt::WContainerWidget(cw_panel_other_components);
							container_flag_control->setId("container_flag_control");
							container_flag_control->setStyleClass(Wt::WString::fromUTF8(""));
							container_flag_control->setInline(0);
							container_flag_control->setHtmlTagName("div");
							{
								container_flag_logical_inner_cp_cp = new Wt::WContainerWidget(container_flag_control);
								container_flag_logical_inner_cp_cp->setId("container_flag_logical_inner_cp_cp");
								container_flag_logical_inner_cp_cp->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_logical_inner_cp_cp->setInline(0);
								container_flag_logical_inner_cp_cp->setHtmlTagName("div");
								{
									container_register1_label_cp_cp_cp_cp = new Wt::WContainerWidget(container_flag_logical_inner_cp_cp);
									container_register1_label_cp_cp_cp_cp->setId("container_register1_label_cp_cp_cp_cp");
									container_register1_label_cp_cp_cp_cp->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_register1_label_cp_cp_cp_cp->setInline(0);
									container_register1_label_cp_cp_cp_cp->setHtmlTagName("div");
									{
										label_flag_logical = new Wt::WText(container_register1_label_cp_cp_cp_cp);
										label_flag_logical->setId("label_flag_logical");
										label_flag_logical->setStyleClass(Wt::WString::fromUTF8("textreg"));
										label_flag_logical->setInline(0);
										label_flag_logical->setTextFormat((Wt::TextFormat)0);
										label_flag_logical->setText(Wt::WString::fromUTF8("L"));
									}
									container_logical_flag_value = new Wt::WContainerWidget(container_flag_logical_inner_cp_cp);
									container_logical_flag_value->setId("container_logical_flag_value");
									container_logical_flag_value->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_logical_flag_value->setInline(0);
									container_logical_flag_value->setHtmlTagName("div");
									{
										flag_logical_value = new Wt::WText(container_logical_flag_value);
										flag_logical_value->setId("flag_logical_value");
										flag_logical_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										flag_logical_value->setInline(0);
										flag_logical_value->setTextFormat((Wt::TextFormat)0);
										flag_logical_value->setText(Wt::WString::fromUTF8("false"));
									}
								}
							}
							container_control_registers = new Wt::WContainerWidget(cw_panel_other_components);
							container_control_registers->setId("container_control_registers");
							container_control_registers->setStyleClass(Wt::WString::fromUTF8(""));
							container_control_registers->setInline(0);
							container_control_registers->setHtmlTagName("div");
						}
					}
					container_other_components_cp = new Wt::WContainerWidget(container_vm);
					container_other_components_cp->setId("container_other_components_cp");
					container_other_components_cp->setStyleClass(Wt::WString::fromUTF8(""));
					container_other_components_cp->setInline(0);
					container_other_components_cp->setHtmlTagName("div");
					{
						Wt::WContainerWidget *cw_panel_other_components_cp = new Wt::WContainerWidget(container_other_components_cp);
						panel_other_components_cp = new Wt::WPanel(container_other_components_cp);
						panel_other_components_cp->setId("panel_other_components_cp");
						panel_other_components_cp->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
						panel_other_components_cp->setInline(0);
						panel_other_components_cp->setTitle(Wt::WString::fromUTF8("Control Registers"));
						panel_other_components_cp->setCollapsible(1);
						panel_other_components_cp->setCentralWidget(cw_panel_other_components_cp);
						{
							container_flag_logical_cp = new Wt::WContainerWidget(cw_panel_other_components_cp);
							container_flag_logical_cp->setId("container_flag_logical_cp");
							container_flag_logical_cp->setStyleClass(Wt::WString::fromUTF8(""));
							container_flag_logical_cp->setInline(0);
							container_flag_logical_cp->setHtmlTagName("div");
							{
								container_flag_logical_inner_cp = new Wt::WContainerWidget(container_flag_logical_cp);
								container_flag_logical_inner_cp->setId("container_flag_logical_inner_cp");
								container_flag_logical_inner_cp->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_logical_inner_cp->setInline(0);
								container_flag_logical_inner_cp->setHtmlTagName("div");
								{
									container_flag_if_container_cp = new Wt::WContainerWidget(container_flag_logical_inner_cp);
									container_flag_if_container_cp->setId("container_flag_if_container_cp");
									container_flag_if_container_cp->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_flag_if_container_cp->setInline(0);
									container_flag_if_container_cp->setHtmlTagName("div");
									{
										control_register1_label = new Wt::WText(container_flag_if_container_cp);
										control_register1_label->setId("control_register1_label");
										control_register1_label->setStyleClass(Wt::WString::fromUTF8("textreg"));
										control_register1_label->setInline(0);
										control_register1_label->setTextFormat((Wt::TextFormat)0);
										control_register1_label->setText(Wt::WString::fromUTF8("RC1"));
									}
									container_flag_if_value_cp_cp = new Wt::WContainerWidget(container_flag_logical_inner_cp);
									container_flag_if_value_cp_cp->setId("container_flag_if_value_cp_cp");
									container_flag_if_value_cp_cp->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_flag_if_value_cp_cp->setInline(0);
									container_flag_if_value_cp_cp->setHtmlTagName("div");
									{
										control_register1_value = new Wt::WText(container_flag_if_value_cp_cp);
										control_register1_value->setId("control_register1_value");
										control_register1_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										control_register1_value->setInline(0);
										control_register1_value->setTextFormat((Wt::TextFormat)0);
										control_register1_value->setText(Wt::WString::fromUTF8("none"));
									}
								}
								container_flag_while_cp = new Wt::WContainerWidget(container_flag_logical_cp);
								container_flag_while_cp->setId("container_flag_while_cp");
								container_flag_while_cp->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_while_cp->setInline(0);
								container_flag_while_cp->setHtmlTagName("div");
								{
									container_flag_while_label_cp = new Wt::WContainerWidget(container_flag_while_cp);
									container_flag_while_label_cp->setId("container_flag_while_label_cp");
									container_flag_while_label_cp->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_flag_while_label_cp->setInline(0);
									container_flag_while_label_cp->setHtmlTagName("div");
									{
										control_register2_label = new Wt::WText(container_flag_while_label_cp);
										control_register2_label->setId("control_register2_label");
										control_register2_label->setStyleClass(Wt::WString::fromUTF8("textreg"));
										control_register2_label->setInline(0);
										control_register2_label->setTextFormat((Wt::TextFormat)0);
										control_register2_label->setText(Wt::WString::fromUTF8("RC2"));
									}
									container_register1_value_cp_cp_cp = new Wt::WContainerWidget(container_flag_while_cp);
									container_register1_value_cp_cp_cp->setId("container_register1_value_cp_cp_cp");
									container_register1_value_cp_cp_cp->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_register1_value_cp_cp_cp->setInline(0);
									container_register1_value_cp_cp_cp->setHtmlTagName("div");
									{
										control_register2_value = new Wt::WText(container_register1_value_cp_cp_cp);
										control_register2_value->setId("control_register2_value");
										control_register2_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										control_register2_value->setInline(0);
										control_register2_value->setTextFormat((Wt::TextFormat)0);
										control_register2_value->setText(Wt::WString::fromUTF8("none"));
									}
								}
							}
							container_flag_control_cp = new Wt::WContainerWidget(cw_panel_other_components_cp);
							container_flag_control_cp->setId("container_flag_control_cp");
							container_flag_control_cp->setStyleClass(Wt::WString::fromUTF8(""));
							container_flag_control_cp->setInline(0);
							container_flag_control_cp->setHtmlTagName("div");
							{
								container_flag_logical_inner_cp_cp_cp = new Wt::WContainerWidget(container_flag_control_cp);
								container_flag_logical_inner_cp_cp_cp->setId("container_flag_logical_inner_cp_cp_cp");
								container_flag_logical_inner_cp_cp_cp->setStyleClass(Wt::WString::fromUTF8(" col-xs-6 container-fluid"));
								container_flag_logical_inner_cp_cp_cp->setInline(0);
								container_flag_logical_inner_cp_cp_cp->setHtmlTagName("div");
								{
									container_register1_label_cp_cp_cp_cp_cp = new Wt::WContainerWidget(container_flag_logical_inner_cp_cp_cp);
									container_register1_label_cp_cp_cp_cp_cp->setId("container_register1_label_cp_cp_cp_cp_cp");
									container_register1_label_cp_cp_cp_cp_cp->setStyleClass(Wt::WString::fromUTF8("textreg col-xs-3  contaner-reg container-fluid"));
									container_register1_label_cp_cp_cp_cp_cp->setInline(0);
									container_register1_label_cp_cp_cp_cp_cp->setHtmlTagName("div");
									{
										control_registe3_label = new Wt::WText(container_register1_label_cp_cp_cp_cp_cp);
										control_registe3_label->setId("control_registe3_label");
										control_registe3_label->setStyleClass(Wt::WString::fromUTF8("textreg"));
										control_registe3_label->setInline(0);
										control_registe3_label->setTextFormat((Wt::TextFormat)0);
										control_registe3_label->setText(Wt::WString::fromUTF8("RC3"));
									}
									container_logical_flag_value_cp = new Wt::WContainerWidget(container_flag_logical_inner_cp_cp_cp);
									container_logical_flag_value_cp->setId("container_logical_flag_value_cp");
									container_logical_flag_value_cp->setStyleClass(Wt::WString::fromUTF8("col-xs-9  contaner-reg container-fluid"));
									container_logical_flag_value_cp->setInline(0);
									container_logical_flag_value_cp->setHtmlTagName("div");
									{
										control_register3_value = new Wt::WText(container_logical_flag_value_cp);
										control_register3_value->setId("control_register3_value");
										control_register3_value->setStyleClass(Wt::WString::fromUTF8("textreg-value"));
										control_register3_value->setInline(0);
										control_register3_value->setTextFormat((Wt::TextFormat)0);
										control_register3_value->setText(Wt::WString::fromUTF8("none"));
									}
								}
							}
							container_control_registers_cp = new Wt::WContainerWidget(cw_panel_other_components_cp);
							container_control_registers_cp->setId("container_control_registers_cp");
							container_control_registers_cp->setStyleClass(Wt::WString::fromUTF8(""));
							container_control_registers_cp->setInline(0);
							container_control_registers_cp->setHtmlTagName("div");
						}
						Wt::WContainerWidget *cw_panel_IOBuffer = new Wt::WContainerWidget(container_vm);
						panel_IOBuffer = new Wt::WPanel(container_vm);
						panel_IOBuffer->setId("panel_IOBuffer");
						panel_IOBuffer->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default container-vm"));
						panel_IOBuffer->setInline(0);
						panel_IOBuffer->setTitle(Wt::WString::fromUTF8("I/O Buffers"));
						panel_IOBuffer->setCollapsible(1);
						panel_IOBuffer->setCentralWidget(cw_panel_IOBuffer);
						{
							table_IOBuffer = new Wt::WTable(cw_panel_IOBuffer);
							table_IOBuffer->setId("table_IOBuffer");

							table_IOBuffer->setStyleClass("table-bordered table table-striped table-hover ");
							//	table_arrayRegisters->setHtmlTagName("div");
							table_IOBuffer->setInline(0);
							table_IOBuffer->setHeaderCount(1, Wt::Orientation::Horizontal);
							table_IOBuffer->setHeaderCount(1, Wt::Orientation::Vertical);
							table_IOBuffer->setHidden(1);

							tableView2 = new Wt::WTableView(cw_panel_IOBuffer);
							tableView2->setSortingEnabled(false);
							tableView2->setAlternatingRowColors(true);
							tableView2->setRowHeight(20);
							tableView2->setHeaderHeight(0);
							tableView2->setSelectionMode(Wt::ExtendedSelection);
							tableView2->setEditTriggers(Wt::WAbstractItemView::NoEditTrigger);
							tableView2->setRowHeaderCount(1);




						}

						group = new Wt::WButtonGroup(cw_panel_IOBuffer);
						buttonDouble = new Wt::WRadioButton("Double", cw_panel_IOBuffer);
						group->addButton(buttonDouble, 1);

						buttonInt = new Wt::WRadioButton("Int", cw_panel_IOBuffer);
						group->addButton(buttonInt, 2);

						buttonChar = new Wt::WRadioButton("Char", cw_panel_IOBuffer);
						group->addButton(buttonChar, 3);

						group->setSelectedButtonIndex(0); // Select the first button by default.


						group->checkedChanged().connect(std::bind([=](Wt::WRadioButton *selection) {

							switch (group->id(selection)) {
							case 1: displayBuffers = 1;
								break;

							case 2: displayBuffers = 2;
								break;

							case 3: displayBuffers = 3;
								break;
							}
							updateUi();
						}, std::placeholders::_1));


						/*Wt::WContainerWidget *cw_panel_stack = new Wt::WContainerWidget(container_vm);
						panel_stack = new Wt::WPanel(container_vm);
						panel_stack->setId("panel_stack");
						panel_stack->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default container-vm"));
						panel_stack->setInline(0);
						panel_stack->setTitle(Wt::WString::fromUTF8("Stacks"));
						panel_stack->setCollapsible(1);
						panel_stack->setCentralWidget(cw_panel_stack);
						{
							table_stack = new Wt::WTable(cw_panel_stack);
							table_stack->setId("table_stack");
							table_stack->setStyleClass("table-bordered table table-striped table-hover ");
							table_stack->setInline(0);
							table_stack->setHeaderCount(1, Wt::Orientation::Horizontal);
							table_stack->setHeaderCount(1, Wt::Orientation::Vertical);
							table_stack->elementAt(0, 0)->addWidget(new Wt::WText("SO"));
							table_stack->elementAt(1, 0)->addWidget(new Wt::WText(" "));
							table_stack->elementAt(1, 0)->addWidget(new Wt::WText("S1"));
							table_stack->elementAt(1, 1)->addWidget(new Wt::WText(" "));
						}
						*/
						Wt::WContainerWidget *cw_panel_input_buffer = new Wt::WContainerWidget(container_vm);
						panel_input_buffer = new Wt::WPanel(container_vm);
						panel_input_buffer->setId("panel_input_buffer");
						panel_input_buffer->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default container-vm"));
						panel_input_buffer->setInline(0);
						panel_input_buffer->setTitle(Wt::WString::fromUTF8("Input Buffer"));
						panel_input_buffer->setCollapsible(1);
						panel_input_buffer->setCentralWidget(cw_panel_input_buffer);
						{
							//BUTTON TO INPUT THE INPUT BUFFER VALUE.
							inputbuffer = new Wt::WPushButton(cw_panel_input_buffer);
							inputbuffer->setId("inputbuffer");
							inputbuffer->setStyleClass(Wt::WString::fromUTF8("btn-default with-label btn btn-default with-label"));
							inputbuffer->setInline(1);
							inputbuffer->setEmptyText(Wt::WString::fromUTF8(""));
							inputbuffer->setText(Wt::WString::fromUTF8("Input"));
							inputbuffer->setLink(Wt::WLink(""));
							
							// textarea->text();

							//TEXT TO HOLD THE INPUT NUMBER.
							Wt::WInPlaceEdit *textarea = new Wt::WInPlaceEdit("Input Buffer Value", cw_panel_input_buffer);
							textarea->setPlaceholderText("Enter input buffer value.");
							textarea->setInline(1);
							textarea->setButtonsEnabled(false);

							inputbuffer->clicked().connect(std::bind([=]() {
								crab::ArrayData tempInput;
								ci_string line = textarea->text().toUTF8().c_str();

								ci_istringstream strstr(line); 
								ci_string number;
								int i = 0;
								try {
									while (std::getline(strstr, number, ','))
									{
										double inputNumber;
										inputNumber = std::stod(number.c_str());
										tempInput.arrayValue[i] = inputNumber;

										i++;
									}
									tempInput.size = i;
									vm->loadInputBuffer(tempInput);
									updateUi();
								}
								catch (std::exception& e)
								{
									std::string errorMessage = e.what();
									errorMessage+="\nPlease enter integers or real numbers separated by a comma"; //+ "at line: " + e.getLineNumber();
									
									Wt::WMessageBox *messageBox = new Wt::WMessageBox("Error", errorMessage, Wt::Information, Wt::Ok);
									messageBox->setModal(false);
									messageBox->buttonClicked().connect(std::bind([=]() {
										delete messageBox;
									}));
									messageBox->show();

								}
								//textarea->setText("pressed");
							}));
						}




					}










				}
			}

			//CONTAINER TO BE USED FOR THE TUTORIAL PAGE.
			container_tutorialpage = new Wt::WContainerWidget(wt_root);
			container_tutorialpage->setId("container_tutorialpage");
			container_tutorialpage->setStyleClass(Wt::WString::fromUTF8("col-xs-12 container-fluid centered"));
			container_tutorialpage->setInline(0);
			container_tutorialpage->setHtmlTagName("div");
			{

				//STARTING THE PANEL CONFIG FROM HERE.
				//PANEL#1 : UNDERSTANDING.
				Wt::WContainerWidget *cw_panel1 = new Wt::WContainerWidget(container_tutorialpage);
				panel1 = new Wt::WPanel(container_tutorialpage);
				panel1->setId("panel1");
				panel1->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
				panel1->setInline(0);
				panel1->setTitle(Wt::WString::fromUTF8("Functionality and understanding."));
				panel1->setCollapsible(1);
				panel1->setCentralWidget(cw_panel1);
				panel1->setCollapsible(false);
				{
					//EXPLANANTION FOR THE VM AND THE CRAB 2.0 LANGUAGE.
					text1 = new Wt::WText(cw_panel1);
					text1->setId("text1");
					text1->setStyleClass(Wt::WString::fromUTF8(""));
					text1->setInline(0);
					text1->setTextFormat((Wt::TextFormat)2);
					text1->setText(Wt::WString::fromUTF8("The virtual machine (VM) is composed of three main parts: the memory, the CPU and the input/output buffers. The CPU, the central processing unit, holds four arrays, four registers and two stacks. The memory is a sequence of 4-byte-wide memory words that extends to and infinite value. Finally, the input/output buffer is a limited-length stream.\n\n\
The process of instructions starts at the CPU advancing the instruction pointer to the first instruction line. It extracts the instructions commands and translates it. It then executes the instruction to move the instruction pointer to the next instruction line."));


				}

				//PANEL#2 : COMMANDS AND RESSOURCES.
				Wt::WContainerWidget *cw_panel2 = new Wt::WContainerWidget(container_tutorialpage);
				panel2 = new Wt::WPanel(container_tutorialpage);
				panel2->setId("panel2");
				panel2->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
				panel2->setInline(0);
				panel2->setTitle(Wt::WString::fromUTF8("Commands and operations."));
				panel2->setCollapsible(1);
				panel2->setCentralWidget(cw_panel2);
				panel2->setCollapsible(false); //INITIALY CLOSED.
				{
					text2 = new Wt::WText(cw_panel2);
					text2->setId("text2");
					text2->setStyleClass(Wt::WString::fromUTF8(""));
					text2->setInline(0);
					text2->setTextFormat((Wt::TextFormat)2);
					text2->setText(Wt::WString::fromUTF8("Crab 2.0 follows a similar syntax as the known assembly language. It is comprised of an operator and an operand selection. It is possible to have one, multiple or no operands. The operands are composed of an array address, a register address or a scalar. The following instruction form must be followed to obtain a proper instruction line for the CPU.\n\n\
<Operator> [Operand #1], [ Operand #2], …, [#N]\n\n\
The following table displays all the possible comands by type:\n\
"));

					//TABLE HERE.
					table = new Wt::WTable(cw_panel2);
					table->setId("table");
					table->setStyleClass(Wt::WString::fromUTF8("table-striped table table-hover table-bordered"));
					table->setInline(0);
					table->setHeaderCount(1, Wt::Orientation::Horizontal);
					table->setHeaderCount(1, Wt::Orientation::Vertical);
					table->resize(900, 500);

					table->elementAt(0, 0)->addWidget(new Wt::WText("Type"));
					table->elementAt(0, 1)->addWidget(new Wt::WText("Command"));
					table->elementAt(0, 2)->addWidget(new Wt::WText("Possible Combinations"));
					table->elementAt(0, 3)->addWidget(new Wt::WText("Operation Explained"));

					table->elementAt(1, 0)->addWidget(new Wt::WText("Transfer Operations:"));

					table->elementAt(1, 1)->addWidget(new Wt::WText("getb"));
					table->elementAt(1, 3)->addWidget(new Wt::WText("r0=i[0];  "));
					table->elementAt(2, 2)->addWidget(new Wt::WText(Wt::WString("~ rX  ")));
					table->elementAt(2, 3)->addWidget(new Wt::WText("rX=i[0];"));
					table->elementAt(3, 2)->addWidget(new Wt::WText(Wt::WString("~ aX	")));
					table->elementAt(3, 3)->addWidget(new Wt::WText("aX[0..]=i[0..]; "));
					table->elementAt(4, 2)->addWidget(new Wt::WText(Wt::WString("~ rX,	rY	")));
					table->elementAt(4, 3)->addWidget(new Wt::WText("rX=i[rY];"));
					table->elementAt(5, 2)->addWidget(new Wt::WText(Wt::WString("~ aX,	rY	 ")));
					table->elementAt(5, 3)->addWidget(new Wt::WText("aX[0..]=i[rY..]; "));
					table->elementAt(6, 2)->addWidget(new Wt::WText(Wt::WString("~ ?X,	aY	")));
					table->elementAt(6, 3)->addWidget(new Wt::WText("degenerates to getb ?X, rY; ?=anything"));

					table->elementAt(7, 1)->addWidget(new Wt::WText("putb"));
					table->elementAt(7, 3)->addWidget(new Wt::WText("o[0]=r0;"));
					table->elementAt(8, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(8, 3)->addWidget(new Wt::WText("o[0]=rX;"));
					table->elementAt(9, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(9, 3)->addWidget(new Wt::WText("o[0..]=aX[0..];"));
					table->elementAt(10, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(10, 3)->addWidget(new Wt::WText("o[rY]=rX;"));
					table->elementAt(11, 2)->addWidget(new Wt::WText("~	aX,	rY "));
					table->elementAt(11, 3)->addWidget(new Wt::WText("o[rY..]=aX[0..];"));
					table->elementAt(12, 2)->addWidget(new Wt::WText("~	?X,	aY"));
					table->elementAt(12, 3)->addWidget(new Wt::WText("degenerates to putb ?X, rY"));

					table->elementAt(13, 1)->addWidget(new Wt::WText("setp"));
					table->elementAt(13, 3)->addWidget(new Wt::WText("mp=r0; "));
					table->elementAt(14, 2)->addWidget(new Wt::WText("~	?X  "));
					table->elementAt(14, 3)->addWidget(new Wt::WText("mp=rX; "));

					table->elementAt(15, 1)->addWidget(new Wt::WText("movp"));
					table->elementAt(15, 3)->addWidget(new Wt::WText("mp++; "));
					table->elementAt(16, 2)->addWidget(new Wt::WText("~	?X  "));
					table->elementAt(16, 3)->addWidget(new Wt::WText("mp+=rX; "));

					table->elementAt(17, 1)->addWidget(new Wt::WText("getm"));
					table->elementAt(17, 3)->addWidget(new Wt::WText("r0=m[mp];"));
					table->elementAt(18, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(18, 3)->addWidget(new Wt::WText("rX=m[mp];"));
					table->elementAt(19, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(19, 3)->addWidget(new Wt::WText("aX[0..]=m[mp..];"));

					table->elementAt(20, 1)->addWidget(new Wt::WText("putm"));
					table->elementAt(20, 3)->addWidget(new Wt::WText("m[mp]=r0;"));
					table->elementAt(21, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(21, 3)->addWidget(new Wt::WText("rX=m[mp];"));
					table->elementAt(22, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(22, 3)->addWidget(new Wt::WText("aX[0..]=m[mp..];"));

					table->elementAt(23, 1)->addWidget(new Wt::WText("assn"));
					table->elementAt(23, 3)->addWidget(new Wt::WText("r0=0;"));
					table->elementAt(24, 2)->addWidget(new Wt::WText("~	rX "));
					table->elementAt(24, 3)->addWidget(new Wt::WText("rX=0"));
					table->elementAt(25, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(25, 3)->addWidget(new Wt::WText("aX[i]=0;		for all i"));
					table->elementAt(26, 2)->addWidget(new Wt::WText("~	rX,	sY"));
					table->elementAt(26, 3)->addWidget(new Wt::WText("rX=Y;"));
					table->elementAt(27, 2)->addWidget(new Wt::WText("~	aX,	sY"));
					table->elementAt(27, 3)->addWidget(new Wt::WText("aX[i]=Y;		for all i"));
					table->elementAt(28, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(28, 3)->addWidget(new Wt::WText("aX[]=aY[0,1,2,3,...,Y];"));
					table->elementAt(29, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(29, 3)->addWidget(new Wt::WText("rX= sizeOf(aY[]);"));
					table->elementAt(30, 2)->addWidget(new Wt::WText("~	aX,	sY,	?Z	"));
					table->elementAt(30, 3)->addWidget(new Wt::WText("aX[rZ]=Y;  *NOT APPLIED*"));

					table->elementAt(31, 1)->addWidget(new Wt::WText("copy"));
					table->elementAt(31, 3)->addWidget(new Wt::WText(" r0=r1;"));
					table->elementAt(32, 2)->addWidget(new Wt::WText("~	rX	"));
					table->elementAt(32, 3)->addWidget(new Wt::WText(" rX=rX+1; (r/a)X+1 mean next register/next array"));
					table->elementAt(33, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(33, 3)->addWidget(new Wt::WText(" aX[i]=aX+1[i];	sliced"));
					table->elementAt(34, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(34, 3)->addWidget(new Wt::WText(" rX=rY;"));
					table->elementAt(35, 2)->addWidget(new Wt::WText("~	aX,	aY	"));
					table->elementAt(35, 3)->addWidget(new Wt::WText(" aX[i]=aY[i];	for all i"));
					table->elementAt(36, 2)->addWidget(new Wt::WText("~	aX,	rY	"));
					table->elementAt(36, 3)->addWidget(new Wt::WText("aX[i]=rY;		for all i"));
					table->elementAt(37, 2)->addWidget(new Wt::WText("~	rX,	aY	"));
					table->elementAt(37, 3)->addWidget(new Wt::WText("rX=sum(aY[i]);	for all i"));
					table->elementAt(38, 2)->addWidget(new Wt::WText("~	aX,	sY,	?Z"));
					table->elementAt(38, 3)->addWidget(new Wt::WText("aX[rZ]=rY;		only here, the 3rd op. matters *NOT APPLIED*"));

					table->elementAt(39, 1)->addWidget(new Wt::WText("swap"));
					table->elementAt(39, 3)->addWidget(new Wt::WText("r0;r1;"));
					table->elementAt(40, 2)->addWidget(new Wt::WText("~	rX	"));
					table->elementAt(40, 3)->addWidget(new Wt::WText("rX;rX+1;"));
					table->elementAt(41, 2)->addWidget(new Wt::WText("~	aX			"));
					table->elementAt(41, 3)->addWidget(new Wt::WText("aX[];aX+1[];"));
					table->elementAt(42, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(42, 3)->addWidget(new Wt::WText("rX;rY;"));
					table->elementAt(43, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(43, 3)->addWidget(new Wt::WText("aX[];aY[];"));
					table->elementAt(44, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(44, 3)->addWidget(new Wt::WText("aX[0];rY;"));
					table->elementAt(45, 2)->addWidget(new Wt::WText("~	rX,	aY	"));
					table->elementAt(45, 3)->addWidget(new Wt::WText("rX;aY[0];"));

					table->elementAt(46, 1)->addWidget(new Wt::WText("push"));
					table->elementAt(46, 3)->addWidget(new Wt::WText("s0.push(r0);"));
					table->elementAt(47, 2)->addWidget(new Wt::WText("~	r/aX"));
					table->elementAt(47, 3)->addWidget(new Wt::WText("s0.push(r/aX);	register content / array address"));
					table->elementAt(48, 2)->addWidget(new Wt::WText("~	r/aX,	?Y"));
					table->elementAt(48, 3)->addWidget(new Wt::WText("Y is either 0 or 1 for stack 0 or 1"));

					table->elementAt(49, 1)->addWidget(new Wt::WText("pop"));
					table->elementAt(49, 3)->addWidget(new Wt::WText("r0=s0.pop();"));
					table->elementAt(50, 2)->addWidget(new Wt::WText("~	r/aX"));
					table->elementAt(50, 3)->addWidget(new Wt::WText("r/aX=s0.pop();"));
					table->elementAt(51, 2)->addWidget(new Wt::WText("~	r/aX,	?Y"));
					table->elementAt(51, 3)->addWidget(new Wt::WText("Y is either 0 or 1 for stack 0 or 1"));

					table->elementAt(52, 0)->addWidget(new Wt::WText("Mathematical Operations:"));

					table->elementAt(52, 1)->addWidget(new Wt::WText("add"));
					table->elementAt(52, 3)->addWidget(new Wt::WText("r0++;	for sub, replace + with -;	"));
					table->elementAt(53, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(53, 3)->addWidget(new Wt::WText("rX++;"));
					table->elementAt(54, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(54, 3)->addWidget(new Wt::WText("aX[i]++; 		for all "));
					table->elementAt(55, 2)->addWidget(new Wt::WText("~	rX, 	rY"));
					table->elementAt(55, 3)->addWidget(new Wt::WText("rX+=rY;"));
					table->elementAt(56, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(56, 3)->addWidget(new Wt::WText("aX[i]+=aY[i];    missing aY[t]=>no change to aX[t]"));
					table->elementAt(57, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(57, 3)->addWidget(new Wt::WText("aX[i]+=rY;		for all i"));
					table->elementAt(58, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(58, 3)->addWidget(new Wt::WText("rX+=sizeOf(aY[i]);	for all i"));

					table->elementAt(59, 1)->addWidget(new Wt::WText("mul"));
					table->elementAt(59, 3)->addWidget(new Wt::WText("r0*=2;	for div, replace *10 with /10"));
					table->elementAt(60, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(60, 3)->addWidget(new Wt::WText("rX*=2;"));
					table->elementAt(61, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(61, 3)->addWidget(new Wt::WText("aX[i]*=2 	for all i"));
					table->elementAt(62, 2)->addWidget(new Wt::WText("~	rX, 	rY"));
					table->elementAt(62, 3)->addWidget(new Wt::WText("rX*=rY;"));
					table->elementAt(63, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(63, 3)->addWidget(new Wt::WText("aX[i]*=aY[i];    missing aY[t]=>no change to aX[t]"));
					table->elementAt(64, 2)->addWidget(new Wt::WText("~	aX,	rY	"));
					table->elementAt(64, 3)->addWidget(new Wt::WText("aX[i]*=rY;		for all i"));
					table->elementAt(65, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(65, 3)->addWidget(new Wt::WText("rX*=sizeOf(aY[i]);	for all i"));

					table->elementAt(66, 1)->addWidget(new Wt::WText("idiv"));
					table->elementAt(66, 3)->addWidget(new Wt::WText("r0=int(r0/2);		for remainder, use irem"));
					table->elementAt(67, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(67, 3)->addWidget(new Wt::WText("rX=int(rX/2);"));
					table->elementAt(68, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(68, 3)->addWidget(new Wt::WText("aX[i]=int(aX[i]/2);	for all i"));
					table->elementAt(69, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(69, 3)->addWidget(new Wt::WText("rX=int(rX/rY);"));
					table->elementAt(70, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(70, 3)->addWidget(new Wt::WText("aX[i]=int(aX[i]/aY[i]);	missing aY[t]=>no change to aX[t]"));
					table->elementAt(71, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(71, 3)->addWidget(new Wt::WText("aX[i]=int(aX[i]/rY);	for all i"));
					table->elementAt(72, 2)->addWidget(new Wt::WText("~	rX,	aYi"));
					table->elementAt(72, 3)->addWidget(new Wt::WText("rX=int(rX/sizeOf(aY[i]));	for all i"));

					table->elementAt(73, 1)->addWidget(new Wt::WText("abs"));
					table->elementAt(73, 3)->addWidget(new Wt::WText("r0=|r0|;"));
					table->elementAt(74, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(74, 3)->addWidget(new Wt::WText("rX=|rX|;"));
					table->elementAt(75, 2)->addWidget(new Wt::WText("~	aX"));
					table->elementAt(75, 3)->addWidget(new Wt::WText("aX[i]=|aX[i]|; 	for all i"));
					table->elementAt(76, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(76, 3)->addWidget(new Wt::WText("rX=|rY|;"));
					table->elementAt(77, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(77, 3)->addWidget(new Wt::WText("aX[i]=|aY[i]|;	missing aY[t]=>no change to aX[t]"));
					table->elementAt(78, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(78, 3)->addWidget(new Wt::WText("aX[i]=|rY|; 	for all i"));
					table->elementAt(79, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(79, 3)->addWidget(new Wt::WText("rX=|sizeOf(aY[i])|;	for all i"));

					table->elementAt(80, 1)->addWidget(new Wt::WText("rnd"));
					table->elementAt(80, 3)->addWidget(new Wt::WText("r0=rnd[0, 10];"));
					table->elementAt(81, 2)->addWidget(new Wt::WText("~	rX"));
					table->elementAt(81, 3)->addWidget(new Wt::WText("rX=rnd[0, rX];"));
					table->elementAt(82, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(82, 3)->addWidget(new Wt::WText("aX[i]=rnd[0, aX[i]];	for all i"));
					table->elementAt(83, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(83, 3)->addWidget(new Wt::WText("rX=rnd[rX, rY];"));
					table->elementAt(84, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(84, 3)->addWidget(new Wt::WText(" aX[i]=rnd[aX[i],aY[i]];	missing aY[t]=>rnd[0, aX[i]];"));
					table->elementAt(85, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(85, 3)->addWidget(new Wt::WText(" aX[i]=rnd[0, rY]; for all i"));
					table->elementAt(86, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(86, 3)->addWidget(new Wt::WText(" rX=rnd[0, sizeOf(aY[])];	"));

					table->elementAt(87, 1)->addWidget(new Wt::WText("sin"));
					table->elementAt(87, 3)->addWidget(new Wt::WText("r0=sin(r0); 		also, cos, asin and acos."));
					table->elementAt(88, 2)->addWidget(new Wt::WText("~  	rX		"));
					table->elementAt(88, 3)->addWidget(new Wt::WText("rX=sin(rX);"));
					table->elementAt(89, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(89, 3)->addWidget(new Wt::WText("aX[i]=sin(aX[i]); 	for all i"));
					table->elementAt(90, 2)->addWidget(new Wt::WText("~	rX,	rY		"));
					table->elementAt(90, 3)->addWidget(new Wt::WText("rX=sin(rY);"));
					table->elementAt(91, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(91, 3)->addWidget(new Wt::WText("aX[i]=sin(aY[i]);	missing aY[t]=>no change to aX[t]"));
					table->elementAt(92, 2)->addWidget(new Wt::WText("~	aX,	rY		"));
					table->elementAt(92, 3)->addWidget(new Wt::WText("aX[i]=sin(rY); 		for all i"));
					table->elementAt(93, 2)->addWidget(new Wt::WText("~	rX,	aY		"));
					table->elementAt(93, 3)->addWidget(new Wt::WText("rX=sin(sizeOf(aY[]));	"));

					table->elementAt(94, 1)->addWidget(new Wt::WText("pow"));
					table->elementAt(94, 3)->addWidget(new Wt::WText("r0=r0^2;"));
					table->elementAt(95, 2)->addWidget(new Wt::WText("~ 	rX	"));
					table->elementAt(95, 3)->addWidget(new Wt::WText("rX=rX^2;"));
					table->elementAt(96, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(96, 3)->addWidget(new Wt::WText("aX[i]=aX[i]^2;		for all i"));
					table->elementAt(97, 2)->addWidget(new Wt::WText("~	rX,	rY	"));
					table->elementAt(97, 3)->addWidget(new Wt::WText("rX=rX^rY;"));
					table->elementAt(98, 2)->addWidget(new Wt::WText("~	aX,	aY	"));
					table->elementAt(98, 3)->addWidget(new Wt::WText("aX[i]=aX[i]^aY[i];	missing aY[t]=>no change in aX[t]"));
					table->elementAt(99, 2)->addWidget(new Wt::WText("~	aX,	rY	"));
					table->elementAt(99, 3)->addWidget(new Wt::WText("aX[i]=aX[i]^rY;		for all i"));
					table->elementAt(100, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(100, 3)->addWidget(new Wt::WText("rX=rX^sizeOf(aY[]);	"));

					table->elementAt(101, 1)->addWidget(new Wt::WText("log"));
					table->elementAt(101, 3)->addWidget(new Wt::WText("r0=log10(r0);		lin for base e"));
					table->elementAt(102, 2)->addWidget(new Wt::WText("~	rX		"));
					table->elementAt(102, 3)->addWidget(new Wt::WText("rX=log10(rX);"));
					table->elementAt(103, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(103, 3)->addWidget(new Wt::WText("aX[i]=log10(aX[i]);	for all i"));
					table->elementAt(104, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(104, 3)->addWidget(new Wt::WText("rX=log10(rY);"));
					table->elementAt(105, 2)->addWidget(new Wt::WText("~	aX,	aY"));
					table->elementAt(105, 3)->addWidget(new Wt::WText("aX[i]=log10(aY[i]);	missing aY[t]=>no change in aX[t]"));
					table->elementAt(106, 2)->addWidget(new Wt::WText("~	aX,	rY"));
					table->elementAt(106, 3)->addWidget(new Wt::WText("aX[i]=log10(rY);		for all i"));
					table->elementAt(107, 2)->addWidget(new Wt::WText("~	rX,	aY		"));
					table->elementAt(107, 3)->addWidget(new Wt::WText("rX= log10(sizeOf(aY[]));	s"));

					table->elementAt(108, 0)->addWidget(new Wt::WText("Logical Operations:"));

					table->elementAt(108, 1)->addWidget(new Wt::WText("and"));
					table->elementAt(108, 3)->addWidget(new Wt::WText("r2=r2 && r3;	"));
					table->elementAt(109, 2)->addWidget(new Wt::WText("~ 	rX	"));
					table->elementAt(109, 3)->addWidget(new Wt::WText("rX=rX && rX+1; 		also, orr, xor."));
					table->elementAt(110, 2)->addWidget(new Wt::WText("~	aX			"));
					table->elementAt(110, 3)->addWidget(new Wt::WText("aX[i]=aX[i] && aX+1[i];	for all i;"));
					table->elementAt(111, 2)->addWidget(new Wt::WText("~	rX,	rY		"));
					table->elementAt(111, 3)->addWidget(new Wt::WText("rX=rX && rY;"));
					table->elementAt(112, 2)->addWidget(new Wt::WText("~	aX,	aY		"));
					table->elementAt(112, 3)->addWidget(new Wt::WText("aX[i]=aX[i] && aY[i]	for all i; "));
					table->elementAt(113, 2)->addWidget(new Wt::WText("~	aX,	rY		"));
					table->elementAt(113, 3)->addWidget(new Wt::WText("aX[i]=aX[i] && rY;	for all i "));
					table->elementAt(114, 2)->addWidget(new Wt::WText("~	rX,	aY	"));
					table->elementAt(114, 3)->addWidget(new Wt::WText("rX=rX && sizeOf(aY[]);	"));

					table->elementAt(115, 1)->addWidget(new Wt::WText("not"));
					table->elementAt(115, 3)->addWidget(new Wt::WText("r2=!(r2);"));
					table->elementAt(116, 2)->addWidget(new Wt::WText("~	rX			"));
					table->elementAt(116, 3)->addWidget(new Wt::WText("rX=!(rX);"));
					table->elementAt(117, 2)->addWidget(new Wt::WText("~	aX			"));
					table->elementAt(117, 3)->addWidget(new Wt::WText("aX[i]=!(aX[i]);		for all i"));
					table->elementAt(118, 2)->addWidget(new Wt::WText("~	rX,	rY	"));
					table->elementAt(118, 3)->addWidget(new Wt::WText("rX=!(rY);"));
					table->elementAt(119, 2)->addWidget(new Wt::WText("~	aX,	aY		"));
					table->elementAt(119, 3)->addWidget(new Wt::WText("aX[i]=!aY[i];		for all i (missing => F)"));
					table->elementAt(120, 2)->addWidget(new Wt::WText("~	aX,	rY	"));
					table->elementAt(120, 3)->addWidget(new Wt::WText("aX[i]=!rY;"));
					table->elementAt(121, 2)->addWidget(new Wt::WText("~	rX,	aY	"));
					table->elementAt(121, 3)->addWidget(new Wt::WText("rX=!(sizeOf(aY[]));	"));

					table->elementAt(122, 1)->addWidget(new Wt::WText("less"));
					table->elementAt(122, 3)->addWidget(new Wt::WText("r2=(r2<0);	"));
					table->elementAt(123, 2)->addWidget(new Wt::WText("~	rX			"));
					table->elementAt(123, 3)->addWidget(new Wt::WText("rX=(rX<0);"));
					table->elementAt(124, 2)->addWidget(new Wt::WText("~	aX		"));
					table->elementAt(124, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]<0);		for all i"));
					table->elementAt(125, 2)->addWidget(new Wt::WText("~	rX,	rY		"));
					table->elementAt(125, 3)->addWidget(new Wt::WText("rX=(rX<rX);"));
					table->elementAt(126, 2)->addWidget(new Wt::WText("~	aX,	aY		 "));
					table->elementAt(126, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]<aY[i]);	for all i"));
					table->elementAt(127, 2)->addWidget(new Wt::WText("~	aX,	rY		"));
					table->elementAt(127, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]<rY);	for all i"));
					table->elementAt(128, 2)->addWidget(new Wt::WText("~	rX,	aY"));
					table->elementAt(128, 3)->addWidget(new Wt::WText("rX=(rX<sizeOf(aY[]));"));

					table->elementAt(129, 1)->addWidget(new Wt::WText("equl"));
					table->elementAt(129, 3)->addWidget(new Wt::WText("r2=(r2==0); also, greq."));
					table->elementAt(130, 2)->addWidget(new Wt::WText("~	rX			"));
					table->elementAt(130, 3)->addWidget(new Wt::WText("rX=(rX==0);"));
					table->elementAt(131, 2)->addWidget(new Wt::WText("~	aX	"));
					table->elementAt(131, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]==0);	for all i"));
					table->elementAt(132, 2)->addWidget(new Wt::WText("~	rX,	rY"));
					table->elementAt(132, 3)->addWidget(new Wt::WText("rX=(rX==rY);"));
					table->elementAt(133, 2)->addWidget(new Wt::WText("~	aX,	aY		 "));
					table->elementAt(133, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]==aY[i]);	for all i (missing => F)"));
					table->elementAt(134, 2)->addWidget(new Wt::WText("~	aX,	rY	"));
					table->elementAt(134, 3)->addWidget(new Wt::WText("aX[i]=(aX[i]==rY);	for all i"));
					table->elementAt(135, 2)->addWidget(new Wt::WText("~	rX,	aY	"));
					table->elementAt(135, 3)->addWidget(new Wt::WText("rX=(rX==sizeOf(aY[]));"));

					table->elementAt(136, 0)->addWidget(new Wt::WText("Flow Control Operations:"));
					table->elementAt(136, 1)->addWidget(new Wt::WText("ifel"));
					table->elementAt(136, 3)->addWidget(new Wt::WText("if (f is true) then execute the next instruction and jump over the following one, else jump over the next instruction then start executing."));
					table->elementAt(137, 2)->addWidget(new Wt::WText("~	?X"));
					table->elementAt(137, 3)->addWidget(new Wt::WText("if (f is true) execute the next set of instructions up to & inc. the following instruction labeled X,else jump to the instruction immediately following the one labeled X (also called X+1)."));
					table->elementAt(138, 2)->addWidget(new Wt::WText("~	?X,	?Y"));
					table->elementAt(138, 3)->addWidget(new Wt::WText("if (f is true) execute the next set of instructionsup to & inc. the instruction labeled X then jump over the following instructions to Y+1, else jump to instruction at X+1 and resume execution."));
					table->elementAt(139, 1)->addWidget(new Wt::WText("whil"));
					table->elementAt(139, 3)->addWidget(new Wt::WText("while (f is true) repeat next instruction."));
					table->elementAt(140, 2)->addWidget(new Wt::WText("~      ?X	"));
					table->elementAt(140, 3)->addWidget(new Wt::WText("while (f is true) repeat instruction(s) up to and inc. the one labeled X, which must follow"));
					table->elementAt(141, 2)->addWidget(new Wt::WText("~	?X,	?Y"));
					table->elementAt(141, 3)->addWidget(new Wt::WText("while (f is true) repeat instruction(s) up to X, Y times"));
				}
			}



			//CONTAINER TO BE USED FOR ABOUT US.
			container_aboutus = new Wt::WContainerWidget(wt_root);
			container_aboutus->setId("container_tutorialpage");
			container_aboutus->setStyleClass(Wt::WString::fromUTF8("col-xs-12 container-fluid row"));
			container_aboutus->setInline(0);
			container_aboutus->setHtmlTagName("div");
			{

				separator = new Wt::WImage(Wt::WLink("Media/Separator.png"), container_aboutus);
				separator->setId("separator");
				separator->setStyleClass(Wt::WString::fromUTF8(""));
				separator->setInline(1);
				separator->setHeight(275);


				Participant = new Wt::WImage(Wt::WLink("Media/ParticipantFinal3.png"), container_aboutus);
				Participant->setId("Participant");
				Participant->setStyleClass(Wt::WString::fromUTF8(""));
				Participant->setInline(1);



			}

			//CONTAINER TO BE USED FOR THE EMULATOR.
			container_emulator = new Wt::WContainerWidget(wt_root);
			container_emulator->setId("container_emulator");
			container_emulator->setStyleClass(Wt::WString::fromUTF8("col-xs-12 container-fluid row"));
			container_emulator->setInline(0);
			container_emulator->setHtmlTagName("div");
			{
				//PANEL NUMBER #1 : Functionality and understanding.

				Wt::WContainerWidget *cw_panel01 = new Wt::WContainerWidget(container_emulator);
				panel01 = new Wt::WPanel(container_emulator);
				panel01->setId("panel01");
				panel01->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
				panel01->setInline(0);
				panel01->setTitle(Wt::WString::fromUTF8("Functionality and understanding."));
				panel01->setCollapsible(1);
				panel01->setCentralWidget(cw_panel01);
				panel01->setCollapsible(false);
				{
					//TEXT FOR EXPLANATION ON WHY BRAIN FUCK IS USED.
					text5 = new Wt::WText(cw_panel01);
					text5->setId("text5");
					text5->setStyleClass(Wt::WString::fromUTF8(""));
					text5->setInline(0);
					text5->setTextFormat((Wt::TextFormat)2);
					text5->setText(Wt::WString::fromUTF8("Turing Completeness (TC) is an important concept in computability theory. It describes a programming language as being able to simulate any single-taped Turing machine. The minimalist esoteric language Brain Fuck is TC and it will be used to demonstrate that Crab 2.0 is TC as well. In fact, any of the 8 commands of Brain Fuck can be simulated by Crab 2.0 commands. The perfect implementation of Brain Fuck code by Crab 2.0 can be tested by the user on this page.\n\n\
For more information on Brain Fuck functionality, please visit : http://fatiherikli.github.io/brainfuck-visualizer. \n\n"));
				}

				//PANEL #2: EXECUTION.


				Wt::WContainerWidget *cw_panel02 = new Wt::WContainerWidget(container_emulator);
				panel02 = new Wt::WPanel(container_emulator);
				panel02->setId("panel02");
				panel02->setStyleClass(Wt::WString::fromUTF8("panel panel panel panel-default"));
				panel02->setInline(0);
				panel02->setTitle(Wt::WString::fromUTF8("Execution."));
				panel02->setCollapsible(1);
				panel02->setCentralWidget(cw_panel02);
				panel02->setCollapsible(false);
				{
					//WHERE THE USER INPUTS THE NEEDED CHARARACTORS.
					user_input = new Wt::WLineEdit(cw_panel02);
					user_input->setInline(1);
					user_input->setWidth(300);
					user_input->setText("HELLOWORLD");


					text6 = new Wt::WText(cw_panel02);
					text6->setId("text6");
					text6->setStyleClass(Wt::WString::fromUTF8(""));
					text6->setInline(1);
					text6->setTextFormat((Wt::TextFormat)2);
					text6->setText(Wt::WString::fromUTF8("*Please enter your characters needed before running the emulation."));


					//WHERE THE USER TYPES THE BRAIN FUCK CODE.
					Wt::WTextArea *TextBox = new Wt::WTextArea(cw_panel02);
					TextBox->setColumns(80);
					TextBox->setRows(5);
					TextBox->setText(",.>,.>,.>,.>,.>,.>,.>,.>,.>,.");

					//BUTTON TO EMULATE THE USER INPUT.
					button_emulate = new Wt::WPushButton(cw_panel02);
					button_emulate->setId("button_emulate");
					button_emulate->setStyleClass(Wt::WString::fromUTF8("btn-default with-label btn  btn btn-default with-label"));
					button_emulate->setInline(0);
					button_emulate->setEmptyText(Wt::WString::fromUTF8(""));
					button_emulate->setText(Wt::WString::fromUTF8("Emulate"));
					button_emulate->setLink(Wt::WLink(""));
					button_emulate->clicked().connect(std::bind([=]() {
						//HERE THE PARSING OF THE STUFF ENTERED IS BEING DONE.

						string word;
						word = (user_input->text()).toUTF8();

						TempNumOne = word.size();
						for (int a = 0; a < TempNumOne; a++)
						{
							Filename[a] = word[a];
						}

						textEmulator->setText(toCrab20((TextBox->text()).toUTF8()));	}));

					//TEXT THAT WILL HOLD THE RESULT.
					textEmulator = new Wt::WText(cw_panel02);
					textEmulator->setStyleClass("xhtml-output");
					textEmulator->setInline(0);
					textEmulator->setTextFormat((Wt::TextFormat)2);
				}
			}

			//LINK FOR THE HTML FILE.
			Wt::WAnchor *anchor = new Wt::WAnchor(Wt::WLink("Media/html/classes.html"), "Developer(Click Here)");
			anchor->setTarget(Wt::TargetNewWindow);




			//SETUP FOR THE LEFT-SIDE MENU.
			Wt::WMenu *leftMenu = new Wt::WMenu(contentsStack, wt_root);
			navigation->addMenu(leftMenu);
			//LEFT ITEM ADDING OF ELEMENTS.
			//MAKE SURE TO HAVE THE PROPER CONTAINERS ATTACHED TO THE ELEMENTS TO DISPLAY.
			//MAKE SURE THE STYLE CLASS OF THE CONTAINER IS PROPER AS WELL.

			//VIRTUAL MACHINE PAGE.
			leftMenu->addItem("Virtual Machine", container_vmpage);

			//RESSOURCES PAGE
			leftMenu->addItem("Instructions", container_tutorialpage);


			//EMULATOR PAGE.
			leftMenu->addItem("BrainFuck Emulator", container_emulator);

			//DEVELOPPER PAGE.
			leftMenu->addItem("Developer", anchor);

			//ABOUT US PAGE.
			leftMenu->addItem("About Us", container_aboutus);
		}


		connectAllSignals();
		addAllJavaScripts();
		updateUi();

	}

	void highlightLine()
	{
		if (vm->isProgramLoaded())
		{
			if (vm->getPc() > 0)
			{
				removeHighlightLine();
				if (vm->getPc() == vm->getLoadedProgram().size())
					currentBreakpointRow = vm->getLoadedProgram().at(vm->getPc() - 1).label;
				else
					currentBreakpointRow = vm->getLoadedProgram().at(vm->getPc()).label - 1;
				std::string editor_ref = editor->jsRef();
				std::string command = editor_ref + ".editor.session.setBreakpoint(" + std::to_string(currentBreakpointRow) + "); ";
				editor->doJavaScript(command);
			}
		}

	}
	void removeHighlightLine()
	{
		std::string editor_ref = editor->jsRef();
		std::string command = editor_ref + ".editor.session.clearBreakpoint(" + std::to_string(currentBreakpointRow) + "); ";
		editor->doJavaScript(command);

	}
	void setEditorValue(std::string value)
	{
		std::string editor_ref = editor->jsRef(); // is a text string that will be the element when executed in JS
		std::string command =
			editor_ref + ".editor.setValue(\"" + value + "\");";
		editor->doJavaScript(command);
	}
	void addAllStyleSheets()
	{

		Wt::WApplication::instance()->useStyleSheet(Wt::WLink("resources/main.css"));
		//Wt::WApplication::instance()->useStyleSheet(Wt::WLink("https://1drv.ms/u/s!AmkOtbSAYucxhdE_uMbcAs9S74Ey9A"));
	}
	void addAllJavaScripts()
	{

		//Wt::WApplication::instance()->require(std::string("ace-editor/ace.js"));
		Wt::WApplication::instance()->require(std::string("https://rawgithub.com/ajaxorg/ace-builds/master/src-noconflict/ace.js"));
		//	Wt::WApplication::instance()->require(std::string("ace/range"));

	}
	void connectAllSignals()
	{


	}


	class VirtualModel : public Wt::WAbstractTableModel
	{
	public:
		VirtualModel(int rows, int columns, Wt::WObject *parent = 0) : Wt::WAbstractTableModel(parent), rows_(rows), columns_(columns)
		{ }

		virtual int rowCount(const Wt::WModelIndex& parent = Wt::WModelIndex()) const
		{
			if (!parent.isValid())
				return rows_;
			else
				return 0;
		}

		virtual int columnCount(const Wt::WModelIndex& parent = Wt::WModelIndex()) const
		{
			if (!parent.isValid())
				return columns_;
			else
				return 0;
		}

		virtual boost::any data(const Wt::WModelIndex& index, int role = Wt::DisplayRole) const
		{
			switch (role) {
			case Wt::DisplayRole:
				if (index.column() == 0)
					return Wt::WString("Row {1}").arg(index.row());
				else
					return Wt::WString("Item row {1}, col {2}")
					.arg(index.row()).arg(index.column());
			default:
				return boost::any();
			}
		}

		/*
		//memory table
		table_memory->clear();

		std::array<double, MAX_ARRAY_SIZE> tempMemory = vm->getMemory();
		for (int i = 0; i < tempMemory.size(); i++)
		{
		if (vm->getMp() != i)
		table_memory->elementAt(0, i)->addWidget(new Wt::WText(cleanNumber(tempMemory[i])));
		else
		table_memory->elementAt(0, i)->addWidget(new Wt::WText("<span style=\"color: #ff0000; \"><strong>"
		+ cleanNumber(tempMemory[i]) + "</strong></span>"));
		}
		*/

		virtual boost::any headerData(int section, Wt::Orientation orientation = Wt::Horizontal, int role = Wt::DisplayRole) const
		{

			if (orientation == Wt::Horizontal) {
				switch (role) {
				case Wt::DisplayRole:
					return Wt::WString("{1}").arg(section);
				default:
					return boost::any();
				}
			}
			else
				return boost::any();
		}

	private:
		int rows_, columns_;
	};



	//**EMULATOR FUNCTION.
	string toCrab20(string code)
	{
		//ALL PRE-CALLED VARIABLES HERE.
		char listToScan[1000]; //ARRAY OF CHARACTERS THAT WILL BE ANALYSED.
		int memory[200] = {}; //ARRAY OF INTEGERS THAT WILL SIMULATE THE MEMORY.
		int pointerAt = 0; // INTEGER THAT WILL SIMULATE THE POINTER.
		int interimValue = 0;
		bool verif1 = true; // FIRST VERIFICATION FOR THE ACCEPTED SYMBOLS.
		bool verif21 = true;
		bool verif22 = true;
		bool verif3 = true;
		char input1; //USED FOR THE INPUT OF THE ASCII CHAR.
		vector< string > final;
		//FOR THE COMMA COMMAND.
		int countercomma = 0;
		int counter = 0;

		//FIRST, TRANFERS OF ALL THE CODE STRING CHARACTERS INTO LIST TO SCAN.
		strncpy_s(listToScan, code.c_str(), sizeof(code));

		//SECOND, FOR TESTING PURPOSE, DEMONSTRATE THE ELEMENTS INTO THE ARRAY.
		final.push_back("Code verification: \n");


		//CONDITION #1 NOT HAVE ANY OTHER SYMBOLS THEN THE ONES SUPPORTED.
		for (int c = 0; c < code.length(); c++)
		{
			if ((listToScan[c] == '>') || (listToScan[c] == '<') || (listToScan[c] == '+') || (listToScan[c] == '-') || (listToScan[c] == ']') || (listToScan[c] == '[') || (listToScan[c] == '.') || (listToScan[c] == '!') || (listToScan[c] == ',') || (listToScan[c] == ' '))
			{
				continue;
			}
			else
			{
				verif1 = false;
				final.push_back("Some command in your code is not supported, please verify your code.\n");
				break;
			}
		}
		if (verif1 == true)
		{
			final.push_back("Symbol verifition: passed.\n");
		}

		//CONDITION #2 IS TO HAVE A ] FOR EVERY [.
		bool interim = false;
		bool interim1 = false;
		for (int d = 0; d < code.length(); d++)
		{
			if (listToScan[d] == '[')
			{
				for (int e = d + 1; e < code.length(); e++)
				{


					if (listToScan[e] == ']')
					{
						interim = true;
						d = e + 1;
						break;
					}
					else if (listToScan[e] == '[')
					{
						//interim stays negative.
						verif21 = false;
						break;
					}
					else
					{
						continue;
					}
				}

				if (interim == true)
				{
					//GOOD TO CONTINUE THE LOOPING.
					//PUT BACK INTERIM TO ORIGINAL VALUE AFTER VERIF.
					interim = false;
				}
				else
				{
					verif21 = false;
					//PUT BACK INTERIM TO ORIGINAL VALUE AFTER VERIF.
					interim = false;
				}
			}


			if (verif21 == true)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		for (int d = 0; d < code.length(); d++)
		{
			if (listToScan[d] == '[')
			{
				interim1 = true;
			}
			else if (listToScan[d] == ']')
			{
				if (interim1 == true)
				{
					//CONTINUE BUT RESET THE VALUE FIRST
					interim1 = false;
					continue;
				}
				else
				{
					//BREAK AND RESET THE VALUE.
					verif22 = false;
					break;
				}
			}
			else
			{
				continue;
			}

		}
		if ((verif21 == true) && (verif22 == true))
		{
			final.push_back("Conditionnal coordination: passed. \n");
		}
		else
		{
			final.push_back("Please verify that each '[' command has it's own end of loop ']' command.\n");
		}

		//FOR TESTING.
		if (verif21 == false)
		{
			final.push_back("ERROR 21 Triggered\n");
		}

		if (verif22 == false)
		{
			final.push_back("ERROR 22 Triggered\n");
		}

		if (verif1 == false)
		{
			final.push_back("ERROR 1 Triggered\n");
		}

		//COUNTING THE NUMBER OF COMMAS IN THE CODE.
		for (int j = 0; j < code.length(); j++)
		{
			if (listToScan[j] == ',')
			{
				counter++;
			}
		}


		if (counter != TempNumOne)
		{
			verif3 = false;
		}

		if (verif3 == false)
		{
			final.push_back("ERROR 3 Triggered\n");
			final.push_back("Please make sure the number of characters is equal to the number of commas in your code.\n");
		}
		else
		{
			final.push_back("Comma entry verification: passed.\n");
		}


		//***
		//DISPLAYING THE CODE VERIFIED STARTS HERE.
		//AL CONDITIONS OF EXCEPTIONS MUST BE PASSED.
		if ((verif1 == true) && (verif21 == true) && (verif22 == true) && (verif3 == true))
		{
			final.push_back("assn a0");
			final.push_back("putb a0");

			//LOOPING AREA TO HANDLE THE TRANSFER INTO CRAB 2.0.
			for (int a = 0; a < code.length(); a++)
			{
				switch (listToScan[a])
				{
				case ',':
				{
					final.push_back("assn r1 " + to_string(int(Filename[countercomma])));
					final.push_back("add r0 r1");
					final.push_back("putm");
					final.push_back("assn r1 0");
					final.push_back("assn");
					memory[pointerAt] = int(Filename[countercomma]);
					countercomma++;
					break;
				}
				case '>':
				{
					final.push_back("movp");
					pointerAt++;
					break;
				}
				case '<':
				{
					final.push_back("assn r0 -1");
					final.push_back("movp r0");
					final.push_back("assn");
					pointerAt--;
					break;
				}
				case '+':
				{
					final.push_back("getm");
					final.push_back("assn r1 1");
					final.push_back("add r0 r1");
					final.push_back("putm");
					final.push_back("assn r1 0");
					final.push_back("assn");
					memory[pointerAt]++;
					break;
				}
				case '-':
				{
					final.push_back("getm");
					final.push_back("assn r1 -1");
					final.push_back("add r0 r1");
					final.push_back("putm");
					final.push_back("assn r1 0");
					final.push_back("assn");
					memory[pointerAt]--;
					break;
				}
				case '.':
				{
					final.push_back("getm");
					final.push_back("putb r0 r3");
					final.push_back("assn");
					final.push_back("assn r0 r1");
					final.push_back("add r3 r0");
					final.push_back("assn");
					break;
				}
				case '[':
				{

					//FIRST WE NEED TO FIND WHERE IS THE NEXT ']'
					for (int j = a + 1; j < code.length(); j++)
					{
						if (listToScan[j] == ']')
						{
							interimValue = j;
							break;
						}
						else
						{
							continue;
						}
					}

					//HERE THE INTERIMVALUE VARIABLE HOLDS WHERE THE NEXT ']' IS LOCATED AT EXACTY.
					//SO A IS STILL AT '['.
					//SO INTERIMVALUE IS AT ']'

					//WHILE LOOP STARTING AT THE RIGH OUTPUT VALUE.
					memory[pointerAt]--;
					while (memory[pointerAt] != 0)
					{
						for (int b = a + 1; b < interimValue; b++)
						{
							switch (listToScan[b])
							{
							case ',':
							{
								cout << "Please write your character input: \n";
								cin >> input1;
								cout << "The value given is: ";
								cout << int(input1);
								cout << "\n";
								system("pause"); //GIVES TIME TO THE USER TO VERIFY THE VALUE.
								final.push_back("assn r1 " + to_string(int(input1)));
								final.push_back("add r0 r1");
								final.push_back("putm");
								final.push_back("assn r1 0");
								final.push_back("assn");
								memory[pointerAt] = int(input1);  //THE DECIMAL VALUE WILL BE STORED AT THE EXACT MEMORY LOCATION.
								break;
							}
							case '>':
							{
								final.push_back("movp");
								pointerAt++;
								break;
							}
							case '<':
							{
								final.push_back("assn r0 -1");
								final.push_back("movp r0");
								final.push_back("assn");
								pointerAt--;
								break;
							}
							case '+':
							{
								final.push_back("getm");
								final.push_back("assn r1 1");
								final.push_back("add r0 r1");
								final.push_back("putm");
								final.push_back("assn r1 0");
								final.push_back("assn");
								memory[pointerAt]++;
								break;
							}
							case '-':
							{
								final.push_back("getm");
								final.push_back("assn r1 -1");
								final.push_back("add r0 r1");
								final.push_back("putm");
								final.push_back("assn r1 0");
								final.push_back("assn");
								memory[pointerAt]--;
								break;
							}
							case '.':
							{
								final.push_back("getm");
								final.push_back("putb r0 r3");
								final.push_back("assn");
								final.push_back("assn r0 r1");
								final.push_back("add r3 r0");
								final.push_back("assn");
								break;
							}
							}
						}

					}
					break;
				}
				}

			}

		}
		else
		{
			cout << "Please verify your code and process again.\n";
		}


		//AN IDEA TO PUT THE WORLDS FROM THE VECTOR INTO THE STRING AND THEN RETURN IT.
		//string Return(final.begin(), final.end()-1);
		//return Return;
		string Return;

		for (decltype(final.size()) i = 0; i < final.size(); ++i)
		{
			Return += final[i] + "\n";
		}


		return Return;

	}

};

#endif // UI_CRAB_H