#include"common.h"
#include "VirtualMachine.h"

namespace crab {
	void VirtualMachine::AND(Operands operands)
	{
		bool left;
		bool right;
		if (operands.size() == 0)
		{
			//and .. r2 = r2 && r3
			left = (registers[2] > 0) ? true : false;
			right = (registers[3] > 0) ? true : false;

			registers[2] = left && right;
			flagLogical = left && right;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//and aX	.. aX[i]=aX[i] && aX+1[i] for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.end())
					{
						left = (*it > 0) ? true : false;
						right = (*(it + 1) > 0) ? true : false;

						*it = left && right;
						flagLogical = flagLogical && (true && (left && right));
					}
				}

			}
			else
			{
				//and rX	.. rX && rX+1
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[0].value + 1 % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] = left && right;
				flagLogical = left && right;
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
				//and aX, aY	.. aX[i]=aX[i] && aY[i]  for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					left = (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;
					right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						left && right;
					flagLogical = flagLogical && (true && (left && right));
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//and aX, rY	.. aX[i]=aX[i] && rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					left = (*it > 0) ? true : false;
					right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

					*it = left && right;
					flagLogical = flagLogical && (true && (left && right));
				}

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//and rX, aY	.. rX=rX && sizeOf(aY[])	size used of aY and not maximum size of the register
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					left && right;
				flagLogical = left && right;
			}
			else
			{
				//and rX, rY	.. rX=rX && rY;
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					left && right;
				flagLogical = left && right;
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::ORR(Operands operands)
	{
		bool left;
		bool right;
		if (operands.size() == 0)
		{
			//orr .. r2 = r2 && r3
			left = (registers[2] > 0) ? true : false;
			right = (registers[3] > 0) ? true : false;

			registers[2] = left || right;
			flagLogical = left || right;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//orr aX	.. aX[i]=aX[i] || aX+1[i] for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.end())
					{
						left = (*it > 0) ? true : false;
						right = (*(it + 1) > 0) ? true : false;

						*it = left || right;
						flagLogical = flagLogical && (true && (left || right));
					}
				}

			}
			else
			{
				//orr rX	.. rX|| rX+1
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[0].value + 1 % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] = left || right;
				flagLogical = left || right;
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
				//orr aX, aY	.. aX[i]=aX[i] || aY[i]  for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					left = (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;
					right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						left || right;
					flagLogical = flagLogical && (true && (left || right));
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//orr aX, rY	.. aX[i]=aX[i] || rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					left = (*it > 0) ? true : false;
					right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

					*it = left || right;
					flagLogical = flagLogical && (true && (left || right));
				}

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//orr rX, aY	.. rX=rX || sizeOf(aY[])	size used of aY and not maximum size of the register
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					left || right;
				flagLogical = left || right;
			}
			else
			{
				//orr rX, rY	.. rX=rX || rY;
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					left || right;
				flagLogical = left || right;
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::XOR(Operands operands)
	{
		bool left;
		bool right;
		if (operands.size() == 0)
		{
			//xor .. r2 = r2 xor r3
			left = (registers[2] > 0) ? true : false;
			right = (registers[3] > 0) ? true : false;

			registers[2] = (left && !right) || (!left && right);
			flagLogical = (left && !right) || (!left && right);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//xor aX	.. aX[i]=aX[i] xor aX+1[i] for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.end())
					{
						left = (*it > 0) ? true : false;
						right = (*(it + 1) > 0) ? true : false;

						*it = (left && !right) || (!left && right);
						flagLogical = flagLogical && (true && ((left && !right) || (!left && right)));
					}
				}

			}
			else
			{
				//xor rX	.. rX xor rX+1
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[0].value + 1 % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] = (left && !right) || (!left && right);
				flagLogical = (left && !right) || (!left && right);
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
				//xor aX, aY	.. aX[i]=aX[i] xor aY[i]  for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					left = (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;
					right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false;

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(left && !right) || (!left && right);
					flagLogical = flagLogical && (true && ((left && !right) || (!left && right)));
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//xor aX, rY	.. aX[i]=aX[i] xor rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					left = (*it > 0) ? true : false;
					right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

					*it = (left && !right) || (!left && right);
					flagLogical = flagLogical && (true && ((left && !right) || (!left && right)));
				}

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//xor rX, aY	.. rX=rX xor sizeOf(aY[])	size used of aY and not maximum size of the register
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(left && !right) || (!left && right);
				flagLogical = (left && !right) || (!left && right);
			}
			else
			{
				//xor rX, rY	.. rX=rX xor rY;
				left = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
				right = (registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false;

				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(left && !right) || (!left && right);
				flagLogical = (left && !right) || (!left && right);
			}

		}
		pc++;	//increment pc
	}
	///not(X) = -X except not(0) = 1
	void VirtualMachine::NOT(Operands operands)
	{
		if (operands.size() == 0)
		{
			//not .. r2 =!r2
			if (registers[2] == 0)
				registers[2] = 1;
			else
				registers[2] *= -1;

			flagLogical = (registers[0] > 0) ? true : false;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				flagLogical = true;
				//not aX	.. aX[i]=!(aX[i]) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (*it == 0)
						*it = 1;
					else
						*it *= -1;

					flagLogical = flagLogical && (true && ((*it > 0) ? true : false));
				}

			}
			else
			{
				//not rX	.. rX=!(rX)
				if (registers[(int)operands[0].value % REGISTER_NUMBER] == 0)
					registers[(int)operands[0].value % REGISTER_NUMBER] = 1;
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] *= -1;

				flagLogical = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
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
				//not aX, aY	.. aX[i]=!aY[i]   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] == 0)
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = 1;
					else
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] * -1;

					flagLogical = flagLogical && (true 
						&& ((arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] > 0) ? true : false));
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				flagLogical = true;
				//not aX, rY	.. aX[i]=!rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
						*it = 1;
					else
						*it = registers[(int)operands[1].value % REGISTER_NUMBER] * -1;

					flagLogical = flagLogical && (true && ((registers[(int)operands[1].value % REGISTER_NUMBER] > 0) ? true : false));
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//not rX, aY	.. rX=!(sizeOf(aY[]))		size used of aY and not maximum size of the register
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size == 0)
					registers[(int)operands[0].value % REGISTER_NUMBER] = 1;
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] =
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size * -1;
				flagLogical = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
			}
			else
			{
				//not rX, rY	.. rX=!(rY)
				if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
					registers[(int)operands[0].value % REGISTER_NUMBER] = 1;
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] =
					registers[(int)operands[1].value % REGISTER_NUMBER] * -1;

				flagLogical = (registers[(int)operands[0].value % REGISTER_NUMBER] > 0) ? true : false;
			}

		}
		pc++;	//increment pc
	}
}