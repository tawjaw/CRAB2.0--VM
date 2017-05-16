#include "VirtualMachine.h"

namespace crab {
	void VirtualMachine::LESS(Operands operands)
	{
		if (operands.size() == 0)
		{
			//less .. r2=(r2<0)
			registers[2] = (registers[2] < 0) ? true : false;
			flagLogical = registers[2];
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//less aX	.. aX[i]=(aX[i]<0) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

				{
					*it = (*it < 0) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}

			}
			else
			{
				//less rX	.. rX=(rX<0)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER] < 0) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			while ((int)operands[1].value < 0)
				operands[1].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//less aX, aY	.. aX[i]=(aX[i]<aY[i])   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]
						< arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]) ? true : false;
					
					flagLogical = 
						flagLogical 
						&& (true  && arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]);
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//less aX, rY	.. aX[i]=(aX[i]<rY)	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					*it = (*it < registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//less rX, aY	.. rX=(rX<sizeOf(aY[]))	size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER] 
					< arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
			else
			{
				//less rX, rY	.. rX=(rX<rY)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER] 
					< registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::EQUL(Operands operands)
	{
		if (operands.size() == 0)
		{
			//equl .. r2=(r2 == 0)
			registers[2] = (registers[2] == 0) ? true : false;
			flagLogical = registers[2];
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//equl aX	.. aX[i]=(aX[i] == 0) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

				{
					*it = (*it == 0) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}

			}
			else
			{
				//equl rX	.. rX=(rX == 0)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER] == 0) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			while ((int)operands[1].value < 0)
				operands[1].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//equl aX, aY	.. aX[i]=(aX[i] == aY[i])   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]
							== arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]) ? true : false;

					flagLogical =
						flagLogical 
						&& (true && arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]);
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//equl aX, rY	.. aX[i]=(aX[i] == rY)	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					*it = (*it == registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//equl rX, aY	.. rX=(rX == sizeOf(aY[]))	size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER]
						== arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
			else
			{
				//equl rX, rY	.. rX=(rX<rY)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER]
						== registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::GREQ(Operands operands)
	{
		if (operands.size() == 0)
		{
			//greq .. r2=(r2 > 0)
			registers[2] = (registers[2] > 0) ? true : false;
			flagLogical = registers[2];
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//greq aX	.. aX[i]=(aX[i] > 0) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

				{
					*it = (*it > 0) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}

			}
			else
			{
				//greq rX	.. rX=(rX > 0)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			while ((int)operands[1].value < 0)
				operands[1].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//greq aX, aY	.. aX[i]=(aX[i] > aY[i])   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]
							> arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]) ? true : false;

					flagLogical =
						flagLogical
						&& (true && arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]);
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//greq aX, rY	.. aX[i]=(aX[i] > rY)	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					*it = (*it > registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
					flagLogical = flagLogical && (true && *it);
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//greq rX, aY	.. rX=(rX > sizeOf(aY[]))	size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER]
						> arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
			else
			{
				//greq rX, rY	.. rX=(rX > rY)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(registers[(int)operands[0].value % REGISTER_NUMBER]
						> registers[(int)operands[1].value % REGISTER_NUMBER]) ? true : false;
				flagLogical = registers[(int)operands[0].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
}