
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2


#include "PotatoSQLListener.h"
#include "PotatoSQLVisitor.h"

#include "PotatoSQLParser.h"


using namespace antlrcpp;
using namespace potatosql;
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

std::vector<PotatoSQLParser::ErrorContext *> PotatoSQLParser::MainContext::error() {
  return getRuleContexts<PotatoSQLParser::ErrorContext>();
}

PotatoSQLParser::ErrorContext* PotatoSQLParser::MainContext::error(size_t i) {
  return getRuleContext<PotatoSQLParser::ErrorContext>(i);
}


size_t PotatoSQLParser::MainContext::getRuleIndex() const {
  return PotatoSQLParser::RuleMain;
}

void PotatoSQLParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void PotatoSQLParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


antlrcpp::Any PotatoSQLParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
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
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::SCOL)
      | (1ULL << PotatoSQLParser::K_ALTER)
      | (1ULL << PotatoSQLParser::K_ANALYZE)
      | (1ULL << PotatoSQLParser::K_ATTACH)
      | (1ULL << PotatoSQLParser::K_BEGIN)
      | (1ULL << PotatoSQLParser::K_COMMIT)
      | (1ULL << PotatoSQLParser::K_CREATE)
      | (1ULL << PotatoSQLParser::K_DELETE)
      | (1ULL << PotatoSQLParser::K_DETACH)
      | (1ULL << PotatoSQLParser::K_DROP))) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (PotatoSQLParser::K_END - 66))
      | (1ULL << (PotatoSQLParser::K_EXPLAIN - 66))
      | (1ULL << (PotatoSQLParser::K_INSERT - 66))
      | (1ULL << (PotatoSQLParser::K_PRAGMA - 66))
      | (1ULL << (PotatoSQLParser::K_REINDEX - 66))
      | (1ULL << (PotatoSQLParser::K_RELEASE - 66))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 66))
      | (1ULL << (PotatoSQLParser::K_ROLLBACK - 66))
      | (1ULL << (PotatoSQLParser::K_SAVEPOINT - 66))
      | (1ULL << (PotatoSQLParser::K_SELECT - 66)))) != 0) || ((((_la - 139) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 139)) & ((1ULL << (PotatoSQLParser::K_UPDATE - 139))
      | (1ULL << (PotatoSQLParser::K_VACUUM - 139))
      | (1ULL << (PotatoSQLParser::K_VALUES - 139))
      | (1ULL << (PotatoSQLParser::K_WITH - 139))
      | (1ULL << (PotatoSQLParser::UNEXPECTED_CHAR - 139)))) != 0)) {
      setState(178);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::SCOL:
        case PotatoSQLParser::K_ALTER:
        case PotatoSQLParser::K_ANALYZE:
        case PotatoSQLParser::K_ATTACH:
        case PotatoSQLParser::K_BEGIN:
        case PotatoSQLParser::K_COMMIT:
        case PotatoSQLParser::K_CREATE:
        case PotatoSQLParser::K_DELETE:
        case PotatoSQLParser::K_DETACH:
        case PotatoSQLParser::K_DROP:
        case PotatoSQLParser::K_END:
        case PotatoSQLParser::K_EXPLAIN:
        case PotatoSQLParser::K_INSERT:
        case PotatoSQLParser::K_PRAGMA:
        case PotatoSQLParser::K_REINDEX:
        case PotatoSQLParser::K_RELEASE:
        case PotatoSQLParser::K_REPLACE:
        case PotatoSQLParser::K_ROLLBACK:
        case PotatoSQLParser::K_SAVEPOINT:
        case PotatoSQLParser::K_SELECT:
        case PotatoSQLParser::K_UPDATE:
        case PotatoSQLParser::K_VACUUM:
        case PotatoSQLParser::K_VALUES:
        case PotatoSQLParser::K_WITH: {
          setState(176);
          sql_stmt_list();
          break;
        }

        case PotatoSQLParser::UNEXPECTED_CHAR: {
          setState(177);
          error();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(183);
    match(PotatoSQLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ErrorContext ------------------------------------------------------------------

PotatoSQLParser::ErrorContext::ErrorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::ErrorContext::UNEXPECTED_CHAR() {
  return getToken(PotatoSQLParser::UNEXPECTED_CHAR, 0);
}


size_t PotatoSQLParser::ErrorContext::getRuleIndex() const {
  return PotatoSQLParser::RuleError;
}

void PotatoSQLParser::ErrorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError(this);
}

void PotatoSQLParser::ErrorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError(this);
}


antlrcpp::Any PotatoSQLParser::ErrorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitError(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::ErrorContext* PotatoSQLParser::error() {
  ErrorContext *_localctx = _tracker.createInstance<ErrorContext>(_ctx, getState());
  enterRule(_localctx, 2, PotatoSQLParser::RuleError);

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
    dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken = match(PotatoSQLParser::UNEXPECTED_CHAR);
     
         throw new RuntimeException("UNEXPECTED_CHAR=" + (dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken != nullptr ? dynamic_cast<ErrorContext *>(_localctx)->unexpected_charToken->getText() : "")); 
       
   
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

void PotatoSQLParser::Sql_stmt_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt_list(this);
}

void PotatoSQLParser::Sql_stmt_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt_list(this);
}


antlrcpp::Any PotatoSQLParser::Sql_stmt_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSql_stmt_list(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Sql_stmt_listContext* PotatoSQLParser::sql_stmt_list() {
  Sql_stmt_listContext *_localctx = _tracker.createInstance<Sql_stmt_listContext>(_ctx, getState());
  enterRule(_localctx, 4, PotatoSQLParser::RuleSql_stmt_list);
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
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::SCOL) {
      setState(188);
      match(PotatoSQLParser::SCOL);
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(194);
    sql_stmt();
    setState(203);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(196); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(195);
          match(PotatoSQLParser::SCOL);
          setState(198); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PotatoSQLParser::SCOL);
        setState(200);
        sql_stmt(); 
      }
      setState(205);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(209);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(206);
        match(PotatoSQLParser::SCOL); 
      }
      setState(211);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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

PotatoSQLParser::Analyze_stmtContext* PotatoSQLParser::Sql_stmtContext::analyze_stmt() {
  return getRuleContext<PotatoSQLParser::Analyze_stmtContext>(0);
}

PotatoSQLParser::Attach_stmtContext* PotatoSQLParser::Sql_stmtContext::attach_stmt() {
  return getRuleContext<PotatoSQLParser::Attach_stmtContext>(0);
}

PotatoSQLParser::Begin_stmtContext* PotatoSQLParser::Sql_stmtContext::begin_stmt() {
  return getRuleContext<PotatoSQLParser::Begin_stmtContext>(0);
}

PotatoSQLParser::Commit_stmtContext* PotatoSQLParser::Sql_stmtContext::commit_stmt() {
  return getRuleContext<PotatoSQLParser::Commit_stmtContext>(0);
}

PotatoSQLParser::Compound_select_stmtContext* PotatoSQLParser::Sql_stmtContext::compound_select_stmt() {
  return getRuleContext<PotatoSQLParser::Compound_select_stmtContext>(0);
}

PotatoSQLParser::Create_index_stmtContext* PotatoSQLParser::Sql_stmtContext::create_index_stmt() {
  return getRuleContext<PotatoSQLParser::Create_index_stmtContext>(0);
}

PotatoSQLParser::Create_table_stmtContext* PotatoSQLParser::Sql_stmtContext::create_table_stmt() {
  return getRuleContext<PotatoSQLParser::Create_table_stmtContext>(0);
}

PotatoSQLParser::Create_trigger_stmtContext* PotatoSQLParser::Sql_stmtContext::create_trigger_stmt() {
  return getRuleContext<PotatoSQLParser::Create_trigger_stmtContext>(0);
}

PotatoSQLParser::Create_view_stmtContext* PotatoSQLParser::Sql_stmtContext::create_view_stmt() {
  return getRuleContext<PotatoSQLParser::Create_view_stmtContext>(0);
}

PotatoSQLParser::Create_virtual_table_stmtContext* PotatoSQLParser::Sql_stmtContext::create_virtual_table_stmt() {
  return getRuleContext<PotatoSQLParser::Create_virtual_table_stmtContext>(0);
}

PotatoSQLParser::Delete_stmtContext* PotatoSQLParser::Sql_stmtContext::delete_stmt() {
  return getRuleContext<PotatoSQLParser::Delete_stmtContext>(0);
}

PotatoSQLParser::Delete_stmt_limitedContext* PotatoSQLParser::Sql_stmtContext::delete_stmt_limited() {
  return getRuleContext<PotatoSQLParser::Delete_stmt_limitedContext>(0);
}

PotatoSQLParser::Detach_stmtContext* PotatoSQLParser::Sql_stmtContext::detach_stmt() {
  return getRuleContext<PotatoSQLParser::Detach_stmtContext>(0);
}

PotatoSQLParser::Drop_index_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_index_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_index_stmtContext>(0);
}

PotatoSQLParser::Drop_table_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_table_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_table_stmtContext>(0);
}

PotatoSQLParser::Drop_trigger_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_trigger_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_trigger_stmtContext>(0);
}

PotatoSQLParser::Drop_view_stmtContext* PotatoSQLParser::Sql_stmtContext::drop_view_stmt() {
  return getRuleContext<PotatoSQLParser::Drop_view_stmtContext>(0);
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

PotatoSQLParser::Reindex_stmtContext* PotatoSQLParser::Sql_stmtContext::reindex_stmt() {
  return getRuleContext<PotatoSQLParser::Reindex_stmtContext>(0);
}

PotatoSQLParser::Release_stmtContext* PotatoSQLParser::Sql_stmtContext::release_stmt() {
  return getRuleContext<PotatoSQLParser::Release_stmtContext>(0);
}

PotatoSQLParser::Rollback_stmtContext* PotatoSQLParser::Sql_stmtContext::rollback_stmt() {
  return getRuleContext<PotatoSQLParser::Rollback_stmtContext>(0);
}

PotatoSQLParser::Savepoint_stmtContext* PotatoSQLParser::Sql_stmtContext::savepoint_stmt() {
  return getRuleContext<PotatoSQLParser::Savepoint_stmtContext>(0);
}

PotatoSQLParser::Simple_select_stmtContext* PotatoSQLParser::Sql_stmtContext::simple_select_stmt() {
  return getRuleContext<PotatoSQLParser::Simple_select_stmtContext>(0);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Sql_stmtContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

PotatoSQLParser::Update_stmtContext* PotatoSQLParser::Sql_stmtContext::update_stmt() {
  return getRuleContext<PotatoSQLParser::Update_stmtContext>(0);
}

PotatoSQLParser::Update_stmt_limitedContext* PotatoSQLParser::Sql_stmtContext::update_stmt_limited() {
  return getRuleContext<PotatoSQLParser::Update_stmt_limitedContext>(0);
}

PotatoSQLParser::Vacuum_stmtContext* PotatoSQLParser::Sql_stmtContext::vacuum_stmt() {
  return getRuleContext<PotatoSQLParser::Vacuum_stmtContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Sql_stmtContext::K_EXPLAIN() {
  return getToken(PotatoSQLParser::K_EXPLAIN, 0);
}

tree::TerminalNode* PotatoSQLParser::Sql_stmtContext::K_QUERY() {
  return getToken(PotatoSQLParser::K_QUERY, 0);
}

tree::TerminalNode* PotatoSQLParser::Sql_stmtContext::K_PLAN() {
  return getToken(PotatoSQLParser::K_PLAN, 0);
}


size_t PotatoSQLParser::Sql_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSql_stmt;
}

void PotatoSQLParser::Sql_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSql_stmt(this);
}

void PotatoSQLParser::Sql_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSql_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Sql_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSql_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Sql_stmtContext* PotatoSQLParser::sql_stmt() {
  Sql_stmtContext *_localctx = _tracker.createInstance<Sql_stmtContext>(_ctx, getState());
  enterRule(_localctx, 6, PotatoSQLParser::RuleSql_stmt);
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
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_EXPLAIN) {
      setState(212);
      match(PotatoSQLParser::K_EXPLAIN);
      setState(215);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_QUERY) {
        setState(213);
        match(PotatoSQLParser::K_QUERY);
        setState(214);
        match(PotatoSQLParser::K_PLAN);
      }
    }
    setState(249);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(219);
      alter_table_stmt();
      break;
    }

    case 2: {
      setState(220);
      analyze_stmt();
      break;
    }

    case 3: {
      setState(221);
      attach_stmt();
      break;
    }

    case 4: {
      setState(222);
      begin_stmt();
      break;
    }

    case 5: {
      setState(223);
      commit_stmt();
      break;
    }

    case 6: {
      setState(224);
      compound_select_stmt();
      break;
    }

    case 7: {
      setState(225);
      create_index_stmt();
      break;
    }

    case 8: {
      setState(226);
      create_table_stmt();
      break;
    }

    case 9: {
      setState(227);
      create_trigger_stmt();
      break;
    }

    case 10: {
      setState(228);
      create_view_stmt();
      break;
    }

    case 11: {
      setState(229);
      create_virtual_table_stmt();
      break;
    }

    case 12: {
      setState(230);
      delete_stmt();
      break;
    }

    case 13: {
      setState(231);
      delete_stmt_limited();
      break;
    }

    case 14: {
      setState(232);
      detach_stmt();
      break;
    }

    case 15: {
      setState(233);
      drop_index_stmt();
      break;
    }

    case 16: {
      setState(234);
      drop_table_stmt();
      break;
    }

    case 17: {
      setState(235);
      drop_trigger_stmt();
      break;
    }

    case 18: {
      setState(236);
      drop_view_stmt();
      break;
    }

    case 19: {
      setState(237);
      factored_select_stmt();
      break;
    }

    case 20: {
      setState(238);
      insert_stmt();
      break;
    }

    case 21: {
      setState(239);
      pragma_stmt();
      break;
    }

    case 22: {
      setState(240);
      reindex_stmt();
      break;
    }

    case 23: {
      setState(241);
      release_stmt();
      break;
    }

    case 24: {
      setState(242);
      rollback_stmt();
      break;
    }

    case 25: {
      setState(243);
      savepoint_stmt();
      break;
    }

    case 26: {
      setState(244);
      simple_select_stmt();
      break;
    }

    case 27: {
      setState(245);
      select_stmt();
      break;
    }

    case 28: {
      setState(246);
      update_stmt();
      break;
    }

    case 29: {
      setState(247);
      update_stmt_limited();
      break;
    }

    case 30: {
      setState(248);
      vacuum_stmt();
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

void PotatoSQLParser::Alter_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter_table_stmt(this);
}

void PotatoSQLParser::Alter_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter_table_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Alter_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitAlter_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Alter_table_stmtContext* PotatoSQLParser::alter_table_stmt() {
  Alter_table_stmtContext *_localctx = _tracker.createInstance<Alter_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, PotatoSQLParser::RuleAlter_table_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(PotatoSQLParser::K_ALTER);
    setState(252);
    match(PotatoSQLParser::K_TABLE);
    setState(256);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(253);
      database_name();
      setState(254);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(258);
    table_name();
    setState(267);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_RENAME: {
        setState(259);
        match(PotatoSQLParser::K_RENAME);
        setState(260);
        match(PotatoSQLParser::K_TO);
        setState(261);
        new_table_name();
        break;
      }

      case PotatoSQLParser::K_ADD: {
        setState(262);
        match(PotatoSQLParser::K_ADD);
        setState(264);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(263);
          match(PotatoSQLParser::K_COLUMN);
          break;
        }

        default:
          break;
        }
        setState(266);
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

//----------------- Analyze_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Analyze_stmtContext::Analyze_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Analyze_stmtContext::K_ANALYZE() {
  return getToken(PotatoSQLParser::K_ANALYZE, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Analyze_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

PotatoSQLParser::Table_or_index_nameContext* PotatoSQLParser::Analyze_stmtContext::table_or_index_name() {
  return getRuleContext<PotatoSQLParser::Table_or_index_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Analyze_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Analyze_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleAnalyze_stmt;
}

void PotatoSQLParser::Analyze_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalyze_stmt(this);
}

void PotatoSQLParser::Analyze_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalyze_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Analyze_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitAnalyze_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Analyze_stmtContext* PotatoSQLParser::analyze_stmt() {
  Analyze_stmtContext *_localctx = _tracker.createInstance<Analyze_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, PotatoSQLParser::RuleAnalyze_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(PotatoSQLParser::K_ANALYZE);
    setState(276);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(270);
      database_name();
      break;
    }

    case 2: {
      setState(271);
      table_or_index_name();
      break;
    }

    case 3: {
      setState(272);
      database_name();
      setState(273);
      match(PotatoSQLParser::DOT);
      setState(274);
      table_or_index_name();
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

//----------------- Attach_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Attach_stmtContext::Attach_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Attach_stmtContext::K_ATTACH() {
  return getToken(PotatoSQLParser::K_ATTACH, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Attach_stmtContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Attach_stmtContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Attach_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Attach_stmtContext::K_DATABASE() {
  return getToken(PotatoSQLParser::K_DATABASE, 0);
}


size_t PotatoSQLParser::Attach_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleAttach_stmt;
}

void PotatoSQLParser::Attach_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttach_stmt(this);
}

void PotatoSQLParser::Attach_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttach_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Attach_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitAttach_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Attach_stmtContext* PotatoSQLParser::attach_stmt() {
  Attach_stmtContext *_localctx = _tracker.createInstance<Attach_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, PotatoSQLParser::RuleAttach_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    match(PotatoSQLParser::K_ATTACH);
    setState(280);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(279);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(282);
    expr(0);
    setState(283);
    match(PotatoSQLParser::K_AS);
    setState(284);
    database_name();
   
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

tree::TerminalNode* PotatoSQLParser::Begin_stmtContext::K_TRANSACTION() {
  return getToken(PotatoSQLParser::K_TRANSACTION, 0);
}

tree::TerminalNode* PotatoSQLParser::Begin_stmtContext::K_DEFERRED() {
  return getToken(PotatoSQLParser::K_DEFERRED, 0);
}

tree::TerminalNode* PotatoSQLParser::Begin_stmtContext::K_IMMEDIATE() {
  return getToken(PotatoSQLParser::K_IMMEDIATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Begin_stmtContext::K_EXCLUSIVE() {
  return getToken(PotatoSQLParser::K_EXCLUSIVE, 0);
}

PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::Begin_stmtContext::transaction_name() {
  return getRuleContext<PotatoSQLParser::Transaction_nameContext>(0);
}


size_t PotatoSQLParser::Begin_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleBegin_stmt;
}

void PotatoSQLParser::Begin_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBegin_stmt(this);
}

void PotatoSQLParser::Begin_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBegin_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Begin_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitBegin_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Begin_stmtContext* PotatoSQLParser::begin_stmt() {
  Begin_stmtContext *_localctx = _tracker.createInstance<Begin_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, PotatoSQLParser::RuleBegin_stmt);
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
    setState(286);
    match(PotatoSQLParser::K_BEGIN);
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (PotatoSQLParser::K_DEFERRED - 58))
      | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 58))
      | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 58)))) != 0)) {
      setState(287);
      _la = _input->LA(1);
      if (!(((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (PotatoSQLParser::K_DEFERRED - 58))
        | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 58))
        | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 58)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(290);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(292);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(291);
        transaction_name();
        break;
      }

      default:
        break;
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

tree::TerminalNode* PotatoSQLParser::Commit_stmtContext::K_TRANSACTION() {
  return getToken(PotatoSQLParser::K_TRANSACTION, 0);
}

PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::Commit_stmtContext::transaction_name() {
  return getRuleContext<PotatoSQLParser::Transaction_nameContext>(0);
}


size_t PotatoSQLParser::Commit_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCommit_stmt;
}

void PotatoSQLParser::Commit_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommit_stmt(this);
}

void PotatoSQLParser::Commit_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommit_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Commit_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCommit_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Commit_stmtContext* PotatoSQLParser::commit_stmt() {
  Commit_stmtContext *_localctx = _tracker.createInstance<Commit_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, PotatoSQLParser::RuleCommit_stmt);
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
    setState(296);
    _la = _input->LA(1);
    if (!(_la == PotatoSQLParser::K_COMMIT

    || _la == PotatoSQLParser::K_END)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(301);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(297);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(299);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(298);
        transaction_name();
        break;
      }

      default:
        break;
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

void PotatoSQLParser::Compound_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_select_stmt(this);
}

void PotatoSQLParser::Compound_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_select_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Compound_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCompound_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Compound_select_stmtContext* PotatoSQLParser::compound_select_stmt() {
  Compound_select_stmtContext *_localctx = _tracker.createInstance<Compound_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 18, PotatoSQLParser::RuleCompound_select_stmt);
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
    setState(304);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(303);
      with_clause();
    }
    setState(306);
    select_core();
    setState(316); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(313);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_UNION: {
          setState(307);
          match(PotatoSQLParser::K_UNION);
          setState(309);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_ALL) {
            setState(308);
            match(PotatoSQLParser::K_ALL);
          }
          break;
        }

        case PotatoSQLParser::K_INTERSECT: {
          setState(311);
          match(PotatoSQLParser::K_INTERSECT);
          break;
        }

        case PotatoSQLParser::K_EXCEPT: {
          setState(312);
          match(PotatoSQLParser::K_EXCEPT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(315);
      select_core();
      setState(318); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(320);
      match(PotatoSQLParser::K_ORDER);
      setState(321);
      match(PotatoSQLParser::K_BY);
      setState(322);
      ordering_term();
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(323);
        match(PotatoSQLParser::COMMA);
        setState(324);
        ordering_term();
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(338);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(332);
      match(PotatoSQLParser::K_LIMIT);
      setState(333);
      expr(0);
      setState(336);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(334);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(335);
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

void PotatoSQLParser::Create_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_index_stmt(this);
}

void PotatoSQLParser::Create_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_index_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Create_index_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCreate_index_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Create_index_stmtContext* PotatoSQLParser::create_index_stmt() {
  Create_index_stmtContext *_localctx = _tracker.createInstance<Create_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, PotatoSQLParser::RuleCreate_index_stmt);
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
    setState(340);
    match(PotatoSQLParser::K_CREATE);
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_UNIQUE) {
      setState(341);
      match(PotatoSQLParser::K_UNIQUE);
    }
    setState(344);
    match(PotatoSQLParser::K_INDEX);
    setState(348);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(345);
      match(PotatoSQLParser::K_IF);
      setState(346);
      match(PotatoSQLParser::K_NOT);
      setState(347);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(353);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(350);
      database_name();
      setState(351);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(355);
    index_name();
    setState(356);
    match(PotatoSQLParser::K_ON);
    setState(357);
    table_name();
    setState(358);
    match(PotatoSQLParser::OPEN_PAR);
    setState(359);
    indexed_column();
    setState(364);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(360);
      match(PotatoSQLParser::COMMA);
      setState(361);
      indexed_column();
      setState(366);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(367);
    match(PotatoSQLParser::CLOSE_PAR);
    setState(370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(368);
      match(PotatoSQLParser::K_WHERE);
      setState(369);
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

void PotatoSQLParser::Create_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_table_stmt(this);
}

void PotatoSQLParser::Create_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_table_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Create_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCreate_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Create_table_stmtContext* PotatoSQLParser::create_table_stmt() {
  Create_table_stmtContext *_localctx = _tracker.createInstance<Create_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, PotatoSQLParser::RuleCreate_table_stmt);
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
    setState(372);
    match(PotatoSQLParser::K_CREATE);
    setState(374);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(373);
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
    setState(376);
    match(PotatoSQLParser::K_TABLE);
    setState(380);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(377);
      match(PotatoSQLParser::K_IF);
      setState(378);
      match(PotatoSQLParser::K_NOT);
      setState(379);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(385);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(382);
      database_name();
      setState(383);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(387);
    table_name();
    setState(411);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::OPEN_PAR: {
        setState(388);
        match(PotatoSQLParser::OPEN_PAR);
        setState(389);
        column_def();
        setState(394);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1 + 1) {
            setState(390);
            match(PotatoSQLParser::COMMA);
            setState(391);
            column_def(); 
          }
          setState(396);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        }
        setState(401);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(397);
          match(PotatoSQLParser::COMMA);
          setState(398);
          table_constraint();
          setState(403);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(404);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(407);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WITHOUT) {
          setState(405);
          match(PotatoSQLParser::K_WITHOUT);
          setState(406);
          match(PotatoSQLParser::IDENTIFIER);
        }
        break;
      }

      case PotatoSQLParser::K_AS: {
        setState(409);
        match(PotatoSQLParser::K_AS);
        setState(410);
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

//----------------- Create_trigger_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Create_trigger_stmtContext::Create_trigger_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_TRIGGER() {
  return getToken(PotatoSQLParser::K_TRIGGER, 0);
}

