//
// passes.h
// Copyright (C) 2015 Félix Cloutier.
// All Rights Reserved.
//
// This file is part of fcd.
// 
// fcd is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// fcd is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with fcd.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __x86Emulator__asaa__
#define __x86Emulator__asaa__

#include "llvm_warnings.h"

SILENCE_LLVM_WARNINGS_BEGIN()
#include <llvm/Pass.h>
#include <llvm/Analysis/AliasAnalysis.h>
#include <llvm/Analysis/CallGraphSCCPass.h>
#include <llvm/Analysis/LoopPass.h>
#include <llvm/Analysis/Passes.h>
#include "MemorySSA.h"
SILENCE_LLVM_WARNINGS_END()

#include "pass_backend.h"
#include "pass_targetinfo.h"
#include "pass_reguse.h"

llvm::ImmutablePass*	createAddressSpaceAliasAnalysisPass();
llvm::CallGraphSCCPass*	createArgumentRecoveryPass();
AstBackEnd*				createAstBackEnd();
llvm::ModulePass*		createInteractiveRegisterUsePass();
llvm::ModulePass*		createIpaRegisterUsePass();
llvm::ModulePass*		createLibraryRegisterUsePass();
llvm::FunctionPass*		createRegisterPointerPromotionPass();
llvm::FunctionPass*		createSESELoopPass();
llvm::FunctionPass*		createSignExtPass();
llvm::FunctionPass*		createConditionSimplificationPass();
TargetInfo*				createTargetInfoPass();

namespace llvm
{
	void initializeArgumentRecoveryPass(PassRegistry& pr);
	void initializeAstBackEndPass(PassRegistry& pr);
	void initializeInteractiveRegisterUsePass(PassRegistry& pr);
	void initializeIpaRegisterUsePass(PassRegistry& pr);
	void initializeLibraryRegisterUsePass(PassRegistry& pr);
	void initializeSESELoopPass(PassRegistry& pr);
}

#endif /* defined(__x86Emulator__asaa__) */
