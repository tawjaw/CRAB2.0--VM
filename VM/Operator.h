#pragma once

#include "boost\bimap.hpp"
#include "ParsingHelper.h"
namespace crab {
	struct Operator {

		/*enum that holds all the instructions set*/
		enum OP {
			//REG/ARRAY<->BUFFERS TRANSFER
			GETB, PUTB,
			//REG/ARRAY<->MEMORY TRANSFER
			SETP, MOVP, GETM, PUTM,
			//REG/ARRAYIMMEDIATE ASSIGN
			ASSN,
			//REG/ARRAY<->REG/ARRAY MOVES
			COPY, SWAP,
			//REG/ARRAY<->STACK MOVES
			PUSH, POP,
			//MATHEMATICAL INSTRUCTIONS
			ADD, SUB, MUL, DIV, IDIV, IREM, ABS, RND, SIN, COS, ASIN, ACOS, POW, LOG,
			//LOGICAL INSTRUCTIONS
			AND, ORR, XOR, NOT,
			//COMPARISON INSTRUCTIONS
			LESS, EQUL, GREQ,
			//FLOW CONTROL INSTRUCTIONS 
			IFEL, WHIL
		};

		typedef boost::bimap<Operator::OP, ci_string > op_bimap;
		typedef op_bimap::value_type position;
		static op_bimap create_map()
		{
			op_bimap bm;
			bm.insert(position(GETB, "GETB"));
			bm.insert(position(PUTB, "PUTB"));
			bm.insert(position(SETP, "SETP"));
			bm.insert(position(MOVP, "MOVP"));
			bm.insert(position(GETM, "GETM"));
			bm.insert(position(PUTM, "PUTM"));
			bm.insert(position(ASSN, "ASSN"));
			bm.insert(position(COPY, "COPY"));
			bm.insert(position(SWAP, "SWAP"));
			bm.insert(position(PUSH, "PUSH"));
			bm.insert(position(POP, "POP"));
			bm.insert(position(ADD, "ADD"));
			bm.insert(position(SUB, "SUB"));
			bm.insert(position(MUL, "MUL"));
			bm.insert(position(DIV, "DIV"));
			bm.insert(position(IDIV, "IDIV"));
			bm.insert(position(IREM, "IREM"));
			bm.insert(position(ABS, "ABS"));
			bm.insert(position(RND, "RND"));
			bm.insert(position(SIN, "SIN"));
			bm.insert(position(COS, "COS"));
			bm.insert(position(ASIN, "ASIN"));
			bm.insert(position(ACOS, "ACOS"));
			bm.insert(position(POW, "POW"));
			bm.insert(position(LOG, "LOG"));
			bm.insert(position(AND, "AND"));
			bm.insert(position(ORR, "ORR"));
			bm.insert(position(XOR, "XOR"));
			bm.insert(position(NOT, "NOT"));
			bm.insert(position(LESS, "LESS"));
			bm.insert(position(EQUL, "EQUL"));
			bm.insert(position(GREQ, "GREQ"));
			bm.insert(position(IFEL, "IFEL"));
			bm.insert(position(WHIL, "WHIL"));
			
			return bm;
		}
		
		template< class MapType >
		static void print_map(const MapType & map,
			const std::string & separator,
			std::ostream & os)
		{
			typedef typename MapType::const_iterator const_iterator;

			for (const_iterator i = map.begin(), iend = map.end(); i != iend; ++i)
			{
				os << i->first;
				os << separator;
				os << i->second;
				os << std::endl;
			}
		}

	};
}