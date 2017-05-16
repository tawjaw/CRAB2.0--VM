#include "VirtualMachine.h"

namespace crab {
	void VirtualMachine::IFEL(Operands operands)
	{
		if (!flagIf && !flagWhile)
		{
			if (operands.size() == 0)
			{
				if (flagLogical)
				{
					if (pc + 2 < translatedMemory.size())
					{
						std::map<int, int>::iterator it = labelsMap.find(translatedMemory.at(pc + 2).label);
						if (it != labelsMap.end())
						{
							flagIf = true;
							flagControl1 = true;
							controlRegister1 = translatedMemory.at(pc + 2).label;
						}
					}
				}
				else
				{
					//if (pc + 1 > translatedMemory.size())
					pc++;
				}
			}
			else if (operands.size() == 1)
			{
				std::map<int, int>::iterator it = labelsMap.find((int)operands.at(0).value);	//if label exist
				if (it != labelsMap.end())
				{
					if (it->second > pc)	//if instruction of label after pc in memory
					{
						if (flagLogical)
						{

							if (it->second + 1 < translatedMemory.size())
							{
								flagIf = true;
								flagControl1 = true;
								controlRegister1 = translatedMemory.at(it->second + 1).label;
							}


						}
						else
						{
							pc = it->second;
						}
					}
				}
			}
			else
			{
				std::map<int, int>::iterator it2 = labelsMap.find((int)operands.at(1).value);	//if label 2 exist
				if (it2 != labelsMap.end())
				{
					std::map<int, int>::iterator it = labelsMap.find((int)operands.at(0).value);	//if label 1 exist
					if (it != labelsMap.end())
					{
						if (flagLogical)
						{
							if (it->second > pc && it2->second > pc)
							{

								if (it->second + 1 < translatedMemory.size() && it2->second + 1 < translatedMemory.size())
								{
									flagIf = true;
									flagControl1 = true; flagControl2 = true;
									controlRegister1 = translatedMemory.at(it->second + 1).label;
									controlRegister2 = translatedMemory.at(it2->second + 1).label;
								}
							}
						}
						else
						{
							if (it->second > pc)
							{
								pc = it->second;
							}


						}
					}
				}
				else  //if label 2 doesnt exist treat it as one operand instruction
				{
					std::map<int, int>::iterator it = labelsMap.find((int)operands.at(0).value);	//if label 1 exist
					if (it != labelsMap.end())
					{
						if (it->second > pc)	//if instruction of label after pc in memory
						{
							if (flagLogical)
							{

								if (it->second + 1 < translatedMemory.size())
								{
									flagControl1 = true;
									controlRegister1 = translatedMemory.at(it->second + 1).label;
								}


							}
							else
							{
								pc = it->second;
							}
						}
					}
				}
			}
		}
		pc++;	//increment pc
	}
	void VirtualMachine::WHIL(Operands operands)
	{
		if (!flagIf && !flagWhile)
		{
			if (operands.size() == 0)
			{
				if (pc + 1 < translatedMemory.size())
				{
					std::map<int, int>::iterator it = labelsMap.find(translatedMemory.at(pc + 1).label);
					if (it != labelsMap.end())
					{
						if (flagLogical)
						{
							flagWhile = true;
							flagControl1 = true;
							controlRegister1 = translatedMemory.at(pc + 1).label;
						}
					}
				}

			}
			else if (operands.size() == 1)
			{
				std::map<int, int>::iterator it = labelsMap.find((int)operands.at(0).value);	//if label exist
				if (it != labelsMap.end())
				{
					if (it->second > pc)	//if instruction of label after pc in memory
					{
						if (flagLogical)
						{
							flagWhile = true;

							flagControl1 = true;
							controlRegister1 = translatedMemory.at(pc + 1).label;

							flagControl2 = true;
							controlRegister2 = translatedMemory.at(it->second).label;

						}
					}
				}
			}
			else
			{
				std::map<int, int>::iterator it = labelsMap.find((int)operands.at(0).value);	//if label exist
				if (it != labelsMap.end())
				{
					if (it->second > pc)	//if instruction of label after pc in memory
					{
						if (flagLogical)
						{
							flagWhile = true;

							flagControl1 = true;
							controlRegister1 = translatedMemory.at(pc + 1).label;

							flagControl2 = true;
							controlRegister2 = translatedMemory.at(it->second).label;

							flagControl3 = true;
							controlRegister3 = std::abs((int)operands.at(1).value);
						}
					}
				}
			}
		}
		pc++;
	}
	
}
