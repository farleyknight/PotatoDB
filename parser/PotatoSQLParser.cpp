
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2



#include "PotatoSQLParser.h"


using namespace antlrcpp;
using namespace potatodb;
using namespace antlr4;

PotatoSQLParser::PotatoSQLParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

PotatoSQLParser::~PotatoSQLParser() {
  delete _interpreter;
}

std::string PotatoSQLParser::getGrammarFileName() const {
  return "PotatoSQL.g4";
}

const std::vector<std::string>& PotatoSQLParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& PotatoSQLParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MainContext ------------------------------------------------------------------

PotatoSQLParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::MainContext::EOF() {
  return getToken(PotatoSQLParser::EOF, 0);
}

std::vector<PotatoSQLParser::Sql_stmt_listContext *> PotatoSQLParser::MainContext::sql_stmt_list() {
  return getRuleContexts<PotatoSQLParser::Sql_stmt_listContext>();
}

PotatoSQLParser::Sql_stmt_listContext* PotatoSQLParser::MainContext::sql_stmt_list(size_t i) {
  return getRuleContext<PotatoSQLParser::Sql_stmt_listContext>(i);
}


size_t PotatoSQLParser::MainContext::getRuleIndex() const {
  return PotatoSQLParser::RuleMain;
}


PotatoSQLParser::MainContext* PotatoSQLParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, PotatoSQLParser::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::SCOL)
      | (1ULL << PotatoSQLParser::K_BEGIN)
      | (1ULL << PotatoSQLParser::K_ALTER)
      | (1ULL << PotatoSQLParser::K_COMMIT)
      | (1ULL << PotatoSQLParser::K_END)
      | (1ULL << PotatoSQLParser::K_CREATE))) != 0) || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (PotatoSQLParser::K_DELETE - 68))
      | (1ULL << (PotatoSQLParser::K_DROP - 68))
      | (1ULL << (PotatoSQLParser::K_INSERT - 68))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 68))
      | (1ULL << (PotatoSQLParser::K_ROLLBACK - 68))
      | (1ULL << (PotatoSQLParser::K_VALUES - 68))
      | (1ULL << (PotatoSQLParser::K_PRAGMA - 68))
      | (1ULL << (PotatoSQLParser::K_SELECT - 68))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 68))
      | (1ULL << (PotatoSQLParser::K_WITH - 68)))) != 0)) {
      setState(134);
      sql_stmt_list();
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(140);
    match(PotatoSQLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmt_listContext ------------------------------------------------------------------

PotatoSQLParser::Sql_stmt_listContext::Sql_stmt_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Sql_stmtContext *> PotatoSQLParser::Sql_stmt_listContext::sql_stmt() {
  return getRuleContexts<PotatoSQLParser::Sql_stmtContext>();
}

PotatoSQLParser::Sql_stmtContext* PotatoSQLParser::Sql_stmt_listContext::sql_stmt(size_t i) {
  return getRuleContext<PotatoSQLParser::Sql_stmtContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Sql_stmt_listContext::SCOL() {
  return getTokens(PotatoSQLParser::SCOL);
}

tree::TerminalNode* PotatoSQLParser::Sql_stmt_listContext::SCOL(size_t i) {
  return getToken(PotatoSQLParser::SCOL, i);
}


size_t PotatoSQLParser::Sql_stmt_listContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSql_stmt_list;
}


PotatoSQLParser::Sql_stmt_listContext* PotatoSQLParser::sql_stmt_list() {
  Sql_stmt_listContext *_localctx = _tracker.createInstance<Sql_stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 2, PotatoSQLParser::RuleSql_stmt_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(145);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::SCOL) {
      setState(142);
      match(PotatoSQLParser::SCOL);
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(148);
    sql_stmt();
    setState(157);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(150); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(149);
          match(PotatoSQLParser::SCOL);
          setState(152); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PotatoSQLParser::SCOL);
        setState(154);
        sql_stmt(); 
      }
      setState(159);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(163);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        match(PotatoSQLParser::SCOL); 
      }
      setState(165);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sql_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Sql_stmtContext::Sql_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Alter_table_stmtContext* PotatoSQLParser::Sql_stmtContext::alter_table_stmt() {
  return getRuleContext<PotatoSQLParser::Alter_table_stmtContext>(0);
}

PotatoSQLParser::Begin_stmtContext* PotatoSQLParser::Sql_stmtContext::begin_stmt() {
  return getRuleContext<PotatoSQLParser::Begin_stmtContext>(0);
}

PotatoSQLParser::Commit_stmtContext* PotatoSQLParser::Sql_stmtContext::commit_stmt() {
  return getRuleContext<PotatoSQLParser::Commit_stmtContext>(0);
}

PotatoSQLParser::Create_index_stmtContext* PotatoSQLParser::Sql_stmtContext::create_index_stmt() {
  return getRuleContext<PotatoSQLParser::Create_index_stmtContext>(0);
}

PotatoSQLParser::Compound_select_stmtContext* PotatoSQLParser::Sql_stmtContext::compound_select_stmt() {
  return getRuleContext<PotatoSQLParser::Compound_select_stmtContext>(0);
}

PotatoSQLParser::Create_table_stmtContext* PotatoSQLParser::Sql_stmtContext::create_table_stmt() {
  return getRuleContext<PotatoSQLParser::Create_table_stmtContext>(0);
}

PotatoSQLParser::Drop_table_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_table_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_table_stmtContext>(0);
}

PotatoSQLParser::Delete_stmtContext* PotatoSQLParser::Sql_stmtContext::delete_stmt() {
  return getRuleContext<PotatoSQLParser::Delete_stmtContext>(0);
}

PotatoSQLParser::Drop_index_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_index_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_index_stmtContext>(0);
}

PotatoSQLParser::Factored_select_stmtContext* PotatoSQLParser::Sql_stmtContext::factored_select_stmt() {
  return getRuleContext<PotatoSQLParser::Factored_select_stmtContext>(0);
}

PotatoSQLParser::Insert_stmtContext* PotatoSQLParser::Sql_stmtContext::insert_stmt() {
  return getRuleContext<PotatoSQLParser::Insert_stmtContext>(0);
}

PotatoSQLParser::Pragma_stmtContext* PotatoSQLParser::Sql_stmtContext::pragma_stmt() {
  return getRuleContext<PotatoSQLParser::Pragma_stmtContext>(0);
}

PotatoSQLParser::Rollback_stmtContext* PotatoSQLParser::Sql_stmtContext::rollback_stmt() {
  return getRuleContext<PotatoSQLParser::Rollback_stmtContext>(0);
}

PotatoSQLParser::Simple_select_stmtContext* PotatoSQLParser::Sql_stmtContext::simple_select_stmt() {
  return getRuleContext<PotatoSQLParser::Simple_select_stmtContext>(0);
}

PotatoSQLParser::Update_stmtContext* PotatoSQLParser::Sql_stmtContext::update_stmt() {
  return getRuleContext<PotatoSQLParser::Update_stmtContext>(0);
}

PotatoSQLParser::Update_stmt_limitedContext* PotatoSQLParser::Sql_stmtContext::update_stmt_limited() {
  return getRuleContext<PotatoSQLParser::Update_stmt_limitedContext>(0);
}


size_t PotatoSQLParser::Sql_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSql_stmt;
}


