
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.1


#include "PotatoSQLListener.h"
#include "PotatoSQLVisitor.h"

#include "PotatoSQLParser.h"


using namespace antlrcpp;
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
    setState(194);
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
      | (1ULL << PotatoSQLParser::K_DESCRIBE)
      | (1ULL << PotatoSQLParser::K_DETACH))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (PotatoSQLParser::K_DROP - 64))
      | (1ULL << (PotatoSQLParser::K_END - 64))
      | (1ULL << (PotatoSQLParser::K_EXPLAIN - 64))
      | (1ULL << (PotatoSQLParser::K_INSERT - 64))
      | (1ULL << (PotatoSQLParser::K_PRAGMA - 64))
      | (1ULL << (PotatoSQLParser::K_REINDEX - 64))
      | (1ULL << (PotatoSQLParser::K_RELEASE - 64))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 64))
      | (1ULL << (PotatoSQLParser::K_ROLLBACK - 64)))) != 0) || ((((_la - 129) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 129)) & ((1ULL << (PotatoSQLParser::K_SAVEPOINT - 129))
      | (1ULL << (PotatoSQLParser::K_SELECT - 129))
      | (1ULL << (PotatoSQLParser::K_SHOW - 129))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 129))
      | (1ULL << (PotatoSQLParser::K_VACUUM - 129))
      | (1ULL << (PotatoSQLParser::K_VALUES - 129))
      | (1ULL << (PotatoSQLParser::K_WITH - 129))
      | (1ULL << (PotatoSQLParser::UNEXPECTED_CHAR - 129)))) != 0)) {
      setState(192);
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
        case PotatoSQLParser::K_DESCRIBE:
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
        case PotatoSQLParser::K_SHOW:
        case PotatoSQLParser::K_UPDATE:
        case PotatoSQLParser::K_VACUUM:
        case PotatoSQLParser::K_VALUES:
        case PotatoSQLParser::K_WITH: {
          setState(190);
          sql_stmt_list();
          break;
        }

        case PotatoSQLParser::UNEXPECTED_CHAR: {
          setState(191);
          error();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(196);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(197);
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
    setState(199);
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
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::SCOL) {
      setState(202);
      match(PotatoSQLParser::SCOL);
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(208);
    sql_stmt();
    setState(217);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(210); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(209);
          match(PotatoSQLParser::SCOL);
          setState(212); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PotatoSQLParser::SCOL);
        setState(214);
        sql_stmt(); 
      }
      setState(219);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(223);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(220);
        match(PotatoSQLParser::SCOL); 
      }
      setState(225);
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

PotatoSQLParser::Describe_table_stmtContext* PotatoSQLParser::Sql_stmtContext::describe_table_stmt() {
  return getRuleContext<PotatoSQLParser::Describe_table_stmtContext>(0);
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

PotatoSQLParser::Show_tables_stmtContext* PotatoSQLParser::Sql_stmtContext::show_tables_stmt() {
  return getRuleContext<PotatoSQLParser::Show_tables_stmtContext>(0);
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
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_EXPLAIN) {
      setState(226);
      match(PotatoSQLParser::K_EXPLAIN);
      setState(229);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_QUERY) {
        setState(227);
        match(PotatoSQLParser::K_QUERY);
        setState(228);
        match(PotatoSQLParser::K_PLAN);
      }
    }
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(233);
      alter_table_stmt();
      break;
    }

    case 2: {
      setState(234);
      analyze_stmt();
      break;
    }

    case 3: {
      setState(235);
      attach_stmt();
      break;
    }

    case 4: {
      setState(236);
      begin_stmt();
      break;
    }

    case 5: {
      setState(237);
      commit_stmt();
      break;
    }

    case 6: {
      setState(238);
      compound_select_stmt();
      break;
    }

    case 7: {
      setState(239);
      create_index_stmt();
      break;
    }

    case 8: {
      setState(240);
      create_table_stmt();
      break;
    }

    case 9: {
      setState(241);
      create_trigger_stmt();
      break;
    }

    case 10: {
      setState(242);
      create_view_stmt();
      break;
    }

    case 11: {
      setState(243);
      create_virtual_table_stmt();
      break;
    }

    case 12: {
      setState(244);
      delete_stmt();
      break;
    }

    case 13: {
      setState(245);
      delete_stmt_limited();
      break;
    }

    case 14: {
      setState(246);
      describe_table_stmt();
      break;
    }

    case 15: {
      setState(247);
      detach_stmt();
      break;
    }

    case 16: {
      setState(248);
      drop_index_stmt();
      break;
    }

    case 17: {
      setState(249);
      drop_table_stmt();
      break;
    }

    case 18: {
      setState(250);
      drop_trigger_stmt();
      break;
    }

    case 19: {
      setState(251);
      drop_view_stmt();
      break;
    }

    case 20: {
      setState(252);
      factored_select_stmt();
      break;
    }

    case 21: {
      setState(253);
      insert_stmt();
      break;
    }

    case 22: {
      setState(254);
      pragma_stmt();
      break;
    }

    case 23: {
      setState(255);
      reindex_stmt();
      break;
    }

    case 24: {
      setState(256);
      release_stmt();
      break;
    }

    case 25: {
      setState(257);
      rollback_stmt();
      break;
    }

    case 26: {
      setState(258);
      savepoint_stmt();
      break;
    }

    case 27: {
      setState(259);
      simple_select_stmt();
      break;
    }

    case 28: {
      setState(260);
      select_stmt();
      break;
    }

    case 29: {
      setState(261);
      show_tables_stmt();
      break;
    }

    case 30: {
      setState(262);
      update_stmt();
      break;
    }

    case 31: {
      setState(263);
      update_stmt_limited();
      break;
    }

    case 32: {
      setState(264);
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
    setState(267);
    match(PotatoSQLParser::K_ALTER);
    setState(268);
    match(PotatoSQLParser::K_TABLE);
    setState(272);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(269);
      database_name();
      setState(270);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(274);
    table_name();
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_RENAME: {
        setState(275);
        match(PotatoSQLParser::K_RENAME);
        setState(276);
        match(PotatoSQLParser::K_TO);
        setState(277);
        new_table_name();
        break;
      }

      case PotatoSQLParser::K_ADD: {
        setState(278);
        match(PotatoSQLParser::K_ADD);
        setState(280);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(279);
          match(PotatoSQLParser::K_COLUMN);
          break;
        }

        default:
          break;
        }
        setState(282);
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

//----------------- Show_tables_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Show_tables_stmtContext::Show_tables_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Show_tables_stmtContext::K_SHOW() {
  return getToken(PotatoSQLParser::K_SHOW, 0);
}

tree::TerminalNode* PotatoSQLParser::Show_tables_stmtContext::K_TABLES() {
  return getToken(PotatoSQLParser::K_TABLES, 0);
}


size_t PotatoSQLParser::Show_tables_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleShow_tables_stmt;
}

void PotatoSQLParser::Show_tables_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow_tables_stmt(this);
}

void PotatoSQLParser::Show_tables_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow_tables_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Show_tables_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitShow_tables_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Show_tables_stmtContext* PotatoSQLParser::show_tables_stmt() {
  Show_tables_stmtContext *_localctx = _tracker.createInstance<Show_tables_stmtContext>(_ctx, getState());
  enterRule(_localctx, 10, PotatoSQLParser::RuleShow_tables_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    match(PotatoSQLParser::K_SHOW);
    setState(286);
    match(PotatoSQLParser::K_TABLES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Describe_table_stmtContext ------------------------------------------------------------------

PotatoSQLParser::Describe_table_stmtContext::Describe_table_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Describe_table_stmtContext::K_DESCRIBE() {
  return getToken(PotatoSQLParser::K_DESCRIBE, 0);
}

tree::TerminalNode* PotatoSQLParser::Describe_table_stmtContext::K_TABLE() {
  return getToken(PotatoSQLParser::K_TABLE, 0);
}

PotatoSQLParser::Table_nameContext* PotatoSQLParser::Describe_table_stmtContext::table_name() {
  return getRuleContext<PotatoSQLParser::Table_nameContext>(0);
}


size_t PotatoSQLParser::Describe_table_stmtContext::getRuleIndex() const {
  return PotatoSQLParser::RuleDescribe_table_stmt;
}

void PotatoSQLParser::Describe_table_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescribe_table_stmt(this);
}

void PotatoSQLParser::Describe_table_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescribe_table_stmt(this);
}


antlrcpp::Any PotatoSQLParser::Describe_table_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitDescribe_table_stmt(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Describe_table_stmtContext* PotatoSQLParser::describe_table_stmt() {
  Describe_table_stmtContext *_localctx = _tracker.createInstance<Describe_table_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, PotatoSQLParser::RuleDescribe_table_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(PotatoSQLParser::K_DESCRIBE);
    setState(289);
    match(PotatoSQLParser::K_TABLE);
    setState(290);
    table_name();
   
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
  enterRule(_localctx, 14, PotatoSQLParser::RuleAnalyze_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(PotatoSQLParser::K_ANALYZE);
    setState(299);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(293);
      database_name();
      break;
    }

    case 2: {
      setState(294);
      table_or_index_name();
      break;
    }

    case 3: {
      setState(295);
      database_name();
      setState(296);
      match(PotatoSQLParser::DOT);
      setState(297);
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
  enterRule(_localctx, 16, PotatoSQLParser::RuleAttach_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(PotatoSQLParser::K_ATTACH);
    setState(303);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(302);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(305);
    expr(0);
    setState(306);
    match(PotatoSQLParser::K_AS);
    setState(307);
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
  enterRule(_localctx, 18, PotatoSQLParser::RuleBegin_stmt);
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
    setState(309);
    match(PotatoSQLParser::K_BEGIN);
    setState(311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (PotatoSQLParser::K_DEFERRED - 58))
      | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 58))
      | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 58)))) != 0)) {
      setState(310);
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
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(313);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(315);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(314);
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
  enterRule(_localctx, 20, PotatoSQLParser::RuleCommit_stmt);
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
    setState(319);
    _la = _input->LA(1);
    if (!(_la == PotatoSQLParser::K_COMMIT

    || _la == PotatoSQLParser::K_END)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(324);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(320);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(322);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(321);
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
  enterRule(_localctx, 22, PotatoSQLParser::RuleCompound_select_stmt);
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
    setState(327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(326);
      with_clause();
    }
    setState(329);
    select_core();
    setState(339); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(336);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_UNION: {
          setState(330);
          match(PotatoSQLParser::K_UNION);
          setState(332);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_ALL) {
            setState(331);
            match(PotatoSQLParser::K_ALL);
          }
          break;
        }

        case PotatoSQLParser::K_INTERSECT: {
          setState(334);
          match(PotatoSQLParser::K_INTERSECT);
          break;
        }

        case PotatoSQLParser::K_EXCEPT: {
          setState(335);
          match(PotatoSQLParser::K_EXCEPT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(338);
      select_core();
      setState(341); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION);
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(343);
      match(PotatoSQLParser::K_ORDER);
      setState(344);
      match(PotatoSQLParser::K_BY);
      setState(345);
      ordering_term();
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(346);
        match(PotatoSQLParser::COMMA);
        setState(347);
        ordering_term();
        setState(352);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(361);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(355);
      match(PotatoSQLParser::K_LIMIT);
      setState(356);
      expr(0);
      setState(359);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(357);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(358);
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
  enterRule(_localctx, 24, PotatoSQLParser::RuleCreate_index_stmt);
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
    setState(363);
    match(PotatoSQLParser::K_CREATE);
    setState(365);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_UNIQUE) {
      setState(364);
      match(PotatoSQLParser::K_UNIQUE);
    }
    setState(367);
    match(PotatoSQLParser::K_INDEX);
    setState(371);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(368);
      match(PotatoSQLParser::K_IF);
      setState(369);
      match(PotatoSQLParser::K_NOT);
      setState(370);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(376);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(373);
      database_name();
      setState(374);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(378);
    index_name();
    setState(379);
    match(PotatoSQLParser::K_ON);
    setState(380);
    table_name();
    setState(381);
    match(PotatoSQLParser::OPEN_PAR);
    setState(382);
    indexed_column();
    setState(387);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(383);
      match(PotatoSQLParser::COMMA);
      setState(384);
      indexed_column();
      setState(389);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(390);
    match(PotatoSQLParser::CLOSE_PAR);
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(391);
      match(PotatoSQLParser::K_WHERE);
      setState(392);
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
  enterRule(_localctx, 26, PotatoSQLParser::RuleCreate_table_stmt);
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
    setState(395);
    match(PotatoSQLParser::K_CREATE);
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(396);
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
    setState(399);
    match(PotatoSQLParser::K_TABLE);
    setState(403);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(400);
      match(PotatoSQLParser::K_IF);
      setState(401);
      match(PotatoSQLParser::K_NOT);
      setState(402);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(408);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(405);
      database_name();
      setState(406);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(410);
    table_name();
    setState(434);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::OPEN_PAR: {
        setState(411);
        match(PotatoSQLParser::OPEN_PAR);
        setState(412);
        column_def();
        setState(417);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1 + 1) {
            setState(413);
            match(PotatoSQLParser::COMMA);
            setState(414);
            column_def(); 
          }
          setState(419);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        }
        setState(424);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(420);
          match(PotatoSQLParser::COMMA);
          setState(421);
          table_constraint();
          setState(426);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(427);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(430);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WITHOUT) {
          setState(428);
          match(PotatoSQLParser::K_WITHOUT);
          setState(429);
          match(PotatoSQLParser::IDENTIFIER);
        }
        break;
      }

      case PotatoSQLParser::K_AS: {
        setState(432);
        match(PotatoSQLParser::K_AS);
        setState(433);
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
  enterRule(_localctx, 28, PotatoSQLParser::RuleCreate_trigger_stmt);
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
    setState(436);
    match(PotatoSQLParser::K_CREATE);
    setState(438);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(437);
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
    setState(440);
    match(PotatoSQLParser::K_TRIGGER);
    setState(444);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(441);
      match(PotatoSQLParser::K_IF);
      setState(442);
      match(PotatoSQLParser::K_NOT);
      setState(443);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(449);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(446);
      database_name();
      setState(447);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(451);
    trigger_name();
    setState(456);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_BEFORE: {
        setState(452);
        match(PotatoSQLParser::K_BEFORE);
        break;
      }

      case PotatoSQLParser::K_AFTER: {
        setState(453);
        match(PotatoSQLParser::K_AFTER);
        break;
      }

      case PotatoSQLParser::K_INSTEAD: {
        setState(454);
        match(PotatoSQLParser::K_INSTEAD);
        setState(455);
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
    setState(472);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_DELETE: {
        setState(458);
        match(PotatoSQLParser::K_DELETE);
        break;
      }

      case PotatoSQLParser::K_INSERT: {
        setState(459);
        match(PotatoSQLParser::K_INSERT);
        break;
      }

      case PotatoSQLParser::K_UPDATE: {
        setState(460);
        match(PotatoSQLParser::K_UPDATE);
        setState(470);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_OF) {
          setState(461);
          match(PotatoSQLParser::K_OF);
          setState(462);
          column_name();
          setState(467);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(463);
            match(PotatoSQLParser::COMMA);
            setState(464);
            column_name();
            setState(469);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(474);
    match(PotatoSQLParser::K_ON);
    setState(478);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(475);
      database_name();
      setState(476);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(480);
    table_name();
    setState(484);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_FOR) {
      setState(481);
      match(PotatoSQLParser::K_FOR);
      setState(482);
      match(PotatoSQLParser::K_EACH);
      setState(483);
      match(PotatoSQLParser::K_ROW);
    }
    setState(488);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHEN) {
      setState(486);
      match(PotatoSQLParser::K_WHEN);
      setState(487);
      expr(0);
    }
    setState(490);
    match(PotatoSQLParser::K_BEGIN);
    setState(499); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(495);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(491);
        update_stmt();
        break;
      }

      case 2: {
        setState(492);
        insert_stmt();
        break;
      }

      case 3: {
        setState(493);
        delete_stmt();
        break;
      }

      case 4: {
        setState(494);
        select_stmt();
        break;
      }

      default:
        break;
      }
      setState(497);
      match(PotatoSQLParser::SCOL);
      setState(501); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_DELETE || ((((_la - 90) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 90)) & ((1ULL << (PotatoSQLParser::K_INSERT - 90))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 90))
      | (1ULL << (PotatoSQLParser::K_SELECT - 90))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 90))
      | (1ULL << (PotatoSQLParser::K_VALUES - 90))
      | (1ULL << (PotatoSQLParser::K_WITH - 90)))) != 0));
    setState(503);
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
  enterRule(_localctx, 30, PotatoSQLParser::RuleCreate_view_stmt);
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
    match(PotatoSQLParser::K_CREATE);
    setState(507);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(506);
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
    setState(509);
    match(PotatoSQLParser::K_VIEW);
    setState(513);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(510);
      match(PotatoSQLParser::K_IF);
      setState(511);
      match(PotatoSQLParser::K_NOT);
      setState(512);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(518);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(515);
      database_name();
      setState(516);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(520);
    view_name();
    setState(521);
    match(PotatoSQLParser::K_AS);
    setState(522);
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
  enterRule(_localctx, 32, PotatoSQLParser::RuleCreate_virtual_table_stmt);
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
    setState(524);
    match(PotatoSQLParser::K_CREATE);
    setState(525);
    match(PotatoSQLParser::K_VIRTUAL);
    setState(526);
    match(PotatoSQLParser::K_TABLE);
    setState(530);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      setState(527);
      match(PotatoSQLParser::K_IF);
      setState(528);
      match(PotatoSQLParser::K_NOT);
      setState(529);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(535);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(532);
      database_name();
      setState(533);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(537);
    table_name();
    setState(538);
    match(PotatoSQLParser::K_USING);
    setState(539);
    module_name();
    setState(551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(540);
      match(PotatoSQLParser::OPEN_PAR);
      setState(541);
      module_argument();
      setState(546);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(542);
        match(PotatoSQLParser::COMMA);
        setState(543);
        module_argument();
        setState(548);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(549);
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

PotatoSQLParser::Where_clauseContext* PotatoSQLParser::Delete_stmtContext::where_clause() {
  return getRuleContext<PotatoSQLParser::Where_clauseContext>(0);
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
  enterRule(_localctx, 34, PotatoSQLParser::RuleDelete_stmt);
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
    setState(554);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(553);
      with_clause();
    }
    setState(556);
    match(PotatoSQLParser::K_DELETE);
    setState(557);
    match(PotatoSQLParser::K_FROM);
    setState(558);
    qualified_table_name();
    setState(561);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(559);
      match(PotatoSQLParser::K_WHERE);
      setState(560);
      where_clause();
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
  enterRule(_localctx, 36, PotatoSQLParser::RuleDelete_stmt_limited);
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
    setState(564);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(563);
      with_clause();
    }
    setState(566);
    match(PotatoSQLParser::K_DELETE);
    setState(567);
    match(PotatoSQLParser::K_FROM);
    setState(568);
    qualified_table_name();
    setState(571);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(569);
      match(PotatoSQLParser::K_WHERE);
      setState(570);
      expr(0);
    }
    setState(591);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(583);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(573);
        match(PotatoSQLParser::K_ORDER);
        setState(574);
        match(PotatoSQLParser::K_BY);
        setState(575);
        ordering_term();
        setState(580);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(576);
          match(PotatoSQLParser::COMMA);
          setState(577);
          ordering_term();
          setState(582);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(585);
      match(PotatoSQLParser::K_LIMIT);
      setState(586);
      expr(0);
      setState(589);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(587);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(588);
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
  enterRule(_localctx, 38, PotatoSQLParser::RuleDetach_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    match(PotatoSQLParser::K_DETACH);
    setState(595);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(594);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(597);
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
  enterRule(_localctx, 40, PotatoSQLParser::RuleDrop_index_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(599);
    match(PotatoSQLParser::K_DROP);
    setState(600);
    match(PotatoSQLParser::K_INDEX);
    setState(603);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(601);
      match(PotatoSQLParser::K_IF);
      setState(602);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(608);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(605);
      database_name();
      setState(606);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(610);
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
  enterRule(_localctx, 42, PotatoSQLParser::RuleDrop_table_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(612);
    match(PotatoSQLParser::K_DROP);
    setState(613);
    match(PotatoSQLParser::K_TABLE);
    setState(616);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(614);
      match(PotatoSQLParser::K_IF);
      setState(615);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(621);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      setState(618);
      database_name();
      setState(619);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(623);
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
  enterRule(_localctx, 44, PotatoSQLParser::RuleDrop_trigger_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(625);
    match(PotatoSQLParser::K_DROP);
    setState(626);
    match(PotatoSQLParser::K_TRIGGER);
    setState(629);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      setState(627);
      match(PotatoSQLParser::K_IF);
      setState(628);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(634);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(631);
      database_name();
      setState(632);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(636);
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
  enterRule(_localctx, 46, PotatoSQLParser::RuleDrop_view_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(638);
    match(PotatoSQLParser::K_DROP);
    setState(639);
    match(PotatoSQLParser::K_VIEW);
    setState(642);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(640);
      match(PotatoSQLParser::K_IF);
      setState(641);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(647);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      setState(644);
      database_name();
      setState(645);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(649);
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
  enterRule(_localctx, 48, PotatoSQLParser::RuleFactored_select_stmt);
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
    select_core();
    setState(660);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(655);
      compound_operator();
      setState(656);
      select_core();
      setState(662);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(673);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(663);
      match(PotatoSQLParser::K_ORDER);
      setState(664);
      match(PotatoSQLParser::K_BY);
      setState(665);
      ordering_term();
      setState(670);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(666);
        match(PotatoSQLParser::COMMA);
        setState(667);
        ordering_term();
        setState(672);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(681);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(675);
      match(PotatoSQLParser::K_LIMIT);
      setState(676);
      expr(0);
      setState(679);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(677);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(678);
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
  enterRule(_localctx, 50, PotatoSQLParser::RuleInsert_prefix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(700);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(683);
      match(PotatoSQLParser::K_INSERT);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(684);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(685);
      match(PotatoSQLParser::K_INSERT);
      setState(686);
      match(PotatoSQLParser::K_OR);
      setState(687);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(688);
      match(PotatoSQLParser::K_INSERT);
      setState(689);
      match(PotatoSQLParser::K_OR);
      setState(690);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(691);
      match(PotatoSQLParser::K_INSERT);
      setState(692);
      match(PotatoSQLParser::K_OR);
      setState(693);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(694);
      match(PotatoSQLParser::K_INSERT);
      setState(695);
      match(PotatoSQLParser::K_OR);
      setState(696);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(697);
      match(PotatoSQLParser::K_INSERT);
      setState(698);
      match(PotatoSQLParser::K_OR);
      setState(699);
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
  enterRule(_localctx, 52, PotatoSQLParser::RuleInsert_tuple);
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
    setState(702);
    match(PotatoSQLParser::OPEN_PAR);
    setState(703);
    expr(0);
    setState(708);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(704);
      match(PotatoSQLParser::COMMA);
      setState(705);
      expr(0);
      setState(710);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(711);
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
  enterRule(_localctx, 54, PotatoSQLParser::RuleInsert_tuples);
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
    setState(713);
    insert_tuple();
    setState(718);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(714);
      match(PotatoSQLParser::COMMA);
      setState(715);
      insert_tuple();
      setState(720);
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
  enterRule(_localctx, 56, PotatoSQLParser::RuleInsert_columns);
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
    setState(721);
    match(PotatoSQLParser::OPEN_PAR);
    setState(722);
    column_name();
    setState(727);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(723);
      match(PotatoSQLParser::COMMA);
      setState(724);
      column_name();
      setState(729);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(730);
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
  enterRule(_localctx, 58, PotatoSQLParser::RuleInsert_stmt);
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
    setState(733);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(732);
      with_clause();
    }
    setState(735);
    insert_prefix();
    setState(736);
    match(PotatoSQLParser::K_INTO);
    setState(740);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      setState(737);
      database_name();
      setState(738);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(742);
    table_name();
    setState(744);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(743);
      insert_columns();
    }
    setState(751);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
    case 1: {
      setState(746);
      match(PotatoSQLParser::K_VALUES);
      setState(747);
      insert_tuples();
      break;
    }

    case 2: {
      setState(748);
      select_stmt();
      break;
    }

    case 3: {
      setState(749);
      match(PotatoSQLParser::K_DEFAULT);
      setState(750);
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
  enterRule(_localctx, 60, PotatoSQLParser::RulePragma_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(753);
    match(PotatoSQLParser::K_PRAGMA);
    setState(757);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      setState(754);
      database_name();
      setState(755);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(759);
    pragma_name();
    setState(766);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::ASSIGN: {
        setState(760);
        match(PotatoSQLParser::ASSIGN);
        setState(761);
        pragma_value();
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        setState(762);
        match(PotatoSQLParser::OPEN_PAR);
        setState(763);
        pragma_value();
        setState(764);
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
      case PotatoSQLParser::K_DESCRIBE:
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
      case PotatoSQLParser::K_SHOW:
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
  enterRule(_localctx, 62, PotatoSQLParser::RuleReindex_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(768);
    match(PotatoSQLParser::K_REINDEX);
    setState(779);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
    case 1: {
      setState(769);
      collation_name();
      break;
    }

    case 2: {
      setState(773);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
      case 1: {
        setState(770);
        database_name();
        setState(771);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(777);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
      case 1: {
        setState(775);
        table_name();
        break;
      }

      case 2: {
        setState(776);
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
  enterRule(_localctx, 64, PotatoSQLParser::RuleRelease_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(781);
    match(PotatoSQLParser::K_RELEASE);
    setState(783);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(782);
      match(PotatoSQLParser::K_SAVEPOINT);
      break;
    }

    default:
      break;
    }
    setState(785);
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
  enterRule(_localctx, 66, PotatoSQLParser::RuleRollback_stmt);
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
    setState(787);
    match(PotatoSQLParser::K_ROLLBACK);
    setState(792);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(788);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(790);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
      case 1: {
        setState(789);
        transaction_name();
        break;
      }

      default:
        break;
      }
    }
    setState(799);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TO) {
      setState(794);
      match(PotatoSQLParser::K_TO);
      setState(796);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx)) {
      case 1: {
        setState(795);
        match(PotatoSQLParser::K_SAVEPOINT);
        break;
      }

      default:
        break;
      }
      setState(798);
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
  enterRule(_localctx, 68, PotatoSQLParser::RuleSavepoint_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(801);
    match(PotatoSQLParser::K_SAVEPOINT);
    setState(802);
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
  enterRule(_localctx, 70, PotatoSQLParser::RuleSimple_select_stmt);
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
    setState(805);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(804);
      with_clause();
    }
    setState(807);
    select_core();
    setState(818);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(808);
      match(PotatoSQLParser::K_ORDER);
      setState(809);
      match(PotatoSQLParser::K_BY);
      setState(810);
      ordering_term();
      setState(815);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(811);
        match(PotatoSQLParser::COMMA);
        setState(812);
        ordering_term();
        setState(817);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(826);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(820);
      match(PotatoSQLParser::K_LIMIT);
      setState(821);
      expr(0);
      setState(824);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(822);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(823);
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
  enterRule(_localctx, 72, PotatoSQLParser::RuleSelect_stmt);
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
    setState(829);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(828);
      with_clause();
    }
    setState(831);
    select_or_values();
    setState(837);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(832);
      compound_operator();
      setState(833);
      select_or_values();
      setState(839);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(850);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(840);
      match(PotatoSQLParser::K_ORDER);
      setState(841);
      match(PotatoSQLParser::K_BY);
      setState(842);
      ordering_term();
      setState(847);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(843);
        match(PotatoSQLParser::COMMA);
        setState(844);
        ordering_term();
        setState(849);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(858);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(852);
      match(PotatoSQLParser::K_LIMIT);
      setState(853);
      expr(0);
      setState(856);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(854);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(855);
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
  enterRule(_localctx, 74, PotatoSQLParser::RuleSelect_or_values);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(934);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(860);
        match(PotatoSQLParser::K_SELECT);
        setState(862);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
        case 1: {
          setState(861);
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
        setState(864);
        result_column();
        setState(869);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(865);
          match(PotatoSQLParser::COMMA);
          setState(866);
          result_column();
          setState(871);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(884);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(872);
          match(PotatoSQLParser::K_FROM);
          setState(882);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx)) {
          case 1: {
            setState(873);
            table_or_subquery();
            setState(878);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(874);
              match(PotatoSQLParser::COMMA);
              setState(875);
              table_or_subquery();
              setState(880);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(881);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(888);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(886);
          match(PotatoSQLParser::K_WHERE);
          setState(887);
          expr(0);
        }
        setState(904);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(890);
          match(PotatoSQLParser::K_GROUP);
          setState(891);
          match(PotatoSQLParser::K_BY);
          setState(892);
          expr(0);
          setState(897);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(893);
            match(PotatoSQLParser::COMMA);
            setState(894);
            expr(0);
            setState(899);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(902);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(900);
            match(PotatoSQLParser::K_HAVING);
            setState(901);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(906);
        match(PotatoSQLParser::K_VALUES);
        setState(907);
        match(PotatoSQLParser::OPEN_PAR);
        setState(908);
        expr(0);
        setState(913);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(909);
          match(PotatoSQLParser::COMMA);
          setState(910);
          expr(0);
          setState(915);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(916);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(931);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(917);
          match(PotatoSQLParser::COMMA);
          setState(918);
          match(PotatoSQLParser::OPEN_PAR);
          setState(919);
          expr(0);
          setState(924);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(920);
            match(PotatoSQLParser::COMMA);
            setState(921);
            expr(0);
            setState(926);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(927);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(933);
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

PotatoSQLParser::Where_clauseContext* PotatoSQLParser::Update_stmtContext::where_clause() {
  return getRuleContext<PotatoSQLParser::Where_clauseContext>(0);
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
  enterRule(_localctx, 76, PotatoSQLParser::RuleUpdate_stmt);
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
    setState(937);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(936);
      with_clause();
    }
    setState(939);
    match(PotatoSQLParser::K_UPDATE);
    setState(950);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      setState(940);
      match(PotatoSQLParser::K_OR);
      setState(941);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(942);
      match(PotatoSQLParser::K_OR);
      setState(943);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(944);
      match(PotatoSQLParser::K_OR);
      setState(945);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(946);
      match(PotatoSQLParser::K_OR);
      setState(947);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(948);
      match(PotatoSQLParser::K_OR);
      setState(949);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(952);
    qualified_table_name();
    setState(953);
    match(PotatoSQLParser::K_SET);
    setState(954);
    column_name();
    setState(955);
    match(PotatoSQLParser::ASSIGN);
    setState(956);
    expr(0);
    setState(964);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(957);
      match(PotatoSQLParser::COMMA);
      setState(958);
      column_name();
      setState(959);
      match(PotatoSQLParser::ASSIGN);
      setState(960);
      expr(0);
      setState(966);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(969);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(967);
      match(PotatoSQLParser::K_WHERE);
      setState(968);
      where_clause();
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

PotatoSQLParser::Where_clauseContext* PotatoSQLParser::Update_stmt_limitedContext::where_clause() {
  return getRuleContext<PotatoSQLParser::Where_clauseContext>(0);
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
  enterRule(_localctx, 78, PotatoSQLParser::RuleUpdate_stmt_limited);
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
    setState(972);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(971);
      with_clause();
    }
    setState(974);
    match(PotatoSQLParser::K_UPDATE);
    setState(985);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      setState(975);
      match(PotatoSQLParser::K_OR);
      setState(976);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(977);
      match(PotatoSQLParser::K_OR);
      setState(978);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(979);
      match(PotatoSQLParser::K_OR);
      setState(980);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(981);
      match(PotatoSQLParser::K_OR);
      setState(982);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(983);
      match(PotatoSQLParser::K_OR);
      setState(984);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(987);
    qualified_table_name();
    setState(988);
    match(PotatoSQLParser::K_SET);
    setState(989);
    column_name();
    setState(990);
    match(PotatoSQLParser::ASSIGN);
    setState(991);
    expr(0);
    setState(999);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(992);
      match(PotatoSQLParser::COMMA);
      setState(993);
      column_name();
      setState(994);
      match(PotatoSQLParser::ASSIGN);
      setState(995);
      expr(0);
      setState(1001);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1004);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(1002);
      match(PotatoSQLParser::K_WHERE);
      setState(1003);
      where_clause();
    }
    setState(1024);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(1016);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(1006);
        match(PotatoSQLParser::K_ORDER);
        setState(1007);
        match(PotatoSQLParser::K_BY);
        setState(1008);
        ordering_term();
        setState(1013);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1009);
          match(PotatoSQLParser::COMMA);
          setState(1010);
          ordering_term();
          setState(1015);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1018);
      match(PotatoSQLParser::K_LIMIT);
      setState(1019);
      expr(0);
      setState(1022);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(1020);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1021);
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
  enterRule(_localctx, 80, PotatoSQLParser::RuleVacuum_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1026);
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
  enterRule(_localctx, 82, PotatoSQLParser::RuleColumn_def);
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
    setState(1028);
    column_name();
    setState(1030);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx)) {
    case 1: {
      setState(1029);
      type_name();
      break;
    }

    default:
      break;
    }
    setState(1035);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_CHECK)
      | (1ULL << PotatoSQLParser::K_COLLATE)
      | (1ULL << PotatoSQLParser::K_CONSTRAINT)
      | (1ULL << PotatoSQLParser::K_DEFAULT))) != 0) || ((((_la - 104) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 104)) & ((1ULL << (PotatoSQLParser::K_NOT - 104))
      | (1ULL << (PotatoSQLParser::K_PRIMARY - 104))
      | (1ULL << (PotatoSQLParser::K_REFERENCES - 104))
      | (1ULL << (PotatoSQLParser::K_UNIQUE - 104)))) != 0)) {
      setState(1032);
      column_constraint();
      setState(1037);
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
  enterRule(_localctx, 84, PotatoSQLParser::RuleType_name);

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
    setState(1039); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(1038);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1041); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 137, _ctx);
    } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(1053);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx)) {
    case 1: {
      setState(1043);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1044);
      signed_number();
      setState(1045);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(1047);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1048);
      signed_number();
      setState(1049);
      match(PotatoSQLParser::COMMA);
      setState(1050);
      signed_number();
      setState(1051);
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