PotatoSQLParser::Trigger_nameContext* PotatoSQLParser::Create_trigger_stmtContext::trigger_name() {
  return getRuleContext<PotatoSQLParser::Trigger_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_ON() {
  return getToken(PotatoSQLParser::K_ON, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Create_trigger_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_BEGIN() {
  return getToken(PotatoSQLParser::K_BEGIN, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_END() {
  return getToken(PotatoSQLParser::K_END, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_DELETE() {
  return getToken(PotatoSQLParser::K_DELETE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_INSERT() {
  return getToken(PotatoSQLParser::K_INSERT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_UPDATE() {
  return getToken(PotatoSQLParser::K_UPDATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

std::vector<PotatoSQLParser::Database_nameContext *> PotatoSQLParser::Create_trigger_stmtContext::database_name() {
  return getRuleContexts<PotatoSQLParser::Database_nameContext>();
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Create_trigger_stmtContext::database_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_trigger_stmtContext::DOT() {
  return getTokens(PotatoSQLParser::DOT);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::DOT(size_t i) {
  return getToken(PotatoSQLParser::DOT, i);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_BEFORE() {
  return getToken(PotatoSQLParser::K_BEFORE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_AFTER() {
  return getToken(PotatoSQLParser::K_AFTER, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_INSTEAD() {
  return getToken(PotatoSQLParser::K_INSTEAD, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_trigger_stmtContext::K_OF() {
  return getTokens(PotatoSQLParser::K_OF);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_OF(size_t i) {
  return getToken(PotatoSQLParser::K_OF, i);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_FOR() {
  return getToken(PotatoSQLParser::K_FOR, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_EACH() {
  return getToken(PotatoSQLParser::K_EACH, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_ROW() {
  return getToken(PotatoSQLParser::K_ROW, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_WHEN() {
  return getToken(PotatoSQLParser::K_WHEN, 0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Create_trigger_stmtContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_trigger_stmtContext::SCOL() {
  return getTokens(PotatoSQLParser::SCOL);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::SCOL(size_t i) {
  return getToken(PotatoSQLParser::SCOL, i);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_TEMP() {
  return getToken(PotatoSQLParser::K_TEMP, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::K_TEMPORARY() {
  return getToken(PotatoSQLParser::K_TEMPORARY, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Create_trigger_stmtContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Create_trigger_stmtContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

std::vector<PotatoSQLParser::Update_stmtContext *> PotatoSQLParser::Create_trigger_stmtContext::update_stmt() {
  return getRuleContexts<PotatoSQLParser::Update_stmtContext>();
}

PotatoSQLParser::Update_stmtContext* PotatoSQLParser::Create_trigger_stmtContext::update_stmt(size_t i) {
  return getRuleContext<PotatoSQLParser::Update_stmtContext>(i);
}

std::vector<PotatoSQLParser::Insert_stmtContext *> PotatoSQLParser::Create_trigger_stmtContext::insert_stmt() {
  return getRuleContexts<PotatoSQLParser::Insert_stmtContext>();
}

PotatoSQLParser::Insert_stmtContext* PotatoSQLParser::Create_trigger_stmtContext::insert_stmt(size_t i) {
  return getRuleContext<PotatoSQLParser::Insert_stmtContext>(i);
}

std::vector<PotatoSQLParser::Delete_stmtContext *> PotatoSQLParser::Create_trigger_stmtContext::delete_stmt() {
  return getRuleContexts<PotatoSQLParser::Delete_stmtContext>();
}

PotatoSQLParser::Delete_stmtContext* PotatoSQLParser::Create_trigger_stmtContext::delete_stmt(size_t i) {
  return getRuleContext<PotatoSQLParser::Delete_stmtContext>(i);
}

std::vector<PotatoSQLParser::Select_stmtContext *> PotatoSQLParser::Create_trigger_stmtContext::select_stmt() {
  return getRuleContexts<PotatoSQLParser::Select_stmtContext>();
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Create_trigger_stmtContext::select_stmt(size_t i) {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_trigger_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Create_trigger_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Create_trigger_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCreate_trigger_stmt;
}

void PotatoSQLParser::Create_trigger_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_trigger_stmt(this);
}

void PotatoSQLParser::Create_trigger_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_trigger_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Create_trigger_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCreate_trigger_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Create_trigger_stmtContext* PotatoSQLParser::create_trigger_stmt() {
  Create_trigger_stmtContext *_localctx = _tracker.createInstance<Create_trigger_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, PotatoSQLParser::RuleCreate_trigger_stmt);
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
    setState(413);
    match(PotatoSQLParser::K_CREATE);
    setState(415);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(414);
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
    setState(417);
    match(PotatoSQLParser::K_TRIGGER);
    setState(421);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(418);
      match(PotatoSQLParser::K_IF);
      setState(419);
      match(PotatoSQLParser::K_NOT);
      setState(420);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(426);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(423);
      database_name();
      setState(424);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(428);
    trigger_name();
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_BEFORE: {
        setState(429);
        match(PotatoSQLParser::K_BEFORE);
        break;
      }

      case PotatoSQLParser::K_AFTER: {
        setState(430);
        match(PotatoSQLParser::K_AFTER);
        break;
      }

      case PotatoSQLParser::K_INSTEAD: {
        setState(431);
        match(PotatoSQLParser::K_INSTEAD);
        setState(432);
        match(PotatoSQLParser::K_OF);
        break;
      }

      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_UPDATE: {
        break;
      }

    default:
      break;
    }
    setState(449);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_DELETE: {
        setState(435);
        match(PotatoSQLParser::K_DELETE);
        break;
      }

      case PotatoSQLParser::K_INSERT: {
        setState(436);
        match(PotatoSQLParser::K_INSERT);
        break;
      }

      case PotatoSQLParser::K_UPDATE: {
        setState(437);
        match(PotatoSQLParser::K_UPDATE);
        setState(447);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_OF) {
          setState(438);
          match(PotatoSQLParser::K_OF);
          setState(439);
          column_name();
          setState(444);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(440);
            match(PotatoSQLParser::COMMA);
            setState(441);
            column_name();
            setState(446);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(451);
    match(PotatoSQLParser::K_ON);
    setState(455);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(452);
      database_name();
      setState(453);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(457);
    table_name();
    setState(461);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_FOR) {
      setState(458);
      match(PotatoSQLParser::K_FOR);
      setState(459);
      match(PotatoSQLParser::K_EACH);
      setState(460);
      match(PotatoSQLParser::K_ROW);
    }
    setState(465);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHEN) {
      setState(463);
      match(PotatoSQLParser::K_WHEN);
      setState(464);
      expr(0);
    }
    setState(467);
    match(PotatoSQLParser::K_BEGIN);
    setState(476); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(472);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(468);
        update_stmt();
        break;
      }

      case 2: {
        setState(469);
        insert_stmt();
        break;
      }

      case 3: {
        setState(470);
        delete_stmt();
        break;
      }

      case 4: {
        setState(471);
        select_stmt();
        break;
      }

      default:
        break;
      }
      setState(474);
      match(PotatoSQLParser::SCOL);
      setState(478); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_DELETE || ((((_la - 88) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 88)) & ((1ULL << (PotatoSQLParser::K_INSERT - 88))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 88))
      | (1ULL << (PotatoSQLParser::K_SELECT - 88))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 88))
      | (1ULL << (PotatoSQLParser::K_VALUES - 88))
      | (1ULL << (PotatoSQLParser::K_WITH - 88)))) != 0));
    setState(480);
    match(PotatoSQLParser::K_END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_view_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Create_view_stmtContext::Create_view_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_VIEW() {
  return getToken(PotatoSQLParser::K_VIEW, 0);
}

PotatoSQLParser::View_nameContext* PotatoSQLParser::Create_view_stmtContext::view_name() {
  return getRuleContext<PotatoSQLParser::View_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::Create_view_stmtContext::select_stmt() {
  return getRuleContext<PotatoSQLParser::Select_stmtContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Create_view_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_TEMP() {
  return getToken(PotatoSQLParser::K_TEMP, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_view_stmtContext::K_TEMPORARY() {
  return getToken(PotatoSQLParser::K_TEMPORARY, 0);
}


size_t PotatoSQLParser::Create_view_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCreate_view_stmt;
}

void PotatoSQLParser::Create_view_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_view_stmt(this);
}

void PotatoSQLParser::Create_view_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_view_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Create_view_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCreate_view_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Create_view_stmtContext* PotatoSQLParser::create_view_stmt() {
  Create_view_stmtContext *_localctx = _tracker.createInstance<Create_view_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, PotatoSQLParser::RuleCreate_view_stmt);
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
    setState(482);
    match(PotatoSQLParser::K_CREATE);
    setState(484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(483);
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
    setState(486);
    match(PotatoSQLParser::K_VIEW);
    setState(490);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(487);
      match(PotatoSQLParser::K_IF);
      setState(488);
      match(PotatoSQLParser::K_NOT);
      setState(489);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(495);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(492);
      database_name();
      setState(493);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(497);
    view_name();
    setState(498);
    match(PotatoSQLParser::K_AS);
    setState(499);
    select_stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Create_virtual_table_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Create_virtual_table_stmtContext::Create_virtual_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_VIRTUAL() {
  return getToken(PotatoSQLParser::K_VIRTUAL, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Create_virtual_table_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_USING() {
  return getToken(PotatoSQLParser::K_USING, 0);
}

PotatoSQLParser::Module_nameContext* PotatoSQLParser::Create_virtual_table_stmtContext::module_name() {
  return getRuleContext<PotatoSQLParser::Module_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Create_virtual_table_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Module_argumentContext *> PotatoSQLParser::Create_virtual_table_stmtContext::module_argument() {
  return getRuleContexts<PotatoSQLParser::Module_argumentContext>();
}

PotatoSQLParser::Module_argumentContext* PotatoSQLParser::Create_virtual_table_stmtContext::module_argument(size_t i) {
  return getRuleContext<PotatoSQLParser::Module_argumentContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Create_virtual_table_stmtContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Create_virtual_table_stmtContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Create_virtual_table_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleCreate_virtual_table_stmt;
}

void PotatoSQLParser::Create_virtual_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreate_virtual_table_stmt(this);
}

void PotatoSQLParser::Create_virtual_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreate_virtual_table_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Create_virtual_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCreate_virtual_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Create_virtual_table_stmtContext* PotatoSQLParser::create_virtual_table_stmt() {
  Create_virtual_table_stmtContext *_localctx = _tracker.createInstance<Create_virtual_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, PotatoSQLParser::RuleCreate_virtual_table_stmt);
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
    setState(501);
    match(PotatoSQLParser::K_CREATE);
    setState(502);
    match(PotatoSQLParser::K_VIRTUAL);
    setState(503);
    match(PotatoSQLParser::K_TABLE);
    setState(507);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      setState(504);
      match(PotatoSQLParser::K_IF);
      setState(505);
      match(PotatoSQLParser::K_NOT);
      setState(506);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(512);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(509);
      database_name();
      setState(510);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(514);
    table_name();
    setState(515);
    match(PotatoSQLParser::K_USING);
    setState(516);
    module_name();
    setState(528);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(517);
      match(PotatoSQLParser::OPEN_PAR);
      setState(518);
      module_argument();
      setState(523);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(519);
        match(PotatoSQLParser::COMMA);
        setState(520);
        module_argument();
        setState(525);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(526);
      match(PotatoSQLParser::CLOSE_PAR);
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

void PotatoSQLParser::Delete_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt(this);
}

void PotatoSQLParser::Delete_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Delete_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDelete_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Delete_stmtContext* PotatoSQLParser::delete_stmt() {
  Delete_stmtContext *_localctx = _tracker.createInstance<Delete_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, PotatoSQLParser::RuleDelete_stmt);
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
    setState(531);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(530);
      with_clause();
    }
    setState(533);
    match(PotatoSQLParser::K_DELETE);
    setState(534);
    match(PotatoSQLParser::K_FROM);
    setState(535);
    qualified_table_name();
    setState(538);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(536);
      match(PotatoSQLParser::K_WHERE);
      setState(537);
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

void PotatoSQLParser::Delete_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete_stmt_limited(this);
}

void PotatoSQLParser::Delete_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete_stmt_limited(this);
}


antlrcpp::Any PotatoSQLParser::Delete_stmt_limitedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDelete_stmt_limited(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Delete_stmt_limitedContext* PotatoSQLParser::delete_stmt_limited() {
  Delete_stmt_limitedContext *_localctx = _tracker.createInstance<Delete_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 32, PotatoSQLParser::RuleDelete_stmt_limited);
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
    setState(541);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(540);
      with_clause();
    }
    setState(543);
    match(PotatoSQLParser::K_DELETE);
    setState(544);
    match(PotatoSQLParser::K_FROM);
    setState(545);
    qualified_table_name();
    setState(548);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(546);
      match(PotatoSQLParser::K_WHERE);
      setState(547);
      expr(0);
    }
    setState(568);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(560);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(550);
        match(PotatoSQLParser::K_ORDER);
        setState(551);
        match(PotatoSQLParser::K_BY);
        setState(552);
        ordering_term();
        setState(557);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(553);
          match(PotatoSQLParser::COMMA);
          setState(554);
          ordering_term();
          setState(559);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(562);
      match(PotatoSQLParser::K_LIMIT);
      setState(563);
      expr(0);
      setState(566);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(564);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(565);
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

//----------------- Detach_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Detach_stmtContext::Detach_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Detach_stmtContext::K_DETACH() {
  return getToken(PotatoSQLParser::K_DETACH, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Detach_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Detach_stmtContext::K_DATABASE() {
  return getToken(PotatoSQLParser::K_DATABASE, 0);
}


size_t PotatoSQLParser::Detach_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDetach_stmt;
}

void PotatoSQLParser::Detach_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDetach_stmt(this);
}

void PotatoSQLParser::Detach_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDetach_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Detach_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDetach_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Detach_stmtContext* PotatoSQLParser::detach_stmt() {
  Detach_stmtContext *_localctx = _tracker.createInstance<Detach_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, PotatoSQLParser::RuleDetach_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    match(PotatoSQLParser::K_DETACH);
    setState(572);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(571);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(574);
    database_name();
   
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

void PotatoSQLParser::Drop_index_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_index_stmt(this);
}

void PotatoSQLParser::Drop_index_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_index_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Drop_index_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDrop_index_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Drop_index_stmtContext* PotatoSQLParser::drop_index_stmt() {
  Drop_index_stmtContext *_localctx = _tracker.createInstance<Drop_index_stmtContext>(_ctx, getState());
  enterRule(_localctx, 36, PotatoSQLParser::RuleDrop_index_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(576);
    match(PotatoSQLParser::K_DROP);
    setState(577);
    match(PotatoSQLParser::K_INDEX);
    setState(580);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(578);
      match(PotatoSQLParser::K_IF);
      setState(579);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(585);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(582);
      database_name();
      setState(583);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(587);
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

void PotatoSQLParser::Drop_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_table_stmt(this);
}

void PotatoSQLParser::Drop_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_table_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Drop_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDrop_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Drop_table_stmtContext* PotatoSQLParser::drop_table_stmt() {
  Drop_table_stmtContext *_localctx = _tracker.createInstance<Drop_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 38, PotatoSQLParser::RuleDrop_table_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(589);
    match(PotatoSQLParser::K_DROP);
    setState(590);
    match(PotatoSQLParser::K_TABLE);
    setState(593);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(591);
      match(PotatoSQLParser::K_IF);
      setState(592);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(598);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      setState(595);
      database_name();
      setState(596);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(600);
    table_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_trigger_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Drop_trigger_stmtContext::Drop_trigger_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Drop_trigger_stmtContext::K_DROP() {
  return getToken(PotatoSQLParser::K_DROP, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_trigger_stmtContext::K_TRIGGER() {
  return getToken(PotatoSQLParser::K_TRIGGER, 0);
}

PotatoSQLParser::Trigger_nameContext* PotatoSQLParser::Drop_trigger_stmtContext::trigger_name() {
  return getRuleContext<PotatoSQLParser::Trigger_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_trigger_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_trigger_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Drop_trigger_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_trigger_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Drop_trigger_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDrop_trigger_stmt;
}

void PotatoSQLParser::Drop_trigger_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_trigger_stmt(this);
}

void PotatoSQLParser::Drop_trigger_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_trigger_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Drop_trigger_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDrop_trigger_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Drop_trigger_stmtContext* PotatoSQLParser::drop_trigger_stmt() {
  Drop_trigger_stmtContext *_localctx = _tracker.createInstance<Drop_trigger_stmtContext>(_ctx, getState());
  enterRule(_localctx, 40, PotatoSQLParser::RuleDrop_trigger_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(PotatoSQLParser::K_DROP);
    setState(603);
    match(PotatoSQLParser::K_TRIGGER);
    setState(606);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      setState(604);
      match(PotatoSQLParser::K_IF);
      setState(605);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(611);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(608);
      database_name();
      setState(609);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(613);
    trigger_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Drop_view_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Drop_view_stmtContext::Drop_view_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Drop_view_stmtContext::K_DROP() {
  return getToken(PotatoSQLParser::K_DROP, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_view_stmtContext::K_VIEW() {
  return getToken(PotatoSQLParser::K_VIEW, 0);
}

PotatoSQLParser::View_nameContext* PotatoSQLParser::Drop_view_stmtContext::view_name() {
  return getRuleContext<PotatoSQLParser::View_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_view_stmtContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::Drop_view_stmtContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Drop_view_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Drop_view_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Drop_view_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDrop_view_stmt;
}

void PotatoSQLParser::Drop_view_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDrop_view_stmt(this);
}

void PotatoSQLParser::Drop_view_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDrop_view_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Drop_view_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDrop_view_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Drop_view_stmtContext* PotatoSQLParser::drop_view_stmt() {
  Drop_view_stmtContext *_localctx = _tracker.createInstance<Drop_view_stmtContext>(_ctx, getState());
  enterRule(_localctx, 42, PotatoSQLParser::RuleDrop_view_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(615);
    match(PotatoSQLParser::K_DROP);
    setState(616);
    match(PotatoSQLParser::K_VIEW);
    setState(619);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(617);
      match(PotatoSQLParser::K_IF);
      setState(618);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(624);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      setState(621);
      database_name();
      setState(622);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(626);
    view_name();
   
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

void PotatoSQLParser::Factored_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactored_select_stmt(this);
}

void PotatoSQLParser::Factored_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactored_select_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Factored_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitFactored_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Factored_select_stmtContext* PotatoSQLParser::factored_select_stmt() {
  Factored_select_stmtContext *_localctx = _tracker.createInstance<Factored_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 44, PotatoSQLParser::RuleFactored_select_stmt);
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
    setState(629);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(628);
      with_clause();
    }
    setState(631);
    select_core();
    setState(637);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(632);
      compound_operator();
      setState(633);
      select_core();
      setState(639);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(650);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(640);
      match(PotatoSQLParser::K_ORDER);
      setState(641);
      match(PotatoSQLParser::K_BY);
      setState(642);
      ordering_term();
      setState(647);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(643);
        match(PotatoSQLParser::COMMA);
        setState(644);
        ordering_term();
        setState(649);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(658);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(652);
      match(PotatoSQLParser::K_LIMIT);
      setState(653);
      expr(0);
      setState(656);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(654);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(655);
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

//----------------- Insert_prefixContext ------------------------------------------------------------------

PotatoSQLParser::Insert_prefixContext::Insert_prefixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_INSERT() {
  return getToken(PotatoSQLParser::K_INSERT, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::Insert_prefixContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}


size_t PotatoSQLParser::Insert_prefixContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_prefix;
}

void PotatoSQLParser::Insert_prefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_prefix(this);
}

void PotatoSQLParser::Insert_prefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_prefix(this);
}


antlrcpp::Any PotatoSQLParser::Insert_prefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitInsert_prefix(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Insert_prefixContext* PotatoSQLParser::insert_prefix() {
  Insert_prefixContext *_localctx = _tracker.createInstance<Insert_prefixContext>(_ctx, getState());
  enterRule(_localctx, 46, PotatoSQLParser::RuleInsert_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(677);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(660);
      match(PotatoSQLParser::K_INSERT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(661);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(662);
      match(PotatoSQLParser::K_INSERT);
      setState(663);
      match(PotatoSQLParser::K_OR);
      setState(664);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(665);
      match(PotatoSQLParser::K_INSERT);
      setState(666);
      match(PotatoSQLParser::K_OR);
      setState(667);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(668);
      match(PotatoSQLParser::K_INSERT);
      setState(669);
      match(PotatoSQLParser::K_OR);
      setState(670);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(671);
      match(PotatoSQLParser::K_INSERT);
      setState(672);
      match(PotatoSQLParser::K_OR);
      setState(673);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(674);
      match(PotatoSQLParser::K_INSERT);
      setState(675);
      match(PotatoSQLParser::K_OR);
      setState(676);
      match(PotatoSQLParser::K_IGNORE);
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

//----------------- Insert_tupleContext ------------------------------------------------------------------

PotatoSQLParser::Insert_tupleContext::Insert_tupleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Insert_tupleContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Insert_tupleContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Insert_tupleContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Insert_tupleContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_tupleContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Insert_tupleContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Insert_tupleContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_tuple;
}

void PotatoSQLParser::Insert_tupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_tuple(this);
}

void PotatoSQLParser::Insert_tupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_tuple(this);
}


antlrcpp::Any PotatoSQLParser::Insert_tupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitInsert_tuple(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Insert_tupleContext* PotatoSQLParser::insert_tuple() {
  Insert_tupleContext *_localctx = _tracker.createInstance<Insert_tupleContext>(_ctx, getState());
  enterRule(_localctx, 48, PotatoSQLParser::RuleInsert_tuple);
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
    setState(679);
    match(PotatoSQLParser::OPEN_PAR);
    setState(680);
    expr(0);
    setState(685);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(681);
      match(PotatoSQLParser::COMMA);
      setState(682);
      expr(0);
      setState(687);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(688);
    match(PotatoSQLParser::CLOSE_PAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Insert_tuplesContext ------------------------------------------------------------------

PotatoSQLParser::Insert_tuplesContext::Insert_tuplesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Insert_tupleContext *> PotatoSQLParser::Insert_tuplesContext::insert_tuple() {
  return getRuleContexts<PotatoSQLParser::Insert_tupleContext>();
}

PotatoSQLParser::Insert_tupleContext* PotatoSQLParser::Insert_tuplesContext::insert_tuple(size_t i) {
  return getRuleContext<PotatoSQLParser::Insert_tupleContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_tuplesContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Insert_tuplesContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Insert_tuplesContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_tuples;
}

void PotatoSQLParser::Insert_tuplesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_tuples(this);
}

void PotatoSQLParser::Insert_tuplesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_tuples(this);
}


antlrcpp::Any PotatoSQLParser::Insert_tuplesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitInsert_tuples(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Insert_tuplesContext* PotatoSQLParser::insert_tuples() {
  Insert_tuplesContext *_localctx = _tracker.createInstance<Insert_tuplesContext>(_ctx, getState());
  enterRule(_localctx, 50, PotatoSQLParser::RuleInsert_tuples);
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
    setState(690);
    insert_tuple();
    setState(695);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(691);
      match(PotatoSQLParser::COMMA);
      setState(692);
      insert_tuple();
      setState(697);
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

//----------------- Insert_columnsContext ------------------------------------------------------------------

PotatoSQLParser::Insert_columnsContext::Insert_columnsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Insert_columnsContext::OPEN_PAR() {
  return getToken(PotatoSQLParser::OPEN_PAR, 0);
}

std::vector<PotatoSQLParser::Column_nameContext *> PotatoSQLParser::Insert_columnsContext::column_name() {
  return getRuleContexts<PotatoSQLParser::Column_nameContext>();
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Insert_columnsContext::column_name(size_t i) {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Insert_columnsContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Insert_columnsContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Insert_columnsContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Insert_columnsContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_columns;
}

void PotatoSQLParser::Insert_columnsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_columns(this);
}

void PotatoSQLParser::Insert_columnsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_columns(this);
}


antlrcpp::Any PotatoSQLParser::Insert_columnsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitInsert_columns(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Insert_columnsContext* PotatoSQLParser::insert_columns() {
  Insert_columnsContext *_localctx = _tracker.createInstance<Insert_columnsContext>(_ctx, getState());
  enterRule(_localctx, 52, PotatoSQLParser::RuleInsert_columns);
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
    setState(698);
    match(PotatoSQLParser::OPEN_PAR);
    setState(699);
    column_name();
    setState(704);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(700);
      match(PotatoSQLParser::COMMA);
      setState(701);
      column_name();
      setState(706);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(707);
    match(PotatoSQLParser::CLOSE_PAR);
   
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

PotatoSQLParser::Insert_prefixContext* PotatoSQLParser::Insert_stmtContext::insert_prefix() {
  return getRuleContext<PotatoSQLParser::Insert_prefixContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_INTO() {
  return getToken(PotatoSQLParser::K_INTO, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Insert_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Insert_stmtContext::K_VALUES() {
  return getToken(PotatoSQLParser::K_VALUES, 0);
}

PotatoSQLParser::Insert_tuplesContext* PotatoSQLParser::Insert_stmtContext::insert_tuples() {
  return getRuleContext<PotatoSQLParser::Insert_tuplesContext>(0);
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

PotatoSQLParser::Insert_columnsContext* PotatoSQLParser::Insert_stmtContext::insert_columns() {
  return getRuleContext<PotatoSQLParser::Insert_columnsContext>(0);
}


size_t PotatoSQLParser::Insert_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleInsert_stmt;
}

void PotatoSQLParser::Insert_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsert_stmt(this);
}

void PotatoSQLParser::Insert_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsert_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Insert_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitInsert_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Insert_stmtContext* PotatoSQLParser::insert_stmt() {
  Insert_stmtContext *_localctx = _tracker.createInstance<Insert_stmtContext>(_ctx, getState());
  enterRule(_localctx, 54, PotatoSQLParser::RuleInsert_stmt);
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
    setState(710);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(709);
      with_clause();
    }
    setState(712);
    insert_prefix();
    setState(713);
    match(PotatoSQLParser::K_INTO);
    setState(717);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      setState(714);
      database_name();
      setState(715);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(719);
    table_name();
    setState(721);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(720);
      insert_columns();
    }
    setState(728);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      setState(723);
      match(PotatoSQLParser::K_VALUES);
      setState(724);
      insert_tuples();
      break;
    }

    case 2: {
      setState(725);
      select_stmt();
      break;
    }

    case 3: {
      setState(726);
      match(PotatoSQLParser::K_DEFAULT);
      setState(727);
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

void PotatoSQLParser::Pragma_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_stmt(this);
}

void PotatoSQLParser::Pragma_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Pragma_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitPragma_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Pragma_stmtContext* PotatoSQLParser::pragma_stmt() {
  Pragma_stmtContext *_localctx = _tracker.createInstance<Pragma_stmtContext>(_ctx, getState());
  enterRule(_localctx, 56, PotatoSQLParser::RulePragma_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(730);
    match(PotatoSQLParser::K_PRAGMA);
    setState(734);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      setState(731);
      database_name();
      setState(732);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(736);
    pragma_name();
    setState(743);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::ASSIGN: {
        setState(737);
        match(PotatoSQLParser::ASSIGN);
        setState(738);
        pragma_value();
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        setState(739);
        match(PotatoSQLParser::OPEN_PAR);
        setState(740);
        pragma_value();
        setState(741);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_ANALYZE:
      case PotatoSQLParser::K_ATTACH:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DETACH:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_EXPLAIN:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_REINDEX:
      case PotatoSQLParser::K_RELEASE:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_SAVEPOINT:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_VACUUM:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_WITH:
      case PotatoSQLParser::UNEXPECTED_CHAR: {
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

//----------------- Reindex_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Reindex_stmtContext::Reindex_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Reindex_stmtContext::K_REINDEX() {
  return getToken(PotatoSQLParser::K_REINDEX, 0);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::Reindex_stmtContext::collation_name() {
  return getRuleContext<PotatoSQLParser::Collation_nameContext>(0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Reindex_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::Reindex_stmtContext::index_name() {
  return getRuleContext<PotatoSQLParser::Index_nameContext>(0);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::Reindex_stmtContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Reindex_stmtContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
}


size_t PotatoSQLParser::Reindex_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleReindex_stmt;
}

void PotatoSQLParser::Reindex_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReindex_stmt(this);
}

void PotatoSQLParser::Reindex_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReindex_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Reindex_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitReindex_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Reindex_stmtContext* PotatoSQLParser::reindex_stmt() {
  Reindex_stmtContext *_localctx = _tracker.createInstance<Reindex_stmtContext>(_ctx, getState());
  enterRule(_localctx, 58, PotatoSQLParser::RuleReindex_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(745);
    match(PotatoSQLParser::K_REINDEX);
    setState(756);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      setState(746);
      collation_name();
      break;
    }

    case 2: {
      setState(750);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
      case 1: {
        setState(747);
        database_name();
        setState(748);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(754);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
      case 1: {
        setState(752);
        table_name();
        break;
      }

      case 2: {
        setState(753);
        index_name();
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

//----------------- Release_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Release_stmtContext::Release_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Release_stmtContext::K_RELEASE() {
  return getToken(PotatoSQLParser::K_RELEASE, 0);
}

PotatoSQLParser::Savepoint_nameContext* PotatoSQLParser::Release_stmtContext::savepoint_name() {
  return getRuleContext<PotatoSQLParser::Savepoint_nameContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Release_stmtContext::K_SAVEPOINT() {
  return getToken(PotatoSQLParser::K_SAVEPOINT, 0);
}


size_t PotatoSQLParser::Release_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleRelease_stmt;
}

void PotatoSQLParser::Release_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelease_stmt(this);
}

void PotatoSQLParser::Release_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelease_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Release_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitRelease_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Release_stmtContext* PotatoSQLParser::release_stmt() {
  Release_stmtContext *_localctx = _tracker.createInstance<Release_stmtContext>(_ctx, getState());
  enterRule(_localctx, 60, PotatoSQLParser::RuleRelease_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(758);
    match(PotatoSQLParser::K_RELEASE);
    setState(760);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(759);
      match(PotatoSQLParser::K_SAVEPOINT);
      break;
    }

    default:
      break;
    }
    setState(762);
    savepoint_name();
   
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

void PotatoSQLParser::Rollback_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRollback_stmt(this);
}

void PotatoSQLParser::Rollback_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRollback_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Rollback_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitRollback_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Rollback_stmtContext* PotatoSQLParser::rollback_stmt() {
  Rollback_stmtContext *_localctx = _tracker.createInstance<Rollback_stmtContext>(_ctx, getState());
  enterRule(_localctx, 62, PotatoSQLParser::RuleRollback_stmt);
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
    setState(764);
    match(PotatoSQLParser::K_ROLLBACK);
    setState(769);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(765);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(767);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
      case 1: {
        setState(766);
        transaction_name();
        break;
      }

      default:
        break;
      }
    }
    setState(776);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TO) {
      setState(771);
      match(PotatoSQLParser::K_TO);
      setState(773);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
      case 1: {
        setState(772);
        match(PotatoSQLParser::K_SAVEPOINT);
        break;
      }

      default:
        break;
      }
      setState(775);
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

//----------------- Savepoint_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Savepoint_stmtContext::Savepoint_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Savepoint_stmtContext::K_SAVEPOINT() {
  return getToken(PotatoSQLParser::K_SAVEPOINT, 0);
}

PotatoSQLParser::Savepoint_nameContext* PotatoSQLParser::Savepoint_stmtContext::savepoint_name() {
  return getRuleContext<PotatoSQLParser::Savepoint_nameContext>(0);
}


size_t PotatoSQLParser::Savepoint_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleSavepoint_stmt;
}

void PotatoSQLParser::Savepoint_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_stmt(this);
}

void PotatoSQLParser::Savepoint_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Savepoint_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSavepoint_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Savepoint_stmtContext* PotatoSQLParser::savepoint_stmt() {
  Savepoint_stmtContext *_localctx = _tracker.createInstance<Savepoint_stmtContext>(_ctx, getState());
  enterRule(_localctx, 64, PotatoSQLParser::RuleSavepoint_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(778);
    match(PotatoSQLParser::K_SAVEPOINT);
    setState(779);
    savepoint_name();
   
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

void PotatoSQLParser::Simple_select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_select_stmt(this);
}

void PotatoSQLParser::Simple_select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_select_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Simple_select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSimple_select_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Simple_select_stmtContext* PotatoSQLParser::simple_select_stmt() {
  Simple_select_stmtContext *_localctx = _tracker.createInstance<Simple_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 66, PotatoSQLParser::RuleSimple_select_stmt);
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
    setState(782);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(781);
      with_clause();
    }
    setState(784);
    select_core();
    setState(795);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(785);
      match(PotatoSQLParser::K_ORDER);
      setState(786);
      match(PotatoSQLParser::K_BY);
      setState(787);
      ordering_term();
      setState(792);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(788);
        match(PotatoSQLParser::COMMA);
        setState(789);
        ordering_term();
        setState(794);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(803);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(797);
      match(PotatoSQLParser::K_LIMIT);
      setState(798);
      expr(0);
      setState(801);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(799);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(800);
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

void PotatoSQLParser::Select_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_stmt(this);
}

void PotatoSQLParser::Select_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Select_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSelect_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Select_stmtContext* PotatoSQLParser::select_stmt() {
  Select_stmtContext *_localctx = _tracker.createInstance<Select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 68, PotatoSQLParser::RuleSelect_stmt);
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
    setState(806);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(805);
      with_clause();
    }
    setState(808);
    select_or_values();
    setState(814);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(809);
      compound_operator();
      setState(810);
      select_or_values();
      setState(816);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(827);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(817);
      match(PotatoSQLParser::K_ORDER);
      setState(818);
      match(PotatoSQLParser::K_BY);
      setState(819);
      ordering_term();
      setState(824);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(820);
        match(PotatoSQLParser::COMMA);
        setState(821);
        ordering_term();
        setState(826);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(835);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(829);
      match(PotatoSQLParser::K_LIMIT);
      setState(830);
      expr(0);
      setState(833);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(831);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(832);
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

void PotatoSQLParser::Select_or_valuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_or_values(this);
}

void PotatoSQLParser::Select_or_valuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_or_values(this);
}


antlrcpp::Any PotatoSQLParser::Select_or_valuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSelect_or_values(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Select_or_valuesContext* PotatoSQLParser::select_or_values() {
  Select_or_valuesContext *_localctx = _tracker.createInstance<Select_or_valuesContext>(_ctx, getState());
  enterRule(_localctx, 70, PotatoSQLParser::RuleSelect_or_values);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(911);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(837);
        match(PotatoSQLParser::K_SELECT);
        setState(839);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
        case 1: {
          setState(838);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ALL

          || _la == PotatoSQLParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        }
        setState(841);
        result_column();
        setState(846);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(842);
          match(PotatoSQLParser::COMMA);
          setState(843);
          result_column();
          setState(848);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(861);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(849);
          match(PotatoSQLParser::K_FROM);
          setState(859);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
          case 1: {
            setState(850);
            table_or_subquery();
            setState(855);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(851);
              match(PotatoSQLParser::COMMA);
              setState(852);
              table_or_subquery();
              setState(857);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(858);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(865);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(863);
          match(PotatoSQLParser::K_WHERE);
          setState(864);
          expr(0);
        }
        setState(881);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(867);
          match(PotatoSQLParser::K_GROUP);
          setState(868);
          match(PotatoSQLParser::K_BY);
          setState(869);
          expr(0);
          setState(874);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(870);
            match(PotatoSQLParser::COMMA);
            setState(871);
            expr(0);
            setState(876);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(879);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(877);
            match(PotatoSQLParser::K_HAVING);
            setState(878);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(883);
        match(PotatoSQLParser::K_VALUES);
        setState(884);
        match(PotatoSQLParser::OPEN_PAR);
        setState(885);
        expr(0);
        setState(890);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(886);
          match(PotatoSQLParser::COMMA);
          setState(887);
          expr(0);
          setState(892);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(893);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(908);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(894);
          match(PotatoSQLParser::COMMA);
          setState(895);
          match(PotatoSQLParser::OPEN_PAR);
          setState(896);
          expr(0);
          setState(901);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(897);
            match(PotatoSQLParser::COMMA);
            setState(898);
            expr(0);
            setState(903);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(904);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(910);
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

void PotatoSQLParser::Update_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt(this);
}

void PotatoSQLParser::Update_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Update_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitUpdate_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Update_stmtContext* PotatoSQLParser::update_stmt() {
  Update_stmtContext *_localctx = _tracker.createInstance<Update_stmtContext>(_ctx, getState());
  enterRule(_localctx, 72, PotatoSQLParser::RuleUpdate_stmt);
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
    setState(914);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(913);
      with_clause();
    }
    setState(916);
    match(PotatoSQLParser::K_UPDATE);
    setState(927);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      setState(917);
      match(PotatoSQLParser::K_OR);
      setState(918);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(919);
      match(PotatoSQLParser::K_OR);
      setState(920);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(921);
      match(PotatoSQLParser::K_OR);
      setState(922);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(923);
      match(PotatoSQLParser::K_OR);
      setState(924);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(925);
      match(PotatoSQLParser::K_OR);
      setState(926);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(929);
    qualified_table_name();
    setState(930);
    match(PotatoSQLParser::K_SET);
    setState(931);
    column_name();
    setState(932);
    match(PotatoSQLParser::ASSIGN);
    setState(933);
    expr(0);
    setState(941);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(934);
      match(PotatoSQLParser::COMMA);
      setState(935);
      column_name();
      setState(936);
      match(PotatoSQLParser::ASSIGN);
      setState(937);
      expr(0);
      setState(943);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(946);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(944);
      match(PotatoSQLParser::K_WHERE);
      setState(945);
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

void PotatoSQLParser::Update_stmt_limitedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_stmt_limited(this);
}

void PotatoSQLParser::Update_stmt_limitedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_stmt_limited(this);
}


antlrcpp::Any PotatoSQLParser::Update_stmt_limitedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitUpdate_stmt_limited(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Update_stmt_limitedContext* PotatoSQLParser::update_stmt_limited() {
  Update_stmt_limitedContext *_localctx = _tracker.createInstance<Update_stmt_limitedContext>(_ctx, getState());
  enterRule(_localctx, 74, PotatoSQLParser::RuleUpdate_stmt_limited);
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
    setState(949);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(948);
      with_clause();
    }
    setState(951);
    match(PotatoSQLParser::K_UPDATE);
    setState(962);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      setState(952);
      match(PotatoSQLParser::K_OR);
      setState(953);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(954);
      match(PotatoSQLParser::K_OR);
      setState(955);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(956);
      match(PotatoSQLParser::K_OR);
      setState(957);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(958);
      match(PotatoSQLParser::K_OR);
      setState(959);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(960);
      match(PotatoSQLParser::K_OR);
      setState(961);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(964);
    qualified_table_name();
    setState(965);
    match(PotatoSQLParser::K_SET);
    setState(966);
    column_name();
    setState(967);
    match(PotatoSQLParser::ASSIGN);
    setState(968);
    expr(0);
    setState(976);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(969);
      match(PotatoSQLParser::COMMA);
      setState(970);
      column_name();
      setState(971);
      match(PotatoSQLParser::ASSIGN);
      setState(972);
      expr(0);
      setState(978);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(981);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(979);
      match(PotatoSQLParser::K_WHERE);
      setState(980);
      expr(0);
    }
    setState(1001);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(993);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(983);
        match(PotatoSQLParser::K_ORDER);
        setState(984);
        match(PotatoSQLParser::K_BY);
        setState(985);
        ordering_term();
        setState(990);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(986);
          match(PotatoSQLParser::COMMA);
          setState(987);
          ordering_term();
          setState(992);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(995);
      match(PotatoSQLParser::K_LIMIT);
      setState(996);
      expr(0);
      setState(999);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(997);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(998);
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

//----------------- Vacuum_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Vacuum_stmtContext::Vacuum_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Vacuum_stmtContext::K_VACUUM() {
  return getToken(PotatoSQLParser::K_VACUUM, 0);
}


size_t PotatoSQLParser::Vacuum_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleVacuum_stmt;
}

void PotatoSQLParser::Vacuum_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVacuum_stmt(this);
}

void PotatoSQLParser::Vacuum_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVacuum_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Vacuum_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitVacuum_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Vacuum_stmtContext* PotatoSQLParser::vacuum_stmt() {
  Vacuum_stmtContext *_localctx = _tracker.createInstance<Vacuum_stmtContext>(_ctx, getState());
  enterRule(_localctx, 76, PotatoSQLParser::RuleVacuum_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1003);
    match(PotatoSQLParser::K_VACUUM);
   
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

void PotatoSQLParser::Column_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_def(this);
}

void PotatoSQLParser::Column_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_def(this);
}


antlrcpp::Any PotatoSQLParser::Column_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitColumn_def(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Column_defContext* PotatoSQLParser::column_def() {
  Column_defContext *_localctx = _tracker.createInstance<Column_defContext>(_ctx, getState());
  enterRule(_localctx, 78, PotatoSQLParser::RuleColumn_def);
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
    setState(1005);
    column_name();
    setState(1007);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      setState(1006);
      type_name();
      break;
    }

    default:
      break;
    }
    setState(1012);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_CHECK)
      | (1ULL << PotatoSQLParser::K_COLLATE)
      | (1ULL << PotatoSQLParser::K_CONSTRAINT)
      | (1ULL << PotatoSQLParser::K_DEFAULT))) != 0) || ((((_la - 102) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 102)) & ((1ULL << (PotatoSQLParser::K_NOT - 102))
      | (1ULL << (PotatoSQLParser::K_NULL - 102))
      | (1ULL << (PotatoSQLParser::K_PRIMARY - 102))
      | (1ULL << (PotatoSQLParser::K_REFERENCES - 102))
      | (1ULL << (PotatoSQLParser::K_UNIQUE - 102)))) != 0)) {
      setState(1009);
      column_constraint();
      setState(1014);
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

void PotatoSQLParser::Type_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_name(this);
}

void PotatoSQLParser::Type_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_name(this);
}


antlrcpp::Any PotatoSQLParser::Type_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitType_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Type_nameContext* PotatoSQLParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 80, PotatoSQLParser::RuleType_name);

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
    setState(1016); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(1015);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1018); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx);
    } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(1030);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      setState(1020);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1021);
      signed_number();
      setState(1022);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(1024);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1025);
      signed_number();
      setState(1026);
      match(PotatoSQLParser::COMMA);
      setState(1027);
      signed_number();
      setState(1028);
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

void PotatoSQLParser::Column_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_constraint(this);
}

void PotatoSQLParser::Column_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_constraint(this);
}


antlrcpp::Any PotatoSQLParser::Column_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitColumn_constraint(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Column_constraintContext* PotatoSQLParser::column_constraint() {
  Column_constraintContext *_localctx = _tracker.createInstance<Column_constraintContext>(_ctx, getState());
  enterRule(_localctx, 82, PotatoSQLParser::RuleColumn_constraint);
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
    setState(1034);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1032);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1033);
      name();
    }
    setState(1069);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY: {
        setState(1036);
        match(PotatoSQLParser::K_PRIMARY);
        setState(1037);
        match(PotatoSQLParser::K_KEY);
        setState(1039);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ASC

        || _la == PotatoSQLParser::K_DESC) {
          setState(1038);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ASC

          || _la == PotatoSQLParser::K_DESC)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(1041);
        conflict_clause();
        setState(1043);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AUTOINCREMENT) {
          setState(1042);
          match(PotatoSQLParser::K_AUTOINCREMENT);
        }
        break;
      }

      case PotatoSQLParser::K_NOT:
      case PotatoSQLParser::K_NULL: {
        setState(1046);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(1045);
          match(PotatoSQLParser::K_NOT);
        }
        setState(1048);
        match(PotatoSQLParser::K_NULL);
        setState(1049);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_UNIQUE: {
        setState(1050);
        match(PotatoSQLParser::K_UNIQUE);
        setState(1051);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1052);
        match(PotatoSQLParser::K_CHECK);
        setState(1053);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1054);
        expr(0);
        setState(1055);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_DEFAULT: {
        setState(1057);
        match(PotatoSQLParser::K_DEFAULT);
        setState(1064);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
        case 1: {
          setState(1058);
          signed_number();
          break;
        }

        case 2: {
          setState(1059);
          literal_value();
          break;
        }

        case 3: {
          setState(1060);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1061);
          expr(0);
          setState(1062);
          match(PotatoSQLParser::CLOSE_PAR);
          break;
        }

        default:
          break;
        }
        break;
      }

      case PotatoSQLParser::K_COLLATE: {
        setState(1066);
        match(PotatoSQLParser::K_COLLATE);
        setState(1067);
        collation_name();
        break;
      }

      case PotatoSQLParser::K_REFERENCES: {
        setState(1068);
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

void PotatoSQLParser::Conflict_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConflict_clause(this);
}

void PotatoSQLParser::Conflict_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConflict_clause(this);
}


antlrcpp::Any PotatoSQLParser::Conflict_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitConflict_clause(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Conflict_clauseContext* PotatoSQLParser::conflict_clause() {
  Conflict_clauseContext *_localctx = _tracker.createInstance<Conflict_clauseContext>(_ctx, getState());
  enterRule(_localctx, 84, PotatoSQLParser::RuleConflict_clause);
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
    setState(1074);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ON) {
      setState(1071);
      match(PotatoSQLParser::K_ON);
      setState(1072);
      match(PotatoSQLParser::K_CONFLICT);
      setState(1073);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ABORT || ((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & ((1ULL << (PotatoSQLParser::K_FAIL - 72))
        | (1ULL << (PotatoSQLParser::K_IGNORE - 72))
        | (1ULL << (PotatoSQLParser::K_REPLACE - 72))
        | (1ULL << (PotatoSQLParser::K_ROLLBACK - 72)))) != 0))) {
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

void PotatoSQLParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void PotatoSQLParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any PotatoSQLParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
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
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, PotatoSQLParser::RuleExpr, precedence);

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
    setState(1152);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
    case 1: {
      setState(1077);
      literal_value();
      break;
    }

    case 2: {
      setState(1078);
      match(PotatoSQLParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(1087);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 147, _ctx)) {
      case 1: {
        setState(1082);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
        case 1: {
          setState(1079);
          database_name();
          setState(1080);
          match(PotatoSQLParser::DOT);
          break;
        }

        default:
          break;
        }
        setState(1084);
        table_name();
        setState(1085);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1089);
      column_name();
      break;
    }

    case 4: {
      setState(1090);
      unary_operator();
      setState(1091);
      expr(21);
      break;
    }

    case 5: {
      setState(1093);
      function_name();
      setState(1094);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1107);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::OPEN_PAR:
        case PotatoSQLParser::PLUS:
        case PotatoSQLParser::MINUS:
        case PotatoSQLParser::TILDE:
        case PotatoSQLParser::K_ABORT:
        case PotatoSQLParser::K_ACTION:
        case PotatoSQLParser::K_ADD:
        case PotatoSQLParser::K_AFTER:
        case PotatoSQLParser::K_ALL:
        case PotatoSQLParser::K_ALTER:
        case PotatoSQLParser::K_ANALYZE:
        case PotatoSQLParser::K_AND:
        case PotatoSQLParser::K_AS:
        case PotatoSQLParser::K_ASC:
        case PotatoSQLParser::K_ATTACH:
        case PotatoSQLParser::K_AUTOINCREMENT:
        case PotatoSQLParser::K_BEFORE:
        case PotatoSQLParser::K_BEGIN:
        case PotatoSQLParser::K_BETWEEN:
        case PotatoSQLParser::K_BY:
        case PotatoSQLParser::K_CASCADE:
        case PotatoSQLParser::K_CASE:
        case PotatoSQLParser::K_CAST:
        case PotatoSQLParser::K_CHECK:
        case PotatoSQLParser::K_COLLATE:
        case PotatoSQLParser::K_COLUMN:
        case PotatoSQLParser::K_COMMIT:
        case PotatoSQLParser::K_CONFLICT:
        case PotatoSQLParser::K_CONSTRAINT:
        case PotatoSQLParser::K_CREATE:
        case PotatoSQLParser::K_CROSS:
        case PotatoSQLParser::K_CURRENT_DATE:
        case PotatoSQLParser::K_CURRENT_TIME:
        case PotatoSQLParser::K_CURRENT_TIMESTAMP:
        case PotatoSQLParser::K_DATABASE:
        case PotatoSQLParser::K_DEFAULT:
        case PotatoSQLParser::K_DEFERRABLE:
        case PotatoSQLParser::K_DEFERRED:
        case PotatoSQLParser::K_DELETE:
        case PotatoSQLParser::K_DESC:
        case PotatoSQLParser::K_DETACH:
        case PotatoSQLParser::K_DISTINCT:
        case PotatoSQLParser::K_DROP:
        case PotatoSQLParser::K_EACH:
        case PotatoSQLParser::K_ELSE:
        case PotatoSQLParser::K_END:
        case PotatoSQLParser::K_ESCAPE:
        case PotatoSQLParser::K_EXCEPT:
        case PotatoSQLParser::K_EXCLUSIVE:
        case PotatoSQLParser::K_EXISTS:
        case PotatoSQLParser::K_EXPLAIN:
        case PotatoSQLParser::K_FAIL:
        case PotatoSQLParser::K_FOR:
        case PotatoSQLParser::K_FOREIGN:
        case PotatoSQLParser::K_FROM:
        case PotatoSQLParser::K_FULL:
        case PotatoSQLParser::K_GLOB:
        case PotatoSQLParser::K_GROUP:
        case PotatoSQLParser::K_HAVING:
        case PotatoSQLParser::K_IF:
        case PotatoSQLParser::K_IGNORE:
        case PotatoSQLParser::K_IMMEDIATE:
        case PotatoSQLParser::K_IN:
        case PotatoSQLParser::K_INDEX:
        case PotatoSQLParser::K_INDEXED:
        case PotatoSQLParser::K_INITIALLY:
        case PotatoSQLParser::K_INNER:
        case PotatoSQLParser::K_INSERT:
        case PotatoSQLParser::K_INSTEAD:
        case PotatoSQLParser::K_INTERSECT:
        case PotatoSQLParser::K_INTO:
        case PotatoSQLParser::K_IS:
        case PotatoSQLParser::K_ISNULL:
        case PotatoSQLParser::K_JOIN:
        case PotatoSQLParser::K_KEY:
        case PotatoSQLParser::K_LEFT:
        case PotatoSQLParser::K_LIKE:
        case PotatoSQLParser::K_LIMIT:
        case PotatoSQLParser::K_MATCH:
        case PotatoSQLParser::K_NATURAL:
        case PotatoSQLParser::K_NO:
        case PotatoSQLParser::K_NOT:
        case PotatoSQLParser::K_NOTNULL:
        case PotatoSQLParser::K_NULL:
        case PotatoSQLParser::K_OF:
        case PotatoSQLParser::K_OFFSET:
        case PotatoSQLParser::K_ON:
        case PotatoSQLParser::K_OR:
        case PotatoSQLParser::K_ORDER:
        case PotatoSQLParser::K_OUTER:
        case PotatoSQLParser::K_PLAN:
        case PotatoSQLParser::K_PRAGMA:
        case PotatoSQLParser::K_PRIMARY:
        case PotatoSQLParser::K_QUERY:
        case PotatoSQLParser::K_RAISE:
        case PotatoSQLParser::K_RECURSIVE:
        case PotatoSQLParser::K_REFERENCES:
        case PotatoSQLParser::K_REGEXP:
        case PotatoSQLParser::K_REINDEX:
        case PotatoSQLParser::K_RELEASE:
        case PotatoSQLParser::K_RENAME:
        case PotatoSQLParser::K_REPLACE:
        case PotatoSQLParser::K_RESTRICT:
        case PotatoSQLParser::K_RIGHT:
        case PotatoSQLParser::K_ROLLBACK:
        case PotatoSQLParser::K_ROW:
        case PotatoSQLParser::K_SAVEPOINT:
        case PotatoSQLParser::K_SELECT:
        case PotatoSQLParser::K_SET:
        case PotatoSQLParser::K_TABLE:
        case PotatoSQLParser::K_TEMP:
        case PotatoSQLParser::K_TEMPORARY:
        case PotatoSQLParser::K_THEN:
        case PotatoSQLParser::K_TO:
        case PotatoSQLParser::K_TRANSACTION:
        case PotatoSQLParser::K_TRIGGER:
        case PotatoSQLParser::K_UNION:
        case PotatoSQLParser::K_UNIQUE:
        case PotatoSQLParser::K_UPDATE:
        case PotatoSQLParser::K_USING:
        case PotatoSQLParser::K_VACUUM:
        case PotatoSQLParser::K_VALUES:
        case PotatoSQLParser::K_VIEW:
        case PotatoSQLParser::K_VIRTUAL:
        case PotatoSQLParser::K_WHEN:
        case PotatoSQLParser::K_WHERE:
        case PotatoSQLParser::K_WITH:
        case PotatoSQLParser::K_WITHOUT:
        case PotatoSQLParser::IDENTIFIER:
        case PotatoSQLParser::NUMERIC_LITERAL:
        case PotatoSQLParser::BIND_PARAMETER:
        case PotatoSQLParser::STRING_LITERAL:
        case PotatoSQLParser::BLOB_LITERAL: {
          setState(1096);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
          case 1: {
            setState(1095);
            match(PotatoSQLParser::K_DISTINCT);
            break;
          }

          default:
            break;
          }
          setState(1098);
          expr(0);
          setState(1103);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1099);
            match(PotatoSQLParser::COMMA);
            setState(1100);
            expr(0);
            setState(1105);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case PotatoSQLParser::STAR: {
          setState(1106);
          match(PotatoSQLParser::STAR);
          break;
        }

        case PotatoSQLParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(1109);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 6: {
      setState(1111);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1112);
      expr(0);
      setState(1113);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(1115);
      match(PotatoSQLParser::K_CAST);
      setState(1116);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1117);
      expr(0);
      setState(1118);
      match(PotatoSQLParser::K_AS);
      setState(1119);
      type_name();
      setState(1120);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 8: {
      setState(1126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_EXISTS

      || _la == PotatoSQLParser::K_NOT) {
        setState(1123);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(1122);
          match(PotatoSQLParser::K_NOT);
        }
        setState(1125);
        match(PotatoSQLParser::K_EXISTS);
      }
      setState(1128);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1129);
      select_stmt();
      setState(1130);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 9: {
      setState(1132);
      match(PotatoSQLParser::K_CASE);
      setState(1134);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx)) {
      case 1: {
        setState(1133);
        expr(0);
        break;
      }

      default:
        break;
      }
      setState(1141); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1136);
        match(PotatoSQLParser::K_WHEN);
        setState(1137);
        expr(0);
        setState(1138);
        match(PotatoSQLParser::K_THEN);
        setState(1139);
        expr(0);
        setState(1143); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == PotatoSQLParser::K_WHEN);
      setState(1147);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ELSE) {
        setState(1145);
        match(PotatoSQLParser::K_ELSE);
        setState(1146);
        expr(0);
      }
      setState(1149);
      match(PotatoSQLParser::K_END);
      break;
    }

    case 10: {
      setState(1151);
      raise_function();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(1241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1239);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1154);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(1155);
          match(PotatoSQLParser::PIPE2);
          setState(1156);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1157);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(1158);
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
          setState(1159);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1160);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(1161);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::PLUS

          || _la == PotatoSQLParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1162);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1163);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(1164);
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
          setState(1165);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1166);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(1167);
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
          setState(1168);
          expr(17);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1169);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(1170);
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
          setState(1171);
          expr(16);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1172);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1173);
          match(PotatoSQLParser::K_AND);
          setState(1174);
          expr(14);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1175);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(1176);
          match(PotatoSQLParser::K_OR);
          setState(1177);
          expr(13);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1178);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1179);
          match(PotatoSQLParser::K_IS);
          setState(1181);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
          case 1: {
            setState(1180);
            match(PotatoSQLParser::K_NOT);
            break;
          }

          default:
            break;
          }
          setState(1183);
          expr(6);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1184);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1186);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1185);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1188);
          match(PotatoSQLParser::K_BETWEEN);
          setState(1189);
          expr(0);
          setState(1190);
          match(PotatoSQLParser::K_AND);
          setState(1191);
          expr(5);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1193);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(1195);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1194);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1197);
          match(PotatoSQLParser::K_IN);
          setState(1217);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
          case 1: {
            setState(1198);
            match(PotatoSQLParser::OPEN_PAR);
            setState(1208);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx)) {
            case 1: {
              setState(1199);
              select_stmt();
              break;
            }

            case 2: {
              setState(1200);
              expr(0);
              setState(1205);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == PotatoSQLParser::COMMA) {
                setState(1201);
                match(PotatoSQLParser::COMMA);
                setState(1202);
                expr(0);
                setState(1207);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

            default:
              break;
            }
            setState(1210);
            match(PotatoSQLParser::CLOSE_PAR);
            break;
          }

          case 2: {
            setState(1214);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx)) {
            case 1: {
              setState(1211);
              database_name();
              setState(1212);
              match(PotatoSQLParser::DOT);
              break;
            }

            default:
              break;
            }
            setState(1216);
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
          setState(1219);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(1220);
          match(PotatoSQLParser::K_COLLATE);
          setState(1221);
          collation_name();
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1222);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1224);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1223);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1226);
          _la = _input->LA(1);
          if (!(((((_la - 77) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 77)) & ((1ULL << (PotatoSQLParser::K_GLOB - 77))
            | (1ULL << (PotatoSQLParser::K_LIKE - 77))
            | (1ULL << (PotatoSQLParser::K_MATCH - 77))
            | (1ULL << (PotatoSQLParser::K_REGEXP - 77)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1227);
          expr(0);
          setState(1230);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
          case 1: {
            setState(1228);
            match(PotatoSQLParser::K_ESCAPE);
            setState(1229);
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
          setState(1232);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1237);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case PotatoSQLParser::K_ISNULL: {
              setState(1233);
              match(PotatoSQLParser::K_ISNULL);
              break;
            }

            case PotatoSQLParser::K_NOTNULL: {
              setState(1234);
              match(PotatoSQLParser::K_NOTNULL);
              break;
            }

            case PotatoSQLParser::K_NOT: {
              setState(1235);
              match(PotatoSQLParser::K_NOT);
              setState(1236);
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
      setState(1243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    }
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

void PotatoSQLParser::Foreign_key_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_key_clause(this);
}

void PotatoSQLParser::Foreign_key_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_key_clause(this);
}


antlrcpp::Any PotatoSQLParser::Foreign_key_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitForeign_key_clause(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Foreign_key_clauseContext* PotatoSQLParser::foreign_key_clause() {
  Foreign_key_clauseContext *_localctx = _tracker.createInstance<Foreign_key_clauseContext>(_ctx, getState());
  enterRule(_localctx, 88, PotatoSQLParser::RuleForeign_key_clause);
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
    setState(1244);
    match(PotatoSQLParser::K_REFERENCES);
    setState(1245);
    foreign_table();
    setState(1257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1246);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1247);
      column_name();
      setState(1252);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1248);
        match(PotatoSQLParser::COMMA);
        setState(1249);
        column_name();
        setState(1254);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1255);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1277);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_MATCH

    || _la == PotatoSQLParser::K_ON) {
      setState(1273);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_ON: {
          setState(1259);
          match(PotatoSQLParser::K_ON);
          setState(1260);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_DELETE || _la == PotatoSQLParser::K_UPDATE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1269);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx)) {
          case 1: {
            setState(1261);
            match(PotatoSQLParser::K_SET);
            setState(1262);
            match(PotatoSQLParser::K_NULL);
            break;
          }

          case 2: {
            setState(1263);
            match(PotatoSQLParser::K_SET);
            setState(1264);
            match(PotatoSQLParser::K_DEFAULT);
            break;
          }

          case 3: {
            setState(1265);
            match(PotatoSQLParser::K_CASCADE);
            break;
          }

          case 4: {
            setState(1266);
            match(PotatoSQLParser::K_RESTRICT);
            break;
          }

          case 5: {
            setState(1267);
            match(PotatoSQLParser::K_NO);
            setState(1268);
            match(PotatoSQLParser::K_ACTION);
            break;
          }

          default:
            break;
          }
          break;
        }

        case PotatoSQLParser::K_MATCH: {
          setState(1271);
          match(PotatoSQLParser::K_MATCH);
          setState(1272);
          name();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1279);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1290);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 176, _ctx)) {
    case 1: {
      setState(1281);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_NOT) {
        setState(1280);
        match(PotatoSQLParser::K_NOT);
      }
      setState(1283);
      match(PotatoSQLParser::K_DEFERRABLE);
      setState(1288);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 175, _ctx)) {
      case 1: {
        setState(1284);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1285);
        match(PotatoSQLParser::K_DEFERRED);
        break;
      }

      case 2: {
        setState(1286);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1287);
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

