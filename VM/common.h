
/*************************************************************\
common.h
Author: Tawfiq Jawhar

//this file contains common type definitions and enums used
//through out the project
/*********************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cfloat> // DBL_MAX
#include <cmath> // std::nextafter
#include "Operator.h"
#include <string>

namespace crab {

#define ISARRAY true
	//maximum size of the VM's array registers and buffers
#define MAX_ARRAY_SIZE 200
#define REGISTER_NUMBER 4

	//struct of an array register/buffer int for the size of the array used
	//float is the type of data saved and the size of the array is the maximum size defined for all arrays in the VM
	struct ArrayData
	{
		int size;
		std::array<double, MAX_ARRAY_SIZE> arrayValue;
	};



	//struct defines the operand used in the translated memory
	//bool represents the addressing mode.. true = array, false = register or scalar 
	struct Operand
	{
		bool addressingMode;
		double value;
	};

	typedef std::vector<Operand> Operands;	//vector of Operand

											/*struct that holds an instruction with its operands in a translated memory*/
	struct Instruction
	{
		Operator::OP op;
		unsigned int label;
		Operands operands;

	};

	class RNG
	{
	public:
		RNG::RNG() : gen(std::random_device()()) {} // Seeds the mt19937.

		double getRandom(double x, double y)
		{
			double min, max;
			if (x > y)
			{
				max = x;
				min = y;
			}
			else
			{
				max = y;
				min = x;
			}
			std::uniform_real_distribution<double> dis(min, std::nextafter(max, DBL_MAX));
			double random = dis(gen);
			return random;
		}

		int getRandom(int x, int y)
		{
			int min, max;
			if (x > y)
			{
				max = x;
				min = y;
			}
			else
			{
				max = y;
				min = x;
			}
			std::uniform_int_distribution<int> dis(min, max);
			int random = dis(gen);
			return random;
		}
	private:
		std::mt19937 gen;
	};



	class InstructionException : public std::exception {
		int line_no;
		ci_string token_error;
	public:
		InstructionException(const char* msg, ci_string token_error_, int line_)
			: std::exception(msg), token_error("'" + token_error_ + "'"), line_no(line_) { }

		static constexpr const char* NOT_OPERATOR = " not a crab operator.";
		static constexpr const char* NOT_OPERAND = " not a crab operand.";


		int getLineNumber() const { return line_no; }
		const char* getTokenError() { return token_error.data(); }

	};


	class ProgramGenerator
	{
	public:
		typedef std::array<unsigned int, 34> InstructionProbability;

		ProgramGenerator()
		{
			maxSettingValue = 0;
			int defaultProb = 10;
			for (int i = 0; i < settings.size(); i++)
			{
				settings[i] = std::make_pair(maxSettingValue, maxSettingValue + defaultProb);
				maxSettingValue += defaultProb;
			}
		}
		void setProbabilities(InstructionProbability prob)
		{
			maxSettingValue = 0;
			for (int i = 0; i < prob.size(); i++)
			{
				settings[i] = std::make_pair(maxSettingValue, maxSettingValue + prob[i]);
				maxSettingValue += prob[i];
			}
		}
		std::vector<Instruction> generateRandomProgram(int min, int max)
		{
			std::vector<Instruction> randomProgram;

			if (min < 0)	min = 0;
			if (max > 5000)	max = 5000;

			int numberOfInstructions = random.getRandom(min, max);

			for (int i = 0; i < numberOfInstructions; i++)
				randomProgram.push_back(generateRandomInstruction(i * 100));

			return randomProgram;
		}

		crab::Instruction generateRandomInstruction(int label)
		{
			Instruction tempInstruction;
			tempInstruction.label = label;

			int randomOperator;
			int randomValue = random.getRandom(0, maxSettingValue);
			for (int i = 0; i < settings.size(); i++)
			{
				if (settings[i].first != settings[i].second)
				{
					if (randomValue < settings[i].second)
					{
						randomOperator = i;
						break;
					}
				}
			}
			Operator::OP randomOperatorEnum = static_cast<Operator::OP>(randomOperator);

			tempInstruction.op = randomOperatorEnum;

			int randomNumberOfOperands = random.getRandom(0, 2);
			for (int j = 0; j < randomNumberOfOperands; j++)
			{
				Operand tempOperand;
				int randomAddressingMode = random.getRandom(0, 1);
				tempOperand.addressingMode = static_cast<bool> (randomAddressingMode);

				int randomValue = random.getRandom(0, 3);
				tempOperand.value = randomValue;

				tempInstruction.operands.push_back(tempOperand);

			}
			return tempInstruction;
		}

		crab::Operator::OP generateRandomOperator()
		{
			int randomOperator;
			int randomValue = random.getRandom(0, maxSettingValue);
			for (int i = 0; i < settings.size(); i++)
			{
				if (settings[i].first != settings[i].second)
				{
					if (randomValue < settings[i].second)
					{
						randomOperator = i;
						break;
					}
				}
			}
			return static_cast<Operator::OP>(randomOperator);
		}

		crab::Operand generateRandomOperand()
		{
			Operand tempOperand;
			int randomAddressingMode = random.getRandom(0, 1);
			tempOperand.addressingMode = static_cast<bool> (randomAddressingMode);

			int randomValue = random.getRandom(0, 3);
			tempOperand.value = randomValue;
			return tempOperand;
		}

	private:
		std::array<std::pair<int, int>, 34> settings;
		int maxSettingValue;
		RNG	random;
	};

	std::string cleanNumber(double f);



}