PotatoSQLParser::Primary_keyContext* PotatoSQLParser::Column_constraintContext::primary_key() {
  return getRuleContext<PotatoSQLParser::Primary_keyContext>(0);
}

PotatoSQLParser::Conflict_clauseContext* PotatoSQLParser::Column_constraintContext::conflict_clause() {
  return getRuleContext<PotatoSQLParser::Conflict_clauseContext>(0);
}

PotatoSQLParser::Not_nullContext* PotatoSQLParser::Column_constraintContext::not_null() {
  return getRuleContext<PotatoSQLParser::Not_nullContext>(0);
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

PotatoSQLParser::AutoincrementContext* PotatoSQLParser::Column_constraintContext::autoincrement() {
  return getRuleContext<PotatoSQLParser::AutoincrementContext>(0);
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
  enterRule(_localctx, 86, PotatoSQLParser::RuleColumn_constraint);
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
    setState(1057);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1055);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1056);
      name();
    }
    setState(1089);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY: {
        setState(1059);
        primary_key();
        setState(1061);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ASC

        || _la == PotatoSQLParser::K_DESC) {
          setState(1060);
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
        setState(1063);
        conflict_clause();
        setState(1065);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AUTOINCREMENT) {
          setState(1064);
          autoincrement();
        }
        break;
      }

      case PotatoSQLParser::K_NOT: {
        setState(1067);
        not_null();
        setState(1068);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_UNIQUE: {
        setState(1070);
        match(PotatoSQLParser::K_UNIQUE);
        setState(1071);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1072);
        match(PotatoSQLParser::K_CHECK);
        setState(1073);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1074);
        expr(0);
        setState(1075);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_DEFAULT: {
        setState(1077);
        match(PotatoSQLParser::K_DEFAULT);
        setState(1084);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx)) {
        case 1: {
          setState(1078);
          signed_number();
          break;
        }

        case 2: {
          setState(1079);
          literal_value();
          break;
        }

        case 3: {
          setState(1080);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1081);
          expr(0);
          setState(1082);
          match(PotatoSQLParser::CLOSE_PAR);
          break;
        }

        default:
          break;
        }
        break;
      }

      case PotatoSQLParser::K_COLLATE: {
        setState(1086);
        match(PotatoSQLParser::K_COLLATE);
        setState(1087);
        collation_name();
        break;
      }

      case PotatoSQLParser::K_REFERENCES: {
        setState(1088);
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

//----------------- Not_nullContext ------------------------------------------------------------------

PotatoSQLParser::Not_nullContext::Not_nullContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Not_nullContext::K_NOT() {
  return getToken(PotatoSQLParser::K_NOT, 0);
}

tree::TerminalNode* PotatoSQLParser::Not_nullContext::K_NULL() {
  return getToken(PotatoSQLParser::K_NULL, 0);
}


size_t PotatoSQLParser::Not_nullContext::getRuleIndex() const {
  return PotatoSQLParser::RuleNot_null;
}

void PotatoSQLParser::Not_nullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_null(this);
}

void PotatoSQLParser::Not_nullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_null(this);
}


antlrcpp::Any PotatoSQLParser::Not_nullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitNot_null(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Not_nullContext* PotatoSQLParser::not_null() {
  Not_nullContext *_localctx = _tracker.createInstance<Not_nullContext>(_ctx, getState());
  enterRule(_localctx, 88, PotatoSQLParser::RuleNot_null);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1091);
    match(PotatoSQLParser::K_NOT);
    setState(1092);
    match(PotatoSQLParser::K_NULL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_keyContext ------------------------------------------------------------------

PotatoSQLParser::Primary_keyContext::Primary_keyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::Primary_keyContext::K_PRIMARY() {
  return getToken(PotatoSQLParser::K_PRIMARY, 0);
}

tree::TerminalNode* PotatoSQLParser::Primary_keyContext::K_KEY() {
  return getToken(PotatoSQLParser::K_KEY, 0);
}


size_t PotatoSQLParser::Primary_keyContext::getRuleIndex() const {
  return PotatoSQLParser::RulePrimary_key;
}

void PotatoSQLParser::Primary_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_key(this);
}

void PotatoSQLParser::Primary_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_key(this);
}


antlrcpp::Any PotatoSQLParser::Primary_keyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitPrimary_key(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Primary_keyContext* PotatoSQLParser::primary_key() {
  Primary_keyContext *_localctx = _tracker.createInstance<Primary_keyContext>(_ctx, getState());
  enterRule(_localctx, 90, PotatoSQLParser::RulePrimary_key);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1094);
    match(PotatoSQLParser::K_PRIMARY);
    setState(1095);
    match(PotatoSQLParser::K_KEY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AutoincrementContext ------------------------------------------------------------------

PotatoSQLParser::AutoincrementContext::AutoincrementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PotatoSQLParser::AutoincrementContext::K_AUTOINCREMENT() {
  return getToken(PotatoSQLParser::K_AUTOINCREMENT, 0);
}


size_t PotatoSQLParser::AutoincrementContext::getRuleIndex() const {
  return PotatoSQLParser::RuleAutoincrement;
}

void PotatoSQLParser::AutoincrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAutoincrement(this);
}

void PotatoSQLParser::AutoincrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAutoincrement(this);
}


antlrcpp::Any PotatoSQLParser::AutoincrementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitAutoincrement(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::AutoincrementContext* PotatoSQLParser::autoincrement() {
  AutoincrementContext *_localctx = _tracker.createInstance<AutoincrementContext>(_ctx, getState());
  enterRule(_localctx, 92, PotatoSQLParser::RuleAutoincrement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1097);
    match(PotatoSQLParser::K_AUTOINCREMENT);
   
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
  enterRule(_localctx, 94, PotatoSQLParser::RuleConflict_clause);
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
    setState(1102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ON) {
      setState(1099);
      match(PotatoSQLParser::K_ON);
      setState(1100);
      match(PotatoSQLParser::K_CONFLICT);
      setState(1101);
      _la = _input->LA(1);
      if (!(_la == PotatoSQLParser::K_ABORT || ((((_la - 73) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 73)) & ((1ULL << (PotatoSQLParser::K_FAIL - 73))
        | (1ULL << (PotatoSQLParser::K_IGNORE - 73))
        | (1ULL << (PotatoSQLParser::K_REPLACE - 73))
        | (1ULL << (PotatoSQLParser::K_ROLLBACK - 73)))) != 0))) {
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

//----------------- Function_argsContext ------------------------------------------------------------------

PotatoSQLParser::Function_argsContext::Function_argsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Function_argsContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Function_argsContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
}

tree::TerminalNode* PotatoSQLParser::Function_argsContext::STAR() {
  return getToken(PotatoSQLParser::STAR, 0);
}

tree::TerminalNode* PotatoSQLParser::Function_argsContext::K_DISTINCT() {
  return getToken(PotatoSQLParser::K_DISTINCT, 0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::Function_argsContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::Function_argsContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
}


size_t PotatoSQLParser::Function_argsContext::getRuleIndex() const {
  return PotatoSQLParser::RuleFunction_args;
}

void PotatoSQLParser::Function_argsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_args(this);
}

void PotatoSQLParser::Function_argsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_args(this);
}


antlrcpp::Any PotatoSQLParser::Function_argsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitFunction_args(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Function_argsContext* PotatoSQLParser::function_args() {
  Function_argsContext *_localctx = _tracker.createInstance<Function_argsContext>(_ctx, getState());
  enterRule(_localctx, 96, PotatoSQLParser::RuleFunction_args);
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
    setState(1116);
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
      case PotatoSQLParser::K_FALSE:
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
      case PotatoSQLParser::K_TRUE:
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
      case PotatoSQLParser::STRING_LITERAL: {
        setState(1105);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
        case 1: {
          setState(1104);
          match(PotatoSQLParser::K_DISTINCT);
          break;
        }

        default:
          break;
        }
        setState(1107);
        expr(0);
        setState(1112);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1108);
          match(PotatoSQLParser::COMMA);
          setState(1109);
          expr(0);
          setState(1114);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case PotatoSQLParser::STAR: {
        setState(1115);
        match(PotatoSQLParser::STAR);
        break;
      }

      case PotatoSQLParser::CLOSE_PAR: {
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

tree::TerminalNode* PotatoSQLParser::ExprContext::DOT() {
  return getToken(PotatoSQLParser::DOT, 0);
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

PotatoSQLParser::Function_argsContext* PotatoSQLParser::ExprContext::function_args() {
  return getRuleContext<PotatoSQLParser::Function_argsContext>(0);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::CLOSE_PAR() {
  return getToken(PotatoSQLParser::CLOSE_PAR, 0);
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

tree::TerminalNode* PotatoSQLParser::ExprContext::STAR() {
  return getToken(PotatoSQLParser::STAR, 0);
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

PotatoSQLParser::Database_nameContext* PotatoSQLParser::ExprContext::database_name() {
  return getRuleContext<PotatoSQLParser::Database_nameContext>(0);
}

std::vector<tree::TerminalNode *> PotatoSQLParser::ExprContext::COMMA() {
  return getTokens(PotatoSQLParser::COMMA);
}

tree::TerminalNode* PotatoSQLParser::ExprContext::COMMA(size_t i) {
  return getToken(PotatoSQLParser::COMMA, i);
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
  size_t startState = 98;
  enterRecursionRule(_localctx, 98, PotatoSQLParser::RuleExpr, precedence);

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
    setState(1176);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
    case 1: {
      setState(1119);
      literal_value();
      break;
    }

    case 2: {
      setState(1120);
      match(PotatoSQLParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(1124);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
      case 1: {
        setState(1121);
        table_name();
        setState(1122);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1126);
      column_name();
      break;
    }

    case 4: {
      setState(1127);
      unary_operator();
      setState(1128);
      expr(21);
      break;
    }

    case 5: {
      setState(1130);
      function_name();
      setState(1131);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1132);
      function_args();
      setState(1133);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 6: {
      setState(1135);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1136);
      expr(0);
      setState(1137);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(1139);
      match(PotatoSQLParser::K_CAST);
      setState(1140);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1141);
      expr(0);
      setState(1142);
      match(PotatoSQLParser::K_AS);
      setState(1143);
      type_name();
      setState(1144);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 8: {
      setState(1150);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_EXISTS

      || _la == PotatoSQLParser::K_NOT) {
        setState(1147);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(1146);
          match(PotatoSQLParser::K_NOT);
        }
        setState(1149);
        match(PotatoSQLParser::K_EXISTS);
      }
      setState(1152);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1153);
      select_stmt();
      setState(1154);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 9: {
      setState(1156);
      match(PotatoSQLParser::K_CASE);
      setState(1158);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
      case 1: {
        setState(1157);
        expr(0);
        break;
      }

      default:
        break;
      }
      setState(1165); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1160);
        match(PotatoSQLParser::K_WHEN);
        setState(1161);
        expr(0);
        setState(1162);
        match(PotatoSQLParser::K_THEN);
        setState(1163);
        expr(0);
        setState(1167); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == PotatoSQLParser::K_WHEN);
      setState(1171);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ELSE) {
        setState(1169);
        match(PotatoSQLParser::K_ELSE);
        setState(1170);
        expr(0);
      }
      setState(1173);
      match(PotatoSQLParser::K_END);
      break;
    }

    case 10: {
      setState(1175);
      raise_function();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(1265);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1263);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1178);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(1179);
          match(PotatoSQLParser::PIPE2);
          setState(1180);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1181);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(1182);
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
          setState(1183);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1184);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(1185);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::PLUS

          || _la == PotatoSQLParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1186);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1187);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(1188);
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
          setState(1189);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1190);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(1191);
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
          setState(1192);
          expr(17);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1193);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(1194);
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
          setState(1195);
          expr(16);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1196);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1197);
          match(PotatoSQLParser::K_AND);
          setState(1198);
          expr(14);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1199);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(1200);
          match(PotatoSQLParser::K_OR);
          setState(1201);
          expr(13);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1202);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1203);
          match(PotatoSQLParser::K_IS);
          setState(1205);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx)) {
          case 1: {
            setState(1204);
            match(PotatoSQLParser::K_NOT);
            break;
          }

          default:
            break;
          }
          setState(1207);
          expr(6);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1208);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1210);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1209);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1212);
          match(PotatoSQLParser::K_BETWEEN);
          setState(1213);
          expr(0);
          setState(1214);
          match(PotatoSQLParser::K_AND);
          setState(1215);
          expr(5);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1217);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(1219);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1218);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1221);
          match(PotatoSQLParser::K_IN);
          setState(1241);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx)) {
          case 1: {
            setState(1222);
            match(PotatoSQLParser::OPEN_PAR);
            setState(1232);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
            case 1: {
              setState(1223);
              select_stmt();
              break;
            }

            case 2: {
              setState(1224);
              expr(0);
              setState(1229);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == PotatoSQLParser::COMMA) {
                setState(1225);
                match(PotatoSQLParser::COMMA);
                setState(1226);
                expr(0);
                setState(1231);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

            default:
              break;
            }
            setState(1234);
            match(PotatoSQLParser::CLOSE_PAR);
            break;
          }

          case 2: {
            setState(1238);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx)) {
            case 1: {
              setState(1235);
              database_name();
              setState(1236);
              match(PotatoSQLParser::DOT);
              break;
            }

            default:
              break;
            }
            setState(1240);
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
          setState(1243);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(1244);
          match(PotatoSQLParser::K_COLLATE);
          setState(1245);
          collation_name();
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1246);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1248);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1247);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1250);
          _la = _input->LA(1);
          if (!(((((_la - 79) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 79)) & ((1ULL << (PotatoSQLParser::K_GLOB - 79))
            | (1ULL << (PotatoSQLParser::K_LIKE - 79))
            | (1ULL << (PotatoSQLParser::K_MATCH - 79))
            | (1ULL << (PotatoSQLParser::K_REGEXP - 79)))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1251);
          expr(0);
          setState(1254);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
          case 1: {
            setState(1252);
            match(PotatoSQLParser::K_ESCAPE);
            setState(1253);
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
          setState(1256);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1261);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case PotatoSQLParser::K_ISNULL: {
              setState(1257);
              match(PotatoSQLParser::K_ISNULL);
              break;
            }

            case PotatoSQLParser::K_NOTNULL: {
              setState(1258);
              match(PotatoSQLParser::K_NOTNULL);
              break;
            }

            case PotatoSQLParser::K_NOT: {
              setState(1259);
              match(PotatoSQLParser::K_NOT);
              setState(1260);
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
      setState(1267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx);
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
  enterRule(_localctx, 100, PotatoSQLParser::RuleForeign_key_clause);
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
    setState(1268);
    match(PotatoSQLParser::K_REFERENCES);
    setState(1269);
    foreign_table();
    setState(1281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1270);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1271);
      column_name();
      setState(1276);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1272);
        match(PotatoSQLParser::COMMA);
        setState(1273);
        column_name();
        setState(1278);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1279);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_MATCH

    || _la == PotatoSQLParser::K_ON) {
      setState(1297);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_ON: {
          setState(1283);
          match(PotatoSQLParser::K_ON);
          setState(1284);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_DELETE || _la == PotatoSQLParser::K_UPDATE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1293);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx)) {
          case 1: {
            setState(1285);
            match(PotatoSQLParser::K_SET);
            setState(1286);
            match(PotatoSQLParser::K_NULL);
            break;
          }

          case 2: {
            setState(1287);
            match(PotatoSQLParser::K_SET);
            setState(1288);
            match(PotatoSQLParser::K_DEFAULT);
            break;
          }

          case 3: {
            setState(1289);
            match(PotatoSQLParser::K_CASCADE);
            break;
          }

          case 4: {
            setState(1290);
            match(PotatoSQLParser::K_RESTRICT);
            break;
          }

          case 5: {
            setState(1291);
            match(PotatoSQLParser::K_NO);
            setState(1292);
            match(PotatoSQLParser::K_ACTION);
            break;
          }

          default:
            break;
          }
          break;
        }

        case PotatoSQLParser::K_MATCH: {
          setState(1295);
          match(PotatoSQLParser::K_MATCH);
          setState(1296);
          name();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1303);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1314);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx)) {
    case 1: {
      setState(1305);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_NOT) {
        setState(1304);
        match(PotatoSQLParser::K_NOT);
      }
      setState(1307);
      match(PotatoSQLParser::K_DEFERRABLE);
      setState(1312);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx)) {
      case 1: {
        setState(1308);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1309);
        match(PotatoSQLParser::K_DEFERRED);
        break;
      }

      case 2: {
        setState(1310);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1311);
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
  enterRule(_localctx, 102, PotatoSQLParser::RuleRaise_function);
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
    setState(1316);
    match(PotatoSQLParser::K_RAISE);
    setState(1317);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_IGNORE: {
        setState(1318);
        match(PotatoSQLParser::K_IGNORE);
        break;
      }

      case PotatoSQLParser::K_ABORT:
      case PotatoSQLParser::K_FAIL:
      case PotatoSQLParser::K_ROLLBACK: {
        setState(1319);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::K_ABORT || _la == PotatoSQLParser::K_FAIL

        || _la == PotatoSQLParser::K_ROLLBACK)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1320);
        match(PotatoSQLParser::COMMA);
        setState(1321);
        error_message();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1324);
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
  enterRule(_localctx, 104, PotatoSQLParser::RuleIndexed_column);
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
    setState(1326);
    column_name();
    setState(1329);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1327);
      match(PotatoSQLParser::K_COLLATE);
      setState(1328);
      collation_name();
    }
    setState(1332);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1331);
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
  enterRule(_localctx, 106, PotatoSQLParser::RuleTable_constraint);
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
    setState(1336);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1334);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1335);
      name();
    }
    setState(1374);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY:
      case PotatoSQLParser::K_UNIQUE: {
        setState(1341);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_PRIMARY: {
            setState(1338);
            match(PotatoSQLParser::K_PRIMARY);
            setState(1339);
            match(PotatoSQLParser::K_KEY);
            break;
          }

          case PotatoSQLParser::K_UNIQUE: {
            setState(1340);
            match(PotatoSQLParser::K_UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1343);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1344);
        indexed_column();
        setState(1349);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1345);
          match(PotatoSQLParser::COMMA);
          setState(1346);
          indexed_column();
          setState(1351);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1352);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1353);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1355);
        match(PotatoSQLParser::K_CHECK);
        setState(1356);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1357);
        expr(0);
        setState(1358);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_FOREIGN: {
        setState(1360);
        match(PotatoSQLParser::K_FOREIGN);
        setState(1361);
        match(PotatoSQLParser::K_KEY);
        setState(1362);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1363);
        column_name();
        setState(1368);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1364);
          match(PotatoSQLParser::COMMA);
          setState(1365);
          column_name();
          setState(1370);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1371);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1372);
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
  enterRule(_localctx, 108, PotatoSQLParser::RuleWith_clause);
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
    setState(1376);
    match(PotatoSQLParser::K_WITH);
    setState(1378);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 183, _ctx)) {
    case 1: {
      setState(1377);
      match(PotatoSQLParser::K_RECURSIVE);
      break;
    }

    default:
      break;
    }
    setState(1380);
    common_table_expression();
    setState(1385);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1381);
      match(PotatoSQLParser::COMMA);
      setState(1382);
      common_table_expression();
      setState(1387);
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
  enterRule(_localctx, 110, PotatoSQLParser::RuleQualified_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1391);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 185, _ctx)) {
    case 1: {
      setState(1388);
      database_name();
      setState(1389);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(1393);
    table_name();
    setState(1399);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_INDEXED: {
        setState(1394);
        match(PotatoSQLParser::K_INDEXED);
        setState(1395);
        match(PotatoSQLParser::K_BY);
        setState(1396);
        index_name();
        break;
      }

      case PotatoSQLParser::K_NOT: {
        setState(1397);
        match(PotatoSQLParser::K_NOT);
        setState(1398);
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
      case PotatoSQLParser::K_DESCRIBE:
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
      case PotatoSQLParser::K_SHOW:
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
  enterRule(_localctx, 112, PotatoSQLParser::RuleOrdering_term);
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
    setState(1401);
    expr(0);
    setState(1404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1402);
      match(PotatoSQLParser::K_COLLATE);
      setState(1403);
      collation_name();
    }
    setState(1407);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1406);
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
  enterRule(_localctx, 114, PotatoSQLParser::RulePragma_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1412);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1409);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1410);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1411);
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
  enterRule(_localctx, 116, PotatoSQLParser::RuleCommon_table_expression);
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
    setState(1414);
    table_name();
    setState(1426);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1415);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1416);
      column_name();
      setState(1421);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1417);
        match(PotatoSQLParser::COMMA);
        setState(1418);
        column_name();
        setState(1423);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1424);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1428);
    match(PotatoSQLParser::K_AS);
    setState(1429);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1430);
    select_stmt();
    setState(1431);
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

