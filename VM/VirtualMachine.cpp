/*************************************************************\
VirtualMachine.cpp
Author: Tawfiq Jawhar

//This file contains //TODO
/*********************************************************/

#include "VirtualMachine.h"
#include <boost/lexical_cast.hpp>


using namespace std::placeholders;

namespace crab {



	VirtualMachine::VirtualMachine()
	{
		mapInstructions();
		operatorsBimap = Operator::create_map();
		programIsLoaded = false;
	}


	void VirtualMachine::printVmComponents()
	{
#ifdef CONSOLE_APP
		std::cout << "register 0 " << registers[0] << std::endl;
		std::cout << "register 1 " << registers[1] << std::endl;
		std::cout << "register 2 " << registers[2] << std::endl;
		std::cout << "register 3 " << registers[3] << std::endl;
#endif

#ifdef WT_WEB_APP

#endif
	}



	void VirtualMachine::mapInstructions()
	{
		instructionFunctions[Operator::GETB] = &VirtualMachine::GETB;
		instructionFunctions[Operator::PUTB] = &VirtualMachine::PUTB;
		instructionFunctions[Operator::SETP] = &VirtualMachine::SETP;
		instructionFunctions[Operator::MOVP] = &VirtualMachine::MOVP;
		instructionFunctions[Operator::GETM] = &VirtualMachine::GETM;
		instructionFunctions[Operator::PUTM] = &VirtualMachine::PUTM;
		instructionFunctions[Operator::ASSN] = &VirtualMachine::ASSN;
		instructionFunctions[Operator::COPY] = &VirtualMachine::COPY;
		instructionFunctions[Operator::SWAP] = &VirtualMachine::SWAP;
		instructionFunctions[Operator::PUSH] = &VirtualMachine::PUSH;
		instructionFunctions[Operator::POP] = &VirtualMachine::POP;
		instructionFunctions[Operator::ADD] = &VirtualMachine::ADD;
		instructionFunctions[Operator::SUB] = &VirtualMachine::SUB;
		instructionFunctions[Operator::MUL] = &VirtualMachine::MUL;
		instructionFunctions[Operator::DIV] = &VirtualMachine::DIV;
		instructionFunctions[Operator::IDIV] = &VirtualMachine::IDIV;
		instructionFunctions[Operator::IREM] = &VirtualMachine::IREM;
		instructionFunctions[Operator::ABS] = &VirtualMachine::ABS;
		instructionFunctions[Operator::RND] = &VirtualMachine::RND;
		instructionFunctions[Operator::SIN] = &VirtualMachine::SIN;
		instructionFunctions[Operator::COS] = &VirtualMachine::COS;
		instructionFunctions[Operator::ASIN] = &VirtualMachine::ASIN;
		instructionFunctions[Operator::ACOS] = &VirtualMachine::ACOS;
		instructionFunctions[Operator::POW] = &VirtualMachine::POW;
		instructionFunctions[Operator::LOG] = &VirtualMachine::LOG;
		instructionFunctions[Operator::AND] = &VirtualMachine::AND;
		instructionFunctions[Operator::ORR] = &VirtualMachine::ORR;
		instructionFunctions[Operator::XOR] = &VirtualMachine::XOR;
		instructionFunctions[Operator::NOT] = &VirtualMachine::NOT;
		instructionFunctions[Operator::LESS] = &VirtualMachine::LESS;
		instructionFunctions[Operator::EQUL] = &VirtualMachine::EQUL;
		instructionFunctions[Operator::GREQ] = &VirtualMachine::GREQ;
		instructionFunctions[Operator::IFEL] = &VirtualMachine::IFEL;
		instructionFunctions[Operator::WHIL] = &VirtualMachine::WHIL;
	}


