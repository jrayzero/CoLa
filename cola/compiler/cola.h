#pragma once

#include "compiler/dsl/dsl.h"

namespace cola {
using namespace seq;

class Cola : public DSL {  
 public:

  std::string getName() const override { return "CoLa"; }
  void addIRPasses(ir::transform::PassManager *pm, bool debug) override;
  
};

}