PotatoSQLParser::Column_nameContext* PotatoSQLParser::Result_columnContext::column_name() {
  return getRuleContext<PotatoSQLParser::Column_nameContext>(0);
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
  enterRule(_localctx, 118, PotatoSQLParser::RuleResult_column);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1449);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 194, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1433);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1434);
      table_name();
      setState(1435);
      match(PotatoSQLParser::DOT);
      setState(1436);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1438);
      table_name();
      setState(1439);
      match(PotatoSQLParser::DOT);
      setState(1440);
      column_name();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1442);
      expr(0);
      setState(1447);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1444);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1443);
          match(PotatoSQLParser::K_AS);
        }
        setState(1446);
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
  enterRule(_localctx, 120, PotatoSQLParser::RuleTable_or_subquery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1517);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1454);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx)) {
      case 1: {
        setState(1451);
        schema_name();
        setState(1452);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1456);
      table_name();
      setState(1461);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1458);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1457);
          match(PotatoSQLParser::K_AS);
        }
        setState(1460);
        table_alias();
      }
      setState(1468);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_INDEXED: {
          setState(1463);
          match(PotatoSQLParser::K_INDEXED);
          setState(1464);
          match(PotatoSQLParser::K_BY);
          setState(1465);
          index_name();
          break;
        }

        case PotatoSQLParser::K_NOT: {
          setState(1466);
          match(PotatoSQLParser::K_NOT);
          setState(1467);
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
        case PotatoSQLParser::K_DESCRIBE:
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
        case PotatoSQLParser::K_SHOW:
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
      setState(1473);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 199, _ctx)) {
      case 1: {
        setState(1470);
        schema_name();
        setState(1471);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1475);
      table_function_name();
      setState(1476);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1485);
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
        | (1ULL << PotatoSQLParser::K_DISTINCT))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (PotatoSQLParser::K_DROP - 64))
        | (1ULL << (PotatoSQLParser::K_EACH - 64))
        | (1ULL << (PotatoSQLParser::K_ELSE - 64))
        | (1ULL << (PotatoSQLParser::K_END - 64))
        | (1ULL << (PotatoSQLParser::K_ESCAPE - 64))
        | (1ULL << (PotatoSQLParser::K_EXCEPT - 64))
        | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 64))
        | (1ULL << (PotatoSQLParser::K_EXISTS - 64))
        | (1ULL << (PotatoSQLParser::K_EXPLAIN - 64))
        | (1ULL << (PotatoSQLParser::K_FAIL - 64))
        | (1ULL << (PotatoSQLParser::K_FALSE - 64))
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
        | (1ULL << (PotatoSQLParser::K_ROLLBACK - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (PotatoSQLParser::K_ROW - 128))
        | (1ULL << (PotatoSQLParser::K_SAVEPOINT - 128))
        | (1ULL << (PotatoSQLParser::K_SELECT - 128))
        | (1ULL << (PotatoSQLParser::K_SET - 128))
        | (1ULL << (PotatoSQLParser::K_TABLE - 128))
        | (1ULL << (PotatoSQLParser::K_TEMP - 128))
        | (1ULL << (PotatoSQLParser::K_TEMPORARY - 128))
        | (1ULL << (PotatoSQLParser::K_THEN - 128))
        | (1ULL << (PotatoSQLParser::K_TO - 128))
        | (1ULL << (PotatoSQLParser::K_TRANSACTION - 128))
        | (1ULL << (PotatoSQLParser::K_TRIGGER - 128))
        | (1ULL << (PotatoSQLParser::K_TRUE - 128))
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
        | (1ULL << (PotatoSQLParser::STRING_LITERAL - 128)))) != 0)) {
        setState(1477);
        expr(0);
        setState(1482);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1478);
          match(PotatoSQLParser::COMMA);
          setState(1479);
          expr(0);
          setState(1484);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1487);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1492);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1489);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1488);
          match(PotatoSQLParser::K_AS);
        }
        setState(1491);
        table_alias();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1494);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1504);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 205, _ctx)) {
      case 1: {
        setState(1495);
        table_or_subquery();
        setState(1500);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1496);
          match(PotatoSQLParser::COMMA);
          setState(1497);
          table_or_subquery();
          setState(1502);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(1503);
        join_clause();
        break;
      }

      default:
        break;
      }
      setState(1506);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1508);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1509);
      select_stmt();
      setState(1510);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1515);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1512);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1511);
          match(PotatoSQLParser::K_AS);
        }
        setState(1514);
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
  enterRule(_localctx, 122, PotatoSQLParser::RuleJoin_clause);
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
    setState(1519);
    table_or_subquery();
    setState(1526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA

    || _la == PotatoSQLParser::K_CROSS || ((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (PotatoSQLParser::K_INNER - 89))
      | (1ULL << (PotatoSQLParser::K_JOIN - 89))
      | (1ULL << (PotatoSQLParser::K_LEFT - 89))
      | (1ULL << (PotatoSQLParser::K_NATURAL - 89)))) != 0)) {
      setState(1520);
      join_operator();
      setState(1521);
      table_or_subquery();
      setState(1522);
      join_constraint();
      setState(1528);
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
  enterRule(_localctx, 124, PotatoSQLParser::RuleJoin_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1542);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(1529);
        match(PotatoSQLParser::COMMA);
        break;
      }

      case PotatoSQLParser::K_CROSS:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_NATURAL: {
        enterOuterAlt(_localctx, 2);
        setState(1531);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NATURAL) {
          setState(1530);
          match(PotatoSQLParser::K_NATURAL);
        }
        setState(1539);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_LEFT: {
            setState(1533);
            match(PotatoSQLParser::K_LEFT);
            setState(1535);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == PotatoSQLParser::K_OUTER) {
              setState(1534);
              match(PotatoSQLParser::K_OUTER);
            }
            break;
          }

          case PotatoSQLParser::K_INNER: {
            setState(1537);
            match(PotatoSQLParser::K_INNER);
            break;
          }

          case PotatoSQLParser::K_CROSS: {
            setState(1538);
            match(PotatoSQLParser::K_CROSS);
            break;
          }

          case PotatoSQLParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(1541);
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
  enterRule(_localctx, 126, PotatoSQLParser::RuleJoin_constraint);
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
    setState(1558);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_ON: {
        setState(1544);
        match(PotatoSQLParser::K_ON);
        setState(1545);
        expr(0);
        break;
      }

      case PotatoSQLParser::K_USING: {
        setState(1546);
        match(PotatoSQLParser::K_USING);
        setState(1547);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1548);
        column_name();
        setState(1553);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1549);
          match(PotatoSQLParser::COMMA);
          setState(1550);
          column_name();
          setState(1555);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1556);
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
      case PotatoSQLParser::K_DESCRIBE:
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
      case PotatoSQLParser::K_SHOW:
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
  enterRule(_localctx, 128, PotatoSQLParser::RuleColumn_list);
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
    setState(1560);
    result_column();
    setState(1565);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1561);
      match(PotatoSQLParser::COMMA);
      setState(1562);
      result_column();
      setState(1567);
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

PotatoSQLParser::Where_clauseContext* PotatoSQLParser::Select_coreContext::where_clause() {
  return getRuleContext<PotatoSQLParser::Where_clauseContext>(0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_GROUP() {
  return getToken(PotatoSQLParser::K_GROUP, 0);
}

tree::TerminalNode* PotatoSQLParser::Select_coreContext::K_BY() {
  return getToken(PotatoSQLParser::K_BY, 0);
}

std::vector<PotatoSQLParser::ExprContext *> PotatoSQLParser::Select_coreContext::expr() {
  return getRuleContexts<PotatoSQLParser::ExprContext>();
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<PotatoSQLParser::ExprContext>(i);
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
  enterRule(_localctx, 130, PotatoSQLParser::RuleSelect_core);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1635);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1568);
        match(PotatoSQLParser::K_SELECT);
        setState(1570);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 217, _ctx)) {
        case 1: {
          setState(1569);
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
        setState(1572);
        column_list();
        setState(1585);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(1573);
          match(PotatoSQLParser::K_FROM);
          setState(1583);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 219, _ctx)) {
          case 1: {
            setState(1574);
            table_or_subquery();
            setState(1579);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(1575);
              match(PotatoSQLParser::COMMA);
              setState(1576);
              table_or_subquery();
              setState(1581);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(1582);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(1589);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(1587);
          match(PotatoSQLParser::K_WHERE);
          setState(1588);
          where_clause();
        }
        setState(1605);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(1591);
          match(PotatoSQLParser::K_GROUP);
          setState(1592);
          match(PotatoSQLParser::K_BY);
          setState(1593);
          expr(0);
          setState(1598);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1594);
            match(PotatoSQLParser::COMMA);
            setState(1595);
            expr(0);
            setState(1600);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1603);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(1601);
            match(PotatoSQLParser::K_HAVING);
            setState(1602);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(1607);
        match(PotatoSQLParser::K_VALUES);
        setState(1608);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1609);
        expr(0);
        setState(1614);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1610);
          match(PotatoSQLParser::COMMA);
          setState(1611);
          expr(0);
          setState(1616);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1617);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1632);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1618);
          match(PotatoSQLParser::COMMA);
          setState(1619);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1620);
          expr(0);
          setState(1625);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1621);
            match(PotatoSQLParser::COMMA);
            setState(1622);
            expr(0);
            setState(1627);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1628);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(1634);
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

//----------------- Where_clauseContext ------------------------------------------------------------------

PotatoSQLParser::Where_clauseContext::Where_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PotatoSQLParser::ExprContext* PotatoSQLParser::Where_clauseContext::expr() {
  return getRuleContext<PotatoSQLParser::ExprContext>(0);
}


size_t PotatoSQLParser::Where_clauseContext::getRuleIndex() const {
  return PotatoSQLParser::RuleWhere_clause;
}

void PotatoSQLParser::Where_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_clause(this);
}

void PotatoSQLParser::Where_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<PotatoSQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_clause(this);
}


antlrcpp::Any PotatoSQLParser::Where_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PotatoSQLVisitor*>(visitor))
    return parserVisitor->visitWhere_clause(this);
  else
    return visitor->visitChildren(this);
}