	void VirtualMachine::initializeComponenets()
	{
		programIsLoaded = false;

		registers[0] = 0;
		registers[1] = 0;
		registers[2] = 0;
		registers[3] = 0;

		arrayRegisters[0].size = 0;
		arrayRegisters[1].size = 0;
		arrayRegisters[2].size = 0;
		arrayRegisters[3].size = 0;

		std::fill(arrayRegisters[0].arrayValue.begin(), arrayRegisters[0].arrayValue.end(), 0);
		std::fill(arrayRegisters[1].arrayValue.begin(), arrayRegisters[1].arrayValue.end(), 0);
		std::fill(arrayRegisters[2].arrayValue.begin(), arrayRegisters[2].arrayValue.end(), 0);
		std::fill(arrayRegisters[3].arrayValue.begin(), arrayRegisters[3].arrayValue.end(), 0);

		inputBuffer.size = 0;
		outputBuffer.size = 0;
		std::fill(inputBuffer.arrayValue.begin(), inputBuffer.arrayValue.end(), 0);
		std::fill(outputBuffer.arrayValue.begin(), outputBuffer.arrayValue.end(), 0);

		std::fill(memory.begin(), memory.end(), 0);

		flagLogical = false;
		flagIf = false;
		flagWhile = false;
		flagControl1 = false;
		flagControl2 = false;
		flagControl3 = false;

		controlRegister1 = 0;
		controlRegister2 = 0;
		controlRegister3 = 0;

		pc = 0;
		mp = 0;
		instructionsExecuted = 0;

	}


	void VirtualMachine::runVm()
	{
		while (executeNextInstruction());
	}

	bool VirtualMachine::executeNextInstruction()
	{
		if (!programIsLoaded)
			throw std::exception("Can not run VM. Program is not loaded successfully.");

		if (translatedMemory.empty())	return false;
		if (pc > translatedMemory.size())	return false;		//TODO wont work if while till end of program i think

		if (flagIf)
		{
			if (pc > translatedMemory.size() - 1)	return false;

			if (controlRegister1 == translatedMemory.at(pc).label && flagControl2)
			{
				std::map<int, int>::iterator it = labelsMap.find(controlRegister2);
				pc = it->second;

				flagControl1 = false;
				flagControl2 = false;
				flagIf = false;
			}
			else if (controlRegister1 == translatedMemory.at(pc).label)
			{
				pc++;
				flagControl1 = false;
				flagIf = false;
			}
		}
		else if (flagWhile)
		{
			if (!flagLogical)
			{
				flagControl1 = false;
				flagControl2 = false;
				flagControl3 = false;
				flagWhile = false;

			}
			else
			{
				std::map<int, int>::iterator it = labelsMap.find(controlRegister1);

				if (flagControl1 && !flagControl2 && !flagControl3)
				{
					pc = it->second;
				}
				else if (flagControl1 && flagControl2 && !flagControl3)
				{
					if (translatedMemory.at(pc - 1).label == controlRegister2)
					{
						pc = it->second;
					}
				}
				else if (flagControl1 && flagControl2 && flagControl3)
				{
					if (translatedMemory.at(pc - 1).label == controlRegister2)
					{

						if (controlRegister3 < 1)
						{
							flagControl1 = false;
							flagControl2 = false;
							flagControl3 = false;
							flagWhile = false;
						}
						else
						{
							pc = it->second;
							controlRegister3--;
						}
					}
				}
			}
		}

		if (pc > translatedMemory.size() - 1)	return false;
		//if(flagIf && translatedMemory.at(pc).op == Operator::OP::IFEL)
		(this->*instructionFunctions[translatedMemory.at(pc).op])(translatedMemory.at(pc).operands);
		instructionsExecuted++;
		if (instructionsExecuted > translatedMemory.size() * 100)
			return false;
		else
			return true;
	}

