#pragma once

class CompExpr : public BaseExpr {
public:
  CompExpr(ptr<BaseExpr>&& left,
           CompType comp,
           ptr<BaseExpr>&& right)
    : BaseExpr (ExprType::COMP),
      left_    (move(left)),
      
    
};