void PotatoSQLParser::Raise_functionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRaise_function(this);
}

void PotatoSQLParser::Raise_functionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRaise_function(this);
}


antlrcpp::Any PotatoSQLParser::Raise_functionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitRaise_function(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Raise_functionContext* PotatoSQLParser::raise_function() {
  Raise_functionContext *_localctx = _tracker.createInstance<Raise_functionContext>(_ctx, getState());
  enterRule(_localctx, 90, PotatoSQLParser::RuleRaise_function);
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
    setState(1292);
    match(PotatoSQLParser::K_RAISE);
    setState(1293);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_IGNORE: {
        setState(1294);
        match(PotatoSQLParser::K_IGNORE);
        break;
      }

      case PotatoSQLParser::K_ABORT:
      case PotatoSQLParser::K_FAIL:
      case PotatoSQLParser::K_ROLLBACK: {
        setState(1295);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::K_ABORT || _la == PotatoSQLParser::K_FAIL

        || _la == PotatoSQLParser::K_ROLLBACK)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1296);
        match(PotatoSQLParser::COMMA);
        setState(1297);
        error_message();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1300);
    match(PotatoSQLParser::CLOSE_PAR);
   
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

void PotatoSQLParser::Indexed_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexed_column(this);
}

void PotatoSQLParser::Indexed_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexed_column(this);
}


antlrcpp::Any PotatoSQLParser::Indexed_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitIndexed_column(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Indexed_columnContext* PotatoSQLParser::indexed_column() {
  Indexed_columnContext *_localctx = _tracker.createInstance<Indexed_columnContext>(_ctx, getState());
  enterRule(_localctx, 92, PotatoSQLParser::RuleIndexed_column);
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
    setState(1302);
    column_name();
    setState(1305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1303);
      match(PotatoSQLParser::K_COLLATE);
      setState(1304);
      collation_name();
    }
    setState(1308);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1307);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ASC

      || _la == PotatoSQLParser::K_DESC)) {
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

void PotatoSQLParser::Table_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_constraint(this);
}

void PotatoSQLParser::Table_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_constraint(this);
}


antlrcpp::Any PotatoSQLParser::Table_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_constraint(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_constraintContext* PotatoSQLParser::table_constraint() {
  Table_constraintContext *_localctx = _tracker.createInstance<Table_constraintContext>(_ctx, getState());
  enterRule(_localctx, 94, PotatoSQLParser::RuleTable_constraint);
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
    setState(1312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1310);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1311);
      name();
    }
    setState(1350);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY:
      case PotatoSQLParser::K_UNIQUE: {
        setState(1317);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_PRIMARY: {
            setState(1314);
            match(PotatoSQLParser::K_PRIMARY);
            setState(1315);
            match(PotatoSQLParser::K_KEY);
            break;
          }

          case PotatoSQLParser::K_UNIQUE: {
            setState(1316);
            match(PotatoSQLParser::K_UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1319);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1320);
        indexed_column();
        setState(1325);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1321);
          match(PotatoSQLParser::COMMA);
          setState(1322);
          indexed_column();
          setState(1327);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1328);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1329);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1331);
        match(PotatoSQLParser::K_CHECK);
        setState(1332);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1333);
        expr(0);
        setState(1334);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_FOREIGN: {
        setState(1336);
        match(PotatoSQLParser::K_FOREIGN);
        setState(1337);
        match(PotatoSQLParser::K_KEY);
        setState(1338);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1339);
        column_name();
        setState(1344);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1340);
          match(PotatoSQLParser::COMMA);
          setState(1341);
          column_name();
          setState(1346);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1347);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1348);
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

void PotatoSQLParser::With_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWith_clause(this);
}

void PotatoSQLParser::With_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWith_clause(this);
}


antlrcpp::Any PotatoSQLParser::With_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitWith_clause(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::With_clauseContext* PotatoSQLParser::with_clause() {
  With_clauseContext *_localctx = _tracker.createInstance<With_clauseContext>(_ctx, getState());
  enterRule(_localctx, 96, PotatoSQLParser::RuleWith_clause);
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
    match(PotatoSQLParser::K_WITH);
    setState(1354);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 185, _ctx)) {
    case 1: {
      setState(1353);
      match(PotatoSQLParser::K_RECURSIVE);
      break;
    }

    default:
      break;
    }
    setState(1356);
    common_table_expression();
    setState(1361);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1357);
      match(PotatoSQLParser::COMMA);
      setState(1358);
      common_table_expression();
      setState(1363);
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

void PotatoSQLParser::Qualified_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualified_table_name(this);
}

void PotatoSQLParser::Qualified_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualified_table_name(this);
}


antlrcpp::Any PotatoSQLParser::Qualified_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitQualified_table_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Qualified_table_nameContext* PotatoSQLParser::qualified_table_name() {
  Qualified_table_nameContext *_localctx = _tracker.createInstance<Qualified_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 98, PotatoSQLParser::RuleQualified_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1367);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 187, _ctx)) {
    case 1: {
      setState(1364);
      database_name();
      setState(1365);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(1369);
    table_name();
    setState(1375);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_INDEXED: {
        setState(1370);
        match(PotatoSQLParser::K_INDEXED);
        setState(1371);
        match(PotatoSQLParser::K_BY);
        setState(1372);
        index_name();
        break;
      }

      case PotatoSQLParser::K_NOT: {
        setState(1373);
        match(PotatoSQLParser::K_NOT);
        setState(1374);
        match(PotatoSQLParser::K_INDEXED);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_ANALYZE:
      case PotatoSQLParser::K_ATTACH:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DETACH:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_EXPLAIN:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_LIMIT:
      case PotatoSQLParser::K_ORDER:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_REINDEX:
      case PotatoSQLParser::K_RELEASE:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_SAVEPOINT:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_SET:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_VACUUM:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_WHERE:
      case PotatoSQLParser::K_WITH:
      case PotatoSQLParser::UNEXPECTED_CHAR: {
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

void PotatoSQLParser::Ordering_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdering_term(this);
}

void PotatoSQLParser::Ordering_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdering_term(this);
}


antlrcpp::Any PotatoSQLParser::Ordering_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitOrdering_term(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Ordering_termContext* PotatoSQLParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 100, PotatoSQLParser::RuleOrdering_term);
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
    setState(1377);
    expr(0);
    setState(1380);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1378);
      match(PotatoSQLParser::K_COLLATE);
      setState(1379);
      collation_name();
    }
    setState(1383);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1382);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ASC

      || _la == PotatoSQLParser::K_DESC)) {
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

void PotatoSQLParser::Pragma_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_value(this);
}

void PotatoSQLParser::Pragma_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_value(this);
}


antlrcpp::Any PotatoSQLParser::Pragma_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitPragma_value(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Pragma_valueContext* PotatoSQLParser::pragma_value() {
  Pragma_valueContext *_localctx = _tracker.createInstance<Pragma_valueContext>(_ctx, getState());
  enterRule(_localctx, 102, PotatoSQLParser::RulePragma_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 191, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1385);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1386);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1387);
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

void PotatoSQLParser::Common_table_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommon_table_expression(this);
}

void PotatoSQLParser::Common_table_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommon_table_expression(this);
}


antlrcpp::Any PotatoSQLParser::Common_table_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCommon_table_expression(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Common_table_expressionContext* PotatoSQLParser::common_table_expression() {
  Common_table_expressionContext *_localctx = _tracker.createInstance<Common_table_expressionContext>(_ctx, getState());
  enterRule(_localctx, 104, PotatoSQLParser::RuleCommon_table_expression);
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
    setState(1390);
    table_name();
    setState(1402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1391);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1392);
      column_name();
      setState(1397);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1393);
        match(PotatoSQLParser::COMMA);
        setState(1394);
        column_name();
        setState(1399);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1400);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1404);
    match(PotatoSQLParser::K_AS);
    setState(1405);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1406);
    select_stmt();
    setState(1407);
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

void PotatoSQLParser::Result_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult_column(this);
}

void PotatoSQLParser::Result_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult_column(this);
}


antlrcpp::Any PotatoSQLParser::Result_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitResult_column(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Result_columnContext* PotatoSQLParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 106, PotatoSQLParser::RuleResult_column);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1421);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1409);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1410);
      table_name();
      setState(1411);
      match(PotatoSQLParser::DOT);
      setState(1412);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1414);
      expr(0);
      setState(1419);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1416);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1415);
          match(PotatoSQLParser::K_AS);
        }
        setState(1418);
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

void PotatoSQLParser::Table_or_subqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_subquery(this);
}

void PotatoSQLParser::Table_or_subqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_subquery(this);
}


antlrcpp::Any PotatoSQLParser::Table_or_subqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_or_subquery(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_or_subqueryContext* PotatoSQLParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 108, PotatoSQLParser::RuleTable_or_subquery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1489);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 210, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1426);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 197, _ctx)) {
      case 1: {
        setState(1423);
        schema_name();
        setState(1424);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1428);
      table_name();
      setState(1433);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1430);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1429);
          match(PotatoSQLParser::K_AS);
        }
        setState(1432);
        table_alias();
      }
      setState(1440);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_INDEXED: {
          setState(1435);
          match(PotatoSQLParser::K_INDEXED);
          setState(1436);
          match(PotatoSQLParser::K_BY);
          setState(1437);
          index_name();
          break;
        }

        case PotatoSQLParser::K_NOT: {
          setState(1438);
          match(PotatoSQLParser::K_NOT);
          setState(1439);
          match(PotatoSQLParser::K_INDEXED);
          break;
        }

        case PotatoSQLParser::EOF:
        case PotatoSQLParser::SCOL:
        case PotatoSQLParser::CLOSE_PAR:
        case PotatoSQLParser::COMMA:
        case PotatoSQLParser::K_ALTER:
        case PotatoSQLParser::K_ANALYZE:
        case PotatoSQLParser::K_ATTACH:
        case PotatoSQLParser::K_BEGIN:
        case PotatoSQLParser::K_COMMIT:
        case PotatoSQLParser::K_CREATE:
        case PotatoSQLParser::K_CROSS:
        case PotatoSQLParser::K_DELETE:
        case PotatoSQLParser::K_DETACH:
        case PotatoSQLParser::K_DROP:
        case PotatoSQLParser::K_END:
        case PotatoSQLParser::K_EXCEPT:
        case PotatoSQLParser::K_EXPLAIN:
        case PotatoSQLParser::K_GROUP:
        case PotatoSQLParser::K_INNER:
        case PotatoSQLParser::K_INSERT:
        case PotatoSQLParser::K_INTERSECT:
        case PotatoSQLParser::K_JOIN:
        case PotatoSQLParser::K_LEFT:
        case PotatoSQLParser::K_LIMIT:
        case PotatoSQLParser::K_NATURAL:
        case PotatoSQLParser::K_ON:
        case PotatoSQLParser::K_ORDER:
        case PotatoSQLParser::K_PRAGMA:
        case PotatoSQLParser::K_REINDEX:
        case PotatoSQLParser::K_RELEASE:
        case PotatoSQLParser::K_REPLACE:
        case PotatoSQLParser::K_ROLLBACK:
        case PotatoSQLParser::K_SAVEPOINT:
        case PotatoSQLParser::K_SELECT:
        case PotatoSQLParser::K_UNION:
        case PotatoSQLParser::K_UPDATE:
        case PotatoSQLParser::K_USING:
        case PotatoSQLParser::K_VACUUM:
        case PotatoSQLParser::K_VALUES:
        case PotatoSQLParser::K_WHERE:
        case PotatoSQLParser::K_WITH:
        case PotatoSQLParser::UNEXPECTED_CHAR: {
          break;
        }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1445);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx)) {
      case 1: {
        setState(1442);
        schema_name();
        setState(1443);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1447);
      table_function_name();
      setState(1448);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1457);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << PotatoSQLParser::OPEN_PAR)
        | (1ULL << PotatoSQLParser::PLUS)
        | (1ULL << PotatoSQLParser::MINUS)
        | (1ULL << PotatoSQLParser::TILDE)
        | (1ULL << PotatoSQLParser::K_ABORT)
        | (1ULL << PotatoSQLParser::K_ACTION)
        | (1ULL << PotatoSQLParser::K_ADD)
        | (1ULL << PotatoSQLParser::K_AFTER)
        | (1ULL << PotatoSQLParser::K_ALL)
        | (1ULL << PotatoSQLParser::K_ALTER)
        | (1ULL << PotatoSQLParser::K_ANALYZE)
        | (1ULL << PotatoSQLParser::K_AND)
        | (1ULL << PotatoSQLParser::K_AS)
        | (1ULL << PotatoSQLParser::K_ASC)
        | (1ULL << PotatoSQLParser::K_ATTACH)
        | (1ULL << PotatoSQLParser::K_AUTOINCREMENT)
        | (1ULL << PotatoSQLParser::K_BEFORE)
        | (1ULL << PotatoSQLParser::K_BEGIN)
        | (1ULL << PotatoSQLParser::K_BETWEEN)
        | (1ULL << PotatoSQLParser::K_BY)
        | (1ULL << PotatoSQLParser::K_CASCADE)
        | (1ULL << PotatoSQLParser::K_CASE)
        | (1ULL << PotatoSQLParser::K_CAST)
        | (1ULL << PotatoSQLParser::K_CHECK)
        | (1ULL << PotatoSQLParser::K_COLLATE)
        | (1ULL << PotatoSQLParser::K_COLUMN)
        | (1ULL << PotatoSQLParser::K_COMMIT)
        | (1ULL << PotatoSQLParser::K_CONFLICT)
        | (1ULL << PotatoSQLParser::K_CONSTRAINT)
        | (1ULL << PotatoSQLParser::K_CREATE)
        | (1ULL << PotatoSQLParser::K_CROSS)
        | (1ULL << PotatoSQLParser::K_CURRENT_DATE)
        | (1ULL << PotatoSQLParser::K_CURRENT_TIME)
        | (1ULL << PotatoSQLParser::K_CURRENT_TIMESTAMP)
        | (1ULL << PotatoSQLParser::K_DATABASE)
        | (1ULL << PotatoSQLParser::K_DEFAULT)
        | (1ULL << PotatoSQLParser::K_DEFERRABLE)
        | (1ULL << PotatoSQLParser::K_DEFERRED)
        | (1ULL << PotatoSQLParser::K_DELETE)
        | (1ULL << PotatoSQLParser::K_DESC)
        | (1ULL << PotatoSQLParser::K_DETACH)
        | (1ULL << PotatoSQLParser::K_DISTINCT)
        | (1ULL << PotatoSQLParser::K_DROP))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (PotatoSQLParser::K_EACH - 64))
        | (1ULL << (PotatoSQLParser::K_ELSE - 64))
        | (1ULL << (PotatoSQLParser::K_END - 64))
        | (1ULL << (PotatoSQLParser::K_ESCAPE - 64))
        | (1ULL << (PotatoSQLParser::K_EXCEPT - 64))
        | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 64))
        | (1ULL << (PotatoSQLParser::K_EXISTS - 64))
        | (1ULL << (PotatoSQLParser::K_EXPLAIN - 64))
        | (1ULL << (PotatoSQLParser::K_FAIL - 64))
        | (1ULL << (PotatoSQLParser::K_FOR - 64))
        | (1ULL << (PotatoSQLParser::K_FOREIGN - 64))
        | (1ULL << (PotatoSQLParser::K_FROM - 64))
        | (1ULL << (PotatoSQLParser::K_FULL - 64))
        | (1ULL << (PotatoSQLParser::K_GLOB - 64))
        | (1ULL << (PotatoSQLParser::K_GROUP - 64))
        | (1ULL << (PotatoSQLParser::K_HAVING - 64))
        | (1ULL << (PotatoSQLParser::K_IF - 64))
        | (1ULL << (PotatoSQLParser::K_IGNORE - 64))
        | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 64))
        | (1ULL << (PotatoSQLParser::K_IN - 64))
        | (1ULL << (PotatoSQLParser::K_INDEX - 64))
        | (1ULL << (PotatoSQLParser::K_INDEXED - 64))
        | (1ULL << (PotatoSQLParser::K_INITIALLY - 64))
        | (1ULL << (PotatoSQLParser::K_INNER - 64))
        | (1ULL << (PotatoSQLParser::K_INSERT - 64))
        | (1ULL << (PotatoSQLParser::K_INSTEAD - 64))
        | (1ULL << (PotatoSQLParser::K_INTERSECT - 64))
        | (1ULL << (PotatoSQLParser::K_INTO - 64))
        | (1ULL << (PotatoSQLParser::K_IS - 64))
        | (1ULL << (PotatoSQLParser::K_ISNULL - 64))
        | (1ULL << (PotatoSQLParser::K_JOIN - 64))
        | (1ULL << (PotatoSQLParser::K_KEY - 64))
        | (1ULL << (PotatoSQLParser::K_LEFT - 64))
        | (1ULL << (PotatoSQLParser::K_LIKE - 64))
        | (1ULL << (PotatoSQLParser::K_LIMIT - 64))
        | (1ULL << (PotatoSQLParser::K_MATCH - 64))
        | (1ULL << (PotatoSQLParser::K_NATURAL - 64))
        | (1ULL << (PotatoSQLParser::K_NO - 64))
        | (1ULL << (PotatoSQLParser::K_NOT - 64))
        | (1ULL << (PotatoSQLParser::K_NOTNULL - 64))
        | (1ULL << (PotatoSQLParser::K_NULL - 64))
        | (1ULL << (PotatoSQLParser::K_OF - 64))
        | (1ULL << (PotatoSQLParser::K_OFFSET - 64))
        | (1ULL << (PotatoSQLParser::K_ON - 64))
        | (1ULL << (PotatoSQLParser::K_OR - 64))
        | (1ULL << (PotatoSQLParser::K_ORDER - 64))
        | (1ULL << (PotatoSQLParser::K_OUTER - 64))
        | (1ULL << (PotatoSQLParser::K_PLAN - 64))
        | (1ULL << (PotatoSQLParser::K_PRAGMA - 64))
        | (1ULL << (PotatoSQLParser::K_PRIMARY - 64))
        | (1ULL << (PotatoSQLParser::K_QUERY - 64))
        | (1ULL << (PotatoSQLParser::K_RAISE - 64))
        | (1ULL << (PotatoSQLParser::K_RECURSIVE - 64))
        | (1ULL << (PotatoSQLParser::K_REFERENCES - 64))
        | (1ULL << (PotatoSQLParser::K_REGEXP - 64))
        | (1ULL << (PotatoSQLParser::K_REINDEX - 64))
        | (1ULL << (PotatoSQLParser::K_RELEASE - 64))
        | (1ULL << (PotatoSQLParser::K_RENAME - 64))
        | (1ULL << (PotatoSQLParser::K_REPLACE - 64))
        | (1ULL << (PotatoSQLParser::K_RESTRICT - 64))
        | (1ULL << (PotatoSQLParser::K_RIGHT - 64))
        | (1ULL << (PotatoSQLParser::K_ROLLBACK - 64))
        | (1ULL << (PotatoSQLParser::K_ROW - 64))
        | (1ULL << (PotatoSQLParser::K_SAVEPOINT - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (PotatoSQLParser::K_SELECT - 128))
        | (1ULL << (PotatoSQLParser::K_SET - 128))
        | (1ULL << (PotatoSQLParser::K_TABLE - 128))
        | (1ULL << (PotatoSQLParser::K_TEMP - 128))
        | (1ULL << (PotatoSQLParser::K_TEMPORARY - 128))
        | (1ULL << (PotatoSQLParser::K_THEN - 128))
        | (1ULL << (PotatoSQLParser::K_TO - 128))
        | (1ULL << (PotatoSQLParser::K_TRANSACTION - 128))
        | (1ULL << (PotatoSQLParser::K_TRIGGER - 128))
        | (1ULL << (PotatoSQLParser::K_UNION - 128))
        | (1ULL << (PotatoSQLParser::K_UNIQUE - 128))
        | (1ULL << (PotatoSQLParser::K_UPDATE - 128))
        | (1ULL << (PotatoSQLParser::K_USING - 128))
        | (1ULL << (PotatoSQLParser::K_VACUUM - 128))
        | (1ULL << (PotatoSQLParser::K_VALUES - 128))
        | (1ULL << (PotatoSQLParser::K_VIEW - 128))
        | (1ULL << (PotatoSQLParser::K_VIRTUAL - 128))
        | (1ULL << (PotatoSQLParser::K_WHEN - 128))
        | (1ULL << (PotatoSQLParser::K_WHERE - 128))
        | (1ULL << (PotatoSQLParser::K_WITH - 128))
        | (1ULL << (PotatoSQLParser::K_WITHOUT - 128))
        | (1ULL << (PotatoSQLParser::IDENTIFIER - 128))
        | (1ULL << (PotatoSQLParser::NUMERIC_LITERAL - 128))
        | (1ULL << (PotatoSQLParser::BIND_PARAMETER - 128))
        | (1ULL << (PotatoSQLParser::STRING_LITERAL - 128))
        | (1ULL << (PotatoSQLParser::BLOB_LITERAL - 128)))) != 0)) {
        setState(1449);
        expr(0);
        setState(1454);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1450);
          match(PotatoSQLParser::COMMA);
          setState(1451);
          expr(0);
          setState(1456);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1459);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1464);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1461);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1460);
          match(PotatoSQLParser::K_AS);
        }
        setState(1463);
        table_alias();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1466);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1476);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 207, _ctx)) {
      case 1: {
        setState(1467);
        table_or_subquery();
        setState(1472);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1468);
          match(PotatoSQLParser::COMMA);
          setState(1469);
          table_or_subquery();
          setState(1474);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(1475);
        join_clause();
        break;
      }

      default:
        break;
      }
      setState(1478);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1480);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1481);
      select_stmt();
      setState(1482);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1487);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1484);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1483);
          match(PotatoSQLParser::K_AS);
        }
        setState(1486);
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

