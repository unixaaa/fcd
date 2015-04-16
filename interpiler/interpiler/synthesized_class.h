//
//  synthesized_class.h
//  interpiler
//
//  Created by Félix on 2015-04-15.
//  Copyright (c) 2015 Félix Cloutier. All rights reserved.
//

#ifndef __interpiler__synthesized_class__
#define __interpiler__synthesized_class__

#include <deque>
#include <llvm/Support/raw_ostream.h>
#include <string>

#include "synthesized_method.h"

class synthesized_class
{
	std::string name;
	synthesized_method constructor;
	std::deque<std::string> fields;
	std::deque<synthesized_method> methods;
	
public:
	explicit synthesized_class(const std::string& name);
	
	inline std::string& new_field()
	{
		fields.emplace_back();
		return fields.back();
	}
	
	inline synthesized_method& new_method(const std::string& returnType, const std::string& name)
	{
		methods.emplace_back(returnType, name);
		return methods.back();
	}
	
	inline std::string& ctor_nl()
	{
		return constructor.nl();
	}
	
	void print_declaration(llvm::raw_ostream& os) const;
	void print_definition(llvm::raw_ostream& os) const;
};

#endif /* defined(__interpiler__synthesized_class__) */