PotatoSQLParser::Sql_stmtContext* PotatoSQLParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, PotatoSQLParser::RuleSql_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(166);
      alter_table_stmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      begin_stmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(168);
      commit_stmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(169);
      create_index_stmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(170);
      compound_select_stmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(171);
      create_table_stmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(172);
      drop_table_stmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(173);
      delete_stmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(174);
      drop_index_stmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(175);
      drop_table_stmt();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(176);
      factored_select_stmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(177);
      insert_stmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(178);
      pragma_stmt();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(179);
      rollback_stmt();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(180);
      simple_select_stmt();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(181);
      update_stmt();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(182);
      update_stmt_limited();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Alter_table_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Alter_table_stmtContext::Alter_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_ALTER() {
  return getToken(PotatoSQLParser::K_ALTER, 0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Alter_table_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_RENAME() {
  return getToken(PotatoSQLParser::K_RENAME, 0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_TO() {
  return getToken(PotatoSQLParser::K_TO, 0);
}

PotatoSQLParser::New_table_nameContext* PotatoSQLParser::Alter_table_stmtContext::new_table_name() {
  return getRuleContext<PotatoSQLParser::New_table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_ADD() {
  return getToken(PotatoSQLParser::K_ADD, 0);
}

PotatoSQLParser::Column_defContext* PotatoSQLParser::Alter_table_stmtContext::column_def() {
  return getRuleContext<PotatoSQLParser::Column_defContext>(0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Alter_table_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Alter_table_stmtContext::K_COLUMN() {
  return getToken(PotatoSQLParser::K_COLUMN, 0);
}


size_t PotatoSQLParser::Alter_table_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleAlter_table_stmt;
}


PotatoSQLParser::Alter_table_stmtContext* PotatoSQLParser::alter_table_stmt() {
  Alter_table_stmtContext *_localctx = _tracker.createInstance<Alter_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, PotatoSQLParser::RuleAlter_table_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(PotatoSQLParser::K_ALTER);
    setState(186);
    match(PotatoSQLParser::K_TABLE);
    setState(190);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(187);
      database_name();
      setState(188);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(192);
    table_name();
    setState(201);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_RENAME: {
        setState(193);
        match(PotatoSQLParser::K_RENAME);
        setState(194);
        match(PotatoSQLParser::K_TO);
        setState(195);
        new_table_name();
        break;
      }

      case PotatoSQLParser::K_ADD: {
        setState(196);
        match(PotatoSQLParser::K_ADD);
        setState(198);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_COLUMN) {
          setState(197);
          match(PotatoSQLParser::K_COLUMN);
        }
        setState(200);
        column_def();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Begin_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Begin_stmtContext::Begin_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Begin_stmtContext::K_BEGIN() {
  return getToken(PotatoSQLParser::K_BEGIN, 0);
}


size_t PotatoSQLParser::Begin_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleBegin_stmt;
}


PotatoSQLParser::Begin_stmtContext* PotatoSQLParser::begin_stmt() {
  Begin_stmtContext *_localctx = _tracker.createInstance<Begin_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, PotatoSQLParser::RuleBegin_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(PotatoSQLParser::K_BEGIN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Commit_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Commit_stmtContext::Commit_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Commit_stmtContext::K_COMMIT() {
  return getToken(PotatoSQLParser::K_COMMIT, 0);
}

tree::TerminalNode* PotatoSQLParser::Commit_stmtContext::K_END() {
  return getToken(PotatoSQLParser::K_END, 0);
}


size_t PotatoSQLParser::Commit_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCommit_stmt;
}


PotatoSQLParser::Commit_stmtContext* PotatoSQLParser::commit_stmt() {
  Commit_stmtContext *_localctx = _tracker.createInstance<Commit_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, PotatoSQLParser::RuleCommit_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    _la = _input->LA(1);
    if (!(_la == PotatoSQLParser::K_COMMIT

    || _la == PotatoSQLParser::K_END)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_select_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Compound_select_stmtContext::Compound_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Select_coreContext *> PotatoSQLParser::Compound_select_stmtContext::select_core() {
  return getRuleContexts<PotatoSQLParser::Select_coreContext>();
}

PotatoSQLParser::Select_coreContext* PotatoSQLParser::Compound_select_stmtContext::select_core(size_t i) {
  return getRuleContext<PotatoSQLParser::Select_coreContext>(i);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Compound_select_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Compound_select_stmtContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Compound_select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Compound_select_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Compound_select_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Compound_select_stmtContext::K_UNION() {
  return getTokens(PotatoSQLParser::K_UNION);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_UNION(size_t i) {
  return getToken(PotatoSQLParser::K_UNION, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Compound_select_stmtContext::K_INTERSECT() {
  return getTokens(PotatoSQLParser::K_INTERSECT);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_INTERSECT(size_t i) {
  return getToken(PotatoSQLParser::K_INTERSECT, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Compound_select_stmtContext::K_EXCEPT() {
  return getTokens(PotatoSQLParser::K_EXCEPT);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_EXCEPT(size_t i) {
  return getToken(PotatoSQLParser::K_EXCEPT, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Compound_select_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Compound_select_stmtContext::K_ALL() {
  return getTokens(PotatoSQLParser::K_ALL);
}

tree::TerminalNode* PotatoSQLParser::Compound_select_stmtContext::K_ALL(size_t i) {
  return getToken(PotatoSQLParser::K_ALL, i);
}


size_t PotatoSQLParser::Compound_select_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCompound_select_stmt;
}


PotatoSQLParser::Compound_select_stmtContext* PotatoSQLParser::compound_select_stmt() {
  Compound_select_stmtContext *_localctx = _tracker.createInstance<Compound_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, PotatoSQLParser::RuleCompound_select_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(207);
      with_clause();
    }
    setState(210);
    select_core();
    setState(220); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(217);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_UNION: {
          setState(211);
          match(PotatoSQLParser::K_UNION);
          setState(213);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_ALL) {
            setState(212);
            match(PotatoSQLParser::K_ALL);
          }
          break;
        }

        case PotatoSQLParser::K_INTERSECT: {
          setState(215);
          match(PotatoSQLParser::K_INTERSECT);
          break;
        }

        case PotatoSQLParser::K_EXCEPT: {
          setState(216);
          match(PotatoSQLParser::K_EXCEPT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(219);
      select_core();
      setState(222); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_UNION)
      | (1ULL << PotatoSQLParser::K_INTERSECT)
      | (1ULL << PotatoSQLParser::K_EXCEPT))) != 0));
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(224);
      match(PotatoSQLParser::K_ORDER);
      setState(225);
      match(PotatoSQLParser::K_BY);
      setState(226);
      ordering_term();
      setState(231);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(227);
        match(PotatoSQLParser::COMMA);
        setState(228);
        ordering_term();
        setState(233);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(242);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(236);
      match(PotatoSQLParser::K_LIMIT);
      setState(237);
      expr(0);
      setState(240);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(238);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(239);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_index_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Create_index_stmtContext::Create_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_INDEX() {
  return getToken(PotatoSQLParser::K_INDEX, 0);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::Create_index_stmtContext::index_name() {
  return getRuleContext<PotatoSQLParser::Index_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_ON() {
  return getToken(PotatoSQLParser::K_ON, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Create_index_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Indexed_columnContext *> PotatoSQLParser::Create_index_stmtContext::indexed_column() {
  return getRuleContexts<PotatoSQLParser::Indexed_columnContext>();
}

PotatoSQLParser::Indexed_columnContext* PotatoSQLParser::Create_index_stmtContext::indexed_column(size_t i) {
  return getRuleContext<PotatoSQLParser::Indexed_columnContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_UNIQUE() {
  return getToken(PotatoSQLParser::K_UNIQUE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Create_index_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_index_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Create_index_stmtContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Create_index_stmtContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}


size_t PotatoSQLParser::Create_index_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCreate_index_stmt;
}


PotatoSQLParser::Create_index_stmtContext* PotatoSQLParser::create_index_stmt() {
  Create_index_stmtContext *_localctx = _tracker.createInstance<Create_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, PotatoSQLParser::RuleCreate_index_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(PotatoSQLParser::K_CREATE);
    setState(246);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_UNIQUE) {
      setState(245);
      match(PotatoSQLParser::K_UNIQUE);
    }
    setState(248);
    match(PotatoSQLParser::K_INDEX);
    setState(252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_IF) {
      setState(249);
      match(PotatoSQLParser::K_IF);
      setState(250);
      match(PotatoSQLParser::K_NOT);
      setState(251);
      match(PotatoSQLParser::K_EXISTS);
    }
    setState(257);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(254);
      database_name();
      setState(255);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(259);
    index_name();
    setState(260);
    match(PotatoSQLParser::K_ON);
    setState(261);
    table_name();
    setState(262);
    match(PotatoSQLParser::OPEN_PAR);
    setState(263);
    indexed_column();
    setState(268);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(264);
      match(PotatoSQLParser::COMMA);
      setState(265);
      indexed_column();
      setState(270);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(271);
    match(PotatoSQLParser::CLOSE_PAR);
    setState(274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(272);
      match(PotatoSQLParser::K_WHERE);
      setState(273);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_table_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Create_table_stmtContext::Create_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Create_table_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Column_defContext *> PotatoSQLParser::Create_table_stmtContext::column_def() {
  return getRuleContexts<PotatoSQLParser::Column_defContext>();
}

PotatoSQLParser::Column_defContext* PotatoSQLParser::Create_table_stmtContext::column_def(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_defContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Create_table_stmtContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Create_table_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_TEMP() {
  return getToken(PotatoSQLParser::K_TEMP, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_TEMPORARY() {
  return getToken(PotatoSQLParser::K_TEMPORARY, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_table_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

std::vector<PotatoSQLParser::Table_constraintContext *> PotatoSQLParser::Create_table_stmtContext::table_constraint() {
  return getRuleContexts<PotatoSQLParser::Table_constraintContext>();
}

PotatoSQLParser::Table_constraintContext* PotatoSQLParser::Create_table_stmtContext::table_constraint(size_t i) {
  return getRuleContext<PotatoSQLParser::Table_constraintContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::K_WITHOUT() {
  return getToken(PotatoSQLParser::K_WITHOUT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_table_stmtContext::IDENTIFIER() {
  return getToken(PotatoSQLParser::IDENTIFIER, 0);
}


size_t PotatoSQLParser::Create_table_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCreate_table_stmt;
}


PotatoSQLParser::Create_table_stmtContext* PotatoSQLParser::create_table_stmt() {
  Create_table_stmtContext *_localctx = _tracker.createInstance<Create_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, PotatoSQLParser::RuleCreate_table_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(276);
    match(PotatoSQLParser::K_CREATE);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(277);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_TEMP

      || _la == PotatoSQLParser::K_TEMPORARY)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(280);
    match(PotatoSQLParser::K_TABLE);
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_IF) {
      setState(281);
      match(PotatoSQLParser::K_IF);
      setState(282);
      match(PotatoSQLParser::K_NOT);
      setState(283);
      match(PotatoSQLParser::K_EXISTS);
    }
    setState(289);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(286);
      database_name();
      setState(287);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(291);
    table_name();
    setState(315);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::OPEN_PAR: {
        setState(292);
        match(PotatoSQLParser::OPEN_PAR);
        setState(293);
        column_def();
        setState(298);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
        while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1 + 1) {
            setState(294);
            match(PotatoSQLParser::COMMA);
            setState(295);
            column_def(); 
          }
          setState(300);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
        }
        setState(305);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(301);
          match(PotatoSQLParser::COMMA);
          setState(302);
          table_constraint();
          setState(307);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(308);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(311);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WITHOUT) {
          setState(309);
          match(PotatoSQLParser::K_WITHOUT);
          setState(310);
          match(PotatoSQLParser::IDENTIFIER);
        }
        break;
      }

      case PotatoSQLParser::K_AS: {
        setState(313);
        match(PotatoSQLParser::K_AS);
        setState(314);
        select_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Delete_stmtContext::Delete_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Delete_stmtContext::K_DELETE() {
  return getToken(PotatoSQLParser::K_DELETE, 0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmtContext::K_FROM() {
  return getToken(PotatoSQLParser::K_FROM, 0);
}

PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::Delete_stmtContext::qualified_table_name() {
  return getRuleContext<PotatoSQLParser::Qualified_table_nameContext>(0);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Delete_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmtContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Delete_stmtContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}


size_t PotatoSQLParser::Delete_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDelete_stmt;
}


PotatoSQLParser::Delete_stmtContext* PotatoSQLParser::delete_stmt() {
  Delete_stmtContext *_localctx = _tracker.createInstance<Delete_stmtContext>(_ctx, getState());
  enterRule(_localctx, 18, PotatoSQLParser::RuleDelete_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(317);
      with_clause();
    }
    setState(320);
    match(PotatoSQLParser::K_DELETE);
    setState(321);
    match(PotatoSQLParser::K_FROM);
    setState(322);
    qualified_table_name();
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(323);
      match(PotatoSQLParser::K_WHERE);
      setState(324);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Delete_stmt_limitedContext ------------------------------------------------------------------

PotatoSQLParser::Delete_stmt_limitedContext::Delete_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_DELETE() {
  return getToken(PotatoSQLParser::K_DELETE, 0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_FROM() {
  return getToken(PotatoSQLParser::K_FROM, 0);
}

PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::Delete_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<PotatoSQLParser::Qualified_table_nameContext>(0);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Delete_stmt_limitedContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Delete_stmt_limitedContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Delete_stmt_limitedContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Delete_stmt_limitedContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Delete_stmt_limitedContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Delete_stmt_limitedContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Delete_stmt_limitedContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Delete_stmt_limitedContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDelete_stmt_limited;
}


PotatoSQLParser::Delete_stmt_limitedContext* PotatoSQLParser::delete_stmt_limited() {
  Delete_stmt_limitedContext *_localctx = _tracker.createInstance<Delete_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 20, PotatoSQLParser::RuleDelete_stmt_limited);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(327);
      with_clause();
    }
    setState(330);
    match(PotatoSQLParser::K_DELETE);
    setState(331);
    match(PotatoSQLParser::K_FROM);
    setState(332);
    qualified_table_name();
    setState(335);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(333);
      match(PotatoSQLParser::K_WHERE);
      setState(334);
      expr(0);
    }
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(347);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(337);
        match(PotatoSQLParser::K_ORDER);
        setState(338);
        match(PotatoSQLParser::K_BY);
        setState(339);
        ordering_term();
        setState(344);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(340);
          match(PotatoSQLParser::COMMA);
          setState(341);
          ordering_term();
          setState(346);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(349);
      match(PotatoSQLParser::K_LIMIT);
      setState(350);
      expr(0);
      setState(353);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(351);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(352);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_index_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Drop_index_stmtContext::Drop_index_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Drop_index_stmtContext::K_DROP() {
  return getToken(PotatoSQLParser::K_DROP, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_index_stmtContext::K_INDEX() {
  return getToken(PotatoSQLParser::K_INDEX, 0);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::Drop_index_stmtContext::index_name() {
  return getRuleContext<PotatoSQLParser::Index_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_index_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_index_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Drop_index_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_index_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Drop_index_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDrop_index_stmt;
}


PotatoSQLParser::Drop_index_stmtContext* PotatoSQLParser::drop_index_stmt() {
  Drop_index_stmtContext *_localctx = _tracker.createInstance<Drop_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, PotatoSQLParser::RuleDrop_index_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(PotatoSQLParser::K_DROP);
    setState(358);
    match(PotatoSQLParser::K_INDEX);
    setState(361);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_IF) {
      setState(359);
      match(PotatoSQLParser::K_IF);
      setState(360);
      match(PotatoSQLParser::K_EXISTS);
    }
    setState(366);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(363);
      database_name();
      setState(364);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(368);
    index_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_table_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Drop_table_stmtContext::Drop_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Drop_table_stmtContext::K_DROP() {
  return getToken(PotatoSQLParser::K_DROP, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_table_stmtContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Drop_table_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_table_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_table_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Drop_table_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_table_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Drop_table_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDrop_table_stmt;
}


PotatoSQLParser::Drop_table_stmtContext* PotatoSQLParser::drop_table_stmt() {
  Drop_table_stmtContext *_localctx = _tracker.createInstance<Drop_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, PotatoSQLParser::RuleDrop_table_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    match(PotatoSQLParser::K_DROP);
    setState(371);
    match(PotatoSQLParser::K_TABLE);
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_IF) {
      setState(372);
      match(PotatoSQLParser::K_IF);
      setState(373);
      match(PotatoSQLParser::K_EXISTS);
    }
    setState(379);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(376);
      database_name();
      setState(377);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(381);
    table_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Factored_select_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Factored_select_stmtContext::Factored_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Select_coreContext *> PotatoSQLParser::Factored_select_stmtContext::select_core() {
  return getRuleContexts<PotatoSQLParser::Select_coreContext>();
}

PotatoSQLParser::Select_coreContext* PotatoSQLParser::Factored_select_stmtContext::select_core(size_t i) {
  return getRuleContext<PotatoSQLParser::Select_coreContext>(i);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Factored_select_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

std::vector<PotatoSQLParser::Compound_operatorContext *> PotatoSQLParser::Factored_select_stmtContext::compound_operator() {
  return getRuleContexts<PotatoSQLParser::Compound_operatorContext>();
}

PotatoSQLParser::Compound_operatorContext* PotatoSQLParser::Factored_select_stmtContext::compound_operator(size_t i) {
  return getRuleContext<PotatoSQLParser::Compound_operatorContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Factored_select_stmtContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Factored_select_stmtContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Factored_select_stmtContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Factored_select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Factored_select_stmtContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Factored_select_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Factored_select_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Factored_select_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Factored_select_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Factored_select_stmtContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}


size_t PotatoSQLParser::Factored_select_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleFactored_select_stmt;
}


PotatoSQLParser::Factored_select_stmtContext* PotatoSQLParser::factored_select_stmt() {
  Factored_select_stmtContext *_localctx = _tracker.createInstance<Factored_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, PotatoSQLParser::RuleFactored_select_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(383);
      with_clause();
    }
    setState(386);
    select_core();
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_UNION)
      | (1ULL << PotatoSQLParser::K_INTERSECT)
      | (1ULL << PotatoSQLParser::K_EXCEPT))) != 0)) {
      setState(387);
      compound_operator();
      setState(388);
      select_core();
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(405);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(395);
      match(PotatoSQLParser::K_ORDER);
      setState(396);
      match(PotatoSQLParser::K_BY);
      setState(397);
      ordering_term();
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(398);
        match(PotatoSQLParser::COMMA);
        setState(399);
        ordering_term();
        setState(404);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(407);
      match(PotatoSQLParser::K_LIMIT);
      setState(408);
      expr(0);
      setState(411);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(409);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(410);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Insert_stmtContext::Insert_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_INTO() {
  return getToken(PotatoSQLParser::K_INTO, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Insert_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_INSERT() {
  return getToken(PotatoSQLParser::K_INSERT, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_VALUES() {
  return getToken(PotatoSQLParser::K_VALUES, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_stmtContext::OPEN_PAR() {
  return getTokens(PotatoSQLParser::OPEN_PAR);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::OPEN_PAR(size_t i) {
  return getToken(PotatoSQLParser::OPEN_PAR, i);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Insert_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Insert_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_stmtContext::CLOSE_PAR() {
  return getTokens(PotatoSQLParser::CLOSE_PAR);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::CLOSE_PAR(size_t i) {
  return getToken(PotatoSQLParser::CLOSE_PAR, i);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Insert_stmtContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_DEFAULT() {
  return getToken(PotatoSQLParser::K_DEFAULT, 0);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Insert_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Insert_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Insert_stmtContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Insert_stmtContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Insert_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_stmt;
}


PotatoSQLParser::Insert_stmtContext* PotatoSQLParser::insert_stmt() {
  Insert_stmtContext *_localctx = _tracker.createInstance<Insert_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, PotatoSQLParser::RuleInsert_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(415);
      with_clause();
    }
    setState(435);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      setState(418);
      match(PotatoSQLParser::K_INSERT);
      break;
    }

    case 2: {
      setState(419);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 3: {
      setState(420);
      match(PotatoSQLParser::K_INSERT);
      setState(421);
      match(PotatoSQLParser::K_OR);
      setState(422);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(423);
      match(PotatoSQLParser::K_INSERT);
      setState(424);
      match(PotatoSQLParser::K_OR);
      setState(425);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 5: {
      setState(426);
      match(PotatoSQLParser::K_INSERT);
      setState(427);
      match(PotatoSQLParser::K_OR);
      setState(428);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 6: {
      setState(429);
      match(PotatoSQLParser::K_INSERT);
      setState(430);
      match(PotatoSQLParser::K_OR);
      setState(431);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 7: {
      setState(432);
      match(PotatoSQLParser::K_INSERT);
      setState(433);
      match(PotatoSQLParser::K_OR);
      setState(434);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(437);
    match(PotatoSQLParser::K_INTO);
    setState(441);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(438);
      database_name();
      setState(439);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(443);
    table_name();
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(444);
      match(PotatoSQLParser::OPEN_PAR);
      setState(445);
      column_name();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(446);
        match(PotatoSQLParser::COMMA);
        setState(447);
        column_name();
        setState(452);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(453);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(488);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(457);
      match(PotatoSQLParser::K_VALUES);
      setState(458);
      match(PotatoSQLParser::OPEN_PAR);
      setState(459);
      expr(0);
      setState(464);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(460);
        match(PotatoSQLParser::COMMA);
        setState(461);
        expr(0);
        setState(466);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(467);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(482);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(468);
        match(PotatoSQLParser::COMMA);
        setState(469);
        match(PotatoSQLParser::OPEN_PAR);
        setState(470);
        expr(0);
        setState(475);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(471);
          match(PotatoSQLParser::COMMA);
          setState(472);
          expr(0);
          setState(477);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(478);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(484);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(485);
      select_stmt();
      break;
    }

    case 3: {
      setState(486);
      match(PotatoSQLParser::K_DEFAULT);
      setState(487);
      match(PotatoSQLParser::K_VALUES);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Pragma_stmtContext::Pragma_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Pragma_stmtContext::K_PRAGMA() {
  return getToken(PotatoSQLParser::K_PRAGMA, 0);
}

PotatoSQLParser::Pragma_nameContext* PotatoSQLParser::Pragma_stmtContext::pragma_name() {
  return getRuleContext<PotatoSQLParser::Pragma_nameContext>(0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Pragma_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Pragma_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Pragma_stmtContext::ASSIGN() {
  return getToken(PotatoSQLParser::ASSIGN, 0);
}

PotatoSQLParser::Pragma_valueContext* PotatoSQLParser::Pragma_stmtContext::pragma_value() {
  return getRuleContext<PotatoSQLParser::Pragma_valueContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Pragma_stmtContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Pragma_stmtContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}


size_t PotatoSQLParser::Pragma_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RulePragma_stmt;
}


PotatoSQLParser::Pragma_stmtContext* PotatoSQLParser::pragma_stmt() {
  Pragma_stmtContext *_localctx = _tracker.createInstance<Pragma_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, PotatoSQLParser::RulePragma_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(490);
    match(PotatoSQLParser::K_PRAGMA);
    setState(494);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      setState(491);
      database_name();
      setState(492);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(496);
    pragma_name();
    setState(503);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::ASSIGN: {
        setState(497);
        match(PotatoSQLParser::ASSIGN);
        setState(498);
        pragma_value();
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        setState(499);
        match(PotatoSQLParser::OPEN_PAR);
        setState(500);
        pragma_value();
        setState(501);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_WITH: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rollback_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Rollback_stmtContext::Rollback_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Rollback_stmtContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Rollback_stmtContext::K_TRANSACTION() {
  return getToken(PotatoSQLParser::K_TRANSACTION, 0);
}

tree::TerminalNode* PotatoSQLParser::Rollback_stmtContext::K_TO() {
  return getToken(PotatoSQLParser::K_TO, 0);
}

PotatoSQLParser::Savepoint_nameContext* PotatoSQLParser::Rollback_stmtContext::savepoint_name() {
  return getRuleContext<PotatoSQLParser::Savepoint_nameContext>(0);
}

PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::Rollback_stmtContext::transaction_name() {
  return getRuleContext<PotatoSQLParser::Transaction_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Rollback_stmtContext::K_SAVEPOINT() {
  return getToken(PotatoSQLParser::K_SAVEPOINT, 0);
}


size_t PotatoSQLParser::Rollback_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleRollback_stmt;
}


PotatoSQLParser::Rollback_stmtContext* PotatoSQLParser::rollback_stmt() {
  Rollback_stmtContext *_localctx = _tracker.createInstance<Rollback_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, PotatoSQLParser::RuleRollback_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    match(PotatoSQLParser::K_ROLLBACK);
    setState(510);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(506);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(508);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
      case 1: {
        setState(507);
        transaction_name();
        break;
      }

      default:
        break;
      }
    }
    setState(517);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TO) {
      setState(512);
      match(PotatoSQLParser::K_TO);
      setState(514);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_SAVEPOINT) {
        setState(513);
        match(PotatoSQLParser::K_SAVEPOINT);
      }
      setState(516);
      savepoint_name();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_select_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Simple_select_stmtContext::Simple_select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Select_coreContext* PotatoSQLParser::Simple_select_stmtContext::select_core() {
  return getRuleContext<PotatoSQLParser::Select_coreContext>(0);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Simple_select_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Simple_select_stmtContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Simple_select_stmtContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Simple_select_stmtContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Simple_select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Simple_select_stmtContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Simple_select_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Simple_select_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Simple_select_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Simple_select_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Simple_select_stmtContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}


size_t PotatoSQLParser::Simple_select_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSimple_select_stmt;
}


PotatoSQLParser::Simple_select_stmtContext* PotatoSQLParser::simple_select_stmt() {
  Simple_select_stmtContext *_localctx = _tracker.createInstance<Simple_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, PotatoSQLParser::RuleSimple_select_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(519);
      with_clause();
    }
    setState(522);
    select_core();
    setState(533);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(523);
      match(PotatoSQLParser::K_ORDER);
      setState(524);
      match(PotatoSQLParser::K_BY);
      setState(525);
      ordering_term();
      setState(530);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(526);
        match(PotatoSQLParser::COMMA);
        setState(527);
        ordering_term();
        setState(532);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(541);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(535);
      match(PotatoSQLParser::K_LIMIT);
      setState(536);
      expr(0);
      setState(539);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(537);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(538);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Select_stmtContext::Select_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Select_or_valuesContext *> PotatoSQLParser::Select_stmtContext::select_or_values() {
  return getRuleContexts<PotatoSQLParser::Select_or_valuesContext>();
}

PotatoSQLParser::Select_or_valuesContext* PotatoSQLParser::Select_stmtContext::select_or_values(size_t i) {
  return getRuleContext<PotatoSQLParser::Select_or_valuesContext>(i);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Select_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

std::vector<PotatoSQLParser::Compound_operatorContext *> PotatoSQLParser::Select_stmtContext::compound_operator() {
  return getRuleContexts<PotatoSQLParser::Compound_operatorContext>();
}

PotatoSQLParser::Compound_operatorContext* PotatoSQLParser::Select_stmtContext::compound_operator(size_t i) {
  return getRuleContext<PotatoSQLParser::Compound_operatorContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Select_stmtContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_stmtContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Select_stmtContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Select_stmtContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Select_stmtContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Select_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Select_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Select_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Select_stmtContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}


size_t PotatoSQLParser::Select_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSelect_stmt;
}


PotatoSQLParser::Select_stmtContext* PotatoSQLParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 36, PotatoSQLParser::RuleSelect_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(543);
      with_clause();
    }
    setState(546);
    select_or_values();
    setState(552);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_UNION)
      | (1ULL << PotatoSQLParser::K_INTERSECT)
      | (1ULL << PotatoSQLParser::K_EXCEPT))) != 0)) {
      setState(547);
      compound_operator();
      setState(548);
      select_or_values();
      setState(554);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(565);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(555);
      match(PotatoSQLParser::K_ORDER);
      setState(556);
      match(PotatoSQLParser::K_BY);
      setState(557);
      ordering_term();
      setState(562);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(558);
        match(PotatoSQLParser::COMMA);
        setState(559);
        ordering_term();
        setState(564);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(573);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(567);
      match(PotatoSQLParser::K_LIMIT);
      setState(568);
      expr(0);
      setState(571);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(569);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(570);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_or_valuesContext ------------------------------------------------------------------

PotatoSQLParser::Select_or_valuesContext::Select_or_valuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_SELECT() {
  return getToken(PotatoSQLParser::K_SELECT, 0);
}

std::vector<PotatoSQLParser::Result_columnContext *> PotatoSQLParser::Select_or_valuesContext::result_column() {
  return getRuleContexts<PotatoSQLParser::Result_columnContext>();
}

PotatoSQLParser::Result_columnContext* PotatoSQLParser::Select_or_valuesContext::result_column(size_t i) {
  return getRuleContext<PotatoSQLParser::Result_columnContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_or_valuesContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_FROM() {
  return getToken(PotatoSQLParser::K_FROM, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Select_or_valuesContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Select_or_valuesContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_GROUP() {
  return getToken(PotatoSQLParser::K_GROUP, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_DISTINCT() {
  return getToken(PotatoSQLParser::K_DISTINCT, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_ALL() {
  return getToken(PotatoSQLParser::K_ALL, 0);
}

std::vector<PotatoSQLParser::Table_or_subqueryContext *> PotatoSQLParser::Select_or_valuesContext::table_or_subquery() {
  return getRuleContexts<PotatoSQLParser::Table_or_subqueryContext>();
}

PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::Select_or_valuesContext::table_or_subquery(size_t i) {
  return getRuleContext<PotatoSQLParser::Table_or_subqueryContext>(i);
}

PotatoSQLParser::Join_clauseContext* PotatoSQLParser::Select_or_valuesContext::join_clause() {
  return getRuleContext<PotatoSQLParser::Join_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_HAVING() {
  return getToken(PotatoSQLParser::K_HAVING, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::K_VALUES() {
  return getToken(PotatoSQLParser::K_VALUES, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_or_valuesContext::OPEN_PAR() {
  return getTokens(PotatoSQLParser::OPEN_PAR);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::OPEN_PAR(size_t i) {
  return getToken(PotatoSQLParser::OPEN_PAR, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_or_valuesContext::CLOSE_PAR() {
  return getTokens(PotatoSQLParser::CLOSE_PAR);
}

tree::TerminalNode* PotatoSQLParser::Select_or_valuesContext::CLOSE_PAR(size_t i) {
  return getToken(PotatoSQLParser::CLOSE_PAR, i);
}


size_t PotatoSQLParser::Select_or_valuesContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSelect_or_values;
}


PotatoSQLParser::Select_or_valuesContext* PotatoSQLParser::select_or_values() {
  Select_or_valuesContext *_localctx = _tracker.createInstance<Select_or_valuesContext>(_ctx, getState());
  enterRule(_localctx, 38, PotatoSQLParser::RuleSelect_or_values);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(649);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(575);
        match(PotatoSQLParser::K_SELECT);
        setState(577);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ALL

        || _la == PotatoSQLParser::K_DISTINCT) {
          setState(576);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ALL

          || _la == PotatoSQLParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(579);
        result_column();
        setState(584);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(580);
          match(PotatoSQLParser::COMMA);
          setState(581);
          result_column();
          setState(586);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(599);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(587);
          match(PotatoSQLParser::K_FROM);
          setState(597);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
          case 1: {
            setState(588);
            table_or_subquery();
            setState(593);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(589);
              match(PotatoSQLParser::COMMA);
              setState(590);
              table_or_subquery();
              setState(595);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(596);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(603);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(601);
          match(PotatoSQLParser::K_WHERE);
          setState(602);
          expr(0);
        }
        setState(619);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(605);
          match(PotatoSQLParser::K_GROUP);
          setState(606);
          match(PotatoSQLParser::K_BY);
          setState(607);
          expr(0);
          setState(612);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(608);
            match(PotatoSQLParser::COMMA);
            setState(609);
            expr(0);
            setState(614);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(617);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(615);
            match(PotatoSQLParser::K_HAVING);
            setState(616);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(621);
        match(PotatoSQLParser::K_VALUES);
        setState(622);
        match(PotatoSQLParser::OPEN_PAR);
        setState(623);
        expr(0);
        setState(628);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(624);
          match(PotatoSQLParser::COMMA);
          setState(625);
          expr(0);
          setState(630);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(631);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(646);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(632);
          match(PotatoSQLParser::COMMA);
          setState(633);
          match(PotatoSQLParser::OPEN_PAR);
          setState(634);
          expr(0);
          setState(639);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(635);
            match(PotatoSQLParser::COMMA);
            setState(636);
            expr(0);
            setState(641);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(642);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(648);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Update_stmtContext::Update_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_UPDATE() {
  return getToken(PotatoSQLParser::K_UPDATE, 0);
}

PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::Update_stmtContext::qualified_table_name() {
  return getRuleContext<PotatoSQLParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_SET() {
  return getToken(PotatoSQLParser::K_SET, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Update_stmtContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Update_stmtContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Update_stmtContext::ASSIGN() {
  return getTokens(PotatoSQLParser::ASSIGN);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::ASSIGN(size_t i) {
  return getToken(PotatoSQLParser::ASSIGN, i);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Update_stmtContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Update_stmtContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Update_stmtContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Update_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Update_stmtContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}


size_t PotatoSQLParser::Update_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleUpdate_stmt;
}


PotatoSQLParser::Update_stmtContext* PotatoSQLParser::update_stmt() {
  Update_stmtContext *_localctx = _tracker.createInstance<Update_stmtContext>(_ctx, getState());
  enterRule(_localctx, 40, PotatoSQLParser::RuleUpdate_stmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(652);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(651);
      with_clause();
    }
    setState(654);
    match(PotatoSQLParser::K_UPDATE);
    setState(665);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      setState(655);
      match(PotatoSQLParser::K_OR);
      setState(656);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(657);
      match(PotatoSQLParser::K_OR);
      setState(658);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(659);
      match(PotatoSQLParser::K_OR);
      setState(660);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(661);
      match(PotatoSQLParser::K_OR);
      setState(662);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(663);
      match(PotatoSQLParser::K_OR);
      setState(664);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(667);
    qualified_table_name();
    setState(668);
    match(PotatoSQLParser::K_SET);
    setState(669);
    column_name();
    setState(670);
    match(PotatoSQLParser::ASSIGN);
    setState(671);
    expr(0);
    setState(679);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(672);
      match(PotatoSQLParser::COMMA);
      setState(673);
      column_name();
      setState(674);
      match(PotatoSQLParser::ASSIGN);
      setState(675);
      expr(0);
      setState(681);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(684);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(682);
      match(PotatoSQLParser::K_WHERE);
      setState(683);
      expr(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Update_stmt_limitedContext ------------------------------------------------------------------

PotatoSQLParser::Update_stmt_limitedContext::Update_stmt_limitedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_UPDATE() {
  return getToken(PotatoSQLParser::K_UPDATE, 0);
}

PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::Update_stmt_limitedContext::qualified_table_name() {
  return getRuleContext<PotatoSQLParser::Qualified_table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_SET() {
  return getToken(PotatoSQLParser::K_SET, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Update_stmt_limitedContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Update_stmt_limitedContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Update_stmt_limitedContext::ASSIGN() {
  return getTokens(PotatoSQLParser::ASSIGN);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::ASSIGN(size_t i) {
  return getToken(PotatoSQLParser::ASSIGN, i);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Update_stmt_limitedContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Update_stmt_limitedContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::Update_stmt_limitedContext::with_clause() {
  return getRuleContext<PotatoSQLParser::With_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Update_stmt_limitedContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::Ordering_termContext *> PotatoSQLParser::Update_stmt_limitedContext::ordering_term() {
  return getRuleContexts<PotatoSQLParser::Ordering_termContext>();
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::Update_stmt_limitedContext::ordering_term(size_t i) {
  return getRuleContext<PotatoSQLParser::Ordering_termContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Update_stmt_limitedContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}


size_t PotatoSQLParser::Update_stmt_limitedContext::getRuleIndex() const {
  return PotatoSQLParser::RuleUpdate_stmt_limited;
}


PotatoSQLParser::Update_stmt_limitedContext* PotatoSQLParser::update_stmt_limited() {
  Update_stmt_limitedContext *_localctx = _tracker.createInstance<Update_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 42, PotatoSQLParser::RuleUpdate_stmt_limited);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(687);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(686);
      with_clause();
    }
    setState(689);
    match(PotatoSQLParser::K_UPDATE);
    setState(700);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
    case 1: {
      setState(690);
      match(PotatoSQLParser::K_OR);
      setState(691);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(692);
      match(PotatoSQLParser::K_OR);
      setState(693);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(694);
      match(PotatoSQLParser::K_OR);
      setState(695);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(696);
      match(PotatoSQLParser::K_OR);
      setState(697);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(698);
      match(PotatoSQLParser::K_OR);
      setState(699);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(702);
    qualified_table_name();
    setState(703);
    match(PotatoSQLParser::K_SET);
    setState(704);
    column_name();
    setState(705);
    match(PotatoSQLParser::ASSIGN);
    setState(706);
    expr(0);
    setState(714);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(707);
      match(PotatoSQLParser::COMMA);
      setState(708);
      column_name();
      setState(709);
      match(PotatoSQLParser::ASSIGN);
      setState(710);
      expr(0);
      setState(716);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(719);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(717);
      match(PotatoSQLParser::K_WHERE);
      setState(718);
      expr(0);
    }
    setState(739);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(731);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(721);
        match(PotatoSQLParser::K_ORDER);
        setState(722);
        match(PotatoSQLParser::K_BY);
        setState(723);
        ordering_term();
        setState(728);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(724);
          match(PotatoSQLParser::COMMA);
          setState(725);
          ordering_term();
          setState(730);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(733);
      match(PotatoSQLParser::K_LIMIT);
      setState(734);
      expr(0);
      setState(737);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA

      || _la == PotatoSQLParser::K_OFFSET) {
        setState(735);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA

        || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(736);
        expr(0);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_defContext ------------------------------------------------------------------

PotatoSQLParser::Column_defContext::Column_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Column_defContext::column_name() {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(0);
}

PotatoSQLParser::Type_nameContext* PotatoSQLParser::Column_defContext::type_name() {
  return getRuleContext<PotatoSQLParser::Type_nameContext>(0);
}

std::vector<PotatoSQLParser::Column_constraintContext *> PotatoSQLParser::Column_defContext::column_constraint() {
  return getRuleContexts<PotatoSQLParser::Column_constraintContext>();
}

PotatoSQLParser::Column_constraintContext* PotatoSQLParser::Column_defContext::column_constraint(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_constraintContext>(i);
}


size_t PotatoSQLParser::Column_defContext::getRuleIndex() const {
  return PotatoSQLParser::RuleColumn_def;
}


PotatoSQLParser::Column_defContext* PotatoSQLParser::column_def() {
  Column_defContext *_localctx = _tracker.createInstance<Column_defContext>(_ctx, getState());
  enterRule(_localctx, 44, PotatoSQLParser::RuleColumn_def);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    column_name();
    setState(743);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
    case 1: {
      setState(742);
      type_name();
      break;
    }

    default:
      break;
    }
    setState(748);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_NOT

    || _la == PotatoSQLParser::K_UNIQUE || ((((_la - 79) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 79)) & ((1ULL << (PotatoSQLParser::K_DEFAULT - 79))
      | (1ULL << (PotatoSQLParser::K_CONSTRAINT - 79))
      | (1ULL << (PotatoSQLParser::K_PRIMARY - 79))
      | (1ULL << (PotatoSQLParser::K_NULL - 79))
      | (1ULL << (PotatoSQLParser::K_CHECK - 79))
      | (1ULL << (PotatoSQLParser::K_COLLATE - 79))
      | (1ULL << (PotatoSQLParser::K_REFERENCES - 79)))) != 0)) {
      setState(745);
      column_constraint();
      setState(750);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

PotatoSQLParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::NameContext *> PotatoSQLParser::Type_nameContext::name() {
  return getRuleContexts<PotatoSQLParser::NameContext>();
}

PotatoSQLParser::NameContext* PotatoSQLParser::Type_nameContext::name(size_t i) {
  return getRuleContext<PotatoSQLParser::NameContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Type_nameContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Signed_numberContext *> PotatoSQLParser::Type_nameContext::signed_number() {
  return getRuleContexts<PotatoSQLParser::Signed_numberContext>();
}

PotatoSQLParser::Signed_numberContext* PotatoSQLParser::Type_nameContext::signed_number(size_t i) {
  return getRuleContext<PotatoSQLParser::Signed_numberContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Type_nameContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Type_nameContext::COMMA() {
  return getToken(PotatoSQLParser::COMMA, 0);
}


size_t PotatoSQLParser::Type_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleType_name;
}


PotatoSQLParser::Type_nameContext* PotatoSQLParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 46, PotatoSQLParser::RuleType_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(752); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(751);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(754); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx);
    } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(766);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
    case 1: {
      setState(756);
      match(PotatoSQLParser::OPEN_PAR);
      setState(757);
      signed_number();
      setState(758);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(760);
      match(PotatoSQLParser::OPEN_PAR);
      setState(761);
      signed_number();
      setState(762);
      match(PotatoSQLParser::COMMA);
      setState(763);
      signed_number();
      setState(764);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_constraintContext ------------------------------------------------------------------

PotatoSQLParser::Column_constraintContext::Column_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_PRIMARY() {
  return getToken(PotatoSQLParser::K_PRIMARY, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_KEY() {
  return getToken(PotatoSQLParser::K_KEY, 0);
}

PotatoSQLParser::Conflict_clauseContext* PotatoSQLParser::Column_constraintContext::conflict_clause() {
  return getRuleContext<PotatoSQLParser::Conflict_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_NULL() {
  return getToken(PotatoSQLParser::K_NULL, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_UNIQUE() {
  return getToken(PotatoSQLParser::K_UNIQUE, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_CHECK() {
  return getToken(PotatoSQLParser::K_CHECK, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Column_constraintContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_DEFAULT() {
  return getToken(PotatoSQLParser::K_DEFAULT, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_COLLATE() {
  return getToken(PotatoSQLParser::K_COLLATE, 0);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::Column_constraintContext::collation_name() {
  return getRuleContext<PotatoSQLParser::Collation_nameContext>(0);
}

PotatoSQLParser::Foreign_key_clauseContext* PotatoSQLParser::Column_constraintContext::foreign_key_clause() {
  return getRuleContext<PotatoSQLParser::Foreign_key_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_CONSTRAINT() {
  return getToken(PotatoSQLParser::K_CONSTRAINT, 0);
}

PotatoSQLParser::NameContext* PotatoSQLParser::Column_constraintContext::name() {
  return getRuleContext<PotatoSQLParser::NameContext>(0);
}

PotatoSQLParser::Signed_numberContext* PotatoSQLParser::Column_constraintContext::signed_number() {
  return getRuleContext<PotatoSQLParser::Signed_numberContext>(0);
}

PotatoSQLParser::Literal_valueContext* PotatoSQLParser::Column_constraintContext::literal_value() {
  return getRuleContext<PotatoSQLParser::Literal_valueContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_AUTOINCREMENT() {
  return getToken(PotatoSQLParser::K_AUTOINCREMENT, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_ASC() {
  return getToken(PotatoSQLParser::K_ASC, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_constraintContext::K_DESC() {
  return getToken(PotatoSQLParser::K_DESC, 0);
}


size_t PotatoSQLParser::Column_constraintContext::getRuleIndex() const {
  return PotatoSQLParser::RuleColumn_constraint;
}


PotatoSQLParser::Column_constraintContext* PotatoSQLParser::column_constraint() {
  Column_constraintContext *_localctx = _tracker.createInstance<Column_constraintContext>(_ctx, getState());
  enterRule(_localctx, 48, PotatoSQLParser::RuleColumn_constraint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(770);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(768);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(769);
      name();
    }
    setState(805);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY: {
        setState(772);
        match(PotatoSQLParser::K_PRIMARY);
        setState(773);
        match(PotatoSQLParser::K_KEY);
        setState(775);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC) {
          setState(774);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(777);
        conflict_clause();
        setState(779);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AUTOINCREMENT) {
          setState(778);
          match(PotatoSQLParser::K_AUTOINCREMENT);
        }
        break;
      }

      case PotatoSQLParser::K_NOT:
      case PotatoSQLParser::K_NULL: {
        setState(782);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(781);
          match(PotatoSQLParser::K_NOT);
        }
        setState(784);
        match(PotatoSQLParser::K_NULL);
        setState(785);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_UNIQUE: {
        setState(786);
        match(PotatoSQLParser::K_UNIQUE);
        setState(787);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(788);
        match(PotatoSQLParser::K_CHECK);
        setState(789);
        match(PotatoSQLParser::OPEN_PAR);
        setState(790);
        expr(0);
        setState(791);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_DEFAULT: {
        setState(793);
        match(PotatoSQLParser::K_DEFAULT);
        setState(800);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
        case 1: {
          setState(794);
          signed_number();
          break;
        }

        case 2: {
          setState(795);
          literal_value();
          break;
        }

        case 3: {
          setState(796);
          match(PotatoSQLParser::OPEN_PAR);
          setState(797);
          expr(0);
          setState(798);
          match(PotatoSQLParser::CLOSE_PAR);
          break;
        }

        default:
          break;
        }
        break;
      }

      case PotatoSQLParser::K_COLLATE: {
        setState(802);
        match(PotatoSQLParser::K_COLLATE);
        setState(803);
        collation_name();
        break;
      }

      case PotatoSQLParser::K_REFERENCES: {
        setState(804);
        foreign_key_clause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conflict_clauseContext ------------------------------------------------------------------

PotatoSQLParser::Conflict_clauseContext::Conflict_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_ON() {
  return getToken(PotatoSQLParser::K_ON, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_CONFLICT() {
  return getToken(PotatoSQLParser::K_CONFLICT, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

tree::TerminalNode* PotatoSQLParser::Conflict_clauseContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}


size_t PotatoSQLParser::Conflict_clauseContext::getRuleIndex() const {
  return PotatoSQLParser::RuleConflict_clause;
}


PotatoSQLParser::Conflict_clauseContext* PotatoSQLParser::conflict_clause() {
  Conflict_clauseContext *_localctx = _tracker.createInstance<Conflict_clauseContext>(_ctx, getState());
  enterRule(_localctx, 50, PotatoSQLParser::RuleConflict_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(810);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ON) {
      setState(807);
      match(PotatoSQLParser::K_ON);
      setState(808);
      match(PotatoSQLParser::K_CONFLICT);
      setState(809);
      _la = _input->LA(1);
      if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (PotatoSQLParser::K_REPLACE - 72))
        | (1ULL << (PotatoSQLParser::K_ROLLBACK - 72))
        | (1ULL << (PotatoSQLParser::K_ABORT - 72))
        | (1ULL << (PotatoSQLParser::K_FAIL - 72))
        | (1ULL << (PotatoSQLParser::K_IGNORE - 72)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

PotatoSQLParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Literal_valueContext* PotatoSQLParser::ExprContext::literal_value() {
  return getRuleContext<PotatoSQLParser::Literal_valueContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::BIND_PARAMETER() {
  return getToken(PotatoSQLParser::BIND_PARAMETER, 0);
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::ExprContext::column_name() {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::ExprContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::ExprContext::DOT() {
  return getTokens(PotatoSQLParser::DOT);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::DOT(size_t i) {
  return getToken(PotatoSQLParser::DOT, i);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::ExprContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

PotatoSQLParser::Unary_operatorContext* PotatoSQLParser::ExprContext::unary_operator() {
  return getRuleContext<PotatoSQLParser::Unary_operatorContext>(0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::ExprContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::ExprContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

PotatoSQLParser::Function_nameContext* PotatoSQLParser::ExprContext::function_name() {
  return getRuleContext<PotatoSQLParser::Function_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::STAR() {
  return getToken(PotatoSQLParser::STAR, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_DISTINCT() {
  return getToken(PotatoSQLParser::K_DISTINCT, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::ExprContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_CAST() {
  return getToken(PotatoSQLParser::K_CAST, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

PotatoSQLParser::Type_nameContext* PotatoSQLParser::ExprContext::type_name() {
  return getRuleContext<PotatoSQLParser::Type_nameContext>(0);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::ExprContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_CASE() {
  return getToken(PotatoSQLParser::K_CASE, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_END() {
  return getToken(PotatoSQLParser::K_END, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::ExprContext::K_WHEN() {
  return getTokens(PotatoSQLParser::K_WHEN);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_WHEN(size_t i) {
  return getToken(PotatoSQLParser::K_WHEN, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::ExprContext::K_THEN() {
  return getTokens(PotatoSQLParser::K_THEN);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_THEN(size_t i) {
  return getToken(PotatoSQLParser::K_THEN, i);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_ELSE() {
  return getToken(PotatoSQLParser::K_ELSE, 0);
}

PotatoSQLParser::Raise_functionContext* PotatoSQLParser::ExprContext::raise_function() {
  return getRuleContext<PotatoSQLParser::Raise_functionContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::PIPE2() {
  return getToken(PotatoSQLParser::PIPE2, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::DIV() {
  return getToken(PotatoSQLParser::DIV, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::MOD() {
  return getToken(PotatoSQLParser::MOD, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::PLUS() {
  return getToken(PotatoSQLParser::PLUS, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::MINUS() {
  return getToken(PotatoSQLParser::MINUS, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::LT2() {
  return getToken(PotatoSQLParser::LT2, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::GT2() {
  return getToken(PotatoSQLParser::GT2, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::AMP() {
  return getToken(PotatoSQLParser::AMP, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::PIPE() {
  return getToken(PotatoSQLParser::PIPE, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::LT() {
  return getToken(PotatoSQLParser::LT, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::LT_EQ() {
  return getToken(PotatoSQLParser::LT_EQ, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::GT() {
  return getToken(PotatoSQLParser::GT, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::GT_EQ() {
  return getToken(PotatoSQLParser::GT_EQ, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::ASSIGN() {
  return getToken(PotatoSQLParser::ASSIGN, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::EQ() {
  return getToken(PotatoSQLParser::EQ, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::NOT_EQ1() {
  return getToken(PotatoSQLParser::NOT_EQ1, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::NOT_EQ2() {
  return getToken(PotatoSQLParser::NOT_EQ2, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_AND() {
  return getToken(PotatoSQLParser::K_AND, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_IS() {
  return getToken(PotatoSQLParser::K_IS, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_BETWEEN() {
  return getToken(PotatoSQLParser::K_BETWEEN, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_IN() {
  return getToken(PotatoSQLParser::K_IN, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_COLLATE() {
  return getToken(PotatoSQLParser::K_COLLATE, 0);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::ExprContext::collation_name() {
  return getRuleContext<PotatoSQLParser::Collation_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_LIKE() {
  return getToken(PotatoSQLParser::K_LIKE, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_GLOB() {
  return getToken(PotatoSQLParser::K_GLOB, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_REGEXP() {
  return getToken(PotatoSQLParser::K_REGEXP, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_MATCH() {
  return getToken(PotatoSQLParser::K_MATCH, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_ESCAPE() {
  return getToken(PotatoSQLParser::K_ESCAPE, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_ISNULL() {
  return getToken(PotatoSQLParser::K_ISNULL, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_NOTNULL() {
  return getToken(PotatoSQLParser::K_NOTNULL, 0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::K_NULL() {
  return getToken(PotatoSQLParser::K_NULL, 0);
}


size_t PotatoSQLParser::ExprContext::getRuleIndex() const {
  return PotatoSQLParser::RuleExpr;
}



PotatoSQLParser::ExprContext* PotatoSQLParser::expr() {
   return expr(0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PotatoSQLParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  PotatoSQLParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, PotatoSQLParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(888);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 119, _ctx)) {
    case 1: {
      setState(813);
      literal_value();
      break;
    }

    case 2: {
      setState(814);
      match(PotatoSQLParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(823);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
      case 1: {
        setState(818);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx)) {
        case 1: {
          setState(815);
          database_name();
          setState(816);
          match(PotatoSQLParser::DOT);
          break;
        }

        default:
          break;
        }
        setState(820);
        table_name();
        setState(821);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(825);
      column_name();
      break;
    }

    case 4: {
      setState(826);
      unary_operator();
      setState(827);
      expr(21);
      break;
    }

    case 5: {
      setState(829);
      function_name();
      setState(830);
      match(PotatoSQLParser::OPEN_PAR);
      setState(843);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::OPEN_PAR:
        case PotatoSQLParser::PLUS:
        case PotatoSQLParser::MINUS:
        case PotatoSQLParser::TILDE:
        case PotatoSQLParser::K_AND:
        case PotatoSQLParser::K_BEGIN:
        case PotatoSQLParser::K_NOT:
        case PotatoSQLParser::IDENTIFIER:
        case PotatoSQLParser::NUMERIC_LITERAL:
        case PotatoSQLParser::STRING_LITERAL:
        case PotatoSQLParser::BLOB_LITERAL:
        case PotatoSQLParser::K_ALTER:
        case PotatoSQLParser::K_EXISTS:
        case PotatoSQLParser::K_DISTINCT:
        case PotatoSQLParser::K_NULL:
        case PotatoSQLParser::BIND_PARAMETER:
        case PotatoSQLParser::K_CAST:
        case PotatoSQLParser::K_CASE:
        case PotatoSQLParser::K_RAISE:
        case PotatoSQLParser::K_CURRENT_TIME:
        case PotatoSQLParser::K_CURRENT_DATE:
        case PotatoSQLParser::K_CURRENT_TIMESTAMP: {
          setState(832);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_DISTINCT) {
            setState(831);
            match(PotatoSQLParser::K_DISTINCT);
          }
          setState(834);
          expr(0);
          setState(839);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(835);
            match(PotatoSQLParser::COMMA);
            setState(836);
            expr(0);
            setState(841);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case PotatoSQLParser::STAR: {
          setState(842);
          match(PotatoSQLParser::STAR);
          break;
        }

        case PotatoSQLParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(845);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 6: {
      setState(847);
      match(PotatoSQLParser::OPEN_PAR);
      setState(848);
      expr(0);
      setState(849);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(851);
      match(PotatoSQLParser::K_CAST);
      setState(852);
      match(PotatoSQLParser::OPEN_PAR);
      setState(853);
      expr(0);
      setState(854);
      match(PotatoSQLParser::K_AS);
      setState(855);
      type_name();
      setState(856);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 8: {
      setState(862);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_NOT

      || _la == PotatoSQLParser::K_EXISTS) {
        setState(859);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(858);
          match(PotatoSQLParser::K_NOT);
        }
        setState(861);
        match(PotatoSQLParser::K_EXISTS);
      }
      setState(864);
      match(PotatoSQLParser::OPEN_PAR);
      setState(865);
      select_stmt();
      setState(866);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 9: {
      setState(868);
      match(PotatoSQLParser::K_CASE);
      setState(870);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::PLUS)
        | (1ULL << PotatoSQLParser::MINUS)
        | (1ULL << PotatoSQLParser::TILDE)
        | (1ULL << PotatoSQLParser::K_AND)
        | (1ULL << PotatoSQLParser::K_BEGIN)
        | (1ULL << PotatoSQLParser::K_NOT)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::NUMERIC_LITERAL)
        | (1ULL << PotatoSQLParser::STRING_LITERAL)
        | (1ULL << PotatoSQLParser::BLOB_LITERAL)
        | (1ULL << PotatoSQLParser::K_ALTER)
        | (1ULL << PotatoSQLParser::K_EXISTS))) != 0) || ((((_la - 93) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 93)) & ((1ULL << (PotatoSQLParser::K_NULL - 93))
        | (1ULL << (PotatoSQLParser::BIND_PARAMETER - 93))
        | (1ULL << (PotatoSQLParser::K_CAST - 93))
        | (1ULL << (PotatoSQLParser::K_CASE - 93))
        | (1ULL << (PotatoSQLParser::K_RAISE - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_TIME - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_DATE - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_TIMESTAMP - 93)))) != 0)) {
        setState(869);
        expr(0);
      }
      setState(877); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(872);
        match(PotatoSQLParser::K_WHEN);
        setState(873);
        expr(0);
        setState(874);
        match(PotatoSQLParser::K_THEN);
        setState(875);
        expr(0);
        setState(879); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == PotatoSQLParser::K_WHEN);
      setState(883);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ELSE) {
        setState(881);
        match(PotatoSQLParser::K_ELSE);
        setState(882);
        expr(0);
      }
      setState(885);
      match(PotatoSQLParser::K_END);
      break;
    }

    case 10: {
      setState(887);
      raise_function();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(977);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(975);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(890);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(891);
          match(PotatoSQLParser::PIPE2);
          setState(892);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(893);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(894);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << PotatoSQLParser::STAR)
            | (1ULL << PotatoSQLParser::DIV)
            | (1ULL << PotatoSQLParser::MOD))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(895);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(896);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(897);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::PLUS

          || _la == PotatoSQLParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(898);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(899);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(900);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << PotatoSQLParser::LT2)
            | (1ULL << PotatoSQLParser::GT2)
            | (1ULL << PotatoSQLParser::AMP)
            | (1ULL << PotatoSQLParser::PIPE))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(901);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(902);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(903);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << PotatoSQLParser::LT)
            | (1ULL << PotatoSQLParser::LT_EQ)
            | (1ULL << PotatoSQLParser::GT)
            | (1ULL << PotatoSQLParser::GT_EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(904);
          expr(17);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(905);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(906);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << PotatoSQLParser::ASSIGN)
            | (1ULL << PotatoSQLParser::EQ)
            | (1ULL << PotatoSQLParser::NOT_EQ1)
            | (1ULL << PotatoSQLParser::NOT_EQ2))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(907);
          expr(16);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(908);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(909);
          match(PotatoSQLParser::K_AND);
          setState(910);
          expr(14);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(911);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(912);
          match(PotatoSQLParser::K_OR);
          setState(913);
          expr(13);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(914);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(915);
          match(PotatoSQLParser::K_IS);
          setState(917);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx)) {
          case 1: {
            setState(916);
            match(PotatoSQLParser::K_NOT);
            break;
          }

          default:
            break;
          }
          setState(919);
          expr(6);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(920);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(922);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(921);
            match(PotatoSQLParser::K_NOT);
          }
          setState(924);
          match(PotatoSQLParser::K_BETWEEN);
          setState(925);
          expr(0);
          setState(926);
          match(PotatoSQLParser::K_AND);
          setState(927);
          expr(5);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(929);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(931);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(930);
            match(PotatoSQLParser::K_NOT);
          }
          setState(933);
          match(PotatoSQLParser::K_IN);
          setState(953);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
          case 1: {
            setState(934);
            match(PotatoSQLParser::OPEN_PAR);
            setState(944);
            _errHandler->sync(this);
            switch (_input->LA(1)) {
              case PotatoSQLParser::K_VALUES:
              case PotatoSQLParser::K_SELECT:
              case PotatoSQLParser::K_WITH: {
                setState(935);
                select_stmt();
                break;
              }

              case PotatoSQLParser::OPEN_PAR:
              case PotatoSQLParser::PLUS:
              case PotatoSQLParser::MINUS:
              case PotatoSQLParser::TILDE:
              case PotatoSQLParser::K_AND:
              case PotatoSQLParser::K_BEGIN:
              case PotatoSQLParser::K_NOT:
              case PotatoSQLParser::IDENTIFIER:
              case PotatoSQLParser::NUMERIC_LITERAL:
              case PotatoSQLParser::STRING_LITERAL:
              case PotatoSQLParser::BLOB_LITERAL:
              case PotatoSQLParser::K_ALTER:
              case PotatoSQLParser::K_EXISTS:
              case PotatoSQLParser::K_NULL:
              case PotatoSQLParser::BIND_PARAMETER:
              case PotatoSQLParser::K_CAST:
              case PotatoSQLParser::K_CASE:
              case PotatoSQLParser::K_RAISE:
              case PotatoSQLParser::K_CURRENT_TIME:
              case PotatoSQLParser::K_CURRENT_DATE:
              case PotatoSQLParser::K_CURRENT_TIMESTAMP: {
                setState(936);
                expr(0);
                setState(941);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == PotatoSQLParser::COMMA) {
                  setState(937);
                  match(PotatoSQLParser::COMMA);
                  setState(938);
                  expr(0);
                  setState(943);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                break;
              }

              case PotatoSQLParser::CLOSE_PAR: {
                break;
              }

            default:
              break;
            }
            setState(946);
            match(PotatoSQLParser::CLOSE_PAR);
            break;
          }

          case 2: {
            setState(950);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
            case 1: {
              setState(947);
              database_name();
              setState(948);
              match(PotatoSQLParser::DOT);
              break;
            }

            default:
              break;
            }
            setState(952);
            table_name();
            break;
          }

          default:
            break;
          }
          break;
        }

        case 12: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(955);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(956);
          match(PotatoSQLParser::K_COLLATE);
          setState(957);
          collation_name();
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(958);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(960);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(959);
            match(PotatoSQLParser::K_NOT);
          }
          setState(962);
          _la = _input->LA(1);
          if (!(((((_la - 106) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 106)) & ((1ULL << (PotatoSQLParser::K_LIKE - 106))
            | (1ULL << (PotatoSQLParser::K_GLOB - 106))
            | (1ULL << (PotatoSQLParser::K_REGEXP - 106))
            | (1ULL << (PotatoSQLParser::K_MATCH - 106)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(963);
          expr(0);
          setState(966);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
          case 1: {
            setState(964);
            match(PotatoSQLParser::K_ESCAPE);
            setState(965);
            expr(0);
            break;
          }

          default:
            break;
          }
          break;
        }

        case 14: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(968);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(973);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case PotatoSQLParser::K_ISNULL: {
              setState(969);
              match(PotatoSQLParser::K_ISNULL);
              break;
            }

            case PotatoSQLParser::K_NOTNULL: {
              setState(970);
              match(PotatoSQLParser::K_NOTNULL);
              break;
            }

            case PotatoSQLParser::K_NOT: {
              setState(971);
              match(PotatoSQLParser::K_NOT);
              setState(972);
              match(PotatoSQLParser::K_NULL);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(979);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Raise_functionContext ------------------------------------------------------------------

PotatoSQLParser::Raise_functionContext::Raise_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::K_RAISE() {
  return getToken(PotatoSQLParser::K_RAISE, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::COMMA() {
  return getToken(PotatoSQLParser::COMMA, 0);
}

PotatoSQLParser::Error_messageContext* PotatoSQLParser::Raise_functionContext::error_message() {
  return getRuleContext<PotatoSQLParser::Error_messageContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Raise_functionContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}


size_t PotatoSQLParser::Raise_functionContext::getRuleIndex() const {
  return PotatoSQLParser::RuleRaise_function;
}


PotatoSQLParser::Raise_functionContext* PotatoSQLParser::raise_function() {
  Raise_functionContext *_localctx = _tracker.createInstance<Raise_functionContext>(_ctx, getState());
  enterRule(_localctx, 54, PotatoSQLParser::RuleRaise_function);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(980);
    match(PotatoSQLParser::K_RAISE);
    setState(981);
    match(PotatoSQLParser::OPEN_PAR);
    setState(986);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_IGNORE: {
        setState(982);
        match(PotatoSQLParser::K_IGNORE);
        break;
      }

      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_ABORT:
      case PotatoSQLParser::K_FAIL: {
        setState(983);
        _la = _input->LA(1);
        if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 73)) & ((1ULL << (PotatoSQLParser::K_ROLLBACK - 73))
          | (1ULL << (PotatoSQLParser::K_ABORT - 73))
          | (1ULL << (PotatoSQLParser::K_FAIL - 73)))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(984);
        match(PotatoSQLParser::COMMA);
        setState(985);
        error_message();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(988);
    match(PotatoSQLParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_key_clauseContext ------------------------------------------------------------------

PotatoSQLParser::Foreign_key_clauseContext::Foreign_key_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_REFERENCES() {
  return getToken(PotatoSQLParser::K_REFERENCES, 0);
}

PotatoSQLParser::Foreign_tableContext* PotatoSQLParser::Foreign_key_clauseContext::foreign_table() {
  return getRuleContext<PotatoSQLParser::Foreign_tableContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Foreign_key_clauseContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Foreign_key_clauseContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_DEFERRABLE() {
  return getToken(PotatoSQLParser::K_DEFERRABLE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_ON() {
  return getTokens(PotatoSQLParser::K_ON);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_ON(size_t i) {
  return getToken(PotatoSQLParser::K_ON, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_MATCH() {
  return getTokens(PotatoSQLParser::K_MATCH);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_MATCH(size_t i) {
  return getToken(PotatoSQLParser::K_MATCH, i);
}

std::vector<PotatoSQLParser::NameContext *> PotatoSQLParser::Foreign_key_clauseContext::name() {
  return getRuleContexts<PotatoSQLParser::NameContext>();
}

PotatoSQLParser::NameContext* PotatoSQLParser::Foreign_key_clauseContext::name(size_t i) {
  return getRuleContext<PotatoSQLParser::NameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_DELETE() {
  return getTokens(PotatoSQLParser::K_DELETE);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_DELETE(size_t i) {
  return getToken(PotatoSQLParser::K_DELETE, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_UPDATE() {
  return getTokens(PotatoSQLParser::K_UPDATE);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_UPDATE(size_t i) {
  return getToken(PotatoSQLParser::K_UPDATE, i);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_INITIALLY() {
  return getToken(PotatoSQLParser::K_INITIALLY, 0);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_DEFERRED() {
  return getToken(PotatoSQLParser::K_DEFERRED, 0);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_IMMEDIATE() {
  return getToken(PotatoSQLParser::K_IMMEDIATE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_SET() {
  return getTokens(PotatoSQLParser::K_SET);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_SET(size_t i) {
  return getToken(PotatoSQLParser::K_SET, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_NULL() {
  return getTokens(PotatoSQLParser::K_NULL);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_NULL(size_t i) {
  return getToken(PotatoSQLParser::K_NULL, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_DEFAULT() {
  return getTokens(PotatoSQLParser::K_DEFAULT);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_DEFAULT(size_t i) {
  return getToken(PotatoSQLParser::K_DEFAULT, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_CASCADE() {
  return getTokens(PotatoSQLParser::K_CASCADE);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_CASCADE(size_t i) {
  return getToken(PotatoSQLParser::K_CASCADE, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_RESTRICT() {
  return getTokens(PotatoSQLParser::K_RESTRICT);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_RESTRICT(size_t i) {
  return getToken(PotatoSQLParser::K_RESTRICT, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_NO() {
  return getTokens(PotatoSQLParser::K_NO);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_NO(size_t i) {
  return getToken(PotatoSQLParser::K_NO, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Foreign_key_clauseContext::K_ACTION() {
  return getTokens(PotatoSQLParser::K_ACTION);
}

tree::TerminalNode* PotatoSQLParser::Foreign_key_clauseContext::K_ACTION(size_t i) {
  return getToken(PotatoSQLParser::K_ACTION, i);
}


size_t PotatoSQLParser::Foreign_key_clauseContext::getRuleIndex() const {
  return PotatoSQLParser::RuleForeign_key_clause;
}


PotatoSQLParser::Foreign_key_clauseContext* PotatoSQLParser::foreign_key_clause() {
  Foreign_key_clauseContext *_localctx = _tracker.createInstance<Foreign_key_clauseContext>(_ctx, getState());
  enterRule(_localctx, 56, PotatoSQLParser::RuleForeign_key_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(990);
    match(PotatoSQLParser::K_REFERENCES);
    setState(991);
    foreign_table();
    setState(1003);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(992);
      match(PotatoSQLParser::OPEN_PAR);
      setState(993);
      column_name();
      setState(998);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(994);
        match(PotatoSQLParser::COMMA);
        setState(995);
        column_name();
        setState(1000);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1001);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1023);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_ON || _la == PotatoSQLParser::K_MATCH) {
      setState(1019);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_ON: {
          setState(1005);
          match(PotatoSQLParser::K_ON);
          setState(1006);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_DELETE

          || _la == PotatoSQLParser::K_UPDATE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1015);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
          case 1: {
            setState(1007);
            match(PotatoSQLParser::K_SET);
            setState(1008);
            match(PotatoSQLParser::K_NULL);
            break;
          }

          case 2: {
            setState(1009);
            match(PotatoSQLParser::K_SET);
            setState(1010);
            match(PotatoSQLParser::K_DEFAULT);
            break;
          }

          case 3: {
            setState(1011);
            match(PotatoSQLParser::K_CASCADE);
            break;
          }

          case 4: {
            setState(1012);
            match(PotatoSQLParser::K_RESTRICT);
            break;
          }

          case 5: {
            setState(1013);
            match(PotatoSQLParser::K_NO);
            setState(1014);
            match(PotatoSQLParser::K_ACTION);
            break;
          }

          default:
            break;
          }
          break;
        }

        case PotatoSQLParser::K_MATCH: {
          setState(1017);
          match(PotatoSQLParser::K_MATCH);
          setState(1018);
          name();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1025);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1036);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx)) {
    case 1: {
      setState(1027);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_NOT) {
        setState(1026);
        match(PotatoSQLParser::K_NOT);
      }
      setState(1029);
      match(PotatoSQLParser::K_DEFERRABLE);
      setState(1034);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
      case 1: {
        setState(1030);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1031);
        match(PotatoSQLParser::K_DEFERRED);
        break;
      }

      case 2: {
        setState(1032);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1033);
        match(PotatoSQLParser::K_IMMEDIATE);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indexed_columnContext ------------------------------------------------------------------

PotatoSQLParser::Indexed_columnContext::Indexed_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Indexed_columnContext::column_name() {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Indexed_columnContext::K_COLLATE() {
  return getToken(PotatoSQLParser::K_COLLATE, 0);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::Indexed_columnContext::collation_name() {
  return getRuleContext<PotatoSQLParser::Collation_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Indexed_columnContext::K_ASC() {
  return getToken(PotatoSQLParser::K_ASC, 0);
}

tree::TerminalNode* PotatoSQLParser::Indexed_columnContext::K_DESC() {
  return getToken(PotatoSQLParser::K_DESC, 0);
}


size_t PotatoSQLParser::Indexed_columnContext::getRuleIndex() const {
  return PotatoSQLParser::RuleIndexed_column;
}


PotatoSQLParser::Indexed_columnContext* PotatoSQLParser::indexed_column() {
  Indexed_columnContext *_localctx = _tracker.createInstance<Indexed_columnContext>(_ctx, getState());
  enterRule(_localctx, 58, PotatoSQLParser::RuleIndexed_column);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1038);
    column_name();
    setState(1041);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1039);
      match(PotatoSQLParser::K_COLLATE);
      setState(1040);
      collation_name();
    }
    setState(1044);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC) {
      setState(1043);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_constraintContext ------------------------------------------------------------------

PotatoSQLParser::Table_constraintContext::Table_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Indexed_columnContext *> PotatoSQLParser::Table_constraintContext::indexed_column() {
  return getRuleContexts<PotatoSQLParser::Indexed_columnContext>();
}

PotatoSQLParser::Indexed_columnContext* PotatoSQLParser::Table_constraintContext::indexed_column(size_t i) {
  return getRuleContext<PotatoSQLParser::Indexed_columnContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

PotatoSQLParser::Conflict_clauseContext* PotatoSQLParser::Table_constraintContext::conflict_clause() {
  return getRuleContext<PotatoSQLParser::Conflict_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_CHECK() {
  return getToken(PotatoSQLParser::K_CHECK, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Table_constraintContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_FOREIGN() {
  return getToken(PotatoSQLParser::K_FOREIGN, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_KEY() {
  return getToken(PotatoSQLParser::K_KEY, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Table_constraintContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Table_constraintContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

PotatoSQLParser::Foreign_key_clauseContext* PotatoSQLParser::Table_constraintContext::foreign_key_clause() {
  return getRuleContext<PotatoSQLParser::Foreign_key_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_CONSTRAINT() {
  return getToken(PotatoSQLParser::K_CONSTRAINT, 0);
}

PotatoSQLParser::NameContext* PotatoSQLParser::Table_constraintContext::name() {
  return getRuleContext<PotatoSQLParser::NameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_PRIMARY() {
  return getToken(PotatoSQLParser::K_PRIMARY, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::K_UNIQUE() {
  return getToken(PotatoSQLParser::K_UNIQUE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Table_constraintContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Table_constraintContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Table_constraintContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_constraint;
}


PotatoSQLParser::Table_constraintContext* PotatoSQLParser::table_constraint() {
  Table_constraintContext *_localctx = _tracker.createInstance<Table_constraintContext>(_ctx, getState());
  enterRule(_localctx, 60, PotatoSQLParser::RuleTable_constraint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1048);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1046);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1047);
      name();
    }
    setState(1086);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_UNIQUE:
      case PotatoSQLParser::K_PRIMARY: {
        setState(1053);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_PRIMARY: {
            setState(1050);
            match(PotatoSQLParser::K_PRIMARY);
            setState(1051);
            match(PotatoSQLParser::K_KEY);
            break;
          }

          case PotatoSQLParser::K_UNIQUE: {
            setState(1052);
            match(PotatoSQLParser::K_UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1055);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1056);
        indexed_column();
        setState(1061);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1057);
          match(PotatoSQLParser::COMMA);
          setState(1058);
          indexed_column();
          setState(1063);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1064);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1065);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1067);
        match(PotatoSQLParser::K_CHECK);
        setState(1068);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1069);
        expr(0);
        setState(1070);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_FOREIGN: {
        setState(1072);
        match(PotatoSQLParser::K_FOREIGN);
        setState(1073);
        match(PotatoSQLParser::K_KEY);
        setState(1074);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1075);
        column_name();
        setState(1080);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1076);
          match(PotatoSQLParser::COMMA);
          setState(1077);
          column_name();
          setState(1082);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1083);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1084);
        foreign_key_clause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- With_clauseContext ------------------------------------------------------------------

PotatoSQLParser::With_clauseContext::With_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::With_clauseContext::K_WITH() {
  return getToken(PotatoSQLParser::K_WITH, 0);
}

std::vector<PotatoSQLParser::Common_table_expressionContext *> PotatoSQLParser::With_clauseContext::common_table_expression() {
  return getRuleContexts<PotatoSQLParser::Common_table_expressionContext>();
}

PotatoSQLParser::Common_table_expressionContext* PotatoSQLParser::With_clauseContext::common_table_expression(size_t i) {
  return getRuleContext<PotatoSQLParser::Common_table_expressionContext>(i);
}

tree::TerminalNode* PotatoSQLParser::With_clauseContext::K_RECURSIVE() {
  return getToken(PotatoSQLParser::K_RECURSIVE, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::With_clauseContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::With_clauseContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::With_clauseContext::getRuleIndex() const {
  return PotatoSQLParser::RuleWith_clause;
}


PotatoSQLParser::With_clauseContext* PotatoSQLParser::with_clause() {
  With_clauseContext *_localctx = _tracker.createInstance<With_clauseContext>(_ctx, getState());
  enterRule(_localctx, 62, PotatoSQLParser::RuleWith_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1088);
    match(PotatoSQLParser::K_WITH);
    setState(1090);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_RECURSIVE) {
      setState(1089);
      match(PotatoSQLParser::K_RECURSIVE);
    }
    setState(1092);
    common_table_expression();
    setState(1097);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1093);
      match(PotatoSQLParser::COMMA);
      setState(1094);
      common_table_expression();
      setState(1099);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Qualified_table_nameContext ------------------------------------------------------------------

PotatoSQLParser::Qualified_table_nameContext::Qualified_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Qualified_table_nameContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Qualified_table_nameContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Qualified_table_nameContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Qualified_table_nameContext::K_INDEXED() {
  return getToken(PotatoSQLParser::K_INDEXED, 0);
}

tree::TerminalNode* PotatoSQLParser::Qualified_table_nameContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::Qualified_table_nameContext::index_name() {
  return getRuleContext<PotatoSQLParser::Index_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Qualified_table_nameContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}


size_t PotatoSQLParser::Qualified_table_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleQualified_table_name;
}


PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::qualified_table_name() {
  Qualified_table_nameContext *_localctx = _tracker.createInstance<Qualified_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 64, PotatoSQLParser::RuleQualified_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1103);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
    case 1: {
      setState(1100);
      database_name();
      setState(1101);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(1105);
    table_name();
    setState(1111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_INDEXED: {
        setState(1106);
        match(PotatoSQLParser::K_INDEXED);
        setState(1107);
        match(PotatoSQLParser::K_BY);
        setState(1108);
        index_name();
        break;
      }

      case PotatoSQLParser::K_NOT: {
        setState(1109);
        match(PotatoSQLParser::K_NOT);
        setState(1110);
        match(PotatoSQLParser::K_INDEXED);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_LIMIT:
      case PotatoSQLParser::K_ORDER:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_WHERE:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_SET:
      case PotatoSQLParser::K_WITH: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ordering_termContext ------------------------------------------------------------------

PotatoSQLParser::Ordering_termContext::Ordering_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Ordering_termContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Ordering_termContext::K_COLLATE() {
  return getToken(PotatoSQLParser::K_COLLATE, 0);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::Ordering_termContext::collation_name() {
  return getRuleContext<PotatoSQLParser::Collation_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Ordering_termContext::K_ASC() {
  return getToken(PotatoSQLParser::K_ASC, 0);
}

tree::TerminalNode* PotatoSQLParser::Ordering_termContext::K_DESC() {
  return getToken(PotatoSQLParser::K_DESC, 0);
}


size_t PotatoSQLParser::Ordering_termContext::getRuleIndex() const {
  return PotatoSQLParser::RuleOrdering_term;
}


PotatoSQLParser::Ordering_termContext* PotatoSQLParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 66, PotatoSQLParser::RuleOrdering_term);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1113);
    expr(0);
    setState(1116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1114);
      match(PotatoSQLParser::K_COLLATE);
      setState(1115);
      collation_name();
    }
    setState(1119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC) {
      setState(1118);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ASC || _la == PotatoSQLParser::K_DESC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_valueContext ------------------------------------------------------------------

PotatoSQLParser::Pragma_valueContext::Pragma_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Signed_numberContext* PotatoSQLParser::Pragma_valueContext::signed_number() {
  return getRuleContext<PotatoSQLParser::Signed_numberContext>(0);
}

PotatoSQLParser::NameContext* PotatoSQLParser::Pragma_valueContext::name() {
  return getRuleContext<PotatoSQLParser::NameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Pragma_valueContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}


size_t PotatoSQLParser::Pragma_valueContext::getRuleIndex() const {
  return PotatoSQLParser::RulePragma_value;
}


PotatoSQLParser::Pragma_valueContext* PotatoSQLParser::pragma_value() {
  Pragma_valueContext *_localctx = _tracker.createInstance<Pragma_valueContext>(_ctx, getState());
  enterRule(_localctx, 68, PotatoSQLParser::RulePragma_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1124);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1121);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1122);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1123);
      match(PotatoSQLParser::STRING_LITERAL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Common_table_expressionContext ------------------------------------------------------------------

PotatoSQLParser::Common_table_expressionContext::Common_table_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Common_table_expressionContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Common_table_expressionContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Common_table_expressionContext::OPEN_PAR() {
  return getTokens(PotatoSQLParser::OPEN_PAR);
}

tree::TerminalNode* PotatoSQLParser::Common_table_expressionContext::OPEN_PAR(size_t i) {
  return getToken(PotatoSQLParser::OPEN_PAR, i);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Common_table_expressionContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Common_table_expressionContext::CLOSE_PAR() {
  return getTokens(PotatoSQLParser::CLOSE_PAR);
}

tree::TerminalNode* PotatoSQLParser::Common_table_expressionContext::CLOSE_PAR(size_t i) {
  return getToken(PotatoSQLParser::CLOSE_PAR, i);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Common_table_expressionContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Common_table_expressionContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Common_table_expressionContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Common_table_expressionContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Common_table_expressionContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCommon_table_expression;
}


PotatoSQLParser::Common_table_expressionContext* PotatoSQLParser::common_table_expression() {
  Common_table_expressionContext *_localctx = _tracker.createInstance<Common_table_expressionContext>(_ctx, getState());
  enterRule(_localctx, 70, PotatoSQLParser::RuleCommon_table_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1126);
    table_name();
    setState(1138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1127);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1128);
      column_name();
      setState(1133);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1129);
        match(PotatoSQLParser::COMMA);
        setState(1130);
        column_name();
        setState(1135);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1136);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1140);
    match(PotatoSQLParser::K_AS);
    setState(1141);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1142);
    select_stmt();
    setState(1143);
    match(PotatoSQLParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

PotatoSQLParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Result_columnContext::STAR() {
  return getToken(PotatoSQLParser::STAR, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Result_columnContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Result_columnContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Result_columnContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

PotatoSQLParser::Column_aliasContext* PotatoSQLParser::Result_columnContext::column_alias() {
  return getRuleContext<PotatoSQLParser::Column_aliasContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Result_columnContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}


size_t PotatoSQLParser::Result_columnContext::getRuleIndex() const {
  return PotatoSQLParser::RuleResult_column;
}


PotatoSQLParser::Result_columnContext* PotatoSQLParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 72, PotatoSQLParser::RuleResult_column);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1145);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1146);
      table_name();
      setState(1147);
      match(PotatoSQLParser::DOT);
      setState(1148);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1150);
      expr(0);
      setState(1155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_AS)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::STRING_LITERAL))) != 0)) {
        setState(1152);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1151);
          match(PotatoSQLParser::K_AS);
        }
        setState(1154);
        column_alias();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_subqueryContext ------------------------------------------------------------------

PotatoSQLParser::Table_or_subqueryContext::Table_or_subqueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Table_or_subqueryContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

PotatoSQLParser::Schema_nameContext* PotatoSQLParser::Table_or_subqueryContext::schema_name() {
  return getRuleContext<PotatoSQLParser::Schema_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

PotatoSQLParser::Table_aliasContext* PotatoSQLParser::Table_or_subqueryContext::table_alias() {
  return getRuleContext<PotatoSQLParser::Table_aliasContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::K_INDEXED() {
  return getToken(PotatoSQLParser::K_INDEXED, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::Table_or_subqueryContext::index_name() {
  return getRuleContext<PotatoSQLParser::Index_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

PotatoSQLParser::Table_function_nameContext* PotatoSQLParser::Table_or_subqueryContext::table_function_name() {
  return getRuleContext<PotatoSQLParser::Table_function_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Table_or_subqueryContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Table_or_subqueryContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Table_or_subqueryContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Table_or_subqueryContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

std::vector<PotatoSQLParser::Table_or_subqueryContext *> PotatoSQLParser::Table_or_subqueryContext::table_or_subquery() {
  return getRuleContexts<PotatoSQLParser::Table_or_subqueryContext>();
}

PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::Table_or_subqueryContext::table_or_subquery(size_t i) {
  return getRuleContext<PotatoSQLParser::Table_or_subqueryContext>(i);
}

PotatoSQLParser::Join_clauseContext* PotatoSQLParser::Table_or_subqueryContext::join_clause() {
  return getRuleContext<PotatoSQLParser::Join_clauseContext>(0);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Table_or_subqueryContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}


size_t PotatoSQLParser::Table_or_subqueryContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_or_subquery;
}


PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 74, PotatoSQLParser::RuleTable_or_subquery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1225);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1162);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx)) {
      case 1: {
        setState(1159);
        schema_name();
        setState(1160);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1164);
      table_name();
      setState(1169);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::K_AS)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::STRING_LITERAL))) != 0)) {
        setState(1166);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1165);
          match(PotatoSQLParser::K_AS);
        }
        setState(1168);
        table_alias();
      }
      setState(1176);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_INDEXED: {
          setState(1171);
          match(PotatoSQLParser::K_INDEXED);
          setState(1172);
          match(PotatoSQLParser::K_BY);
          setState(1173);
          index_name();
          break;
        }

        case PotatoSQLParser::K_NOT: {
          setState(1174);
          match(PotatoSQLParser::K_NOT);
          setState(1175);
          match(PotatoSQLParser::K_INDEXED);
          break;
        }

        case PotatoSQLParser::EOF:
        case PotatoSQLParser::SCOL:
        case PotatoSQLParser::CLOSE_PAR:
        case PotatoSQLParser::COMMA:
        case PotatoSQLParser::K_BEGIN:
        case PotatoSQLParser::K_GROUP:
        case PotatoSQLParser::K_JOIN:
        case PotatoSQLParser::K_LIMIT:
        case PotatoSQLParser::K_ON:
        case PotatoSQLParser::K_ORDER:
        case PotatoSQLParser::K_ALTER:
        case PotatoSQLParser::K_COMMIT:
        case PotatoSQLParser::K_END:
        case PotatoSQLParser::K_UNION:
        case PotatoSQLParser::K_INTERSECT:
        case PotatoSQLParser::K_EXCEPT:
        case PotatoSQLParser::K_CREATE:
        case PotatoSQLParser::K_WHERE:
        case PotatoSQLParser::K_DELETE:
        case PotatoSQLParser::K_DROP:
        case PotatoSQLParser::K_INSERT:
        case PotatoSQLParser::K_REPLACE:
        case PotatoSQLParser::K_ROLLBACK:
        case PotatoSQLParser::K_VALUES:
        case PotatoSQLParser::K_PRAGMA:
        case PotatoSQLParser::K_SELECT:
        case PotatoSQLParser::K_UPDATE:
        case PotatoSQLParser::K_WITH:
        case PotatoSQLParser::K_NATURAL:
        case PotatoSQLParser::K_LEFT:
        case PotatoSQLParser::K_INNER:
        case PotatoSQLParser::K_CROSS:
        case PotatoSQLParser::K_USING: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1181);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx)) {
      case 1: {
        setState(1178);
        schema_name();
        setState(1179);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1183);
      table_function_name();
      setState(1184);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::PLUS)
        | (1ULL << PotatoSQLParser::MINUS)
        | (1ULL << PotatoSQLParser::TILDE)
        | (1ULL << PotatoSQLParser::K_AND)
        | (1ULL << PotatoSQLParser::K_BEGIN)
        | (1ULL << PotatoSQLParser::K_NOT)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::NUMERIC_LITERAL)
        | (1ULL << PotatoSQLParser::STRING_LITERAL)
        | (1ULL << PotatoSQLParser::BLOB_LITERAL)
        | (1ULL << PotatoSQLParser::K_ALTER)
        | (1ULL << PotatoSQLParser::K_EXISTS))) != 0) || ((((_la - 93) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 93)) & ((1ULL << (PotatoSQLParser::K_NULL - 93))
        | (1ULL << (PotatoSQLParser::BIND_PARAMETER - 93))
        | (1ULL << (PotatoSQLParser::K_CAST - 93))
        | (1ULL << (PotatoSQLParser::K_CASE - 93))
        | (1ULL << (PotatoSQLParser::K_RAISE - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_TIME - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_DATE - 93))
        | (1ULL << (PotatoSQLParser::K_CURRENT_TIMESTAMP - 93)))) != 0)) {
        setState(1185);
        expr(0);
        setState(1190);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1186);
          match(PotatoSQLParser::COMMA);
          setState(1187);
          expr(0);
          setState(1192);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1195);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1200);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::K_AS)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::STRING_LITERAL))) != 0)) {
        setState(1197);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1196);
          match(PotatoSQLParser::K_AS);
        }
        setState(1199);
        table_alias();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1202);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1212);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx)) {
      case 1: {
        setState(1203);
        table_or_subquery();
        setState(1208);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1204);
          match(PotatoSQLParser::COMMA);
          setState(1205);
          table_or_subquery();
          setState(1210);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(1211);
        join_clause();
        break;
      }

      default:
        break;
      }
      setState(1214);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1216);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1217);
      select_stmt();
      setState(1218);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1223);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::K_AS)
        | (1ULL << PotatoSQLParser::IDENTIFIER)
        | (1ULL << PotatoSQLParser::STRING_LITERAL))) != 0)) {
        setState(1220);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1219);
          match(PotatoSQLParser::K_AS);
        }
        setState(1222);
        table_alias();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_clauseContext ------------------------------------------------------------------

PotatoSQLParser::Join_clauseContext::Join_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Table_or_subqueryContext *> PotatoSQLParser::Join_clauseContext::table_or_subquery() {
  return getRuleContexts<PotatoSQLParser::Table_or_subqueryContext>();
}

PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::Join_clauseContext::table_or_subquery(size_t i) {
  return getRuleContext<PotatoSQLParser::Table_or_subqueryContext>(i);
}

std::vector<PotatoSQLParser::Join_operatorContext *> PotatoSQLParser::Join_clauseContext::join_operator() {
  return getRuleContexts<PotatoSQLParser::Join_operatorContext>();
}

PotatoSQLParser::Join_operatorContext* PotatoSQLParser::Join_clauseContext::join_operator(size_t i) {
  return getRuleContext<PotatoSQLParser::Join_operatorContext>(i);
}

std::vector<PotatoSQLParser::Join_constraintContext *> PotatoSQLParser::Join_clauseContext::join_constraint() {
  return getRuleContexts<PotatoSQLParser::Join_constraintContext>();
}

PotatoSQLParser::Join_constraintContext* PotatoSQLParser::Join_clauseContext::join_constraint(size_t i) {
  return getRuleContext<PotatoSQLParser::Join_constraintContext>(i);
}


size_t PotatoSQLParser::Join_clauseContext::getRuleIndex() const {
  return PotatoSQLParser::RuleJoin_clause;
}


PotatoSQLParser::Join_clauseContext* PotatoSQLParser::join_clause() {
  Join_clauseContext *_localctx = _tracker.createInstance<Join_clauseContext>(_ctx, getState());
  enterRule(_localctx, 76, PotatoSQLParser::RuleJoin_clause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1227);
    table_or_subquery();
    setState(1234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA

    || _la == PotatoSQLParser::K_JOIN || ((((_la - 127) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 127)) & ((1ULL << (PotatoSQLParser::K_NATURAL - 127))
      | (1ULL << (PotatoSQLParser::K_LEFT - 127))
      | (1ULL << (PotatoSQLParser::K_INNER - 127))
      | (1ULL << (PotatoSQLParser::K_CROSS - 127)))) != 0)) {
      setState(1228);
      join_operator();
      setState(1229);
      table_or_subquery();
      setState(1230);
      join_constraint();
      setState(1236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_operatorContext ------------------------------------------------------------------

PotatoSQLParser::Join_operatorContext::Join_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::COMMA() {
  return getToken(PotatoSQLParser::COMMA, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_JOIN() {
  return getToken(PotatoSQLParser::K_JOIN, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_NATURAL() {
  return getToken(PotatoSQLParser::K_NATURAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_LEFT() {
  return getToken(PotatoSQLParser::K_LEFT, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_INNER() {
  return getToken(PotatoSQLParser::K_INNER, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_CROSS() {
  return getToken(PotatoSQLParser::K_CROSS, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_operatorContext::K_OUTER() {
  return getToken(PotatoSQLParser::K_OUTER, 0);
}


size_t PotatoSQLParser::Join_operatorContext::getRuleIndex() const {
  return PotatoSQLParser::RuleJoin_operator;
}


PotatoSQLParser::Join_operatorContext* PotatoSQLParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 78, PotatoSQLParser::RuleJoin_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(1237);
        match(PotatoSQLParser::COMMA);
        break;
      }

      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_NATURAL:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_CROSS: {
        enterOuterAlt(_localctx, 2);
        setState(1239);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NATURAL) {
          setState(1238);
          match(PotatoSQLParser::K_NATURAL);
        }
        setState(1247);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_LEFT: {
            setState(1241);
            match(PotatoSQLParser::K_LEFT);
            setState(1243);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == PotatoSQLParser::K_OUTER) {
              setState(1242);
              match(PotatoSQLParser::K_OUTER);
            }
            break;
          }

          case PotatoSQLParser::K_INNER: {
            setState(1245);
            match(PotatoSQLParser::K_INNER);
            break;
          }

          case PotatoSQLParser::K_CROSS: {
            setState(1246);
            match(PotatoSQLParser::K_CROSS);
            break;
          }

          case PotatoSQLParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(1249);
        match(PotatoSQLParser::K_JOIN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_constraintContext ------------------------------------------------------------------

PotatoSQLParser::Join_constraintContext::Join_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Join_constraintContext::K_ON() {
  return getToken(PotatoSQLParser::K_ON, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Join_constraintContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Join_constraintContext::K_USING() {
  return getToken(PotatoSQLParser::K_USING, 0);
}

tree::TerminalNode* PotatoSQLParser::Join_constraintContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Join_constraintContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Join_constraintContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Join_constraintContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Join_constraintContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Join_constraintContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Join_constraintContext::getRuleIndex() const {
  return PotatoSQLParser::RuleJoin_constraint;
}


PotatoSQLParser::Join_constraintContext* PotatoSQLParser::join_constraint() {
  Join_constraintContext *_localctx = _tracker.createInstance<Join_constraintContext>(_ctx, getState());
  enterRule(_localctx, 80, PotatoSQLParser::RuleJoin_constraint);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_ON: {
        setState(1252);
        match(PotatoSQLParser::K_ON);
        setState(1253);
        expr(0);
        break;
      }

      case PotatoSQLParser::K_USING: {
        setState(1254);
        match(PotatoSQLParser::K_USING);
        setState(1255);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1256);
        column_name();
        setState(1261);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1257);
          match(PotatoSQLParser::COMMA);
          setState(1258);
          column_name();
          setState(1263);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1264);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::CLOSE_PAR:
      case PotatoSQLParser::COMMA:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_GROUP:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_LIMIT:
      case PotatoSQLParser::K_ORDER:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_UNION:
      case PotatoSQLParser::K_INTERSECT:
      case PotatoSQLParser::K_EXCEPT:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_WHERE:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_WITH:
      case PotatoSQLParser::K_NATURAL:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_CROSS: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

PotatoSQLParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_SELECT() {
  return getToken(PotatoSQLParser::K_SELECT, 0);
}

std::vector<PotatoSQLParser::Result_columnContext *> PotatoSQLParser::Select_coreContext::result_column() {
  return getRuleContexts<PotatoSQLParser::Result_columnContext>();
}

PotatoSQLParser::Result_columnContext* PotatoSQLParser::Select_coreContext::result_column(size_t i) {
  return getRuleContext<PotatoSQLParser::Result_columnContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_coreContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_FROM() {
  return getToken(PotatoSQLParser::K_FROM, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Select_coreContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_GROUP() {
  return getToken(PotatoSQLParser::K_GROUP, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_DISTINCT() {
  return getToken(PotatoSQLParser::K_DISTINCT, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_ALL() {
  return getToken(PotatoSQLParser::K_ALL, 0);
}

std::vector<PotatoSQLParser::Table_or_subqueryContext *> PotatoSQLParser::Select_coreContext::table_or_subquery() {
  return getRuleContexts<PotatoSQLParser::Table_or_subqueryContext>();
}

PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::Select_coreContext::table_or_subquery(size_t i) {
  return getRuleContext<PotatoSQLParser::Table_or_subqueryContext>(i);
}

PotatoSQLParser::Join_clauseContext* PotatoSQLParser::Select_coreContext::join_clause() {
  return getRuleContext<PotatoSQLParser::Join_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_HAVING() {
  return getToken(PotatoSQLParser::K_HAVING, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_VALUES() {
  return getToken(PotatoSQLParser::K_VALUES, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_coreContext::OPEN_PAR() {
  return getTokens(PotatoSQLParser::OPEN_PAR);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::OPEN_PAR(size_t i) {
  return getToken(PotatoSQLParser::OPEN_PAR, i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_coreContext::CLOSE_PAR() {
  return getTokens(PotatoSQLParser::CLOSE_PAR);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::CLOSE_PAR(size_t i) {
  return getToken(PotatoSQLParser::CLOSE_PAR, i);
}


size_t PotatoSQLParser::Select_coreContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSelect_core;
}


PotatoSQLParser::Select_coreContext* PotatoSQLParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 82, PotatoSQLParser::RuleSelect_core);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1342);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1268);
        match(PotatoSQLParser::K_SELECT);
        setState(1270);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ALL

        || _la == PotatoSQLParser::K_DISTINCT) {
          setState(1269);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ALL

          || _la == PotatoSQLParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(1272);
        result_column();
        setState(1277);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1273);
          match(PotatoSQLParser::COMMA);
          setState(1274);
          result_column();
          setState(1279);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1292);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(1280);
          match(PotatoSQLParser::K_FROM);
          setState(1290);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 184, _ctx)) {
          case 1: {
            setState(1281);
            table_or_subquery();
            setState(1286);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(1282);
              match(PotatoSQLParser::COMMA);
              setState(1283);
              table_or_subquery();
              setState(1288);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(1289);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(1296);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(1294);
          match(PotatoSQLParser::K_WHERE);
          setState(1295);
          expr(0);
        }
        setState(1312);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(1298);
          match(PotatoSQLParser::K_GROUP);
          setState(1299);
          match(PotatoSQLParser::K_BY);
          setState(1300);
          expr(0);
          setState(1305);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1301);
            match(PotatoSQLParser::COMMA);
            setState(1302);
            expr(0);
            setState(1307);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1310);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(1308);
            match(PotatoSQLParser::K_HAVING);
            setState(1309);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(1314);
        match(PotatoSQLParser::K_VALUES);
        setState(1315);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1316);
        expr(0);
        setState(1321);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1317);
          match(PotatoSQLParser::COMMA);
          setState(1318);
          expr(0);
          setState(1323);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1324);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1339);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1325);
          match(PotatoSQLParser::COMMA);
          setState(1326);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1327);
          expr(0);
          setState(1332);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1328);
            match(PotatoSQLParser::COMMA);
            setState(1329);
            expr(0);
            setState(1334);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1335);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(1341);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_operatorContext ------------------------------------------------------------------

PotatoSQLParser::Compound_operatorContext::Compound_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Compound_operatorContext::K_UNION() {
  return getToken(PotatoSQLParser::K_UNION, 0);
}

tree::TerminalNode* PotatoSQLParser::Compound_operatorContext::K_ALL() {
  return getToken(PotatoSQLParser::K_ALL, 0);
}

tree::TerminalNode* PotatoSQLParser::Compound_operatorContext::K_INTERSECT() {
  return getToken(PotatoSQLParser::K_INTERSECT, 0);
}

tree::TerminalNode* PotatoSQLParser::Compound_operatorContext::K_EXCEPT() {
  return getToken(PotatoSQLParser::K_EXCEPT, 0);
}


size_t PotatoSQLParser::Compound_operatorContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCompound_operator;
}


PotatoSQLParser::Compound_operatorContext* PotatoSQLParser::compound_operator() {
  Compound_operatorContext *_localctx = _tracker.createInstance<Compound_operatorContext>(_ctx, getState());
  enterRule(_localctx, 84, PotatoSQLParser::RuleCompound_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 194, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1344);
      match(PotatoSQLParser::K_UNION);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1345);
      match(PotatoSQLParser::K_UNION);
      setState(1346);
      match(PotatoSQLParser::K_ALL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1347);
      match(PotatoSQLParser::K_INTERSECT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1348);
      match(PotatoSQLParser::K_EXCEPT);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signed_numberContext ------------------------------------------------------------------

PotatoSQLParser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Signed_numberContext::NUMERIC_LITERAL() {
  return getToken(PotatoSQLParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Signed_numberContext::PLUS() {
  return getToken(PotatoSQLParser::PLUS, 0);
}

tree::TerminalNode* PotatoSQLParser::Signed_numberContext::MINUS() {
  return getToken(PotatoSQLParser::MINUS, 0);
}


size_t PotatoSQLParser::Signed_numberContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSigned_number;
}


PotatoSQLParser::Signed_numberContext* PotatoSQLParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 86, PotatoSQLParser::RuleSigned_number);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1352);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::PLUS

    || _la == PotatoSQLParser::MINUS) {
      setState(1351);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::PLUS

      || _la == PotatoSQLParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1354);
    match(PotatoSQLParser::NUMERIC_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

PotatoSQLParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(PotatoSQLParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::BLOB_LITERAL() {
  return getToken(PotatoSQLParser::BLOB_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_NULL() {
  return getToken(PotatoSQLParser::K_NULL, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_CURRENT_TIME() {
  return getToken(PotatoSQLParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_CURRENT_DATE() {
  return getToken(PotatoSQLParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_CURRENT_TIMESTAMP() {
  return getToken(PotatoSQLParser::K_CURRENT_TIMESTAMP, 0);
}


size_t PotatoSQLParser::Literal_valueContext::getRuleIndex() const {
  return PotatoSQLParser::RuleLiteral_value;
}


PotatoSQLParser::Literal_valueContext* PotatoSQLParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 88, PotatoSQLParser::RuleLiteral_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1356);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::NUMERIC_LITERAL)
      | (1ULL << PotatoSQLParser::STRING_LITERAL)
      | (1ULL << PotatoSQLParser::BLOB_LITERAL))) != 0) || ((((_la - 93) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 93)) & ((1ULL << (PotatoSQLParser::K_NULL - 93))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIME - 93))
      | (1ULL << (PotatoSQLParser::K_CURRENT_DATE - 93))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIMESTAMP - 93)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

PotatoSQLParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Unary_operatorContext::MINUS() {
  return getToken(PotatoSQLParser::MINUS, 0);
}

tree::TerminalNode* PotatoSQLParser::Unary_operatorContext::PLUS() {
  return getToken(PotatoSQLParser::PLUS, 0);
}

tree::TerminalNode* PotatoSQLParser::Unary_operatorContext::TILDE() {
  return getToken(PotatoSQLParser::TILDE, 0);
}

tree::TerminalNode* PotatoSQLParser::Unary_operatorContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}


size_t PotatoSQLParser::Unary_operatorContext::getRuleIndex() const {
  return PotatoSQLParser::RuleUnary_operator;
}


PotatoSQLParser::Unary_operatorContext* PotatoSQLParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 90, PotatoSQLParser::RuleUnary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1358);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::PLUS)
      | (1ULL << PotatoSQLParser::MINUS)
      | (1ULL << PotatoSQLParser::TILDE)
      | (1ULL << PotatoSQLParser::K_NOT))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Error_messageContext ------------------------------------------------------------------

PotatoSQLParser::Error_messageContext::Error_messageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Error_messageContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}


size_t PotatoSQLParser::Error_messageContext::getRuleIndex() const {
  return PotatoSQLParser::RuleError_message;
}


PotatoSQLParser::Error_messageContext* PotatoSQLParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 92, PotatoSQLParser::RuleError_message);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1360);
    match(PotatoSQLParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_argumentContext ------------------------------------------------------------------

PotatoSQLParser::Module_argumentContext::Module_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Module_argumentContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

PotatoSQLParser::Column_defContext* PotatoSQLParser::Module_argumentContext::column_def() {
  return getRuleContext<PotatoSQLParser::Column_defContext>(0);
}


size_t PotatoSQLParser::Module_argumentContext::getRuleIndex() const {
  return PotatoSQLParser::RuleModule_argument;
}


PotatoSQLParser::Module_argumentContext* PotatoSQLParser::module_argument() {
  Module_argumentContext *_localctx = _tracker.createInstance<Module_argumentContext>(_ctx, getState());
  enterRule(_localctx, 94, PotatoSQLParser::RuleModule_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1364);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1362);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1363);
      column_def();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

PotatoSQLParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Column_aliasContext::IDENTIFIER() {
  return getToken(PotatoSQLParser::IDENTIFIER, 0);
}

tree::TerminalNode* PotatoSQLParser::Column_aliasContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}


size_t PotatoSQLParser::Column_aliasContext::getRuleIndex() const {
  return PotatoSQLParser::RuleColumn_alias;
}


PotatoSQLParser::Column_aliasContext* PotatoSQLParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 96, PotatoSQLParser::RuleColumn_alias);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1366);
    _la = _input->LA(1);
    if (!(_la == PotatoSQLParser::IDENTIFIER

    || _la == PotatoSQLParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

PotatoSQLParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::NameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::NameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleName;
}


PotatoSQLParser::NameContext* PotatoSQLParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 98, PotatoSQLParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1368);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

PotatoSQLParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Function_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Function_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleFunction_name;
}


PotatoSQLParser::Function_nameContext* PotatoSQLParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 100, PotatoSQLParser::RuleFunction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1370);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Database_nameContext ------------------------------------------------------------------

PotatoSQLParser::Database_nameContext::Database_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Database_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Database_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDatabase_name;
}


PotatoSQLParser::Database_nameContext* PotatoSQLParser::database_name() {
  Database_nameContext *_localctx = _tracker.createInstance<Database_nameContext>(_ctx, getState());
  enterRule(_localctx, 102, PotatoSQLParser::RuleDatabase_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1372);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Schema_nameContext ------------------------------------------------------------------

PotatoSQLParser::Schema_nameContext::Schema_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Schema_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Schema_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSchema_name;
}


PotatoSQLParser::Schema_nameContext* PotatoSQLParser::schema_name() {
  Schema_nameContext *_localctx = _tracker.createInstance<Schema_nameContext>(_ctx, getState());
  enterRule(_localctx, 104, PotatoSQLParser::RuleSchema_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1374);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_function_nameContext ------------------------------------------------------------------

PotatoSQLParser::Table_function_nameContext::Table_function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Table_function_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Table_function_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_function_name;
}


PotatoSQLParser::Table_function_nameContext* PotatoSQLParser::table_function_name() {
  Table_function_nameContext *_localctx = _tracker.createInstance<Table_function_nameContext>(_ctx, getState());
  enterRule(_localctx, 106, PotatoSQLParser::RuleTable_function_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1376);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

PotatoSQLParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Table_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Table_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_name;
}


PotatoSQLParser::Table_nameContext* PotatoSQLParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 108, PotatoSQLParser::RuleTable_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1378);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_index_nameContext ------------------------------------------------------------------

PotatoSQLParser::Table_or_index_nameContext::Table_or_index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Table_or_index_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Table_or_index_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_or_index_name;
}


PotatoSQLParser::Table_or_index_nameContext* PotatoSQLParser::table_or_index_name() {
  Table_or_index_nameContext *_localctx = _tracker.createInstance<Table_or_index_nameContext>(_ctx, getState());
  enterRule(_localctx, 110, PotatoSQLParser::RuleTable_or_index_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1380);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- New_table_nameContext ------------------------------------------------------------------

PotatoSQLParser::New_table_nameContext::New_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::New_table_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::New_table_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleNew_table_name;
}


PotatoSQLParser::New_table_nameContext* PotatoSQLParser::new_table_name() {
  New_table_nameContext *_localctx = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 112, PotatoSQLParser::RuleNew_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1382);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

PotatoSQLParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Column_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Column_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleColumn_name;
}


PotatoSQLParser::Column_nameContext* PotatoSQLParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 114, PotatoSQLParser::RuleColumn_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1384);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collation_nameContext ------------------------------------------------------------------

PotatoSQLParser::Collation_nameContext::Collation_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Collation_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Collation_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCollation_name;
}


PotatoSQLParser::Collation_nameContext* PotatoSQLParser::collation_name() {
  Collation_nameContext *_localctx = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
  enterRule(_localctx, 116, PotatoSQLParser::RuleCollation_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1386);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_tableContext ------------------------------------------------------------------

PotatoSQLParser::Foreign_tableContext::Foreign_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Foreign_tableContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Foreign_tableContext::getRuleIndex() const {
  return PotatoSQLParser::RuleForeign_table;
}


PotatoSQLParser::Foreign_tableContext* PotatoSQLParser::foreign_table() {
  Foreign_tableContext *_localctx = _tracker.createInstance<Foreign_tableContext>(_ctx, getState());
  enterRule(_localctx, 118, PotatoSQLParser::RuleForeign_table);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1388);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_nameContext ------------------------------------------------------------------

PotatoSQLParser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Index_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Index_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleIndex_name;
}


PotatoSQLParser::Index_nameContext* PotatoSQLParser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 120, PotatoSQLParser::RuleIndex_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1390);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_nameContext ------------------------------------------------------------------

PotatoSQLParser::Pragma_nameContext::Pragma_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Pragma_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Pragma_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RulePragma_name;
}


PotatoSQLParser::Pragma_nameContext* PotatoSQLParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 122, PotatoSQLParser::RulePragma_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1392);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Savepoint_nameContext ------------------------------------------------------------------

PotatoSQLParser::Savepoint_nameContext::Savepoint_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Savepoint_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Savepoint_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSavepoint_name;
}


PotatoSQLParser::Savepoint_nameContext* PotatoSQLParser::savepoint_name() {
  Savepoint_nameContext *_localctx = _tracker.createInstance<Savepoint_nameContext>(_ctx, getState());
  enterRule(_localctx, 124, PotatoSQLParser::RuleSavepoint_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1394);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Transaction_nameContext ------------------------------------------------------------------

PotatoSQLParser::Transaction_nameContext::Transaction_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Transaction_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Transaction_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTransaction_name;
}


PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 126, PotatoSQLParser::RuleTransaction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1396);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_aliasContext ------------------------------------------------------------------

PotatoSQLParser::Table_aliasContext::Table_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Table_aliasContext::IDENTIFIER() {
  return getToken(PotatoSQLParser::IDENTIFIER, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_aliasContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Table_aliasContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

PotatoSQLParser::Table_aliasContext* PotatoSQLParser::Table_aliasContext::table_alias() {
  return getRuleContext<PotatoSQLParser::Table_aliasContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Table_aliasContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}


size_t PotatoSQLParser::Table_aliasContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTable_alias;
}


PotatoSQLParser::Table_aliasContext* PotatoSQLParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 128, PotatoSQLParser::RuleTable_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1404);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1398);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1399);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 3);
        setState(1400);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1401);
        table_alias();
        setState(1402);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

PotatoSQLParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Any_nameContext::IDENTIFIER() {
  return getToken(PotatoSQLParser::IDENTIFIER, 0);
}

PotatoSQLParser::KeywordContext* PotatoSQLParser::Any_nameContext::keyword() {
  return getRuleContext<PotatoSQLParser::KeywordContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Any_nameContext::STRING_LITERAL() {
  return getToken(PotatoSQLParser::STRING_LITERAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Any_nameContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Any_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Any_nameContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}


size_t PotatoSQLParser::Any_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleAny_name;
}


PotatoSQLParser::Any_nameContext* PotatoSQLParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 130, PotatoSQLParser::RuleAny_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1413);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1406);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::K_AND:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_CASE: {
        enterOuterAlt(_localctx, 2);
        setState(1407);
        keyword();
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1408);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(1409);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1410);
        any_name();
        setState(1411);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

PotatoSQLParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ALTER() {
  return getToken(PotatoSQLParser::K_ALTER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_AND() {
  return getToken(PotatoSQLParser::K_AND, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_BEGIN() {
  return getToken(PotatoSQLParser::K_BEGIN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CASE() {
  return getToken(PotatoSQLParser::K_CASE, 0);
}


size_t PotatoSQLParser::KeywordContext::getRuleIndex() const {
  return PotatoSQLParser::RuleKeyword;
}


PotatoSQLParser::KeywordContext* PotatoSQLParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 132, PotatoSQLParser::RuleKeyword);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1415);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_AND)
      | (1ULL << PotatoSQLParser::K_BEGIN)
      | (1ULL << PotatoSQLParser::K_ALTER))) != 0) || _la == PotatoSQLParser::K_CASE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool PotatoSQLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 26: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool PotatoSQLParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 20);
    case 1: return precpred(_ctx, 19);
    case 2: return precpred(_ctx, 18);
    case 3: return precpred(_ctx, 17);
    case 4: return precpred(_ctx, 16);
    case 5: return precpred(_ctx, 15);
    case 6: return precpred(_ctx, 13);
    case 7: return precpred(_ctx, 12);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);
    case 10: return precpred(_ctx, 14);
    case 11: return precpred(_ctx, 8);
    case 12: return precpred(_ctx, 7);
    case 13: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> PotatoSQLParser::_decisionToDFA;
atn::PredictionContextCache PotatoSQLParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN PotatoSQLParser::_atn;
std::vector<uint16_t> PotatoSQLParser::_serializedATN;

std::vector<std::string> PotatoSQLParser::_ruleNames = {
  "main", "sql_stmt_list", "sql_stmt", "alter_table_stmt", "begin_stmt", 
  "commit_stmt", "compound_select_stmt", "create_index_stmt", "create_table_stmt", 
  "delete_stmt", "delete_stmt_limited", "drop_index_stmt", "drop_table_stmt", 
  "factored_select_stmt", "insert_stmt", "pragma_stmt", "rollback_stmt", 
  "simple_select_stmt", "select_stmt", "select_or_values", "update_stmt", 
  "update_stmt_limited", "column_def", "type_name", "column_constraint", 
  "conflict_clause", "expr", "raise_function", "foreign_key_clause", "indexed_column", 
  "table_constraint", "with_clause", "qualified_table_name", "ordering_term", 
  "pragma_value", "common_table_expression", "result_column", "table_or_subquery", 
  "join_clause", "join_operator", "join_constraint", "select_core", "compound_operator", 
  "signed_number", "literal_value", "unary_operator", "error_message", "module_argument", 
  "column_alias", "name", "function_name", "database_name", "schema_name", 
  "table_function_name", "table_name", "table_or_index_name", "new_table_name", 
  "column_name", "collation_name", "foreign_table", "index_name", "pragma_name", 
  "savepoint_name", "transaction_name", "table_alias", "any_name", "keyword"
};

std::vector<std::string> PotatoSQLParser::_literalNames = {
  "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", "'~'", 
  "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> PotatoSQLParser::_symbolicNames = {
  "", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", "ASSIGN", "STAR", 
  "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", "GT2", "AMP", 
  "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", "K_AND", 
  "K_AS", "K_ASC", "K_BEGIN", "K_GROUP", "K_JOIN", "K_LIMIT", "K_NOT", "K_ON", 
  "K_OR", "K_ORDER", "K_OUTER", "IDENTIFIER", "NUMERIC_LITERAL", "STRING_LITERAL", 
  "BLOB_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
  "UNEXPECTED_CHAR", "K_ALTER", "K_TABLE", "K_RENAME", "K_TO", "K_ADD", 
  "K_COLUMN", "K_COMMIT", "K_END", "K_UNION", "K_ALL", "K_INTERSECT", "K_EXCEPT", 
  "K_BY", "K_OFFSET", "K_CREATE", "K_UNIQUE", "K_INDEX", "K_IF", "K_EXISTS", 
  "K_WHERE", "K_TEMP", "K_TEMPORARY", "K_WITHOUT", "K_DELETE", "K_FROM", 
  "K_DROP", "K_INSERT", "K_REPLACE", "K_ROLLBACK", "K_ABORT", "K_FAIL", 
  "K_IGNORE", "K_INTO", "K_VALUES", "K_DEFAULT", "K_PRAGMA", "K_TRANSACTION", 
  "K_SAVEPOINT", "K_SELECT", "K_DISTINCT", "K_HAVING", "K_UPDATE", "K_SET", 
  "K_CONSTRAINT", "K_PRIMARY", "K_KEY", "K_DESC", "K_AUTOINCREMENT", "K_NULL", 
  "K_CHECK", "K_COLLATE", "K_CONFLICT", "BIND_PARAMETER", "K_CAST", "K_CASE", 
  "K_WHEN", "K_THEN", "K_ELSE", "K_IS", "K_BETWEEN", "K_IN", "K_LIKE", "K_GLOB", 
  "K_REGEXP", "K_MATCH", "K_ESCAPE", "K_ISNULL", "K_NOTNULL", "K_RAISE", 
  "K_REFERENCES", "K_CASCADE", "K_RESTRICT", "K_NO", "K_ACTION", "K_DEFERRABLE", 
  "K_INITIALLY", "K_DEFERRED", "K_IMMEDIATE", "K_FOREIGN", "K_WITH", "K_RECURSIVE", 
  "K_INDEXED", "K_NATURAL", "K_LEFT", "K_INNER", "K_CROSS", "K_USING", "K_CURRENT_TIME", 
  "K_CURRENT_DATE", "K_CURRENT_TIMESTAMP"
};

dfa::Vocabulary PotatoSQLParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> PotatoSQLParser::_tokenNames;

PotatoSQLParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x88, 0x58c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x3, 0x2, 0x7, 0x2, 0x8a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0x8d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x92, 0xa, 
       0x3, 0xc, 0x3, 0xe, 0x3, 0x95, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x6, 
       0x3, 0x99, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x9a, 0x3, 0x3, 0x7, 0x3, 
       0x9e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xa1, 0xb, 0x3, 0x3, 0x3, 0x7, 
       0x3, 0xa4, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0xa7, 0xb, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xba, 0xa, 0x4, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xc1, 0xa, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0xc9, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0xcc, 0xa, 0x5, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x5, 0x8, 0xd3, 0xa, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xd8, 0xa, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x5, 0x8, 0xdc, 0xa, 0x8, 0x3, 0x8, 0x6, 0x8, 0xdf, 0xa, 
       0x8, 0xd, 0x8, 0xe, 0x8, 0xe0, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x7, 0x8, 0xe8, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0xeb, 
       0xb, 0x8, 0x5, 0x8, 0xed, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x5, 0x8, 0xf3, 0xa, 0x8, 0x5, 0x8, 0xf5, 0xa, 0x8, 0x3, 
       0x9, 0x3, 0x9, 0x5, 0x9, 0xf9, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x5, 0x9, 0xff, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0x104, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x10d, 0xa, 0x9, 0xc, 
       0x9, 0xe, 0x9, 0x110, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
       0x9, 0x115, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x119, 0xa, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x11f, 0xa, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x124, 0xa, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x12b, 0xa, 0xa, 
       0xc, 0xa, 0xe, 0xa, 0x12e, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
       0x132, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x135, 0xb, 0xa, 0x3, 0xa, 0x3, 
       0xa, 0x3, 0xa, 0x5, 0xa, 0x13a, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
       0xa, 0x13e, 0xa, 0xa, 0x3, 0xb, 0x5, 0xb, 0x141, 0xa, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x148, 0xa, 0xb, 
       0x3, 0xc, 0x5, 0xc, 0x14b, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x152, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x159, 0xa, 0xc, 0xc, 0xc, 
       0xe, 0xc, 0x15c, 0xb, 0xc, 0x5, 0xc, 0x15e, 0xa, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x164, 0xa, 0xc, 0x5, 0xc, 0x166, 
       0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x16c, 
       0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x171, 0xa, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
       0xe, 0x179, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x17e, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x5, 0xf, 0x183, 0xa, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x189, 0xa, 0xf, 
       0xc, 0xf, 0xe, 0xf, 0x18c, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x193, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
       0x196, 0xb, 0xf, 0x5, 0xf, 0x198, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x5, 0xf, 0x19e, 0xa, 0xf, 0x5, 0xf, 0x1a0, 0xa, 0xf, 
       0x3, 0x10, 0x5, 0x10, 0x1a3, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1b6, 0xa, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1bc, 0xa, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1c3, 
       0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1c6, 0xb, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x5, 0x10, 0x1ca, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1d1, 0xa, 0x10, 0xc, 0x10, 0xe, 
       0x10, 0x1d4, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1dc, 0xa, 0x10, 0xc, 0x10, 0xe, 
       0x10, 0x1df, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1e3, 0xa, 
       0x10, 0xc, 0x10, 0xe, 0x10, 0x1e6, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x5, 0x10, 0x1eb, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x5, 0x11, 0x1f1, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0x1fa, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1ff, 
       0xa, 0x12, 0x5, 0x12, 0x201, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 
       0x12, 0x205, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0x208, 0xa, 0x12, 0x3, 
       0x13, 0x5, 0x13, 0x20b, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x213, 0xa, 0x13, 0xc, 
       0x13, 0xe, 0x13, 0x216, 0xb, 0x13, 0x5, 0x13, 0x218, 0xa, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x21e, 0xa, 0x13, 
       0x5, 0x13, 0x220, 0xa, 0x13, 0x3, 0x14, 0x5, 0x14, 0x223, 0xa, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x229, 0xa, 
       0x14, 0xc, 0x14, 0xe, 0x14, 0x22c, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x233, 0xa, 0x14, 0xc, 
       0x14, 0xe, 0x14, 0x236, 0xb, 0x14, 0x5, 0x14, 0x238, 0xa, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x23e, 0xa, 0x14, 
       0x5, 0x14, 0x240, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x244, 
       0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x249, 0xa, 
       0x15, 0xc, 0x15, 0xe, 0x15, 0x24c, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x252, 0xa, 0x15, 0xc, 0x15, 0xe, 
       0x15, 0x255, 0xb, 0x15, 0x3, 0x15, 0x5, 0x15, 0x258, 0xa, 0x15, 0x5, 
       0x15, 0x25a, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x25e, 0xa, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 
       0x15, 0x265, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x268, 0xb, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x5, 0x15, 0x26c, 0xa, 0x15, 0x5, 0x15, 0x26e, 0xa, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 
       0x15, 0x275, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x278, 0xb, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 
       0x15, 0x280, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x283, 0xb, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x7, 0x15, 0x287, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
       0x28a, 0xb, 0x15, 0x5, 0x15, 0x28c, 0xa, 0x15, 0x3, 0x16, 0x5, 0x16, 
       0x28f, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x5, 0x16, 0x29c, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x7, 0x16, 0x2a8, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x2ab, 
       0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x2af, 0xa, 0x16, 0x3, 
       0x17, 0x5, 0x17, 0x2b2, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2bf, 0xa, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x2cb, 0xa, 0x17, 0xc, 0x17, 
       0xe, 0x17, 0x2ce, 0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2d2, 
       0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
       0x7, 0x17, 0x2d9, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x2dc, 0xb, 0x17, 
       0x5, 0x17, 0x2de, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x5, 0x17, 0x2e4, 0xa, 0x17, 0x5, 0x17, 0x2e6, 0xa, 0x17, 0x3, 
       0x18, 0x3, 0x18, 0x5, 0x18, 0x2ea, 0xa, 0x18, 0x3, 0x18, 0x7, 0x18, 
       0x2ed, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x2f0, 0xb, 0x18, 0x3, 0x19, 
       0x6, 0x19, 0x2f3, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x2f4, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x301, 0xa, 0x19, 0x3, 
       0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x305, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x5, 0x1a, 0x30a, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 
       0x1a, 0x30e, 0xa, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x311, 0xa, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x323, 0xa, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x328, 0xa, 0x1a, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x32d, 0xa, 0x1b, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 
       0x335, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x33a, 
       0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x343, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x348, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
       0x34b, 0xb, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x34e, 0xa, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x5, 0x1c, 0x35e, 0xa, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x361, 
       0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x5, 0x1c, 0x369, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x6, 0x1c, 0x370, 0xa, 0x1c, 0xd, 0x1c, 
       0xe, 0x1c, 0x371, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x376, 0xa, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x37b, 0xa, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x398, 0xa, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x39d, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 
       0x1c, 0x3a6, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x3ae, 0xa, 0x1c, 0xc, 0x1c, 0xe, 
       0x1c, 0x3b1, 0xb, 0x1c, 0x5, 0x1c, 0x3b3, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x3b9, 0xa, 0x1c, 0x3, 0x1c, 
       0x5, 0x1c, 0x3bc, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x3c3, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x3c9, 0xa, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x3d0, 0xa, 0x1c, 
       0x7, 0x1c, 0x3d2, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x3d5, 0xb, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x5, 0x1d, 0x3dd, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x3e7, 
       0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x3ea, 0xb, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x5, 0x1e, 0x3ee, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
       0x3, 0x1e, 0x5, 0x1e, 0x3fa, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
       0x1e, 0x3fe, 0xa, 0x1e, 0x7, 0x1e, 0x400, 0xa, 0x1e, 0xc, 0x1e, 0xe, 
       0x1e, 0x403, 0xb, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x406, 0xa, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x40d, 
       0xa, 0x1e, 0x5, 0x1e, 0x40f, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x414, 0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x417, 0xa, 
       0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x41b, 0xa, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x420, 0xa, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x426, 0xa, 0x20, 0xc, 0x20, 
       0xe, 0x20, 0x429, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x439, 
       0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x43c, 0xb, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x5, 0x20, 0x441, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 
       0x5, 0x21, 0x445, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 
       0x21, 0x44a, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x44d, 0xb, 0x21, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x452, 0xa, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
       0x45a, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x45f, 
       0xa, 0x23, 0x3, 0x23, 0x5, 0x23, 0x462, 0xa, 0x23, 0x3, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x5, 0x24, 0x467, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x46e, 0xa, 0x25, 0xc, 
       0x25, 0xe, 0x25, 0x471, 0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 
       0x475, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x5, 0x26, 0x483, 0xa, 0x26, 0x3, 0x26, 0x5, 0x26, 
       0x486, 0xa, 0x26, 0x5, 0x26, 0x488, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x5, 0x27, 0x48d, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
       0x27, 0x491, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x494, 0xa, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x49b, 
       0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x4a0, 0xa, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 
       0x27, 0x4a7, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x4aa, 0xb, 0x27, 0x5, 
       0x27, 0x4ac, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x4b0, 0xa, 
       0x27, 0x3, 0x27, 0x5, 0x27, 0x4b3, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x4b9, 0xa, 0x27, 0xc, 0x27, 0xe, 
       0x27, 0x4bc, 0xb, 0x27, 0x3, 0x27, 0x5, 0x27, 0x4bf, 0xa, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
       0x27, 0x4c7, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x4ca, 0xa, 0x27, 0x5, 
       0x27, 0x4cc, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
       0x3, 0x28, 0x7, 0x28, 0x4d3, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x4d6, 
       0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x4da, 0xa, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x5, 0x29, 0x4de, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x5, 0x29, 0x4e2, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x4e5, 0xa, 0x29, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x7, 0x2a, 0x4ee, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x4f1, 
       0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4f5, 0xa, 0x2a, 0x3, 
       0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x4f9, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x7, 0x2b, 0x4fe, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x501, 
       0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 
       0x507, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x50a, 0xb, 0x2b, 0x3, 0x2b, 
       0x5, 0x2b, 0x50d, 0xa, 0x2b, 0x5, 0x2b, 0x50f, 0xa, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x5, 0x2b, 0x513, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x51a, 0xa, 0x2b, 0xc, 0x2b, 
       0xe, 0x2b, 0x51d, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x521, 
       0xa, 0x2b, 0x5, 0x2b, 0x523, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x52a, 0xa, 0x2b, 0xc, 0x2b, 
       0xe, 0x2b, 0x52d, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x535, 0xa, 0x2b, 0xc, 0x2b, 
       0xe, 0x2b, 0x538, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x53c, 
       0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x53f, 0xb, 0x2b, 0x5, 0x2b, 0x541, 
       0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x5, 0x2c, 0x548, 0xa, 0x2c, 0x3, 0x2d, 0x5, 0x2d, 0x54b, 0xa, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x557, 0xa, 
       0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 
       0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 
       0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 
       0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 0x42, 0x57f, 0xa, 0x42, 0x3, 0x43, 
       0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
       0x5, 0x43, 0x588, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x4, 
       0x12c, 0x2f4, 0x3, 0x36, 0x45, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
       0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
       0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
       0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
       0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
       0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 
       0x7e, 0x80, 0x82, 0x84, 0x86, 0x2, 0x14, 0x3, 0x2, 0x35, 0x36, 0x4, 
       0x2, 0x7, 0x7, 0x3c, 0x3c, 0x3, 0x2, 0x43, 0x44, 0x4, 0x2, 0x38, 
       0x38, 0x56, 0x56, 0x4, 0x2, 0x1d, 0x1d, 0x5d, 0x5d, 0x3, 0x2, 0x4a, 
       0x4e, 0x4, 0x2, 0x9, 0x9, 0xe, 0xf, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 
       0x10, 0x13, 0x3, 0x2, 0x14, 0x17, 0x4, 0x2, 0x8, 0x8, 0x18, 0x1a, 
       0x3, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x4b, 0x4d, 0x4, 0x2, 0x46, 0x46, 
       0x58, 0x58, 0x5, 0x2, 0x28, 0x2a, 0x5f, 0x5f, 0x86, 0x88, 0x4, 0x2, 
       0xa, 0xc, 0x22, 0x22, 0x4, 0x2, 0x27, 0x27, 0x29, 0x29, 0x6, 0x2, 
       0x1b, 0x1b, 0x1e, 0x1e, 0x2f, 0x2f, 0x65, 0x65, 0x2, 0x65f, 0x2, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x93, 0x3, 0x2, 0x2, 0x2, 0x6, 0xb9, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xa, 0xcd, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xe, 0xd2, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x12, 0x116, 0x3, 0x2, 
       0x2, 0x2, 0x14, 0x140, 0x3, 0x2, 0x2, 0x2, 0x16, 0x14a, 0x3, 0x2, 
       0x2, 0x2, 0x18, 0x167, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x174, 0x3, 0x2, 
       0x2, 0x2, 0x1c, 0x182, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1a2, 0x3, 0x2, 
       0x2, 0x2, 0x20, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1fb, 0x3, 0x2, 
       0x2, 0x2, 0x24, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x26, 0x222, 0x3, 0x2, 
       0x2, 0x2, 0x28, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28e, 0x3, 0x2, 
       0x2, 0x2, 0x2c, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2e7, 0x3, 0x2, 
       0x2, 0x2, 0x30, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x32, 0x304, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37a, 0x3, 0x2, 
       0x2, 0x2, 0x38, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3e0, 0x3, 0x2, 
       0x2, 0x2, 0x3c, 0x410, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41a, 0x3, 0x2, 
       0x2, 0x2, 0x40, 0x442, 0x3, 0x2, 0x2, 0x2, 0x42, 0x451, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x45b, 0x3, 0x2, 0x2, 0x2, 0x46, 0x466, 0x3, 0x2, 
       0x2, 0x2, 0x48, 0x468, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x487, 0x3, 0x2, 
       0x2, 0x2, 0x4c, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4cd, 0x3, 0x2, 
       0x2, 0x2, 0x50, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4f4, 0x3, 0x2, 
       0x2, 0x2, 0x54, 0x540, 0x3, 0x2, 0x2, 0x2, 0x56, 0x547, 0x3, 0x2, 
       0x2, 0x2, 0x58, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x54e, 0x3, 0x2, 
       0x2, 0x2, 0x5c, 0x550, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x552, 0x3, 0x2, 
       0x2, 0x2, 0x60, 0x556, 0x3, 0x2, 0x2, 0x2, 0x62, 0x558, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x55a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x55c, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x560, 0x3, 0x2, 
       0x2, 0x2, 0x6c, 0x562, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x564, 0x3, 0x2, 
       0x2, 0x2, 0x70, 0x566, 0x3, 0x2, 0x2, 0x2, 0x72, 0x568, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x76, 0x56c, 0x3, 0x2, 
       0x2, 0x2, 0x78, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x570, 0x3, 0x2, 
       0x2, 0x2, 0x7c, 0x572, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x574, 0x3, 0x2, 
       0x2, 0x2, 0x80, 0x576, 0x3, 0x2, 0x2, 0x2, 0x82, 0x57e, 0x3, 0x2, 
       0x2, 0x2, 0x84, 0x587, 0x3, 0x2, 0x2, 0x2, 0x86, 0x589, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x8a, 0x5, 0x4, 0x3, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 
       0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8d, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x2, 0x2, 0x3, 0x8f, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x3, 0x2, 0x2, 0x91, 0x90, 0x3, 
       0x2, 0x2, 0x2, 0x92, 0x95, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 
       0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x96, 0x3, 0x2, 0x2, 
       0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9f, 0x5, 0x6, 0x4, 0x2, 
       0x97, 0x99, 0x7, 0x3, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 
       0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 
       0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9e, 0x5, 
       0x6, 0x4, 0x2, 0x9d, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 
       0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 
       0x2, 0xa0, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 
       0xa2, 0xa4, 0x7, 0x3, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 
       0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
       0x3, 0x2, 0x2, 0x2, 0xa6, 0x5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 
       0x2, 0x2, 0x2, 0xa8, 0xba, 0x5, 0x8, 0x5, 0x2, 0xa9, 0xba, 0x5, 0xa, 
       0x6, 0x2, 0xaa, 0xba, 0x5, 0xc, 0x7, 0x2, 0xab, 0xba, 0x5, 0x10, 
       0x9, 0x2, 0xac, 0xba, 0x5, 0xe, 0x8, 0x2, 0xad, 0xba, 0x5, 0x12, 
       0xa, 0x2, 0xae, 0xba, 0x5, 0x1a, 0xe, 0x2, 0xaf, 0xba, 0x5, 0x14, 
       0xb, 0x2, 0xb0, 0xba, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xba, 0x5, 0x1a, 
       0xe, 0x2, 0xb2, 0xba, 0x5, 0x1c, 0xf, 0x2, 0xb3, 0xba, 0x5, 0x1e, 
       0x10, 0x2, 0xb4, 0xba, 0x5, 0x20, 0x11, 0x2, 0xb5, 0xba, 0x5, 0x22, 
       0x12, 0x2, 0xb6, 0xba, 0x5, 0x24, 0x13, 0x2, 0xb7, 0xba, 0x5, 0x2a, 
       0x16, 0x2, 0xb8, 0xba, 0x5, 0x2c, 0x17, 0x2, 0xb9, 0xa8, 0x3, 0x2, 
       0x2, 0x2, 0xb9, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xaa, 0x3, 0x2, 0x2, 
       0x2, 0xb9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xac, 0x3, 0x2, 0x2, 0x2, 
       0xb9, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb9, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb1, 
       0x3, 0x2, 0x2, 0x2, 0xb9, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb3, 0x3, 
       0x2, 0x2, 0x2, 0xb9, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb5, 0x3, 0x2, 
       0x2, 0x2, 0xb9, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 
       0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0x7, 0x3, 0x2, 0x2, 0x2, 
       0xbb, 0xbc, 0x7, 0x2f, 0x2, 0x2, 0xbc, 0xc0, 0x7, 0x30, 0x2, 0x2, 
       0xbd, 0xbe, 0x5, 0x68, 0x35, 0x2, 0xbe, 0xbf, 0x7, 0x4, 0x2, 0x2, 
       0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 
       0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xcb, 
       0x5, 0x6e, 0x38, 0x2, 0xc3, 0xc4, 0x7, 0x31, 0x2, 0x2, 0xc4, 0xc5, 
       0x7, 0x32, 0x2, 0x2, 0xc5, 0xcc, 0x5, 0x72, 0x3a, 0x2, 0xc6, 0xc8, 
       0x7, 0x33, 0x2, 0x2, 0xc7, 0xc9, 0x7, 0x34, 0x2, 0x2, 0xc8, 0xc7, 
       0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 
       0x2, 0x2, 0x2, 0xca, 0xcc, 0x5, 0x2e, 0x18, 0x2, 0xcb, 0xc3, 0x3, 
       0x2, 0x2, 0x2, 0xcb, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0xcd, 0xce, 0x7, 0x1e, 0x2, 0x2, 0xce, 0xb, 0x3, 0x2, 0x2, 
       0x2, 0xcf, 0xd0, 0x9, 0x2, 0x2, 0x2, 0xd0, 0xd, 0x3, 0x2, 0x2, 0x2, 
       0xd1, 0xd3, 0x5, 0x40, 0x21, 0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 
       0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 
       0xde, 0x5, 0x54, 0x2b, 0x2, 0xd5, 0xd7, 0x7, 0x37, 0x2, 0x2, 0xd6, 
       0xd8, 0x7, 0x38, 0x2, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd7, 
       0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xdc, 
       0x7, 0x39, 0x2, 0x2, 0xda, 0xdc, 0x7, 0x3a, 0x2, 0x2, 0xdb, 0xd5, 
       0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xda, 0x3, 
       0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x54, 
       0x2b, 0x2, 0xde, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 
       0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 
       0x2, 0xe1, 0xec, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x25, 0x2, 
       0x2, 0xe3, 0xe4, 0x7, 0x3b, 0x2, 0x2, 0xe4, 0xe9, 0x5, 0x44, 0x23, 
       0x2, 0xe5, 0xe6, 0x7, 0x7, 0x2, 0x2, 0xe6, 0xe8, 0x5, 0x44, 0x23, 
       0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 
       0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 
       0xed, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xe2, 
       0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf4, 0x3, 
       0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x21, 0x2, 0x2, 0xef, 0xf2, 0x5, 
       0x36, 0x1c, 0x2, 0xf0, 0xf1, 0x9, 0x3, 0x2, 0x2, 0xf1, 0xf3, 0x5, 
       0x36, 0x1c, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 
       0x2, 0x2, 0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf, 0x3, 0x2, 0x2, 
       0x2, 0xf6, 0xf8, 0x7, 0x3d, 0x2, 0x2, 0xf7, 0xf9, 0x7, 0x3e, 0x2, 
       0x2, 0xf8, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 
       0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfe, 0x7, 0x3f, 0x2, 0x2, 
       0xfb, 0xfc, 0x7, 0x40, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x22, 0x2, 0x2, 
       0xfd, 0xff, 0x7, 0x41, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 
       0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x103, 0x3, 0x2, 0x2, 0x2, 
       0x100, 0x101, 0x5, 0x68, 0x35, 0x2, 0x101, 0x102, 0x7, 0x4, 0x2, 
       0x2, 0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x100, 0x3, 0x2, 0x2, 
       0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 
       0x2, 0x105, 0x106, 0x5, 0x7a, 0x3e, 0x2, 0x106, 0x107, 0x7, 0x23, 
       0x2, 0x2, 0x107, 0x108, 0x5, 0x6e, 0x38, 0x2, 0x108, 0x109, 0x7, 
       0x5, 0x2, 0x2, 0x109, 0x10e, 0x5, 0x3c, 0x1f, 0x2, 0x10a, 0x10b, 
       0x7, 0x7, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x3c, 0x1f, 0x2, 0x10c, 0x10a, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 
       0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 
       0x7, 0x6, 0x2, 0x2, 0x112, 0x113, 0x7, 0x42, 0x2, 0x2, 0x113, 0x115, 
       0x5, 0x36, 0x1c, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x11, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 
       0x7, 0x3d, 0x2, 0x2, 0x117, 0x119, 0x9, 0x4, 0x2, 0x2, 0x118, 0x117, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x11e, 0x7, 0x30, 0x2, 0x2, 0x11b, 0x11c, 
       0x7, 0x40, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0x22, 0x2, 0x2, 0x11d, 0x11f, 
       0x7, 0x41, 0x2, 0x2, 0x11e, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
       0x3, 0x2, 0x2, 0x2, 0x11f, 0x123, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 
       0x5, 0x68, 0x35, 0x2, 0x121, 0x122, 0x7, 0x4, 0x2, 0x2, 0x122, 0x124, 
       0x3, 0x2, 0x2, 0x2, 0x123, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x3, 0x2, 0x2, 0x2, 0x125, 0x13d, 
       0x5, 0x6e, 0x38, 0x2, 0x126, 0x127, 0x7, 0x5, 0x2, 0x2, 0x127, 0x12c, 
       0x5, 0x2e, 0x18, 0x2, 0x128, 0x129, 0x7, 0x7, 0x2, 0x2, 0x129, 0x12b, 
       0x5, 0x2e, 0x18, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12a, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x133, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x7, 0x7, 0x2, 0x2, 0x130, 0x132, 
       0x5, 0x3e, 0x20, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 
       0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 0x133, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x139, 0x7, 0x6, 0x2, 0x2, 0x137, 0x138, 
       0x7, 0x45, 0x2, 0x2, 0x138, 0x13a, 0x7, 0x27, 0x2, 0x2, 0x139, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13e, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x7, 0x1c, 0x2, 0x2, 0x13c, 0x13e, 
       0x5, 0x26, 0x14, 0x2, 0x13d, 0x126, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x13e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x141, 
       0x5, 0x40, 0x21, 0x2, 0x140, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 
       0x7, 0x46, 0x2, 0x2, 0x143, 0x144, 0x7, 0x47, 0x2, 0x2, 0x144, 0x147, 
       0x5, 0x42, 0x22, 0x2, 0x145, 0x146, 0x7, 0x42, 0x2, 0x2, 0x146, 0x148, 
       0x5, 0x36, 0x1c, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x148, 0x15, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14b, 
       0x5, 0x40, 0x21, 0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 
       0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 
       0x7, 0x46, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0x47, 0x2, 0x2, 0x14e, 0x151, 
       0x5, 0x42, 0x22, 0x2, 0x14f, 0x150, 0x7, 0x42, 0x2, 0x2, 0x150, 0x152, 
       0x5, 0x36, 0x1c, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 
       0x3, 0x2, 0x2, 0x2, 0x152, 0x165, 0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 
       0x7, 0x25, 0x2, 0x2, 0x154, 0x155, 0x7, 0x3b, 0x2, 0x2, 0x155, 0x15a, 
       0x5, 0x44, 0x23, 0x2, 0x156, 0x157, 0x7, 0x7, 0x2, 0x2, 0x157, 0x159, 
       0x5, 0x44, 0x23, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15c, 
       0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 
       0x3, 0x2, 0x2, 0x2, 0x15b, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 
       0x3, 0x2, 0x2, 0x2, 0x15d, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 
       0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 
       0x7, 0x21, 0x2, 0x2, 0x160, 0x163, 0x5, 0x36, 0x1c, 0x2, 0x161, 0x162, 
       0x9, 0x3, 0x2, 0x2, 0x162, 0x164, 0x5, 0x36, 0x1c, 0x2, 0x163, 0x161, 
       0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 
       0x3, 0x2, 0x2, 0x2, 0x166, 0x17, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 
       0x7, 0x48, 0x2, 0x2, 0x168, 0x16b, 0x7, 0x3f, 0x2, 0x2, 0x169, 0x16a, 
       0x7, 0x40, 0x2, 0x2, 0x16a, 0x16c, 0x7, 0x41, 0x2, 0x2, 0x16b, 0x169, 
       0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x170, 
       0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x68, 0x35, 0x2, 0x16e, 0x16f, 
       0x7, 0x4, 0x2, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 
       0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x5, 0x7a, 0x3e, 0x2, 0x173, 0x19, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x7, 0x48, 0x2, 0x2, 0x175, 0x178, 
       0x7, 0x30, 0x2, 0x2, 0x176, 0x177, 0x7, 0x40, 0x2, 0x2, 0x177, 0x179, 
       0x7, 0x41, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 
       0x3, 0x2, 0x2, 0x2, 0x179, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 
       0x5, 0x68, 0x35, 0x2, 0x17b, 0x17c, 0x7, 0x4, 0x2, 0x2, 0x17c, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x17d, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 
       0x5, 0x6e, 0x38, 0x2, 0x180, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 
       0x5, 0x40, 0x21, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 
       0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x18a, 
       0x5, 0x54, 0x2b, 0x2, 0x185, 0x186, 0x5, 0x56, 0x2c, 0x2, 0x186, 
       0x187, 0x5, 0x54, 0x2b, 0x2, 0x187, 0x189, 0x3, 0x2, 0x2, 0x2, 0x188, 
       0x185, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18a, 
       0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 
       0x197, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 
       0x18e, 0x7, 0x25, 0x2, 0x2, 0x18e, 0x18f, 0x7, 0x3b, 0x2, 0x2, 0x18f, 
       0x194, 0x5, 0x44, 0x23, 0x2, 0x190, 0x191, 0x7, 0x7, 0x2, 0x2, 0x191, 
       0x193, 0x5, 0x44, 0x23, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x196, 0x3, 0x2, 0x2, 0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x194, 
       0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x198, 0x3, 0x2, 0x2, 0x2, 0x196, 
       0x194, 0x3, 0x2, 0x2, 0x2, 0x197, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x197, 
       0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x199, 
       0x19a, 0x7, 0x21, 0x2, 0x2, 0x19a, 0x19d, 0x5, 0x36, 0x1c, 0x2, 0x19b, 
       0x19c, 0x9, 0x3, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0x36, 0x1c, 0x2, 0x19d, 
       0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1a1, 
       0x1a3, 0x5, 0x40, 0x21, 0x2, 0x1a2, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
       0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
       0x1b6, 0x7, 0x49, 0x2, 0x2, 0x1a5, 0x1b6, 0x7, 0x4a, 0x2, 0x2, 0x1a6, 
       0x1a7, 0x7, 0x49, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x24, 0x2, 0x2, 0x1a8, 
       0x1b6, 0x7, 0x4a, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x49, 0x2, 0x2, 0x1aa, 
       0x1ab, 0x7, 0x24, 0x2, 0x2, 0x1ab, 0x1b6, 0x7, 0x4b, 0x2, 0x2, 0x1ac, 
       0x1ad, 0x7, 0x49, 0x2, 0x2, 0x1ad, 0x1ae, 0x7, 0x24, 0x2, 0x2, 0x1ae, 
       0x1b6, 0x7, 0x4c, 0x2, 0x2, 0x1af, 0x1b0, 0x7, 0x49, 0x2, 0x2, 0x1b0, 
       0x1b1, 0x7, 0x24, 0x2, 0x2, 0x1b1, 0x1b6, 0x7, 0x4d, 0x2, 0x2, 0x1b2, 
       0x1b3, 0x7, 0x49, 0x2, 0x2, 0x1b3, 0x1b4, 0x7, 0x24, 0x2, 0x2, 0x1b4, 
       0x1b6, 0x7, 0x4e, 0x2, 0x2, 0x1b5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
       0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
       0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
       0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
       0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1bb, 0x7, 0x4f, 0x2, 0x2, 0x1b8, 
       0x1b9, 0x5, 0x68, 0x35, 0x2, 0x1b9, 0x1ba, 0x7, 0x4, 0x2, 0x2, 0x1ba, 
       0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1bb, 
       0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
       0x1c9, 0x5, 0x6e, 0x38, 0x2, 0x1be, 0x1bf, 0x7, 0x5, 0x2, 0x2, 0x1bf, 
       0x1c4, 0x5, 0x74, 0x3b, 0x2, 0x1c0, 0x1c1, 0x7, 0x7, 0x2, 0x2, 0x1c1, 
       0x1c3, 0x5, 0x74, 0x3b, 0x2, 0x1c2, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
       0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x6, 0x2, 0x2, 0x1c8, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
       0x1cc, 0x7, 0x50, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0x5, 0x2, 0x2, 0x1cd, 
       0x1d2, 0x5, 0x36, 0x1c, 0x2, 0x1ce, 0x1cf, 0x7, 0x7, 0x2, 0x2, 0x1cf, 
       0x1d1, 0x5, 0x36, 0x1c, 0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 
       0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1e4, 0x7, 0x6, 0x2, 0x2, 0x1d6, 
       0x1d7, 0x7, 0x7, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x5, 0x2, 0x2, 0x1d8, 
       0x1dd, 0x5, 0x36, 0x1c, 0x2, 0x1d9, 0x1da, 0x7, 0x7, 0x2, 0x2, 0x1da, 
       0x1dc, 0x5, 0x36, 0x1c, 0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dd, 
       0x1de, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1df, 
       0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x7, 0x6, 0x2, 0x2, 0x1e1, 
       0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1e6, 
       0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1eb, 0x5, 0x26, 0x14, 0x2, 0x1e8, 
       0x1e9, 0x7, 0x51, 0x2, 0x2, 0x1e9, 0x1eb, 0x7, 0x50, 0x2, 0x2, 0x1ea, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
       0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1ec, 
       0x1f0, 0x7, 0x52, 0x2, 0x2, 0x1ed, 0x1ee, 0x5, 0x68, 0x35, 0x2, 0x1ee, 
       0x1ef, 0x7, 0x4, 0x2, 0x2, 0x1ef, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f9, 0x5, 0x7c, 0x3f, 0x2, 0x1f3, 
       0x1f4, 0x7, 0x8, 0x2, 0x2, 0x1f4, 0x1fa, 0x5, 0x46, 0x24, 0x2, 0x1f5, 
       0x1f6, 0x7, 0x5, 0x2, 0x2, 0x1f6, 0x1f7, 0x5, 0x46, 0x24, 0x2, 0x1f7, 
       0x1f8, 0x7, 0x6, 0x2, 0x2, 0x1f8, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
       0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1fb, 
       0x200, 0x7, 0x4b, 0x2, 0x2, 0x1fc, 0x1fe, 0x7, 0x53, 0x2, 0x2, 0x1fd, 
       0x1ff, 0x5, 0x80, 0x41, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fe, 
       0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x201, 0x3, 0x2, 0x2, 0x2, 0x200, 
       0x1fc, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x207, 0x3, 0x2, 0x2, 0x2, 0x202, 0x204, 0x7, 0x32, 0x2, 0x2, 0x203, 
       0x205, 0x7, 0x54, 0x2, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x208, 0x5, 0x7e, 0x40, 0x2, 0x207, 0x202, 0x3, 0x2, 0x2, 0x2, 0x207, 
       0x208, 0x3, 0x2, 0x2, 0x2, 0x208, 0x23, 0x3, 0x2, 0x2, 0x2, 0x209, 
       0x20b, 0x5, 0x40, 0x21, 0x2, 0x20a, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20a, 
       0x20b, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 
       0x217, 0x5, 0x54, 0x2b, 0x2, 0x20d, 0x20e, 0x7, 0x25, 0x2, 0x2, 0x20e, 
       0x20f, 0x7, 0x3b, 0x2, 0x2, 0x20f, 0x214, 0x5, 0x44, 0x23, 0x2, 0x210, 
       0x211, 0x7, 0x7, 0x2, 0x2, 0x211, 0x213, 0x5, 0x44, 0x23, 0x2, 0x212, 
       0x210, 0x3, 0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 0x2, 0x214, 
       0x212, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 0x2, 0x215, 
       0x218, 0x3, 0x2, 0x2, 0x2, 0x216, 0x214, 0x3, 0x2, 0x2, 0x2, 0x217, 
       0x20d, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 
       0x21f, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x7, 0x21, 0x2, 0x2, 0x21a, 
       0x21d, 0x5, 0x36, 0x1c, 0x2, 0x21b, 0x21c, 0x9, 0x3, 0x2, 0x2, 0x21c, 
       0x21e, 0x5, 0x36, 0x1c, 0x2, 0x21d, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21d, 
       0x21e, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x220, 0x3, 0x2, 0x2, 0x2, 0x21f, 
       0x219, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x3, 0x2, 0x2, 0x2, 0x220, 
       0x25, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 0x5, 0x40, 0x21, 0x2, 0x222, 
       0x221, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 0x2, 0x223, 
       0x224, 0x3, 0x2, 0x2, 0x2, 0x224, 0x22a, 0x5, 0x28, 0x15, 0x2, 0x225, 
       0x226, 0x5, 0x56, 0x2c, 0x2, 0x226, 0x227, 0x5, 0x28, 0x15, 0x2, 
       0x227, 0x229, 0x3, 0x2, 0x2, 0x2, 0x228, 0x225, 0x3, 0x2, 0x2, 0x2, 
       0x229, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x228, 0x3, 0x2, 0x2, 0x2, 
       0x22a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x237, 0x3, 0x2, 0x2, 0x2, 
       0x22c, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x7, 0x25, 0x2, 0x2, 
       0x22e, 0x22f, 0x7, 0x3b, 0x2, 0x2, 0x22f, 0x234, 0x5, 0x44, 0x23, 
       0x2, 0x230, 0x231, 0x7, 0x7, 0x2, 0x2, 0x231, 0x233, 0x5, 0x44, 0x23, 
       0x2, 0x232, 0x230, 0x3, 0x2, 0x2, 0x2, 0x233, 0x236, 0x3, 0x2, 0x2, 
       0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 
       0x2, 0x235, 0x238, 0x3, 0x2, 0x2, 0x2, 0x236, 0x234, 0x3, 0x2, 0x2, 
       0x2, 0x237, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 
       0x2, 0x238, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x21, 0x2, 
       0x2, 0x23a, 0x23d, 0x5, 0x36, 0x1c, 0x2, 0x23b, 0x23c, 0x9, 0x3, 
       0x2, 0x2, 0x23c, 0x23e, 0x5, 0x36, 0x1c, 0x2, 0x23d, 0x23b, 0x3, 
       0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x240, 0x3, 
       0x2, 0x2, 0x2, 0x23f, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x3, 
       0x2, 0x2, 0x2, 0x240, 0x27, 0x3, 0x2, 0x2, 0x2, 0x241, 0x243, 0x7, 
       0x55, 0x2, 0x2, 0x242, 0x244, 0x9, 0x5, 0x2, 0x2, 0x243, 0x242, 0x3, 
       0x2, 0x2, 0x2, 0x243, 0x244, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x3, 
       0x2, 0x2, 0x2, 0x245, 0x24a, 0x5, 0x4a, 0x26, 0x2, 0x246, 0x247, 
       0x7, 0x7, 0x2, 0x2, 0x247, 0x249, 0x5, 0x4a, 0x26, 0x2, 0x248, 0x246, 
       0x3, 0x2, 0x2, 0x2, 0x249, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x248, 
       0x3, 0x2, 0x2, 0x2, 0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x259, 
       0x3, 0x2, 0x2, 0x2, 0x24c, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x257, 
       0x7, 0x47, 0x2, 0x2, 0x24e, 0x253, 0x5, 0x4c, 0x27, 0x2, 0x24f, 0x250, 
       0x7, 0x7, 0x2, 0x2, 0x250, 0x252, 0x5, 0x4c, 0x27, 0x2, 0x251, 0x24f, 
       0x3, 0x2, 0x2, 0x2, 0x252, 0x255, 0x3, 0x2, 0x2, 0x2, 0x253, 0x251, 
       0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x258, 
       0x3, 0x2, 0x2, 0x2, 0x255, 0x253, 0x3, 0x2, 0x2, 0x2, 0x256, 0x258, 
       0x5, 0x4e, 0x28, 0x2, 0x257, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x257, 0x256, 
       0x3, 0x2, 0x2, 0x2, 0x258, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x259, 0x24d, 
       0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25a, 0x25d, 
       0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 0x7, 0x42, 0x2, 0x2, 0x25c, 0x25e, 
       0x5, 0x36, 0x1c, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 
       0x3, 0x2, 0x2, 0x2, 0x25e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 
       0x7, 0x1f, 0x2, 0x2, 0x260, 0x261, 0x7, 0x3b, 0x2, 0x2, 0x261, 0x266, 
       0x5, 0x36, 0x1c, 0x2, 0x262, 0x263, 0x7, 0x7, 0x2, 0x2, 0x263, 0x265, 
       0x5, 0x36, 0x1c, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x268, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x264, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 
       0x3, 0x2, 0x2, 0x2, 0x267, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 
       0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x7, 0x57, 0x2, 0x2, 0x26a, 0x26c, 
       0x5, 0x36, 0x1c, 0x2, 0x26b, 0x269, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 
       0x3, 0x2, 0x2, 0x2, 0x26c, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x25f, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x28c, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x7, 0x50, 0x2, 0x2, 0x270, 0x271, 
       0x7, 0x5, 0x2, 0x2, 0x271, 0x276, 0x5, 0x36, 0x1c, 0x2, 0x272, 0x273, 
       0x7, 0x7, 0x2, 0x2, 0x273, 0x275, 0x5, 0x36, 0x1c, 0x2, 0x274, 0x272, 
       0x3, 0x2, 0x2, 0x2, 0x275, 0x278, 0x3, 0x2, 0x2, 0x2, 0x276, 0x274, 
       0x3, 0x2, 0x2, 0x2, 0x276, 0x277, 0x3, 0x2, 0x2, 0x2, 0x277, 0x279, 
       0x3, 0x2, 0x2, 0x2, 0x278, 0x276, 0x3, 0x2, 0x2, 0x2, 0x279, 0x288, 
       0x7, 0x6, 0x2, 0x2, 0x27a, 0x27b, 0x7, 0x7, 0x2, 0x2, 0x27b, 0x27c, 
       0x7, 0x5, 0x2, 0x2, 0x27c, 0x281, 0x5, 0x36, 0x1c, 0x2, 0x27d, 0x27e, 
       0x7, 0x7, 0x2, 0x2, 0x27e, 0x280, 0x5, 0x36, 0x1c, 0x2, 0x27f, 0x27d, 
       0x3, 0x2, 0x2, 0x2, 0x280, 0x283, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27f, 
       0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 0x282, 0x284, 
       0x3, 0x2, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 
       0x7, 0x6, 0x2, 0x2, 0x285, 0x287, 0x3, 0x2, 0x2, 0x2, 0x286, 0x27a, 
       0x3, 0x2, 0x2, 0x2, 0x287, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x288, 0x286, 
       0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28c, 
       0x3, 0x2, 0x2, 0x2, 0x28a, 0x288, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x241, 
       0x3, 0x2, 0x2, 0x2, 0x28b, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x28d, 0x28f, 0x5, 0x40, 0x21, 0x2, 0x28e, 0x28d, 
       0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 
       0x3, 0x2, 0x2, 0x2, 0x290, 0x29b, 0x7, 0x58, 0x2, 0x2, 0x291, 0x292, 
       0x7, 0x24, 0x2, 0x2, 0x292, 0x29c, 0x7, 0x4b, 0x2, 0x2, 0x293, 0x294, 
       0x7, 0x24, 0x2, 0x2, 0x294, 0x29c, 0x7, 0x4c, 0x2, 0x2, 0x295, 0x296, 
       0x7, 0x24, 0x2, 0x2, 0x296, 0x29c, 0x7, 0x4a, 0x2, 0x2, 0x297, 0x298, 
       0x7, 0x24, 0x2, 0x2, 0x298, 0x29c, 0x7, 0x4d, 0x2, 0x2, 0x299, 0x29a, 
       0x7, 0x24, 0x2, 0x2, 0x29a, 0x29c, 0x7, 0x4e, 0x2, 0x2, 0x29b, 0x291, 
       0x3, 0x2, 0x2, 0x2, 0x29b, 0x293, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x295, 
       0x3, 0x2, 0x2, 0x2, 0x29b, 0x297, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x299, 
       0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 
       0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x5, 0x42, 0x22, 0x2, 0x29e, 0x29f, 
       0x7, 0x59, 0x2, 0x2, 0x29f, 0x2a0, 0x5, 0x74, 0x3b, 0x2, 0x2a0, 0x2a1, 
       0x7, 0x8, 0x2, 0x2, 0x2a1, 0x2a9, 0x5, 0x36, 0x1c, 0x2, 0x2a2, 0x2a3, 
       0x7, 0x7, 0x2, 0x2, 0x2a3, 0x2a4, 0x5, 0x74, 0x3b, 0x2, 0x2a4, 0x2a5, 
       0x7, 0x8, 0x2, 0x2, 0x2a5, 0x2a6, 0x5, 0x36, 0x1c, 0x2, 0x2a6, 0x2a8, 
       0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2ab, 
       0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 
       0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a9, 
       0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x7, 0x42, 0x2, 0x2, 0x2ad, 0x2af, 
       0x5, 0x36, 0x1c, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 
       0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2b2, 
       0x5, 0x40, 0x21, 0x2, 0x2b1, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b2, 
       0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2be, 
       0x7, 0x58, 0x2, 0x2, 0x2b4, 0x2b5, 0x7, 0x24, 0x2, 0x2, 0x2b5, 0x2bf, 
       0x7, 0x4b, 0x2, 0x2, 0x2b6, 0x2b7, 0x7, 0x24, 0x2, 0x2, 0x2b7, 0x2bf, 
       0x7, 0x4c, 0x2, 0x2, 0x2b8, 0x2b9, 0x7, 0x24, 0x2, 0x2, 0x2b9, 0x2bf, 
       0x7, 0x4a, 0x2, 0x2, 0x2ba, 0x2bb, 0x7, 0x24, 0x2, 0x2, 0x2bb, 0x2bf, 
       0x7, 0x4d, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x24, 0x2, 0x2, 0x2bd, 0x2bf, 
       0x7, 0x4e, 0x2, 0x2, 0x2be, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b6, 
       0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2ba, 
       0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 
       0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 
       0x5, 0x42, 0x22, 0x2, 0x2c1, 0x2c2, 0x7, 0x59, 0x2, 0x2, 0x2c2, 0x2c3, 
       0x5, 0x74, 0x3b, 0x2, 0x2c3, 0x2c4, 0x7, 0x8, 0x2, 0x2, 0x2c4, 0x2cc, 
       0x5, 0x36, 0x1c, 0x2, 0x2c5, 0x2c6, 0x7, 0x7, 0x2, 0x2, 0x2c6, 0x2c7, 
       0x5, 0x74, 0x3b, 0x2, 0x2c7, 0x2c8, 0x7, 0x8, 0x2, 0x2, 0x2c8, 0x2c9, 
       0x5, 0x36, 0x1c, 0x2, 0x2c9, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c5, 
       0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2ca, 
       0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2d1, 
       0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 
       0x7, 0x42, 0x2, 0x2, 0x2d0, 0x2d2, 0x5, 0x36, 0x1c, 0x2, 0x2d1, 0x2cf, 
       0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2e5, 
       0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x25, 0x2, 0x2, 0x2d4, 0x2d5, 
       0x7, 0x3b, 0x2, 0x2, 0x2d5, 0x2da, 0x5, 0x44, 0x23, 0x2, 0x2d6, 0x2d7, 
       0x7, 0x7, 0x2, 0x2, 0x2d7, 0x2d9, 0x5, 0x44, 0x23, 0x2, 0x2d8, 0x2d6, 
       0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2de, 
       0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2d3, 
       0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x7, 0x21, 0x2, 0x2, 0x2e0, 0x2e3, 
       0x5, 0x36, 0x1c, 0x2, 0x2e1, 0x2e2, 0x9, 0x3, 0x2, 0x2, 0x2e2, 0x2e4, 
       0x5, 0x36, 0x1c, 0x2, 0x2e3, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 
       0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2dd, 
       0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e9, 0x5, 0x74, 0x3b, 0x2, 0x2e8, 0x2ea, 
       0x5, 0x30, 0x19, 0x2, 0x2e9, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ea, 
       0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ed, 
       0x5, 0x32, 0x1a, 0x2, 0x2ec, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ef, 
       0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2ee, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f3, 0x5, 0x64, 0x33, 0x2, 0x2f2, 0x2f1, 
       0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 
       0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x300, 
       0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x7, 0x5, 0x2, 0x2, 0x2f7, 0x2f8, 
       0x5, 0x58, 0x2d, 0x2, 0x2f8, 0x2f9, 0x7, 0x6, 0x2, 0x2, 0x2f9, 0x301, 
       0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x5, 0x2, 0x2, 0x2fb, 0x2fc, 
       0x5, 0x58, 0x2d, 0x2, 0x2fc, 0x2fd, 0x7, 0x7, 0x2, 0x2, 0x2fd, 0x2fe, 
       0x5, 0x58, 0x2d, 0x2, 0x2fe, 0x2ff, 0x7, 0x6, 0x2, 0x2, 0x2ff, 0x301, 
       0x3, 0x2, 0x2, 0x2, 0x300, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fa, 
       0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 0x2, 0x2, 0x2, 0x301, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x7, 0x5a, 0x2, 0x2, 0x303, 0x305, 
       0x5, 0x64, 0x33, 0x2, 0x304, 0x302, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 
       0x3, 0x2, 0x2, 0x2, 0x305, 0x327, 0x3, 0x2, 0x2, 0x2, 0x306, 0x307, 
       0x7, 0x5b, 0x2, 0x2, 0x307, 0x309, 0x7, 0x5c, 0x2, 0x2, 0x308, 0x30a, 
       0x9, 0x6, 0x2, 0x2, 0x309, 0x308, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30a, 
       0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30d, 
       0x5, 0x34, 0x1b, 0x2, 0x30c, 0x30e, 0x7, 0x5e, 0x2, 0x2, 0x30d, 0x30c, 
       0x3, 0x2, 0x2, 0x2, 0x30d, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x328, 
       0x3, 0x2, 0x2, 0x2, 0x30f, 0x311, 0x7, 0x22, 0x2, 0x2, 0x310, 0x30f, 
       0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 
       0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 0x7, 0x5f, 0x2, 0x2, 0x313, 0x328, 
       0x5, 0x34, 0x1b, 0x2, 0x314, 0x315, 0x7, 0x3e, 0x2, 0x2, 0x315, 0x328, 
       0x5, 0x34, 0x1b, 0x2, 0x316, 0x317, 0x7, 0x60, 0x2, 0x2, 0x317, 0x318, 
       0x7, 0x5, 0x2, 0x2, 0x318, 0x319, 0x5, 0x36, 0x1c, 0x2, 0x319, 0x31a, 
       0x7, 0x6, 0x2, 0x2, 0x31a, 0x328, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x322, 
       0x7, 0x51, 0x2, 0x2, 0x31c, 0x323, 0x5, 0x58, 0x2d, 0x2, 0x31d, 0x323, 
       0x5, 0x5a, 0x2e, 0x2, 0x31e, 0x31f, 0x7, 0x5, 0x2, 0x2, 0x31f, 0x320, 
       0x5, 0x36, 0x1c, 0x2, 0x320, 0x321, 0x7, 0x6, 0x2, 0x2, 0x321, 0x323, 
       0x3, 0x2, 0x2, 0x2, 0x322, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x322, 0x31d, 
       0x3, 0x2, 0x2, 0x2, 0x322, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x323, 0x328, 
       0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 0x7, 0x61, 0x2, 0x2, 0x325, 0x328, 
       0x5, 0x76, 0x3c, 0x2, 0x326, 0x328, 0x5, 0x3a, 0x1e, 0x2, 0x327, 
       0x306, 0x3, 0x2, 0x2, 0x2, 0x327, 0x310, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x314, 0x3, 0x2, 0x2, 0x2, 0x327, 0x316, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x31b, 0x3, 0x2, 0x2, 0x2, 0x327, 0x324, 0x3, 0x2, 0x2, 0x2, 0x327, 
       0x326, 0x3, 0x2, 0x2, 0x2, 0x328, 0x33, 0x3, 0x2, 0x2, 0x2, 0x329, 
       0x32a, 0x7, 0x23, 0x2, 0x2, 0x32a, 0x32b, 0x7, 0x62, 0x2, 0x2, 0x32b, 
       0x32d, 0x9, 0x7, 0x2, 0x2, 0x32c, 0x329, 0x3, 0x2, 0x2, 0x2, 0x32c, 
       0x32d, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x32e, 
       0x32f, 0x8, 0x1c, 0x1, 0x2, 0x32f, 0x37b, 0x5, 0x5a, 0x2e, 0x2, 0x330, 
       0x37b, 0x7, 0x63, 0x2, 0x2, 0x331, 0x332, 0x5, 0x68, 0x35, 0x2, 0x332, 
       0x333, 0x7, 0x4, 0x2, 0x2, 0x333, 0x335, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x331, 0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 0x3, 0x2, 0x2, 0x2, 0x335, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0x5, 0x6e, 0x38, 0x2, 0x337, 
       0x338, 0x7, 0x4, 0x2, 0x2, 0x338, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x339, 
       0x334, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x33a, 
       0x33b, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x37b, 0x5, 0x74, 0x3b, 0x2, 0x33c, 
       0x33d, 0x5, 0x5c, 0x2f, 0x2, 0x33d, 0x33e, 0x5, 0x36, 0x1c, 0x17, 
       0x33e, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x5, 0x66, 0x34, 
       0x2, 0x340, 0x34d, 0x7, 0x5, 0x2, 0x2, 0x341, 0x343, 0x7, 0x56, 0x2, 
       0x2, 0x342, 0x341, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x3, 0x2, 0x2, 
       0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 0x349, 0x5, 0x36, 0x1c, 
       0x2, 0x345, 0x346, 0x7, 0x7, 0x2, 0x2, 0x346, 0x348, 0x5, 0x36, 0x1c, 
       0x2, 0x347, 0x345, 0x3, 0x2, 0x2, 0x2, 0x348, 0x34b, 0x3, 0x2, 0x2, 
       0x2, 0x349, 0x347, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34a, 0x3, 0x2, 0x2, 
       0x2, 0x34a, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 0x2, 
       0x2, 0x34c, 0x34e, 0x7, 0x9, 0x2, 0x2, 0x34d, 0x342, 0x3, 0x2, 0x2, 
       0x2, 0x34d, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x3, 0x2, 0x2, 
       0x2, 0x34e, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x7, 0x6, 0x2, 
       0x2, 0x350, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x7, 0x5, 0x2, 
       0x2, 0x352, 0x353, 0x5, 0x36, 0x1c, 0x2, 0x353, 0x354, 0x7, 0x6, 
       0x2, 0x2, 0x354, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x7, 0x64, 
       0x2, 0x2, 0x356, 0x357, 0x7, 0x5, 0x2, 0x2, 0x357, 0x358, 0x5, 0x36, 
       0x1c, 0x2, 0x358, 0x359, 0x7, 0x1c, 0x2, 0x2, 0x359, 0x35a, 0x5, 
       0x30, 0x19, 0x2, 0x35a, 0x35b, 0x7, 0x6, 0x2, 0x2, 0x35b, 0x37b, 
       0x3, 0x2, 0x2, 0x2, 0x35c, 0x35e, 0x7, 0x22, 0x2, 0x2, 0x35d, 0x35c, 
       0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 
       0x3, 0x2, 0x2, 0x2, 0x35f, 0x361, 0x7, 0x41, 0x2, 0x2, 0x360, 0x35d, 
       0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 
       0x3, 0x2, 0x2, 0x2, 0x362, 0x363, 0x7, 0x5, 0x2, 0x2, 0x363, 0x364, 
       0x5, 0x26, 0x14, 0x2, 0x364, 0x365, 0x7, 0x6, 0x2, 0x2, 0x365, 0x37b, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0x368, 0x7, 0x65, 0x2, 0x2, 0x367, 0x369, 
       0x5, 0x36, 0x1c, 0x2, 0x368, 0x367, 0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 
       0x3, 0x2, 0x2, 0x2, 0x369, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36b, 
       0x7, 0x66, 0x2, 0x2, 0x36b, 0x36c, 0x5, 0x36, 0x1c, 0x2, 0x36c, 0x36d, 
       0x7, 0x67, 0x2, 0x2, 0x36d, 0x36e, 0x5, 0x36, 0x1c, 0x2, 0x36e, 0x370, 
       0x3, 0x2, 0x2, 0x2, 0x36f, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 
       0x3, 0x2, 0x2, 0x2, 0x371, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 
       0x3, 0x2, 0x2, 0x2, 0x372, 0x375, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 
       0x7, 0x68, 0x2, 0x2, 0x374, 0x376, 0x5, 0x36, 0x1c, 0x2, 0x375, 0x373, 
       0x3, 0x2, 0x2, 0x2, 0x375, 0x376, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 
       0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x7, 0x36, 0x2, 0x2, 0x378, 0x37b, 
       0x3, 0x2, 0x2, 0x2, 0x379, 0x37b, 0x5, 0x38, 0x1d, 0x2, 0x37a, 0x32e, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x330, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x339, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x33f, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x351, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x355, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x360, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x366, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x379, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x3d3, 
       0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0xc, 0x16, 0x2, 0x2, 0x37d, 0x37e, 
       0x7, 0xd, 0x2, 0x2, 0x37e, 0x3d2, 0x5, 0x36, 0x1c, 0x17, 0x37f, 0x380, 
       0xc, 0x15, 0x2, 0x2, 0x380, 0x381, 0x9, 0x8, 0x2, 0x2, 0x381, 0x3d2, 
       0x5, 0x36, 0x1c, 0x16, 0x382, 0x383, 0xc, 0x14, 0x2, 0x2, 0x383, 
       0x384, 0x9, 0x9, 0x2, 0x2, 0x384, 0x3d2, 0x5, 0x36, 0x1c, 0x15, 0x385, 
       0x386, 0xc, 0x13, 0x2, 0x2, 0x386, 0x387, 0x9, 0xa, 0x2, 0x2, 0x387, 
       0x3d2, 0x5, 0x36, 0x1c, 0x14, 0x388, 0x389, 0xc, 0x12, 0x2, 0x2, 
       0x389, 0x38a, 0x9, 0xb, 0x2, 0x2, 0x38a, 0x3d2, 0x5, 0x36, 0x1c, 
       0x13, 0x38b, 0x38c, 0xc, 0x11, 0x2, 0x2, 0x38c, 0x38d, 0x9, 0xc, 
       0x2, 0x2, 0x38d, 0x3d2, 0x5, 0x36, 0x1c, 0x12, 0x38e, 0x38f, 0xc, 
       0xf, 0x2, 0x2, 0x38f, 0x390, 0x7, 0x1b, 0x2, 0x2, 0x390, 0x3d2, 0x5, 
       0x36, 0x1c, 0x10, 0x391, 0x392, 0xc, 0xe, 0x2, 0x2, 0x392, 0x393, 
       0x7, 0x24, 0x2, 0x2, 0x393, 0x3d2, 0x5, 0x36, 0x1c, 0xf, 0x394, 0x395, 
       0xc, 0x7, 0x2, 0x2, 0x395, 0x397, 0x7, 0x69, 0x2, 0x2, 0x396, 0x398, 
       0x7, 0x22, 0x2, 0x2, 0x397, 0x396, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 0x3, 0x2, 0x2, 0x2, 0x399, 0x3d2, 
       0x5, 0x36, 0x1c, 0x8, 0x39a, 0x39c, 0xc, 0x6, 0x2, 0x2, 0x39b, 0x39d, 
       0x7, 0x22, 0x2, 0x2, 0x39c, 0x39b, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 
       0x7, 0x6a, 0x2, 0x2, 0x39f, 0x3a0, 0x5, 0x36, 0x1c, 0x2, 0x3a0, 0x3a1, 
       0x7, 0x1b, 0x2, 0x2, 0x3a1, 0x3a2, 0x5, 0x36, 0x1c, 0x7, 0x3a2, 0x3d2, 
       0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a5, 0xc, 0x10, 0x2, 0x2, 0x3a4, 0x3a6, 
       0x7, 0x22, 0x2, 0x2, 0x3a5, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 
       0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3bb, 
       0x7, 0x6b, 0x2, 0x2, 0x3a8, 0x3b2, 0x7, 0x5, 0x2, 0x2, 0x3a9, 0x3b3, 
       0x5, 0x26, 0x14, 0x2, 0x3aa, 0x3af, 0x5, 0x36, 0x1c, 0x2, 0x3ab, 
       0x3ac, 0x7, 0x7, 0x2, 0x2, 0x3ac, 0x3ae, 0x5, 0x36, 0x1c, 0x2, 0x3ad, 
       0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3af, 
       0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 
       0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3b2, 
       0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3b2, 
       0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 
       0x3bc, 0x7, 0x6, 0x2, 0x2, 0x3b5, 0x3b6, 0x5, 0x68, 0x35, 0x2, 0x3b6, 
       0x3b7, 0x7, 0x4, 0x2, 0x2, 0x3b7, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b8, 
       0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
       0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bc, 0x5, 0x6e, 0x38, 0x2, 0x3bb, 
       0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3bc, 
       0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0xc, 0xa, 0x2, 0x2, 0x3be, 
       0x3bf, 0x7, 0x61, 0x2, 0x2, 0x3bf, 0x3d2, 0x5, 0x76, 0x3c, 0x2, 0x3c0, 
       0x3c2, 0xc, 0x9, 0x2, 0x2, 0x3c1, 0x3c3, 0x7, 0x22, 0x2, 0x2, 0x3c2, 
       0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c3, 
       0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x9, 0xd, 0x2, 0x2, 0x3c5, 
       0x3c8, 0x5, 0x36, 0x1c, 0x2, 0x3c6, 0x3c7, 0x7, 0x70, 0x2, 0x2, 0x3c7, 
       0x3c9, 0x5, 0x36, 0x1c, 0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c8, 
       0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3ca, 
       0x3cf, 0xc, 0x8, 0x2, 0x2, 0x3cb, 0x3d0, 0x7, 0x71, 0x2, 0x2, 0x3cc, 
       0x3d0, 0x7, 0x72, 0x2, 0x2, 0x3cd, 0x3ce, 0x7, 0x22, 0x2, 0x2, 0x3ce, 
       0x3d0, 0x7, 0x5f, 0x2, 0x2, 0x3cf, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cf, 
       0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3d0, 
       0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x37f, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x382, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x385, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x388, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x38b, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x391, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x394, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x39a, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3d1, 
       0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d3, 
       0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d4, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d6, 
       0x3d7, 0x7, 0x73, 0x2, 0x2, 0x3d7, 0x3dc, 0x7, 0x5, 0x2, 0x2, 0x3d8, 
       0x3dd, 0x7, 0x4e, 0x2, 0x2, 0x3d9, 0x3da, 0x9, 0xe, 0x2, 0x2, 0x3da, 
       0x3db, 0x7, 0x7, 0x2, 0x2, 0x3db, 0x3dd, 0x5, 0x5e, 0x30, 0x2, 0x3dc, 
       0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3dd, 
       0x3de, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3df, 0x7, 0x6, 0x2, 0x2, 0x3df, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x7, 0x74, 0x2, 0x2, 0x3e1, 
       0x3ed, 0x5, 0x78, 0x3d, 0x2, 0x3e2, 0x3e3, 0x7, 0x5, 0x2, 0x2, 0x3e3, 
       0x3e8, 0x5, 0x74, 0x3b, 0x2, 0x3e4, 0x3e5, 0x7, 0x7, 0x2, 0x2, 0x3e5, 
       0x3e7, 0x5, 0x74, 0x3b, 0x2, 0x3e6, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e7, 
       0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e8, 
       0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ea, 
       0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 0x7, 0x6, 0x2, 0x2, 0x3ec, 
       0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3ed, 
       0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x401, 0x3, 0x2, 0x2, 0x2, 0x3ef, 
       0x3f0, 0x7, 0x23, 0x2, 0x2, 0x3f0, 0x3f9, 0x9, 0xf, 0x2, 0x2, 0x3f1, 
       0x3f2, 0x7, 0x59, 0x2, 0x2, 0x3f2, 0x3fa, 0x7, 0x5f, 0x2, 0x2, 0x3f3, 
       0x3f4, 0x7, 0x59, 0x2, 0x2, 0x3f4, 0x3fa, 0x7, 0x51, 0x2, 0x2, 0x3f5, 
       0x3fa, 0x7, 0x75, 0x2, 0x2, 0x3f6, 0x3fa, 0x7, 0x76, 0x2, 0x2, 0x3f7, 
       0x3f8, 0x7, 0x77, 0x2, 0x2, 0x3f8, 0x3fa, 0x7, 0x78, 0x2, 0x2, 0x3f9, 
       0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f9, 
       0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f9, 
       0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fb, 
       0x3fc, 0x7, 0x6f, 0x2, 0x2, 0x3fc, 0x3fe, 0x5, 0x64, 0x33, 0x2, 0x3fd, 
       0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fe, 
       0x400, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x400, 
       0x403, 0x3, 0x2, 0x2, 0x2, 0x401, 0x3ff, 0x3, 0x2, 0x2, 0x2, 0x401, 
       0x402, 0x3, 0x2, 0x2, 0x2, 0x402, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x403, 
       0x401, 0x3, 0x2, 0x2, 0x2, 0x404, 0x406, 0x7, 0x22, 0x2, 0x2, 0x405, 
       0x404, 0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 0x3, 0x2, 0x2, 0x2, 0x406, 
       0x407, 0x3, 0x2, 0x2, 0x2, 0x407, 0x40c, 0x7, 0x79, 0x2, 0x2, 0x408, 
       0x409, 0x7, 0x7a, 0x2, 0x2, 0x409, 0x40d, 0x7, 0x7b, 0x2, 0x2, 0x40a, 
       0x40b, 0x7, 0x7a, 0x2, 0x2, 0x40b, 0x40d, 0x7, 0x7c, 0x2, 0x2, 0x40c, 
       0x408, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40c, 
       0x40d, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x40e, 
       0x405, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x40f, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x410, 0x413, 0x5, 0x74, 0x3b, 0x2, 0x411, 
       0x412, 0x7, 0x61, 0x2, 0x2, 0x412, 0x414, 0x5, 0x76, 0x3c, 0x2, 0x413, 
       0x411, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 0x3, 0x2, 0x2, 0x2, 0x414, 
       0x416, 0x3, 0x2, 0x2, 0x2, 0x415, 0x417, 0x9, 0x6, 0x2, 0x2, 0x416, 
       0x415, 0x3, 0x2, 0x2, 0x2, 0x416, 0x417, 0x3, 0x2, 0x2, 0x2, 0x417, 
       0x3d, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x7, 0x5a, 0x2, 0x2, 0x419, 
       0x41b, 0x5, 0x64, 0x33, 0x2, 0x41a, 0x418, 0x3, 0x2, 0x2, 0x2, 0x41a, 
       0x41b, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x440, 0x3, 0x2, 0x2, 0x2, 0x41c, 
       0x41d, 0x7, 0x5b, 0x2, 0x2, 0x41d, 0x420, 0x7, 0x5c, 0x2, 0x2, 0x41e, 
       0x420, 0x7, 0x3e, 0x2, 0x2, 0x41f, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41f, 
       0x41e, 0x3, 0x2, 0x2, 0x2, 0x420, 0x421, 0x3, 0x2, 0x2, 0x2, 0x421, 
       0x422, 0x7, 0x5, 0x2, 0x2, 0x422, 0x427, 0x5, 0x3c, 0x1f, 0x2, 0x423, 
       0x424, 0x7, 0x7, 0x2, 0x2, 0x424, 0x426, 0x5, 0x3c, 0x1f, 0x2, 0x425, 
       0x423, 0x3, 0x2, 0x2, 0x2, 0x426, 0x429, 0x3, 0x2, 0x2, 0x2, 0x427, 
       0x425, 0x3, 0x2, 0x2, 0x2, 0x427, 0x428, 0x3, 0x2, 0x2, 0x2, 0x428, 
       0x42a, 0x3, 0x2, 0x2, 0x2, 0x429, 0x427, 0x3, 0x2, 0x2, 0x2, 0x42a, 
       0x42b, 0x7, 0x6, 0x2, 0x2, 0x42b, 0x42c, 0x5, 0x34, 0x1b, 0x2, 0x42c, 
       0x441, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42e, 0x7, 0x60, 0x2, 0x2, 0x42e, 
       0x42f, 0x7, 0x5, 0x2, 0x2, 0x42f, 0x430, 0x5, 0x36, 0x1c, 0x2, 0x430, 
       0x431, 0x7, 0x6, 0x2, 0x2, 0x431, 0x441, 0x3, 0x2, 0x2, 0x2, 0x432, 
       0x433, 0x7, 0x7d, 0x2, 0x2, 0x433, 0x434, 0x7, 0x5c, 0x2, 0x2, 0x434, 
       0x435, 0x7, 0x5, 0x2, 0x2, 0x435, 0x43a, 0x5, 0x74, 0x3b, 0x2, 0x436, 
       0x437, 0x7, 0x7, 0x2, 0x2, 0x437, 0x439, 0x5, 0x74, 0x3b, 0x2, 0x438, 
       0x436, 0x3, 0x2, 0x2, 0x2, 0x439, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x43a, 
       0x438, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x43b, 
       0x43d, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43a, 0x3, 0x2, 0x2, 0x2, 0x43d, 
       0x43e, 0x7, 0x6, 0x2, 0x2, 0x43e, 0x43f, 0x5, 0x3a, 0x1e, 0x2, 0x43f, 
       0x441, 0x3, 0x2, 0x2, 0x2, 0x440, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x440, 
       0x42d, 0x3, 0x2, 0x2, 0x2, 0x440, 0x432, 0x3, 0x2, 0x2, 0x2, 0x441, 
       0x3f, 0x3, 0x2, 0x2, 0x2, 0x442, 0x444, 0x7, 0x7e, 0x2, 0x2, 0x443, 
       0x445, 0x7, 0x7f, 0x2, 0x2, 0x444, 0x443, 0x3, 0x2, 0x2, 0x2, 0x444, 
       0x445, 0x3, 0x2, 0x2, 0x2, 0x445, 0x446, 0x3, 0x2, 0x2, 0x2, 0x446, 
       0x44b, 0x5, 0x48, 0x25, 0x2, 0x447, 0x448, 0x7, 0x7, 0x2, 0x2, 0x448, 
       0x44a, 0x5, 0x48, 0x25, 0x2, 0x449, 0x447, 0x3, 0x2, 0x2, 0x2, 0x44a, 
       0x44d, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44b, 
       0x44c, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44d, 
       0x44b, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x44f, 0x5, 0x68, 0x35, 0x2, 0x44f, 
       0x450, 0x7, 0x4, 0x2, 0x2, 0x450, 0x452, 0x3, 0x2, 0x2, 0x2, 0x451, 
       0x44e, 0x3, 0x2, 0x2, 0x2, 0x451, 0x452, 0x3, 0x2, 0x2, 0x2, 0x452, 
       0x453, 0x3, 0x2, 0x2, 0x2, 0x453, 0x459, 0x5, 0x6e, 0x38, 0x2, 0x454, 
       0x455, 0x7, 0x80, 0x2, 0x2, 0x455, 0x456, 0x7, 0x3b, 0x2, 0x2, 0x456, 
       0x45a, 0x5, 0x7a, 0x3e, 0x2, 0x457, 0x458, 0x7, 0x22, 0x2, 0x2, 0x458, 
       0x45a, 0x7, 0x80, 0x2, 0x2, 0x459, 0x454, 0x3, 0x2, 0x2, 0x2, 0x459, 
       0x457, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45a, 
       0x43, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45e, 0x5, 0x36, 0x1c, 0x2, 0x45c, 
       0x45d, 0x7, 0x61, 0x2, 0x2, 0x45d, 0x45f, 0x5, 0x76, 0x3c, 0x2, 0x45e, 
       0x45c, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45f, 
       0x461, 0x3, 0x2, 0x2, 0x2, 0x460, 0x462, 0x9, 0x6, 0x2, 0x2, 0x461, 
       0x460, 0x3, 0x2, 0x2, 0x2, 0x461, 0x462, 0x3, 0x2, 0x2, 0x2, 0x462, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x463, 0x467, 0x5, 0x58, 0x2d, 0x2, 0x464, 
       0x467, 0x5, 0x64, 0x33, 0x2, 0x465, 0x467, 0x7, 0x29, 0x2, 0x2, 0x466, 
       0x463, 0x3, 0x2, 0x2, 0x2, 0x466, 0x464, 0x3, 0x2, 0x2, 0x2, 0x466, 
       0x465, 0x3, 0x2, 0x2, 0x2, 0x467, 0x47, 0x3, 0x2, 0x2, 0x2, 0x468, 
       0x474, 0x5, 0x6e, 0x38, 0x2, 0x469, 0x46a, 0x7, 0x5, 0x2, 0x2, 0x46a, 
       0x46f, 0x5, 0x74, 0x3b, 0x2, 0x46b, 0x46c, 0x7, 0x7, 0x2, 0x2, 0x46c, 
       0x46e, 0x5, 0x74, 0x3b, 0x2, 0x46d, 0x46b, 0x3, 0x2, 0x2, 0x2, 0x46e, 
       0x471, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x46f, 
       0x470, 0x3, 0x2, 0x2, 0x2, 0x470, 0x472, 0x3, 0x2, 0x2, 0x2, 0x471, 
       0x46f, 0x3, 0x2, 0x2, 0x2, 0x472, 0x473, 0x7, 0x6, 0x2, 0x2, 0x473, 
       0x475, 0x3, 0x2, 0x2, 0x2, 0x474, 0x469, 0x3, 0x2, 0x2, 0x2, 0x474, 
       0x475, 0x3, 0x2, 0x2, 0x2, 0x475, 0x476, 0x3, 0x2, 0x2, 0x2, 0x476, 
       0x477, 0x7, 0x1c, 0x2, 0x2, 0x477, 0x478, 0x7, 0x5, 0x2, 0x2, 0x478, 
       0x479, 0x5, 0x26, 0x14, 0x2, 0x479, 0x47a, 0x7, 0x6, 0x2, 0x2, 0x47a, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x488, 0x7, 0x9, 0x2, 0x2, 0x47c, 
       0x47d, 0x5, 0x6e, 0x38, 0x2, 0x47d, 0x47e, 0x7, 0x4, 0x2, 0x2, 0x47e, 
       0x47f, 0x7, 0x9, 0x2, 0x2, 0x47f, 0x488, 0x3, 0x2, 0x2, 0x2, 0x480, 
       0x485, 0x5, 0x36, 0x1c, 0x2, 0x481, 0x483, 0x7, 0x1c, 0x2, 0x2, 0x482, 
       0x481, 0x3, 0x2, 0x2, 0x2, 0x482, 0x483, 0x3, 0x2, 0x2, 0x2, 0x483, 
       0x484, 0x3, 0x2, 0x2, 0x2, 0x484, 0x486, 0x5, 0x62, 0x32, 0x2, 0x485, 
       0x482, 0x3, 0x2, 0x2, 0x2, 0x485, 0x486, 0x3, 0x2, 0x2, 0x2, 0x486, 
       0x488, 0x3, 0x2, 0x2, 0x2, 0x487, 0x47b, 0x3, 0x2, 0x2, 0x2, 0x487, 
       0x47c, 0x3, 0x2, 0x2, 0x2, 0x487, 0x480, 0x3, 0x2, 0x2, 0x2, 0x488, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48a, 0x5, 0x6a, 0x36, 0x2, 0x48a, 
       0x48b, 0x7, 0x4, 0x2, 0x2, 0x48b, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48c, 
       0x489, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48d, 0x3, 0x2, 0x2, 0x2, 0x48d, 
       0x48e, 0x3, 0x2, 0x2, 0x2, 0x48e, 0x493, 0x5, 0x6e, 0x38, 0x2, 0x48f, 
       0x491, 0x7, 0x1c, 0x2, 0x2, 0x490, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x490, 
       0x491, 0x3, 0x2, 0x2, 0x2, 0x491, 0x492, 0x3, 0x2, 0x2, 0x2, 0x492, 
       0x494, 0x5, 0x82, 0x42, 0x2, 0x493, 0x490, 0x3, 0x2, 0x2, 0x2, 0x493, 
       0x494, 0x3, 0x2, 0x2, 0x2, 0x494, 0x49a, 0x3, 0x2, 0x2, 0x2, 0x495, 
       0x496, 0x7, 0x80, 0x2, 0x2, 0x496, 0x497, 0x7, 0x3b, 0x2, 0x2, 0x497, 
       0x49b, 0x5, 0x7a, 0x3e, 0x2, 0x498, 0x499, 0x7, 0x22, 0x2, 0x2, 0x499, 
       0x49b, 0x7, 0x80, 0x2, 0x2, 0x49a, 0x495, 0x3, 0x2, 0x2, 0x2, 0x49a, 
       0x498, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x49b, 
       0x4cc, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x49d, 0x5, 0x6a, 0x36, 0x2, 0x49d, 
       0x49e, 0x7, 0x4, 0x2, 0x2, 0x49e, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x49f, 
       0x49c, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a0, 
       0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 0x5, 0x6c, 0x37, 0x2, 0x4a2, 
       0x4ab, 0x7, 0x5, 0x2, 0x2, 0x4a3, 0x4a8, 0x5, 0x36, 0x1c, 0x2, 0x4a4, 
       0x4a5, 0x7, 0x7, 0x2, 0x2, 0x4a5, 0x4a7, 0x5, 0x36, 0x1c, 0x2, 0x4a6, 
       0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a7, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4a8, 
       0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4a9, 
       0x4ac, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4a8, 0x3, 0x2, 0x2, 0x2, 0x4ab, 
       0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 0x3, 0x2, 0x2, 0x2, 0x4ac, 
       0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4b2, 0x7, 0x6, 0x2, 0x2, 0x4ae, 
       0x4b0, 0x7, 0x1c, 0x2, 0x2, 0x4af, 0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4af, 
       0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4b1, 
       0x4b3, 0x5, 0x82, 0x42, 0x2, 0x4b2, 0x4af, 0x3, 0x2, 0x2, 0x2, 0x4b2, 
       0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4b4, 
       0x4be, 0x7, 0x5, 0x2, 0x2, 0x4b5, 0x4ba, 0x5, 0x4c, 0x27, 0x2, 0x4b6, 
       0x4b7, 0x7, 0x7, 0x2, 0x2, 0x4b7, 0x4b9, 0x5, 0x4c, 0x27, 0x2, 0x4b8, 
       0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4ba, 
       0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4bb, 
       0x4bf, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4ba, 0x3, 0x2, 0x2, 0x2, 0x4bd, 
       0x4bf, 0x5, 0x4e, 0x28, 0x2, 0x4be, 0x4b5, 0x3, 0x2, 0x2, 0x2, 0x4be, 
       0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
       0x4c1, 0x7, 0x6, 0x2, 0x2, 0x4c1, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4c2, 
       0x4c3, 0x7, 0x5, 0x2, 0x2, 0x4c3, 0x4c4, 0x5, 0x26, 0x14, 0x2, 0x4c4, 
       0x4c9, 0x7, 0x6, 0x2, 0x2, 0x4c5, 0x4c7, 0x7, 0x1c, 0x2, 0x2, 0x4c6, 
       0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c7, 
       0x4c8, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4ca, 0x5, 0x82, 0x42, 0x2, 0x4c9, 
       0x4c6, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4ca, 
       0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x48c, 0x3, 0x2, 0x2, 0x2, 0x4cb, 
       0x49f, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4cb, 
       0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4cd, 
       0x4d4, 0x5, 0x4c, 0x27, 0x2, 0x4ce, 0x4cf, 0x5, 0x50, 0x29, 0x2, 
       0x4cf, 0x4d0, 0x5, 0x4c, 0x27, 0x2, 0x4d0, 0x4d1, 0x5, 0x52, 0x2a, 
       0x2, 0x4d1, 0x4d3, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4ce, 0x3, 0x2, 0x2, 
       0x2, 0x4d3, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d2, 0x3, 0x2, 0x2, 
       0x2, 0x4d4, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0x4d6, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4e5, 0x7, 0x7, 0x2, 
       0x2, 0x4d8, 0x4da, 0x7, 0x81, 0x2, 0x2, 0x4d9, 0x4d8, 0x3, 0x2, 0x2, 
       0x2, 0x4d9, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4e1, 0x3, 0x2, 0x2, 
       0x2, 0x4db, 0x4dd, 0x7, 0x82, 0x2, 0x2, 0x4dc, 0x4de, 0x7, 0x26, 
       0x2, 0x2, 0x4dd, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4de, 0x3, 0x2, 
       0x2, 0x2, 0x4de, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e2, 0x7, 0x83, 
       0x2, 0x2, 0x4e0, 0x4e2, 0x7, 0x84, 0x2, 0x2, 0x4e1, 0x4db, 0x3, 0x2, 
       0x2, 0x2, 0x4e1, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4e0, 0x3, 0x2, 
       0x2, 0x2, 0x4e1, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e3, 0x3, 0x2, 
       0x2, 0x2, 0x4e3, 0x4e5, 0x7, 0x20, 0x2, 0x2, 0x4e4, 0x4d7, 0x3, 0x2, 
       0x2, 0x2, 0x4e4, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x51, 0x3, 0x2, 
       0x2, 0x2, 0x4e6, 0x4e7, 0x7, 0x23, 0x2, 0x2, 0x4e7, 0x4f5, 0x5, 0x36, 
       0x1c, 0x2, 0x4e8, 0x4e9, 0x7, 0x85, 0x2, 0x2, 0x4e9, 0x4ea, 0x7, 
       0x5, 0x2, 0x2, 0x4ea, 0x4ef, 0x5, 0x74, 0x3b, 0x2, 0x4eb, 0x4ec, 
       0x7, 0x7, 0x2, 0x2, 0x4ec, 0x4ee, 0x5, 0x74, 0x3b, 0x2, 0x4ed, 0x4eb, 
       0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4ed, 
       0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f2, 
       0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4f3, 
       0x7, 0x6, 0x2, 0x2, 0x4f3, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4e6, 
       0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f5, 
       0x3, 0x2, 0x2, 0x2, 0x4f5, 0x53, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f8, 
       0x7, 0x55, 0x2, 0x2, 0x4f7, 0x4f9, 0x9, 0x5, 0x2, 0x2, 0x4f8, 0x4f7, 
       0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f9, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fa, 
       0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4ff, 0x5, 0x4a, 0x26, 0x2, 0x4fb, 0x4fc, 
       0x7, 0x7, 0x2, 0x2, 0x4fc, 0x4fe, 0x5, 0x4a, 0x26, 0x2, 0x4fd, 0x4fb, 
       0x3, 0x2, 0x2, 0x2, 0x4fe, 0x501, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x4fd, 
       0x3, 0x2, 0x2, 0x2, 0x4ff, 0x500, 0x3, 0x2, 0x2, 0x2, 0x500, 0x50e, 
       0x3, 0x2, 0x2, 0x2, 0x501, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x502, 0x50c, 
       0x7, 0x47, 0x2, 0x2, 0x503, 0x508, 0x5, 0x4c, 0x27, 0x2, 0x504, 0x505, 
       0x7, 0x7, 0x2, 0x2, 0x505, 0x507, 0x5, 0x4c, 0x27, 0x2, 0x506, 0x504, 
       0x3, 0x2, 0x2, 0x2, 0x507, 0x50a, 0x3, 0x2, 0x2, 0x2, 0x508, 0x506, 
       0x3, 0x2, 0x2, 0x2, 0x508, 0x509, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50d, 
       0x3, 0x2, 0x2, 0x2, 0x50a, 0x508, 0x3, 0x2, 0x2, 0x2, 0x50b, 0x50d, 
       0x5, 0x4e, 0x28, 0x2, 0x50c, 0x503, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x50b, 
       0x3, 0x2, 0x2, 0x2, 0x50d, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x502, 
       0x3, 0x2, 0x2, 0x2, 0x50e, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50f, 0x512, 
       0x3, 0x2, 0x2, 0x2, 0x510, 0x511, 0x7, 0x42, 0x2, 0x2, 0x511, 0x513, 
       0x5, 0x36, 0x1c, 0x2, 0x512, 0x510, 0x3, 0x2, 0x2, 0x2, 0x512, 0x513, 
       0x3, 0x2, 0x2, 0x2, 0x513, 0x522, 0x3, 0x2, 0x2, 0x2, 0x514, 0x515, 
       0x7, 0x1f, 0x2, 0x2, 0x515, 0x516, 0x7, 0x3b, 0x2, 0x2, 0x516, 0x51b, 
       0x5, 0x36, 0x1c, 0x2, 0x517, 0x518, 0x7, 0x7, 0x2, 0x2, 0x518, 0x51a, 
       0x5, 0x36, 0x1c, 0x2, 0x519, 0x517, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x51d, 
       0x3, 0x2, 0x2, 0x2, 0x51b, 0x519, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51c, 
       0x3, 0x2, 0x2, 0x2, 0x51c, 0x520, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51b, 
       0x3, 0x2, 0x2, 0x2, 0x51e, 0x51f, 0x7, 0x57, 0x2, 0x2, 0x51f, 0x521, 
       0x5, 0x36, 0x1c, 0x2, 0x520, 0x51e, 0x3, 0x2, 0x2, 0x2, 0x520, 0x521, 
       0x3, 0x2, 0x2, 0x2, 0x521, 0x523, 0x3, 0x2, 0x2, 0x2, 0x522, 0x514, 
       0x3, 0x2, 0x2, 0x2, 0x522, 0x523, 0x3, 0x2, 0x2, 0x2, 0x523, 0x541, 
       0x3, 0x2, 0x2, 0x2, 0x524, 0x525, 0x7, 0x50, 0x2, 0x2, 0x525, 0x526, 
       0x7, 0x5, 0x2, 0x2, 0x526, 0x52b, 0x5, 0x36, 0x1c, 0x2, 0x527, 0x528, 
       0x7, 0x7, 0x2, 0x2, 0x528, 0x52a, 0x5, 0x36, 0x1c, 0x2, 0x529, 0x527, 
       0x3, 0x2, 0x2, 0x2, 0x52a, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x529, 
       0x3, 0x2, 0x2, 0x2, 0x52b, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x52e, 
       0x3, 0x2, 0x2, 0x2, 0x52d, 0x52b, 0x3, 0x2, 0x2, 0x2, 0x52e, 0x53d, 
       0x7, 0x6, 0x2, 0x2, 0x52f, 0x530, 0x7, 0x7, 0x2, 0x2, 0x530, 0x531, 
       0x7, 0x5, 0x2, 0x2, 0x531, 0x536, 0x5, 0x36, 0x1c, 0x2, 0x532, 0x533, 
       0x7, 0x7, 0x2, 0x2, 0x533, 0x535, 0x5, 0x36, 0x1c, 0x2, 0x534, 0x532, 
       0x3, 0x2, 0x2, 0x2, 0x535, 0x538, 0x3, 0x2, 0x2, 0x2, 0x536, 0x534, 
       0x3, 0x2, 0x2, 0x2, 0x536, 0x537, 0x3, 0x2, 0x2, 0x2, 0x537, 0x539, 
       0x3, 0x2, 0x2, 0x2, 0x538, 0x536, 0x3, 0x2, 0x2, 0x2, 0x539, 0x53a, 
       0x7, 0x6, 0x2, 0x2, 0x53a, 0x53c, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x52f, 
       0x3, 0x2, 0x2, 0x2, 0x53c, 0x53f, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53b, 
       0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x541, 
       0x3, 0x2, 0x2, 0x2, 0x53f, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x540, 0x4f6, 
       0x3, 0x2, 0x2, 0x2, 0x540, 0x524, 0x3, 0x2, 0x2, 0x2, 0x541, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x542, 0x548, 0x7, 0x37, 0x2, 0x2, 0x543, 0x544, 
       0x7, 0x37, 0x2, 0x2, 0x544, 0x548, 0x7, 0x38, 0x2, 0x2, 0x545, 0x548, 
       0x7, 0x39, 0x2, 0x2, 0x546, 0x548, 0x7, 0x3a, 0x2, 0x2, 0x547, 0x542, 
       0x3, 0x2, 0x2, 0x2, 0x547, 0x543, 0x3, 0x2, 0x2, 0x2, 0x547, 0x545, 
       0x3, 0x2, 0x2, 0x2, 0x547, 0x546, 0x3, 0x2, 0x2, 0x2, 0x548, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x549, 0x54b, 0x9, 0x9, 0x2, 0x2, 0x54a, 0x549, 
       0x3, 0x2, 0x2, 0x2, 0x54a, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x54c, 
       0x3, 0x2, 0x2, 0x2, 0x54c, 0x54d, 0x7, 0x28, 0x2, 0x2, 0x54d, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x54e, 0x54f, 0x9, 0x10, 0x2, 0x2, 0x54f, 0x5b, 
       0x3, 0x2, 0x2, 0x2, 0x550, 0x551, 0x9, 0x11, 0x2, 0x2, 0x551, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x552, 0x553, 0x7, 0x29, 0x2, 0x2, 0x553, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x554, 0x557, 0x5, 0x36, 0x1c, 0x2, 0x555, 0x557, 
       0x5, 0x2e, 0x18, 0x2, 0x556, 0x554, 0x3, 0x2, 0x2, 0x2, 0x556, 0x555, 
       0x3, 0x2, 0x2, 0x2, 0x557, 0x61, 0x3, 0x2, 0x2, 0x2, 0x558, 0x559, 
       0x9, 0x12, 0x2, 0x2, 0x559, 0x63, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x55b, 
       0x5, 0x84, 0x43, 0x2, 0x55b, 0x65, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55d, 
       0x5, 0x84, 0x43, 0x2, 0x55d, 0x67, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x55f, 
       0x5, 0x84, 0x43, 0x2, 0x55f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x560, 0x561, 
       0x5, 0x84, 0x43, 0x2, 0x561, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x562, 0x563, 
       0x5, 0x84, 0x43, 0x2, 0x563, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x564, 0x565, 
       0x5, 0x84, 0x43, 0x2, 0x565, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 
       0x5, 0x84, 0x43, 0x2, 0x567, 0x71, 0x3, 0x2, 0x2, 0x2, 0x568, 0x569, 
       0x5, 0x84, 0x43, 0x2, 0x569, 0x73, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x56b, 
       0x5, 0x84, 0x43, 0x2, 0x56b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 
       0x5, 0x84, 0x43, 0x2, 0x56d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56f, 
       0x5, 0x84, 0x43, 0x2, 0x56f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x570, 0x571, 
       0x5, 0x84, 0x43, 0x2, 0x571, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x572, 0x573, 
       0x5, 0x84, 0x43, 0x2, 0x573, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x574, 0x575, 
       0x5, 0x84, 0x43, 0x2, 0x575, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x576, 0x577, 
       0x5, 0x84, 0x43, 0x2, 0x577, 0x81, 0x3, 0x2, 0x2, 0x2, 0x578, 0x57f, 
       0x7, 0x27, 0x2, 0x2, 0x579, 0x57f, 0x7, 0x29, 0x2, 0x2, 0x57a, 0x57b, 
       0x7, 0x5, 0x2, 0x2, 0x57b, 0x57c, 0x5, 0x82, 0x42, 0x2, 0x57c, 0x57d, 
       0x7, 0x6, 0x2, 0x2, 0x57d, 0x57f, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x578, 
       0x3, 0x2, 0x2, 0x2, 0x57e, 0x579, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57a, 
       0x3, 0x2, 0x2, 0x2, 0x57f, 0x83, 0x3, 0x2, 0x2, 0x2, 0x580, 0x588, 
       0x7, 0x27, 0x2, 0x2, 0x581, 0x588, 0x5, 0x86, 0x44, 0x2, 0x582, 0x588, 
       0x7, 0x29, 0x2, 0x2, 0x583, 0x584, 0x7, 0x5, 0x2, 0x2, 0x584, 0x585, 
       0x5, 0x84, 0x43, 0x2, 0x585, 0x586, 0x7, 0x6, 0x2, 0x2, 0x586, 0x588, 
       0x3, 0x2, 0x2, 0x2, 0x587, 0x580, 0x3, 0x2, 0x2, 0x2, 0x587, 0x581, 
       0x3, 0x2, 0x2, 0x2, 0x587, 0x582, 0x3, 0x2, 0x2, 0x2, 0x587, 0x583, 
       0x3, 0x2, 0x2, 0x2, 0x588, 0x85, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58a, 
       0x9, 0x13, 0x2, 0x2, 0x58a, 0x87, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x8b, 
       0x93, 0x9a, 0x9f, 0xa5, 0xb9, 0xc0, 0xc8, 0xcb, 0xd2, 0xd7, 0xdb, 
       0xe0, 0xe9, 0xec, 0xf2, 0xf4, 0xf8, 0xfe, 0x103, 0x10e, 0x114, 0x118, 
       0x11e, 0x123, 0x12c, 0x133, 0x139, 0x13d, 0x140, 0x147, 0x14a, 0x151, 
       0x15a, 0x15d, 0x163, 0x165, 0x16b, 0x170, 0x178, 0x17d, 0x182, 0x18a, 
       0x194, 0x197, 0x19d, 0x19f, 0x1a2, 0x1b5, 0x1bb, 0x1c4, 0x1c9, 0x1d2, 
       0x1dd, 0x1e4, 0x1ea, 0x1f0, 0x1f9, 0x1fe, 0x200, 0x204, 0x207, 0x20a, 
       0x214, 0x217, 0x21d, 0x21f, 0x222, 0x22a, 0x234, 0x237, 0x23d, 0x23f, 
       0x243, 0x24a, 0x253, 0x257, 0x259, 0x25d, 0x266, 0x26b, 0x26d, 0x276, 
       0x281, 0x288, 0x28b, 0x28e, 0x29b, 0x2a9, 0x2ae, 0x2b1, 0x2be, 0x2cc, 
       0x2d1, 0x2da, 0x2dd, 0x2e3, 0x2e5, 0x2e9, 0x2ee, 0x2f4, 0x300, 0x304, 
       0x309, 0x30d, 0x310, 0x322, 0x327, 0x32c, 0x334, 0x339, 0x342, 0x349, 
       0x34d, 0x35d, 0x360, 0x368, 0x371, 0x375, 0x37a, 0x397, 0x39c, 0x3a5, 
       0x3af, 0x3b2, 0x3b8, 0x3bb, 0x3c2, 0x3c8, 0x3cf, 0x3d1, 0x3d3, 0x3dc, 
       0x3e8, 0x3ed, 0x3f9, 0x3fd, 0x401, 0x405, 0x40c, 0x40e, 0x413, 0x416, 
       0x41a, 0x41f, 0x427, 0x43a, 0x440, 0x444, 0x44b, 0x451, 0x459, 0x45e, 
       0x461, 0x466, 0x46f, 0x474, 0x482, 0x485, 0x487, 0x48c, 0x490, 0x493, 
       0x49a, 0x49f, 0x4a8, 0x4ab, 0x4af, 0x4b2, 0x4ba, 0x4be, 0x4c6, 0x4c9, 
       0x4cb, 0x4d4, 0x4d9, 0x4dd, 0x4e1, 0x4e4, 0x4ef, 0x4f4, 0x4f8, 0x4ff, 
       0x508, 0x50c, 0x50e, 0x512, 0x51b, 0x520, 0x522, 0x52b, 0x536, 0x53d, 
       0x540, 0x547, 0x54a, 0x556, 0x57e, 0x587, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PotatoSQLParser::Initializer PotatoSQLParser::_init;
