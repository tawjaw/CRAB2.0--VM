/*************************************************************\
	func_math_operators.h
	Author: Tawfiq Jawhar

//This file contains the functions implemnenting 
//the mathematical instructions of the VM 
/*********************************************************/
#include"common.h"
#include "VirtualMachine.h"

#include <cmath>

namespace crab {
#define PI 3.14159265358979323846  /* pi */

	void VirtualMachine::ADD(Operands operands)
	{
		if (operands.size() == 0)
		{
			//add .. r0++
			registers[0]++;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//add aX	.. aX[i]++ for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size); ++it)

					*it += 1;

				//for(int i =0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size ; i++)
					//arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]++;
			}
			else
			{
				//add rX	.. rX++
				registers[(int)operands[0].value % REGISTER_NUMBER]++;
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
				//ADD aX, aY	.. aX[i]+=aY[i]   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] +=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i];


			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//ADD aX, rY	.. aX[i]+=rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it += registers[(int)operands[1].value % REGISTER_NUMBER];

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//ADD rX, aY	.. rX+=sizeOf(aY[])		size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] +=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;
			}
			else
			{
				//ADD rX, rY	.. rX+=rY;
				registers[(int)operands[0].value % REGISTER_NUMBER] +=
					registers[(int)operands[1].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::SUB(Operands operands)
	{
		if (operands.size() == 0)
		{
			//SUB .. r0--
			registers[0]--;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//SUB aX	.. aX[i]-- for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it -= 1;

			}
			else
			{
				//SUB rX	.. rX--
				registers[(int)operands[0].value % REGISTER_NUMBER]--;
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
				//SUB aX, aY	.. aX[i]-=aY[i]   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] -=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i];

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//SUB aX, rY	.. aX[i]+=rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it -= registers[(int)operands[1].value % REGISTER_NUMBER];

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//SUB rX, aY	.. rX-=sizeOf(aY[])		size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] -=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;
			}
			else
			{
				//SUB rX, rY	.. rX-=rY;
				registers[(int)operands[0].value % REGISTER_NUMBER] -=
					registers[(int)operands[1].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::MUL(Operands operands)
	{
		if (operands.size() == 0)
		{
			//MUL .. r0*=2
			registers[0] *= 2;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
		
			if (operands[0].addressingMode == ISARRAY)
			{
				//MUL aX	.. aX[i]*=2 for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it *= 2;

			}
			else
			{
				//MUL rX	.. rX*=2
				registers[(int)operands[0].value % REGISTER_NUMBER] *= 2;
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
				//MUL aX, aY	.. aX[i]*=aY[i]   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] *=
						arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i];
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//MUL aX, rY	.. aX[i]*=rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it *= registers[(int)operands[1].value % REGISTER_NUMBER];

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//MUL rX, aY	.. rX*=sizeOf(aY[])		size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] *=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;
			}
			else
			{
				//MUL rX, rY	.. rX*=rY;
				registers[(int)operands[0].value % REGISTER_NUMBER] *=
					registers[(int)operands[1].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::DIV(Operands operands)
	{
		if (operands.size() == 0)
		{
			//DIV .. r0/=2
			registers[0] /= 2.0;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//DIV aX	.. aX[i]/=2 for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it /= 2.0;
			}
			else
			{
				//DIV rX	.. rX/=2
				registers[(int)operands[0].value % REGISTER_NUMBER] /= 2.0;
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
				//DIV aX, aY	.. aX[i]/=aY[i]   for all used i in aX and aY .. N/0 == 1/N
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] == 0)
					{
						if (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] != 0)

							arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
							1 / arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i];
					}
					else
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] /=
						arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i];
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//DIV aX, rY	.. aX[i]/=rY	for all used i in aX .. N/0 == 1/N
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
					{
						if (*it != 0)
							*it = 1 / (*it);
					}
					else
						*it /= registers[(int)operands[1].value % REGISTER_NUMBER];
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//DIV rX, aY	.. rX/=sizeOf(aY[])		size used of aY and not maximum size of the register .. N/0 == 1/N
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size == 0)
				{
					if (registers[(int)operands[0].value % REGISTER_NUMBER] != 0)

						registers[(int)operands[0].value % REGISTER_NUMBER] =
						1 / registers[(int)operands[0].value % REGISTER_NUMBER];
				}
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] /=
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;

			}
			else
			{
				//DIV rX, rY	.. rX/=rY .. N/0 == 1/N
				if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
				{
					if (registers[(int)operands[0].value % REGISTER_NUMBER] != 0)

						registers[(int)operands[0].value % REGISTER_NUMBER] =
						1 / registers[(int)operands[0].value % REGISTER_NUMBER];
				}
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] /=
					registers[(int)operands[1].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::IDIV(Operands operands)
	{
		if (operands.size() == 0)
		{
			//IDIV .. r0 = (int) r0/2
			registers[0] = (int)(registers[0] / 2.0);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			
			if (operands[0].addressingMode == ISARRAY)
			{
				//IDIV aX	.. aX[i] = (int) aX[i]/2 for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = (int)(*it / 2.0);

			}
			else
			{
				//IDIV rX	.. rX = (int)rX/2
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)(registers[(int)operands[0].value % REGISTER_NUMBER] / 2.0);
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
				//IDIV aX, aY	.. aX[i]=(int) aX[i]/aY[i]   for all used i in aX and aY .. N/0 == 1/N
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] == 0)
					{
						if (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] != 0)

							arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
							(int)(1 / arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]);
					}
					else
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(int)(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]
						/ arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]);
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//IDIV aX, rY	.. aX[i]= (int) aX[i]/rY	for all used i in aX .. N/0 == 1/N
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
					{
						if (*it != 0)
							*it = (int)(1 / (*it));
					}
					else
						*it = (int)(*it / registers[(int)operands[1].value % REGISTER_NUMBER]);
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//IDIV rX, aY	.. rX = (int) rX/sizeOf(aY[])		size used of aY and not maximum size of the register .. N/0 == 1/N
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size == 0)
				{
					if (registers[(int)operands[0].value % REGISTER_NUMBER] != 0)

						registers[(int)operands[0].value % REGISTER_NUMBER] =
						(int)(1 / registers[(int)operands[0].value % REGISTER_NUMBER]);
				}
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)(registers[(int)operands[0].value % REGISTER_NUMBER]
					/ arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size);

			}
			else
			{
				//IDIV rX, rY	.. rX = (int) rX/rY .. N/0 == 1/N
				if (registers[(int)operands[1].value % REGISTER_NUMBER] == 0)
				{
					if (registers[(int)operands[0].value % REGISTER_NUMBER] != 0)

						registers[(int)operands[0].value % REGISTER_NUMBER] =
						(int)(1 / registers[(int)operands[0].value % REGISTER_NUMBER]);
				}
				else
					registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)(registers[(int)operands[0].value % REGISTER_NUMBER]
					/ registers[(int)operands[1].value % REGISTER_NUMBER]);
			}

		}
		pc++;	//increment pc
	}

	///can not divide by zero
	void VirtualMachine::IREM(Operands operands)
	{
		if (operands.size() == 0)
		{
			//IREM .. r0 = r0 % 2
			registers[0] = (int)registers[0] % 2;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//IREM aX	.. aX[i] = (int) aX[i] % 2 for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = (int)*it % 2;
			}
			else
			{
				//IREM rX	.. rX = (int)rX % 2
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)registers[(int)operands[0].value % REGISTER_NUMBER] % 2;
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
				//IREM aX, aY	.. aX[i]=(int) aX[i] % aY[i]   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if ((int)arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] != 0)

						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						(int)arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]
						% (int)arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i];
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//IREM aX, rY	.. aX[i]= (int) aX[i] % rY	for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if ((int)registers[(int)operands[1].value % REGISTER_NUMBER] != 0)

						*it = (int)*it % (int)registers[(int)operands[1].value % REGISTER_NUMBER];
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//IREM rX, aY	.. rX = (int) rX % sizeOf(aY[])		size used of aY and not maximum size of the register 
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size != 0)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)registers[(int)operands[0].value % REGISTER_NUMBER]
					% arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;

			}
			else
			{
				//IREM rX, rY	.. rX = (int) rX % (int) rY 
				if ((int)registers[(int)operands[1].value % REGISTER_NUMBER] != 0)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					(int)registers[(int)operands[0].value % REGISTER_NUMBER]
					% (int)registers[(int)operands[1].value % REGISTER_NUMBER];
			}
		}
		pc++;	//increment pc
	}
	void VirtualMachine::ABS(Operands operands)
	{
		if (operands.size() == 0)
		{
			//abs .. r0 = |r0| 
			registers[0] = abs(registers[0]);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//abs aX	.. aX[i] = |aX[i]| for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = abs(*it);
			}
			else
			{
				//abs rX	.. rX = |rX|
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					abs(registers[(int)operands[0].value % REGISTER_NUMBER]);
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
				//abs aX, aY	.. aX[i] = |aY[i]|   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						abs(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]);
				}
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//abs aX, rY	.. aX[i] = |rY|	for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin() +
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					*it = abs(registers[(int)operands[1].value % REGISTER_NUMBER]);
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//abs rX, aY	.. rX = |sizeOf(aY[])|		size used of aY and not maximum size of the register 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					std::abs(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size);
			}
			else
			{
				//abs rX, rY	.. rX = |rY| 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					std::abs(registers[(int)operands[1].value % REGISTER_NUMBER]);
			}
		}
		pc++;	//increment pc	
	}

	///takes the smaller number between the two operands as min 
	void VirtualMachine::RND(Operands operands)
	{
		if (operands.size() == 0)
		{
			//rnd .. r0 = rnd[0, 10]	 
			registers[0] = rng.getRandom(0.0f, 10.0f);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//rnd aX	.. aX[i] = rnd[0, 10]; for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = rng.getRandom(0.0f, *it);
			}
			else
			{
				//rnd rX	.. rX=rnd[0, rX];
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					rng.getRandom(0.0f, registers[(int)operands[0].value % REGISTER_NUMBER]);
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
				//rnd aX, aY	.. aX[i] = rnd(aX[i],aY[i])   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
					rng.getRandom(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i],
						arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]);
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//rnd aX, rY	.. aX[i] = rnd[0,rY]	for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = rng.getRandom(0.0f, registers[(int)operands[1].value % REGISTER_NUMBER]);
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//rnd rX, aY	.. rX = rnd[0, sizeOf(aY[])]		size used of aY and not maximum size of the register 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					rng.getRandom(0, arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size);
			}
			else
			{
				//rnd rX, rY	.. rX = rnd[rX, rY] 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					rng.getRandom(registers[(int)operands[0].value % REGISTER_NUMBER], registers[(int)operands[1].value % REGISTER_NUMBER]);
			}
		}
		pc++;	//increment pc	
	}
	///Value representing an angle expressed in degrees
	void VirtualMachine::SIN(Operands operands)
	{
		if (operands.size() == 0)
		{
			//sin .. r0 = sin(r0)	 
			registers[0] = sin(registers[0] * PI / 180);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//sin aX	.. aX[i] = sin(aX[i]) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = sin(*it * PI / 180);
			}
			else
			{
				//sin rX	.. rX = sin(rX)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					sin(registers[(int)operands[0].value % REGISTER_NUMBER] * PI / 180);
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
				//sin aX, aY	.. aX[i] = sin(aY[i])   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
					sin(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] * PI / 180);
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//sin aX, rY	.. aX[i] = sin(rY)	for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = sin(registers[(int)operands[1].value % REGISTER_NUMBER] * PI / 180);
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//sin rX, aY	.. rX = sin(sizeOf(aY[]))		size used of aY and not maximum size of the register 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					sin(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size * PI / 180);
			}
			else
			{
				//sin rX, rY	.. rX = sin(rY) 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					sin(registers[(int)operands[1].value % REGISTER_NUMBER] * PI / 180);
			}
		}
		pc++;	//increment pc	
	}
	///Value representing an angle expressed in degrees
	void VirtualMachine::COS(Operands operands)
	{
		if (operands.size() == 0)
		{
			//cos .. r0 = sin(r0)	 
			registers[0] = cos(registers[0] * PI / 180);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//cos aX	.. aX[i] = cos(aX[i]) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = cos(*it * PI / 180);
			}
			else
			{
				//cos rX	.. rX = cos(rX)
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					cos(registers[(int)operands[0].value % REGISTER_NUMBER] * PI / 180);
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
				//cos aX, aY	.. aX[i] = cos(aY[i])   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)

					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
					cos(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] * PI / 180);
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//cos aX, rY	.. aX[i] = cos(rY)	for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = cos(registers[(int)operands[1].value % REGISTER_NUMBER] * PI / 180);
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//cos rX, aY	.. rX = cos(sizeOf(aY[]))		size used of aY and not maximum size of the register 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					cos(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size * PI / 180);
			}
			else
			{
				//cos rX, rY	.. rX = cos(rY) 
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					cos(registers[(int)operands[1].value % REGISTER_NUMBER] * PI / 180);
			}
		}
		pc++;	//increment pc	
	}
	///if value not between -1 and 1, the instruction will not do anything
	///return value is an angle in degrees
	void VirtualMachine::ASIN(Operands operands)
	{
		if (operands.size() == 0)
		{
			//asin .. r0 = asin(r0)	 
			if (registers[0] >= -1 && registers[0] <= 1)
				registers[0] = asin(registers[0]) * 180.0 / PI;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//asin aX	.. aX[i] = asin(aX[i]) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (*it >= -1 && *it <= 1)
						*it = asin(*it) * 180.0 / PI;
				}
			}
			else
			{
				//asin rX	.. rX = asin(rX)
				if (registers[(int)operands[0].value % REGISTER_NUMBER] >= -1
					&& registers[(int)operands[0].value % REGISTER_NUMBER] <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					asin(registers[(int)operands[0].value % REGISTER_NUMBER]) * 180.0 / PI;
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
				//asin aX, aY	.. aX[i] = asin(aY[i])   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] >= -1
						&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] <= 1)

						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						asin(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]) * 180.0 / PI;
				}
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//asin aX, rY	.. aX[i] = asin(rY)		for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (registers[(int)operands[1].value % REGISTER_NUMBER] >= -1
						&& registers[(int)operands[1].value % REGISTER_NUMBER] <= 1)

						*it = asin(registers[(int)operands[1].value % REGISTER_NUMBER]) * 180.0 / PI;
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//asin rX, aY	.. rX = asin(sizeOf(aY[]))		size used of aY and not maximum size of the register 
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size >= -1
					&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					asin(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size) * 180.0 / PI;
			}
			else
			{
				//asin rX, rY	.. rX = asin(rY) 
				if (registers[(int)operands[1].value % REGISTER_NUMBER] >= -1
					&& registers[(int)operands[1].value % REGISTER_NUMBER] <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					asin(registers[(int)operands[1].value % REGISTER_NUMBER]) * 180.0 / PI;
			}
		}
		pc++;	//increment pc	
	}
	///if value not between -1 and 1, the instruction will not do anything
	///return value is an angle in degrees
	void VirtualMachine::ACOS(Operands operands)
	{
		if (operands.size() == 0)
		{
			//acos .. r0 = acos(r0)	 
			if (registers[0] >= -1 && registers[0] <= 1)
				registers[0] = acos(registers[0]) * 180.0 / PI;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//acos aX	.. aX[i] = acos(aX[i]) for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (*it >= -1 && *it <= 1)
						*it = acos(*it) * 180.0 / PI;
				}
			}
			else
			{
				//acos rX	.. rX = acos(rX)
				if (registers[(int)operands[0].value % REGISTER_NUMBER] >= -1
					&& registers[(int)operands[0].value % REGISTER_NUMBER] <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					acos(registers[(int)operands[0].value % REGISTER_NUMBER]) * 180.0 / PI;
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
				//acos aX, aY	.. aX[i] = acos(aY[i])   for all used i in aX and aY 
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] >= -1
						&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] <= 1)

						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						acos(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]) * 180.0 / PI;

				}
			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//acos aX, rY	.. aX[i] = acos(rY)		for all used i in aX 
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (registers[(int)operands[1].value % REGISTER_NUMBER] >= -1
						&& registers[(int)operands[1].value % REGISTER_NUMBER] <= 1)

						*it = acos(registers[(int)operands[1].value % REGISTER_NUMBER]) * 180.0 / PI;
				}
			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//acos rX, aY	.. rX = acos(sizeOf(aY[]))		size used of aY and not maximum size of the register 
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size >= -1
					&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					acos(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size) * 180.0 / PI;
			}
			else
			{
				//acos rX, rY	.. rX = acos(rY) 
				if (registers[(int)operands[1].value % REGISTER_NUMBER] >= -1
					&& registers[(int)operands[1].value % REGISTER_NUMBER] <= 1)

					registers[(int)operands[0].value % REGISTER_NUMBER] =
					acos(registers[(int)operands[1].value % REGISTER_NUMBER]) * 180.0 / PI;
			}
		}
		pc++;	//increment pc	
	}

	void VirtualMachine::POW(Operands operands)
	{
		if (operands.size() == 0)
		{
			//pow .. r0 = r0 ^ 2
			registers[0] = pow(registers[0], 2);
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//pow aX	.. aX[i] = aX[i]^2 for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = pow(*it, 2);

			}
			else
			{
				//pow rX	.. rX = rX^2
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					pow(registers[(int)operands[0].value % REGISTER_NUMBER], 2);
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
				//pow aX, aY	.. aX[i] = aX[i] ^ aY[i]   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						pow(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i],
							arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]);
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//pow aX, rY	.. aX[i] = aX[i]^rY	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)

					*it = pow(*it, registers[(int)operands[1].value % REGISTER_NUMBER]);

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//pow rX, aY	.. rX = rX^sizeOf(aY[])		size used of aY and not maximum size of the register
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					pow(registers[(int)operands[0].value % REGISTER_NUMBER],
						arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size);
			}
			else
			{
				//pow rX, rY	.. rX = rX^rY;
				registers[(int)operands[0].value % REGISTER_NUMBER] =
					pow(registers[(int)operands[0].value % REGISTER_NUMBER],
						registers[(int)operands[1].value % REGISTER_NUMBER]);
			}

		}
		pc++;	//increment pc
	}

	///the value passed to log should be positive. if log(x) is in the dominator then x should not be equal to 1
	void VirtualMachine::LOG(Operands operands)
	{
		if (operands.size() == 0)
		{
			//log .. r0 = log2 r0
			if (registers[0] > 0)
			{
				registers[0] = log2(registers[0]);
				if (std::isnan(registers[0]))
					registers[0] = 0;
				if (!std::isfinite(registers[0]))
					registers[0] = 0;
			
			}
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//log aX	.. aX[i]=log2(aX[i])  for all used i in aX
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin()
					+ arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (*it > 0)
						*it = log2(*it);
					if (std::isnan(*it))
						*it = 0;
					if (!std::isfinite(*it))
						*it = 0;
				}
			}
			else
			{
				//log rX	.. rX=log2(rX)
				if (registers[(int)operands[0].value % REGISTER_NUMBER] > 0)
				{
					registers[(int)operands[0].value % REGISTER_NUMBER] =
						log2(registers[(int)operands[0].value % REGISTER_NUMBER]);
					if (std::isnan(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
					if (!std::isfinite(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
				}
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
				//log aX, aY	.. aX[i]=log aY[i] (aX[i])   for all used i in aX and aY
				for (auto i = 0; (i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size
					&& i < arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size); i++)
				{
					if (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] > 0
						&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] > 0
						&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i] != 1)
					{
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
							log2(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i])
							/ log2(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[i]);
						if (std::isnan(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]))
							arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = 0;
						if (!std::isfinite(arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i]))
							arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = 0;
					}
				}

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//log aX, rY	.. aX[i]=log rY (aX[i])	for all used i in aX	
				for (auto it = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin();
					it != arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue.begin() +
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; ++it)
				{
					if (*it > 0 && registers[(int)operands[1].value % REGISTER_NUMBER] > 0
						&& registers[(int)operands[1].value % REGISTER_NUMBER] != 1)
					{
						*it = log2(*it) / log2(registers[(int)operands[1].value % REGISTER_NUMBER]);
						if (std::isnan(*it))
							*it = 0;
						if (!std::isfinite(*it))
							*it = 0;
					}
				}

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//log rX, aY	.. rX= log sizeOf(aY[]) (rX)		size used of aY and not maximum size of the register
				if (registers[(int)operands[0].value % REGISTER_NUMBER] > 0
					&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size > 0
					&& arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size != 1)
				{
					registers[(int)operands[0].value % REGISTER_NUMBER] =
						log2(registers[(int)operands[0].value % REGISTER_NUMBER])
						/ log2(arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size);
					if (std::isnan(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
					if (!std::isfinite(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
				}
			}
			else
			{
				//log rX, rY	.. rX = log rY (rX);
				if (registers[(int)operands[0].value % REGISTER_NUMBER] > 0
					&& registers[(int)operands[1].value % REGISTER_NUMBER] > 0
					&& registers[(int)operands[1].value % REGISTER_NUMBER] != 0)
				{
					registers[(int)operands[0].value % REGISTER_NUMBER] =
						log2(registers[(int)operands[0].value % REGISTER_NUMBER])
						/ log2(registers[(int)operands[1].value % REGISTER_NUMBER]);
					if (std::isnan(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
					if(!std::isfinite(registers[(int)operands[0].value % REGISTER_NUMBER]))
						registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
				}
			}

		}
		pc++;	//increment pc
	}
}