PotatoSQLParser::Where_clauseContext* PotatoSQLParser::where_clause() {
  Where_clauseContext *_localctx = _tracker.createInstance<Where_clauseContext>(_ctx, getState());
  enterRule(_localctx, 132, PotatoSQLParser::RuleWhere_clause);

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
    expr(0);
   
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
  enterRule(_localctx, 134, PotatoSQLParser::RuleCompound_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1644);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 229, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1639);
      match(PotatoSQLParser::K_UNION);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1640);
      match(PotatoSQLParser::K_UNION);
      setState(1641);
      match(PotatoSQLParser::K_ALL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1642);
      match(PotatoSQLParser::K_INTERSECT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1643);
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
  enterRule(_localctx, 136, PotatoSQLParser::RuleSigned_number);
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
    setState(1647);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::PLUS

    || _la == PotatoSQLParser::MINUS) {
      setState(1646);
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
    setState(1649);
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

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_TRUE() {
  return getToken(PotatoSQLParser::K_TRUE, 0);
}

tree::TerminalNode* PotatoSQLParser::Literal_valueContext::K_FALSE() {
  return getToken(PotatoSQLParser::K_FALSE, 0);
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
  enterRule(_localctx, 138, PotatoSQLParser::RuleLiteral_value);
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
    setState(1651);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (PotatoSQLParser::K_CURRENT_DATE - 52))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIME - 52))
      | (1ULL << (PotatoSQLParser::K_CURRENT_TIMESTAMP - 52))
      | (1ULL << (PotatoSQLParser::K_FALSE - 52))
      | (1ULL << (PotatoSQLParser::K_NULL - 52)))) != 0) || ((((_la - 141) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 141)) & ((1ULL << (PotatoSQLParser::K_TRUE - 141))
      | (1ULL << (PotatoSQLParser::NUMERIC_LITERAL - 141))
      | (1ULL << (PotatoSQLParser::STRING_LITERAL - 141)))) != 0))) {
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
  enterRule(_localctx, 140, PotatoSQLParser::RuleUnary_operator);
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
    setState(1653);
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
  enterRule(_localctx, 142, PotatoSQLParser::RuleError_message);

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
  enterRule(_localctx, 144, PotatoSQLParser::RuleModule_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1659);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 231, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1657);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1658);
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
  enterRule(_localctx, 146, PotatoSQLParser::RuleColumn_alias);
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
    setState(1661);
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

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_FALSE() {
  return getToken(PotatoSQLParser::K_FALSE, 0);
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

tree::TerminalNode* PotatoSQLParser::KeywordContext::K_TRUE() {
  return getToken(PotatoSQLParser::K_TRUE, 0);
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
  enterRule(_localctx, 148, PotatoSQLParser::RuleKeyword);
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
    setState(1663);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << PotatoSQLParser::K_ABORT)
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
      | (1ULL << PotatoSQLParser::K_DISTINCT))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (PotatoSQLParser::K_DROP - 64))
      | (1ULL << (PotatoSQLParser::K_EACH - 64))
      | (1ULL << (PotatoSQLParser::K_ELSE - 64))
      | (1ULL << (PotatoSQLParser::K_END - 64))
      | (1ULL << (PotatoSQLParser::K_ESCAPE - 64))
      | (1ULL << (PotatoSQLParser::K_EXCEPT - 64))
      | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 64))
      | (1ULL << (PotatoSQLParser::K_EXISTS - 64))
      | (1ULL << (PotatoSQLParser::K_EXPLAIN - 64))
      | (1ULL << (PotatoSQLParser::K_FAIL - 64))
      | (1ULL << (PotatoSQLParser::K_FALSE - 64))
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
      | (1ULL << (PotatoSQLParser::K_ROLLBACK - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (PotatoSQLParser::K_ROW - 128))
      | (1ULL << (PotatoSQLParser::K_SAVEPOINT - 128))
      | (1ULL << (PotatoSQLParser::K_SELECT - 128))
      | (1ULL << (PotatoSQLParser::K_SET - 128))
      | (1ULL << (PotatoSQLParser::K_TABLE - 128))
      | (1ULL << (PotatoSQLParser::K_TEMP - 128))
      | (1ULL << (PotatoSQLParser::K_TEMPORARY - 128))
      | (1ULL << (PotatoSQLParser::K_THEN - 128))
      | (1ULL << (PotatoSQLParser::K_TO - 128))
      | (1ULL << (PotatoSQLParser::K_TRANSACTION - 128))
      | (1ULL << (PotatoSQLParser::K_TRIGGER - 128))
      | (1ULL << (PotatoSQLParser::K_TRUE - 128))
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
      | (1ULL << (PotatoSQLParser::K_WITHOUT - 128)))) != 0))) {
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
  enterRule(_localctx, 150, PotatoSQLParser::RuleName);

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
  enterRule(_localctx, 152, PotatoSQLParser::RuleFunction_name);

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
  enterRule(_localctx, 154, PotatoSQLParser::RuleDatabase_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1669);
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
  enterRule(_localctx, 156, PotatoSQLParser::RuleSchema_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1671);
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
  enterRule(_localctx, 158, PotatoSQLParser::RuleTable_function_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1673);
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
  enterRule(_localctx, 160, PotatoSQLParser::RuleTable_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1675);
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
  enterRule(_localctx, 162, PotatoSQLParser::RuleTable_or_index_name);

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
  enterRule(_localctx, 164, PotatoSQLParser::RuleNew_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1679);
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
  enterRule(_localctx, 166, PotatoSQLParser::RuleColumn_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1681);
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
  enterRule(_localctx, 168, PotatoSQLParser::RuleCollation_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1683);
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
  enterRule(_localctx, 170, PotatoSQLParser::RuleForeign_table);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1685);
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
  enterRule(_localctx, 172, PotatoSQLParser::RuleIndex_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1687);
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
  enterRule(_localctx, 174, PotatoSQLParser::RuleTrigger_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1689);
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
  enterRule(_localctx, 176, PotatoSQLParser::RuleView_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1691);
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
  enterRule(_localctx, 178, PotatoSQLParser::RuleModule_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1693);
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
  enterRule(_localctx, 180, PotatoSQLParser::RulePragma_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1695);
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
  enterRule(_localctx, 182, PotatoSQLParser::RuleSavepoint_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1697);
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
  enterRule(_localctx, 184, PotatoSQLParser::RuleTable_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1705);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1699);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1700);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 3);
        setState(1701);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1702);
        table_alias();
        setState(1703);
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
  enterRule(_localctx, 186, PotatoSQLParser::RuleTransaction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1707);
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
  enterRule(_localctx, 188, PotatoSQLParser::RuleAny_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1716);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1709);
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
      case PotatoSQLParser::K_FALSE:
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
      case PotatoSQLParser::K_TRUE:
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
        setState(1710);
        keyword();
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1711);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(1712);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1713);
        any_name();
        setState(1714);
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
    case 49: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "main", "error", "sql_stmt_list", "sql_stmt", "alter_table_stmt", "show_tables_stmt", 
  "describe_table_stmt", "analyze_stmt", "attach_stmt", "begin_stmt", "commit_stmt", 
  "compound_select_stmt", "create_index_stmt", "create_table_stmt", "create_trigger_stmt", 
  "create_view_stmt", "create_virtual_table_stmt", "delete_stmt", "delete_stmt_limited", 
  "detach_stmt", "drop_index_stmt", "drop_table_stmt", "drop_trigger_stmt", 
  "drop_view_stmt", "factored_select_stmt", "insert_prefix", "insert_tuple", 
  "insert_tuples", "insert_columns", "insert_stmt", "pragma_stmt", "reindex_stmt", 
  "release_stmt", "rollback_stmt", "savepoint_stmt", "simple_select_stmt", 
  "select_stmt", "select_or_values", "update_stmt", "update_stmt_limited", 
  "vacuum_stmt", "column_def", "type_name", "column_constraint", "not_null", 
  "primary_key", "autoincrement", "conflict_clause", "function_args", "expr", 
  "foreign_key_clause", "raise_function", "indexed_column", "table_constraint", 
  "with_clause", "qualified_table_name", "ordering_term", "pragma_value", 
  "common_table_expression", "result_column", "table_or_subquery", "join_clause", 
  "join_operator", "join_constraint", "column_list", "select_core", "where_clause", 
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
  "K_DEFAULT", "K_DEFERRABLE", "K_DEFERRED", "K_DELETE", "K_DESC", "K_DESCRIBE", 
  "K_DETACH", "K_DISTINCT", "K_DROP", "K_EACH", "K_ELSE", "K_END", "K_ESCAPE", 
  "K_EXCEPT", "K_EXCLUSIVE", "K_EXISTS", "K_EXPLAIN", "K_FAIL", "K_FALSE", 
  "K_FOR", "K_FOREIGN", "K_FROM", "K_FULL", "K_GLOB", "K_GROUP", "K_HAVING", 
  "K_IF", "K_IGNORE", "K_IMMEDIATE", "K_IN", "K_INDEX", "K_INDEXED", "K_INITIALLY", 
  "K_INNER", "K_INSERT", "K_INSTEAD", "K_INTERSECT", "K_INTO", "K_IS", "K_ISNULL", 
  "K_JOIN", "K_KEY", "K_LEFT", "K_LIKE", "K_LIMIT", "K_MATCH", "K_NATURAL", 
  "K_NO", "K_NOT", "K_NOTNULL", "K_NULL", "K_OF", "K_OFFSET", "K_ON", "K_OR", 
  "K_ORDER", "K_OUTER", "K_PLAN", "K_PRAGMA", "K_PRIMARY", "K_QUERY", "K_RAISE", 
  "K_RECURSIVE", "K_REFERENCES", "K_REGEXP", "K_REINDEX", "K_RELEASE", "K_RENAME", 
  "K_REPLACE", "K_RESTRICT", "K_RIGHT", "K_ROLLBACK", "K_ROW", "K_SAVEPOINT", 
  "K_SELECT", "K_SET", "K_SHOW", "K_TABLE", "K_TABLES", "K_TEMP", "K_TEMPORARY", 
  "K_THEN", "K_TO", "K_TRANSACTION", "K_TRIGGER", "K_TRUE", "K_UNION", "K_UNIQUE", 
  "K_UPDATE", "K_USING", "K_VACUUM", "K_VALUES", "K_VIEW", "K_VIRTUAL", 
  "K_WHEN", "K_WHERE", "K_WITH", "K_WITHOUT", "IDENTIFIER", "NUMERIC_LITERAL", 
  "BIND_PARAMETER", "STRING_LITERAL", "BLOB_LITERAL", "SINGLE_LINE_COMMENT", 
  "MULTILINE_COMMENT", "SPACES", "UNEXPECTED_CHAR"
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa4, 0x6b9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xc3, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0xc6, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x7, 0x4, 0xce, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xd1, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0xd5, 0xa, 0x4, 0xd, 0x4, 0xe, 
    0x4, 0xd6, 0x3, 0x4, 0x7, 0x4, 0xda, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xdd, 
    0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 0xe0, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xe3, 
    0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xe8, 0xa, 0x5, 0x5, 
    0x5, 0xea, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x10c, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x113, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x11b, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x11e, 0xa, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x12e, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x132, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x13a, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x13e, 0xa, 
    0xb, 0x5, 0xb, 0x140, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x145, 0xa, 0xc, 0x5, 0xc, 0x147, 0xa, 0xc, 0x3, 0xd, 0x5, 0xd, 0x14a, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x14f, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0x153, 0xa, 0xd, 0x3, 0xd, 0x6, 0xd, 0x156, 
    0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x157, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0x15f, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x162, 
    0xb, 0xd, 0x5, 0xd, 0x164, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x5, 0xd, 0x16a, 0xa, 0xd, 0x5, 0xd, 0x16c, 0xa, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x170, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x176, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x17b, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x7, 0xe, 0x184, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x187, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x18c, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x190, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x196, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x19b, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x7, 0xf, 0x1a2, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1a5, 0xb, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0x1a9, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1ac, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1b1, 0xa, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x5, 0xf, 0x1b5, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 
    0x10, 0x1b9, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0x1bf, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x1c4, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0x1cb, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1d4, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x1d7, 0xb, 0x10, 0x5, 0x10, 0x1d9, 0xa, 0x10, 0x5, 0x10, 
    0x1db, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x1e1, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x1e7, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1eb, 0xa, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1f2, 
    0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x6, 0x10, 0x1f6, 0xa, 0x10, 0xd, 0x10, 
    0xe, 0x10, 0x1f7, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x1fe, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x204, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x209, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x215, 
    0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x21a, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x7, 0x12, 0x223, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x226, 0xb, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x22a, 0xa, 0x12, 0x3, 0x13, 
    0x5, 0x13, 0x22d, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x234, 0xa, 0x13, 0x3, 0x14, 0x5, 0x14, 0x237, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x23e, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0x245, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x248, 
    0xb, 0x14, 0x5, 0x14, 0x24a, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x250, 0xa, 0x14, 0x5, 0x14, 0x252, 0xa, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x256, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x25e, 0xa, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x263, 0xa, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x26b, 
    0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x270, 0xa, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0x278, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x27d, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x5, 0x19, 0x285, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x28a, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x5, 0x1a, 
    0x28f, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 
    0x295, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x298, 0xb, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x29f, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x2a2, 0xb, 0x1a, 0x5, 0x1a, 0x2a4, 0xa, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x2aa, 0xa, 0x1a, 
    0x5, 0x1a, 0x2ac, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x2bf, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x7, 0x1c, 0x2c5, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2c8, 0xb, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x2cf, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x2d2, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x2d8, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
    0x2db, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x2e0, 
    0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
    0x1f, 0x2e7, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2eb, 0xa, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x2f2, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
    0x2f8, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x301, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x308, 0xa, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x5, 0x21, 0x30c, 0xa, 0x21, 0x5, 0x21, 0x30e, 0xa, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x312, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x319, 0xa, 0x23, 0x5, 0x23, 
    0x31b, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x31f, 0xa, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x322, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x5, 0x25, 0x328, 0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x330, 0xa, 0x25, 0xc, 0x25, 
    0xe, 0x25, 0x333, 0xb, 0x25, 0x5, 0x25, 0x335, 0xa, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x33b, 0xa, 0x25, 0x5, 0x25, 
    0x33d, 0xa, 0x25, 0x3, 0x26, 0x5, 0x26, 0x340, 0xa, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x346, 0xa, 0x26, 0xc, 0x26, 
    0xe, 0x26, 0x349, 0xb, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x7, 0x26, 0x350, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x353, 
    0xb, 0x26, 0x5, 0x26, 0x355, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x5, 0x26, 0x35b, 0xa, 0x26, 0x5, 0x26, 0x35d, 0xa, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x361, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x7, 0x27, 0x366, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x369, 
    0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x36f, 
    0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x372, 0xb, 0x27, 0x3, 0x27, 0x5, 0x27, 
    0x375, 0xa, 0x27, 0x5, 0x27, 0x377, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x37b, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x7, 0x27, 0x382, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x385, 
    0xb, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x389, 0xa, 0x27, 0x5, 0x27, 
    0x38b, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x7, 0x27, 0x392, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x395, 0xb, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 
    0x27, 0x39d, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x3a0, 0xb, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x7, 0x27, 0x3a4, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 
    0x3a7, 0xb, 0x27, 0x5, 0x27, 0x3a9, 0xa, 0x27, 0x3, 0x28, 0x5, 0x28, 
    0x3ac, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 
    0x28, 0x3b9, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 
    0x28, 0x3c5, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x3c8, 0xb, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x5, 0x28, 0x3cc, 0xa, 0x28, 0x3, 0x29, 0x5, 0x29, 
    0x3cf, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 
    0x29, 0x3dc, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 
    0x29, 0x3e8, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x3eb, 0xb, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x5, 0x29, 0x3ef, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x3f6, 0xa, 0x29, 0xc, 0x29, 
    0xe, 0x29, 0x3f9, 0xb, 0x29, 0x5, 0x29, 0x3fb, 0xa, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x401, 0xa, 0x29, 0x5, 0x29, 
    0x403, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 
    0x409, 0xa, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x40c, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x40f, 0xb, 0x2b, 0x3, 0x2c, 0x6, 0x2c, 0x412, 0xa, 0x2c, 
    0xd, 0x2c, 0xe, 0x2c, 0x413, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 
    0x2c, 0x420, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x424, 0xa, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x428, 0xa, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x42c, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x43f, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x444, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x5, 0x31, 0x451, 0xa, 0x31, 0x3, 0x32, 0x5, 0x32, 0x454, 0xa, 
    0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x459, 0xa, 0x32, 
    0xc, 0x32, 0xe, 0x32, 0x45c, 0xb, 0x32, 0x3, 0x32, 0x5, 0x32, 0x45f, 
    0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x5, 0x33, 0x467, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x47e, 
    0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x481, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x489, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x6, 0x33, 0x490, 
    0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x491, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 
    0x496, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x49b, 
    0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x4b8, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x4bd, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x4c6, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 
    0x33, 0x4ce, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x4d1, 0xb, 0x33, 0x5, 
    0x33, 0x4d3, 0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x5, 0x33, 0x4d9, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x4dc, 0xa, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x4e3, 
    0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x4e9, 
    0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 
    0x33, 0x4f0, 0xa, 0x33, 0x7, 0x33, 0x4f2, 0xa, 0x33, 0xc, 0x33, 0xe, 
    0x33, 0x4f5, 0xb, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x4fd, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 
    0x500, 0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x504, 0xa, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x510, 0xa, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x514, 0xa, 0x34, 0x7, 0x34, 0x516, 
    0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x519, 0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 
    0x51c, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 
    0x5, 0x34, 0x523, 0xa, 0x34, 0x5, 0x34, 0x525, 0xa, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x52d, 
    0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 
    0x36, 0x534, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x537, 0xa, 0x36, 0x3, 
    0x37, 0x3, 0x37, 0x5, 0x37, 0x53b, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x5, 0x37, 0x540, 0xa, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x7, 0x37, 0x546, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x549, 
    0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x559, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 
    0x55c, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x561, 
    0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x565, 0xa, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x56a, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 
    0x56d, 0xb, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x572, 
    0xa, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 
    0x39, 0x5, 0x39, 0x57a, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x5, 0x3a, 0x57f, 0xa, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x582, 0xa, 0x3a, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x587, 0xa, 0x3b, 0x3, 0x3c, 
    0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 0x58e, 0xa, 0x3c, 
    0xc, 0x3c, 0xe, 0x3c, 0x591, 0xb, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x5, 0x3c, 
    0x595, 0xa, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x5a7, 
    0xa, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x5aa, 0xa, 0x3d, 0x5, 0x3d, 0x5ac, 
    0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5b1, 0xa, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5b5, 0xa, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x5b8, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x5, 0x3e, 0x5bf, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 
    0x5c4, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x7, 0x3e, 0x5cb, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x5ce, 0xb, 0x3e, 
    0x5, 0x3e, 0x5d0, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5d4, 
    0xa, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5d7, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x5dd, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 
    0x5e0, 0xb, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5e3, 0xa, 0x3e, 0x3, 0x3e, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5eb, 
    0xa, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5ee, 0xa, 0x3e, 0x5, 0x3e, 0x5f0, 
    0xa, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 
    0x3f, 0x5f7, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x5fa, 0xb, 0x3f, 0x3, 
    0x40, 0x3, 0x40, 0x5, 0x40, 0x5fe, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 
    0x5, 0x40, 0x602, 0xa, 0x40, 0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x606, 
    0xa, 0x40, 0x3, 0x40, 0x5, 0x40, 0x609, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x612, 
    0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x615, 0xb, 0x41, 0x3, 0x41, 0x3, 0x41, 
    0x5, 0x41, 0x619, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 
    0x61e, 0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x621, 0xb, 0x42, 0x3, 0x43, 
    0x3, 0x43, 0x5, 0x43, 0x625, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x62c, 0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 
    0x62f, 0xb, 0x43, 0x3, 0x43, 0x5, 0x43, 0x632, 0xa, 0x43, 0x5, 0x43, 
    0x634, 0xa, 0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x638, 0xa, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x63f, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x642, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x5, 0x43, 0x646, 0xa, 0x43, 0x5, 0x43, 0x648, 0xa, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x64f, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x652, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x65a, 0xa, 0x43, 0xc, 0x43, 
    0xe, 0x43, 0x65d, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x661, 
    0xa, 0x43, 0xc, 0x43, 0xe, 0x43, 0x664, 0xb, 0x43, 0x5, 0x43, 0x666, 
    0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x3, 
    0x45, 0x3, 0x45, 0x5, 0x45, 0x66f, 0xa, 0x45, 0x3, 0x46, 0x5, 0x46, 
    0x672, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 
    0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x67e, 
    0xa, 0x4a, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 
    0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 
    0x54, 0x3, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 
    0x3, 0x57, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 
    0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 
    0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x5, 
    0x5e, 0x6ac, 0xa, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 
    0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x5, 0x60, 0x6b7, 
    0xa, 0x60, 0x3, 0x60, 0x4, 0x1a3, 0x413, 0x3, 0x64, 0x61, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
    0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 
    0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
    0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 
    0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 
    0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 0x2, 0x15, 0x5, 0x2, 
    0x3c, 0x3c, 0x48, 0x48, 0x56, 0x56, 0x4, 0x2, 0x31, 0x31, 0x45, 0x45, 
    0x4, 0x2, 0x7, 0x7, 0x6e, 0x6e, 0x3, 0x2, 0x89, 0x8a, 0x4, 0x2, 0x1f, 
    0x1f, 0x41, 0x41, 0x4, 0x2, 0x24, 0x24, 0x3e, 0x3e, 0x7, 0x2, 0x1b, 
    0x1b, 0x4b, 0x4b, 0x55, 0x55, 0x7e, 0x7e, 0x81, 0x81, 0x4, 0x2, 0x9, 
    0x9, 0xe, 0xf, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0x10, 0x13, 0x3, 0x2, 0x14, 
    0x17, 0x4, 0x2, 0x8, 0x8, 0x18, 0x1a, 0x6, 0x2, 0x51, 0x51, 0x65, 0x65, 
    0x67, 0x67, 0x7a, 0x7a, 0x4, 0x2, 0x3d, 0x3d, 0x92, 0x92, 0x5, 0x2, 
    0x1b, 0x1b, 0x4b, 0x4b, 0x81, 0x81, 0x8, 0x2, 0x36, 0x38, 0x4c, 0x4c, 
    0x6c, 0x6c, 0x8f, 0x8f, 0x9d, 0x9d, 0x9f, 0x9f, 0x4, 0x2, 0xa, 0xc, 
    0x6a, 0x6a, 0x4, 0x2, 0x9c, 0x9c, 0x9f, 0x9f, 0x6, 0x2, 0x1b, 0x3e, 
    0x40, 0x85, 0x87, 0x87, 0x89, 0x9b, 0x2, 0x7ab, 0x2, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x6, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xa, 0x10d, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x11f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x122, 0x3, 0x2, 0x2, 0x2, 0x10, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x141, 0x3, 0x2, 0x2, 0x2, 0x18, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x18d, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x236, 0x3, 0x2, 0x2, 0x2, 0x28, 0x253, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x259, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x266, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x273, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x280, 0x3, 0x2, 0x2, 0x2, 0x32, 0x28e, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x36, 0x2c0, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x2d3, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x302, 0x3, 0x2, 0x2, 0x2, 0x42, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x315, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x323, 0x3, 0x2, 0x2, 0x2, 0x48, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3a8, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x50, 0x3ce, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x404, 0x3, 0x2, 0x2, 0x2, 0x54, 0x406, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x411, 0x3, 0x2, 0x2, 0x2, 0x58, 0x423, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x445, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x448, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x44b, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x450, 0x3, 0x2, 0x2, 0x2, 0x62, 0x45e, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x49a, 0x3, 0x2, 0x2, 0x2, 0x66, 0x4f6, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x526, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x530, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x562, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x571, 0x3, 0x2, 0x2, 0x2, 0x72, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x586, 0x3, 0x2, 0x2, 0x2, 0x76, 0x588, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5ab, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x5ef, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x5f1, 0x3, 
    0x2, 0x2, 0x2, 0x7e, 0x608, 0x3, 0x2, 0x2, 0x2, 0x80, 0x618, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x61a, 0x3, 0x2, 0x2, 0x2, 0x84, 0x665, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x667, 0x3, 0x2, 0x2, 0x2, 0x88, 0x66e, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x671, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x675, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x677, 0x3, 0x2, 0x2, 0x2, 0x90, 0x679, 0x3, 0x2, 0x2, 0x2, 0x92, 0x67d, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x67f, 0x3, 0x2, 0x2, 0x2, 0x96, 0x681, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x683, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x685, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x687, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x689, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x68b, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x68d, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0x68f, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x691, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0x693, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x695, 0x3, 0x2, 0x2, 0x2, 0xac, 0x697, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0x699, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x69b, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0x69d, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x69f, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0x6a1, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x6a3, 0x3, 0x2, 0x2, 
    0x2, 0xba, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x6ad, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0x6b6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x5, 0x6, 0x4, 0x2, 0xc1, 
    0xc3, 0x5, 0x4, 0x3, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x2, 0x2, 
    0x3, 0xc8, 0x3, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0xa4, 0x2, 0x2, 
    0xca, 0xcb, 0x8, 0x3, 0x1, 0x2, 0xcb, 0x5, 0x3, 0x2, 0x2, 0x2, 0xcc, 
    0xce, 0x7, 0x3, 0x2, 0x2, 0xcd, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xdb, 0x5, 0x8, 0x5, 0x2, 0xd3, 0xd5, 0x7, 0x3, 0x2, 
    0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 0x5, 0x8, 0x5, 0x2, 0xd9, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x7, 0x3, 0x2, 
    0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 
    0x7, 0x4a, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x76, 0x2, 0x2, 0xe6, 0xe8, 0x7, 
    0x73, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0xeb, 0x10c, 0x5, 0xa, 0x6, 0x2, 0xec, 0x10c, 0x5, 0x10, 0x9, 0x2, 0xed, 
    0x10c, 0x5, 0x12, 0xa, 0x2, 0xee, 0x10c, 0x5, 0x14, 0xb, 0x2, 0xef, 
    0x10c, 0x5, 0x16, 0xc, 0x2, 0xf0, 0x10c, 0x5, 0x18, 0xd, 0x2, 0xf1, 
    0x10c, 0x5, 0x1a, 0xe, 0x2, 0xf2, 0x10c, 0x5, 0x1c, 0xf, 0x2, 0xf3, 
    0x10c, 0x5, 0x1e, 0x10, 0x2, 0xf4, 0x10c, 0x5, 0x20, 0x11, 0x2, 0xf5, 
    0x10c, 0x5, 0x22, 0x12, 0x2, 0xf6, 0x10c, 0x5, 0x24, 0x13, 0x2, 0xf7, 
    0x10c, 0x5, 0x26, 0x14, 0x2, 0xf8, 0x10c, 0x5, 0xe, 0x8, 0x2, 0xf9, 
    0x10c, 0x5, 0x28, 0x15, 0x2, 0xfa, 0x10c, 0x5, 0x2a, 0x16, 0x2, 0xfb, 
    0x10c, 0x5, 0x2c, 0x17, 0x2, 0xfc, 0x10c, 0x5, 0x2e, 0x18, 0x2, 0xfd, 
    0x10c, 0x5, 0x30, 0x19, 0x2, 0xfe, 0x10c, 0x5, 0x32, 0x1a, 0x2, 0xff, 
    0x10c, 0x5, 0x3c, 0x1f, 0x2, 0x100, 0x10c, 0x5, 0x3e, 0x20, 0x2, 0x101, 
    0x10c, 0x5, 0x40, 0x21, 0x2, 0x102, 0x10c, 0x5, 0x42, 0x22, 0x2, 0x103, 
    0x10c, 0x5, 0x44, 0x23, 0x2, 0x104, 0x10c, 0x5, 0x46, 0x24, 0x2, 0x105, 
    0x10c, 0x5, 0x48, 0x25, 0x2, 0x106, 0x10c, 0x5, 0x4a, 0x26, 0x2, 0x107, 
    0x10c, 0x5, 0xc, 0x7, 0x2, 0x108, 0x10c, 0x5, 0x4e, 0x28, 0x2, 0x109, 
    0x10c, 0x5, 0x50, 0x29, 0x2, 0x10a, 0x10c, 0x5, 0x52, 0x2a, 0x2, 0x10b, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xec, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xed, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0xee, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xef, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0xf2, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0xf8, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x10b, 0xfe, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0xff, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x100, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x101, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x103, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x20, 0x2, 0x2, 
    0x10e, 0x112, 0x7, 0x87, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x9c, 0x4f, 0x2, 
    0x110, 0x111, 0x7, 0x4, 0x2, 0x2, 0x111, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x112, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x11d, 0x5, 0xa2, 0x52, 0x2, 
    0x115, 0x116, 0x7, 0x7d, 0x2, 0x2, 0x116, 0x117, 0x7, 0x8c, 0x2, 0x2, 
    0x117, 0x11e, 0x5, 0xa6, 0x54, 0x2, 0x118, 0x11a, 0x7, 0x1d, 0x2, 0x2, 
    0x119, 0x11b, 0x7, 0x30, 0x2, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0x11a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11e, 0x5, 0x54, 0x2b, 0x2, 0x11d, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x120, 0x7, 0x86, 0x2, 0x2, 0x120, 0x121, 0x7, 0x88, 0x2, 0x2, 0x121, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x3f, 0x2, 0x2, 0x123, 0x124, 
    0x7, 0x87, 0x2, 0x2, 0x124, 0x125, 0x5, 0xa2, 0x52, 0x2, 0x125, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x12d, 0x7, 0x21, 0x2, 0x2, 0x127, 0x12e, 
    0x5, 0x9c, 0x4f, 0x2, 0x128, 0x12e, 0x5, 0xa4, 0x53, 0x2, 0x129, 0x12a, 
    0x5, 0x9c, 0x4f, 0x2, 0x12a, 0x12b, 0x7, 0x4, 0x2, 0x2, 0x12b, 0x12c, 
    0x5, 0xa4, 0x53, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x131, 0x7, 0x25, 0x2, 0x2, 0x130, 0x132, 0x7, 
    0x39, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x5, 
    0x64, 0x33, 0x2, 0x134, 0x135, 0x7, 0x23, 0x2, 0x2, 0x135, 0x136, 0x5, 
    0x9c, 0x4f, 0x2, 0x136, 0x13, 0x3, 0x2, 0x2, 0x2, 0x137, 0x139, 0x7, 
    0x28, 0x2, 0x2, 0x138, 0x13a, 0x9, 0x2, 0x2, 0x2, 0x139, 0x138, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x13d, 0x7, 0x8d, 0x2, 0x2, 0x13c, 0x13e, 0x5, 
    0xbc, 0x5f, 0x2, 0x13d, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x13e, 0x140, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x146, 0x9, 0x3, 0x2, 0x2, 0x142, 0x144, 0x7, 0x8d, 
    0x2, 0x2, 0x143, 0x145, 0x5, 0xbc, 0x5f, 0x2, 0x144, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x142, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x17, 0x3, 0x2, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x6e, 
    0x38, 0x2, 0x149, 0x148, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x155, 0x5, 0x84, 
    0x43, 0x2, 0x14c, 0x14e, 0x7, 0x90, 0x2, 0x2, 0x14d, 0x14f, 0x7, 0x1f, 
    0x2, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x153, 0x3, 0x2, 0x2, 0x2, 0x150, 0x153, 0x7, 0x5e, 
    0x2, 0x2, 0x151, 0x153, 0x7, 0x47, 0x2, 0x2, 0x152, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x156, 0x5, 0x84, 
    0x43, 0x2, 0x155, 0x152, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x3, 0x2, 
    0x2, 0x2, 0x158, 0x163, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x7, 0x71, 
    0x2, 0x2, 0x15a, 0x15b, 0x7, 0x2a, 0x2, 0x2, 0x15b, 0x160, 0x5, 0x72, 
    0x3a, 0x2, 0x15c, 0x15d, 0x7, 0x7, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x72, 
    0x3a, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x159, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x66, 
    0x2, 0x2, 0x166, 0x169, 0x5, 0x64, 0x33, 0x2, 0x167, 0x168, 0x9, 0x4, 
    0x2, 0x2, 0x168, 0x16a, 0x5, 0x64, 0x33, 0x2, 0x169, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16c, 0x3, 0x2, 
    0x2, 0x2, 0x16b, 0x165, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 
    0x2, 0x2, 0x16c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16f, 0x7, 0x34, 
    0x2, 0x2, 0x16e, 0x170, 0x7, 0x91, 0x2, 0x2, 0x16f, 0x16e, 0x3, 0x2, 
    0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x3, 0x2, 
    0x2, 0x2, 0x171, 0x175, 0x7, 0x58, 0x2, 0x2, 0x172, 0x173, 0x7, 0x54, 
    0x2, 0x2, 0x173, 0x174, 0x7, 0x6a, 0x2, 0x2, 0x174, 0x176, 0x7, 0x49, 
    0x2, 0x2, 0x175, 0x172, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x5, 0x9c, 
    0x4f, 0x2, 0x178, 0x179, 0x7, 0x4, 0x2, 0x2, 0x179, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17a, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0xae, 
    0x58, 0x2, 0x17d, 0x17e, 0x7, 0x6f, 0x2, 0x2, 0x17e, 0x17f, 0x5, 0xa2, 
    0x52, 0x2, 0x17f, 0x180, 0x7, 0x5, 0x2, 0x2, 0x180, 0x185, 0x5, 0x6a, 
    0x36, 0x2, 0x181, 0x182, 0x7, 0x7, 0x2, 0x2, 0x182, 0x184, 0x5, 0x6a, 
    0x36, 0x2, 0x183, 0x181, 0x3, 0x2, 0x2, 0x2, 0x184, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x186, 0x188, 0x3, 0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x18b, 0x7, 0x6, 0x2, 0x2, 0x189, 0x18a, 0x7, 0x99, 
    0x2, 0x2, 0x18a, 0x18c, 0x5, 0x64, 0x33, 0x2, 0x18b, 0x189, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x18f, 0x7, 0x34, 0x2, 0x2, 0x18e, 0x190, 0x9, 0x5, 0x2, 
    0x2, 0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 0x2, 0x191, 0x195, 0x7, 0x87, 0x2, 
    0x2, 0x192, 0x193, 0x7, 0x54, 0x2, 0x2, 0x193, 0x194, 0x7, 0x6a, 0x2, 
    0x2, 0x194, 0x196, 0x7, 0x49, 0x2, 0x2, 0x195, 0x192, 0x3, 0x2, 0x2, 
    0x2, 0x195, 0x196, 0x3, 0x2, 0x2, 0x2, 0x196, 0x19a, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x198, 0x5, 0x9c, 0x4f, 0x2, 0x198, 0x199, 0x7, 0x4, 0x2, 
    0x2, 0x199, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x1b4, 0x5, 0xa2, 0x52, 0x2, 0x19d, 0x19e, 0x7, 0x5, 0x2, 
    0x2, 0x19e, 0x1a3, 0x5, 0x54, 0x2b, 0x2, 0x19f, 0x1a0, 0x7, 0x7, 0x2, 
    0x2, 0x1a0, 0x1a2, 0x5, 0x54, 0x2b, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 
    0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1aa, 0x3, 0x2, 0x2, 
    0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0x7, 0x2, 
    0x2, 0x1a7, 0x1a9, 0x5, 0x6c, 0x37, 0x2, 0x1a8, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b0, 0x7, 0x6, 0x2, 
    0x2, 0x1ae, 0x1af, 0x7, 0x9b, 0x2, 0x2, 0x1af, 0x1b1, 0x7, 0x9c, 0x2, 
    0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x23, 0x2, 
    0x2, 0x1b3, 0x1b5, 0x5, 0x4a, 0x26, 0x2, 0x1b4, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1b6, 0x1b8, 0x7, 0x34, 0x2, 0x2, 0x1b7, 0x1b9, 0x9, 0x5, 0x2, 0x2, 
    0x1b8, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1be, 0x7, 0x8e, 0x2, 0x2, 
    0x1bb, 0x1bc, 0x7, 0x54, 0x2, 0x2, 0x1bc, 0x1bd, 0x7, 0x6a, 0x2, 0x2, 
    0x1bd, 0x1bf, 0x7, 0x49, 0x2, 0x2, 0x1be, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c3, 0x3, 0x2, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x5, 0x9c, 0x4f, 0x2, 0x1c1, 0x1c2, 0x7, 0x4, 0x2, 0x2, 
    0x1c2, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c0, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 
    0x1c5, 0x1ca, 0x5, 0xb0, 0x59, 0x2, 0x1c6, 0x1cb, 0x7, 0x27, 0x2, 0x2, 
    0x1c7, 0x1cb, 0x7, 0x1e, 0x2, 0x2, 0x1c8, 0x1c9, 0x7, 0x5d, 0x2, 0x2, 
    0x1c9, 0x1cb, 0x7, 0x6d, 0x2, 0x2, 0x1ca, 0x1c6, 0x3, 0x2, 0x2, 0x2, 
    0x1ca, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1c8, 0x3, 0x2, 0x2, 0x2, 
    0x1ca, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1da, 0x3, 0x2, 0x2, 0x2, 
    0x1cc, 0x1db, 0x7, 0x3d, 0x2, 0x2, 0x1cd, 0x1db, 0x7, 0x5c, 0x2, 0x2, 
    0x1ce, 0x1d8, 0x7, 0x92, 0x2, 0x2, 0x1cf, 0x1d0, 0x7, 0x6d, 0x2, 0x2, 
    0x1d0, 0x1d5, 0x5, 0xa8, 0x55, 0x2, 0x1d1, 0x1d2, 0x7, 0x7, 0x2, 0x2, 
    0x1d2, 0x1d4, 0x5, 0xa8, 0x55, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 
    0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d9, 0x3, 0x2, 0x2, 0x2, 
    0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
    0x1d8, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1db, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1cd, 0x3, 0x2, 0x2, 0x2, 
    0x1da, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 0x2, 
    0x1dc, 0x1e0, 0x7, 0x6f, 0x2, 0x2, 0x1dd, 0x1de, 0x5, 0x9c, 0x4f, 0x2, 
    0x1de, 0x1df, 0x7, 0x4, 0x2, 0x2, 0x1df, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e0, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e1, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e6, 0x5, 0xa2, 0x52, 0x2, 
    0x1e3, 0x1e4, 0x7, 0x4d, 0x2, 0x2, 0x1e4, 0x1e5, 0x7, 0x43, 0x2, 0x2, 
    0x1e5, 0x1e7, 0x7, 0x82, 0x2, 0x2, 0x1e6, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x1e6, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1e8, 0x1e9, 0x7, 0x98, 0x2, 0x2, 0x1e9, 0x1eb, 0x5, 0x64, 0x33, 0x2, 
    0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1f5, 0x7, 0x28, 0x2, 0x2, 
    0x1ed, 0x1f2, 0x5, 0x4e, 0x28, 0x2, 0x1ee, 0x1f2, 0x5, 0x3c, 0x1f, 0x2, 
    0x1ef, 0x1f2, 0x5, 0x24, 0x13, 0x2, 0x1f0, 0x1f2, 0x5, 0x4a, 0x26, 0x2, 
    0x1f1, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1ee, 0x3, 0x2, 0x2, 0x2, 
    0x1f1, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f0, 0x3, 0x2, 0x2, 0x2, 
    0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x3, 0x2, 0x2, 
    0x1f4, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 
    0x1f7, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1f9, 0x1fa, 0x7, 0x45, 0x2, 0x2, 0x1fa, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1fd, 0x7, 0x34, 0x2, 0x2, 0x1fc, 0x1fe, 0x9, 0x5, 0x2, 0x2, 
    0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x203, 0x7, 0x96, 0x2, 0x2, 
    0x200, 0x201, 0x7, 0x54, 0x2, 0x2, 0x201, 0x202, 0x7, 0x6a, 0x2, 0x2, 
    0x202, 0x204, 0x7, 0x49, 0x2, 0x2, 0x203, 0x200, 0x3, 0x2, 0x2, 0x2, 
    0x203, 0x204, 0x3, 0x2, 0x2, 0x2, 0x204, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x205, 0x206, 0x5, 0x9c, 0x4f, 0x2, 0x206, 0x207, 0x7, 0x4, 0x2, 0x2, 
    0x207, 0x209, 0x3, 0x2, 0x2, 0x2, 0x208, 0x205, 0x3, 0x2, 0x2, 0x2, 
    0x208, 0x209, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x20a, 0x20b, 0x5, 0xb2, 0x5a, 0x2, 0x20b, 0x20c, 0x7, 0x23, 0x2, 0x2, 
    0x20c, 0x20d, 0x5, 0x4a, 0x26, 0x2, 0x20d, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20f, 0x7, 0x34, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x97, 0x2, 0x2, 
    0x210, 0x214, 0x7, 0x87, 0x2, 0x2, 0x211, 0x212, 0x7, 0x54, 0x2, 0x2, 
    0x212, 0x213, 0x7, 0x6a, 0x2, 0x2, 0x213, 0x215, 0x7, 0x49, 0x2, 0x2, 
    0x214, 0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x215, 0x3, 0x2, 0x2, 0x2, 
    0x215, 0x219, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x5, 0x9c, 0x4f, 0x2, 
    0x217, 0x218, 0x7, 0x4, 0x2, 0x2, 0x218, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x219, 0x216, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21c, 0x5, 0xa2, 0x52, 0x2, 
    0x21c, 0x21d, 0x7, 0x93, 0x2, 0x2, 0x21d, 0x229, 0x5, 0xb4, 0x5b, 0x2, 
    0x21e, 0x21f, 0x7, 0x5, 0x2, 0x2, 0x21f, 0x224, 0x5, 0x92, 0x4a, 0x2, 
    0x220, 0x221, 0x7, 0x7, 0x2, 0x2, 0x221, 0x223, 0x5, 0x92, 0x4a, 0x2, 
    0x222, 0x220, 0x3, 0x2, 0x2, 0x2, 0x223, 0x226, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 0x2, 0x2, 0x2, 
    0x225, 0x227, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x227, 0x228, 0x7, 0x6, 0x2, 0x2, 0x228, 0x22a, 0x3, 0x2, 0x2, 0x2, 
    0x229, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 
    0x22a, 0x23, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22d, 0x5, 0x6e, 0x38, 0x2, 
    0x22c, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22d, 0x3, 0x2, 0x2, 0x2, 
    0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x7, 0x3d, 0x2, 0x2, 
    0x22f, 0x230, 0x7, 0x4f, 0x2, 0x2, 0x230, 0x233, 0x5, 0x70, 0x39, 0x2, 
    0x231, 0x232, 0x7, 0x99, 0x2, 0x2, 0x232, 0x234, 0x5, 0x86, 0x44, 0x2, 
    0x233, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x3, 0x2, 0x2, 0x2, 
    0x234, 0x25, 0x3, 0x2, 0x2, 0x2, 0x235, 0x237, 0x5, 0x6e, 0x38, 0x2, 
    0x236, 0x235, 0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 
    0x237, 0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x7, 0x3d, 0x2, 0x2, 
    0x239, 0x23a, 0x7, 0x4f, 0x2, 0x2, 0x23a, 0x23d, 0x5, 0x70, 0x39, 0x2, 
    0x23b, 0x23c, 0x7, 0x99, 0x2, 0x2, 0x23c, 0x23e, 0x5, 0x64, 0x33, 0x2, 
    0x23d, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x23e, 0x3, 0x2, 0x2, 0x2, 
    0x23e, 0x251, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x71, 0x2, 0x2, 
    0x240, 0x241, 0x7, 0x2a, 0x2, 0x2, 0x241, 0x246, 0x5, 0x72, 0x3a, 0x2, 
    0x242, 0x243, 0x7, 0x7, 0x2, 0x2, 0x243, 0x245, 0x5, 0x72, 0x3a, 0x2, 
    0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x245, 0x248, 0x3, 0x2, 0x2, 0x2, 
    0x246, 0x244, 0x3, 0x2, 0x2, 0x2, 0x246, 0x247, 0x3, 0x2, 0x2, 0x2, 
    0x247, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 0x2, 0x2, 
    0x249, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 
    0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x7, 0x66, 0x2, 0x2, 
    0x24c, 0x24f, 0x5, 0x64, 0x33, 0x2, 0x24d, 0x24e, 0x9, 0x4, 0x2, 0x2, 
    0x24e, 0x250, 0x5, 0x64, 0x33, 0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 0x2, 
    0x24f, 0x250, 0x3, 0x2, 0x2, 0x2, 0x250, 0x252, 0x3, 0x2, 0x2, 0x2, 
    0x251, 0x249, 0x3, 0x2, 0x2, 0x2, 0x251, 0x252, 0x3, 0x2, 0x2, 0x2, 
    0x252, 0x27, 0x3, 0x2, 0x2, 0x2, 0x253, 0x255, 0x7, 0x40, 0x2, 0x2, 
    0x254, 0x256, 0x7, 0x39, 0x2, 0x2, 0x255, 0x254, 0x3, 0x2, 0x2, 0x2, 
    0x255, 0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 
    0x257, 0x258, 0x5, 0x9c, 0x4f, 0x2, 0x258, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x259, 0x25a, 0x7, 0x42, 0x2, 0x2, 0x25a, 0x25d, 0x7, 0x58, 0x2, 0x2, 
    0x25b, 0x25c, 0x7, 0x54, 0x2, 0x2, 0x25c, 0x25e, 0x7, 0x49, 0x2, 0x2, 
    0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x262, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 0x5, 0x9c, 0x4f, 0x2, 
    0x260, 0x261, 0x7, 0x4, 0x2, 0x2, 0x261, 0x263, 0x3, 0x2, 0x2, 0x2, 
    0x262, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 0x2, 0x2, 
    0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x265, 0x5, 0xae, 0x58, 0x2, 
    0x265, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x7, 0x42, 0x2, 0x2, 
    0x267, 0x26a, 0x7, 0x87, 0x2, 0x2, 0x268, 0x269, 0x7, 0x54, 0x2, 0x2, 
    0x269, 0x26b, 0x7, 0x49, 0x2, 0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26f, 0x3, 0x2, 0x2, 0x2, 
    0x26c, 0x26d, 0x5, 0x9c, 0x4f, 0x2, 0x26d, 0x26e, 0x7, 0x4, 0x2, 0x2, 
    0x26e, 0x270, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26c, 0x3, 0x2, 0x2, 0x2, 
    0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 
    0x271, 0x272, 0x5, 0xa2, 0x52, 0x2, 0x272, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x273, 0x274, 0x7, 0x42, 0x2, 0x2, 0x274, 0x277, 0x7, 0x8e, 0x2, 0x2, 
    0x275, 0x276, 0x7, 0x54, 0x2, 0x2, 0x276, 0x278, 0x7, 0x49, 0x2, 0x2, 
    0x277, 0x275, 0x3, 0x2, 0x2, 0x2, 0x277, 0x278, 0x3, 0x2, 0x2, 0x2, 
    0x278, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27a, 0x5, 0x9c, 0x4f, 0x2, 
    0x27a, 0x27b, 0x7, 0x4, 0x2, 0x2, 0x27b, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x27c, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x3, 0x2, 0x2, 0x2, 
    0x27d, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x27f, 0x5, 0xb0, 0x59, 0x2, 
    0x27f, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x280, 0x281, 0x7, 0x42, 0x2, 0x2, 
    0x281, 0x284, 0x7, 0x96, 0x2, 0x2, 0x282, 0x283, 0x7, 0x54, 0x2, 0x2, 
    0x283, 0x285, 0x7, 0x49, 0x2, 0x2, 0x284, 0x282, 0x3, 0x2, 0x2, 0x2, 
    0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x289, 0x3, 0x2, 0x2, 0x2, 
    0x286, 0x287, 0x5, 0x9c, 0x4f, 0x2, 0x287, 0x288, 0x7, 0x4, 0x2, 0x2, 
    0x288, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x289, 0x286, 0x3, 0x2, 0x2, 0x2, 
    0x289, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 
    0x28b, 0x28c, 0x5, 0xb2, 0x5a, 0x2, 0x28c, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x28d, 0x28f, 0x5, 0x6e, 0x38, 0x2, 0x28e, 0x28d, 0x3, 0x2, 0x2, 0x2, 
    0x28e, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 0x3, 0x2, 0x2, 0x2, 
    0x290, 0x296, 0x5, 0x84, 0x43, 0x2, 0x291, 0x292, 0x5, 0x88, 0x45, 0x2, 
    0x292, 0x293, 0x5, 0x84, 0x43, 0x2, 0x293, 0x295, 0x3, 0x2, 0x2, 0x2, 
    0x294, 0x291, 0x3, 0x2, 0x2, 0x2, 0x295, 0x298, 0x3, 0x2, 0x2, 0x2, 
    0x296, 0x294, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x3, 0x2, 0x2, 0x2, 
    0x297, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x298, 0x296, 0x3, 0x2, 0x2, 0x2, 
    0x299, 0x29a, 0x7, 0x71, 0x2, 0x2, 0x29a, 0x29b, 0x7, 0x2a, 0x2, 0x2, 
    0x29b, 0x2a0, 0x5, 0x72, 0x3a, 0x2, 0x29c, 0x29d, 0x7, 0x7, 0x2, 0x2, 
    0x29d, 0x29f, 0x5, 0x72, 0x3a, 0x2, 0x29e, 0x29c, 0x3, 0x2, 0x2, 0x2, 
    0x29f, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x2a0, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a4, 0x3, 0x2, 0x2, 0x2, 
    0x2a2, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x2a3, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2ab, 0x3, 0x2, 0x2, 0x2, 
    0x2a5, 0x2a6, 0x7, 0x66, 0x2, 0x2, 0x2a6, 0x2a9, 0x5, 0x64, 0x33, 0x2, 
    0x2a7, 0x2a8, 0x9, 0x4, 0x2, 0x2, 0x2a8, 0x2aa, 0x5, 0x64, 0x33, 0x2, 
    0x2a9, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2aa, 0x3, 0x2, 0x2, 0x2, 
    0x2aa, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2a5, 0x3, 0x2, 0x2, 0x2, 
    0x2ab, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2bf, 0x7, 0x5c, 0x2, 0x2, 0x2ae, 0x2bf, 0x7, 0x7e, 0x2, 0x2, 0x2af, 
    0x2b0, 0x7, 0x5c, 0x2, 0x2, 0x2b0, 0x2b1, 0x7, 0x70, 0x2, 0x2, 0x2b1, 
    0x2bf, 0x7, 0x7e, 0x2, 0x2, 0x2b2, 0x2b3, 0x7, 0x5c, 0x2, 0x2, 0x2b3, 
    0x2b4, 0x7, 0x70, 0x2, 0x2, 0x2b4, 0x2bf, 0x7, 0x81, 0x2, 0x2, 0x2b5, 
    0x2b6, 0x7, 0x5c, 0x2, 0x2, 0x2b6, 0x2b7, 0x7, 0x70, 0x2, 0x2, 0x2b7, 
    0x2bf, 0x7, 0x1b, 0x2, 0x2, 0x2b8, 0x2b9, 0x7, 0x5c, 0x2, 0x2, 0x2b9, 
    0x2ba, 0x7, 0x70, 0x2, 0x2, 0x2ba, 0x2bf, 0x7, 0x4b, 0x2, 0x2, 0x2bb, 
    0x2bc, 0x7, 0x5c, 0x2, 0x2, 0x2bc, 0x2bd, 0x7, 0x70, 0x2, 0x2, 0x2bd, 
    0x2bf, 0x7, 0x55, 0x2, 0x2, 0x2be, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2be, 
    0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bf, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x7, 0x5, 0x2, 0x2, 0x2c1, 0x2c6, 
    0x5, 0x64, 0x33, 0x2, 0x2c2, 0x2c3, 0x7, 0x7, 0x2, 0x2, 0x2c3, 0x2c5, 
    0x5, 0x64, 0x33, 0x2, 0x2c4, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c8, 
    0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 
    0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c6, 
    0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x6, 0x2, 0x2, 0x2ca, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x2cb, 0x2d0, 0x5, 0x36, 0x1c, 0x2, 0x2cc, 0x2cd, 0x7, 
    0x7, 0x2, 0x2, 0x2cd, 0x2cf, 0x5, 0x36, 0x1c, 0x2, 0x2ce, 0x2cc, 0x3, 
    0x2, 0x2, 0x2, 0x2cf, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2ce, 0x3, 
    0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 0x5, 
    0x2, 0x2, 0x2d4, 0x2d9, 0x5, 0xa8, 0x55, 0x2, 0x2d5, 0x2d6, 0x7, 0x7, 
    0x2, 0x2, 0x2d6, 0x2d8, 0x5, 0xa8, 0x55, 0x2, 0x2d7, 0x2d5, 0x3, 0x2, 
    0x2, 0x2, 0x2d8, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2d9, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2dc, 0x3, 0x2, 
    0x2, 0x2, 0x2db, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x7, 0x6, 
    0x2, 0x2, 0x2dd, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2e0, 0x5, 0x6e, 
    0x38, 0x2, 0x2df, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x5, 0x34, 
    0x1b, 0x2, 0x2e2, 0x2e6, 0x7, 0x5f, 0x2, 0x2, 0x2e3, 0x2e4, 0x5, 0x9c, 
    0x4f, 0x2, 0x2e4, 0x2e5, 0x7, 0x4, 0x2, 0x2, 0x2e5, 0x2e7, 0x3, 0x2, 
    0x2, 0x2, 0x2e6, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 
    0x2, 0x2, 0x2e7, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2ea, 0x5, 0xa2, 
    0x52, 0x2, 0x2e9, 0x2eb, 0x5, 0x3a, 0x1e, 0x2, 0x2ea, 0x2e9, 0x3, 0x2, 
    0x2, 0x2, 0x2ea, 0x2eb, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2f1, 0x3, 0x2, 
    0x2, 0x2, 0x2ec, 0x2ed, 0x7, 0x95, 0x2, 0x2, 0x2ed, 0x2f2, 0x5, 0x38, 
    0x1d, 0x2, 0x2ee, 0x2f2, 0x5, 0x4a, 0x26, 0x2, 0x2ef, 0x2f0, 0x7, 0x3a, 
    0x2, 0x2, 0x2f0, 0x2f2, 0x7, 0x95, 0x2, 0x2, 0x2f1, 0x2ec, 0x3, 0x2, 
    0x2, 0x2, 0x2f1, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2ef, 0x3, 0x2, 
    0x2, 0x2, 0x2f2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f7, 0x7, 0x74, 
    0x2, 0x2, 0x2f4, 0x2f5, 0x5, 0x9c, 0x4f, 0x2, 0x2f5, 0x2f6, 0x7, 0x4, 
    0x2, 0x2, 0x2f6, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f4, 0x3, 0x2, 
    0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 0x2, 
    0x2, 0x2, 0x2f9, 0x300, 0x5, 0xb6, 0x5c, 0x2, 0x2fa, 0x2fb, 0x7, 0x8, 
    0x2, 0x2, 0x2fb, 0x301, 0x5, 0x74, 0x3b, 0x2, 0x2fc, 0x2fd, 0x7, 0x5, 
    0x2, 0x2, 0x2fd, 0x2fe, 0x5, 0x74, 0x3b, 0x2, 0x2fe, 0x2ff, 0x7, 0x6, 
    0x2, 0x2, 0x2ff, 0x301, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fa, 0x3, 0x2, 
    0x2, 0x2, 0x300, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 0x2, 
    0x2, 0x2, 0x301, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x302, 0x30d, 0x7, 0x7b, 
    0x2, 0x2, 0x303, 0x30e, 0x5, 0xaa, 0x56, 0x2, 0x304, 0x305, 0x5, 0x9c, 
    0x4f, 0x2, 0x305, 0x306, 0x7, 0x4, 0x2, 0x2, 0x306, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x307, 0x304, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x3, 0x2, 
    0x2, 0x2, 0x308, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30c, 0x5, 0xa2, 
    0x52, 0x2, 0x30a, 0x30c, 0x5, 0xae, 0x58, 0x2, 0x30b, 0x309, 0x3, 0x2, 
    0x2, 0x2, 0x30b, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30e, 0x3, 0x2, 
    0x2, 0x2, 0x30d, 0x303, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x307, 0x3, 0x2, 
    0x2, 0x2, 0x30d, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x30f, 0x311, 0x7, 0x7c, 0x2, 0x2, 0x310, 0x312, 0x7, 0x83, 0x2, 
    0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 0x3, 0x2, 0x2, 
    0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x5, 0xb8, 0x5d, 
    0x2, 0x314, 0x43, 0x3, 0x2, 0x2, 0x2, 0x315, 0x31a, 0x7, 0x81, 0x2, 
    0x2, 0x316, 0x318, 0x7, 0x8d, 0x2, 0x2, 0x317, 0x319, 0x5, 0xbc, 0x5f, 
    0x2, 0x318, 0x317, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 0x3, 0x2, 0x2, 
    0x2, 0x319, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x316, 0x3, 0x2, 0x2, 
    0x2, 0x31a, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x321, 0x3, 0x2, 0x2, 
    0x2, 0x31c, 0x31e, 0x7, 0x8c, 0x2, 0x2, 0x31d, 0x31f, 0x7, 0x83, 0x2, 
    0x2, 0x31e, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 0x3, 0x2, 0x2, 
    0x2, 0x31f, 0x320, 0x3, 0x2, 0x2, 0x2, 0x320, 0x322, 0x5, 0xb8, 0x5d, 
    0x2, 0x321, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 0x2, 
    0x2, 0x322, 0x45, 0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 0x7, 0x83, 0x2, 
    0x2, 0x324, 0x325, 0x5, 0xb8, 0x5d, 0x2, 0x325, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x326, 0x328, 0x5, 0x6e, 0x38, 0x2, 0x327, 0x326, 0x3, 0x2, 0x2, 
    0x2, 0x327, 0x328, 0x3, 0x2, 0x2, 0x2, 0x328, 0x329, 0x3, 0x2, 0x2, 
    0x2, 0x329, 0x334, 0x5, 0x84, 0x43, 0x2, 0x32a, 0x32b, 0x7, 0x71, 0x2, 
    0x2, 0x32b, 0x32c, 0x7, 0x2a, 0x2, 0x2, 0x32c, 0x331, 0x5, 0x72, 0x3a, 
    0x2, 0x32d, 0x32e, 0x7, 0x7, 0x2, 0x2, 0x32e, 0x330, 0x5, 0x72, 0x3a, 
    0x2, 0x32f, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x330, 0x333, 0x3, 0x2, 0x2, 
    0x2, 0x331, 0x32f, 0x3, 0x2, 0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 
    0x2, 0x332, 0x335, 0x3, 0x2, 0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 
    0x2, 0x334, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 0x3, 0x2, 0x2, 
    0x2, 0x335, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0x7, 0x66, 0x2, 
    0x2, 0x337, 0x33a, 0x5, 0x64, 0x33, 0x2, 0x338, 0x339, 0x9, 0x4, 0x2, 
    0x2, 0x339, 0x33b, 0x5, 0x64, 0x33, 0x2, 0x33a, 0x338, 0x3, 0x2, 0x2, 
    0x2, 0x33a, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x33d, 0x3, 0x2, 0x2, 
    0x2, 0x33c, 0x336, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 0x2, 
    0x2, 0x33d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x340, 0x5, 0x6e, 0x38, 
    0x2, 0x33f, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 
    0x2, 0x340, 0x341, 0x3, 0x2, 0x2, 0x2, 0x341, 0x347, 0x5, 0x4c, 0x27, 
    0x2, 0x342, 0x343, 0x5, 0x88, 0x45, 0x2, 0x343, 0x344, 0x5, 0x4c, 0x27, 
    0x2, 0x344, 0x346, 0x3, 0x2, 0x2, 0x2, 0x345, 0x342, 0x3, 0x2, 0x2, 
    0x2, 0x346, 0x349, 0x3, 0x2, 0x2, 0x2, 0x347, 0x345, 0x3, 0x2, 0x2, 
    0x2, 0x347, 0x348, 0x3, 0x2, 0x2, 0x2, 0x348, 0x354, 0x3, 0x2, 0x2, 
    0x2, 0x349, 0x347, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34b, 0x7, 0x71, 0x2, 
    0x2, 0x34b, 0x34c, 0x7, 0x2a, 0x2, 0x2, 0x34c, 0x351, 0x5, 0x72, 0x3a, 
    0x2, 0x34d, 0x34e, 0x7, 0x7, 0x2, 0x2, 0x34e, 0x350, 0x5, 0x72, 0x3a, 
    0x2, 0x34f, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x350, 0x353, 0x3, 0x2, 0x2, 
    0x2, 0x351, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 0x3, 0x2, 0x2, 
    0x2, 0x352, 0x355, 0x3, 0x2, 0x2, 0x2, 0x353, 0x351, 0x3, 0x2, 0x2, 
    0x2, 0x354, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 0x3, 0x2, 0x2, 
    0x2, 0x355, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x356, 0x357, 0x7, 0x66, 0x2, 
    0x2, 0x357, 0x35a, 0x5, 0x64, 0x33, 0x2, 0x358, 0x359, 0x9, 0x4, 0x2, 
    0x2, 0x359, 0x35b, 0x5, 0x64, 0x33, 0x2, 0x35a, 0x358, 0x3, 0x2, 0x2, 
    0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35d, 0x3, 0x2, 0x2, 
    0x2, 0x35c, 0x356, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 
    0x2, 0x35d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x360, 0x7, 0x84, 0x2, 
    0x2, 0x35f, 0x361, 0x9, 0x6, 0x2, 0x2, 0x360, 0x35f, 0x3, 0x2, 0x2, 
    0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 0x3, 0x2, 0x2, 
    0x2, 0x362, 0x367, 0x5, 0x78, 0x3d, 0x2, 0x363, 0x364, 0x7, 0x7, 0x2, 
    0x2, 0x364, 0x366, 0x5, 0x78, 0x3d, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 
    0x2, 0x366, 0x369, 0x3, 0x2, 0x2, 0x2, 0x367, 0x365, 0x3, 0x2, 0x2, 
    0x2, 0x367, 0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 0x376, 0x3, 0x2, 0x2, 
    0x2, 0x369, 0x367, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x374, 0x7, 0x4f, 0x2, 
    0x2, 0x36b, 0x370, 0x5, 0x7a, 0x3e, 0x2, 0x36c, 0x36d, 0x7, 0x7, 0x2, 
    0x2, 0x36d, 0x36f, 0x5, 0x7a, 0x3e, 0x2, 0x36e, 0x36c, 0x3, 0x2, 0x2, 
    0x2, 0x36f, 0x372, 0x3, 0x2, 0x2, 0x2, 0x370, 0x36e, 0x3, 0x2, 0x2, 
    0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 0x371, 0x375, 0x3, 0x2, 0x2, 
    0x2, 0x372, 0x370, 0x3, 0x2, 0x2, 0x2, 0x373, 0x375, 0x5, 0x7c, 0x3f, 
    0x2, 0x374, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x374, 0x373, 0x3, 0x2, 0x2, 
    0x2, 0x375, 0x377, 0x3, 0x2, 0x2, 0x2, 0x376, 0x36a, 0x3, 0x2, 0x2, 
    0x2, 0x376, 0x377, 0x3, 0x2, 0x2, 0x2, 0x377, 0x37a, 0x3, 0x2, 0x2, 
    0x2, 0x378, 0x379, 0x7, 0x99, 0x2, 0x2, 0x379, 0x37b, 0x5, 0x64, 0x33, 
    0x2, 0x37a, 0x378, 0x3, 0x2, 0x2, 0x2, 0x37a, 0x37b, 0x3, 0x2, 0x2, 
    0x2, 0x37b, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x7, 0x52, 0x2, 
    0x2, 0x37d, 0x37e, 0x7, 0x2a, 0x2, 0x2, 0x37e, 0x383, 0x5, 0x64, 0x33, 
    0x2, 0x37f, 0x380, 0x7, 0x7, 0x2, 0x2, 0x380, 0x382, 0x5, 0x64, 0x33, 
    0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x382, 0x385, 0x3, 0x2, 0x2, 
    0x2, 0x383, 0x381, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 
    0x2, 0x384, 0x388, 0x3, 0x2, 0x2, 0x2, 0x385, 0x383, 0x3, 0x2, 0x2, 
    0x2, 0x386, 0x387, 0x7, 0x53, 0x2, 0x2, 0x387, 0x389, 0x5, 0x64, 0x33, 
    0x2, 0x388, 0x386, 0x3, 0x2, 0x2, 0x2, 0x388, 0x389, 0x3, 0x2, 0x2, 
    0x2, 0x389, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x37c, 0x3, 0x2, 0x2, 
    0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x3a9, 0x3, 0x2, 0x2, 
    0x2, 0x38c, 0x38d, 0x7, 0x95, 0x2, 0x2, 0x38d, 0x38e, 0x7, 0x5, 0x2, 
    0x2, 0x38e, 0x393, 0x5, 0x64, 0x33, 0x2, 0x38f, 0x390, 0x7, 0x7, 0x2, 
    0x2, 0x390, 0x392, 0x5, 0x64, 0x33, 0x2, 0x391, 0x38f, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x395, 0x3, 0x2, 0x2, 0x2, 0x393, 0x391, 0x3, 0x2, 0x2, 
    0x2, 0x393, 0x394, 0x3, 0x2, 0x2, 0x2, 0x394, 0x396, 0x3, 0x2, 0x2, 
    0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 0x2, 0x396, 0x3a5, 0x7, 0x6, 0x2, 
    0x2, 0x397, 0x398, 0x7, 0x7, 0x2, 0x2, 0x398, 0x399, 0x7, 0x5, 0x2, 
    0x2, 0x399, 0x39e, 0x5, 0x64, 0x33, 0x2, 0x39a, 0x39b, 0x7, 0x7, 0x2, 
    0x2, 0x39b, 0x39d, 0x5, 0x64, 0x33, 0x2, 0x39c, 0x39a, 0x3, 0x2, 0x2, 
    0x2, 0x39d, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39c, 0x3, 0x2, 0x2, 
    0x2, 0x39e, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a1, 0x3, 0x2, 0x2, 
    0x2, 0x3a0, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x7, 0x6, 0x2, 
    0x2, 0x3a2, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x397, 0x3, 0x2, 0x2, 
    0x2, 0x3a4, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a3, 0x3, 0x2, 0x2, 
    0x2, 0x3a5, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a9, 0x3, 0x2, 0x2, 
    0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x35e, 0x3, 0x2, 0x2, 
    0x2, 0x3a8, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x3aa, 0x3ac, 0x5, 0x6e, 0x38, 0x2, 0x3ab, 0x3aa, 0x3, 0x2, 0x2, 0x2, 
    0x3ab, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x3, 0x2, 0x2, 0x2, 
    0x3ad, 0x3b8, 0x7, 0x92, 0x2, 0x2, 0x3ae, 0x3af, 0x7, 0x70, 0x2, 0x2, 
    0x3af, 0x3b9, 0x7, 0x81, 0x2, 0x2, 0x3b0, 0x3b1, 0x7, 0x70, 0x2, 0x2, 
    0x3b1, 0x3b9, 0x7, 0x1b, 0x2, 0x2, 0x3b2, 0x3b3, 0x7, 0x70, 0x2, 0x2, 
    0x3b3, 0x3b9, 0x7, 0x7e, 0x2, 0x2, 0x3b4, 0x3b5, 0x7, 0x70, 0x2, 0x2, 
    0x3b5, 0x3b9, 0x7, 0x4b, 0x2, 0x2, 0x3b6, 0x3b7, 0x7, 0x70, 0x2, 0x2, 
    0x3b7, 0x3b9, 0x7, 0x55, 0x2, 0x2, 0x3b8, 0x3ae, 0x3, 0x2, 0x2, 0x2, 
    0x3b8, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b2, 0x3, 0x2, 0x2, 0x2, 
    0x3b8, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b6, 0x3, 0x2, 0x2, 0x2, 
    0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3ba, 0x3, 0x2, 0x2, 0x2, 
    0x3ba, 0x3bb, 0x5, 0x70, 0x39, 0x2, 0x3bb, 0x3bc, 0x7, 0x85, 0x2, 0x2, 
    0x3bc, 0x3bd, 0x5, 0xa8, 0x55, 0x2, 0x3bd, 0x3be, 0x7, 0x8, 0x2, 0x2, 
    0x3be, 0x3c6, 0x5, 0x64, 0x33, 0x2, 0x3bf, 0x3c0, 0x7, 0x7, 0x2, 0x2, 
    0x3c0, 0x3c1, 0x5, 0xa8, 0x55, 0x2, 0x3c1, 0x3c2, 0x7, 0x8, 0x2, 0x2, 
    0x3c2, 0x3c3, 0x5, 0x64, 0x33, 0x2, 0x3c3, 0x3c5, 0x3, 0x2, 0x2, 0x2, 
    0x3c4, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c8, 0x3, 0x2, 0x2, 0x2, 
    0x3c6, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 
    0x3c7, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3c6, 0x3, 0x2, 0x2, 0x2, 
    0x3c9, 0x3ca, 0x7, 0x99, 0x2, 0x2, 0x3ca, 0x3cc, 0x5, 0x86, 0x44, 0x2, 
    0x3cb, 0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3cc, 0x3, 0x2, 0x2, 0x2, 
    0x3cc, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cf, 0x5, 0x6e, 0x38, 0x2, 
    0x3ce, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 0x3, 0x2, 0x2, 0x2, 
    0x3cf, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3db, 0x7, 0x92, 0x2, 0x2, 
    0x3d1, 0x3d2, 0x7, 0x70, 0x2, 0x2, 0x3d2, 0x3dc, 0x7, 0x81, 0x2, 0x2, 
    0x3d3, 0x3d4, 0x7, 0x70, 0x2, 0x2, 0x3d4, 0x3dc, 0x7, 0x1b, 0x2, 0x2, 
    0x3d5, 0x3d6, 0x7, 0x70, 0x2, 0x2, 0x3d6, 0x3dc, 0x7, 0x7e, 0x2, 0x2, 
    0x3d7, 0x3d8, 0x7, 0x70, 0x2, 0x2, 0x3d8, 0x3dc, 0x7, 0x4b, 0x2, 0x2, 
    0x3d9, 0x3da, 0x7, 0x70, 0x2, 0x2, 0x3da, 0x3dc, 0x7, 0x55, 0x2, 0x2, 
    0x3db, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d3, 0x3, 0x2, 0x2, 0x2, 
    0x3db, 0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d7, 0x3, 0x2, 0x2, 0x2, 
    0x3db, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 
    0x3dc, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3de, 0x5, 0x70, 0x39, 0x2, 
    0x3de, 0x3df, 0x7, 0x85, 0x2, 0x2, 0x3df, 0x3e0, 0x5, 0xa8, 0x55, 0x2, 
    0x3e0, 0x3e1, 0x7, 0x8, 0x2, 0x2, 0x3e1, 0x3e9, 0x5, 0x64, 0x33, 0x2, 
    0x3e2, 0x3e3, 0x7, 0x7, 0x2, 0x2, 0x3e3, 0x3e4, 0x5, 0xa8, 0x55, 0x2, 
    0x3e4, 0x3e5, 0x7, 0x8, 0x2, 0x2, 0x3e5, 0x3e6, 0x5, 0x64, 0x33, 0x2, 
    0x3e6, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e2, 0x3, 0x2, 0x2, 0x2, 
    0x3e8, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3e7, 0x3, 0x2, 0x2, 0x2, 
    0x3e9, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3ee, 0x3, 0x2, 0x2, 0x2, 
    0x3eb, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x7, 0x99, 0x2, 0x2, 
    0x3ed, 0x3ef, 0x5, 0x86, 0x44, 0x2, 0x3ee, 0x3ec, 0x3, 0x2, 0x2, 0x2, 
    0x3ee, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3ef, 0x402, 0x3, 0x2, 0x2, 0x2, 
    0x3f0, 0x3f1, 0x7, 0x71, 0x2, 0x2, 0x3f1, 0x3f2, 0x7, 0x2a, 0x2, 0x2, 
    0x3f2, 0x3f7, 0x5, 0x72, 0x3a, 0x2, 0x3f3, 0x3f4, 0x7, 0x7, 0x2, 0x2, 
    0x3f4, 0x3f6, 0x5, 0x72, 0x3a, 0x2, 0x3f5, 0x3f3, 0x3, 0x2, 0x2, 0x2, 
    0x3f6, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f5, 0x3, 0x2, 0x2, 0x2, 
    0x3f7, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3fb, 0x3, 0x2, 0x2, 0x2, 
    0x3f9, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3f0, 0x3, 0x2, 0x2, 0x2, 
    0x3fa, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fc, 0x3, 0x2, 0x2, 0x2, 
    0x3fc, 0x3fd, 0x7, 0x66, 0x2, 0x2, 0x3fd, 0x400, 0x5, 0x64, 0x33, 0x2, 
    0x3fe, 0x3ff, 0x9, 0x4, 0x2, 0x2, 0x3ff, 0x401, 0x5, 0x64, 0x33, 0x2, 
    0x400, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x400, 0x401, 0x3, 0x2, 0x2, 0x2, 
    0x401, 0x403, 0x3, 0x2, 0x2, 0x2, 0x402, 0x3fa, 0x3, 0x2, 0x2, 0x2, 
    0x402, 0x403, 0x3, 0x2, 0x2, 0x2, 0x403, 0x51, 0x3, 0x2, 0x2, 0x2, 0x404, 
    0x405, 0x7, 0x94, 0x2, 0x2, 0x405, 0x53, 0x3, 0x2, 0x2, 0x2, 0x406, 
    0x408, 0x5, 0xa8, 0x55, 0x2, 0x407, 0x409, 0x5, 0x56, 0x2c, 0x2, 0x408, 
    0x407, 0x3, 0x2, 0x2, 0x2, 0x408, 0x409, 0x3, 0x2, 0x2, 0x2, 0x409, 
    0x40d, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40c, 0x5, 0x58, 0x2d, 0x2, 0x40b, 
    0x40a, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x40f, 0x3, 0x2, 0x2, 0x2, 0x40d, 
    0x40b, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40e, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x410, 0x412, 
    0x5, 0x98, 0x4d, 0x2, 0x411, 0x410, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 
    0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 0x3, 0x2, 0x2, 0x2, 0x413, 0x411, 
    0x3, 0x2, 0x2, 0x2, 0x414, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 
    0x7, 0x5, 0x2, 0x2, 0x416, 0x417, 0x5, 0x8a, 0x46, 0x2, 0x417, 0x418, 
    0x7, 0x6, 0x2, 0x2, 0x418, 0x420, 0x3, 0x2, 0x2, 0x2, 0x419, 0x41a, 
    0x7, 0x5, 0x2, 0x2, 0x41a, 0x41b, 0x5, 0x8a, 0x46, 0x2, 0x41b, 0x41c, 
    0x7, 0x7, 0x2, 0x2, 0x41c, 0x41d, 0x5, 0x8a, 0x46, 0x2, 0x41d, 0x41e, 
    0x7, 0x6, 0x2, 0x2, 0x41e, 0x420, 0x3, 0x2, 0x2, 0x2, 0x41f, 0x415, 
    0x3, 0x2, 0x2, 0x2, 0x41f, 0x419, 0x3, 0x2, 0x2, 0x2, 0x41f, 0x420, 
    0x3, 0x2, 0x2, 0x2, 0x420, 0x57, 0x3, 0x2, 0x2, 0x2, 0x421, 0x422, 0x7, 
    0x33, 0x2, 0x2, 0x422, 0x424, 0x5, 0x98, 0x4d, 0x2, 0x423, 0x421, 0x3, 
    0x2, 0x2, 0x2, 0x423, 0x424, 0x3, 0x2, 0x2, 0x2, 0x424, 0x443, 0x3, 
    0x2, 0x2, 0x2, 0x425, 0x427, 0x5, 0x5c, 0x2f, 0x2, 0x426, 0x428, 0x9, 
    0x7, 0x2, 0x2, 0x427, 0x426, 0x3, 0x2, 0x2, 0x2, 0x427, 0x428, 0x3, 
    0x2, 0x2, 0x2, 0x428, 0x429, 0x3, 0x2, 0x2, 0x2, 0x429, 0x42b, 0x5, 
    0x60, 0x31, 0x2, 0x42a, 0x42c, 0x5, 0x5e, 0x30, 0x2, 0x42b, 0x42a, 0x3, 
    0x2, 0x2, 0x2, 0x42b, 0x42c, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x444, 0x3, 
    0x2, 0x2, 0x2, 0x42d, 0x42e, 0x5, 0x5a, 0x2e, 0x2, 0x42e, 0x42f, 0x5, 
    0x60, 0x31, 0x2, 0x42f, 0x444, 0x3, 0x2, 0x2, 0x2, 0x430, 0x431, 0x7, 
    0x91, 0x2, 0x2, 0x431, 0x444, 0x5, 0x60, 0x31, 0x2, 0x432, 0x433, 0x7, 
    0x2e, 0x2, 0x2, 0x433, 0x434, 0x7, 0x5, 0x2, 0x2, 0x434, 0x435, 0x5, 
    0x64, 0x33, 0x2, 0x435, 0x436, 0x7, 0x6, 0x2, 0x2, 0x436, 0x444, 0x3, 
    0x2, 0x2, 0x2, 0x437, 0x43e, 0x7, 0x3a, 0x2, 0x2, 0x438, 0x43f, 0x5, 
    0x8a, 0x46, 0x2, 0x439, 0x43f, 0x5, 0x8c, 0x47, 0x2, 0x43a, 0x43b, 0x7, 
    0x5, 0x2, 0x2, 0x43b, 0x43c, 0x5, 0x64, 0x33, 0x2, 0x43c, 0x43d, 0x7, 
    0x6, 0x2, 0x2, 0x43d, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x438, 0x3, 
    0x2, 0x2, 0x2, 0x43e, 0x439, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x43a, 0x3, 
    0x2, 0x2, 0x2, 0x43f, 0x444, 0x3, 0x2, 0x2, 0x2, 0x440, 0x441, 0x7, 
    0x2f, 0x2, 0x2, 0x441, 0x444, 0x5, 0xaa, 0x56, 0x2, 0x442, 0x444, 0x5, 
    0x66, 0x34, 0x2, 0x443, 0x425, 0x3, 0x2, 0x2, 0x2, 0x443, 0x42d, 0x3, 
    0x2, 0x2, 0x2, 0x443, 0x430, 0x3, 0x2, 0x2, 0x2, 0x443, 0x432, 0x3, 
    0x2, 0x2, 0x2, 0x443, 0x437, 0x3, 0x2, 0x2, 0x2, 0x443, 0x440, 0x3, 
    0x2, 0x2, 0x2, 0x443, 0x442, 0x3, 0x2, 0x2, 0x2, 0x444, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x445, 0x446, 0x7, 0x6a, 0x2, 0x2, 0x446, 0x447, 0x7, 0x6c, 
    0x2, 0x2, 0x447, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x448, 0x449, 0x7, 0x75, 
    0x2, 0x2, 0x449, 0x44a, 0x7, 0x63, 0x2, 0x2, 0x44a, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x44b, 0x44c, 0x7, 0x26, 0x2, 0x2, 0x44c, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x44d, 0x44e, 0x7, 0x6f, 0x2, 0x2, 0x44e, 0x44f, 0x7, 0x32, 
    0x2, 0x2, 0x44f, 0x451, 0x9, 0x8, 0x2, 0x2, 0x450, 0x44d, 0x3, 0x2, 
    0x2, 0x2, 0x450, 0x451, 0x3, 0x2, 0x2, 0x2, 0x451, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x452, 0x454, 0x7, 0x41, 0x2, 0x2, 0x453, 0x452, 0x3, 0x2, 0x2, 
    0x2, 0x453, 0x454, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0x3, 0x2, 0x2, 
    0x2, 0x455, 0x45a, 0x5, 0x64, 0x33, 0x2, 0x456, 0x457, 0x7, 0x7, 0x2, 
    0x2, 0x457, 0x459, 0x5, 0x64, 0x33, 0x2, 0x458, 0x456, 0x3, 0x2, 0x2, 
    0x2, 0x459, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x45a, 0x458, 0x3, 0x2, 0x2, 
    0x2, 0x45a, 0x45b, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45f, 0x3, 0x2, 0x2, 
    0x2, 0x45c, 0x45a, 0x3, 0x2, 0x2, 0x2, 0x45d, 0x45f, 0x7, 0x9, 0x2, 
    0x2, 0x45e, 0x453, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x45d, 0x3, 0x2, 0x2, 
    0x2, 0x45e, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x460, 0x461, 0x8, 0x33, 0x1, 0x2, 0x461, 0x49b, 0x5, 0x8c, 0x47, 0x2, 
    0x462, 0x49b, 0x7, 0x9e, 0x2, 0x2, 0x463, 0x464, 0x5, 0xa2, 0x52, 0x2, 
    0x464, 0x465, 0x7, 0x4, 0x2, 0x2, 0x465, 0x467, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x463, 0x3, 0x2, 0x2, 0x2, 0x466, 0x467, 0x3, 0x2, 0x2, 0x2, 
    0x467, 0x468, 0x3, 0x2, 0x2, 0x2, 0x468, 0x49b, 0x5, 0xa8, 0x55, 0x2, 
    0x469, 0x46a, 0x5, 0x8e, 0x48, 0x2, 0x46a, 0x46b, 0x5, 0x64, 0x33, 0x17, 
    0x46b, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x46d, 0x5, 0x9a, 0x4e, 0x2, 
    0x46d, 0x46e, 0x7, 0x5, 0x2, 0x2, 0x46e, 0x46f, 0x5, 0x62, 0x32, 0x2, 
    0x46f, 0x470, 0x7, 0x6, 0x2, 0x2, 0x470, 0x49b, 0x3, 0x2, 0x2, 0x2, 
    0x471, 0x472, 0x7, 0x5, 0x2, 0x2, 0x472, 0x473, 0x5, 0x64, 0x33, 0x2, 
    0x473, 0x474, 0x7, 0x6, 0x2, 0x2, 0x474, 0x49b, 0x3, 0x2, 0x2, 0x2, 
    0x475, 0x476, 0x7, 0x2d, 0x2, 0x2, 0x476, 0x477, 0x7, 0x5, 0x2, 0x2, 
    0x477, 0x478, 0x5, 0x64, 0x33, 0x2, 0x478, 0x479, 0x7, 0x23, 0x2, 0x2, 
    0x479, 0x47a, 0x5, 0x56, 0x2c, 0x2, 0x47a, 0x47b, 0x7, 0x6, 0x2, 0x2, 
    0x47b, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x47c, 0x47e, 0x7, 0x6a, 0x2, 0x2, 
    0x47d, 0x47c, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x47e, 0x3, 0x2, 0x2, 0x2, 
    0x47e, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x481, 0x7, 0x49, 0x2, 0x2, 
    0x480, 0x47d, 0x3, 0x2, 0x2, 0x2, 0x480, 0x481, 0x3, 0x2, 0x2, 0x2, 
    0x481, 0x482, 0x3, 0x2, 0x2, 0x2, 0x482, 0x483, 0x7, 0x5, 0x2, 0x2, 
    0x483, 0x484, 0x5, 0x4a, 0x26, 0x2, 0x484, 0x485, 0x7, 0x6, 0x2, 0x2, 
    0x485, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x486, 0x488, 0x7, 0x2c, 0x2, 0x2, 
    0x487, 0x489, 0x5, 0x64, 0x33, 0x2, 0x488, 0x487, 0x3, 0x2, 0x2, 0x2, 
    0x488, 0x489, 0x3, 0x2, 0x2, 0x2, 0x489, 0x48f, 0x3, 0x2, 0x2, 0x2, 
    0x48a, 0x48b, 0x7, 0x98, 0x2, 0x2, 0x48b, 0x48c, 0x5, 0x64, 0x33, 0x2, 
    0x48c, 0x48d, 0x7, 0x8b, 0x2, 0x2, 0x48d, 0x48e, 0x5, 0x64, 0x33, 0x2, 
    0x48e, 0x490, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x48a, 0x3, 0x2, 0x2, 0x2, 
    0x490, 0x491, 0x3, 0x2, 0x2, 0x2, 0x491, 0x48f, 0x3, 0x2, 0x2, 0x2, 
    0x491, 0x492, 0x3, 0x2, 0x2, 0x2, 0x492, 0x495, 0x3, 0x2, 0x2, 0x2, 
    0x493, 0x494, 0x7, 0x44, 0x2, 0x2, 0x494, 0x496, 0x5, 0x64, 0x33, 0x2, 
    0x495, 0x493, 0x3, 0x2, 0x2, 0x2, 0x495, 0x496, 0x3, 0x2, 0x2, 0x2, 
    0x496, 0x497, 0x3, 0x2, 0x2, 0x2, 0x497, 0x498, 0x7, 0x45, 0x2, 0x2, 
    0x498, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x499, 0x49b, 0x5, 0x68, 0x35, 0x2, 
    0x49a, 0x460, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x462, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x466, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x469, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x471, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x475, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x480, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x486, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x499, 0x3, 0x2, 0x2, 0x2, 
    0x49b, 0x4f3, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x49d, 0xc, 0x16, 0x2, 0x2, 
    0x49d, 0x49e, 0x7, 0xd, 0x2, 0x2, 0x49e, 0x4f2, 0x5, 0x64, 0x33, 0x17, 
    0x49f, 0x4a0, 0xc, 0x15, 0x2, 0x2, 0x4a0, 0x4a1, 0x9, 0x9, 0x2, 0x2, 
    0x4a1, 0x4f2, 0x5, 0x64, 0x33, 0x16, 0x4a2, 0x4a3, 0xc, 0x14, 0x2, 0x2, 
    0x4a3, 0x4a4, 0x9, 0xa, 0x2, 0x2, 0x4a4, 0x4f2, 0x5, 0x64, 0x33, 0x15, 
    0x4a5, 0x4a6, 0xc, 0x13, 0x2, 0x2, 0x4a6, 0x4a7, 0x9, 0xb, 0x2, 0x2, 
    0x4a7, 0x4f2, 0x5, 0x64, 0x33, 0x14, 0x4a8, 0x4a9, 0xc, 0x12, 0x2, 0x2, 
    0x4a9, 0x4aa, 0x9, 0xc, 0x2, 0x2, 0x4aa, 0x4f2, 0x5, 0x64, 0x33, 0x13, 
    0x4ab, 0x4ac, 0xc, 0x11, 0x2, 0x2, 0x4ac, 0x4ad, 0x9, 0xd, 0x2, 0x2, 
    0x4ad, 0x4f2, 0x5, 0x64, 0x33, 0x12, 0x4ae, 0x4af, 0xc, 0xf, 0x2, 0x2, 
    0x4af, 0x4b0, 0x7, 0x22, 0x2, 0x2, 0x4b0, 0x4f2, 0x5, 0x64, 0x33, 0x10, 
    0x4b1, 0x4b2, 0xc, 0xe, 0x2, 0x2, 0x4b2, 0x4b3, 0x7, 0x70, 0x2, 0x2, 
    0x4b3, 0x4f2, 0x5, 0x64, 0x33, 0xf, 0x4b4, 0x4b5, 0xc, 0x7, 0x2, 0x2, 
    0x4b5, 0x4b7, 0x7, 0x60, 0x2, 0x2, 0x4b6, 0x4b8, 0x7, 0x6a, 0x2, 0x2, 
    0x4b7, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b8, 0x3, 0x2, 0x2, 0x2, 
    0x4b8, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4f2, 0x5, 0x64, 0x33, 0x8, 
    0x4ba, 0x4bc, 0xc, 0x6, 0x2, 0x2, 0x4bb, 0x4bd, 0x7, 0x6a, 0x2, 0x2, 
    0x4bc, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4bd, 0x3, 0x2, 0x2, 0x2, 
    0x4bd, 0x4be, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bf, 0x7, 0x29, 0x2, 0x2, 
    0x4bf, 0x4c0, 0x5, 0x64, 0x33, 0x2, 0x4c0, 0x4c1, 0x7, 0x22, 0x2, 0x2, 
    0x4c1, 0x4c2, 0x5, 0x64, 0x33, 0x7, 0x4c2, 0x4f2, 0x3, 0x2, 0x2, 0x2, 
    0x4c3, 0x4c5, 0xc, 0x10, 0x2, 0x2, 0x4c4, 0x4c6, 0x7, 0x6a, 0x2, 0x2, 
    0x4c5, 0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 0x3, 0x2, 0x2, 0x2, 
    0x4c6, 0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c7, 0x4db, 0x7, 0x57, 0x2, 0x2, 
    0x4c8, 0x4d2, 0x7, 0x5, 0x2, 0x2, 0x4c9, 0x4d3, 0x5, 0x4a, 0x26, 0x2, 
    0x4ca, 0x4cf, 0x5, 0x64, 0x33, 0x2, 0x4cb, 0x4cc, 0x7, 0x7, 0x2, 0x2, 
    0x4cc, 0x4ce, 0x5, 0x64, 0x33, 0x2, 0x4cd, 0x4cb, 0x3, 0x2, 0x2, 0x2, 
    0x4ce, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4cf, 0x4cd, 0x3, 0x2, 0x2, 0x2, 
    0x4cf, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4d3, 0x3, 0x2, 0x2, 0x2, 
    0x4d1, 0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4c9, 0x3, 0x2, 0x2, 0x2, 
    0x4d2, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4d3, 0x3, 0x2, 0x2, 0x2, 
    0x4d3, 0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4dc, 0x7, 0x6, 0x2, 0x2, 
    0x4d5, 0x4d6, 0x5, 0x9c, 0x4f, 0x2, 0x4d6, 0x4d7, 0x7, 0x4, 0x2, 0x2, 
    0x4d7, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d8, 0x4d5, 0x3, 0x2, 0x2, 0x2, 
    0x4d8, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4da, 0x3, 0x2, 0x2, 0x2, 
    0x4da, 0x4dc, 0x5, 0xa2, 0x52, 0x2, 0x4db, 0x4c8, 0x3, 0x2, 0x2, 0x2, 
    0x4db, 0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4f2, 0x3, 0x2, 0x2, 0x2, 
    0x4dd, 0x4de, 0xc, 0xa, 0x2, 0x2, 0x4de, 0x4df, 0x7, 0x2f, 0x2, 0x2, 
    0x4df, 0x4f2, 0x5, 0xaa, 0x56, 0x2, 0x4e0, 0x4e2, 0xc, 0x9, 0x2, 0x2, 
    0x4e1, 0x4e3, 0x7, 0x6a, 0x2, 0x2, 0x4e2, 0x4e1, 0x3, 0x2, 0x2, 0x2, 
    0x4e2, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4e4, 0x3, 0x2, 0x2, 0x2, 
    0x4e4, 0x4e5, 0x9, 0xe, 0x2, 0x2, 0x4e5, 0x4e8, 0x5, 0x64, 0x33, 0x2, 
    0x4e6, 0x4e7, 0x7, 0x46, 0x2, 0x2, 0x4e7, 0x4e9, 0x5, 0x64, 0x33, 0x2, 
    0x4e8, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e9, 0x3, 0x2, 0x2, 0x2, 
    0x4e9, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4ef, 0xc, 0x8, 0x2, 0x2, 
    0x4eb, 0x4f0, 0x7, 0x61, 0x2, 0x2, 0x4ec, 0x4f0, 0x7, 0x6b, 0x2, 0x2, 
    0x4ed, 0x4ee, 0x7, 0x6a, 0x2, 0x2, 0x4ee, 0x4f0, 0x7, 0x6c, 0x2, 0x2, 
    0x4ef, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4ec, 0x3, 0x2, 0x2, 0x2, 
    0x4ef, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f2, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x49f, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4a2, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4a5, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4a8, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4ab, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4b1, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4ba, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4dd, 0x3, 0x2, 0x2, 0x2, 
    0x4f1, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4ea, 0x3, 0x2, 0x2, 0x2, 
    0x4f2, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f1, 0x3, 0x2, 0x2, 0x2, 
    0x4f3, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x65, 0x3, 0x2, 0x2, 0x2, 0x4f5, 
    0x4f3, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x7, 0x79, 0x2, 0x2, 0x4f7, 
    0x503, 0x5, 0xac, 0x57, 0x2, 0x4f8, 0x4f9, 0x7, 0x5, 0x2, 0x2, 0x4f9, 
    0x4fe, 0x5, 0xa8, 0x55, 0x2, 0x4fa, 0x4fb, 0x7, 0x7, 0x2, 0x2, 0x4fb, 
    0x4fd, 0x5, 0xa8, 0x55, 0x2, 0x4fc, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
    0x500, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fe, 
    0x4ff, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x501, 0x3, 0x2, 0x2, 0x2, 0x500, 
    0x4fe, 0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x7, 0x6, 0x2, 0x2, 0x502, 
    0x504, 0x3, 0x2, 0x2, 0x2, 0x503, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x503, 
    0x504, 0x3, 0x2, 0x2, 0x2, 0x504, 0x517, 0x3, 0x2, 0x2, 0x2, 0x505, 
    0x506, 0x7, 0x6f, 0x2, 0x2, 0x506, 0x50f, 0x9, 0xf, 0x2, 0x2, 0x507, 
    0x508, 0x7, 0x85, 0x2, 0x2, 0x508, 0x510, 0x7, 0x6c, 0x2, 0x2, 0x509, 
    0x50a, 0x7, 0x85, 0x2, 0x2, 0x50a, 0x510, 0x7, 0x3a, 0x2, 0x2, 0x50b, 
    0x510, 0x7, 0x2b, 0x2, 0x2, 0x50c, 0x510, 0x7, 0x7f, 0x2, 0x2, 0x50d, 
    0x50e, 0x7, 0x69, 0x2, 0x2, 0x50e, 0x510, 0x7, 0x1c, 0x2, 0x2, 0x50f, 
    0x507, 0x3, 0x2, 0x2, 0x2, 0x50f, 0x509, 0x3, 0x2, 0x2, 0x2, 0x50f, 
    0x50b, 0x3, 0x2, 0x2, 0x2, 0x50f, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x50f, 
    0x50d, 0x3, 0x2, 0x2, 0x2, 0x510, 0x514, 0x3, 0x2, 0x2, 0x2, 0x511, 
    0x512, 0x7, 0x67, 0x2, 0x2, 0x512, 0x514, 0x5, 0x98, 0x4d, 0x2, 0x513, 
    0x505, 0x3, 0x2, 0x2, 0x2, 0x513, 0x511, 0x3, 0x2, 0x2, 0x2, 0x514, 
    0x516, 0x3, 0x2, 0x2, 0x2, 0x515, 0x513, 0x3, 0x2, 0x2, 0x2, 0x516, 
    0x519, 0x3, 0x2, 0x2, 0x2, 0x517, 0x515, 0x3, 0x2, 0x2, 0x2, 0x517, 
    0x518, 0x3, 0x2, 0x2, 0x2, 0x518, 0x524, 0x3, 0x2, 0x2, 0x2, 0x519, 
    0x517, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x51c, 0x7, 0x6a, 0x2, 0x2, 0x51b, 
    0x51a, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x51c, 
    0x51d, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x522, 0x7, 0x3b, 0x2, 0x2, 0x51e, 
    0x51f, 0x7, 0x5a, 0x2, 0x2, 0x51f, 0x523, 0x7, 0x3c, 0x2, 0x2, 0x520, 
    0x521, 0x7, 0x5a, 0x2, 0x2, 0x521, 0x523, 0x7, 0x56, 0x2, 0x2, 0x522, 
    0x51e, 0x3, 0x2, 0x2, 0x2, 0x522, 0x520, 0x3, 0x2, 0x2, 0x2, 0x522, 
    0x523, 0x3, 0x2, 0x2, 0x2, 0x523, 0x525, 0x3, 0x2, 0x2, 0x2, 0x524, 
    0x51b, 0x3, 0x2, 0x2, 0x2, 0x524, 0x525, 0x3, 0x2, 0x2, 0x2, 0x525, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x526, 0x527, 0x7, 0x77, 0x2, 0x2, 0x527, 
    0x52c, 0x7, 0x5, 0x2, 0x2, 0x528, 0x52d, 0x7, 0x55, 0x2, 0x2, 0x529, 
    0x52a, 0x9, 0x10, 0x2, 0x2, 0x52a, 0x52b, 0x7, 0x7, 0x2, 0x2, 0x52b, 
    0x52d, 0x5, 0x90, 0x49, 0x2, 0x52c, 0x528, 0x3, 0x2, 0x2, 0x2, 0x52c, 
    0x529, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x52e, 0x3, 0x2, 0x2, 0x2, 0x52e, 
    0x52f, 0x7, 0x6, 0x2, 0x2, 0x52f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x530, 0x533, 
    0x5, 0xa8, 0x55, 0x2, 0x531, 0x532, 0x7, 0x2f, 0x2, 0x2, 0x532, 0x534, 
    0x5, 0xaa, 0x56, 0x2, 0x533, 0x531, 0x3, 0x2, 0x2, 0x2, 0x533, 0x534, 
    0x3, 0x2, 0x2, 0x2, 0x534, 0x536, 0x3, 0x2, 0x2, 0x2, 0x535, 0x537, 
    0x9, 0x7, 0x2, 0x2, 0x536, 0x535, 0x3, 0x2, 0x2, 0x2, 0x536, 0x537, 
    0x3, 0x2, 0x2, 0x2, 0x537, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x538, 0x539, 0x7, 
    0x33, 0x2, 0x2, 0x539, 0x53b, 0x5, 0x98, 0x4d, 0x2, 0x53a, 0x538, 0x3, 
    0x2, 0x2, 0x2, 0x53a, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x560, 0x3, 
    0x2, 0x2, 0x2, 0x53c, 0x53d, 0x7, 0x75, 0x2, 0x2, 0x53d, 0x540, 0x7, 
    0x63, 0x2, 0x2, 0x53e, 0x540, 0x7, 0x91, 0x2, 0x2, 0x53f, 0x53c, 0x3, 
    0x2, 0x2, 0x2, 0x53f, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x540, 0x541, 0x3, 
    0x2, 0x2, 0x2, 0x541, 0x542, 0x7, 0x5, 0x2, 0x2, 0x542, 0x547, 0x5, 
    0x6a, 0x36, 0x2, 0x543, 0x544, 0x7, 0x7, 0x2, 0x2, 0x544, 0x546, 0x5, 
    0x6a, 0x36, 0x2, 0x545, 0x543, 0x3, 0x2, 0x2, 0x2, 0x546, 0x549, 0x3, 
    0x2, 0x2, 0x2, 0x547, 0x545, 0x3, 0x2, 0x2, 0x2, 0x547, 0x548, 0x3, 
    0x2, 0x2, 0x2, 0x548, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x549, 0x547, 0x3, 
    0x2, 0x2, 0x2, 0x54a, 0x54b, 0x7, 0x6, 0x2, 0x2, 0x54b, 0x54c, 0x5, 
    0x60, 0x31, 0x2, 0x54c, 0x561, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54e, 0x7, 
    0x2e, 0x2, 0x2, 0x54e, 0x54f, 0x7, 0x5, 0x2, 0x2, 0x54f, 0x550, 0x5, 
    0x64, 0x33, 0x2, 0x550, 0x551, 0x7, 0x6, 0x2, 0x2, 0x551, 0x561, 0x3, 
    0x2, 0x2, 0x2, 0x552, 0x553, 0x7, 0x4e, 0x2, 0x2, 0x553, 0x554, 0x7, 
    0x63, 0x2, 0x2, 0x554, 0x555, 0x7, 0x5, 0x2, 0x2, 0x555, 0x55a, 0x5, 
    0xa8, 0x55, 0x2, 0x556, 0x557, 0x7, 0x7, 0x2, 0x2, 0x557, 0x559, 0x5, 
    0xa8, 0x55, 0x2, 0x558, 0x556, 0x3, 0x2, 0x2, 0x2, 0x559, 0x55c, 0x3, 
    0x2, 0x2, 0x2, 0x55a, 0x558, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x55b, 0x3, 
    0x2, 0x2, 0x2, 0x55b, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55a, 0x3, 
    0x2, 0x2, 0x2, 0x55d, 0x55e, 0x7, 0x6, 0x2, 0x2, 0x55e, 0x55f, 0x5, 
    0x66, 0x34, 0x2, 0x55f, 0x561, 0x3, 0x2, 0x2, 0x2, 0x560, 0x53f, 0x3, 
    0x2, 0x2, 0x2, 0x560, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x560, 0x552, 0x3, 
    0x2, 0x2, 0x2, 0x561, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x562, 0x564, 0x7, 0x9a, 
    0x2, 0x2, 0x563, 0x565, 0x7, 0x78, 0x2, 0x2, 0x564, 0x563, 0x3, 0x2, 
    0x2, 0x2, 0x564, 0x565, 0x3, 0x2, 0x2, 0x2, 0x565, 0x566, 0x3, 0x2, 
    0x2, 0x2, 0x566, 0x56b, 0x5, 0x76, 0x3c, 0x2, 0x567, 0x568, 0x7, 0x7, 
    0x2, 0x2, 0x568, 0x56a, 0x5, 0x76, 0x3c, 0x2, 0x569, 0x567, 0x3, 0x2, 
    0x2, 0x2, 0x56a, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x569, 0x3, 0x2, 
    0x2, 0x2, 0x56b, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x56d, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x56f, 0x5, 0x9c, 0x4f, 
    0x2, 0x56f, 0x570, 0x7, 0x4, 0x2, 0x2, 0x570, 0x572, 0x3, 0x2, 0x2, 
    0x2, 0x571, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x571, 0x572, 0x3, 0x2, 0x2, 
    0x2, 0x572, 0x573, 0x3, 0x2, 0x2, 0x2, 0x573, 0x579, 0x5, 0xa2, 0x52, 
    0x2, 0x574, 0x575, 0x7, 0x59, 0x2, 0x2, 0x575, 0x576, 0x7, 0x2a, 0x2, 
    0x2, 0x576, 0x57a, 0x5, 0xae, 0x58, 0x2, 0x577, 0x578, 0x7, 0x6a, 0x2, 
    0x2, 0x578, 0x57a, 0x7, 0x59, 0x2, 0x2, 0x579, 0x574, 0x3, 0x2, 0x2, 
    0x2, 0x579, 0x577, 0x3, 0x2, 0x2, 0x2, 0x579, 0x57a, 0x3, 0x2, 0x2, 
    0x2, 0x57a, 0x71, 0x3, 0x2, 0x2, 0x2, 0x57b, 0x57e, 0x5, 0x64, 0x33, 
    0x2, 0x57c, 0x57d, 0x7, 0x2f, 0x2, 0x2, 0x57d, 0x57f, 0x5, 0xaa, 0x56, 
    0x2, 0x57e, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57f, 0x3, 0x2, 0x2, 
    0x2, 0x57f, 0x581, 0x3, 0x2, 0x2, 0x2, 0x580, 0x582, 0x9, 0x7, 0x2, 
    0x2, 0x581, 0x580, 0x3, 0x2, 0x2, 0x2, 0x581, 0x582, 0x3, 0x2, 0x2, 
    0x2, 0x582, 0x73, 0x3, 0x2, 0x2, 0x2, 0x583, 0x587, 0x5, 0x8a, 0x46, 
    0x2, 0x584, 0x587, 0x5, 0x98, 0x4d, 0x2, 0x585, 0x587, 0x7, 0x9f, 0x2, 
    0x2, 0x586, 0x583, 0x3, 0x2, 0x2, 0x2, 0x586, 0x584, 0x3, 0x2, 0x2, 
    0x2, 0x586, 0x585, 0x3, 0x2, 0x2, 0x2, 0x587, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x588, 0x594, 0x5, 0xa2, 0x52, 0x2, 0x589, 0x58a, 0x7, 0x5, 0x2, 0x2, 
    0x58a, 0x58f, 0x5, 0xa8, 0x55, 0x2, 0x58b, 0x58c, 0x7, 0x7, 0x2, 0x2, 
    0x58c, 0x58e, 0x5, 0xa8, 0x55, 0x2, 0x58d, 0x58b, 0x3, 0x2, 0x2, 0x2, 
    0x58e, 0x591, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x58d, 0x3, 0x2, 0x2, 0x2, 
    0x58f, 0x590, 0x3, 0x2, 0x2, 0x2, 0x590, 0x592, 0x3, 0x2, 0x2, 0x2, 
    0x591, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x592, 0x593, 0x7, 0x6, 0x2, 0x2, 
    0x593, 0x595, 0x3, 0x2, 0x2, 0x2, 0x594, 0x589, 0x3, 0x2, 0x2, 0x2, 
    0x594, 0x595, 0x3, 0x2, 0x2, 0x2, 0x595, 0x596, 0x3, 0x2, 0x2, 0x2, 
    0x596, 0x597, 0x7, 0x23, 0x2, 0x2, 0x597, 0x598, 0x7, 0x5, 0x2, 0x2, 
    0x598, 0x599, 0x5, 0x4a, 0x26, 0x2, 0x599, 0x59a, 0x7, 0x6, 0x2, 0x2, 
    0x59a, 0x77, 0x3, 0x2, 0x2, 0x2, 0x59b, 0x5ac, 0x7, 0x9, 0x2, 0x2, 0x59c, 
    0x59d, 0x5, 0xa2, 0x52, 0x2, 0x59d, 0x59e, 0x7, 0x4, 0x2, 0x2, 0x59e, 
    0x59f, 0x7, 0x9, 0x2, 0x2, 0x59f, 0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5a0, 
    0x5a1, 0x5, 0xa2, 0x52, 0x2, 0x5a1, 0x5a2, 0x7, 0x4, 0x2, 0x2, 0x5a2, 
    0x5a3, 0x5, 0xa8, 0x55, 0x2, 0x5a3, 0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5a4, 
    0x5a9, 0x5, 0x64, 0x33, 0x2, 0x5a5, 0x5a7, 0x7, 0x23, 0x2, 0x2, 0x5a6, 
    0x5a5, 0x3, 0x2, 0x2, 0x2, 0x5a6, 0x5a7, 0x3, 0x2, 0x2, 0x2, 0x5a7, 
    0x5a8, 0x3, 0x2, 0x2, 0x2, 0x5a8, 0x5aa, 0x5, 0x94, 0x4b, 0x2, 0x5a9, 
    0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 0x3, 0x2, 0x2, 0x2, 0x5aa, 
    0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5ab, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x5ab, 
    0x59c, 0x3, 0x2, 0x2, 0x2, 0x5ab, 0x5a0, 0x3, 0x2, 0x2, 0x2, 0x5ab, 
    0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5ac, 0x79, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ae, 
    0x5, 0x9e, 0x50, 0x2, 0x5ae, 0x5af, 0x7, 0x4, 0x2, 0x2, 0x5af, 0x5b1, 
    0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5ad, 0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5b1, 
    0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5b7, 
    0x5, 0xa2, 0x52, 0x2, 0x5b3, 0x5b5, 0x7, 0x23, 0x2, 0x2, 0x5b4, 0x5b3, 
    0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b5, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0x5b6, 
    0x3, 0x2, 0x2, 0x2, 0x5b6, 0x5b8, 0x5, 0xba, 0x5e, 0x2, 0x5b7, 0x5b4, 
    0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5be, 
    0x3, 0x2, 0x2, 0x2, 0x5b9, 0x5ba, 0x7, 0x59, 0x2, 0x2, 0x5ba, 0x5bb, 
    0x7, 0x2a, 0x2, 0x2, 0x5bb, 0x5bf, 0x5, 0xae, 0x58, 0x2, 0x5bc, 0x5bd, 
    0x7, 0x6a, 0x2, 0x2, 0x5bd, 0x5bf, 0x7, 0x59, 0x2, 0x2, 0x5be, 0x5b9, 
    0x3, 0x2, 0x2, 0x2, 0x5be, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x5bf, 
    0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5c0, 0x5c1, 
    0x5, 0x9e, 0x50, 0x2, 0x5c1, 0x5c2, 0x7, 0x4, 0x2, 0x2, 0x5c2, 0x5c4, 
    0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c4, 
    0x3, 0x2, 0x2, 0x2, 0x5c4, 0x5c5, 0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c6, 
    0x5, 0xa0, 0x51, 0x2, 0x5c6, 0x5cf, 0x7, 0x5, 0x2, 0x2, 0x5c7, 0x5cc, 
    0x5, 0x64, 0x33, 0x2, 0x5c8, 0x5c9, 0x7, 0x7, 0x2, 0x2, 0x5c9, 0x5cb, 
    0x5, 0x64, 0x33, 0x2, 0x5ca, 0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5ce, 
    0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 
    0x3, 0x2, 0x2, 0x2, 0x5cd, 0x5d0, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cc, 
    0x3, 0x2, 0x2, 0x2, 0x5cf, 0x5c7, 0x3, 0x2, 0x2, 0x2, 0x5cf, 0x5d0, 
    0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5d1, 0x3, 0x2, 0x2, 0x2, 0x5d1, 0x5d6, 
    0x7, 0x6, 0x2, 0x2, 0x5d2, 0x5d4, 0x7, 0x23, 0x2, 0x2, 0x5d3, 0x5d2, 
    0x3, 0x2, 0x2, 0x2, 0x5d3, 0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5d4, 0x5d5, 
    0x3, 0x2, 0x2, 0x2, 0x5d5, 0x5d7, 0x5, 0xba, 0x5e, 0x2, 0x5d6, 0x5d3, 
    0x3, 0x2, 0x2, 0x2, 0x5d6, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5d7, 0x5f0, 
    0x3, 0x2, 0x2, 0x2, 0x5d8, 0x5e2, 0x7, 0x5, 0x2, 0x2, 0x5d9, 0x5de, 
    0x5, 0x7a, 0x3e, 0x2, 0x5da, 0x5db, 0x7, 0x7, 0x2, 0x2, 0x5db, 0x5dd, 
    0x5, 0x7a, 0x3e, 0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x5e0, 
    0x3, 0x2, 0x2, 0x2, 0x5de, 0x5dc, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5df, 
    0x3, 0x2, 0x2, 0x2, 0x5df, 0x5e3, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5de, 
    0x3, 0x2, 0x2, 0x2, 0x5e1, 0x5e3, 0x5, 0x7c, 0x3f, 0x2, 0x5e2, 0x5d9, 
    0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5e3, 0x5e4, 
    0x3, 0x2, 0x2, 0x2, 0x5e4, 0x5e5, 0x7, 0x6, 0x2, 0x2, 0x5e5, 0x5f0, 
    0x3, 0x2, 0x2, 0x2, 0x5e6, 0x5e7, 0x7, 0x5, 0x2, 0x2, 0x5e7, 0x5e8, 
    0x5, 0x4a, 0x26, 0x2, 0x5e8, 0x5ed, 0x7, 0x6, 0x2, 0x2, 0x5e9, 0x5eb, 
    0x7, 0x23, 0x2, 0x2, 0x5ea, 0x5e9, 0x3, 0x2, 0x2, 0x2, 0x5ea, 0x5eb, 
    0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5ec, 0x5ee, 
    0x5, 0xba, 0x5e, 0x2, 0x5ed, 0x5ea, 0x3, 0x2, 0x2, 0x2, 0x5ed, 0x5ee, 
    0x3, 0x2, 0x2, 0x2, 0x5ee, 0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5b0, 
    0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5d8, 
    0x3, 0x2, 0x2, 0x2, 0x5ef, 0x5e6, 0x3, 0x2, 0x2, 0x2, 0x5f0, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x5f1, 0x5f8, 0x5, 0x7a, 0x3e, 0x2, 0x5f2, 0x5f3, 0x5, 
    0x7e, 0x40, 0x2, 0x5f3, 0x5f4, 0x5, 0x7a, 0x3e, 0x2, 0x5f4, 0x5f5, 0x5, 
    0x80, 0x41, 0x2, 0x5f5, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5f6, 0x5f2, 0x3, 
    0x2, 0x2, 0x2, 0x5f7, 0x5fa, 0x3, 0x2, 0x2, 0x2, 0x5f8, 0x5f6, 0x3, 
    0x2, 0x2, 0x2, 0x5f8, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5f9, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x5fa, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5fb, 0x609, 0x7, 0x7, 
    0x2, 0x2, 0x5fc, 0x5fe, 0x7, 0x68, 0x2, 0x2, 0x5fd, 0x5fc, 0x3, 0x2, 
    0x2, 0x2, 0x5fd, 0x5fe, 0x3, 0x2, 0x2, 0x2, 0x5fe, 0x605, 0x3, 0x2, 
    0x2, 0x2, 0x5ff, 0x601, 0x7, 0x64, 0x2, 0x2, 0x600, 0x602, 0x7, 0x72, 
    0x2, 0x2, 0x601, 0x600, 0x3, 0x2, 0x2, 0x2, 0x601, 0x602, 0x3, 0x2, 
    0x2, 0x2, 0x602, 0x606, 0x3, 0x2, 0x2, 0x2, 0x603, 0x606, 0x7, 0x5b, 
    0x2, 0x2, 0x604, 0x606, 0x7, 0x35, 0x2, 0x2, 0x605, 0x5ff, 0x3, 0x2, 
    0x2, 0x2, 0x605, 0x603, 0x3, 0x2, 0x2, 0x2, 0x605, 0x604, 0x3, 0x2, 
    0x2, 0x2, 0x605, 0x606, 0x3, 0x2, 0x2, 0x2, 0x606, 0x607, 0x3, 0x2, 
    0x2, 0x2, 0x607, 0x609, 0x7, 0x62, 0x2, 0x2, 0x608, 0x5fb, 0x3, 0x2, 
    0x2, 0x2, 0x608, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x609, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x60a, 0x60b, 0x7, 0x6f, 0x2, 0x2, 0x60b, 0x619, 0x5, 0x64, 0x33, 
    0x2, 0x60c, 0x60d, 0x7, 0x93, 0x2, 0x2, 0x60d, 0x60e, 0x7, 0x5, 0x2, 
    0x2, 0x60e, 0x613, 0x5, 0xa8, 0x55, 0x2, 0x60f, 0x610, 0x7, 0x7, 0x2, 
    0x2, 0x610, 0x612, 0x5, 0xa8, 0x55, 0x2, 0x611, 0x60f, 0x3, 0x2, 0x2, 
    0x2, 0x612, 0x615, 0x3, 0x2, 0x2, 0x2, 0x613, 0x611, 0x3, 0x2, 0x2, 
    0x2, 0x613, 0x614, 0x3, 0x2, 0x2, 0x2, 0x614, 0x616, 0x3, 0x2, 0x2, 
    0x2, 0x615, 0x613, 0x3, 0x2, 0x2, 0x2, 0x616, 0x617, 0x7, 0x6, 0x2, 
    0x2, 0x617, 0x619, 0x3, 0x2, 0x2, 0x2, 0x618, 0x60a, 0x3, 0x2, 0x2, 
    0x2, 0x618, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x618, 0x619, 0x3, 0x2, 0x2, 
    0x2, 0x619, 0x81, 0x3, 0x2, 0x2, 0x2, 0x61a, 0x61f, 0x5, 0x78, 0x3d, 
    0x2, 0x61b, 0x61c, 0x7, 0x7, 0x2, 0x2, 0x61c, 0x61e, 0x5, 0x78, 0x3d, 
    0x2, 0x61d, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x61e, 0x621, 0x3, 0x2, 0x2, 
    0x2, 0x61f, 0x61d, 0x3, 0x2, 0x2, 0x2, 0x61f, 0x620, 0x3, 0x2, 0x2, 
    0x2, 0x620, 0x83, 0x3, 0x2, 0x2, 0x2, 0x621, 0x61f, 0x3, 0x2, 0x2, 0x2, 
    0x622, 0x624, 0x7, 0x84, 0x2, 0x2, 0x623, 0x625, 0x9, 0x6, 0x2, 0x2, 
    0x624, 0x623, 0x3, 0x2, 0x2, 0x2, 0x624, 0x625, 0x3, 0x2, 0x2, 0x2, 
    0x625, 0x626, 0x3, 0x2, 0x2, 0x2, 0x626, 0x633, 0x5, 0x82, 0x42, 0x2, 
    0x627, 0x631, 0x7, 0x4f, 0x2, 0x2, 0x628, 0x62d, 0x5, 0x7a, 0x3e, 0x2, 
    0x629, 0x62a, 0x7, 0x7, 0x2, 0x2, 0x62a, 0x62c, 0x5, 0x7a, 0x3e, 0x2, 
    0x62b, 0x629, 0x3, 0x2, 0x2, 0x2, 0x62c, 0x62f, 0x3, 0x2, 0x2, 0x2, 
    0x62d, 0x62b, 0x3, 0x2, 0x2, 0x2, 0x62d, 0x62e, 0x3, 0x2, 0x2, 0x2, 
    0x62e, 0x632, 0x3, 0x2, 0x2, 0x2, 0x62f, 0x62d, 0x3, 0x2, 0x2, 0x2, 
    0x630, 0x632, 0x5, 0x7c, 0x3f, 0x2, 0x631, 0x628, 0x3, 0x2, 0x2, 0x2, 
    0x631, 0x630, 0x3, 0x2, 0x2, 0x2, 0x632, 0x634, 0x3, 0x2, 0x2, 0x2, 
    0x633, 0x627, 0x3, 0x2, 0x2, 0x2, 0x633, 0x634, 0x3, 0x2, 0x2, 0x2, 
    0x634, 0x637, 0x3, 0x2, 0x2, 0x2, 0x635, 0x636, 0x7, 0x99, 0x2, 0x2, 
    0x636, 0x638, 0x5, 0x86, 0x44, 0x2, 0x637, 0x635, 0x3, 0x2, 0x2, 0x2, 
    0x637, 0x638, 0x3, 0x2, 0x2, 0x2, 0x638, 0x647, 0x3, 0x2, 0x2, 0x2, 
    0x639, 0x63a, 0x7, 0x52, 0x2, 0x2, 0x63a, 0x63b, 0x7, 0x2a, 0x2, 0x2, 
    0x63b, 0x640, 0x5, 0x64, 0x33, 0x2, 0x63c, 0x63d, 0x7, 0x7, 0x2, 0x2, 
    0x63d, 0x63f, 0x5, 0x64, 0x33, 0x2, 0x63e, 0x63c, 0x3, 0x2, 0x2, 0x2, 
    0x63f, 0x642, 0x3, 0x2, 0x2, 0x2, 0x640, 0x63e, 0x3, 0x2, 0x2, 0x2, 
    0x640, 0x641, 0x3, 0x2, 0x2, 0x2, 0x641, 0x645, 0x3, 0x2, 0x2, 0x2, 
    0x642, 0x640, 0x3, 0x2, 0x2, 0x2, 0x643, 0x644, 0x7, 0x53, 0x2, 0x2, 
    0x644, 0x646, 0x5, 0x64, 0x33, 0x2, 0x645, 0x643, 0x3, 0x2, 0x2, 0x2, 
    0x645, 0x646, 0x3, 0x2, 0x2, 0x2, 0x646, 0x648, 0x3, 0x2, 0x2, 0x2, 
    0x647, 0x639, 0x3, 0x2, 0x2, 0x2, 0x647, 0x648, 0x3, 0x2, 0x2, 0x2, 
    0x648, 0x666, 0x3, 0x2, 0x2, 0x2, 0x649, 0x64a, 0x7, 0x95, 0x2, 0x2, 
    0x64a, 0x64b, 0x7, 0x5, 0x2, 0x2, 0x64b, 0x650, 0x5, 0x64, 0x33, 0x2, 
    0x64c, 0x64d, 0x7, 0x7, 0x2, 0x2, 0x64d, 0x64f, 0x5, 0x64, 0x33, 0x2, 
    0x64e, 0x64c, 0x3, 0x2, 0x2, 0x2, 0x64f, 0x652, 0x3, 0x2, 0x2, 0x2, 
    0x650, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x650, 0x651, 0x3, 0x2, 0x2, 0x2, 
    0x651, 0x653, 0x3, 0x2, 0x2, 0x2, 0x652, 0x650, 0x3, 0x2, 0x2, 0x2, 
    0x653, 0x662, 0x7, 0x6, 0x2, 0x2, 0x654, 0x655, 0x7, 0x7, 0x2, 0x2, 
    0x655, 0x656, 0x7, 0x5, 0x2, 0x2, 0x656, 0x65b, 0x5, 0x64, 0x33, 0x2, 
    0x657, 0x658, 0x7, 0x7, 0x2, 0x2, 0x658, 0x65a, 0x5, 0x64, 0x33, 0x2, 
    0x659, 0x657, 0x3, 0x2, 0x2, 0x2, 0x65a, 0x65d, 0x3, 0x2, 0x2, 0x2, 
    0x65b, 0x659, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x65c, 0x3, 0x2, 0x2, 0x2, 
    0x65c, 0x65e, 0x3, 0x2, 0x2, 0x2, 0x65d, 0x65b, 0x3, 0x2, 0x2, 0x2, 
    0x65e, 0x65f, 0x7, 0x6, 0x2, 0x2, 0x65f, 0x661, 0x3, 0x2, 0x2, 0x2, 
    0x660, 0x654, 0x3, 0x2, 0x2, 0x2, 0x661, 0x664, 0x3, 0x2, 0x2, 0x2, 
    0x662, 0x660, 0x3, 0x2, 0x2, 0x2, 0x662, 0x663, 0x3, 0x2, 0x2, 0x2, 
    0x663, 0x666, 0x3, 0x2, 0x2, 0x2, 0x664, 0x662, 0x3, 0x2, 0x2, 0x2, 
    0x665, 0x622, 0x3, 0x2, 0x2, 0x2, 0x665, 0x649, 0x3, 0x2, 0x2, 0x2, 
    0x666, 0x85, 0x3, 0x2, 0x2, 0x2, 0x667, 0x668, 0x5, 0x64, 0x33, 0x2, 
    0x668, 0x87, 0x3, 0x2, 0x2, 0x2, 0x669, 0x66f, 0x7, 0x90, 0x2, 0x2, 
    0x66a, 0x66b, 0x7, 0x90, 0x2, 0x2, 0x66b, 0x66f, 0x7, 0x1f, 0x2, 0x2, 
    0x66c, 0x66f, 0x7, 0x5e, 0x2, 0x2, 0x66d, 0x66f, 0x7, 0x47, 0x2, 0x2, 
    0x66e, 0x669, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66a, 0x3, 0x2, 0x2, 0x2, 
    0x66e, 0x66c, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66d, 0x3, 0x2, 0x2, 0x2, 
    0x66f, 0x89, 0x3, 0x2, 0x2, 0x2, 0x670, 0x672, 0x9, 0xa, 0x2, 0x2, 0x671, 
    0x670, 0x3, 0x2, 0x2, 0x2, 0x671, 0x672, 0x3, 0x2, 0x2, 0x2, 0x672, 
    0x673, 0x3, 0x2, 0x2, 0x2, 0x673, 0x674, 0x7, 0x9d, 0x2, 0x2, 0x674, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x675, 0x676, 0x9, 0x11, 0x2, 0x2, 0x676, 
    0x8d, 0x3, 0x2, 0x2, 0x2, 0x677, 0x678, 0x9, 0x12, 0x2, 0x2, 0x678, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x679, 0x67a, 0x7, 0x9f, 0x2, 0x2, 0x67a, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67e, 0x5, 0x64, 0x33, 0x2, 0x67c, 
    0x67e, 0x5, 0x54, 0x2b, 0x2, 0x67d, 0x67b, 0x3, 0x2, 0x2, 0x2, 0x67d, 
    0x67c, 0x3, 0x2, 0x2, 0x2, 0x67e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x67f, 0x680, 
    0x9, 0x13, 0x2, 0x2, 0x680, 0x95, 0x3, 0x2, 0x2, 0x2, 0x681, 0x682, 
    0x9, 0x14, 0x2, 0x2, 0x682, 0x97, 0x3, 0x2, 0x2, 0x2, 0x683, 0x684, 
    0x5, 0xbe, 0x60, 0x2, 0x684, 0x99, 0x3, 0x2, 0x2, 0x2, 0x685, 0x686, 
    0x5, 0xbe, 0x60, 0x2, 0x686, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x687, 0x688, 
    0x5, 0xbe, 0x60, 0x2, 0x688, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x689, 0x68a, 
    0x5, 0xbe, 0x60, 0x2, 0x68a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x68c, 
    0x5, 0xbe, 0x60, 0x2, 0x68c, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x68d, 0x68e, 
    0x5, 0xbe, 0x60, 0x2, 0x68e, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x690, 
    0x5, 0xbe, 0x60, 0x2, 0x690, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x691, 0x692, 
    0x5, 0xbe, 0x60, 0x2, 0x692, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x693, 0x694, 
    0x5, 0xbe, 0x60, 0x2, 0x694, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x695, 0x696, 
    0x5, 0xbe, 0x60, 0x2, 0x696, 0xab, 0x3, 0x2, 0x2, 0x2, 0x697, 0x698, 
    0x5, 0xbe, 0x60, 0x2, 0x698, 0xad, 0x3, 0x2, 0x2, 0x2, 0x699, 0x69a, 
    0x5, 0xbe, 0x60, 0x2, 0x69a, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69c, 
    0x5, 0xbe, 0x60, 0x2, 0x69c, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x69d, 0x69e, 
    0x5, 0xbe, 0x60, 0x2, 0x69e, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x69f, 0x6a0, 
    0x5, 0xbe, 0x60, 0x2, 0x6a0, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x6a1, 0x6a2, 
    0x5, 0xbe, 0x60, 0x2, 0x6a2, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x6a3, 0x6a4, 
    0x5, 0xbe, 0x60, 0x2, 0x6a4, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x6a5, 0x6ac, 
    0x7, 0x9c, 0x2, 0x2, 0x6a6, 0x6ac, 0x7, 0x9f, 0x2, 0x2, 0x6a7, 0x6a8, 
    0x7, 0x5, 0x2, 0x2, 0x6a8, 0x6a9, 0x5, 0xba, 0x5e, 0x2, 0x6a9, 0x6aa, 
    0x7, 0x6, 0x2, 0x2, 0x6aa, 0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a5, 
    0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a7, 
    0x3, 0x2, 0x2, 0x2, 0x6ac, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x6ad, 0x6ae, 0x5, 
    0xbe, 0x60, 0x2, 0x6ae, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x6af, 0x6b7, 0x7, 
    0x9c, 0x2, 0x2, 0x6b0, 0x6b7, 0x5, 0x96, 0x4c, 0x2, 0x6b1, 0x6b7, 0x7, 
    0x9f, 0x2, 0x2, 0x6b2, 0x6b3, 0x7, 0x5, 0x2, 0x2, 0x6b3, 0x6b4, 0x5, 
    0xbe, 0x60, 0x2, 0x6b4, 0x6b5, 0x7, 0x6, 0x2, 0x2, 0x6b5, 0x6b7, 0x3, 
    0x2, 0x2, 0x2, 0x6b6, 0x6af, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6b0, 0x3, 
    0x2, 0x2, 0x2, 0x6b6, 0x6b1, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6b2, 0x3, 
    0x2, 0x2, 0x2, 0x6b7, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xec, 0xc2, 0xc4, 0xcf, 
    0xd6, 0xdb, 0xe1, 0xe7, 0xe9, 0x10b, 0x112, 0x11a, 0x11d, 0x12d, 0x131, 
    0x139, 0x13d, 0x13f, 0x144, 0x146, 0x149, 0x14e, 0x152, 0x157, 0x160, 
    0x163, 0x169, 0x16b, 0x16f, 0x175, 0x17a, 0x185, 0x18b, 0x18f, 0x195, 
    0x19a, 0x1a3, 0x1aa, 0x1b0, 0x1b4, 0x1b8, 0x1be, 0x1c3, 0x1ca, 0x1d5, 
    0x1d8, 0x1da, 0x1e0, 0x1e6, 0x1ea, 0x1f1, 0x1f7, 0x1fd, 0x203, 0x208, 
    0x214, 0x219, 0x224, 0x229, 0x22c, 0x233, 0x236, 0x23d, 0x246, 0x249, 
    0x24f, 0x251, 0x255, 0x25d, 0x262, 0x26a, 0x26f, 0x277, 0x27c, 0x284, 
    0x289, 0x28e, 0x296, 0x2a0, 0x2a3, 0x2a9, 0x2ab, 0x2be, 0x2c6, 0x2d0, 
    0x2d9, 0x2df, 0x2e6, 0x2ea, 0x2f1, 0x2f7, 0x300, 0x307, 0x30b, 0x30d, 
    0x311, 0x318, 0x31a, 0x31e, 0x321, 0x327, 0x331, 0x334, 0x33a, 0x33c, 
    0x33f, 0x347, 0x351, 0x354, 0x35a, 0x35c, 0x360, 0x367, 0x370, 0x374, 
    0x376, 0x37a, 0x383, 0x388, 0x38a, 0x393, 0x39e, 0x3a5, 0x3a8, 0x3ab, 
    0x3b8, 0x3c6, 0x3cb, 0x3ce, 0x3db, 0x3e9, 0x3ee, 0x3f7, 0x3fa, 0x400, 
    0x402, 0x408, 0x40d, 0x413, 0x41f, 0x423, 0x427, 0x42b, 0x43e, 0x443, 
    0x450, 0x453, 0x45a, 0x45e, 0x466, 0x47d, 0x480, 0x488, 0x491, 0x495, 
    0x49a, 0x4b7, 0x4bc, 0x4c5, 0x4cf, 0x4d2, 0x4d8, 0x4db, 0x4e2, 0x4e8, 
    0x4ef, 0x4f1, 0x4f3, 0x4fe, 0x503, 0x50f, 0x513, 0x517, 0x51b, 0x522, 
    0x524, 0x52c, 0x533, 0x536, 0x53a, 0x53f, 0x547, 0x55a, 0x560, 0x564, 
    0x56b, 0x571, 0x579, 0x57e, 0x581, 0x586, 0x58f, 0x594, 0x5a6, 0x5a9, 
    0x5ab, 0x5b0, 0x5b4, 0x5b7, 0x5be, 0x5c3, 0x5cc, 0x5cf, 0x5d3, 0x5d6, 
    0x5de, 0x5e2, 0x5ea, 0x5ed, 0x5ef, 0x5f8, 0x5fd, 0x601, 0x605, 0x608, 
    0x613, 0x618, 0x61f, 0x624, 0x62d, 0x631, 0x633, 0x637, 0x640, 0x645, 
    0x647, 0x650, 0x65b, 0x662, 0x665, 0x66e, 0x671, 0x67d, 0x6ab, 0x6b6, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

PotatoSQLParser::Initializer PotatoSQLParser::_init;