	void VirtualMachine::loadProgram(ci_istringstream& iss)
	{
		ci_string line;

		// Parse program line by line
		int line_no = 0;
		programIsLoaded = false;
		translatedMemory.clear();
		labelsMap.clear();

		while (std::getline(iss, line))
		{
			line_no++;

			// Splitting line into tokens
			ci_istringstream strstr(line);
			std::istream_iterator<ci_string, char, ci_char_traits> it(strstr);
			std::istream_iterator<ci_string, char, ci_char_traits> end;
			std::vector<ci_string> token(it, end);

			if (!token.empty())
			{
				Instruction inst;
				if (operatorsBimap.right.find(token[0]) != operatorsBimap.right.end())
				{
					//std::cout << token[0] << " = " << operatorsBimap.right.at(token[0]) << std::endl;
					inst.op = operatorsBimap.right.at(token[0]);
					inst.label = line_no;
					for (int i = 1; i < token.size(); i++)
					{
						try
						{
							Operand operand;

							if (token[i][0] == 'a' || token[i][0] == 'A')
							{
								operand.addressingMode = ISARRAY;
								double value_ = boost::lexical_cast<double>(token[i].substr(1, token[i].size() - 1));
								operand.value = value_;

							}
							else if (token[i][0] == 'R' || token[i][0] == 'r')
							{
								operand.addressingMode = !ISARRAY;
								double value_ = boost::lexical_cast<double>(token[i].substr(1, token[i].size() - 1));
								operand.value = value_;
							}
							else
							{
								bool is_a_number = false;

								double value_ = boost::lexical_cast<double>(token[i]);
								operand.addressingMode = !ISARRAY;
								operand.value = value_;

							}

							inst.operands.push_back(operand);
						}
						catch (boost::bad_lexical_cast &)
						{
							// if it throws, it's not a number.
							programIsLoaded = false;
							throw InstructionException(InstructionException::NOT_OPERAND, token[i], line_no);
						}
					}
				}
				else
				{
					programIsLoaded = false;
					throw InstructionException(InstructionException::NOT_OPERATOR, token[0], line_no);
				}

				translatedMemory.push_back(inst);
				labelsMap[inst.label] = translatedMemory.size() - 1;
			}

		}

		programIsLoaded = true;
	}

	void VirtualMachine::loadProgram(std::vector<Instruction> program)
	{
		translatedMemory.clear();
		labelsMap.clear();
		translatedMemory = program;
		for (int i = 0; i < translatedMemory.size(); i++)
		{
			labelsMap[translatedMemory.at(i).label] = i;
		}
		programIsLoaded = true;
	}

	void VirtualMachine::loadInputBuffer(ArrayData input)
	{
		inputBuffer = input;
	}



	std::string VirtualMachine::printProgram()
	{
		std::string program = "";
		std::for_each(translatedMemory.begin(), translatedMemory.end(), [&](Instruction& inst)
		{
			program += inst.label;
			program += " ";
			program += operatorsBimap.left.find(inst.op)->second.data();
			program += " ";
			std::for_each(inst.operands.begin(), inst.operands.end(), [&](Operand& operand)
			{
				if (operand.addressingMode == ISARRAY)
					program += "a";
				else
					program += "r";

				program += operand.value;
				program += " ";

			});

			program += "\n";
		});
		return program;
	}

	std::string VirtualMachine::printProgram(std::vector<Instruction> programMemory)
	{
		std::string program = "";
		std::for_each(programMemory.begin(), programMemory.end(), [&](Instruction& inst)
		{
			program += std::to_string(inst.label);
			program += " ";
			program += operatorsBimap.left.find(inst.op)->second.data();
			program += " ";
			std::for_each(inst.operands.begin(), inst.operands.end(), [&](Operand& operand)
			{
				if (operand.addressingMode == ISARRAY)
					program += "a";
				else
					program += "r";

				program += cleanNumber(operand.value);
				program += " ";

			});

			program += "\n";
		});
		return program;
	}



	bool VirtualMachine::isProgramLoaded()
	{
		return programIsLoaded;
	}



}