void PotatoSQLParser::Join_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_clause(this);
}

void PotatoSQLParser::Join_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_clause(this);
}


antlrcpp::Any PotatoSQLParser::Join_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitJoin_clause(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Join_clauseContext* PotatoSQLParser::join_clause() {
  Join_clauseContext *_localctx = _tracker.createInstance<Join_clauseContext>(_ctx, getState());
  enterRule(_localctx, 110, PotatoSQLParser::RuleJoin_clause);
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
    setState(1491);
    table_or_subquery();
    setState(1498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA

    || _la == PotatoSQLParser::K_CROSS || ((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (PotatoSQLParser::K_INNER - 87))
      | (1ULL << (PotatoSQLParser::K_JOIN - 87))
      | (1ULL << (PotatoSQLParser::K_LEFT - 87))
      | (1ULL << (PotatoSQLParser::K_NATURAL - 87)))) != 0)) {
      setState(1492);
      join_operator();
      setState(1493);
      table_or_subquery();
      setState(1494);
      join_constraint();
      setState(1500);
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

void PotatoSQLParser::Join_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_operator(this);
}

void PotatoSQLParser::Join_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_operator(this);
}


antlrcpp::Any PotatoSQLParser::Join_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitJoin_operator(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Join_operatorContext* PotatoSQLParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 112, PotatoSQLParser::RuleJoin_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1514);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(1501);
        match(PotatoSQLParser::COMMA);
        break;
      }

      case PotatoSQLParser::K_CROSS:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_NATURAL: {
        enterOuterAlt(_localctx, 2);
        setState(1503);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NATURAL) {
          setState(1502);
          match(PotatoSQLParser::K_NATURAL);
        }
        setState(1511);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_LEFT: {
            setState(1505);
            match(PotatoSQLParser::K_LEFT);
            setState(1507);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == PotatoSQLParser::K_OUTER) {
              setState(1506);
              match(PotatoSQLParser::K_OUTER);
            }
            break;
          }

          case PotatoSQLParser::K_INNER: {
            setState(1509);
            match(PotatoSQLParser::K_INNER);
            break;
          }

          case PotatoSQLParser::K_CROSS: {
            setState(1510);
            match(PotatoSQLParser::K_CROSS);
            break;
          }

          case PotatoSQLParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(1513);
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

void PotatoSQLParser::Join_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_constraint(this);
}

void PotatoSQLParser::Join_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_constraint(this);
}


antlrcpp::Any PotatoSQLParser::Join_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitJoin_constraint(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Join_constraintContext* PotatoSQLParser::join_constraint() {
  Join_constraintContext *_localctx = _tracker.createInstance<Join_constraintContext>(_ctx, getState());
  enterRule(_localctx, 114, PotatoSQLParser::RuleJoin_constraint);
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
    setState(1530);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_ON: {
        setState(1516);
        match(PotatoSQLParser::K_ON);
        setState(1517);
        expr(0);
        break;
      }

      case PotatoSQLParser::K_USING: {
        setState(1518);
        match(PotatoSQLParser::K_USING);
        setState(1519);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1520);
        column_name();
        setState(1525);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1521);
          match(PotatoSQLParser::COMMA);
          setState(1522);
          column_name();
          setState(1527);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1528);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::EOF:
      case PotatoSQLParser::SCOL:
      case PotatoSQLParser::CLOSE_PAR:
      case PotatoSQLParser::COMMA:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_ANALYZE:
      case PotatoSQLParser::K_ATTACH:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_CROSS:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DETACH:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_EXCEPT:
      case PotatoSQLParser::K_EXPLAIN:
      case PotatoSQLParser::K_GROUP:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_INTERSECT:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_LIMIT:
      case PotatoSQLParser::K_NATURAL:
      case PotatoSQLParser::K_ORDER:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_REINDEX:
      case PotatoSQLParser::K_RELEASE:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_SAVEPOINT:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_UNION:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_VACUUM:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_WHERE:
      case PotatoSQLParser::K_WITH:
      case PotatoSQLParser::UNEXPECTED_CHAR: {
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

//----------------- Column_listContext ------------------------------------------------------------------

PotatoSQLParser::Column_listContext::Column_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::Result_columnContext *> PotatoSQLParser::Column_listContext::result_column() {
  return getRuleContexts<PotatoSQLParser::Result_columnContext>();
}

PotatoSQLParser::Result_columnContext* PotatoSQLParser::Column_listContext::result_column(size_t i) {
  return getRuleContext<PotatoSQLParser::Result_columnContext>(i);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Column_listContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Column_listContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Column_listContext::getRuleIndex() const {
  return PotatoSQLParser::RuleColumn_list;
}

void PotatoSQLParser::Column_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_list(this);
}

void PotatoSQLParser::Column_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_list(this);
}


antlrcpp::Any PotatoSQLParser::Column_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitColumn_list(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Column_listContext* PotatoSQLParser::column_list() {
  Column_listContext *_localctx = _tracker.createInstance<Column_listContext>(_ctx, getState());
  enterRule(_localctx, 116, PotatoSQLParser::RuleColumn_list);
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
    setState(1532);
    result_column();
    setState(1537);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1533);
      match(PotatoSQLParser::COMMA);
      setState(1534);
      result_column();
      setState(1539);
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

//----------------- Select_coreContext ------------------------------------------------------------------

PotatoSQLParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_SELECT() {
  return getToken(PotatoSQLParser::K_SELECT, 0);
}

PotatoSQLParser::Column_listContext* PotatoSQLParser::Select_coreContext::column_list() {
  return getRuleContext<PotatoSQLParser::Column_listContext>(0);
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

std::vector<tree::TerminalNode *> PotatoSQLParser::Select_coreContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
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

void PotatoSQLParser::Select_coreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_core(this);
}

void PotatoSQLParser::Select_coreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_core(this);
}


antlrcpp::Any PotatoSQLParser::Select_coreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSelect_core(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Select_coreContext* PotatoSQLParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 118, PotatoSQLParser::RuleSelect_core);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1607);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1540);
        match(PotatoSQLParser::K_SELECT);
        setState(1542);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 219, _ctx)) {
        case 1: {
          setState(1541);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_ALL

          || _la == PotatoSQLParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        }
        setState(1544);
        column_list();
        setState(1557);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(1545);
          match(PotatoSQLParser::K_FROM);
          setState(1555);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 221, _ctx)) {
          case 1: {
            setState(1546);
            table_or_subquery();
            setState(1551);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(1547);
              match(PotatoSQLParser::COMMA);
              setState(1548);
              table_or_subquery();
              setState(1553);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(1554);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(1561);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(1559);
          match(PotatoSQLParser::K_WHERE);
          setState(1560);
          expr(0);
        }
        setState(1577);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(1563);
          match(PotatoSQLParser::K_GROUP);
          setState(1564);
          match(PotatoSQLParser::K_BY);
          setState(1565);
          expr(0);
          setState(1570);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1566);
            match(PotatoSQLParser::COMMA);
            setState(1567);
            expr(0);
            setState(1572);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1575);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(1573);
            match(PotatoSQLParser::K_HAVING);
            setState(1574);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(1579);
        match(PotatoSQLParser::K_VALUES);
        setState(1580);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1581);
        expr(0);
        setState(1586);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1582);
          match(PotatoSQLParser::COMMA);
          setState(1583);
          expr(0);
          setState(1588);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1589);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1604);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1590);
          match(PotatoSQLParser::COMMA);
          setState(1591);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1592);
          expr(0);
          setState(1597);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1593);
            match(PotatoSQLParser::COMMA);
            setState(1594);
            expr(0);
            setState(1599);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1600);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(1606);
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

void PotatoSQLParser::Compound_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_operator(this);
}

void PotatoSQLParser::Compound_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_operator(this);
}


antlrcpp::Any PotatoSQLParser::Compound_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCompound_operator(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Compound_operatorContext* PotatoSQLParser::compound_operator() {
  Compound_operatorContext *_localctx = _tracker.createInstance<Compound_operatorContext>(_ctx, getState());
  enterRule(_localctx, 120, PotatoSQLParser::RuleCompound_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1614);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 231, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1609);
      match(PotatoSQLParser::K_UNION);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1610);
      match(PotatoSQLParser::K_UNION);
      setState(1611);
      match(PotatoSQLParser::K_ALL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1612);
      match(PotatoSQLParser::K_INTERSECT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1613);
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

void PotatoSQLParser::Signed_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigned_number(this);
}

void PotatoSQLParser::Signed_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigned_number(this);
}


antlrcpp::Any PotatoSQLParser::Signed_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSigned_number(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Signed_numberContext* PotatoSQLParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 122, PotatoSQLParser::RuleSigned_number);
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
    setState(1617);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::PLUS

    || _la == PotatoSQLParser::MINUS) {
      setState(1616);
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
    setState(1619);
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

void PotatoSQLParser::Literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_value(this);
}

void PotatoSQLParser::Literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_value(this);
}


antlrcpp::Any PotatoSQLParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Literal_valueContext* PotatoSQLParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 124, PotatoSQLParser::RuleLiteral_value);
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
    setState(1621);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_CURRENT_DATE)
      | (1ULL << PotatoSQLParser::K_CURRENT_TIME)
      | (1ULL << PotatoSQLParser::K_CURRENT_TIMESTAMP))) != 0) || ((((_la - 104) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 104)) & ((1ULL << (PotatoSQLParser::K_NULL - 104))
      | (1ULL << (PotatoSQLParser::NUMERIC_LITERAL - 104))
      | (1ULL << (PotatoSQLParser::STRING_LITERAL - 104))
      | (1ULL << (PotatoSQLParser::BLOB_LITERAL - 104)))) != 0))) {
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

void PotatoSQLParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}

void PotatoSQLParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}


antlrcpp::Any PotatoSQLParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Unary_operatorContext* PotatoSQLParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 126, PotatoSQLParser::RuleUnary_operator);
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
    setState(1623);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::PLUS)
      | (1ULL << PotatoSQLParser::MINUS)
      | (1ULL << PotatoSQLParser::TILDE))) != 0) || _la == PotatoSQLParser::K_NOT)) {
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

void PotatoSQLParser::Error_messageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError_message(this);
}

void PotatoSQLParser::Error_messageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError_message(this);
}


antlrcpp::Any PotatoSQLParser::Error_messageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitError_message(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Error_messageContext* PotatoSQLParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 128, PotatoSQLParser::RuleError_message);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1625);
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

void PotatoSQLParser::Module_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_argument(this);
}

void PotatoSQLParser::Module_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_argument(this);
}


antlrcpp::Any PotatoSQLParser::Module_argumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitModule_argument(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Module_argumentContext* PotatoSQLParser::module_argument() {
  Module_argumentContext *_localctx = _tracker.createInstance<Module_argumentContext>(_ctx, getState());
  enterRule(_localctx, 130, PotatoSQLParser::RuleModule_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 233, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1627);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1628);
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

void PotatoSQLParser::Column_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_alias(this);
}

void PotatoSQLParser::Column_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_alias(this);
}


antlrcpp::Any PotatoSQLParser::Column_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitColumn_alias(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Column_aliasContext* PotatoSQLParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 132, PotatoSQLParser::RuleColumn_alias);
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
    setState(1631);
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

//----------------- KeywordContext ------------------------------------------------------------------

PotatoSQLParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ABORT() {
  return getToken(PotatoSQLParser::K_ABORT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ACTION() {
  return getToken(PotatoSQLParser::K_ACTION, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ADD() {
  return getToken(PotatoSQLParser::K_ADD, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_AFTER() {
  return getToken(PotatoSQLParser::K_AFTER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ALL() {
  return getToken(PotatoSQLParser::K_ALL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ALTER() {
  return getToken(PotatoSQLParser::K_ALTER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ANALYZE() {
  return getToken(PotatoSQLParser::K_ANALYZE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_AND() {
  return getToken(PotatoSQLParser::K_AND, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_AS() {
  return getToken(PotatoSQLParser::K_AS, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ASC() {
  return getToken(PotatoSQLParser::K_ASC, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ATTACH() {
  return getToken(PotatoSQLParser::K_ATTACH, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_AUTOINCREMENT() {
  return getToken(PotatoSQLParser::K_AUTOINCREMENT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_BEFORE() {
  return getToken(PotatoSQLParser::K_BEFORE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_BEGIN() {
  return getToken(PotatoSQLParser::K_BEGIN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_BETWEEN() {
  return getToken(PotatoSQLParser::K_BETWEEN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CASCADE() {
  return getToken(PotatoSQLParser::K_CASCADE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CASE() {
  return getToken(PotatoSQLParser::K_CASE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CAST() {
  return getToken(PotatoSQLParser::K_CAST, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CHECK() {
  return getToken(PotatoSQLParser::K_CHECK, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_COLLATE() {
  return getToken(PotatoSQLParser::K_COLLATE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_COLUMN() {
  return getToken(PotatoSQLParser::K_COLUMN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_COMMIT() {
  return getToken(PotatoSQLParser::K_COMMIT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CONFLICT() {
  return getToken(PotatoSQLParser::K_CONFLICT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CONSTRAINT() {
  return getToken(PotatoSQLParser::K_CONSTRAINT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CREATE() {
  return getToken(PotatoSQLParser::K_CREATE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CROSS() {
  return getToken(PotatoSQLParser::K_CROSS, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CURRENT_DATE() {
  return getToken(PotatoSQLParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CURRENT_TIME() {
  return getToken(PotatoSQLParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_CURRENT_TIMESTAMP() {
  return getToken(PotatoSQLParser::K_CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DATABASE() {
  return getToken(PotatoSQLParser::K_DATABASE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DEFAULT() {
  return getToken(PotatoSQLParser::K_DEFAULT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DEFERRABLE() {
  return getToken(PotatoSQLParser::K_DEFERRABLE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DEFERRED() {
  return getToken(PotatoSQLParser::K_DEFERRED, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DELETE() {
  return getToken(PotatoSQLParser::K_DELETE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DESC() {
  return getToken(PotatoSQLParser::K_DESC, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DETACH() {
  return getToken(PotatoSQLParser::K_DETACH, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DISTINCT() {
  return getToken(PotatoSQLParser::K_DISTINCT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_DROP() {
  return getToken(PotatoSQLParser::K_DROP, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_EACH() {
  return getToken(PotatoSQLParser::K_EACH, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ELSE() {
  return getToken(PotatoSQLParser::K_ELSE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_END() {
  return getToken(PotatoSQLParser::K_END, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ESCAPE() {
  return getToken(PotatoSQLParser::K_ESCAPE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_EXCEPT() {
  return getToken(PotatoSQLParser::K_EXCEPT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_EXCLUSIVE() {
  return getToken(PotatoSQLParser::K_EXCLUSIVE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_EXISTS() {
  return getToken(PotatoSQLParser::K_EXISTS, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_EXPLAIN() {
  return getToken(PotatoSQLParser::K_EXPLAIN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FAIL() {
  return getToken(PotatoSQLParser::K_FAIL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FOR() {
  return getToken(PotatoSQLParser::K_FOR, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FOREIGN() {
  return getToken(PotatoSQLParser::K_FOREIGN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FROM() {
  return getToken(PotatoSQLParser::K_FROM, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FULL() {
  return getToken(PotatoSQLParser::K_FULL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_GLOB() {
  return getToken(PotatoSQLParser::K_GLOB, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_GROUP() {
  return getToken(PotatoSQLParser::K_GROUP, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_HAVING() {
  return getToken(PotatoSQLParser::K_HAVING, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_IF() {
  return getToken(PotatoSQLParser::K_IF, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_IGNORE() {
  return getToken(PotatoSQLParser::K_IGNORE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_IMMEDIATE() {
  return getToken(PotatoSQLParser::K_IMMEDIATE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_IN() {
  return getToken(PotatoSQLParser::K_IN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INDEX() {
  return getToken(PotatoSQLParser::K_INDEX, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INDEXED() {
  return getToken(PotatoSQLParser::K_INDEXED, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INITIALLY() {
  return getToken(PotatoSQLParser::K_INITIALLY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INNER() {
  return getToken(PotatoSQLParser::K_INNER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INSERT() {
  return getToken(PotatoSQLParser::K_INSERT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INSTEAD() {
  return getToken(PotatoSQLParser::K_INSTEAD, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INTERSECT() {
  return getToken(PotatoSQLParser::K_INTERSECT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_INTO() {
  return getToken(PotatoSQLParser::K_INTO, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_IS() {
  return getToken(PotatoSQLParser::K_IS, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ISNULL() {
  return getToken(PotatoSQLParser::K_ISNULL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_JOIN() {
  return getToken(PotatoSQLParser::K_JOIN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_KEY() {
  return getToken(PotatoSQLParser::K_KEY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_LEFT() {
  return getToken(PotatoSQLParser::K_LEFT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_LIKE() {
  return getToken(PotatoSQLParser::K_LIKE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_LIMIT() {
  return getToken(PotatoSQLParser::K_LIMIT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_MATCH() {
  return getToken(PotatoSQLParser::K_MATCH, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_NATURAL() {
  return getToken(PotatoSQLParser::K_NATURAL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_NO() {
  return getToken(PotatoSQLParser::K_NO, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_NOTNULL() {
  return getToken(PotatoSQLParser::K_NOTNULL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_NULL() {
  return getToken(PotatoSQLParser::K_NULL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_OF() {
  return getToken(PotatoSQLParser::K_OF, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_OFFSET() {
  return getToken(PotatoSQLParser::K_OFFSET, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ON() {
  return getToken(PotatoSQLParser::K_ON, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_OR() {
  return getToken(PotatoSQLParser::K_OR, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ORDER() {
  return getToken(PotatoSQLParser::K_ORDER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_OUTER() {
  return getToken(PotatoSQLParser::K_OUTER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_PLAN() {
  return getToken(PotatoSQLParser::K_PLAN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_PRAGMA() {
  return getToken(PotatoSQLParser::K_PRAGMA, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_PRIMARY() {
  return getToken(PotatoSQLParser::K_PRIMARY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_QUERY() {
  return getToken(PotatoSQLParser::K_QUERY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RAISE() {
  return getToken(PotatoSQLParser::K_RAISE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RECURSIVE() {
  return getToken(PotatoSQLParser::K_RECURSIVE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_REFERENCES() {
  return getToken(PotatoSQLParser::K_REFERENCES, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_REGEXP() {
  return getToken(PotatoSQLParser::K_REGEXP, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_REINDEX() {
  return getToken(PotatoSQLParser::K_REINDEX, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RELEASE() {
  return getToken(PotatoSQLParser::K_RELEASE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RENAME() {
  return getToken(PotatoSQLParser::K_RENAME, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_REPLACE() {
  return getToken(PotatoSQLParser::K_REPLACE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RESTRICT() {
  return getToken(PotatoSQLParser::K_RESTRICT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_RIGHT() {
  return getToken(PotatoSQLParser::K_RIGHT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ROLLBACK() {
  return getToken(PotatoSQLParser::K_ROLLBACK, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_ROW() {
  return getToken(PotatoSQLParser::K_ROW, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_SAVEPOINT() {
  return getToken(PotatoSQLParser::K_SAVEPOINT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_SELECT() {
  return getToken(PotatoSQLParser::K_SELECT, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_SET() {
  return getToken(PotatoSQLParser::K_SET, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TEMP() {
  return getToken(PotatoSQLParser::K_TEMP, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TEMPORARY() {
  return getToken(PotatoSQLParser::K_TEMPORARY, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_THEN() {
  return getToken(PotatoSQLParser::K_THEN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TO() {
  return getToken(PotatoSQLParser::K_TO, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TRANSACTION() {
  return getToken(PotatoSQLParser::K_TRANSACTION, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TRIGGER() {
  return getToken(PotatoSQLParser::K_TRIGGER, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_UNION() {
  return getToken(PotatoSQLParser::K_UNION, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_UNIQUE() {
  return getToken(PotatoSQLParser::K_UNIQUE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_UPDATE() {
  return getToken(PotatoSQLParser::K_UPDATE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_USING() {
  return getToken(PotatoSQLParser::K_USING, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_VACUUM() {
  return getToken(PotatoSQLParser::K_VACUUM, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_VALUES() {
  return getToken(PotatoSQLParser::K_VALUES, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_VIEW() {
  return getToken(PotatoSQLParser::K_VIEW, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_VIRTUAL() {
  return getToken(PotatoSQLParser::K_VIRTUAL, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_WHEN() {
  return getToken(PotatoSQLParser::K_WHEN, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_WHERE() {
  return getToken(PotatoSQLParser::K_WHERE, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_WITH() {
  return getToken(PotatoSQLParser::K_WITH, 0);
}

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_WITHOUT() {
  return getToken(PotatoSQLParser::K_WITHOUT, 0);
}


size_t PotatoSQLParser::KeywordContext::getRuleIndex() const {
  return PotatoSQLParser::RuleKeyword;
}

void PotatoSQLParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void PotatoSQLParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any PotatoSQLParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::KeywordContext* PotatoSQLParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 134, PotatoSQLParser::RuleKeyword);
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
    setState(1633);
    _la = _input->LA(1);
    if (!(((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (PotatoSQLParser::K_ABORT - 25))
      | (1ULL << (PotatoSQLParser::K_ACTION - 25))
      | (1ULL << (PotatoSQLParser::K_ADD - 25))
      | (1ULL << (PotatoSQLParser::K_AFTER - 25))
      | (1ULL << (PotatoSQLParser::K_ALL - 25))
      | (1ULL << (PotatoSQLParser::K_ALTER - 25))
      | (1ULL << (PotatoSQLParser::K_ANALYZE - 25))
      | (1ULL << (PotatoSQLParser::K_AND - 25))
      | (1ULL << (PotatoSQLParser::K_AS - 25))
      | (1ULL << (PotatoSQLParser::K_ASC - 25))
      | (1ULL << (PotatoSQLParser::K_ATTACH - 25))
      | (1ULL << (PotatoSQLParser::K_AUTOINCREMENT - 25))
      | (1ULL << (PotatoSQLParser::K_BEFORE - 25))
      | (1ULL << (PotatoSQLParser::K_BEGIN - 25))
      | (1ULL << (PotatoSQLParser::K_BETWEEN - 25))
      | (1ULL << (PotatoSQLParser::K_BY - 25))
      | (1ULL << (PotatoSQLParser::K_CASCADE - 25))
      | (1ULL << (PotatoSQLParser::K_CASE - 25))
      | (1ULL << (PotatoSQLParser::K_CAST - 25))
      | (1ULL << (PotatoSQLParser::K_CHECK - 25))
      | (1ULL << (PotatoSQLParser::K_COLLATE - 25))
      | (1ULL << (PotatoSQLParser::K_COLUMN - 25))
      | (1ULL << (PotatoSQLParser::K_COMMIT - 25))
      | (1ULL << (PotatoSQLParser::K_CONFLICT - 25))
      | (1ULL << (PotatoSQLParser::K_CONSTRAINT - 25))
      | (1ULL << (PotatoSQLParser::K_CREATE - 25))
      | (1ULL << (PotatoSQLParser::K_CROSS - 25))
      | (1ULL << (PotatoSQLParser::K_CURRENT_DATE - 25))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIME - 25))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIMESTAMP - 25))
      | (1ULL << (PotatoSQLParser::K_DATABASE - 25))
      | (1ULL << (PotatoSQLParser::K_DEFAULT - 25))
      | (1ULL << (PotatoSQLParser::K_DEFERRABLE - 25))
      | (1ULL << (PotatoSQLParser::K_DEFERRED - 25))
      | (1ULL << (PotatoSQLParser::K_DELETE - 25))
      | (1ULL << (PotatoSQLParser::K_DESC - 25))
      | (1ULL << (PotatoSQLParser::K_DETACH - 25))
      | (1ULL << (PotatoSQLParser::K_DISTINCT - 25))
      | (1ULL << (PotatoSQLParser::K_DROP - 25))
      | (1ULL << (PotatoSQLParser::K_EACH - 25))
      | (1ULL << (PotatoSQLParser::K_ELSE - 25))
      | (1ULL << (PotatoSQLParser::K_END - 25))
      | (1ULL << (PotatoSQLParser::K_ESCAPE - 25))
      | (1ULL << (PotatoSQLParser::K_EXCEPT - 25))
      | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 25))
      | (1ULL << (PotatoSQLParser::K_EXISTS - 25))
      | (1ULL << (PotatoSQLParser::K_EXPLAIN - 25))
      | (1ULL << (PotatoSQLParser::K_FAIL - 25))
      | (1ULL << (PotatoSQLParser::K_FOR - 25))
      | (1ULL << (PotatoSQLParser::K_FOREIGN - 25))
      | (1ULL << (PotatoSQLParser::K_FROM - 25))
      | (1ULL << (PotatoSQLParser::K_FULL - 25))
      | (1ULL << (PotatoSQLParser::K_GLOB - 25))
      | (1ULL << (PotatoSQLParser::K_GROUP - 25))
      | (1ULL << (PotatoSQLParser::K_HAVING - 25))
      | (1ULL << (PotatoSQLParser::K_IF - 25))
      | (1ULL << (PotatoSQLParser::K_IGNORE - 25))
      | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 25))
      | (1ULL << (PotatoSQLParser::K_IN - 25))
      | (1ULL << (PotatoSQLParser::K_INDEX - 25))
      | (1ULL << (PotatoSQLParser::K_INDEXED - 25))
      | (1ULL << (PotatoSQLParser::K_INITIALLY - 25))
      | (1ULL << (PotatoSQLParser::K_INNER - 25))
      | (1ULL << (PotatoSQLParser::K_INSERT - 25)))) != 0) || ((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (PotatoSQLParser::K_INSTEAD - 89))
      | (1ULL << (PotatoSQLParser::K_INTERSECT - 89))
      | (1ULL << (PotatoSQLParser::K_INTO - 89))
      | (1ULL << (PotatoSQLParser::K_IS - 89))
      | (1ULL << (PotatoSQLParser::K_ISNULL - 89))
      | (1ULL << (PotatoSQLParser::K_JOIN - 89))
      | (1ULL << (PotatoSQLParser::K_KEY - 89))
      | (1ULL << (PotatoSQLParser::K_LEFT - 89))
      | (1ULL << (PotatoSQLParser::K_LIKE - 89))
      | (1ULL << (PotatoSQLParser::K_LIMIT - 89))
      | (1ULL << (PotatoSQLParser::K_MATCH - 89))
      | (1ULL << (PotatoSQLParser::K_NATURAL - 89))
      | (1ULL << (PotatoSQLParser::K_NO - 89))
      | (1ULL << (PotatoSQLParser::K_NOT - 89))
      | (1ULL << (PotatoSQLParser::K_NOTNULL - 89))
      | (1ULL << (PotatoSQLParser::K_NULL - 89))
      | (1ULL << (PotatoSQLParser::K_OF - 89))
      | (1ULL << (PotatoSQLParser::K_OFFSET - 89))
      | (1ULL << (PotatoSQLParser::K_ON - 89))
      | (1ULL << (PotatoSQLParser::K_OR - 89))
      | (1ULL << (PotatoSQLParser::K_ORDER - 89))
      | (1ULL << (PotatoSQLParser::K_OUTER - 89))
      | (1ULL << (PotatoSQLParser::K_PLAN - 89))
      | (1ULL << (PotatoSQLParser::K_PRAGMA - 89))
      | (1ULL << (PotatoSQLParser::K_PRIMARY - 89))
      | (1ULL << (PotatoSQLParser::K_QUERY - 89))
      | (1ULL << (PotatoSQLParser::K_RAISE - 89))
      | (1ULL << (PotatoSQLParser::K_RECURSIVE - 89))
      | (1ULL << (PotatoSQLParser::K_REFERENCES - 89))
      | (1ULL << (PotatoSQLParser::K_REGEXP - 89))
      | (1ULL << (PotatoSQLParser::K_REINDEX - 89))
      | (1ULL << (PotatoSQLParser::K_RELEASE - 89))
      | (1ULL << (PotatoSQLParser::K_RENAME - 89))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 89))
      | (1ULL << (PotatoSQLParser::K_RESTRICT - 89))
      | (1ULL << (PotatoSQLParser::K_RIGHT - 89))
      | (1ULL << (PotatoSQLParser::K_ROLLBACK - 89))
      | (1ULL << (PotatoSQLParser::K_ROW - 89))
      | (1ULL << (PotatoSQLParser::K_SAVEPOINT - 89))
      | (1ULL << (PotatoSQLParser::K_SELECT - 89))
      | (1ULL << (PotatoSQLParser::K_SET - 89))
      | (1ULL << (PotatoSQLParser::K_TABLE - 89))
      | (1ULL << (PotatoSQLParser::K_TEMP - 89))
      | (1ULL << (PotatoSQLParser::K_TEMPORARY - 89))
      | (1ULL << (PotatoSQLParser::K_THEN - 89))
      | (1ULL << (PotatoSQLParser::K_TO - 89))
      | (1ULL << (PotatoSQLParser::K_TRANSACTION - 89))
      | (1ULL << (PotatoSQLParser::K_TRIGGER - 89))
      | (1ULL << (PotatoSQLParser::K_UNION - 89))
      | (1ULL << (PotatoSQLParser::K_UNIQUE - 89))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 89))
      | (1ULL << (PotatoSQLParser::K_USING - 89))
      | (1ULL << (PotatoSQLParser::K_VACUUM - 89))
      | (1ULL << (PotatoSQLParser::K_VALUES - 89))
      | (1ULL << (PotatoSQLParser::K_VIEW - 89))
      | (1ULL << (PotatoSQLParser::K_VIRTUAL - 89))
      | (1ULL << (PotatoSQLParser::K_WHEN - 89))
      | (1ULL << (PotatoSQLParser::K_WHERE - 89))
      | (1ULL << (PotatoSQLParser::K_WITH - 89))
      | (1ULL << (PotatoSQLParser::K_WITHOUT - 89)))) != 0))) {
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

void PotatoSQLParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void PotatoSQLParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any PotatoSQLParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::NameContext* PotatoSQLParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 136, PotatoSQLParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1635);
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

void PotatoSQLParser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void PotatoSQLParser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}


antlrcpp::Any PotatoSQLParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Function_nameContext* PotatoSQLParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 138, PotatoSQLParser::RuleFunction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1637);
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

void PotatoSQLParser::Database_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDatabase_name(this);
}

void PotatoSQLParser::Database_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDatabase_name(this);
}


antlrcpp::Any PotatoSQLParser::Database_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDatabase_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Database_nameContext* PotatoSQLParser::database_name() {
  Database_nameContext *_localctx = _tracker.createInstance<Database_nameContext>(_ctx, getState());
  enterRule(_localctx, 140, PotatoSQLParser::RuleDatabase_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1639);
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

void PotatoSQLParser::Schema_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSchema_name(this);
}

void PotatoSQLParser::Schema_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSchema_name(this);
}


antlrcpp::Any PotatoSQLParser::Schema_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSchema_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Schema_nameContext* PotatoSQLParser::schema_name() {
  Schema_nameContext *_localctx = _tracker.createInstance<Schema_nameContext>(_ctx, getState());
  enterRule(_localctx, 142, PotatoSQLParser::RuleSchema_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1641);
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

void PotatoSQLParser::Table_function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_function_name(this);
}

void PotatoSQLParser::Table_function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_function_name(this);
}


antlrcpp::Any PotatoSQLParser::Table_function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_function_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_function_nameContext* PotatoSQLParser::table_function_name() {
  Table_function_nameContext *_localctx = _tracker.createInstance<Table_function_nameContext>(_ctx, getState());
  enterRule(_localctx, 144, PotatoSQLParser::RuleTable_function_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1643);
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

void PotatoSQLParser::Table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_name(this);
}

void PotatoSQLParser::Table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_name(this);
}


antlrcpp::Any PotatoSQLParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 146, PotatoSQLParser::RuleTable_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1645);
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

void PotatoSQLParser::Table_or_index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_index_name(this);
}

void PotatoSQLParser::Table_or_index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_index_name(this);
}


antlrcpp::Any PotatoSQLParser::Table_or_index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_or_index_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_or_index_nameContext* PotatoSQLParser::table_or_index_name() {
  Table_or_index_nameContext *_localctx = _tracker.createInstance<Table_or_index_nameContext>(_ctx, getState());
  enterRule(_localctx, 148, PotatoSQLParser::RuleTable_or_index_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1647);
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

void PotatoSQLParser::New_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew_table_name(this);
}

void PotatoSQLParser::New_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew_table_name(this);
}


antlrcpp::Any PotatoSQLParser::New_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitNew_table_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::New_table_nameContext* PotatoSQLParser::new_table_name() {
  New_table_nameContext *_localctx = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 150, PotatoSQLParser::RuleNew_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1649);
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

void PotatoSQLParser::Column_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_name(this);
}

void PotatoSQLParser::Column_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_name(this);
}


antlrcpp::Any PotatoSQLParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitColumn_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Column_nameContext* PotatoSQLParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 152, PotatoSQLParser::RuleColumn_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1651);
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

void PotatoSQLParser::Collation_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollation_name(this);
}

void PotatoSQLParser::Collation_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollation_name(this);
}


antlrcpp::Any PotatoSQLParser::Collation_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitCollation_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Collation_nameContext* PotatoSQLParser::collation_name() {
  Collation_nameContext *_localctx = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
  enterRule(_localctx, 154, PotatoSQLParser::RuleCollation_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1653);
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

void PotatoSQLParser::Foreign_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_table(this);
}

void PotatoSQLParser::Foreign_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_table(this);
}


antlrcpp::Any PotatoSQLParser::Foreign_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitForeign_table(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Foreign_tableContext* PotatoSQLParser::foreign_table() {
  Foreign_tableContext *_localctx = _tracker.createInstance<Foreign_tableContext>(_ctx, getState());
  enterRule(_localctx, 156, PotatoSQLParser::RuleForeign_table);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1655);
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

void PotatoSQLParser::Index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_name(this);
}

void PotatoSQLParser::Index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_name(this);
}


antlrcpp::Any PotatoSQLParser::Index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitIndex_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Index_nameContext* PotatoSQLParser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 158, PotatoSQLParser::RuleIndex_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1657);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trigger_nameContext ------------------------------------------------------------------

PotatoSQLParser::Trigger_nameContext::Trigger_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Trigger_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Trigger_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleTrigger_name;
}

void PotatoSQLParser::Trigger_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrigger_name(this);
}

void PotatoSQLParser::Trigger_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrigger_name(this);
}


antlrcpp::Any PotatoSQLParser::Trigger_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTrigger_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Trigger_nameContext* PotatoSQLParser::trigger_name() {
  Trigger_nameContext *_localctx = _tracker.createInstance<Trigger_nameContext>(_ctx, getState());
  enterRule(_localctx, 160, PotatoSQLParser::RuleTrigger_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1659);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- View_nameContext ------------------------------------------------------------------

PotatoSQLParser::View_nameContext::View_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::View_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::View_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleView_name;
}

void PotatoSQLParser::View_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterView_name(this);
}

void PotatoSQLParser::View_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitView_name(this);
}


antlrcpp::Any PotatoSQLParser::View_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitView_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::View_nameContext* PotatoSQLParser::view_name() {
  View_nameContext *_localctx = _tracker.createInstance<View_nameContext>(_ctx, getState());
  enterRule(_localctx, 162, PotatoSQLParser::RuleView_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1661);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_nameContext ------------------------------------------------------------------

PotatoSQLParser::Module_nameContext::Module_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::Module_nameContext::any_name() {
  return getRuleContext<PotatoSQLParser::Any_nameContext>(0);
}


size_t PotatoSQLParser::Module_nameContext::getRuleIndex() const {
  return PotatoSQLParser::RuleModule_name;
}

void PotatoSQLParser::Module_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_name(this);
}

void PotatoSQLParser::Module_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_name(this);
}


antlrcpp::Any PotatoSQLParser::Module_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitModule_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Module_nameContext* PotatoSQLParser::module_name() {
  Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, getState());
  enterRule(_localctx, 164, PotatoSQLParser::RuleModule_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1663);
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

void PotatoSQLParser::Pragma_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_name(this);
}

void PotatoSQLParser::Pragma_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_name(this);
}


antlrcpp::Any PotatoSQLParser::Pragma_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitPragma_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Pragma_nameContext* PotatoSQLParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 166, PotatoSQLParser::RulePragma_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1665);
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

void PotatoSQLParser::Savepoint_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_name(this);
}

void PotatoSQLParser::Savepoint_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_name(this);
}


antlrcpp::Any PotatoSQLParser::Savepoint_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitSavepoint_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Savepoint_nameContext* PotatoSQLParser::savepoint_name() {
  Savepoint_nameContext *_localctx = _tracker.createInstance<Savepoint_nameContext>(_ctx, getState());
  enterRule(_localctx, 168, PotatoSQLParser::RuleSavepoint_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1667);
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

void PotatoSQLParser::Table_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_alias(this);
}

void PotatoSQLParser::Table_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_alias(this);
}


antlrcpp::Any PotatoSQLParser::Table_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTable_alias(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Table_aliasContext* PotatoSQLParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 170, PotatoSQLParser::RuleTable_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1675);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1669);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1670);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 3);
        setState(1671);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1672);
        table_alias();
        setState(1673);
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

void PotatoSQLParser::Transaction_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransaction_name(this);
}

void PotatoSQLParser::Transaction_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransaction_name(this);
}


antlrcpp::Any PotatoSQLParser::Transaction_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitTransaction_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 172, PotatoSQLParser::RuleTransaction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1677);
    any_name();
   
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

void PotatoSQLParser::Any_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_name(this);
}

void PotatoSQLParser::Any_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_name(this);
}


antlrcpp::Any PotatoSQLParser::Any_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitAny_name(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Any_nameContext* PotatoSQLParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 174, PotatoSQLParser::RuleAny_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1686);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1679);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::K_ABORT:
      case PotatoSQLParser::K_ACTION:
      case PotatoSQLParser::K_ADD:
      case PotatoSQLParser::K_AFTER:
      case PotatoSQLParser::K_ALL:
      case PotatoSQLParser::K_ALTER:
      case PotatoSQLParser::K_ANALYZE:
      case PotatoSQLParser::K_AND:
      case PotatoSQLParser::K_AS:
      case PotatoSQLParser::K_ASC:
      case PotatoSQLParser::K_ATTACH:
      case PotatoSQLParser::K_AUTOINCREMENT:
      case PotatoSQLParser::K_BEFORE:
      case PotatoSQLParser::K_BEGIN:
      case PotatoSQLParser::K_BETWEEN:
      case PotatoSQLParser::K_BY:
      case PotatoSQLParser::K_CASCADE:
      case PotatoSQLParser::K_CASE:
      case PotatoSQLParser::K_CAST:
      case PotatoSQLParser::K_CHECK:
      case PotatoSQLParser::K_COLLATE:
      case PotatoSQLParser::K_COLUMN:
      case PotatoSQLParser::K_COMMIT:
      case PotatoSQLParser::K_CONFLICT:
      case PotatoSQLParser::K_CONSTRAINT:
      case PotatoSQLParser::K_CREATE:
      case PotatoSQLParser::K_CROSS:
      case PotatoSQLParser::K_CURRENT_DATE:
      case PotatoSQLParser::K_CURRENT_TIME:
      case PotatoSQLParser::K_CURRENT_TIMESTAMP:
      case PotatoSQLParser::K_DATABASE:
      case PotatoSQLParser::K_DEFAULT:
      case PotatoSQLParser::K_DEFERRABLE:
      case PotatoSQLParser::K_DEFERRED:
      case PotatoSQLParser::K_DELETE:
      case PotatoSQLParser::K_DESC:
      case PotatoSQLParser::K_DETACH:
      case PotatoSQLParser::K_DISTINCT:
      case PotatoSQLParser::K_DROP:
      case PotatoSQLParser::K_EACH:
      case PotatoSQLParser::K_ELSE:
      case PotatoSQLParser::K_END:
      case PotatoSQLParser::K_ESCAPE:
      case PotatoSQLParser::K_EXCEPT:
      case PotatoSQLParser::K_EXCLUSIVE:
      case PotatoSQLParser::K_EXISTS:
      case PotatoSQLParser::K_EXPLAIN:
      case PotatoSQLParser::K_FAIL:
      case PotatoSQLParser::K_FOR:
      case PotatoSQLParser::K_FOREIGN:
      case PotatoSQLParser::K_FROM:
      case PotatoSQLParser::K_FULL:
      case PotatoSQLParser::K_GLOB:
      case PotatoSQLParser::K_GROUP:
      case PotatoSQLParser::K_HAVING:
      case PotatoSQLParser::K_IF:
      case PotatoSQLParser::K_IGNORE:
      case PotatoSQLParser::K_IMMEDIATE:
      case PotatoSQLParser::K_IN:
      case PotatoSQLParser::K_INDEX:
      case PotatoSQLParser::K_INDEXED:
      case PotatoSQLParser::K_INITIALLY:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_INSERT:
      case PotatoSQLParser::K_INSTEAD:
      case PotatoSQLParser::K_INTERSECT:
      case PotatoSQLParser::K_INTO:
      case PotatoSQLParser::K_IS:
      case PotatoSQLParser::K_ISNULL:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_KEY:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_LIKE:
      case PotatoSQLParser::K_LIMIT:
      case PotatoSQLParser::K_MATCH:
      case PotatoSQLParser::K_NATURAL:
      case PotatoSQLParser::K_NO:
      case PotatoSQLParser::K_NOT:
      case PotatoSQLParser::K_NOTNULL:
      case PotatoSQLParser::K_NULL:
      case PotatoSQLParser::K_OF:
      case PotatoSQLParser::K_OFFSET:
      case PotatoSQLParser::K_ON:
      case PotatoSQLParser::K_OR:
      case PotatoSQLParser::K_ORDER:
      case PotatoSQLParser::K_OUTER:
      case PotatoSQLParser::K_PLAN:
      case PotatoSQLParser::K_PRAGMA:
      case PotatoSQLParser::K_PRIMARY:
      case PotatoSQLParser::K_QUERY:
      case PotatoSQLParser::K_RAISE:
      case PotatoSQLParser::K_RECURSIVE:
      case PotatoSQLParser::K_REFERENCES:
      case PotatoSQLParser::K_REGEXP:
      case PotatoSQLParser::K_REINDEX:
      case PotatoSQLParser::K_RELEASE:
      case PotatoSQLParser::K_RENAME:
      case PotatoSQLParser::K_REPLACE:
      case PotatoSQLParser::K_RESTRICT:
      case PotatoSQLParser::K_RIGHT:
      case PotatoSQLParser::K_ROLLBACK:
      case PotatoSQLParser::K_ROW:
      case PotatoSQLParser::K_SAVEPOINT:
      case PotatoSQLParser::K_SELECT:
      case PotatoSQLParser::K_SET:
      case PotatoSQLParser::K_TABLE:
      case PotatoSQLParser::K_TEMP:
      case PotatoSQLParser::K_TEMPORARY:
      case PotatoSQLParser::K_THEN:
      case PotatoSQLParser::K_TO:
      case PotatoSQLParser::K_TRANSACTION:
      case PotatoSQLParser::K_TRIGGER:
      case PotatoSQLParser::K_UNION:
      case PotatoSQLParser::K_UNIQUE:
      case PotatoSQLParser::K_UPDATE:
      case PotatoSQLParser::K_USING:
      case PotatoSQLParser::K_VACUUM:
      case PotatoSQLParser::K_VALUES:
      case PotatoSQLParser::K_VIEW:
      case PotatoSQLParser::K_VIRTUAL:
      case PotatoSQLParser::K_WHEN:
      case PotatoSQLParser::K_WHERE:
      case PotatoSQLParser::K_WITH:
      case PotatoSQLParser::K_WITHOUT: {
        enterOuterAlt(_localctx, 2);
        setState(1680);
        keyword();
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1681);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(1682);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1683);
        any_name();
        setState(1684);
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

bool PotatoSQLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 43: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "main", "error", "sql_stmt_list", "sql_stmt", "alter_table_stmt", "analyze_stmt", 
  "attach_stmt", "begin_stmt", "commit_stmt", "compound_select_stmt", "create_index_stmt", 
  "create_table_stmt", "create_trigger_stmt", "create_view_stmt", "create_virtual_table_stmt", 
  "delete_stmt", "delete_stmt_limited", "detach_stmt", "drop_index_stmt", 
  "drop_table_stmt", "drop_trigger_stmt", "drop_view_stmt", "factored_select_stmt", 
  "insert_prefix", "insert_tuple", "insert_tuples", "insert_columns", "insert_stmt", 
  "pragma_stmt", "reindex_stmt", "release_stmt", "rollback_stmt", "savepoint_stmt", 
  "simple_select_stmt", "select_stmt", "select_or_values", "update_stmt", 
  "update_stmt_limited", "vacuum_stmt", "column_def", "type_name", "column_constraint", 
  "conflict_clause", "expr", "foreign_key_clause", "raise_function", "indexed_column", 
  "table_constraint", "with_clause", "qualified_table_name", "ordering_term", 
  "pragma_value", "common_table_expression", "result_column", "table_or_subquery", 
  "join_clause", "join_operator", "join_constraint", "column_list", "select_core", 
  "compound_operator", "signed_number", "literal_value", "unary_operator", 
  "error_message", "module_argument", "column_alias", "keyword", "name", 
  "function_name", "database_name", "schema_name", "table_function_name", 
  "table_name", "table_or_index_name", "new_table_name", "column_name", 
  "collation_name", "foreign_table", "index_name", "trigger_name", "view_name", 
  "module_name", "pragma_name", "savepoint_name", "table_alias", "transaction_name", 
  "any_name"
};

std::vector<std::string> PotatoSQLParser::_literalNames = {
  "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", "'~'", 
  "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> PotatoSQLParser::_symbolicNames = {
  "", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", "ASSIGN", "STAR", 
  "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", "GT2", "AMP", 
  "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", "K_ABORT", 
  "K_ACTION", "K_ADD", "K_AFTER", "K_ALL", "K_ALTER", "K_ANALYZE", "K_AND", 
  "K_AS", "K_ASC", "K_ATTACH", "K_AUTOINCREMENT", "K_BEFORE", "K_BEGIN", 
  "K_BETWEEN", "K_BY", "K_CASCADE", "K_CASE", "K_CAST", "K_CHECK", "K_COLLATE", 
  "K_COLUMN", "K_COMMIT", "K_CONFLICT", "K_CONSTRAINT", "K_CREATE", "K_CROSS", 
  "K_CURRENT_DATE", "K_CURRENT_TIME", "K_CURRENT_TIMESTAMP", "K_DATABASE", 
  "K_DEFAULT", "K_DEFERRABLE", "K_DEFERRED", "K_DELETE", "K_DESC", "K_DETACH", 
  "K_DISTINCT", "K_DROP", "K_EACH", "K_ELSE", "K_END", "K_ESCAPE", "K_EXCEPT", 
  "K_EXCLUSIVE", "K_EXISTS", "K_EXPLAIN", "K_FAIL", "K_FOR", "K_FOREIGN", 
  "K_FROM", "K_FULL", "K_GLOB", "K_GROUP", "K_HAVING", "K_IF", "K_IGNORE", 
  "K_IMMEDIATE", "K_IN", "K_INDEX", "K_INDEXED", "K_INITIALLY", "K_INNER", 
  "K_INSERT", "K_INSTEAD", "K_INTERSECT", "K_INTO", "K_IS", "K_ISNULL", 
  "K_JOIN", "K_KEY", "K_LEFT", "K_LIKE", "K_LIMIT", "K_MATCH", "K_NATURAL", 
  "K_NO", "K_NOT", "K_NOTNULL", "K_NULL", "K_OF", "K_OFFSET", "K_ON", "K_OR", 
  "K_ORDER", "K_OUTER", "K_PLAN", "K_PRAGMA", "K_PRIMARY", "K_QUERY", "K_RAISE", 
  "K_RECURSIVE", "K_REFERENCES", "K_REGEXP", "K_REINDEX", "K_RELEASE", "K_RENAME", 
  "K_REPLACE", "K_RESTRICT", "K_RIGHT", "K_ROLLBACK", "K_ROW", "K_SAVEPOINT", 
  "K_SELECT", "K_SET", "K_TABLE", "K_TEMP", "K_TEMPORARY", "K_THEN", "K_TO", 
  "K_TRANSACTION", "K_TRIGGER", "K_UNION", "K_UNIQUE", "K_UPDATE", "K_USING", 
  "K_VACUUM", "K_VALUES", "K_VIEW", "K_VIRTUAL", "K_WHEN", "K_WHERE", "K_WITH", 
  "K_WITHOUT", "IDENTIFIER", "NUMERIC_LITERAL", "BIND_PARAMETER", "STRING_LITERAL", 
  "BLOB_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
  "UNEXPECTED_CHAR"
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
       0x3, 0x9f, 0x69b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xb5, 0xa, 0x2, 0xc, 0x2, 
       0xe, 0x2, 0xb8, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x4, 0x7, 0x4, 0xc0, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
       0xc3, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0xc7, 0xa, 0x4, 0xd, 
       0x4, 0xe, 0x4, 0xc8, 0x3, 0x4, 0x7, 0x4, 0xcc, 0xa, 0x4, 0xc, 0x4, 
       0xe, 0x4, 0xcf, 0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 0xd2, 0xa, 0x4, 0xc, 
       0x4, 0xe, 0x4, 0xd5, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
       0x5, 0xda, 0xa, 0x5, 0x5, 0x5, 0xdc, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xfc, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x103, 0xa, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x10b, 
       0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x10e, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x117, 
       0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x11b, 0xa, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x123, 
       0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x127, 0xa, 0x9, 0x5, 0x9, 
       0x129, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x12e, 0xa, 
       0xa, 0x5, 0xa, 0x130, 0xa, 0xa, 0x3, 0xb, 0x5, 0xb, 0x133, 0xa, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x138, 0xa, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x5, 0xb, 0x13c, 0xa, 0xb, 0x3, 0xb, 0x6, 0xb, 0x13f, 0xa, 
       0xb, 0xd, 0xb, 0xe, 0xb, 0x140, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x7, 0xb, 0x148, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x14b, 
       0xb, 0xb, 0x5, 0xb, 0x14d, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x5, 0xb, 0x153, 0xa, 0xb, 0x5, 0xb, 0x155, 0xa, 0xb, 0x3, 
       0xc, 0x3, 0xc, 0x5, 0xc, 0x159, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x5, 0xc, 0x15f, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x5, 0xc, 0x164, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x16d, 0xa, 0xc, 0xc, 
       0xc, 0xe, 0xc, 0x170, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
       0xc, 0x175, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x179, 0xa, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x17f, 0xa, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x184, 0xa, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x18b, 0xa, 0xd, 
       0xc, 0xd, 0xe, 0xd, 0x18e, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
       0x192, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x195, 0xb, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x5, 0xd, 0x19a, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
       0xd, 0x19e, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1a2, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1a8, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1ad, 0xa, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1b4, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x7, 0xe, 0x1bd, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x1c0, 0xb, 0xe, 
       0x5, 0xe, 0x1c2, 0xa, 0xe, 0x5, 0xe, 0x1c4, 0xa, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1ca, 0xa, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1d0, 0xa, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x5, 0xe, 0x1d4, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x5, 0xe, 0x1db, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x6, 
       0xe, 0x1df, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x1e0, 0x3, 0xe, 0x3, 0xe, 
       0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1e7, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1ed, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x5, 0xf, 0x1f2, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
       0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x5, 0x10, 0x1fe, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
       0x10, 0x5, 0x10, 0x203, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x20c, 0xa, 
       0x10, 0xc, 0x10, 0xe, 0x10, 0x20f, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x5, 0x10, 0x213, 0xa, 0x10, 0x3, 0x11, 0x5, 0x11, 0x216, 0xa, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0x21d, 0xa, 0x11, 0x3, 0x12, 0x5, 0x12, 0x220, 0xa, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x227, 0xa, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
       0x12, 0x22e, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x231, 0xb, 0x12, 0x5, 
       0x12, 0x233, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x5, 0x12, 0x239, 0xa, 0x12, 0x5, 0x12, 0x23b, 0xa, 0x12, 0x3, 0x13, 
       0x3, 0x13, 0x5, 0x13, 0x23f, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x247, 0xa, 0x14, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x24c, 0xa, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 
       0x15, 0x254, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
       0x259, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x5, 0x16, 0x261, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x16, 0x5, 0x16, 0x266, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x26e, 0xa, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x273, 0xa, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x18, 0x5, 0x18, 0x278, 0xa, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x27e, 0xa, 0x18, 0xc, 
       0x18, 0xe, 0x18, 0x281, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x288, 0xa, 0x18, 0xc, 0x18, 0xe, 
       0x18, 0x28b, 0xb, 0x18, 0x5, 0x18, 0x28d, 0xa, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x293, 0xa, 0x18, 0x5, 0x18, 
       0x295, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x5, 0x19, 0x2a8, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x7, 0x1a, 0x2ae, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x2b1, 
       0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
       0x7, 0x1b, 0x2b8, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x2bb, 0xb, 0x1b, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x2c1, 0xa, 
       0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2c4, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x3, 0x1d, 0x5, 0x1d, 0x2c9, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x2d0, 0xa, 0x1d, 0x3, 0x1d, 
       0x3, 0x1d, 0x5, 0x1d, 0x2d4, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
       0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x2db, 0xa, 0x1d, 0x3, 0x1e, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x2e1, 0xa, 0x1e, 0x3, 
       0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x5, 0x1e, 0x2ea, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2f1, 0xa, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x2f5, 0xa, 0x1f, 0x5, 0x1f, 0x2f7, 0xa, 0x1f, 0x3, 
       0x20, 0x3, 0x20, 0x5, 0x20, 0x2fb, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x302, 0xa, 0x21, 0x5, 
       0x21, 0x304, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x308, 0xa, 
       0x21, 0x3, 0x21, 0x5, 0x21, 0x30b, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x23, 0x5, 0x23, 0x311, 0xa, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x319, 
       0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x31c, 0xb, 0x23, 0x5, 0x23, 0x31e, 
       0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 
       0x324, 0xa, 0x23, 0x5, 0x23, 0x326, 0xa, 0x23, 0x3, 0x24, 0x5, 0x24, 
       0x329, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 
       0x24, 0x32f, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x332, 0xb, 0x24, 0x3, 
       0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x339, 
       0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x33c, 0xb, 0x24, 0x5, 0x24, 0x33e, 
       0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
       0x344, 0xa, 0x24, 0x5, 0x24, 0x346, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 
       0x5, 0x25, 0x34a, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 
       0x25, 0x34f, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x352, 0xb, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x358, 0xa, 0x25, 
       0xc, 0x25, 0xe, 0x25, 0x35b, 0xb, 0x25, 0x3, 0x25, 0x5, 0x25, 0x35e, 
       0xa, 0x25, 0x5, 0x25, 0x360, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 
       0x25, 0x364, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x7, 0x25, 0x36b, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x36e, 
       0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x372, 0xa, 0x25, 0x5, 
       0x25, 0x374, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x7, 0x25, 0x37b, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x37e, 
       0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x3, 0x25, 0x7, 0x25, 0x386, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x389, 
       0xb, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x38d, 0xa, 0x25, 0xc, 
       0x25, 0xe, 0x25, 0x390, 0xb, 0x25, 0x5, 0x25, 0x392, 0xa, 0x25, 0x3, 
       0x26, 0x5, 0x26, 0x395, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
       0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x3a2, 0xa, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x3ae, 0xa, 0x26, 0xc, 0x26, 
       0xe, 0x26, 0x3b1, 0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x3b5, 
       0xa, 0x26, 0x3, 0x27, 0x5, 0x27, 0x3b8, 0xa, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x3c5, 0xa, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x3d1, 0xa, 
       0x27, 0xc, 0x27, 0xe, 0x27, 0x3d4, 0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x5, 0x27, 0x3d8, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x7, 0x27, 0x3df, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
       0x3e2, 0xb, 0x27, 0x5, 0x27, 0x3e4, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x3ea, 0xa, 0x27, 0x5, 0x27, 0x3ec, 
       0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
       0x3f2, 0xa, 0x29, 0x3, 0x29, 0x7, 0x29, 0x3f5, 0xa, 0x29, 0xc, 0x29, 
       0xe, 0x29, 0x3f8, 0xb, 0x29, 0x3, 0x2a, 0x6, 0x2a, 0x3fb, 0xa, 0x2a, 
       0xd, 0x2a, 0xe, 0x2a, 0x3fc, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x5, 0x2a, 0x409, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
       0x40d, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x412, 
       0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x416, 0xa, 0x2b, 0x3, 
       0x2b, 0x5, 0x2b, 0x419, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
       0x3, 0x2b, 0x5, 0x2b, 0x42b, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x5, 0x2b, 0x430, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x5, 0x2c, 0x435, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x43d, 0xa, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x442, 0xa, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
       0x2d, 0x44b, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 
       0x450, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x453, 0xb, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x456, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x466, 
       0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x469, 0xa, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x471, 
       0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x6, 0x2d, 0x478, 0xa, 0x2d, 0xd, 0x2d, 0xe, 0x2d, 0x479, 0x3, 0x2d, 
       0x3, 0x2d, 0x5, 0x2d, 0x47e, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x5, 0x2d, 0x483, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x4a0, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
       0x2d, 0x4a5, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x4ae, 0xa, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 
       0x2d, 0x4b6, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x4b9, 0xb, 0x2d, 0x5, 
       0x2d, 0x4bb, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x4c1, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x4c4, 0xa, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
       0x4cb, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 
       0x2d, 0x4d1, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x5, 0x2d, 0x4d8, 0xa, 0x2d, 0x7, 0x2d, 0x4da, 0xa, 0x2d, 
       0xc, 0x2d, 0xe, 0x2d, 0x4dd, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x4e5, 0xa, 0x2e, 
       0xc, 0x2e, 0xe, 0x2e, 0x4e8, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 
       0x2e, 0x4ec, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x5, 0x2e, 0x4f8, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x4fc, 
       0xa, 0x2e, 0x7, 0x2e, 0x4fe, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x501, 
       0xb, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x504, 0xa, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x50b, 0xa, 0x2e, 
       0x5, 0x2e, 0x50d, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x515, 0xa, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x51c, 0xa, 
       0x30, 0x3, 0x30, 0x5, 0x30, 0x51f, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 
       0x5, 0x31, 0x523, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
       0x31, 0x528, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x7, 0x31, 0x52e, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x531, 0xb, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x541, 0xa, 0x31, 0xc, 0x31, 0xe, 
       0x31, 0x544, 0xb, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 
       0x549, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x54d, 0xa, 0x32, 
       0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x552, 0xa, 0x32, 0xc, 
       0x32, 0xe, 0x32, 0x555, 0xb, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x5, 0x33, 0x55a, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
       0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x562, 0xa, 0x33, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x567, 0xa, 0x34, 0x3, 0x34, 0x5, 
       0x34, 0x56a, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 
       0x56f, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 
       0x36, 0x7, 0x36, 0x576, 0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x579, 0xb, 
       0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x57d, 0xa, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 
       0x58b, 0xa, 0x37, 0x3, 0x37, 0x5, 0x37, 0x58e, 0xa, 0x37, 0x5, 0x37, 
       0x590, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x595, 
       0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x599, 0xa, 0x38, 0x3, 
       0x38, 0x5, 0x38, 0x59c, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x5a3, 0xa, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x5, 0x38, 0x5a8, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x5af, 0xa, 0x38, 0xc, 
       0x38, 0xe, 0x38, 0x5b2, 0xb, 0x38, 0x5, 0x38, 0x5b4, 0xa, 0x38, 0x3, 
       0x38, 0x3, 0x38, 0x5, 0x38, 0x5b8, 0xa, 0x38, 0x3, 0x38, 0x5, 0x38, 
       0x5bb, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 
       0x38, 0x5c1, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x5c4, 0xb, 0x38, 0x3, 
       0x38, 0x5, 0x38, 0x5c7, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x5cf, 0xa, 0x38, 0x3, 
       0x38, 0x5, 0x38, 0x5d2, 0xa, 0x38, 0x5, 0x38, 0x5d4, 0xa, 0x38, 0x3, 
       0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x7, 0x39, 0x5db, 
       0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x5de, 0xb, 0x39, 0x3, 0x3a, 0x3, 
       0x3a, 0x5, 0x3a, 0x5e2, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 
       0x5e6, 0xa, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x5ea, 0xa, 0x3a, 
       0x3, 0x3a, 0x5, 0x3a, 0x5ed, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x7, 0x3b, 0x5f6, 
       0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x5f9, 0xb, 0x3b, 0x3, 0x3b, 0x3, 
       0x3b, 0x5, 0x3b, 0x5fd, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
       0x7, 0x3c, 0x602, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x605, 0xb, 0x3c, 
       0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x609, 0xa, 0x3d, 0x3, 0x3d, 0x3, 
       0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x610, 0xa, 0x3d, 
       0xc, 0x3d, 0xe, 0x3d, 0x613, 0xb, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x616, 
       0xa, 0x3d, 0x5, 0x3d, 0x618, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 
       0x3d, 0x61c, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x7, 0x3d, 0x623, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x626, 
       0xb, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x62a, 0xa, 0x3d, 0x5, 
       0x3d, 0x62c, 0xa, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x7, 0x3d, 0x633, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x636, 
       0xb, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 
       0x3, 0x3d, 0x7, 0x3d, 0x63e, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x641, 
       0xb, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 0x645, 0xa, 0x3d, 0xc, 
       0x3d, 0xe, 0x3d, 0x648, 0xb, 0x3d, 0x5, 0x3d, 0x64a, 0xa, 0x3d, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x651, 
       0xa, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x654, 0xa, 0x3f, 0x3, 0x3f, 0x3, 
       0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x42, 0x3, 
       0x42, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x660, 0xa, 0x43, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 
       0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 
       0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 
       0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 
       0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 
       0x3, 0x57, 0x5, 0x57, 0x68e, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 
       0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x5, 0x59, 0x699, 0xa, 0x59, 0x3, 0x59, 0x4, 0x18c, 0x3fc, 
       0x3, 0x58, 0x5a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
       0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
       0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
       0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
       0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 
       0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 
       0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 
       0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 
       0xb0, 0x2, 0x15, 0x5, 0x2, 0x3c, 0x3c, 0x47, 0x47, 0x54, 0x54, 0x4, 
       0x2, 0x31, 0x31, 0x44, 0x44, 0x4, 0x2, 0x7, 0x7, 0x6c, 0x6c, 0x3, 
       0x2, 0x85, 0x86, 0x4, 0x2, 0x1f, 0x1f, 0x40, 0x40, 0x4, 0x2, 0x24, 
       0x24, 0x3e, 0x3e, 0x7, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x53, 0x53, 0x7c, 
       0x7c, 0x7f, 0x7f, 0x4, 0x2, 0x9, 0x9, 0xe, 0xf, 0x3, 0x2, 0xa, 0xb, 
       0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 0x17, 0x4, 0x2, 0x8, 0x8, 0x18, 
       0x1a, 0x6, 0x2, 0x4f, 0x4f, 0x63, 0x63, 0x65, 0x65, 0x78, 0x78, 0x4, 
       0x2, 0x3d, 0x3d, 0x8d, 0x8d, 0x5, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x7f, 
       0x7f, 0x6, 0x2, 0x36, 0x38, 0x6a, 0x6a, 0x98, 0x98, 0x9a, 0x9b, 0x4, 
       0x2, 0xa, 0xc, 0x68, 0x68, 0x4, 0x2, 0x97, 0x97, 0x9a, 0x9a, 0x3, 
       0x2, 0x1b, 0x96, 0x2, 0x793, 0x2, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x4, 
       0xbb, 0x3, 0x2, 0x2, 0x2, 0x6, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x8, 0xdb, 
       0x3, 0x2, 0x2, 0x2, 0xa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xc, 0x10f, 0x3, 
       0x2, 0x2, 0x2, 0xe, 0x118, 0x3, 0x2, 0x2, 0x2, 0x10, 0x120, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x132, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0x156, 0x3, 0x2, 0x2, 0x2, 0x18, 0x176, 0x3, 
       0x2, 0x2, 0x2, 0x1a, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e4, 0x3, 
       0x2, 0x2, 0x2, 0x1e, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x20, 0x215, 0x3, 
       0x2, 0x2, 0x2, 0x22, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x23c, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0x242, 0x3, 0x2, 0x2, 0x2, 0x28, 0x24f, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x269, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x277, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2a7, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x2a9, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2b4, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x38, 0x2c8, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x2eb, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x40, 0x2fe, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x310, 0x3, 
       0x2, 0x2, 0x2, 0x46, 0x328, 0x3, 0x2, 0x2, 0x2, 0x48, 0x391, 0x3, 
       0x2, 0x2, 0x2, 0x4a, 0x394, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3b7, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x3ed, 0x3, 0x2, 0x2, 0x2, 0x50, 0x3ef, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x54, 0x40c, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x434, 0x3, 0x2, 0x2, 0x2, 0x58, 0x482, 0x3, 
       0x2, 0x2, 0x2, 0x5a, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x50e, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x518, 0x3, 0x2, 0x2, 0x2, 0x60, 0x522, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x64, 0x559, 0x3, 
       0x2, 0x2, 0x2, 0x66, 0x563, 0x3, 0x2, 0x2, 0x2, 0x68, 0x56e, 0x3, 
       0x2, 0x2, 0x2, 0x6a, 0x570, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x58f, 0x3, 
       0x2, 0x2, 0x2, 0x6e, 0x5d3, 0x3, 0x2, 0x2, 0x2, 0x70, 0x5d5, 0x3, 
       0x2, 0x2, 0x2, 0x72, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x74, 0x5fc, 0x3, 
       0x2, 0x2, 0x2, 0x76, 0x5fe, 0x3, 0x2, 0x2, 0x2, 0x78, 0x649, 0x3, 
       0x2, 0x2, 0x2, 0x7a, 0x650, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x653, 0x3, 
       0x2, 0x2, 0x2, 0x7e, 0x657, 0x3, 0x2, 0x2, 0x2, 0x80, 0x659, 0x3, 
       0x2, 0x2, 0x2, 0x82, 0x65b, 0x3, 0x2, 0x2, 0x2, 0x84, 0x65f, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x661, 0x3, 0x2, 0x2, 0x2, 0x88, 0x663, 0x3, 
       0x2, 0x2, 0x2, 0x8a, 0x665, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x667, 0x3, 
       0x2, 0x2, 0x2, 0x8e, 0x669, 0x3, 0x2, 0x2, 0x2, 0x90, 0x66b, 0x3, 
       0x2, 0x2, 0x2, 0x92, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x94, 0x66f, 0x3, 
       0x2, 0x2, 0x2, 0x96, 0x671, 0x3, 0x2, 0x2, 0x2, 0x98, 0x673, 0x3, 
       0x2, 0x2, 0x2, 0x9a, 0x675, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x677, 0x3, 
       0x2, 0x2, 0x2, 0x9e, 0x679, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x67b, 0x3, 
       0x2, 0x2, 0x2, 0xa2, 0x67d, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x67f, 0x3, 
       0x2, 0x2, 0x2, 0xa6, 0x681, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x683, 0x3, 
       0x2, 0x2, 0x2, 0xaa, 0x685, 0x3, 0x2, 0x2, 0x2, 0xac, 0x68d, 0x3, 
       0x2, 0x2, 0x2, 0xae, 0x68f, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x698, 0x3, 
       0x2, 0x2, 0x2, 0xb2, 0xb5, 0x5, 0x6, 0x4, 0x2, 0xb3, 0xb5, 0x5, 0x4, 
       0x3, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 
       0x2, 0xb5, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 
       0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x2, 0x2, 0x3, 0xba, 0x3, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x9f, 0x2, 0x2, 0xbc, 0xbd, 
       0x8, 0x3, 0x1, 0x2, 0xbd, 0x5, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x7, 
       0x3, 0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 
       0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 
       0x2, 0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 
       0xc4, 0xcd, 0x5, 0x8, 0x5, 0x2, 0xc5, 0xc7, 0x7, 0x3, 0x2, 0x2, 0xc6, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 
       0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 
       0x2, 0x2, 0x2, 0xca, 0xcc, 0x5, 0x8, 0x5, 0x2, 0xcb, 0xc6, 0x3, 0x2, 
       0x2, 0x2, 0xcc, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 
       0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd3, 0x3, 0x2, 0x2, 0x2, 
       0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 0x7, 0x3, 0x2, 0x2, 0xd1, 
       0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 
       0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x7, 0x3, 
       0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd9, 0x7, 0x49, 
       0x2, 0x2, 0xd7, 0xd8, 0x7, 0x74, 0x2, 0x2, 0xd8, 0xda, 0x7, 0x71, 
       0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 
       0x2, 0xda, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd6, 0x3, 0x2, 0x2, 0x2, 
       0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xdd, 
       0xfc, 0x5, 0xa, 0x6, 0x2, 0xde, 0xfc, 0x5, 0xc, 0x7, 0x2, 0xdf, 0xfc, 
       0x5, 0xe, 0x8, 0x2, 0xe0, 0xfc, 0x5, 0x10, 0x9, 0x2, 0xe1, 0xfc, 
       0x5, 0x12, 0xa, 0x2, 0xe2, 0xfc, 0x5, 0x14, 0xb, 0x2, 0xe3, 0xfc, 
       0x5, 0x16, 0xc, 0x2, 0xe4, 0xfc, 0x5, 0x18, 0xd, 0x2, 0xe5, 0xfc, 
       0x5, 0x1a, 0xe, 0x2, 0xe6, 0xfc, 0x5, 0x1c, 0xf, 0x2, 0xe7, 0xfc, 
       0x5, 0x1e, 0x10, 0x2, 0xe8, 0xfc, 0x5, 0x20, 0x11, 0x2, 0xe9, 0xfc, 
       0x5, 0x22, 0x12, 0x2, 0xea, 0xfc, 0x5, 0x24, 0x13, 0x2, 0xeb, 0xfc, 
       0x5, 0x26, 0x14, 0x2, 0xec, 0xfc, 0x5, 0x28, 0x15, 0x2, 0xed, 0xfc, 
       0x5, 0x2a, 0x16, 0x2, 0xee, 0xfc, 0x5, 0x2c, 0x17, 0x2, 0xef, 0xfc, 
       0x5, 0x2e, 0x18, 0x2, 0xf0, 0xfc, 0x5, 0x38, 0x1d, 0x2, 0xf1, 0xfc, 
       0x5, 0x3a, 0x1e, 0x2, 0xf2, 0xfc, 0x5, 0x3c, 0x1f, 0x2, 0xf3, 0xfc, 
       0x5, 0x3e, 0x20, 0x2, 0xf4, 0xfc, 0x5, 0x40, 0x21, 0x2, 0xf5, 0xfc, 
       0x5, 0x42, 0x22, 0x2, 0xf6, 0xfc, 0x5, 0x44, 0x23, 0x2, 0xf7, 0xfc, 
       0x5, 0x46, 0x24, 0x2, 0xf8, 0xfc, 0x5, 0x4a, 0x26, 0x2, 0xf9, 0xfc, 
       0x5, 0x4c, 0x27, 0x2, 0xfa, 0xfc, 0x5, 0x4e, 0x28, 0x2, 0xfb, 0xdd, 
       0x3, 0x2, 0x2, 0x2, 0xfb, 0xde, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xdf, 0x3, 
       0x2, 0x2, 0x2, 0xfb, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xe1, 0x3, 0x2, 
       0x2, 0x2, 0xfb, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xe3, 0x3, 0x2, 0x2, 
       0x2, 0xfb, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xe5, 0x3, 0x2, 0x2, 0x2, 
       0xfb, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xfb, 
       0xe8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xea, 
       0x3, 0x2, 0x2, 0x2, 0xfb, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xec, 0x3, 
       0x2, 0x2, 0x2, 0xfb, 0xed, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xfb, 0xef, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf0, 0x3, 0x2, 0x2, 
       0x2, 0xfb, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf2, 0x3, 0x2, 0x2, 0x2, 
       0xfb, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xfb, 
       0xf5, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf7, 
       0x3, 0x2, 0x2, 0x2, 0xfb, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xf9, 0x3, 
       0x2, 0x2, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x9, 0x3, 0x2, 
       0x2, 0x2, 0xfd, 0xfe, 0x7, 0x20, 0x2, 0x2, 0xfe, 0x102, 0x7, 0x84, 
       0x2, 0x2, 0xff, 0x100, 0x5, 0x8e, 0x48, 0x2, 0x100, 0x101, 0x7, 0x4, 
       0x2, 0x2, 0x101, 0x103, 0x3, 0x2, 0x2, 0x2, 0x102, 0xff, 0x3, 0x2, 
       0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 
       0x2, 0x2, 0x104, 0x10d, 0x5, 0x94, 0x4b, 0x2, 0x105, 0x106, 0x7, 
       0x7b, 0x2, 0x2, 0x106, 0x107, 0x7, 0x88, 0x2, 0x2, 0x107, 0x10e, 
       0x5, 0x98, 0x4d, 0x2, 0x108, 0x10a, 0x7, 0x1d, 0x2, 0x2, 0x109, 0x10b, 
       0x7, 0x30, 0x2, 0x2, 0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 
       0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 
       0x5, 0x50, 0x29, 0x2, 0x10d, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x108, 
       0x3, 0x2, 0x2, 0x2, 0x10e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x116, 
       0x7, 0x21, 0x2, 0x2, 0x110, 0x117, 0x5, 0x8e, 0x48, 0x2, 0x111, 0x117, 
       0x5, 0x96, 0x4c, 0x2, 0x112, 0x113, 0x5, 0x8e, 0x48, 0x2, 0x113, 
       0x114, 0x7, 0x4, 0x2, 0x2, 0x114, 0x115, 0x5, 0x96, 0x4c, 0x2, 0x115, 
       0x117, 0x3, 0x2, 0x2, 0x2, 0x116, 0x110, 0x3, 0x2, 0x2, 0x2, 0x116, 
       0x111, 0x3, 0x2, 0x2, 0x2, 0x116, 0x112, 0x3, 0x2, 0x2, 0x2, 0x116, 
       0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0xd, 0x3, 0x2, 0x2, 0x2, 0x118, 
       0x11a, 0x7, 0x25, 0x2, 0x2, 0x119, 0x11b, 0x7, 0x39, 0x2, 0x2, 0x11a, 
       0x119, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 
       0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x58, 0x2d, 0x2, 0x11d, 
       0x11e, 0x7, 0x23, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x8e, 0x48, 0x2, 0x11f, 
       0xf, 0x3, 0x2, 0x2, 0x2, 0x120, 0x122, 0x7, 0x28, 0x2, 0x2, 0x121, 
       0x123, 0x9, 0x2, 0x2, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x122, 
       0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x128, 0x3, 0x2, 0x2, 0x2, 0x124, 
       0x126, 0x7, 0x89, 0x2, 0x2, 0x125, 0x127, 0x5, 0xae, 0x58, 0x2, 0x126, 
       0x125, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 
       0x129, 0x3, 0x2, 0x2, 0x2, 0x128, 0x124, 0x3, 0x2, 0x2, 0x2, 0x128, 
       0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x11, 0x3, 0x2, 0x2, 0x2, 0x12a, 
       0x12f, 0x9, 0x3, 0x2, 0x2, 0x12b, 0x12d, 0x7, 0x89, 0x2, 0x2, 0x12c, 
       0x12e, 0x5, 0xae, 0x58, 0x2, 0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12d, 
       0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12f, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x130, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x131, 0x133, 0x5, 0x62, 0x32, 0x2, 0x132, 
       0x131, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 0x13e, 0x5, 0x78, 0x3d, 0x2, 0x135, 
       0x137, 0x7, 0x8b, 0x2, 0x2, 0x136, 0x138, 0x7, 0x1f, 0x2, 0x2, 0x137, 
       0x136, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 
       0x13c, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x7, 0x5c, 0x2, 0x2, 0x13a, 
       0x13c, 0x7, 0x46, 0x2, 0x2, 0x13b, 0x135, 0x3, 0x2, 0x2, 0x2, 0x13b, 
       0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 
       0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13f, 0x5, 0x78, 0x3d, 0x2, 0x13e, 
       0x13b, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
       0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 
       0x14c, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x7, 0x6f, 0x2, 0x2, 0x143, 
       0x144, 0x7, 0x2a, 0x2, 0x2, 0x144, 0x149, 0x5, 0x66, 0x34, 0x2, 0x145, 
       0x146, 0x7, 0x7, 0x2, 0x2, 0x146, 0x148, 0x5, 0x66, 0x34, 0x2, 0x147, 
       0x145, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 
       0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 
       0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 
       0x154, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x64, 0x2, 0x2, 0x14f, 
       0x152, 0x5, 0x58, 0x2d, 0x2, 0x150, 0x151, 0x9, 0x4, 0x2, 0x2, 0x151, 
       0x153, 0x5, 0x58, 0x2d, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x3, 0x2, 0x2, 0x2, 0x154, 
       0x14e, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x156, 0x158, 0x7, 0x34, 0x2, 0x2, 0x157, 
       0x159, 0x7, 0x8c, 0x2, 0x2, 0x158, 0x157, 0x3, 0x2, 0x2, 0x2, 0x158, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 
       0x15e, 0x7, 0x56, 0x2, 0x2, 0x15b, 0x15c, 0x7, 0x52, 0x2, 0x2, 0x15c, 
       0x15d, 0x7, 0x68, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x48, 0x2, 0x2, 0x15e, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15f, 
       0x163, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x5, 0x8e, 0x48, 0x2, 0x161, 
       0x162, 0x7, 0x4, 0x2, 0x2, 0x162, 0x164, 0x3, 0x2, 0x2, 0x2, 0x163, 
       0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x5, 0xa0, 0x51, 0x2, 0x166, 
       0x167, 0x7, 0x6d, 0x2, 0x2, 0x167, 0x168, 0x5, 0x94, 0x4b, 0x2, 0x168, 
       0x169, 0x7, 0x5, 0x2, 0x2, 0x169, 0x16e, 0x5, 0x5e, 0x30, 0x2, 0x16a, 
       0x16b, 0x7, 0x7, 0x2, 0x2, 0x16b, 0x16d, 0x5, 0x5e, 0x30, 0x2, 0x16c, 
       0x16a, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16e, 
       0x16c, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x171, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 
       0x174, 0x7, 0x6, 0x2, 0x2, 0x172, 0x173, 0x7, 0x94, 0x2, 0x2, 0x173, 
       0x175, 0x5, 0x58, 0x2d, 0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 
       0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x17, 0x3, 0x2, 0x2, 0x2, 0x176, 
       0x178, 0x7, 0x34, 0x2, 0x2, 0x177, 0x179, 0x9, 0x5, 0x2, 0x2, 0x178, 
       0x177, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 
       0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17e, 0x7, 0x84, 0x2, 0x2, 0x17b, 
       0x17c, 0x7, 0x52, 0x2, 0x2, 0x17c, 0x17d, 0x7, 0x68, 0x2, 0x2, 0x17d, 
       0x17f, 0x7, 0x48, 0x2, 0x2, 0x17e, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17e, 
       0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x183, 0x3, 0x2, 0x2, 0x2, 0x180, 
       0x181, 0x5, 0x8e, 0x48, 0x2, 0x181, 0x182, 0x7, 0x4, 0x2, 0x2, 0x182, 
       0x184, 0x3, 0x2, 0x2, 0x2, 0x183, 0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 
       0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 
       0x19d, 0x5, 0x94, 0x4b, 0x2, 0x186, 0x187, 0x7, 0x5, 0x2, 0x2, 0x187, 
       0x18c, 0x5, 0x50, 0x29, 0x2, 0x188, 0x189, 0x7, 0x7, 0x2, 0x2, 0x189, 
       0x18b, 0x5, 0x50, 0x29, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 
       0x18e, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18c, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x193, 0x3, 0x2, 0x2, 0x2, 0x18e, 
       0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x7, 0x2, 0x2, 0x190, 
       0x192, 0x5, 0x60, 0x31, 0x2, 0x191, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x192, 
       0x195, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x194, 0x3, 0x2, 0x2, 0x2, 0x194, 0x196, 0x3, 0x2, 0x2, 0x2, 0x195, 
       0x193, 0x3, 0x2, 0x2, 0x2, 0x196, 0x199, 0x7, 0x6, 0x2, 0x2, 0x197, 
       0x198, 0x7, 0x96, 0x2, 0x2, 0x198, 0x19a, 0x7, 0x97, 0x2, 0x2, 0x199, 
       0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 
       0x19e, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x23, 0x2, 0x2, 0x19c, 
       0x19e, 0x5, 0x46, 0x24, 0x2, 0x19d, 0x186, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a1, 0x7, 0x34, 0x2, 0x2, 0x1a0, 0x1a2, 0x9, 0x5, 0x2, 0x2, 0x1a1, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
       0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a7, 0x7, 0x8a, 0x2, 0x2, 0x1a4, 
       0x1a5, 0x7, 0x52, 0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x68, 0x2, 0x2, 0x1a6, 
       0x1a8, 0x7, 0x48, 0x2, 0x2, 0x1a7, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a7, 
       0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x5, 0x8e, 0x48, 0x2, 0x1aa, 0x1ab, 0x7, 0x4, 0x2, 0x2, 0x1ab, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ae, 
       0x1b3, 0x5, 0xa2, 0x52, 0x2, 0x1af, 0x1b4, 0x7, 0x27, 0x2, 0x2, 0x1b0, 
       0x1b4, 0x7, 0x1e, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x5b, 0x2, 0x2, 0x1b2, 
       0x1b4, 0x7, 0x6b, 0x2, 0x2, 0x1b3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
       0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
       0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
       0x1c4, 0x7, 0x3d, 0x2, 0x2, 0x1b6, 0x1c4, 0x7, 0x5a, 0x2, 0x2, 0x1b7, 
       0x1c1, 0x7, 0x8d, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x6b, 0x2, 0x2, 0x1b9, 
       0x1be, 0x5, 0x9a, 0x4e, 0x2, 0x1ba, 0x1bb, 0x7, 0x7, 0x2, 0x2, 0x1bb, 
       0x1bd, 0x5, 0x9a, 0x4e, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
       0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1be, 
       0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
       0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1c1, 
       0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
       0x1c9, 0x7, 0x6d, 0x2, 0x2, 0x1c6, 0x1c7, 0x5, 0x8e, 0x48, 0x2, 0x1c7, 
       0x1c8, 0x7, 0x4, 0x2, 0x2, 0x1c8, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cf, 0x5, 0x94, 0x4b, 0x2, 0x1cc, 
       0x1cd, 0x7, 0x4b, 0x2, 0x2, 0x1cd, 0x1ce, 0x7, 0x42, 0x2, 0x2, 0x1ce, 
       0x1d0, 0x7, 0x80, 0x2, 0x2, 0x1cf, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 
       0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d1, 
       0x1d2, 0x7, 0x93, 0x2, 0x2, 0x1d2, 0x1d4, 0x5, 0x58, 0x2d, 0x2, 0x1d3, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1de, 0x7, 0x28, 0x2, 0x2, 0x1d6, 
       0x1db, 0x5, 0x4a, 0x26, 0x2, 0x1d7, 0x1db, 0x5, 0x38, 0x1d, 0x2, 
       0x1d8, 0x1db, 0x5, 0x20, 0x11, 0x2, 0x1d9, 0x1db, 0x5, 0x46, 0x24, 
       0x2, 0x1da, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d7, 0x3, 0x2, 0x2, 
       0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d9, 0x3, 0x2, 0x2, 
       0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x7, 0x3, 0x2, 
       0x2, 0x1dd, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1da, 0x3, 0x2, 0x2, 
       0x2, 0x1df, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 
       0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x3, 0x2, 0x2, 
       0x2, 0x1e2, 0x1e3, 0x7, 0x44, 0x2, 0x2, 0x1e3, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0x1e4, 0x1e6, 0x7, 0x34, 0x2, 0x2, 0x1e5, 0x1e7, 0x9, 0x5, 0x2, 
       0x2, 0x1e6, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 
       0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1ec, 0x7, 0x91, 0x2, 
       0x2, 0x1e9, 0x1ea, 0x7, 0x52, 0x2, 0x2, 0x1ea, 0x1eb, 0x7, 0x68, 
       0x2, 0x2, 0x1eb, 0x1ed, 0x7, 0x48, 0x2, 0x2, 0x1ec, 0x1e9, 0x3, 0x2, 
       0x2, 0x2, 0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1f1, 0x3, 0x2, 
       0x2, 0x2, 0x1ee, 0x1ef, 0x5, 0x8e, 0x48, 0x2, 0x1ef, 0x1f0, 0x7, 
       0x4, 0x2, 0x2, 0x1f0, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1ee, 0x3, 
       0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x3, 
       0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x5, 0xa4, 0x53, 0x2, 0x1f4, 0x1f5, 
       0x7, 0x23, 0x2, 0x2, 0x1f5, 0x1f6, 0x5, 0x46, 0x24, 0x2, 0x1f6, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 0x7, 0x34, 0x2, 0x2, 0x1f8, 0x1f9, 
       0x7, 0x92, 0x2, 0x2, 0x1f9, 0x1fd, 0x7, 0x84, 0x2, 0x2, 0x1fa, 0x1fb, 
       0x7, 0x52, 0x2, 0x2, 0x1fb, 0x1fc, 0x7, 0x68, 0x2, 0x2, 0x1fc, 0x1fe, 
       0x7, 0x48, 0x2, 0x2, 0x1fd, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 
       0x3, 0x2, 0x2, 0x2, 0x1fe, 0x202, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x200, 
       0x5, 0x8e, 0x48, 0x2, 0x200, 0x201, 0x7, 0x4, 0x2, 0x2, 0x201, 0x203, 
       0x3, 0x2, 0x2, 0x2, 0x202, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x202, 0x203, 
       0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 
       0x5, 0x94, 0x4b, 0x2, 0x205, 0x206, 0x7, 0x8e, 0x2, 0x2, 0x206, 0x212, 
       0x5, 0xa6, 0x54, 0x2, 0x207, 0x208, 0x7, 0x5, 0x2, 0x2, 0x208, 0x20d, 
       0x5, 0x84, 0x43, 0x2, 0x209, 0x20a, 0x7, 0x7, 0x2, 0x2, 0x20a, 0x20c, 
       0x5, 0x84, 0x43, 0x2, 0x20b, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20f, 
       0x3, 0x2, 0x2, 0x2, 0x20d, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 
       0x3, 0x2, 0x2, 0x2, 0x20e, 0x210, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x20d, 
       0x3, 0x2, 0x2, 0x2, 0x210, 0x211, 0x7, 0x6, 0x2, 0x2, 0x211, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x212, 0x207, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x213, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x214, 0x216, 
       0x5, 0x62, 0x32, 0x2, 0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 
       0x7, 0x3d, 0x2, 0x2, 0x218, 0x219, 0x7, 0x4d, 0x2, 0x2, 0x219, 0x21c, 
       0x5, 0x64, 0x33, 0x2, 0x21a, 0x21b, 0x7, 0x94, 0x2, 0x2, 0x21b, 0x21d, 
       0x5, 0x58, 0x2d, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x220, 
       0x5, 0x62, 0x32, 0x2, 0x21f, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 
       0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 0x2, 0x2, 0x2, 0x221, 0x222, 
       0x7, 0x3d, 0x2, 0x2, 0x222, 0x223, 0x7, 0x4d, 0x2, 0x2, 0x223, 0x226, 
       0x5, 0x64, 0x33, 0x2, 0x224, 0x225, 0x7, 0x94, 0x2, 0x2, 0x225, 0x227, 
       0x5, 0x58, 0x2d, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 
       0x3, 0x2, 0x2, 0x2, 0x227, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 
       0x7, 0x6f, 0x2, 0x2, 0x229, 0x22a, 0x7, 0x2a, 0x2, 0x2, 0x22a, 0x22f, 
       0x5, 0x66, 0x34, 0x2, 0x22b, 0x22c, 0x7, 0x7, 0x2, 0x2, 0x22c, 0x22e, 
       0x5, 0x66, 0x34, 0x2, 0x22d, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x231, 
       0x3, 0x2, 0x2, 0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 
       0x3, 0x2, 0x2, 0x2, 0x230, 0x233, 0x3, 0x2, 0x2, 0x2, 0x231, 0x22f, 
       0x3, 0x2, 0x2, 0x2, 0x232, 0x228, 0x3, 0x2, 0x2, 0x2, 0x232, 0x233, 
       0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 
       0x7, 0x64, 0x2, 0x2, 0x235, 0x238, 0x5, 0x58, 0x2d, 0x2, 0x236, 0x237, 
       0x9, 0x4, 0x2, 0x2, 0x237, 0x239, 0x5, 0x58, 0x2d, 0x2, 0x238, 0x236, 
       0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23b, 
       0x3, 0x2, 0x2, 0x2, 0x23a, 0x232, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 
       0x3, 0x2, 0x2, 0x2, 0x23b, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23e, 
       0x7, 0x3f, 0x2, 0x2, 0x23d, 0x23f, 0x7, 0x39, 0x2, 0x2, 0x23e, 0x23d, 
       0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 
       0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 0x5, 0x8e, 0x48, 0x2, 0x241, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x7, 0x41, 0x2, 0x2, 0x243, 0x246, 
       0x7, 0x56, 0x2, 0x2, 0x244, 0x245, 0x7, 0x52, 0x2, 0x2, 0x245, 0x247, 
       0x7, 0x48, 0x2, 0x2, 0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 
       0x3, 0x2, 0x2, 0x2, 0x247, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 
       0x5, 0x8e, 0x48, 0x2, 0x249, 0x24a, 0x7, 0x4, 0x2, 0x2, 0x24a, 0x24c, 
       0x3, 0x2, 0x2, 0x2, 0x24b, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 
       0x3, 0x2, 0x2, 0x2, 0x24c, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x24e, 
       0x5, 0xa0, 0x51, 0x2, 0x24e, 0x27, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 
       0x7, 0x41, 0x2, 0x2, 0x250, 0x253, 0x7, 0x84, 0x2, 0x2, 0x251, 0x252, 
       0x7, 0x52, 0x2, 0x2, 0x252, 0x254, 0x7, 0x48, 0x2, 0x2, 0x253, 0x251, 
       0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x258, 
       0x3, 0x2, 0x2, 0x2, 0x255, 0x256, 0x5, 0x8e, 0x48, 0x2, 0x256, 0x257, 
       0x7, 0x4, 0x2, 0x2, 0x257, 0x259, 0x3, 0x2, 0x2, 0x2, 0x258, 0x255, 
       0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 0x3, 0x2, 0x2, 0x2, 0x259, 0x25a, 
       0x3, 0x2, 0x2, 0x2, 0x25a, 0x25b, 0x5, 0x94, 0x4b, 0x2, 0x25b, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x7, 0x41, 0x2, 0x2, 0x25d, 0x260, 
       0x7, 0x8a, 0x2, 0x2, 0x25e, 0x25f, 0x7, 0x52, 0x2, 0x2, 0x25f, 0x261, 
       0x7, 0x48, 0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x260, 0x261, 
       0x3, 0x2, 0x2, 0x2, 0x261, 0x265, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 
       0x5, 0x8e, 0x48, 0x2, 0x263, 0x264, 0x7, 0x4, 0x2, 0x2, 0x264, 0x266, 
       0x3, 0x2, 0x2, 0x2, 0x265, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 0x2, 0x2, 0x267, 0x268, 
       0x5, 0xa2, 0x52, 0x2, 0x268, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 
       0x7, 0x41, 0x2, 0x2, 0x26a, 0x26d, 0x7, 0x91, 0x2, 0x2, 0x26b, 0x26c, 
       0x7, 0x52, 0x2, 0x2, 0x26c, 0x26e, 0x7, 0x48, 0x2, 0x2, 0x26d, 0x26b, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x272, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x5, 0x8e, 0x48, 0x2, 0x270, 0x271, 
       0x7, 0x4, 0x2, 0x2, 0x271, 0x273, 0x3, 0x2, 0x2, 0x2, 0x272, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 
       0x3, 0x2, 0x2, 0x2, 0x274, 0x275, 0x5, 0xa4, 0x53, 0x2, 0x275, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x276, 0x278, 0x5, 0x62, 0x32, 0x2, 0x277, 0x276, 
       0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 
       0x3, 0x2, 0x2, 0x2, 0x279, 0x27f, 0x5, 0x78, 0x3d, 0x2, 0x27a, 0x27b, 
       0x5, 0x7a, 0x3e, 0x2, 0x27b, 0x27c, 0x5, 0x78, 0x3d, 0x2, 0x27c, 
       0x27e, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27e, 
       0x281, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 
       0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x281, 
       0x27f, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x7, 0x6f, 0x2, 0x2, 0x283, 
       0x284, 0x7, 0x2a, 0x2, 0x2, 0x284, 0x289, 0x5, 0x66, 0x34, 0x2, 0x285, 
       0x286, 0x7, 0x7, 0x2, 0x2, 0x286, 0x288, 0x5, 0x66, 0x34, 0x2, 0x287, 
       0x285, 0x3, 0x2, 0x2, 0x2, 0x288, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x289, 
       0x287, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28a, 
       0x28d, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28c, 
       0x282, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x3, 0x2, 0x2, 0x2, 0x28d, 
       0x294, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x28f, 0x7, 0x64, 0x2, 0x2, 0x28f, 
       0x292, 0x5, 0x58, 0x2d, 0x2, 0x290, 0x291, 0x9, 0x4, 0x2, 0x2, 0x291, 
       0x293, 0x5, 0x58, 0x2d, 0x2, 0x292, 0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 
       0x293, 0x3, 0x2, 0x2, 0x2, 0x293, 0x295, 0x3, 0x2, 0x2, 0x2, 0x294, 
       0x28e, 0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x3, 0x2, 0x2, 0x2, 0x295, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x296, 0x2a8, 0x7, 0x5a, 0x2, 0x2, 0x297, 
       0x2a8, 0x7, 0x7c, 0x2, 0x2, 0x298, 0x299, 0x7, 0x5a, 0x2, 0x2, 0x299, 
       0x29a, 0x7, 0x6e, 0x2, 0x2, 0x29a, 0x2a8, 0x7, 0x7c, 0x2, 0x2, 0x29b, 
       0x29c, 0x7, 0x5a, 0x2, 0x2, 0x29c, 0x29d, 0x7, 0x6e, 0x2, 0x2, 0x29d, 
       0x2a8, 0x7, 0x7f, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x5a, 0x2, 0x2, 0x29f, 
       0x2a0, 0x7, 0x6e, 0x2, 0x2, 0x2a0, 0x2a8, 0x7, 0x1b, 0x2, 0x2, 0x2a1, 
       0x2a2, 0x7, 0x5a, 0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x6e, 0x2, 0x2, 0x2a3, 
       0x2a8, 0x7, 0x4a, 0x2, 0x2, 0x2a4, 0x2a5, 0x7, 0x5a, 0x2, 0x2, 0x2a5, 
       0x2a6, 0x7, 0x6e, 0x2, 0x2, 0x2a6, 0x2a8, 0x7, 0x53, 0x2, 0x2, 0x2a7, 
       0x296, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x297, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x298, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x31, 0x3, 0x2, 0x2, 0x2, 0x2a9, 
       0x2aa, 0x7, 0x5, 0x2, 0x2, 0x2aa, 0x2af, 0x5, 0x58, 0x2d, 0x2, 0x2ab, 
       0x2ac, 0x7, 0x7, 0x2, 0x2, 0x2ac, 0x2ae, 0x5, 0x58, 0x2d, 0x2, 0x2ad, 
       0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2af, 
       0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
       0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
       0x2b3, 0x7, 0x6, 0x2, 0x2, 0x2b3, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
       0x2b9, 0x5, 0x32, 0x1a, 0x2, 0x2b5, 0x2b6, 0x7, 0x7, 0x2, 0x2, 0x2b6, 
       0x2b8, 0x5, 0x32, 0x1a, 0x2, 0x2b7, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b8, 
       0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2b9, 
       0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x35, 0x3, 0x2, 0x2, 0x2, 0x2bb, 
       0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x5, 0x2, 0x2, 0x2bd, 
       0x2c2, 0x5, 0x9a, 0x4e, 0x2, 0x2be, 0x2bf, 0x7, 0x7, 0x2, 0x2, 0x2bf, 
       0x2c1, 0x5, 0x9a, 0x4e, 0x2, 0x2c0, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
       0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2c2, 
       0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c4, 
       0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x6, 0x2, 0x2, 0x2c6, 
       0x37, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c9, 0x5, 0x62, 0x32, 0x2, 0x2c8, 
       0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
       0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cb, 0x5, 0x30, 0x19, 0x2, 0x2cb, 
       0x2cf, 0x7, 0x5d, 0x2, 0x2, 0x2cc, 0x2cd, 0x5, 0x8e, 0x48, 0x2, 0x2cd, 
       0x2ce, 0x7, 0x4, 0x2, 0x2, 0x2ce, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
       0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
       0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d3, 0x5, 0x94, 0x4b, 0x2, 0x2d2, 
       0x2d4, 0x5, 0x36, 0x1c, 0x2, 0x2d3, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d3, 
       0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2d5, 
       0x2d6, 0x7, 0x90, 0x2, 0x2, 0x2d6, 0x2db, 0x5, 0x34, 0x1b, 0x2, 0x2d7, 
       0x2db, 0x5, 0x46, 0x24, 0x2, 0x2d8, 0x2d9, 0x7, 0x3a, 0x2, 0x2, 0x2d9, 
       0x2db, 0x7, 0x90, 0x2, 0x2, 0x2da, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2da, 
       0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2db, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2e0, 0x7, 0x72, 0x2, 0x2, 0x2dd, 
       0x2de, 0x5, 0x8e, 0x48, 0x2, 0x2de, 0x2df, 0x7, 0x4, 0x2, 0x2, 0x2df, 
       0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2e0, 
       0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 
       0x2e9, 0x5, 0xa8, 0x55, 0x2, 0x2e3, 0x2e4, 0x7, 0x8, 0x2, 0x2, 0x2e4, 
       0x2ea, 0x5, 0x68, 0x35, 0x2, 0x2e5, 0x2e6, 0x7, 0x5, 0x2, 0x2, 0x2e6, 
       0x2e7, 0x5, 0x68, 0x35, 0x2, 0x2e7, 0x2e8, 0x7, 0x6, 0x2, 0x2, 0x2e8, 
       0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e9, 
       0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ea, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2f6, 0x7, 0x79, 0x2, 0x2, 0x2ec, 
       0x2f7, 0x5, 0x9c, 0x4f, 0x2, 0x2ed, 0x2ee, 0x5, 0x8e, 0x48, 0x2, 
       0x2ee, 0x2ef, 0x7, 0x4, 0x2, 0x2, 0x2ef, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
       0x2f0, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x3, 0x2, 0x2, 0x2, 
       0x2f1, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f5, 0x5, 0x94, 0x4b, 
       0x2, 0x2f3, 0x2f5, 0x5, 0xa0, 0x51, 0x2, 0x2f4, 0x2f2, 0x3, 0x2, 
       0x2, 0x2, 0x2f4, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f7, 0x3, 0x2, 
       0x2, 0x2, 0x2f6, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f0, 0x3, 0x2, 
       0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x3d, 0x3, 0x2, 
       0x2, 0x2, 0x2f8, 0x2fa, 0x7, 0x7a, 0x2, 0x2, 0x2f9, 0x2fb, 0x7, 0x81, 
       0x2, 0x2, 0x2fa, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fb, 0x3, 0x2, 
       0x2, 0x2, 0x2fb, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x5, 0xaa, 
       0x56, 0x2, 0x2fd, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x303, 0x7, 0x7f, 
       0x2, 0x2, 0x2ff, 0x301, 0x7, 0x89, 0x2, 0x2, 0x300, 0x302, 0x5, 0xae, 
       0x58, 0x2, 0x301, 0x300, 0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 0x2, 
       0x2, 0x2, 0x302, 0x304, 0x3, 0x2, 0x2, 0x2, 0x303, 0x2ff, 0x3, 0x2, 
       0x2, 0x2, 0x303, 0x304, 0x3, 0x2, 0x2, 0x2, 0x304, 0x30a, 0x3, 0x2, 
       0x2, 0x2, 0x305, 0x307, 0x7, 0x88, 0x2, 0x2, 0x306, 0x308, 0x7, 0x81, 
       0x2, 0x2, 0x307, 0x306, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 
       0x2, 0x2, 0x308, 0x309, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30b, 0x5, 0xaa, 
       0x56, 0x2, 0x30a, 0x305, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 0x3, 0x2, 
       0x2, 0x2, 0x30b, 0x41, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x7, 0x81, 
       0x2, 0x2, 0x30d, 0x30e, 0x5, 0xaa, 0x56, 0x2, 0x30e, 0x43, 0x3, 0x2, 
       0x2, 0x2, 0x30f, 0x311, 0x5, 0x62, 0x32, 0x2, 0x310, 0x30f, 0x3, 
       0x2, 0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 
       0x2, 0x2, 0x2, 0x312, 0x31d, 0x5, 0x78, 0x3d, 0x2, 0x313, 0x314, 
       0x7, 0x6f, 0x2, 0x2, 0x314, 0x315, 0x7, 0x2a, 0x2, 0x2, 0x315, 0x31a, 
       0x5, 0x66, 0x34, 0x2, 0x316, 0x317, 0x7, 0x7, 0x2, 0x2, 0x317, 0x319, 
       0x5, 0x66, 0x34, 0x2, 0x318, 0x316, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31a, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31a, 
       0x3, 0x2, 0x2, 0x2, 0x31d, 0x313, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 
       0x3, 0x2, 0x2, 0x2, 0x31e, 0x325, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 
       0x7, 0x64, 0x2, 0x2, 0x320, 0x323, 0x5, 0x58, 0x2d, 0x2, 0x321, 0x322, 
       0x9, 0x4, 0x2, 0x2, 0x322, 0x324, 0x5, 0x58, 0x2d, 0x2, 0x323, 0x321, 
       0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x3, 0x2, 0x2, 0x2, 0x324, 0x326, 
       0x3, 0x2, 0x2, 0x2, 0x325, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x325, 0x326, 
       0x3, 0x2, 0x2, 0x2, 0x326, 0x45, 0x3, 0x2, 0x2, 0x2, 0x327, 0x329, 
       0x5, 0x62, 0x32, 0x2, 0x328, 0x327, 0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 
       0x3, 0x2, 0x2, 0x2, 0x329, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x330, 
       0x5, 0x48, 0x25, 0x2, 0x32b, 0x32c, 0x5, 0x7a, 0x3e, 0x2, 0x32c, 
       0x32d, 0x5, 0x48, 0x25, 0x2, 0x32d, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x32e, 
       0x32b, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x332, 0x3, 0x2, 0x2, 0x2, 0x330, 
       0x32e, 0x3, 0x2, 0x2, 0x2, 0x330, 0x331, 0x3, 0x2, 0x2, 0x2, 0x331, 
       0x33d, 0x3, 0x2, 0x2, 0x2, 0x332, 0x330, 0x3, 0x2, 0x2, 0x2, 0x333, 
       0x334, 0x7, 0x6f, 0x2, 0x2, 0x334, 0x335, 0x7, 0x2a, 0x2, 0x2, 0x335, 
       0x33a, 0x5, 0x66, 0x34, 0x2, 0x336, 0x337, 0x7, 0x7, 0x2, 0x2, 0x337, 
       0x339, 0x5, 0x66, 0x34, 0x2, 0x338, 0x336, 0x3, 0x2, 0x2, 0x2, 0x339, 
       0x33c, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x338, 0x3, 0x2, 0x2, 0x2, 0x33a, 
       0x33b, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33c, 
       0x33a, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x333, 0x3, 0x2, 0x2, 0x2, 0x33d, 
       0x33e, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x345, 0x3, 0x2, 0x2, 0x2, 0x33f, 
       0x340, 0x7, 0x64, 0x2, 0x2, 0x340, 0x343, 0x5, 0x58, 0x2d, 0x2, 0x341, 
       0x342, 0x9, 0x4, 0x2, 0x2, 0x342, 0x344, 0x5, 0x58, 0x2d, 0x2, 0x343, 
       0x341, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 
       0x346, 0x3, 0x2, 0x2, 0x2, 0x345, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x345, 
       0x346, 0x3, 0x2, 0x2, 0x2, 0x346, 0x47, 0x3, 0x2, 0x2, 0x2, 0x347, 
       0x349, 0x7, 0x82, 0x2, 0x2, 0x348, 0x34a, 0x9, 0x6, 0x2, 0x2, 0x349, 
       0x348, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x34a, 
       0x34b, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x350, 0x5, 0x6c, 0x37, 0x2, 0x34c, 
       0x34d, 0x7, 0x7, 0x2, 0x2, 0x34d, 0x34f, 0x5, 0x6c, 0x37, 0x2, 0x34e, 
       0x34c, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x352, 0x3, 0x2, 0x2, 0x2, 0x350, 
       0x34e, 0x3, 0x2, 0x2, 0x2, 0x350, 0x351, 0x3, 0x2, 0x2, 0x2, 0x351, 
       0x35f, 0x3, 0x2, 0x2, 0x2, 0x352, 0x350, 0x3, 0x2, 0x2, 0x2, 0x353, 
       0x35d, 0x7, 0x4d, 0x2, 0x2, 0x354, 0x359, 0x5, 0x6e, 0x38, 0x2, 0x355, 
       0x356, 0x7, 0x7, 0x2, 0x2, 0x356, 0x358, 0x5, 0x6e, 0x38, 0x2, 0x357, 
       0x355, 0x3, 0x2, 0x2, 0x2, 0x358, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x359, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35a, 
       0x35e, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35c, 
       0x35e, 0x5, 0x70, 0x39, 0x2, 0x35d, 0x354, 0x3, 0x2, 0x2, 0x2, 0x35d, 
       0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 0x3, 0x2, 0x2, 0x2, 0x35f, 
       0x353, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 
       0x363, 0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 0x7, 0x94, 0x2, 0x2, 0x362, 
       0x364, 0x5, 0x58, 0x2d, 0x2, 0x363, 0x361, 0x3, 0x2, 0x2, 0x2, 0x363, 
       0x364, 0x3, 0x2, 0x2, 0x2, 0x364, 0x373, 0x3, 0x2, 0x2, 0x2, 0x365, 
       0x366, 0x7, 0x50, 0x2, 0x2, 0x366, 0x367, 0x7, 0x2a, 0x2, 0x2, 0x367, 
       0x36c, 0x5, 0x58, 0x2d, 0x2, 0x368, 0x369, 0x7, 0x7, 0x2, 0x2, 0x369, 
       0x36b, 0x5, 0x58, 0x2d, 0x2, 0x36a, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36b, 
       0x36e, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36c, 
       0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x371, 0x3, 0x2, 0x2, 0x2, 0x36e, 
       0x36c, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x370, 0x7, 0x51, 0x2, 0x2, 0x370, 
       0x372, 0x5, 0x58, 0x2d, 0x2, 0x371, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x371, 
       0x372, 0x3, 0x2, 0x2, 0x2, 0x372, 0x374, 0x3, 0x2, 0x2, 0x2, 0x373, 
       0x365, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 
       0x392, 0x3, 0x2, 0x2, 0x2, 0x375, 0x376, 0x7, 0x90, 0x2, 0x2, 0x376, 
       0x377, 0x7, 0x5, 0x2, 0x2, 0x377, 0x37c, 0x5, 0x58, 0x2d, 0x2, 0x378, 
       0x379, 0x7, 0x7, 0x2, 0x2, 0x379, 0x37b, 0x5, 0x58, 0x2d, 0x2, 0x37a, 
       0x378, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37c, 
       0x37a, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37d, 
       0x37f, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37f, 
       0x38e, 0x7, 0x6, 0x2, 0x2, 0x380, 0x381, 0x7, 0x7, 0x2, 0x2, 0x381, 
       0x382, 0x7, 0x5, 0x2, 0x2, 0x382, 0x387, 0x5, 0x58, 0x2d, 0x2, 0x383, 
       0x384, 0x7, 0x7, 0x2, 0x2, 0x384, 0x386, 0x5, 0x58, 0x2d, 0x2, 0x385, 
       0x383, 0x3, 0x2, 0x2, 0x2, 0x386, 0x389, 0x3, 0x2, 0x2, 0x2, 0x387, 
       0x385, 0x3, 0x2, 0x2, 0x2, 0x387, 0x388, 0x3, 0x2, 0x2, 0x2, 0x388, 
       0x38a, 0x3, 0x2, 0x2, 0x2, 0x389, 0x387, 0x3, 0x2, 0x2, 0x2, 0x38a, 
       0x38b, 0x7, 0x6, 0x2, 0x2, 0x38b, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38c, 
       0x380, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x390, 0x3, 0x2, 0x2, 0x2, 0x38e, 
       0x38c, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x38f, 
       0x392, 0x3, 0x2, 0x2, 0x2, 0x390, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x391, 
       0x347, 0x3, 0x2, 0x2, 0x2, 0x391, 0x375, 0x3, 0x2, 0x2, 0x2, 0x392, 
       0x49, 0x3, 0x2, 0x2, 0x2, 0x393, 0x395, 0x5, 0x62, 0x32, 0x2, 0x394, 
       0x393, 0x3, 0x2, 0x2, 0x2, 0x394, 0x395, 0x3, 0x2, 0x2, 0x2, 0x395, 
       0x396, 0x3, 0x2, 0x2, 0x2, 0x396, 0x3a1, 0x7, 0x8d, 0x2, 0x2, 0x397, 
       0x398, 0x7, 0x6e, 0x2, 0x2, 0x398, 0x3a2, 0x7, 0x7f, 0x2, 0x2, 0x399, 
       0x39a, 0x7, 0x6e, 0x2, 0x2, 0x39a, 0x3a2, 0x7, 0x1b, 0x2, 0x2, 0x39b, 
       0x39c, 0x7, 0x6e, 0x2, 0x2, 0x39c, 0x3a2, 0x7, 0x7c, 0x2, 0x2, 0x39d, 
       0x39e, 0x7, 0x6e, 0x2, 0x2, 0x39e, 0x3a2, 0x7, 0x4a, 0x2, 0x2, 0x39f, 
       0x3a0, 0x7, 0x6e, 0x2, 0x2, 0x3a0, 0x3a2, 0x7, 0x53, 0x2, 0x2, 0x3a1, 
       0x397, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x399, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
       0x39b, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x3a1, 
       0x39f, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
       0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x5, 0x64, 0x33, 0x2, 0x3a4, 
       0x3a5, 0x7, 0x83, 0x2, 0x2, 0x3a5, 0x3a6, 0x5, 0x9a, 0x4e, 0x2, 0x3a6, 
       0x3a7, 0x7, 0x8, 0x2, 0x2, 0x3a7, 0x3af, 0x5, 0x58, 0x2d, 0x2, 0x3a8, 
       0x3a9, 0x7, 0x7, 0x2, 0x2, 0x3a9, 0x3aa, 0x5, 0x9a, 0x4e, 0x2, 0x3aa, 
       0x3ab, 0x7, 0x8, 0x2, 0x2, 0x3ab, 0x3ac, 0x5, 0x58, 0x2d, 0x2, 0x3ac, 
       0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3ae, 
       0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 
       0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b1, 
       0x3af, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x7, 0x94, 0x2, 0x2, 0x3b3, 
       0x3b5, 0x5, 0x58, 0x2d, 0x2, 0x3b4, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b4, 
       0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x3b6, 
       0x3b8, 0x5, 0x62, 0x32, 0x2, 0x3b7, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b7, 
       0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
       0x3c4, 0x7, 0x8d, 0x2, 0x2, 0x3ba, 0x3bb, 0x7, 0x6e, 0x2, 0x2, 0x3bb, 
       0x3c5, 0x7, 0x7f, 0x2, 0x2, 0x3bc, 0x3bd, 0x7, 0x6e, 0x2, 0x2, 0x3bd, 
       0x3c5, 0x7, 0x1b, 0x2, 0x2, 0x3be, 0x3bf, 0x7, 0x6e, 0x2, 0x2, 0x3bf, 
       0x3c5, 0x7, 0x7c, 0x2, 0x2, 0x3c0, 0x3c1, 0x7, 0x6e, 0x2, 0x2, 0x3c1, 
       0x3c5, 0x7, 0x4a, 0x2, 0x2, 0x3c2, 0x3c3, 0x7, 0x6e, 0x2, 0x2, 0x3c3, 
       0x3c5, 0x7, 0x53, 0x2, 0x2, 0x3c4, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3c4, 
       0x3bc, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3c4, 
       0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c4, 
       0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c6, 
       0x3c7, 0x5, 0x64, 0x33, 0x2, 0x3c7, 0x3c8, 0x7, 0x83, 0x2, 0x2, 0x3c8, 
       0x3c9, 0x5, 0x9a, 0x4e, 0x2, 0x3c9, 0x3ca, 0x7, 0x8, 0x2, 0x2, 0x3ca, 
       0x3d2, 0x5, 0x58, 0x2d, 0x2, 0x3cb, 0x3cc, 0x7, 0x7, 0x2, 0x2, 0x3cc, 
       0x3cd, 0x5, 0x9a, 0x4e, 0x2, 0x3cd, 0x3ce, 0x7, 0x8, 0x2, 0x2, 0x3ce, 
       0x3cf, 0x5, 0x58, 0x2d, 0x2, 0x3cf, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d0, 
       0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d2, 
       0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d3, 
       0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d5, 
       0x3d6, 0x7, 0x94, 0x2, 0x2, 0x3d6, 0x3d8, 0x5, 0x58, 0x2d, 0x2, 0x3d7, 
       0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3d8, 
       0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3da, 0x7, 0x6f, 0x2, 0x2, 0x3da, 
       0x3db, 0x7, 0x2a, 0x2, 0x2, 0x3db, 0x3e0, 0x5, 0x66, 0x34, 0x2, 0x3dc, 
       0x3dd, 0x7, 0x7, 0x2, 0x2, 0x3dd, 0x3df, 0x5, 0x66, 0x34, 0x2, 0x3de, 
       0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
       0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 
       0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e3, 
       0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e4, 
       0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0x7, 0x64, 0x2, 0x2, 0x3e6, 
       0x3e9, 0x5, 0x58, 0x2d, 0x2, 0x3e7, 0x3e8, 0x9, 0x4, 0x2, 0x2, 0x3e8, 
       0x3ea, 0x5, 0x58, 0x2d, 0x2, 0x3e9, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e9, 
       0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3eb, 
       0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ec, 
       0x4d, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ee, 0x7, 0x8f, 0x2, 0x2, 0x3ee, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f1, 0x5, 0x9a, 0x4e, 0x2, 0x3f0, 
       0x3f2, 0x5, 0x52, 0x2a, 0x2, 0x3f1, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x3f1, 
       0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
       0x3f5, 0x5, 0x54, 0x2b, 0x2, 0x3f4, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f5, 
       0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f6, 
       0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x51, 0x3, 0x2, 0x2, 0x2, 0x3f8, 
       0x3f6, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fb, 0x5, 0x8a, 0x46, 0x2, 0x3fa, 
       0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fc, 
       0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fa, 0x3, 0x2, 0x2, 0x2, 0x3fd, 
       0x408, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3ff, 0x7, 0x5, 0x2, 0x2, 0x3ff, 
       0x400, 0x5, 0x7c, 0x3f, 0x2, 0x400, 0x401, 0x7, 0x6, 0x2, 0x2, 0x401, 
       0x409, 0x3, 0x2, 0x2, 0x2, 0x402, 0x403, 0x7, 0x5, 0x2, 0x2, 0x403, 
       0x404, 0x5, 0x7c, 0x3f, 0x2, 0x404, 0x405, 0x7, 0x7, 0x2, 0x2, 0x405, 
       0x406, 0x5, 0x7c, 0x3f, 0x2, 0x406, 0x407, 0x7, 0x6, 0x2, 0x2, 0x407, 
       0x409, 0x3, 0x2, 0x2, 0x2, 0x408, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x408, 
       0x402, 0x3, 0x2, 0x2, 0x2, 0x408, 0x409, 0x3, 0x2, 0x2, 0x2, 0x409, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 0x7, 0x33, 0x2, 0x2, 0x40b, 
       0x40d, 0x5, 0x8a, 0x46, 0x2, 0x40c, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40c, 
       0x40d, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x40e, 
       0x40f, 0x7, 0x73, 0x2, 0x2, 0x40f, 0x411, 0x7, 0x61, 0x2, 0x2, 0x410, 
       0x412, 0x9, 0x7, 0x2, 0x2, 0x411, 0x410, 0x3, 0x2, 0x2, 0x2, 0x411, 
       0x412, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 0x2, 0x413, 
       0x415, 0x5, 0x56, 0x2c, 0x2, 0x414, 0x416, 0x7, 0x26, 0x2, 0x2, 0x415, 
       0x414, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x3, 0x2, 0x2, 0x2, 0x416, 
       0x430, 0x3, 0x2, 0x2, 0x2, 0x417, 0x419, 0x7, 0x68, 0x2, 0x2, 0x418, 
       0x417, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 0x3, 0x2, 0x2, 0x2, 0x419, 
       0x41a, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x41b, 0x7, 0x6a, 0x2, 0x2, 0x41b, 
       0x430, 0x5, 0x56, 0x2c, 0x2, 0x41c, 0x41d, 0x7, 0x8c, 0x2, 0x2, 0x41d, 
       0x430, 0x5, 0x56, 0x2c, 0x2, 0x41e, 0x41f, 0x7, 0x2e, 0x2, 0x2, 0x41f, 
       0x420, 0x7, 0x5, 0x2, 0x2, 0x420, 0x421, 0x5, 0x58, 0x2d, 0x2, 0x421, 
       0x422, 0x7, 0x6, 0x2, 0x2, 0x422, 0x430, 0x3, 0x2, 0x2, 0x2, 0x423, 
       0x42a, 0x7, 0x3a, 0x2, 0x2, 0x424, 0x42b, 0x5, 0x7c, 0x3f, 0x2, 0x425, 
       0x42b, 0x5, 0x7e, 0x40, 0x2, 0x426, 0x427, 0x7, 0x5, 0x2, 0x2, 0x427, 
       0x428, 0x5, 0x58, 0x2d, 0x2, 0x428, 0x429, 0x7, 0x6, 0x2, 0x2, 0x429, 
       0x42b, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x424, 0x3, 0x2, 0x2, 0x2, 0x42a, 
       0x425, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x426, 0x3, 0x2, 0x2, 0x2, 0x42b, 
       0x430, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x42d, 0x7, 0x2f, 0x2, 0x2, 0x42d, 
       0x430, 0x5, 0x9c, 0x4f, 0x2, 0x42e, 0x430, 0x5, 0x5a, 0x2e, 0x2, 
       0x42f, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x418, 0x3, 0x2, 0x2, 0x2, 
       0x42f, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x41e, 0x3, 0x2, 0x2, 0x2, 
       0x42f, 0x423, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x42c, 0x3, 0x2, 0x2, 0x2, 
       0x42f, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x430, 0x55, 0x3, 0x2, 0x2, 0x2, 
       0x431, 0x432, 0x7, 0x6d, 0x2, 0x2, 0x432, 0x433, 0x7, 0x32, 0x2, 
       0x2, 0x433, 0x435, 0x9, 0x8, 0x2, 0x2, 0x434, 0x431, 0x3, 0x2, 0x2, 
       0x2, 0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0x57, 0x3, 0x2, 0x2, 
       0x2, 0x436, 0x437, 0x8, 0x2d, 0x1, 0x2, 0x437, 0x483, 0x5, 0x7e, 
       0x40, 0x2, 0x438, 0x483, 0x7, 0x99, 0x2, 0x2, 0x439, 0x43a, 0x5, 
       0x8e, 0x48, 0x2, 0x43a, 0x43b, 0x7, 0x4, 0x2, 0x2, 0x43b, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x43c, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x43f, 
       0x5, 0x94, 0x4b, 0x2, 0x43f, 0x440, 0x7, 0x4, 0x2, 0x2, 0x440, 0x442, 
       0x3, 0x2, 0x2, 0x2, 0x441, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x441, 0x442, 
       0x3, 0x2, 0x2, 0x2, 0x442, 0x443, 0x3, 0x2, 0x2, 0x2, 0x443, 0x483, 
       0x5, 0x9a, 0x4e, 0x2, 0x444, 0x445, 0x5, 0x80, 0x41, 0x2, 0x445, 
       0x446, 0x5, 0x58, 0x2d, 0x17, 0x446, 0x483, 0x3, 0x2, 0x2, 0x2, 0x447, 
       0x448, 0x5, 0x8c, 0x47, 0x2, 0x448, 0x455, 0x7, 0x5, 0x2, 0x2, 0x449, 
       0x44b, 0x7, 0x40, 0x2, 0x2, 0x44a, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44a, 
       0x44b, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x44c, 0x3, 0x2, 0x2, 0x2, 0x44c, 
       0x451, 0x5, 0x58, 0x2d, 0x2, 0x44d, 0x44e, 0x7, 0x7, 0x2, 0x2, 0x44e, 
       0x450, 0x5, 0x58, 0x2d, 0x2, 0x44f, 0x44d, 0x3, 0x2, 0x2, 0x2, 0x450, 
       0x453, 0x3, 0x2, 0x2, 0x2, 0x451, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x451, 
       0x452, 0x3, 0x2, 0x2, 0x2, 0x452, 0x456, 0x3, 0x2, 0x2, 0x2, 0x453, 
       0x451, 0x3, 0x2, 0x2, 0x2, 0x454, 0x456, 0x7, 0x9, 0x2, 0x2, 0x455, 
       0x44a, 0x3, 0x2, 0x2, 0x2, 0x455, 0x454, 0x3, 0x2, 0x2, 0x2, 0x455, 
       0x456, 0x3, 0x2, 0x2, 0x2, 0x456, 0x457, 0x3, 0x2, 0x2, 0x2, 0x457, 
       0x458, 0x7, 0x6, 0x2, 0x2, 0x458, 0x483, 0x3, 0x2, 0x2, 0x2, 0x459, 
       0x45a, 0x7, 0x5, 0x2, 0x2, 0x45a, 0x45b, 0x5, 0x58, 0x2d, 0x2, 0x45b, 
       0x45c, 0x7, 0x6, 0x2, 0x2, 0x45c, 0x483, 0x3, 0x2, 0x2, 0x2, 0x45d, 
       0x45e, 0x7, 0x2d, 0x2, 0x2, 0x45e, 0x45f, 0x7, 0x5, 0x2, 0x2, 0x45f, 
       0x460, 0x5, 0x58, 0x2d, 0x2, 0x460, 0x461, 0x7, 0x23, 0x2, 0x2, 0x461, 
       0x462, 0x5, 0x52, 0x2a, 0x2, 0x462, 0x463, 0x7, 0x6, 0x2, 0x2, 0x463, 
       0x483, 0x3, 0x2, 0x2, 0x2, 0x464, 0x466, 0x7, 0x68, 0x2, 0x2, 0x465, 
       0x464, 0x3, 0x2, 0x2, 0x2, 0x465, 0x466, 0x3, 0x2, 0x2, 0x2, 0x466, 
       0x467, 0x3, 0x2, 0x2, 0x2, 0x467, 0x469, 0x7, 0x48, 0x2, 0x2, 0x468, 
       0x465, 0x3, 0x2, 0x2, 0x2, 0x468, 0x469, 0x3, 0x2, 0x2, 0x2, 0x469, 
       0x46a, 0x3, 0x2, 0x2, 0x2, 0x46a, 0x46b, 0x7, 0x5, 0x2, 0x2, 0x46b, 
       0x46c, 0x5, 0x46, 0x24, 0x2, 0x46c, 0x46d, 0x7, 0x6, 0x2, 0x2, 0x46d, 
       0x483, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x470, 0x7, 0x2c, 0x2, 0x2, 0x46f, 
       0x471, 0x5, 0x58, 0x2d, 0x2, 0x470, 0x46f, 0x3, 0x2, 0x2, 0x2, 0x470, 
       0x471, 0x3, 0x2, 0x2, 0x2, 0x471, 0x477, 0x3, 0x2, 0x2, 0x2, 0x472, 
       0x473, 0x7, 0x93, 0x2, 0x2, 0x473, 0x474, 0x5, 0x58, 0x2d, 0x2, 0x474, 
       0x475, 0x7, 0x87, 0x2, 0x2, 0x475, 0x476, 0x5, 0x58, 0x2d, 0x2, 0x476, 
       0x478, 0x3, 0x2, 0x2, 0x2, 0x477, 0x472, 0x3, 0x2, 0x2, 0x2, 0x478, 
       0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 0x477, 0x3, 0x2, 0x2, 0x2, 0x479, 
       0x47a, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x47d, 0x3, 0x2, 0x2, 0x2, 0x47b, 
       0x47c, 0x7, 0x43, 0x2, 0x2, 0x47c, 0x47e, 0x5, 0x58, 0x2d, 0x2, 0x47d, 
       0x47b, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x47e, 
       0x47f, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x480, 0x7, 0x44, 0x2, 0x2, 0x480, 
       0x483, 0x3, 0x2, 0x2, 0x2, 0x481, 0x483, 0x5, 0x5c, 0x2f, 0x2, 0x482, 
       0x436, 0x3, 0x2, 0x2, 0x2, 0x482, 0x438, 0x3, 0x2, 0x2, 0x2, 0x482, 
       0x441, 0x3, 0x2, 0x2, 0x2, 0x482, 0x444, 0x3, 0x2, 0x2, 0x2, 0x482, 
       0x447, 0x3, 0x2, 0x2, 0x2, 0x482, 0x459, 0x3, 0x2, 0x2, 0x2, 0x482, 
       0x45d, 0x3, 0x2, 0x2, 0x2, 0x482, 0x468, 0x3, 0x2, 0x2, 0x2, 0x482, 
       0x46e, 0x3, 0x2, 0x2, 0x2, 0x482, 0x481, 0x3, 0x2, 0x2, 0x2, 0x483, 
       0x4db, 0x3, 0x2, 0x2, 0x2, 0x484, 0x485, 0xc, 0x16, 0x2, 0x2, 0x485, 
       0x486, 0x7, 0xd, 0x2, 0x2, 0x486, 0x4da, 0x5, 0x58, 0x2d, 0x17, 0x487, 
       0x488, 0xc, 0x15, 0x2, 0x2, 0x488, 0x489, 0x9, 0x9, 0x2, 0x2, 0x489, 
       0x4da, 0x5, 0x58, 0x2d, 0x16, 0x48a, 0x48b, 0xc, 0x14, 0x2, 0x2, 
       0x48b, 0x48c, 0x9, 0xa, 0x2, 0x2, 0x48c, 0x4da, 0x5, 0x58, 0x2d, 
       0x15, 0x48d, 0x48e, 0xc, 0x13, 0x2, 0x2, 0x48e, 0x48f, 0x9, 0xb, 
       0x2, 0x2, 0x48f, 0x4da, 0x5, 0x58, 0x2d, 0x14, 0x490, 0x491, 0xc, 
       0x12, 0x2, 0x2, 0x491, 0x492, 0x9, 0xc, 0x2, 0x2, 0x492, 0x4da, 0x5, 
       0x58, 0x2d, 0x13, 0x493, 0x494, 0xc, 0x11, 0x2, 0x2, 0x494, 0x495, 
       0x9, 0xd, 0x2, 0x2, 0x495, 0x4da, 0x5, 0x58, 0x2d, 0x12, 0x496, 0x497, 
       0xc, 0xf, 0x2, 0x2, 0x497, 0x498, 0x7, 0x22, 0x2, 0x2, 0x498, 0x4da, 
       0x5, 0x58, 0x2d, 0x10, 0x499, 0x49a, 0xc, 0xe, 0x2, 0x2, 0x49a, 0x49b, 
       0x7, 0x6e, 0x2, 0x2, 0x49b, 0x4da, 0x5, 0x58, 0x2d, 0xf, 0x49c, 0x49d, 
       0xc, 0x7, 0x2, 0x2, 0x49d, 0x49f, 0x7, 0x5e, 0x2, 0x2, 0x49e, 0x4a0, 
       0x7, 0x68, 0x2, 0x2, 0x49f, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a0, 
       0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4da, 
       0x5, 0x58, 0x2d, 0x8, 0x4a2, 0x4a4, 0xc, 0x6, 0x2, 0x2, 0x4a3, 0x4a5, 
       0x7, 0x68, 0x2, 0x2, 0x4a4, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4a4, 0x4a5, 
       0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 
       0x7, 0x29, 0x2, 0x2, 0x4a7, 0x4a8, 0x5, 0x58, 0x2d, 0x2, 0x4a8, 0x4a9, 
       0x7, 0x22, 0x2, 0x2, 0x4a9, 0x4aa, 0x5, 0x58, 0x2d, 0x7, 0x4aa, 0x4da, 
       0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ad, 0xc, 0x10, 0x2, 0x2, 0x4ac, 0x4ae, 
       0x7, 0x68, 0x2, 0x2, 0x4ad, 0x4ac, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 
       0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4af, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4c3, 
       0x7, 0x55, 0x2, 0x2, 0x4b0, 0x4ba, 0x7, 0x5, 0x2, 0x2, 0x4b1, 0x4bb, 
       0x5, 0x46, 0x24, 0x2, 0x4b2, 0x4b7, 0x5, 0x58, 0x2d, 0x2, 0x4b3, 
       0x4b4, 0x7, 0x7, 0x2, 0x2, 0x4b4, 0x4b6, 0x5, 0x58, 0x2d, 0x2, 0x4b5, 
       0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0x4b7, 
       0x4b5, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4b8, 
       0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4ba, 
       0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4ba, 
       0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4bb, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bc, 
       0x4c4, 0x7, 0x6, 0x2, 0x2, 0x4bd, 0x4be, 0x5, 0x8e, 0x48, 0x2, 0x4be, 
       0x4bf, 0x7, 0x4, 0x2, 0x2, 0x4bf, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4c0, 
       0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c1, 0x3, 0x2, 0x2, 0x2, 0x4c1, 
       0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c4, 0x5, 0x94, 0x4b, 0x2, 0x4c3, 
       0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4c4, 
       0x4da, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 0xc, 0xa, 0x2, 0x2, 0x4c6, 
       0x4c7, 0x7, 0x2f, 0x2, 0x2, 0x4c7, 0x4da, 0x5, 0x9c, 0x4f, 0x2, 0x4c8, 
       0x4ca, 0xc, 0x9, 0x2, 0x2, 0x4c9, 0x4cb, 0x7, 0x68, 0x2, 0x2, 0x4ca, 
       0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4cb, 
       0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4cd, 0x9, 0xe, 0x2, 0x2, 0x4cd, 
       0x4d0, 0x5, 0x58, 0x2d, 0x2, 0x4ce, 0x4cf, 0x7, 0x45, 0x2, 0x2, 0x4cf, 
       0x4d1, 0x5, 0x58, 0x2d, 0x2, 0x4d0, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4d0, 
       0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4da, 0x3, 0x2, 0x2, 0x2, 0x4d2, 
       0x4d7, 0xc, 0x8, 0x2, 0x2, 0x4d3, 0x4d8, 0x7, 0x5f, 0x2, 0x2, 0x4d4, 
       0x4d8, 0x7, 0x69, 0x2, 0x2, 0x4d5, 0x4d6, 0x7, 0x68, 0x2, 0x2, 0x4d6, 
       0x4d8, 0x7, 0x6a, 0x2, 0x2, 0x4d7, 0x4d3, 0x3, 0x2, 0x2, 0x2, 0x4d7, 
       0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d8, 
       0x4da, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x484, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x487, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x48d, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x490, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x493, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x496, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x499, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x4a2, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x4c5, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0x4db, 
       0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4db, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4dc, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4db, 0x3, 0x2, 0x2, 0x2, 0x4de, 
       0x4df, 0x7, 0x77, 0x2, 0x2, 0x4df, 0x4eb, 0x5, 0x9e, 0x50, 0x2, 0x4e0, 
       0x4e1, 0x7, 0x5, 0x2, 0x2, 0x4e1, 0x4e6, 0x5, 0x9a, 0x4e, 0x2, 0x4e2, 
       0x4e3, 0x7, 0x7, 0x2, 0x2, 0x4e3, 0x4e5, 0x5, 0x9a, 0x4e, 0x2, 0x4e4, 
       0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4e6, 
       0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e7, 
       0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e9, 
       0x4ea, 0x7, 0x6, 0x2, 0x2, 0x4ea, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4eb, 
       0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4ec, 
       0x4ff, 0x3, 0x2, 0x2, 0x2, 0x4ed, 0x4ee, 0x7, 0x6d, 0x2, 0x2, 0x4ee, 
       0x4f7, 0x9, 0xf, 0x2, 0x2, 0x4ef, 0x4f0, 0x7, 0x83, 0x2, 0x2, 0x4f0, 
       0x4f8, 0x7, 0x6a, 0x2, 0x2, 0x4f1, 0x4f2, 0x7, 0x83, 0x2, 0x2, 0x4f2, 
       0x4f8, 0x7, 0x3a, 0x2, 0x2, 0x4f3, 0x4f8, 0x7, 0x2b, 0x2, 0x2, 0x4f4, 
       0x4f8, 0x7, 0x7d, 0x2, 0x2, 0x4f5, 0x4f6, 0x7, 0x67, 0x2, 0x2, 0x4f6, 
       0x4f8, 0x7, 0x1c, 0x2, 0x2, 0x4f7, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4f7, 
       0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f3, 0x3, 0x2, 0x2, 0x2, 0x4f7, 
       0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f8, 
       0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fa, 0x7, 0x65, 0x2, 0x2, 0x4fa, 
       0x4fc, 0x5, 0x8a, 0x46, 0x2, 0x4fb, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4fb, 
       0x4f9, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
       0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x501, 0x3, 0x2, 0x2, 0x2, 0x4ff, 
       0x4fd, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x500, 0x3, 0x2, 0x2, 0x2, 0x500, 
       0x50c, 0x3, 0x2, 0x2, 0x2, 0x501, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x502, 
       0x504, 0x7, 0x68, 0x2, 0x2, 0x503, 0x502, 0x3, 0x2, 0x2, 0x2, 0x503, 
       0x504, 0x3, 0x2, 0x2, 0x2, 0x504, 0x505, 0x3, 0x2, 0x2, 0x2, 0x505, 
       0x50a, 0x7, 0x3b, 0x2, 0x2, 0x506, 0x507, 0x7, 0x58, 0x2, 0x2, 0x507, 
       0x50b, 0x7, 0x3c, 0x2, 0x2, 0x508, 0x509, 0x7, 0x58, 0x2, 0x2, 0x509, 
       0x50b, 0x7, 0x54, 0x2, 0x2, 0x50a, 0x506, 0x3, 0x2, 0x2, 0x2, 0x50a, 
       0x508, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x50b, 0x3, 0x2, 0x2, 0x2, 0x50b, 
       0x50d, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x503, 0x3, 0x2, 0x2, 0x2, 0x50c, 
       0x50d, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x50e, 
       0x50f, 0x7, 0x75, 0x2, 0x2, 0x50f, 0x514, 0x7, 0x5, 0x2, 0x2, 0x510, 
       0x515, 0x7, 0x53, 0x2, 0x2, 0x511, 0x512, 0x9, 0x10, 0x2, 0x2, 0x512, 
       0x513, 0x7, 0x7, 0x2, 0x2, 0x513, 0x515, 0x5, 0x82, 0x42, 0x2, 0x514, 
       0x510, 0x3, 0x2, 0x2, 0x2, 0x514, 0x511, 0x3, 0x2, 0x2, 0x2, 0x515, 
       0x516, 0x3, 0x2, 0x2, 0x2, 0x516, 0x517, 0x7, 0x6, 0x2, 0x2, 0x517, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x518, 0x51b, 0x5, 0x9a, 0x4e, 0x2, 0x519, 
       0x51a, 0x7, 0x2f, 0x2, 0x2, 0x51a, 0x51c, 0x5, 0x9c, 0x4f, 0x2, 0x51b, 
       0x519, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x51c, 
       0x51e, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x51f, 0x9, 0x7, 0x2, 0x2, 0x51e, 
       0x51d, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x51f, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x520, 0x521, 0x7, 0x33, 0x2, 0x2, 0x521, 
       0x523, 0x5, 0x8a, 0x46, 0x2, 0x522, 0x520, 0x3, 0x2, 0x2, 0x2, 0x522, 
       0x523, 0x3, 0x2, 0x2, 0x2, 0x523, 0x548, 0x3, 0x2, 0x2, 0x2, 0x524, 
       0x525, 0x7, 0x73, 0x2, 0x2, 0x525, 0x528, 0x7, 0x61, 0x2, 0x2, 0x526, 
       0x528, 0x7, 0x8c, 0x2, 0x2, 0x527, 0x524, 0x3, 0x2, 0x2, 0x2, 0x527, 
       0x526, 0x3, 0x2, 0x2, 0x2, 0x528, 0x529, 0x3, 0x2, 0x2, 0x2, 0x529, 
       0x52a, 0x7, 0x5, 0x2, 0x2, 0x52a, 0x52f, 0x5, 0x5e, 0x30, 0x2, 0x52b, 
       0x52c, 0x7, 0x7, 0x2, 0x2, 0x52c, 0x52e, 0x5, 0x5e, 0x30, 0x2, 0x52d, 
       0x52b, 0x3, 0x2, 0x2, 0x2, 0x52e, 0x531, 0x3, 0x2, 0x2, 0x2, 0x52f, 
       0x52d, 0x3, 0x2, 0x2, 0x2, 0x52f, 0x530, 0x3, 0x2, 0x2, 0x2, 0x530, 
       0x532, 0x3, 0x2, 0x2, 0x2, 0x531, 0x52f, 0x3, 0x2, 0x2, 0x2, 0x532, 
       0x533, 0x7, 0x6, 0x2, 0x2, 0x533, 0x534, 0x5, 0x56, 0x2c, 0x2, 0x534, 
       0x549, 0x3, 0x2, 0x2, 0x2, 0x535, 0x536, 0x7, 0x2e, 0x2, 0x2, 0x536, 
       0x537, 0x7, 0x5, 0x2, 0x2, 0x537, 0x538, 0x5, 0x58, 0x2d, 0x2, 0x538, 
       0x539, 0x7, 0x6, 0x2, 0x2, 0x539, 0x549, 0x3, 0x2, 0x2, 0x2, 0x53a, 
       0x53b, 0x7, 0x4c, 0x2, 0x2, 0x53b, 0x53c, 0x7, 0x61, 0x2, 0x2, 0x53c, 
       0x53d, 0x7, 0x5, 0x2, 0x2, 0x53d, 0x542, 0x5, 0x9a, 0x4e, 0x2, 0x53e, 
       0x53f, 0x7, 0x7, 0x2, 0x2, 0x53f, 0x541, 0x5, 0x9a, 0x4e, 0x2, 0x540, 
       0x53e, 0x3, 0x2, 0x2, 0x2, 0x541, 0x544, 0x3, 0x2, 0x2, 0x2, 0x542, 
       0x540, 0x3, 0x2, 0x2, 0x2, 0x542, 0x543, 0x3, 0x2, 0x2, 0x2, 0x543, 
       0x545, 0x3, 0x2, 0x2, 0x2, 0x544, 0x542, 0x3, 0x2, 0x2, 0x2, 0x545, 
       0x546, 0x7, 0x6, 0x2, 0x2, 0x546, 0x547, 0x5, 0x5a, 0x2e, 0x2, 0x547, 
       0x549, 0x3, 0x2, 0x2, 0x2, 0x548, 0x527, 0x3, 0x2, 0x2, 0x2, 0x548, 
       0x535, 0x3, 0x2, 0x2, 0x2, 0x548, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x549, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x54c, 0x7, 0x95, 0x2, 0x2, 0x54b, 
       0x54d, 0x7, 0x76, 0x2, 0x2, 0x54c, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x54c, 
       0x54d, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54e, 0x3, 0x2, 0x2, 0x2, 0x54e, 
       0x553, 0x5, 0x6a, 0x36, 0x2, 0x54f, 0x550, 0x7, 0x7, 0x2, 0x2, 0x550, 
       0x552, 0x5, 0x6a, 0x36, 0x2, 0x551, 0x54f, 0x3, 0x2, 0x2, 0x2, 0x552, 
       0x555, 0x3, 0x2, 0x2, 0x2, 0x553, 0x551, 0x3, 0x2, 0x2, 0x2, 0x553, 
       0x554, 0x3, 0x2, 0x2, 0x2, 0x554, 0x63, 0x3, 0x2, 0x2, 0x2, 0x555, 
       0x553, 0x3, 0x2, 0x2, 0x2, 0x556, 0x557, 0x5, 0x8e, 0x48, 0x2, 0x557, 
       0x558, 0x7, 0x4, 0x2, 0x2, 0x558, 0x55a, 0x3, 0x2, 0x2, 0x2, 0x559, 
       0x556, 0x3, 0x2, 0x2, 0x2, 0x559, 0x55a, 0x3, 0x2, 0x2, 0x2, 0x55a, 
       0x55b, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x561, 0x5, 0x94, 0x4b, 0x2, 0x55c, 
       0x55d, 0x7, 0x57, 0x2, 0x2, 0x55d, 0x55e, 0x7, 0x2a, 0x2, 0x2, 0x55e, 
       0x562, 0x5, 0xa0, 0x51, 0x2, 0x55f, 0x560, 0x7, 0x68, 0x2, 0x2, 0x560, 
       0x562, 0x7, 0x57, 0x2, 0x2, 0x561, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x561, 
       0x55f, 0x3, 0x2, 0x2, 0x2, 0x561, 0x562, 0x3, 0x2, 0x2, 0x2, 0x562, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x563, 0x566, 0x5, 0x58, 0x2d, 0x2, 0x564, 
       0x565, 0x7, 0x2f, 0x2, 0x2, 0x565, 0x567, 0x5, 0x9c, 0x4f, 0x2, 0x566, 
       0x564, 0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 0x3, 0x2, 0x2, 0x2, 0x567, 
       0x569, 0x3, 0x2, 0x2, 0x2, 0x568, 0x56a, 0x9, 0x7, 0x2, 0x2, 0x569, 
       0x568, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x56a, 
       0x67, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56f, 0x5, 0x7c, 0x3f, 0x2, 0x56c, 
       0x56f, 0x5, 0x8a, 0x46, 0x2, 0x56d, 0x56f, 0x7, 0x9a, 0x2, 0x2, 0x56e, 
       0x56b, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56e, 
       0x56d, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x570, 
       0x57c, 0x5, 0x94, 0x4b, 0x2, 0x571, 0x572, 0x7, 0x5, 0x2, 0x2, 0x572, 
       0x577, 0x5, 0x9a, 0x4e, 0x2, 0x573, 0x574, 0x7, 0x7, 0x2, 0x2, 0x574, 
       0x576, 0x5, 0x9a, 0x4e, 0x2, 0x575, 0x573, 0x3, 0x2, 0x2, 0x2, 0x576, 
       0x579, 0x3, 0x2, 0x2, 0x2, 0x577, 0x575, 0x3, 0x2, 0x2, 0x2, 0x577, 
       0x578, 0x3, 0x2, 0x2, 0x2, 0x578, 0x57a, 0x3, 0x2, 0x2, 0x2, 0x579, 
       0x577, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57b, 0x7, 0x6, 0x2, 0x2, 0x57b, 
       0x57d, 0x3, 0x2, 0x2, 0x2, 0x57c, 0x571, 0x3, 0x2, 0x2, 0x2, 0x57c, 
       0x57d, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x57e, 
       0x57f, 0x7, 0x23, 0x2, 0x2, 0x57f, 0x580, 0x7, 0x5, 0x2, 0x2, 0x580, 
       0x581, 0x5, 0x46, 0x24, 0x2, 0x581, 0x582, 0x7, 0x6, 0x2, 0x2, 0x582, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x583, 0x590, 0x7, 0x9, 0x2, 0x2, 0x584, 
       0x585, 0x5, 0x94, 0x4b, 0x2, 0x585, 0x586, 0x7, 0x4, 0x2, 0x2, 0x586, 
       0x587, 0x7, 0x9, 0x2, 0x2, 0x587, 0x590, 0x3, 0x2, 0x2, 0x2, 0x588, 
       0x58d, 0x5, 0x58, 0x2d, 0x2, 0x589, 0x58b, 0x7, 0x23, 0x2, 0x2, 0x58a, 
       0x589, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58b, 
       0x58c, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58e, 0x5, 0x86, 0x44, 0x2, 0x58d, 
       0x58a, 0x3, 0x2, 0x2, 0x2, 0x58d, 0x58e, 0x3, 0x2, 0x2, 0x2, 0x58e, 
       0x590, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x583, 0x3, 0x2, 0x2, 0x2, 0x58f, 
       0x584, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x588, 0x3, 0x2, 0x2, 0x2, 0x590, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x591, 0x592, 0x5, 0x90, 0x49, 0x2, 0x592, 
       0x593, 0x7, 0x4, 0x2, 0x2, 0x593, 0x595, 0x3, 0x2, 0x2, 0x2, 0x594, 
       0x591, 0x3, 0x2, 0x2, 0x2, 0x594, 0x595, 0x3, 0x2, 0x2, 0x2, 0x595, 
       0x596, 0x3, 0x2, 0x2, 0x2, 0x596, 0x59b, 0x5, 0x94, 0x4b, 0x2, 0x597, 
       0x599, 0x7, 0x23, 0x2, 0x2, 0x598, 0x597, 0x3, 0x2, 0x2, 0x2, 0x598, 
       0x599, 0x3, 0x2, 0x2, 0x2, 0x599, 0x59a, 0x3, 0x2, 0x2, 0x2, 0x59a, 
       0x59c, 0x5, 0xac, 0x57, 0x2, 0x59b, 0x598, 0x3, 0x2, 0x2, 0x2, 0x59b, 
       0x59c, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x5a2, 0x3, 0x2, 0x2, 0x2, 0x59d, 
       0x59e, 0x7, 0x57, 0x2, 0x2, 0x59e, 0x59f, 0x7, 0x2a, 0x2, 0x2, 0x59f, 
       0x5a3, 0x5, 0xa0, 0x51, 0x2, 0x5a0, 0x5a1, 0x7, 0x68, 0x2, 0x2, 0x5a1, 
       0x5a3, 0x7, 0x57, 0x2, 0x2, 0x5a2, 0x59d, 0x3, 0x2, 0x2, 0x2, 0x5a2, 
       0x5a0, 0x3, 0x2, 0x2, 0x2, 0x5a2, 0x5a3, 0x3, 0x2, 0x2, 0x2, 0x5a3, 
       0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a5, 0x5, 0x90, 0x49, 0x2, 0x5a5, 
       0x5a6, 0x7, 0x4, 0x2, 0x2, 0x5a6, 0x5a8, 0x3, 0x2, 0x2, 0x2, 0x5a7, 
       0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x5a8, 0x3, 0x2, 0x2, 0x2, 0x5a8, 
       0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 0x5, 0x92, 0x4a, 0x2, 0x5aa, 
       0x5b3, 0x7, 0x5, 0x2, 0x2, 0x5ab, 0x5b0, 0x5, 0x58, 0x2d, 0x2, 0x5ac, 
       0x5ad, 0x7, 0x7, 0x2, 0x2, 0x5ad, 0x5af, 0x5, 0x58, 0x2d, 0x2, 0x5ae, 
       0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5af, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b0, 
       0x5ae, 0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5b1, 0x3, 0x2, 0x2, 0x2, 0x5b1, 
       0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b3, 
       0x5ab, 0x3, 0x2, 0x2, 0x2, 0x5b3, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b4, 
       0x5b5, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0x5ba, 0x7, 0x6, 0x2, 0x2, 0x5b6, 
       0x5b8, 0x7, 0x23, 0x2, 0x2, 0x5b7, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b7, 
       0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5b9, 
       0x5bb, 0x5, 0xac, 0x57, 0x2, 0x5ba, 0x5b7, 0x3, 0x2, 0x2, 0x2, 0x5ba, 
       0x5bb, 0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5bc, 
       0x5c6, 0x7, 0x5, 0x2, 0x2, 0x5bd, 0x5c2, 0x5, 0x6e, 0x38, 0x2, 0x5be, 
       0x5bf, 0x7, 0x7, 0x2, 0x2, 0x5bf, 0x5c1, 0x5, 0x6e, 0x38, 0x2, 0x5c0, 
       0x5be, 0x3, 0x2, 0x2, 0x2, 0x5c1, 0x5c4, 0x3, 0x2, 0x2, 0x2, 0x5c2, 
       0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c3, 
       0x5c7, 0x3, 0x2, 0x2, 0x2, 0x5c4, 0x5c2, 0x3, 0x2, 0x2, 0x2, 0x5c5, 
       0x5c7, 0x5, 0x70, 0x39, 0x2, 0x5c6, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5c6, 
       0x5c5, 0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5c8, 
       0x5c9, 0x7, 0x6, 0x2, 0x2, 0x5c9, 0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5ca, 
       0x5cb, 0x7, 0x5, 0x2, 0x2, 0x5cb, 0x5cc, 0x5, 0x46, 0x24, 0x2, 0x5cc, 
       0x5d1, 0x7, 0x6, 0x2, 0x2, 0x5cd, 0x5cf, 0x7, 0x23, 0x2, 0x2, 0x5ce, 
       0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5cf, 
       0x5d0, 0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5d2, 0x5, 0xac, 0x57, 0x2, 0x5d1, 
       0x5ce, 0x3, 0x2, 0x2, 0x2, 0x5d1, 0x5d2, 0x3, 0x2, 0x2, 0x2, 0x5d2, 
       0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5d3, 0x594, 0x3, 0x2, 0x2, 0x2, 0x5d3, 
       0x5a7, 0x3, 0x2, 0x2, 0x2, 0x5d3, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0x5d3, 
       0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5d4, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x5d5, 
       0x5dc, 0x5, 0x6e, 0x38, 0x2, 0x5d6, 0x5d7, 0x5, 0x72, 0x3a, 0x2, 
       0x5d7, 0x5d8, 0x5, 0x6e, 0x38, 0x2, 0x5d8, 0x5d9, 0x5, 0x74, 0x3b, 
       0x2, 0x5d9, 0x5db, 0x3, 0x2, 0x2, 0x2, 0x5da, 0x5d6, 0x3, 0x2, 0x2, 
       0x2, 0x5db, 0x5de, 0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 
       0x2, 0x5dc, 0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x71, 0x3, 0x2, 0x2, 
       0x2, 0x5de, 0x5dc, 0x3, 0x2, 0x2, 0x2, 0x5df, 0x5ed, 0x7, 0x7, 0x2, 
       0x2, 0x5e0, 0x5e2, 0x7, 0x66, 0x2, 0x2, 0x5e1, 0x5e0, 0x3, 0x2, 0x2, 
       0x2, 0x5e1, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e9, 0x3, 0x2, 0x2, 
       0x2, 0x5e3, 0x5e5, 0x7, 0x62, 0x2, 0x2, 0x5e4, 0x5e6, 0x7, 0x70, 
       0x2, 0x2, 0x5e5, 0x5e4, 0x3, 0x2, 0x2, 0x2, 0x5e5, 0x5e6, 0x3, 0x2, 
       0x2, 0x2, 0x5e6, 0x5ea, 0x3, 0x2, 0x2, 0x2, 0x5e7, 0x5ea, 0x7, 0x59, 
       0x2, 0x2, 0x5e8, 0x5ea, 0x7, 0x35, 0x2, 0x2, 0x5e9, 0x5e3, 0x3, 0x2, 
       0x2, 0x2, 0x5e9, 0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5e9, 0x5e8, 0x3, 0x2, 
       0x2, 0x2, 0x5e9, 0x5ea, 0x3, 0x2, 0x2, 0x2, 0x5ea, 0x5eb, 0x3, 0x2, 
       0x2, 0x2, 0x5eb, 0x5ed, 0x7, 0x60, 0x2, 0x2, 0x5ec, 0x5df, 0x3, 0x2, 
       0x2, 0x2, 0x5ec, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5ed, 0x73, 0x3, 0x2, 
       0x2, 0x2, 0x5ee, 0x5ef, 0x7, 0x6d, 0x2, 0x2, 0x5ef, 0x5fd, 0x5, 0x58, 
       0x2d, 0x2, 0x5f0, 0x5f1, 0x7, 0x8e, 0x2, 0x2, 0x5f1, 0x5f2, 0x7, 
       0x5, 0x2, 0x2, 0x5f2, 0x5f7, 0x5, 0x9a, 0x4e, 0x2, 0x5f3, 0x5f4, 
       0x7, 0x7, 0x2, 0x2, 0x5f4, 0x5f6, 0x5, 0x9a, 0x4e, 0x2, 0x5f5, 0x5f3, 
       0x3, 0x2, 0x2, 0x2, 0x5f6, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f5, 
       0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5f8, 0x5fa, 
       0x3, 0x2, 0x2, 0x2, 0x5f9, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5fa, 0x5fb, 
       0x7, 0x6, 0x2, 0x2, 0x5fb, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x5ee, 
       0x3, 0x2, 0x2, 0x2, 0x5fc, 0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x5fd, 
       0x3, 0x2, 0x2, 0x2, 0x5fd, 0x75, 0x3, 0x2, 0x2, 0x2, 0x5fe, 0x603, 
       0x5, 0x6c, 0x37, 0x2, 0x5ff, 0x600, 0x7, 0x7, 0x2, 0x2, 0x600, 0x602, 
       0x5, 0x6c, 0x37, 0x2, 0x601, 0x5ff, 0x3, 0x2, 0x2, 0x2, 0x602, 0x605, 
       0x3, 0x2, 0x2, 0x2, 0x603, 0x601, 0x3, 0x2, 0x2, 0x2, 0x603, 0x604, 
       0x3, 0x2, 0x2, 0x2, 0x604, 0x77, 0x3, 0x2, 0x2, 0x2, 0x605, 0x603, 
       0x3, 0x2, 0x2, 0x2, 0x606, 0x608, 0x7, 0x82, 0x2, 0x2, 0x607, 0x609, 
       0x9, 0x6, 0x2, 0x2, 0x608, 0x607, 0x3, 0x2, 0x2, 0x2, 0x608, 0x609, 
       0x3, 0x2, 0x2, 0x2, 0x609, 0x60a, 0x3, 0x2, 0x2, 0x2, 0x60a, 0x617, 
       0x5, 0x76, 0x3c, 0x2, 0x60b, 0x615, 0x7, 0x4d, 0x2, 0x2, 0x60c, 0x611, 
       0x5, 0x6e, 0x38, 0x2, 0x60d, 0x60e, 0x7, 0x7, 0x2, 0x2, 0x60e, 0x610, 
       0x5, 0x6e, 0x38, 0x2, 0x60f, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x610, 0x613, 
       0x3, 0x2, 0x2, 0x2, 0x611, 0x60f, 0x3, 0x2, 0x2, 0x2, 0x611, 0x612, 
       0x3, 0x2, 0x2, 0x2, 0x612, 0x616, 0x3, 0x2, 0x2, 0x2, 0x613, 0x611, 
       0x3, 0x2, 0x2, 0x2, 0x614, 0x616, 0x5, 0x70, 0x39, 0x2, 0x615, 0x60c, 
       0x3, 0x2, 0x2, 0x2, 0x615, 0x614, 0x3, 0x2, 0x2, 0x2, 0x616, 0x618, 
       0x3, 0x2, 0x2, 0x2, 0x617, 0x60b, 0x3, 0x2, 0x2, 0x2, 0x617, 0x618, 
       0x3, 0x2, 0x2, 0x2, 0x618, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x619, 0x61a, 
       0x7, 0x94, 0x2, 0x2, 0x61a, 0x61c, 0x5, 0x58, 0x2d, 0x2, 0x61b, 0x619, 
       0x3, 0x2, 0x2, 0x2, 0x61b, 0x61c, 0x3, 0x2, 0x2, 0x2, 0x61c, 0x62b, 
       0x3, 0x2, 0x2, 0x2, 0x61d, 0x61e, 0x7, 0x50, 0x2, 0x2, 0x61e, 0x61f, 
       0x7, 0x2a, 0x2, 0x2, 0x61f, 0x624, 0x5, 0x58, 0x2d, 0x2, 0x620, 0x621, 
       0x7, 0x7, 0x2, 0x2, 0x621, 0x623, 0x5, 0x58, 0x2d, 0x2, 0x622, 0x620, 
       0x3, 0x2, 0x2, 0x2, 0x623, 0x626, 0x3, 0x2, 0x2, 0x2, 0x624, 0x622, 
       0x3, 0x2, 0x2, 0x2, 0x624, 0x625, 0x3, 0x2, 0x2, 0x2, 0x625, 0x629, 
       0x3, 0x2, 0x2, 0x2, 0x626, 0x624, 0x3, 0x2, 0x2, 0x2, 0x627, 0x628, 
       0x7, 0x51, 0x2, 0x2, 0x628, 0x62a, 0x5, 0x58, 0x2d, 0x2, 0x629, 0x627, 
       0x3, 0x2, 0x2, 0x2, 0x629, 0x62a, 0x3, 0x2, 0x2, 0x2, 0x62a, 0x62c, 
       0x3, 0x2, 0x2, 0x2, 0x62b, 0x61d, 0x3, 0x2, 0x2, 0x2, 0x62b, 0x62c, 
       0x3, 0x2, 0x2, 0x2, 0x62c, 0x64a, 0x3, 0x2, 0x2, 0x2, 0x62d, 0x62e, 
       0x7, 0x90, 0x2, 0x2, 0x62e, 0x62f, 0x7, 0x5, 0x2, 0x2, 0x62f, 0x634, 
       0x5, 0x58, 0x2d, 0x2, 0x630, 0x631, 0x7, 0x7, 0x2, 0x2, 0x631, 0x633, 
       0x5, 0x58, 0x2d, 0x2, 0x632, 0x630, 0x3, 0x2, 0x2, 0x2, 0x633, 0x636, 
       0x3, 0x2, 0x2, 0x2, 0x634, 0x632, 0x3, 0x2, 0x2, 0x2, 0x634, 0x635, 
       0x3, 0x2, 0x2, 0x2, 0x635, 0x637, 0x3, 0x2, 0x2, 0x2, 0x636, 0x634, 
       0x3, 0x2, 0x2, 0x2, 0x637, 0x646, 0x7, 0x6, 0x2, 0x2, 0x638, 0x639, 
       0x7, 0x7, 0x2, 0x2, 0x639, 0x63a, 0x7, 0x5, 0x2, 0x2, 0x63a, 0x63f, 
       0x5, 0x58, 0x2d, 0x2, 0x63b, 0x63c, 0x7, 0x7, 0x2, 0x2, 0x63c, 0x63e, 
       0x5, 0x58, 0x2d, 0x2, 0x63d, 0x63b, 0x3, 0x2, 0x2, 0x2, 0x63e, 0x641, 
       0x3, 0x2, 0x2, 0x2, 0x63f, 0x63d, 0x3, 0x2, 0x2, 0x2, 0x63f, 0x640, 
       0x3, 0x2, 0x2, 0x2, 0x640, 0x642, 0x3, 0x2, 0x2, 0x2, 0x641, 0x63f, 
       0x3, 0x2, 0x2, 0x2, 0x642, 0x643, 0x7, 0x6, 0x2, 0x2, 0x643, 0x645, 
       0x3, 0x2, 0x2, 0x2, 0x644, 0x638, 0x3, 0x2, 0x2, 0x2, 0x645, 0x648, 
       0x3, 0x2, 0x2, 0x2, 0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x646, 0x647, 
       0x3, 0x2, 0x2, 0x2, 0x647, 0x64a, 0x3, 0x2, 0x2, 0x2, 0x648, 0x646, 
       0x3, 0x2, 0x2, 0x2, 0x649, 0x606, 0x3, 0x2, 0x2, 0x2, 0x649, 0x62d, 
       0x3, 0x2, 0x2, 0x2, 0x64a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x64b, 0x651, 
       0x7, 0x8b, 0x2, 0x2, 0x64c, 0x64d, 0x7, 0x8b, 0x2, 0x2, 0x64d, 0x651, 
       0x7, 0x1f, 0x2, 0x2, 0x64e, 0x651, 0x7, 0x5c, 0x2, 0x2, 0x64f, 0x651, 
       0x7, 0x46, 0x2, 0x2, 0x650, 0x64b, 0x3, 0x2, 0x2, 0x2, 0x650, 0x64c, 
       0x3, 0x2, 0x2, 0x2, 0x650, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x650, 0x64f, 
       0x3, 0x2, 0x2, 0x2, 0x651, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x652, 0x654, 
       0x9, 0xa, 0x2, 0x2, 0x653, 0x652, 0x3, 0x2, 0x2, 0x2, 0x653, 0x654, 
       0x3, 0x2, 0x2, 0x2, 0x654, 0x655, 0x3, 0x2, 0x2, 0x2, 0x655, 0x656, 
       0x7, 0x98, 0x2, 0x2, 0x656, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x657, 0x658, 
       0x9, 0x11, 0x2, 0x2, 0x658, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x659, 0x65a, 
       0x9, 0x12, 0x2, 0x2, 0x65a, 0x81, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x65c, 
       0x7, 0x9a, 0x2, 0x2, 0x65c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x65d, 0x660, 
       0x5, 0x58, 0x2d, 0x2, 0x65e, 0x660, 0x5, 0x50, 0x29, 0x2, 0x65f, 
       0x65d, 0x3, 0x2, 0x2, 0x2, 0x65f, 0x65e, 0x3, 0x2, 0x2, 0x2, 0x660, 
       0x85, 0x3, 0x2, 0x2, 0x2, 0x661, 0x662, 0x9, 0x13, 0x2, 0x2, 0x662, 
       0x87, 0x3, 0x2, 0x2, 0x2, 0x663, 0x664, 0x9, 0x14, 0x2, 0x2, 0x664, 
       0x89, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 0x5, 0xb0, 0x59, 0x2, 0x666, 
       0x8b, 0x3, 0x2, 0x2, 0x2, 0x667, 0x668, 0x5, 0xb0, 0x59, 0x2, 0x668, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x669, 0x66a, 0x5, 0xb0, 0x59, 0x2, 0x66a, 
       0x8f, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66c, 0x5, 0xb0, 0x59, 0x2, 0x66c, 
       0x91, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x66e, 0x5, 0xb0, 0x59, 0x2, 0x66e, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x66f, 0x670, 0x5, 0xb0, 0x59, 0x2, 0x670, 
       0x95, 0x3, 0x2, 0x2, 0x2, 0x671, 0x672, 0x5, 0xb0, 0x59, 0x2, 0x672, 
       0x97, 0x3, 0x2, 0x2, 0x2, 0x673, 0x674, 0x5, 0xb0, 0x59, 0x2, 0x674, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0x675, 0x676, 0x5, 0xb0, 0x59, 0x2, 0x676, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x677, 0x678, 0x5, 0xb0, 0x59, 0x2, 0x678, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x679, 0x67a, 0x5, 0xb0, 0x59, 0x2, 0x67a, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67c, 0x5, 0xb0, 0x59, 0x2, 0x67c, 
       0xa1, 0x3, 0x2, 0x2, 0x2, 0x67d, 0x67e, 0x5, 0xb0, 0x59, 0x2, 0x67e, 
       0xa3, 0x3, 0x2, 0x2, 0x2, 0x67f, 0x680, 0x5, 0xb0, 0x59, 0x2, 0x680, 
       0xa5, 0x3, 0x2, 0x2, 0x2, 0x681, 0x682, 0x5, 0xb0, 0x59, 0x2, 0x682, 
       0xa7, 0x3, 0x2, 0x2, 0x2, 0x683, 0x684, 0x5, 0xb0, 0x59, 0x2, 0x684, 
       0xa9, 0x3, 0x2, 0x2, 0x2, 0x685, 0x686, 0x5, 0xb0, 0x59, 0x2, 0x686, 
       0xab, 0x3, 0x2, 0x2, 0x2, 0x687, 0x68e, 0x7, 0x97, 0x2, 0x2, 0x688, 
       0x68e, 0x7, 0x9a, 0x2, 0x2, 0x689, 0x68a, 0x7, 0x5, 0x2, 0x2, 0x68a, 
       0x68b, 0x5, 0xac, 0x57, 0x2, 0x68b, 0x68c, 0x7, 0x6, 0x2, 0x2, 0x68c, 
       0x68e, 0x3, 0x2, 0x2, 0x2, 0x68d, 0x687, 0x3, 0x2, 0x2, 0x2, 0x68d, 
       0x688, 0x3, 0x2, 0x2, 0x2, 0x68d, 0x689, 0x3, 0x2, 0x2, 0x2, 0x68e, 
       0xad, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x690, 0x5, 0xb0, 0x59, 0x2, 0x690, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0x691, 0x699, 0x7, 0x97, 0x2, 0x2, 0x692, 
       0x699, 0x5, 0x88, 0x45, 0x2, 0x693, 0x699, 0x7, 0x9a, 0x2, 0x2, 0x694, 
       0x695, 0x7, 0x5, 0x2, 0x2, 0x695, 0x696, 0x5, 0xb0, 0x59, 0x2, 0x696, 
       0x697, 0x7, 0x6, 0x2, 0x2, 0x697, 0x699, 0x3, 0x2, 0x2, 0x2, 0x698, 
       0x691, 0x3, 0x2, 0x2, 0x2, 0x698, 0x692, 0x3, 0x2, 0x2, 0x2, 0x698, 
       0x693, 0x3, 0x2, 0x2, 0x2, 0x698, 0x694, 0x3, 0x2, 0x2, 0x2, 0x699, 
       0xb1, 0x3, 0x2, 0x2, 0x2, 0xee, 0xb4, 0xb6, 0xc1, 0xc8, 0xcd, 0xd3, 
       0xd9, 0xdb, 0xfb, 0x102, 0x10a, 0x10d, 0x116, 0x11a, 0x122, 0x126, 
       0x128, 0x12d, 0x12f, 0x132, 0x137, 0x13b, 0x140, 0x149, 0x14c, 0x152, 
       0x154, 0x158, 0x15e, 0x163, 0x16e, 0x174, 0x178, 0x17e, 0x183, 0x18c, 
       0x193, 0x199, 0x19d, 0x1a1, 0x1a7, 0x1ac, 0x1b3, 0x1be, 0x1c1, 0x1c3, 
       0x1c9, 0x1cf, 0x1d3, 0x1da, 0x1e0, 0x1e6, 0x1ec, 0x1f1, 0x1fd, 0x202, 
       0x20d, 0x212, 0x215, 0x21c, 0x21f, 0x226, 0x22f, 0x232, 0x238, 0x23a, 
       0x23e, 0x246, 0x24b, 0x253, 0x258, 0x260, 0x265, 0x26d, 0x272, 0x277, 
       0x27f, 0x289, 0x28c, 0x292, 0x294, 0x2a7, 0x2af, 0x2b9, 0x2c2, 0x2c8, 
       0x2cf, 0x2d3, 0x2da, 0x2e0, 0x2e9, 0x2f0, 0x2f4, 0x2f6, 0x2fa, 0x301, 
       0x303, 0x307, 0x30a, 0x310, 0x31a, 0x31d, 0x323, 0x325, 0x328, 0x330, 
       0x33a, 0x33d, 0x343, 0x345, 0x349, 0x350, 0x359, 0x35d, 0x35f, 0x363, 
       0x36c, 0x371, 0x373, 0x37c, 0x387, 0x38e, 0x391, 0x394, 0x3a1, 0x3af, 
       0x3b4, 0x3b7, 0x3c4, 0x3d2, 0x3d7, 0x3e0, 0x3e3, 0x3e9, 0x3eb, 0x3f1, 
       0x3f6, 0x3fc, 0x408, 0x40c, 0x411, 0x415, 0x418, 0x42a, 0x42f, 0x434, 
       0x43c, 0x441, 0x44a, 0x451, 0x455, 0x465, 0x468, 0x470, 0x479, 0x47d, 
       0x482, 0x49f, 0x4a4, 0x4ad, 0x4b7, 0x4ba, 0x4c0, 0x4c3, 0x4ca, 0x4d0, 
       0x4d7, 0x4d9, 0x4db, 0x4e6, 0x4eb, 0x4f7, 0x4fb, 0x4ff, 0x503, 0x50a, 
       0x50c, 0x514, 0x51b, 0x51e, 0x522, 0x527, 0x52f, 0x542, 0x548, 0x54c, 
       0x553, 0x559, 0x561, 0x566, 0x569, 0x56e, 0x577, 0x57c, 0x58a, 0x58d, 
       0x58f, 0x594, 0x598, 0x59b, 0x5a2, 0x5a7, 0x5b0, 0x5b3, 0x5b7, 0x5ba, 
       0x5c2, 0x5c6, 0x5ce, 0x5d1, 0x5d3, 0x5dc, 0x5e1, 0x5e5, 0x5e9, 0x5ec, 
       0x5f7, 0x5fc, 0x603, 0x608, 0x611, 0x615, 0x617, 0x61b, 0x624, 0x629, 
       0x62b, 0x634, 0x63f, 0x646, 0x649, 0x650, 0x653, 0x65f, 0x68d, 0x698, 
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
