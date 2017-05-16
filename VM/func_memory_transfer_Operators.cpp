#include"common.h"
#include "VirtualMachine.h"
//
namespace crab {
	void VirtualMachine::GETB(Operands operands)
	{
		if (operands.size() == 0)
		{
			//getb	r0=i[0];  	
			if (inputBuffer.size > 0)
				registers[0] = inputBuffer.arrayValue[0];
			
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//getb aX	aX[0..]=i[0..]; 
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER] = inputBuffer;
				
			}
			else
			{
				//getb rX	rX=i[0];
				if (inputBuffer.size > 0)
					registers[(int)operands[0].value % REGISTER_NUMBER] = inputBuffer.arrayValue[0];
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			while ((int)operands[1].value < 0)
				operands[1].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//getb aX, ?Y = getb aX, rY
				if (inputBuffer.size > abs(registers[(int)operands[1].value % REGISTER_NUMBER]))
				{
										
					for (int i = (int)abs(registers[(int)operands[1].value % REGISTER_NUMBER]); i < MAX_ARRAY_SIZE; i++)
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
						inputBuffer.arrayValue[i];
				}

			}
			else if (operands[0].addressingMode == !ISARRAY)
			{
				//getb rX, ?Y = getb rX, rY
				if (inputBuffer.size > abs(registers[(int)operands[1].value % REGISTER_NUMBER]))
				{
					registers[(int)operands[0].value % REGISTER_NUMBER] = 
						inputBuffer.arrayValue[(int)abs(registers[(int)operands[1].value % REGISTER_NUMBER])];
				}
			}
			
		}
		pc++;	//increment pc
	}
	void VirtualMachine::PUTB(Operands operands)
	{
		if (operands.size() == 0)
		{
			//putb	o[0]=r0;	
			if (outputBuffer.size == 0)
				outputBuffer.size = 1;
			
			outputBuffer.arrayValue[0] = registers[0];

		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//putb aX	o[0..]=aX[0..]; 
				outputBuffer = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER];

			}
			else
			{
				//putb rX	o[0]=rX;
				if (outputBuffer.size == 0)
					outputBuffer.size = 1;

				outputBuffer.arrayValue[0] = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;
			while ((int)operands[1].value < 0)
				operands[1].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//putb aX, ?Y = putb aX, rY
				if(outputBuffer.size > abs(registers[(int)operands[1].value % REGISTER_NUMBER]))
				{
								

					for (int i = (int)abs(registers[(int)operands[1].value % REGISTER_NUMBER]); i < MAX_ARRAY_SIZE; i++)
						outputBuffer.arrayValue[i] = 
						arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i];
				}

			}
			else 
			{
				//putb rX, ?Y = putb rX, rY
				if (outputBuffer.size > abs(registers[(int)operands[1].value % REGISTER_NUMBER]))
				{
					outputBuffer.arrayValue[(int)abs(registers[(int)operands[1].value % REGISTER_NUMBER])] = 
						registers[(int)operands[0].value % REGISTER_NUMBER];
				}
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::SETP(Operands operands)
	{

		if (operands.size() == 0)
		{
			//setp	mp=r0; 
			mp = abs((int)registers[0]) % MAX_ARRAY_SIZE;
		}
		else 
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			//setp ?X	mp=rX;  
			mp = abs((int) registers[(int)operands[0].value % REGISTER_NUMBER]) % MAX_ARRAY_SIZE;
		}
		
		pc++;	//increment pc
	}
	void VirtualMachine::MOVP(Operands operands)
	{
		if (operands.size() == 0)
		{
			//movp	mp++; 
			int temp = mp;
			temp++;
			while (temp < 0)
				temp += MAX_ARRAY_SIZE;
			mp = temp % MAX_ARRAY_SIZE;
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			//movp ?X	mp+=rX; 
			int temp = mp;
			temp += registers[(int)operands[0].value % REGISTER_NUMBER];
			while (temp < 0)
				temp += MAX_ARRAY_SIZE;
			mp = temp % MAX_ARRAY_SIZE;
		}

		pc++;	//increment pc
	}
	void VirtualMachine::GETM(Operands operands)
	{
		if (operands.size() == 0)
		{
			//getm	r0=m[mp];
			registers[0] = memory[mp];
		}
		else 
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//getm aX	aX[0..]=m[mp..];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size =
					memory.size() - mp;

				for (int i = 0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; i++)
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] =
					memory[mp+i];

			}
			else
			{
				//getm rX	rX=m[mp];
				registers[(int)operands[0].value % REGISTER_NUMBER] = memory[mp];
			}
		}
	
		pc++;	//increment pc
	}
	void VirtualMachine::PUTM(Operands operands)
	{

		if (operands.size() == 0)
		{
			//putm	m[mp]=r0;
			memory[mp] = registers[0];
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//putm aX	m[mp..]=aX[0..];
				for (int i = mp; i < MAX_ARRAY_SIZE; i++)
					memory[i] = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i - mp];

			}
			else
			{
				//putm rX	m[mp]=rX;
				memory[mp] = registers[(int)operands[0].value % REGISTER_NUMBER];
			}
		}

		pc++;	//increment pc
	}
	void VirtualMachine::ASSN(Operands operands)
	{
		if (operands.size() == 0)
		{
			//assn	r0 = 0;
			registers[0] = 0;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//assn aX		aX[i] = 0;
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size = MAX_ARRAY_SIZE;
				for (int i = 0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; i++)
				{
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = 0;
				}

			}
			else
			{
				//assn rX		rX = 0;
				registers[(int)operands[0].value % REGISTER_NUMBER] = 0;
			}
		}
		else
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//assn aX,	aY		// aX[]=[0,1,2,3.. ,Y];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size =
					std::abs((int)operands[1].value % MAX_ARRAY_SIZE);
				
				for (int i = 0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; i++)
					
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = i;

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
			
				//assn aX,	sY		// aX[i]=Y;		for all i
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size = MAX_ARRAY_SIZE;

				for (int i = 0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; i++)
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = operands[1].value;

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				while ((int)operands[1].value < 0)
					operands[1].value += REGISTER_NUMBER;

				//assn	rX,	aY		// rX= sizeOf(aY[]);
				registers[(int)operands[0].value % REGISTER_NUMBER] = 
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;
			}
			else
			{
				//assn  rX,	sY		// rX=Y;
				registers[(int)operands[0].value % REGISTER_NUMBER] = operands[1].value;
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::COPY(Operands operands)
	{
		if (operands.size() == 0)
		{
			//copy		//r0 = r1
			registers[0] = registers[1];
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//copy aX			// aX[i]=aX+1[i];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER] = arrayRegisters[((int)operands[0].value + 1) % REGISTER_NUMBER];
			}
			else
			{
				//copy rX	//rX=rX+1; (r/a)X+1 mean next register/next array
				registers[(int)operands[0].value % REGISTER_NUMBER] = registers[((int)operands[0].value + 1) % REGISTER_NUMBER];
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
				//copy aX,	aY		// aX[i]=aY[i];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER] = arrayRegisters[(int)operands[1].value % REGISTER_NUMBER];

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//copy aX,	rY		// aX[i]=rY;	
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size = MAX_ARRAY_SIZE;

				for (int i = 0; i < arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size; i++)
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[i] = 
					registers[(int)operands[1].value % REGISTER_NUMBER];

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//copy rX,	aY		// rX=sizeOf(aY[i]);
				registers[(int)operands[0].value % REGISTER_NUMBER] = 
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size;
			}
			else
			{
				//copy rX,	rY		// rX=rY;
				registers[(int)operands[0].value % REGISTER_NUMBER] = registers[(int)operands[1].value % REGISTER_NUMBER];
			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::SWAP(Operands operands)
	{
		if (operands.size() == 0)
		{
			//swap				// r0<=>r1
			double tempValue = registers[0];
			registers[0] = registers[1];
			registers[1] = tempValue;
		}
		else if (operands.size() == 1)
		{
			while ((int)operands[0].value < 0)
				operands[0].value += REGISTER_NUMBER;

			if (operands[0].addressingMode == ISARRAY)
			{
				//swap aX			// aX[]<=>aX+1[];
				ArrayData tempArray = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER] = arrayRegisters[((int)operands[0].value + 1) % REGISTER_NUMBER];
				arrayRegisters[((int)operands[0].value + 1) % REGISTER_NUMBER] = tempArray;

			}
			else
			{
				//swap rX			// rX <=> rX+1;
				double tempValue = registers[(int)operands[0].value % REGISTER_NUMBER];
				registers[(int)operands[0].value % REGISTER_NUMBER] = registers[((int)operands[0].value + 1) % REGISTER_NUMBER];
				registers[((int)operands[0].value + 1) % REGISTER_NUMBER] = tempValue;
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
				//swap aX,	aY		// aX[]<=>aY[];
				ArrayData tempArray = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER];
				arrayRegisters[(int)operands[0].value % REGISTER_NUMBER] = arrayRegisters[(int)operands[1].value % REGISTER_NUMBER];
				arrayRegisters[(int)operands[1].value % REGISTER_NUMBER] = tempArray;

			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{
				//swap aX,	rY		// aX[0] <=> rY;
				if (arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].size > 0)
				{
					double tempValue = arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[0];
					arrayRegisters[(int)operands[0].value % REGISTER_NUMBER].arrayValue[0] = registers[(int)operands[1].value % REGISTER_NUMBER];
					registers[(int)operands[1].value % REGISTER_NUMBER] = tempValue;

				}

			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{
				//swap rX, aY		// rX<=>aY[0];
				if (arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].size > 0)
				{
					double tempValue = arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[0];
					arrayRegisters[(int)operands[1].value % REGISTER_NUMBER].arrayValue[0] = registers[(int)operands[0].value % REGISTER_NUMBER];
					registers[(int)operands[0].value % REGISTER_NUMBER] = tempValue;

				}
			}
			else
			{
				//swap rX,	rY		// rX<=>rY;
				double tempValue = registers[(int)operands[0].value % REGISTER_NUMBER];
				registers[(int)operands[0].value % REGISTER_NUMBER] = registers[((int)operands[1].value) % REGISTER_NUMBER];
				registers[((int)operands[1].value) % REGISTER_NUMBER] = tempValue;

			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::PUSH(Operands operands)
	{
		if (operands.size() == 0)
		{

		}
		else if (operands.size() == 1)
		{
			if (operands[0].addressingMode == ISARRAY)
			{


			}
			else
			{

			}
		}
		else
		{
			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{


			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{


			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{

			}
			else
			{

			}

		}
		pc++;	//increment pc
	}
	void VirtualMachine::POP(Operands operands)
	{
		if (operands.size() == 0)
		{

		}
		else if (operands.size() == 1)
		{
			if (operands[0].addressingMode == ISARRAY)
			{


			}
			else
			{

			}
		}
		else
		{
			if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == ISARRAY)
			{


			}
			else if (operands[0].addressingMode == ISARRAY && operands[1].addressingMode == !ISARRAY)
			{


			}
			else if (operands[0].addressingMode == !ISARRAY && operands[1].addressingMode == ISARRAY)
			{

			}
			else
			{

			}

		}
		pc++;	//increment pc
	}
}



