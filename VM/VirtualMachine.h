#pragma once
/*************************************************************\
VirtualMachine.h
Author: Tawfiq Jawhar

//This file contains //TODO
/*********************************************************/

#include "common.h"
#include <iostream>
#include <functional>
#include "ParsingHelper.h"
#include <map>

namespace crab {

	class VirtualMachine
	{
	private:

		RNG rng;									//random number generator

		bool programIsLoaded;						//true if program is loaded correctly into translatedMemory

		std::vector<Instruction> translatedMemory;	//holds a group of instructions that represent the program

													/******VM components******/

		std::array<double, 4> registers;				//4 registers of type float

		std::array<ArrayData, 4> arrayRegisters;	//4 array registers 

		bool flagLogical;							//logical flag of type bool

		std::vector<double> stack1;					//2 stacks 
		std::vector<double> stack2;

		ArrayData inputBuffer;						//input buffer
		ArrayData outputBuffer;						//output buffer

		std::array<double, MAX_ARRAY_SIZE> memory;	//none protected memory. initialized to 0 at the beginning. 

		bool flagIf;								//flagIf used when 'ifel' instruction is using the control registers	
		bool flagWhile;								//flagWhile used when 'whil' instruction is using control registers

		unsigned int controlRegister1;						//control registers can only be set by the 'ifel' and 'whil' operators
		unsigned int controlRegister2;
		unsigned int controlRegister3;

		bool flagControl1;							//control registers flags to know if the values are set in the controlRegisters
		bool flagControl2;
		bool flagControl3;

		unsigned int pc;										//program counter. VM starts with pc = 0
		unsigned int mp;										//memory pointer. VM starts with mp = 0
		int instructionsExecuted;

		/**** Function Type Definition ****
		every operator will have a function of this type
		when the function is called a vector of operands will be passed
		and the instruction will be executed in the VM
		**********************************/

		typedef void(VirtualMachine::*FunctionOfOperator)(Operands);

		/**** Map of Pointer Functions to CRAB Operator ****
		a map is used to link operator functions with the enum representing the operator in the instruction
		to call the function representing the ADD operator:
		instructionFunctions[ADD](Operands);
		this will execute the ADD instructions with the operands passed to the function
		**********************************/

		std::map<Operator::OP, FunctionOfOperator> instructionFunctions;

		/**** Bidirectional Map of enum operator and ci_string ****
		bidirectional map to get ci_string (case insensitive string) of every enum operator
		used when loading a program from a stringstream or when printing an operator to a stringstream
		**********************************/

		Operator::op_bimap operatorsBimap;

		/**** Map of int label and int index ****
		a map to get the index of an instruction from translatedMemory by the instruction's label
		the map will be created when the program is loading
		and it will be used whenever the VM needs to find an instruction based on its label
		*********************************/

		std::map<int, int> labelsMap;


		/**** Operator Functions ****/

		void
			//REG/ARRAY<->BUFFERS TRANSFER
			GETB(Operands operands), PUTB(Operands operands),
			//REG/ARRAY<->MEMORY TRANSFER
			SETP(Operands operands), MOVP(Operands operands),
			GETM(Operands operands), PUTM(Operands operands),
			//REG/ARRAYIMMEDIATE ASSIGN
			ASSN(Operands operands),
			//REG/ARRAY<->REG/ARRAY MOVES
			COPY(Operands operands), SWAP(Operands operands),
			//REG/ARRAY<->STACK MOVES
			PUSH(Operands operands), POP(Operands operands),
			//MATHEMATICAL INSTRUCTIONS
			ADD(Operands operands), SUB(Operands operands), MUL(Operands operands),
			DIV(Operands operands), IDIV(Operands operands), IREM(Operands operands),
			ABS(Operands operands), RND(Operands operands), SIN(Operands operands),
			COS(Operands operands), ASIN(Operands operands), ACOS(Operands operands),
			POW(Operands operands), LOG(Operands operands),
			//LOGICAL INSTRUCTIONS
			AND(Operands operands), ORR(Operands operands),
			XOR(Operands operands), NOT(Operands operands),
			//COMPARISON INSTRUCTIONS
			LESS(Operands operands), EQUL(Operands operands), GREQ(Operands operands),
			//FLOW CONTROL INSTRUCTIONS 
			IFEL(Operands operands), WHIL(Operands operands);

		/**** VM private methods ****/

		void mapInstructions();								//map every instruction function to its operator enum

	public:

		VirtualMachine();
		void initializeComponenets();						//initialize all buffers and registers to 0 and reset pc
		void runVm();										//execute the whole program
		bool executeNextInstruction();						//execute next instruction where address of instruction = pc
		void printVmComponents();							//print the components of the VM
		void loadProgram(ci_istringstream& iss);			//translate a program from a stringstream and load to the translated_memory
		void loadProgram(std::vector<Instruction> program); //load a program to memory
		void loadInputBuffer(ArrayData input);		//translate a string of numbers seperated by a space to the input buffer
		std::string printProgram();							//returns string of the text program in memory
		std::string printProgram(std::vector<Instruction>);	//returns string of the text program of memory passed
		bool isProgramLoaded();								//returns true if program is loaded successfully to translated_memory

															/**** get methods for VM components ****/
		std::vector<Instruction> getLoadedProgram() { if (programIsLoaded) return translatedMemory; }

		int	getPc() { return pc; }
		int getMp() { return mp; }
		double getRegister0() { return registers[0]; }
		double getRegister1() { return registers[1]; }
		double getRegister2() { return registers[2]; }
		double getRegister3() { return registers[3]; }

		ArrayData getArrayRegister0() { return arrayRegisters[0]; }
		ArrayData getArrayRegister1() { return arrayRegisters[1]; }
		ArrayData getArrayRegister2() { return arrayRegisters[2]; }
		ArrayData getArrayRegister3() { return arrayRegisters[3]; }

		ArrayData getInputBuffer() { return inputBuffer; }
		ArrayData getOutputbuffer() { return outputBuffer; }

		bool getFlagLogical() { return flagLogical; }
		bool getFlagIf() { return flagIf; }
		bool getFlagWhile() { return flagWhile; }

		bool getFlagControl1() { return flagControl1; }
		bool getFlagControl2() { return flagControl2; }
		bool getFlagControl3() { return flagControl3; }

		int getControlRegister1() { return controlRegister1; }
		int getControlRegister2() { return controlRegister2; }
		int getControlRegister3() { return controlRegister3; }

		std::array<double, MAX_ARRAY_SIZE> getMemory() { return memory; }

	};

}