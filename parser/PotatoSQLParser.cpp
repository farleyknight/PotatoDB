
// Generated from parser/PotatoSQL.g4 by ANTLR 4.9.2



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
    setState(170);
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
      setState(168);
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
          setState(166);
          sql_stmt_list();
          break;
        }

        case PotatoSQLParser::UNEXPECTED_CHAR: {
          setState(167);
          error();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(173);
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
    setState(175);
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
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::SCOL) {
      setState(178);
      match(PotatoSQLParser::SCOL);
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(184);
    sql_stmt();
    setState(193);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(186); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(185);
          match(PotatoSQLParser::SCOL);
          setState(188); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == PotatoSQLParser::SCOL);
        setState(190);
        sql_stmt(); 
      }
      setState(195);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(196);
        match(PotatoSQLParser::SCOL); 
      }
      setState(201);
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
    setState(207);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_EXPLAIN) {
      setState(202);
      match(PotatoSQLParser::K_EXPLAIN);
      setState(205);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_QUERY) {
        setState(203);
        match(PotatoSQLParser::K_QUERY);
        setState(204);
        match(PotatoSQLParser::K_PLAN);
      }
    }
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(209);
      alter_table_stmt();
      break;
    }

    case 2: {
      setState(210);
      analyze_stmt();
      break;
    }

    case 3: {
      setState(211);
      attach_stmt();
      break;
    }

    case 4: {
      setState(212);
      begin_stmt();
      break;
    }

    case 5: {
      setState(213);
      commit_stmt();
      break;
    }

    case 6: {
      setState(214);
      compound_select_stmt();
      break;
    }

    case 7: {
      setState(215);
      create_index_stmt();
      break;
    }

    case 8: {
      setState(216);
      create_table_stmt();
      break;
    }

    case 9: {
      setState(217);
      create_trigger_stmt();
      break;
    }

    case 10: {
      setState(218);
      create_view_stmt();
      break;
    }

    case 11: {
      setState(219);
      create_virtual_table_stmt();
      break;
    }

    case 12: {
      setState(220);
      delete_stmt();
      break;
    }

    case 13: {
      setState(221);
      delete_stmt_limited();
      break;
    }

    case 14: {
      setState(222);
      detach_stmt();
      break;
    }

    case 15: {
      setState(223);
      drop_index_stmt();
      break;
    }

    case 16: {
      setState(224);
      drop_table_stmt();
      break;
    }

    case 17: {
      setState(225);
      drop_trigger_stmt();
      break;
    }

    case 18: {
      setState(226);
      drop_view_stmt();
      break;
    }

    case 19: {
      setState(227);
      factored_select_stmt();
      break;
    }

    case 20: {
      setState(228);
      insert_stmt();
      break;
    }

    case 21: {
      setState(229);
      pragma_stmt();
      break;
    }

    case 22: {
      setState(230);
      reindex_stmt();
      break;
    }

    case 23: {
      setState(231);
      release_stmt();
      break;
    }

    case 24: {
      setState(232);
      rollback_stmt();
      break;
    }

    case 25: {
      setState(233);
      savepoint_stmt();
      break;
    }

    case 26: {
      setState(234);
      simple_select_stmt();
      break;
    }

    case 27: {
      setState(235);
      select_stmt();
      break;
    }

    case 28: {
      setState(236);
      update_stmt();
      break;
    }

    case 29: {
      setState(237);
      update_stmt_limited();
      break;
    }

    case 30: {
      setState(238);
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
    setState(241);
    match(PotatoSQLParser::K_ALTER);
    setState(242);
    match(PotatoSQLParser::K_TABLE);
    setState(246);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(243);
      database_name();
      setState(244);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(248);
    table_name();
    setState(257);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_RENAME: {
        setState(249);
        match(PotatoSQLParser::K_RENAME);
        setState(250);
        match(PotatoSQLParser::K_TO);
        setState(251);
        new_table_name();
        break;
      }

      case PotatoSQLParser::K_ADD: {
        setState(252);
        match(PotatoSQLParser::K_ADD);
        setState(254);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(253);
          match(PotatoSQLParser::K_COLUMN);
          break;
        }

        default:
          break;
        }
        setState(256);
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
    setState(259);
    match(PotatoSQLParser::K_ANALYZE);
    setState(266);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(260);
      database_name();
      break;
    }

    case 2: {
      setState(261);
      table_or_index_name();
      break;
    }

    case 3: {
      setState(262);
      database_name();
      setState(263);
      match(PotatoSQLParser::DOT);
      setState(264);
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
    setState(268);
    match(PotatoSQLParser::K_ATTACH);
    setState(270);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(269);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(272);
    expr(0);
    setState(273);
    match(PotatoSQLParser::K_AS);
    setState(274);
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
    setState(276);
    match(PotatoSQLParser::K_BEGIN);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 58) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 58)) & ((1ULL << (PotatoSQLParser::K_DEFERRED - 58))
      | (1ULL << (PotatoSQLParser::K_EXCLUSIVE - 58))
      | (1ULL << (PotatoSQLParser::K_IMMEDIATE - 58)))) != 0)) {
      setState(277);
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
    setState(284);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(280);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(282);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(281);
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
    setState(286);
    _la = _input->LA(1);
    if (!(_la == PotatoSQLParser::K_COMMIT

    || _la == PotatoSQLParser::K_END)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(287);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(289);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(288);
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
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(293);
      with_clause();
    }
    setState(296);
    select_core();
    setState(306); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(303);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_UNION: {
          setState(297);
          match(PotatoSQLParser::K_UNION);
          setState(299);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_ALL) {
            setState(298);
            match(PotatoSQLParser::K_ALL);
          }
          break;
        }

        case PotatoSQLParser::K_INTERSECT: {
          setState(301);
          match(PotatoSQLParser::K_INTERSECT);
          break;
        }

        case PotatoSQLParser::K_EXCEPT: {
          setState(302);
          match(PotatoSQLParser::K_EXCEPT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(305);
      select_core();
      setState(308); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION);
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(310);
      match(PotatoSQLParser::K_ORDER);
      setState(311);
      match(PotatoSQLParser::K_BY);
      setState(312);
      ordering_term();
      setState(317);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(313);
        match(PotatoSQLParser::COMMA);
        setState(314);
        ordering_term();
        setState(319);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(322);
      match(PotatoSQLParser::K_LIMIT);
      setState(323);
      expr(0);
      setState(326);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(324);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(325);
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
    setState(330);
    match(PotatoSQLParser::K_CREATE);
    setState(332);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_UNIQUE) {
      setState(331);
      match(PotatoSQLParser::K_UNIQUE);
    }
    setState(334);
    match(PotatoSQLParser::K_INDEX);
    setState(338);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(335);
      match(PotatoSQLParser::K_IF);
      setState(336);
      match(PotatoSQLParser::K_NOT);
      setState(337);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(343);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(340);
      database_name();
      setState(341);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(345);
    index_name();
    setState(346);
    match(PotatoSQLParser::K_ON);
    setState(347);
    table_name();
    setState(348);
    match(PotatoSQLParser::OPEN_PAR);
    setState(349);
    indexed_column();
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(350);
      match(PotatoSQLParser::COMMA);
      setState(351);
      indexed_column();
      setState(356);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(357);
    match(PotatoSQLParser::CLOSE_PAR);
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(358);
      match(PotatoSQLParser::K_WHERE);
      setState(359);
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
    setState(362);
    match(PotatoSQLParser::K_CREATE);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(363);
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
    setState(366);
    match(PotatoSQLParser::K_TABLE);
    setState(370);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(367);
      match(PotatoSQLParser::K_IF);
      setState(368);
      match(PotatoSQLParser::K_NOT);
      setState(369);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(375);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(372);
      database_name();
      setState(373);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(377);
    table_name();
    setState(401);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::OPEN_PAR: {
        setState(378);
        match(PotatoSQLParser::OPEN_PAR);
        setState(379);
        column_def();
        setState(384);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1 + 1) {
            setState(380);
            match(PotatoSQLParser::COMMA);
            setState(381);
            column_def(); 
          }
          setState(386);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        }
        setState(391);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(387);
          match(PotatoSQLParser::COMMA);
          setState(388);
          table_constraint();
          setState(393);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(394);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(397);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WITHOUT) {
          setState(395);
          match(PotatoSQLParser::K_WITHOUT);
          setState(396);
          match(PotatoSQLParser::IDENTIFIER);
        }
        break;
      }

      case PotatoSQLParser::K_AS: {
        setState(399);
        match(PotatoSQLParser::K_AS);
        setState(400);
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
    setState(403);
    match(PotatoSQLParser::K_CREATE);
    setState(405);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(404);
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
    setState(407);
    match(PotatoSQLParser::K_TRIGGER);
    setState(411);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(408);
      match(PotatoSQLParser::K_IF);
      setState(409);
      match(PotatoSQLParser::K_NOT);
      setState(410);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(416);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(413);
      database_name();
      setState(414);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(418);
    trigger_name();
    setState(423);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_BEFORE: {
        setState(419);
        match(PotatoSQLParser::K_BEFORE);
        break;
      }

      case PotatoSQLParser::K_AFTER: {
        setState(420);
        match(PotatoSQLParser::K_AFTER);
        break;
      }

      case PotatoSQLParser::K_INSTEAD: {
        setState(421);
        match(PotatoSQLParser::K_INSTEAD);
        setState(422);
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
    setState(439);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_DELETE: {
        setState(425);
        match(PotatoSQLParser::K_DELETE);
        break;
      }

      case PotatoSQLParser::K_INSERT: {
        setState(426);
        match(PotatoSQLParser::K_INSERT);
        break;
      }

      case PotatoSQLParser::K_UPDATE: {
        setState(427);
        match(PotatoSQLParser::K_UPDATE);
        setState(437);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_OF) {
          setState(428);
          match(PotatoSQLParser::K_OF);
          setState(429);
          column_name();
          setState(434);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(430);
            match(PotatoSQLParser::COMMA);
            setState(431);
            column_name();
            setState(436);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(441);
    match(PotatoSQLParser::K_ON);
    setState(445);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(442);
      database_name();
      setState(443);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(447);
    table_name();
    setState(451);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_FOR) {
      setState(448);
      match(PotatoSQLParser::K_FOR);
      setState(449);
      match(PotatoSQLParser::K_EACH);
      setState(450);
      match(PotatoSQLParser::K_ROW);
    }
    setState(455);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHEN) {
      setState(453);
      match(PotatoSQLParser::K_WHEN);
      setState(454);
      expr(0);
    }
    setState(457);
    match(PotatoSQLParser::K_BEGIN);
    setState(466); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(462);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
      case 1: {
        setState(458);
        update_stmt();
        break;
      }

      case 2: {
        setState(459);
        insert_stmt();
        break;
      }

      case 3: {
        setState(460);
        delete_stmt();
        break;
      }

      case 4: {
        setState(461);
        select_stmt();
        break;
      }

      default:
        break;
      }
      setState(464);
      match(PotatoSQLParser::SCOL);
      setState(468); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == PotatoSQLParser::K_DELETE || ((((_la - 88) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 88)) & ((1ULL << (PotatoSQLParser::K_INSERT - 88))
      | (1ULL << (PotatoSQLParser::K_REPLACE - 88))
      | (1ULL << (PotatoSQLParser::K_SELECT - 88))
      | (1ULL << (PotatoSQLParser::K_UPDATE - 88))
      | (1ULL << (PotatoSQLParser::K_VALUES - 88))
      | (1ULL << (PotatoSQLParser::K_WITH - 88)))) != 0));
    setState(470);
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
    setState(472);
    match(PotatoSQLParser::K_CREATE);
    setState(474);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TEMP

    || _la == PotatoSQLParser::K_TEMPORARY) {
      setState(473);
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
    setState(476);
    match(PotatoSQLParser::K_VIEW);
    setState(480);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      setState(477);
      match(PotatoSQLParser::K_IF);
      setState(478);
      match(PotatoSQLParser::K_NOT);
      setState(479);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(485);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(482);
      database_name();
      setState(483);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(487);
    view_name();
    setState(488);
    match(PotatoSQLParser::K_AS);
    setState(489);
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
    setState(491);
    match(PotatoSQLParser::K_CREATE);
    setState(492);
    match(PotatoSQLParser::K_VIRTUAL);
    setState(493);
    match(PotatoSQLParser::K_TABLE);
    setState(497);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      setState(494);
      match(PotatoSQLParser::K_IF);
      setState(495);
      match(PotatoSQLParser::K_NOT);
      setState(496);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(502);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
    case 1: {
      setState(499);
      database_name();
      setState(500);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(504);
    table_name();
    setState(505);
    match(PotatoSQLParser::K_USING);
    setState(506);
    module_name();
    setState(518);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(507);
      match(PotatoSQLParser::OPEN_PAR);
      setState(508);
      module_argument();
      setState(513);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(509);
        match(PotatoSQLParser::COMMA);
        setState(510);
        module_argument();
        setState(515);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(516);
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
    setState(521);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(520);
      with_clause();
    }
    setState(523);
    match(PotatoSQLParser::K_DELETE);
    setState(524);
    match(PotatoSQLParser::K_FROM);
    setState(525);
    qualified_table_name();
    setState(528);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(526);
      match(PotatoSQLParser::K_WHERE);
      setState(527);
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
    setState(558);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(550);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(540);
        match(PotatoSQLParser::K_ORDER);
        setState(541);
        match(PotatoSQLParser::K_BY);
        setState(542);
        ordering_term();
        setState(547);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(543);
          match(PotatoSQLParser::COMMA);
          setState(544);
          ordering_term();
          setState(549);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(552);
      match(PotatoSQLParser::K_LIMIT);
      setState(553);
      expr(0);
      setState(556);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(554);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(555);
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
    setState(560);
    match(PotatoSQLParser::K_DETACH);
    setState(562);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      setState(561);
      match(PotatoSQLParser::K_DATABASE);
      break;
    }

    default:
      break;
    }
    setState(564);
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
    setState(566);
    match(PotatoSQLParser::K_DROP);
    setState(567);
    match(PotatoSQLParser::K_INDEX);
    setState(570);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      setState(568);
      match(PotatoSQLParser::K_IF);
      setState(569);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(575);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      setState(572);
      database_name();
      setState(573);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(577);
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
    setState(579);
    match(PotatoSQLParser::K_DROP);
    setState(580);
    match(PotatoSQLParser::K_TABLE);
    setState(583);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(581);
      match(PotatoSQLParser::K_IF);
      setState(582);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(588);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      setState(585);
      database_name();
      setState(586);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(590);
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
    setState(592);
    match(PotatoSQLParser::K_DROP);
    setState(593);
    match(PotatoSQLParser::K_TRIGGER);
    setState(596);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      setState(594);
      match(PotatoSQLParser::K_IF);
      setState(595);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(601);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(598);
      database_name();
      setState(599);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(603);
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
    setState(605);
    match(PotatoSQLParser::K_DROP);
    setState(606);
    match(PotatoSQLParser::K_VIEW);
    setState(609);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(607);
      match(PotatoSQLParser::K_IF);
      setState(608);
      match(PotatoSQLParser::K_EXISTS);
      break;
    }

    default:
      break;
    }
    setState(614);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      setState(611);
      database_name();
      setState(612);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(616);
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
    setState(619);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(618);
      with_clause();
    }
    setState(621);
    select_core();
    setState(627);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(622);
      compound_operator();
      setState(623);
      select_core();
      setState(629);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(640);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(630);
      match(PotatoSQLParser::K_ORDER);
      setState(631);
      match(PotatoSQLParser::K_BY);
      setState(632);
      ordering_term();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(633);
        match(PotatoSQLParser::COMMA);
        setState(634);
        ordering_term();
        setState(639);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(648);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(642);
      match(PotatoSQLParser::K_LIMIT);
      setState(643);
      expr(0);
      setState(646);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(644);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(645);
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
  enterRule(_localctx, 46, PotatoSQLParser::RuleInsert_stmt);
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
    setState(651);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(650);
      with_clause();
    }
    setState(670);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      setState(653);
      match(PotatoSQLParser::K_INSERT);
      break;
    }

    case 2: {
      setState(654);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 3: {
      setState(655);
      match(PotatoSQLParser::K_INSERT);
      setState(656);
      match(PotatoSQLParser::K_OR);
      setState(657);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(658);
      match(PotatoSQLParser::K_INSERT);
      setState(659);
      match(PotatoSQLParser::K_OR);
      setState(660);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 5: {
      setState(661);
      match(PotatoSQLParser::K_INSERT);
      setState(662);
      match(PotatoSQLParser::K_OR);
      setState(663);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 6: {
      setState(664);
      match(PotatoSQLParser::K_INSERT);
      setState(665);
      match(PotatoSQLParser::K_OR);
      setState(666);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 7: {
      setState(667);
      match(PotatoSQLParser::K_INSERT);
      setState(668);
      match(PotatoSQLParser::K_OR);
      setState(669);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(672);
    match(PotatoSQLParser::K_INTO);
    setState(676);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      setState(673);
      database_name();
      setState(674);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(678);
    table_name();
    setState(690);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(679);
      match(PotatoSQLParser::OPEN_PAR);
      setState(680);
      column_name();
      setState(685);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(681);
        match(PotatoSQLParser::COMMA);
        setState(682);
        column_name();
        setState(687);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(688);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(723);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
    case 1: {
      setState(692);
      match(PotatoSQLParser::K_VALUES);
      setState(693);
      match(PotatoSQLParser::OPEN_PAR);
      setState(694);
      expr(0);
      setState(699);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(695);
        match(PotatoSQLParser::COMMA);
        setState(696);
        expr(0);
        setState(701);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(702);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(717);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(703);
        match(PotatoSQLParser::COMMA);
        setState(704);
        match(PotatoSQLParser::OPEN_PAR);
        setState(705);
        expr(0);
        setState(710);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(706);
          match(PotatoSQLParser::COMMA);
          setState(707);
          expr(0);
          setState(712);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(713);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(719);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(720);
      select_stmt();
      break;
    }

    case 3: {
      setState(721);
      match(PotatoSQLParser::K_DEFAULT);
      setState(722);
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
  enterRule(_localctx, 48, PotatoSQLParser::RulePragma_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    match(PotatoSQLParser::K_PRAGMA);
    setState(729);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      setState(726);
      database_name();
      setState(727);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(731);
    pragma_name();
    setState(738);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::ASSIGN: {
        setState(732);
        match(PotatoSQLParser::ASSIGN);
        setState(733);
        pragma_value();
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        setState(734);
        match(PotatoSQLParser::OPEN_PAR);
        setState(735);
        pragma_value();
        setState(736);
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


PotatoSQLParser::Reindex_stmtContext* PotatoSQLParser::reindex_stmt() {
  Reindex_stmtContext *_localctx = _tracker.createInstance<Reindex_stmtContext>(_ctx, getState());
  enterRule(_localctx, 50, PotatoSQLParser::RuleReindex_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(740);
    match(PotatoSQLParser::K_REINDEX);
    setState(751);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(741);
      collation_name();
      break;
    }

    case 2: {
      setState(745);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx)) {
      case 1: {
        setState(742);
        database_name();
        setState(743);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(749);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
      case 1: {
        setState(747);
        table_name();
        break;
      }

      case 2: {
        setState(748);
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


PotatoSQLParser::Release_stmtContext* PotatoSQLParser::release_stmt() {
  Release_stmtContext *_localctx = _tracker.createInstance<Release_stmtContext>(_ctx, getState());
  enterRule(_localctx, 52, PotatoSQLParser::RuleRelease_stmt);

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
    match(PotatoSQLParser::K_RELEASE);
    setState(755);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
    case 1: {
      setState(754);
      match(PotatoSQLParser::K_SAVEPOINT);
      break;
    }

    default:
      break;
    }
    setState(757);
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


PotatoSQLParser::Rollback_stmtContext* PotatoSQLParser::rollback_stmt() {
  Rollback_stmtContext *_localctx = _tracker.createInstance<Rollback_stmtContext>(_ctx, getState());
  enterRule(_localctx, 54, PotatoSQLParser::RuleRollback_stmt);
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
    setState(759);
    match(PotatoSQLParser::K_ROLLBACK);
    setState(764);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TRANSACTION) {
      setState(760);
      match(PotatoSQLParser::K_TRANSACTION);
      setState(762);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
      case 1: {
        setState(761);
        transaction_name();
        break;
      }

      default:
        break;
      }
    }
    setState(771);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_TO) {
      setState(766);
      match(PotatoSQLParser::K_TO);
      setState(768);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
      case 1: {
        setState(767);
        match(PotatoSQLParser::K_SAVEPOINT);
        break;
      }

      default:
        break;
      }
      setState(770);
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


PotatoSQLParser::Savepoint_stmtContext* PotatoSQLParser::savepoint_stmt() {
  Savepoint_stmtContext *_localctx = _tracker.createInstance<Savepoint_stmtContext>(_ctx, getState());
  enterRule(_localctx, 56, PotatoSQLParser::RuleSavepoint_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(773);
    match(PotatoSQLParser::K_SAVEPOINT);
    setState(774);
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


PotatoSQLParser::Simple_select_stmtContext* PotatoSQLParser::simple_select_stmt() {
  Simple_select_stmtContext *_localctx = _tracker.createInstance<Simple_select_stmtContext>(_ctx, getState());
  enterRule(_localctx, 58, PotatoSQLParser::RuleSimple_select_stmt);
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
    setState(777);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(776);
      with_clause();
    }
    setState(779);
    select_core();
    setState(790);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(780);
      match(PotatoSQLParser::K_ORDER);
      setState(781);
      match(PotatoSQLParser::K_BY);
      setState(782);
      ordering_term();
      setState(787);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(783);
        match(PotatoSQLParser::COMMA);
        setState(784);
        ordering_term();
        setState(789);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(798);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(792);
      match(PotatoSQLParser::K_LIMIT);
      setState(793);
      expr(0);
      setState(796);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(794);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(795);
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
  enterRule(_localctx, 60, PotatoSQLParser::RuleSelect_stmt);
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
    setState(801);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(800);
      with_clause();
    }
    setState(803);
    select_or_values();
    setState(809);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_EXCEPT

    || _la == PotatoSQLParser::K_INTERSECT || _la == PotatoSQLParser::K_UNION) {
      setState(804);
      compound_operator();
      setState(805);
      select_or_values();
      setState(811);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(822);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ORDER) {
      setState(812);
      match(PotatoSQLParser::K_ORDER);
      setState(813);
      match(PotatoSQLParser::K_BY);
      setState(814);
      ordering_term();
      setState(819);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(815);
        match(PotatoSQLParser::COMMA);
        setState(816);
        ordering_term();
        setState(821);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(830);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT) {
      setState(824);
      match(PotatoSQLParser::K_LIMIT);
      setState(825);
      expr(0);
      setState(828);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(826);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(827);
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
  enterRule(_localctx, 62, PotatoSQLParser::RuleSelect_or_values);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(906);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(832);
        match(PotatoSQLParser::K_SELECT);
        setState(834);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx)) {
        case 1: {
          setState(833);
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
        setState(836);
        result_column();
        setState(841);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(837);
          match(PotatoSQLParser::COMMA);
          setState(838);
          result_column();
          setState(843);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(856);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(844);
          match(PotatoSQLParser::K_FROM);
          setState(854);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
          case 1: {
            setState(845);
            table_or_subquery();
            setState(850);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(846);
              match(PotatoSQLParser::COMMA);
              setState(847);
              table_or_subquery();
              setState(852);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(853);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(860);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(858);
          match(PotatoSQLParser::K_WHERE);
          setState(859);
          expr(0);
        }
        setState(876);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(862);
          match(PotatoSQLParser::K_GROUP);
          setState(863);
          match(PotatoSQLParser::K_BY);
          setState(864);
          expr(0);
          setState(869);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(865);
            match(PotatoSQLParser::COMMA);
            setState(866);
            expr(0);
            setState(871);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(874);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(872);
            match(PotatoSQLParser::K_HAVING);
            setState(873);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(878);
        match(PotatoSQLParser::K_VALUES);
        setState(879);
        match(PotatoSQLParser::OPEN_PAR);
        setState(880);
        expr(0);
        setState(885);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(881);
          match(PotatoSQLParser::COMMA);
          setState(882);
          expr(0);
          setState(887);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(888);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(903);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(889);
          match(PotatoSQLParser::COMMA);
          setState(890);
          match(PotatoSQLParser::OPEN_PAR);
          setState(891);
          expr(0);
          setState(896);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(892);
            match(PotatoSQLParser::COMMA);
            setState(893);
            expr(0);
            setState(898);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(899);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(905);
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
  enterRule(_localctx, 64, PotatoSQLParser::RuleUpdate_stmt);
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
    setState(909);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(908);
      with_clause();
    }
    setState(911);
    match(PotatoSQLParser::K_UPDATE);
    setState(922);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
    case 1: {
      setState(912);
      match(PotatoSQLParser::K_OR);
      setState(913);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(914);
      match(PotatoSQLParser::K_OR);
      setState(915);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(916);
      match(PotatoSQLParser::K_OR);
      setState(917);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(918);
      match(PotatoSQLParser::K_OR);
      setState(919);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(920);
      match(PotatoSQLParser::K_OR);
      setState(921);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(924);
    qualified_table_name();
    setState(925);
    match(PotatoSQLParser::K_SET);
    setState(926);
    column_name();
    setState(927);
    match(PotatoSQLParser::ASSIGN);
    setState(928);
    expr(0);
    setState(936);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(929);
      match(PotatoSQLParser::COMMA);
      setState(930);
      column_name();
      setState(931);
      match(PotatoSQLParser::ASSIGN);
      setState(932);
      expr(0);
      setState(938);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(941);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(939);
      match(PotatoSQLParser::K_WHERE);
      setState(940);
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
  enterRule(_localctx, 66, PotatoSQLParser::RuleUpdate_stmt_limited);
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
    setState(944);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WITH) {
      setState(943);
      with_clause();
    }
    setState(946);
    match(PotatoSQLParser::K_UPDATE);
    setState(957);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 129, _ctx)) {
    case 1: {
      setState(947);
      match(PotatoSQLParser::K_OR);
      setState(948);
      match(PotatoSQLParser::K_ROLLBACK);
      break;
    }

    case 2: {
      setState(949);
      match(PotatoSQLParser::K_OR);
      setState(950);
      match(PotatoSQLParser::K_ABORT);
      break;
    }

    case 3: {
      setState(951);
      match(PotatoSQLParser::K_OR);
      setState(952);
      match(PotatoSQLParser::K_REPLACE);
      break;
    }

    case 4: {
      setState(953);
      match(PotatoSQLParser::K_OR);
      setState(954);
      match(PotatoSQLParser::K_FAIL);
      break;
    }

    case 5: {
      setState(955);
      match(PotatoSQLParser::K_OR);
      setState(956);
      match(PotatoSQLParser::K_IGNORE);
      break;
    }

    default:
      break;
    }
    setState(959);
    qualified_table_name();
    setState(960);
    match(PotatoSQLParser::K_SET);
    setState(961);
    column_name();
    setState(962);
    match(PotatoSQLParser::ASSIGN);
    setState(963);
    expr(0);
    setState(971);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(964);
      match(PotatoSQLParser::COMMA);
      setState(965);
      column_name();
      setState(966);
      match(PotatoSQLParser::ASSIGN);
      setState(967);
      expr(0);
      setState(973);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(976);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_WHERE) {
      setState(974);
      match(PotatoSQLParser::K_WHERE);
      setState(975);
      expr(0);
    }
    setState(996);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_LIMIT

    || _la == PotatoSQLParser::K_ORDER) {
      setState(988);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ORDER) {
        setState(978);
        match(PotatoSQLParser::K_ORDER);
        setState(979);
        match(PotatoSQLParser::K_BY);
        setState(980);
        ordering_term();
        setState(985);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(981);
          match(PotatoSQLParser::COMMA);
          setState(982);
          ordering_term();
          setState(987);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(990);
      match(PotatoSQLParser::K_LIMIT);
      setState(991);
      expr(0);
      setState(994);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET) {
        setState(992);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::COMMA || _la == PotatoSQLParser::K_OFFSET)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(993);
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


PotatoSQLParser::Vacuum_stmtContext* PotatoSQLParser::vacuum_stmt() {
  Vacuum_stmtContext *_localctx = _tracker.createInstance<Vacuum_stmtContext>(_ctx, getState());
  enterRule(_localctx, 68, PotatoSQLParser::RuleVacuum_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(998);
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


PotatoSQLParser::Column_defContext* PotatoSQLParser::column_def() {
  Column_defContext *_localctx = _tracker.createInstance<Column_defContext>(_ctx, getState());
  enterRule(_localctx, 70, PotatoSQLParser::RuleColumn_def);
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
    setState(1000);
    column_name();
    setState(1002);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 136, _ctx)) {
    case 1: {
      setState(1001);
      type_name();
      break;
    }

    default:
      break;
    }
    setState(1007);
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
      setState(1004);
      column_constraint();
      setState(1009);
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
  enterRule(_localctx, 72, PotatoSQLParser::RuleType_name);

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
    setState(1011); 
    _errHandler->sync(this);
    alt = 1 + 1;
    do {
      switch (alt) {
        case 1 + 1: {
              setState(1010);
              name();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1013); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx);
    } while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(1025);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
    case 1: {
      setState(1015);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1016);
      signed_number();
      setState(1017);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 2: {
      setState(1019);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1020);
      signed_number();
      setState(1021);
      match(PotatoSQLParser::COMMA);
      setState(1022);
      signed_number();
      setState(1023);
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
  enterRule(_localctx, 74, PotatoSQLParser::RuleColumn_constraint);
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
    setState(1029);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1027);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1028);
      name();
    }
    setState(1064);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY: {
        setState(1031);
        match(PotatoSQLParser::K_PRIMARY);
        setState(1032);
        match(PotatoSQLParser::K_KEY);
        setState(1034);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_ASC

        || _la == PotatoSQLParser::K_DESC) {
          setState(1033);
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
        setState(1036);
        conflict_clause();
        setState(1038);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AUTOINCREMENT) {
          setState(1037);
          match(PotatoSQLParser::K_AUTOINCREMENT);
        }
        break;
      }

      case PotatoSQLParser::K_NOT:
      case PotatoSQLParser::K_NULL: {
        setState(1041);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(1040);
          match(PotatoSQLParser::K_NOT);
        }
        setState(1043);
        match(PotatoSQLParser::K_NULL);
        setState(1044);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_UNIQUE: {
        setState(1045);
        match(PotatoSQLParser::K_UNIQUE);
        setState(1046);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1047);
        match(PotatoSQLParser::K_CHECK);
        setState(1048);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1049);
        expr(0);
        setState(1050);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_DEFAULT: {
        setState(1052);
        match(PotatoSQLParser::K_DEFAULT);
        setState(1059);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
        case 1: {
          setState(1053);
          signed_number();
          break;
        }

        case 2: {
          setState(1054);
          literal_value();
          break;
        }

        case 3: {
          setState(1055);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1056);
          expr(0);
          setState(1057);
          match(PotatoSQLParser::CLOSE_PAR);
          break;
        }

        default:
          break;
        }
        break;
      }

      case PotatoSQLParser::K_COLLATE: {
        setState(1061);
        match(PotatoSQLParser::K_COLLATE);
        setState(1062);
        collation_name();
        break;
      }

      case PotatoSQLParser::K_REFERENCES: {
        setState(1063);
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
  enterRule(_localctx, 76, PotatoSQLParser::RuleConflict_clause);
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
    setState(1069);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ON) {
      setState(1066);
      match(PotatoSQLParser::K_ON);
      setState(1067);
      match(PotatoSQLParser::K_CONFLICT);
      setState(1068);
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



PotatoSQLParser::ExprContext* PotatoSQLParser::expr() {
   return expr(0);
}

PotatoSQLParser::ExprContext* PotatoSQLParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  PotatoSQLParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  PotatoSQLParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 78;
  enterRecursionRule(_localctx, 78, PotatoSQLParser::RuleExpr, precedence);

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
    setState(1147);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
    case 1: {
      setState(1072);
      literal_value();
      break;
    }

    case 2: {
      setState(1073);
      match(PotatoSQLParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(1082);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
      case 1: {
        setState(1077);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 147, _ctx)) {
        case 1: {
          setState(1074);
          database_name();
          setState(1075);
          match(PotatoSQLParser::DOT);
          break;
        }

        default:
          break;
        }
        setState(1079);
        table_name();
        setState(1080);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1084);
      column_name();
      break;
    }

    case 4: {
      setState(1085);
      unary_operator();
      setState(1086);
      expr(21);
      break;
    }

    case 5: {
      setState(1088);
      function_name();
      setState(1089);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1102);
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
          setState(1091);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx)) {
          case 1: {
            setState(1090);
            match(PotatoSQLParser::K_DISTINCT);
            break;
          }

          default:
            break;
          }
          setState(1093);
          expr(0);
          setState(1098);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1094);
            match(PotatoSQLParser::COMMA);
            setState(1095);
            expr(0);
            setState(1100);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case PotatoSQLParser::STAR: {
          setState(1101);
          match(PotatoSQLParser::STAR);
          break;
        }

        case PotatoSQLParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(1104);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 6: {
      setState(1106);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1107);
      expr(0);
      setState(1108);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 7: {
      setState(1110);
      match(PotatoSQLParser::K_CAST);
      setState(1111);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1112);
      expr(0);
      setState(1113);
      match(PotatoSQLParser::K_AS);
      setState(1114);
      type_name();
      setState(1115);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 8: {
      setState(1121);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_EXISTS

      || _la == PotatoSQLParser::K_NOT) {
        setState(1118);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NOT) {
          setState(1117);
          match(PotatoSQLParser::K_NOT);
        }
        setState(1120);
        match(PotatoSQLParser::K_EXISTS);
      }
      setState(1123);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1124);
      select_stmt();
      setState(1125);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 9: {
      setState(1127);
      match(PotatoSQLParser::K_CASE);
      setState(1129);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
      case 1: {
        setState(1128);
        expr(0);
        break;
      }

      default:
        break;
      }
      setState(1136); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1131);
        match(PotatoSQLParser::K_WHEN);
        setState(1132);
        expr(0);
        setState(1133);
        match(PotatoSQLParser::K_THEN);
        setState(1134);
        expr(0);
        setState(1138); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == PotatoSQLParser::K_WHEN);
      setState(1142);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_ELSE) {
        setState(1140);
        match(PotatoSQLParser::K_ELSE);
        setState(1141);
        expr(0);
      }
      setState(1144);
      match(PotatoSQLParser::K_END);
      break;
    }

    case 10: {
      setState(1146);
      raise_function();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(1236);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1234);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1149);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(1150);
          match(PotatoSQLParser::PIPE2);
          setState(1151);
          expr(21);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1152);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(1153);
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
          setState(1154);
          expr(20);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1155);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(1156);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::PLUS

          || _la == PotatoSQLParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1157);
          expr(19);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1158);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(1159);
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
          setState(1160);
          expr(18);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1161);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(1162);
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
          setState(1163);
          expr(17);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1164);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(1165);
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
          setState(1166);
          expr(16);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1167);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1168);
          match(PotatoSQLParser::K_AND);
          setState(1169);
          expr(14);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1170);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(1171);
          match(PotatoSQLParser::K_OR);
          setState(1172);
          expr(13);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1173);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(1174);
          match(PotatoSQLParser::K_IS);
          setState(1176);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx)) {
          case 1: {
            setState(1175);
            match(PotatoSQLParser::K_NOT);
            break;
          }

          default:
            break;
          }
          setState(1178);
          expr(6);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1179);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1181);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1180);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1183);
          match(PotatoSQLParser::K_BETWEEN);
          setState(1184);
          expr(0);
          setState(1185);
          match(PotatoSQLParser::K_AND);
          setState(1186);
          expr(5);
          break;
        }

        case 11: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1188);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(1190);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1189);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1192);
          match(PotatoSQLParser::K_IN);
          setState(1212);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx)) {
          case 1: {
            setState(1193);
            match(PotatoSQLParser::OPEN_PAR);
            setState(1203);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx)) {
            case 1: {
              setState(1194);
              select_stmt();
              break;
            }

            case 2: {
              setState(1195);
              expr(0);
              setState(1200);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while (_la == PotatoSQLParser::COMMA) {
                setState(1196);
                match(PotatoSQLParser::COMMA);
                setState(1197);
                expr(0);
                setState(1202);
                _errHandler->sync(this);
                _la = _input->LA(1);
              }
              break;
            }

            default:
              break;
            }
            setState(1205);
            match(PotatoSQLParser::CLOSE_PAR);
            break;
          }

          case 2: {
            setState(1209);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
            case 1: {
              setState(1206);
              database_name();
              setState(1207);
              match(PotatoSQLParser::DOT);
              break;
            }

            default:
              break;
            }
            setState(1211);
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
          setState(1214);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(1215);
          match(PotatoSQLParser::K_COLLATE);
          setState(1216);
          collation_name();
          break;
        }

        case 13: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(1217);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(1219);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_NOT) {
            setState(1218);
            match(PotatoSQLParser::K_NOT);
          }
          setState(1221);
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
          setState(1222);
          expr(0);
          setState(1225);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
          case 1: {
            setState(1223);
            match(PotatoSQLParser::K_ESCAPE);
            setState(1224);
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
          setState(1227);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(1232);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case PotatoSQLParser::K_ISNULL: {
              setState(1228);
              match(PotatoSQLParser::K_ISNULL);
              break;
            }

            case PotatoSQLParser::K_NOTNULL: {
              setState(1229);
              match(PotatoSQLParser::K_NOTNULL);
              break;
            }

            case PotatoSQLParser::K_NOT: {
              setState(1230);
              match(PotatoSQLParser::K_NOT);
              setState(1231);
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
      setState(1238);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx);
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


PotatoSQLParser::Foreign_key_clauseContext* PotatoSQLParser::foreign_key_clause() {
  Foreign_key_clauseContext *_localctx = _tracker.createInstance<Foreign_key_clauseContext>(_ctx, getState());
  enterRule(_localctx, 80, PotatoSQLParser::RuleForeign_key_clause);
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
    setState(1239);
    match(PotatoSQLParser::K_REFERENCES);
    setState(1240);
    foreign_table();
    setState(1252);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1241);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1242);
      column_name();
      setState(1247);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1243);
        match(PotatoSQLParser::COMMA);
        setState(1244);
        column_name();
        setState(1249);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1250);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1272);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::K_MATCH

    || _la == PotatoSQLParser::K_ON) {
      setState(1268);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_ON: {
          setState(1254);
          match(PotatoSQLParser::K_ON);
          setState(1255);
          _la = _input->LA(1);
          if (!(_la == PotatoSQLParser::K_DELETE || _la == PotatoSQLParser::K_UPDATE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(1264);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx)) {
          case 1: {
            setState(1256);
            match(PotatoSQLParser::K_SET);
            setState(1257);
            match(PotatoSQLParser::K_NULL);
            break;
          }

          case 2: {
            setState(1258);
            match(PotatoSQLParser::K_SET);
            setState(1259);
            match(PotatoSQLParser::K_DEFAULT);
            break;
          }

          case 3: {
            setState(1260);
            match(PotatoSQLParser::K_CASCADE);
            break;
          }

          case 4: {
            setState(1261);
            match(PotatoSQLParser::K_RESTRICT);
            break;
          }

          case 5: {
            setState(1262);
            match(PotatoSQLParser::K_NO);
            setState(1263);
            match(PotatoSQLParser::K_ACTION);
            break;
          }

          default:
            break;
          }
          break;
        }

        case PotatoSQLParser::K_MATCH: {
          setState(1266);
          match(PotatoSQLParser::K_MATCH);
          setState(1267);
          name();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(1274);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1285);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 177, _ctx)) {
    case 1: {
      setState(1276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_NOT) {
        setState(1275);
        match(PotatoSQLParser::K_NOT);
      }
      setState(1278);
      match(PotatoSQLParser::K_DEFERRABLE);
      setState(1283);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 176, _ctx)) {
      case 1: {
        setState(1279);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1280);
        match(PotatoSQLParser::K_DEFERRED);
        break;
      }

      case 2: {
        setState(1281);
        match(PotatoSQLParser::K_INITIALLY);
        setState(1282);
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


PotatoSQLParser::Raise_functionContext* PotatoSQLParser::raise_function() {
  Raise_functionContext *_localctx = _tracker.createInstance<Raise_functionContext>(_ctx, getState());
  enterRule(_localctx, 82, PotatoSQLParser::RuleRaise_function);
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
    setState(1287);
    match(PotatoSQLParser::K_RAISE);
    setState(1288);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1293);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_IGNORE: {
        setState(1289);
        match(PotatoSQLParser::K_IGNORE);
        break;
      }

      case PotatoSQLParser::K_ABORT:
      case PotatoSQLParser::K_FAIL:
      case PotatoSQLParser::K_ROLLBACK: {
        setState(1290);
        _la = _input->LA(1);
        if (!(_la == PotatoSQLParser::K_ABORT || _la == PotatoSQLParser::K_FAIL

        || _la == PotatoSQLParser::K_ROLLBACK)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(1291);
        match(PotatoSQLParser::COMMA);
        setState(1292);
        error_message();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(1295);
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


PotatoSQLParser::Indexed_columnContext* PotatoSQLParser::indexed_column() {
  Indexed_columnContext *_localctx = _tracker.createInstance<Indexed_columnContext>(_ctx, getState());
  enterRule(_localctx, 84, PotatoSQLParser::RuleIndexed_column);
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
    setState(1297);
    column_name();
    setState(1300);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1298);
      match(PotatoSQLParser::K_COLLATE);
      setState(1299);
      collation_name();
    }
    setState(1303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1302);
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


PotatoSQLParser::Table_constraintContext* PotatoSQLParser::table_constraint() {
  Table_constraintContext *_localctx = _tracker.createInstance<Table_constraintContext>(_ctx, getState());
  enterRule(_localctx, 86, PotatoSQLParser::RuleTable_constraint);
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
    setState(1307);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_CONSTRAINT) {
      setState(1305);
      match(PotatoSQLParser::K_CONSTRAINT);
      setState(1306);
      name();
    }
    setState(1345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_PRIMARY:
      case PotatoSQLParser::K_UNIQUE: {
        setState(1312);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_PRIMARY: {
            setState(1309);
            match(PotatoSQLParser::K_PRIMARY);
            setState(1310);
            match(PotatoSQLParser::K_KEY);
            break;
          }

          case PotatoSQLParser::K_UNIQUE: {
            setState(1311);
            match(PotatoSQLParser::K_UNIQUE);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(1314);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1315);
        indexed_column();
        setState(1320);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1316);
          match(PotatoSQLParser::COMMA);
          setState(1317);
          indexed_column();
          setState(1322);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1323);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1324);
        conflict_clause();
        break;
      }

      case PotatoSQLParser::K_CHECK: {
        setState(1326);
        match(PotatoSQLParser::K_CHECK);
        setState(1327);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1328);
        expr(0);
        setState(1329);
        match(PotatoSQLParser::CLOSE_PAR);
        break;
      }

      case PotatoSQLParser::K_FOREIGN: {
        setState(1331);
        match(PotatoSQLParser::K_FOREIGN);
        setState(1332);
        match(PotatoSQLParser::K_KEY);
        setState(1333);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1334);
        column_name();
        setState(1339);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1335);
          match(PotatoSQLParser::COMMA);
          setState(1336);
          column_name();
          setState(1341);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1342);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1343);
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
  enterRule(_localctx, 88, PotatoSQLParser::RuleWith_clause);
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
    setState(1347);
    match(PotatoSQLParser::K_WITH);
    setState(1349);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 186, _ctx)) {
    case 1: {
      setState(1348);
      match(PotatoSQLParser::K_RECURSIVE);
      break;
    }

    default:
      break;
    }
    setState(1351);
    common_table_expression();
    setState(1356);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA) {
      setState(1352);
      match(PotatoSQLParser::COMMA);
      setState(1353);
      common_table_expression();
      setState(1358);
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
  enterRule(_localctx, 90, PotatoSQLParser::RuleQualified_table_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 188, _ctx)) {
    case 1: {
      setState(1359);
      database_name();
      setState(1360);
      match(PotatoSQLParser::DOT);
      break;
    }

    default:
      break;
    }
    setState(1364);
    table_name();
    setState(1370);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_INDEXED: {
        setState(1365);
        match(PotatoSQLParser::K_INDEXED);
        setState(1366);
        match(PotatoSQLParser::K_BY);
        setState(1367);
        index_name();
        break;
      }

      case PotatoSQLParser::K_NOT: {
        setState(1368);
        match(PotatoSQLParser::K_NOT);
        setState(1369);
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


PotatoSQLParser::Ordering_termContext* PotatoSQLParser::ordering_term() {
  Ordering_termContext *_localctx = _tracker.createInstance<Ordering_termContext>(_ctx, getState());
  enterRule(_localctx, 92, PotatoSQLParser::RuleOrdering_term);
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
    setState(1372);
    expr(0);
    setState(1375);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_COLLATE) {
      setState(1373);
      match(PotatoSQLParser::K_COLLATE);
      setState(1374);
      collation_name();
    }
    setState(1378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::K_ASC

    || _la == PotatoSQLParser::K_DESC) {
      setState(1377);
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


PotatoSQLParser::Pragma_valueContext* PotatoSQLParser::pragma_value() {
  Pragma_valueContext *_localctx = _tracker.createInstance<Pragma_valueContext>(_ctx, getState());
  enterRule(_localctx, 94, PotatoSQLParser::RulePragma_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1383);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1380);
      signed_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1381);
      name();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1382);
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
  enterRule(_localctx, 96, PotatoSQLParser::RuleCommon_table_expression);
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
    setState(1385);
    table_name();
    setState(1397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::OPEN_PAR) {
      setState(1386);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1387);
      column_name();
      setState(1392);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == PotatoSQLParser::COMMA) {
        setState(1388);
        match(PotatoSQLParser::COMMA);
        setState(1389);
        column_name();
        setState(1394);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1395);
      match(PotatoSQLParser::CLOSE_PAR);
    }
    setState(1399);
    match(PotatoSQLParser::K_AS);
    setState(1400);
    match(PotatoSQLParser::OPEN_PAR);
    setState(1401);
    select_stmt();
    setState(1402);
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
  enterRule(_localctx, 98, PotatoSQLParser::RuleResult_column);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 197, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1404);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1405);
      table_name();
      setState(1406);
      match(PotatoSQLParser::DOT);
      setState(1407);
      match(PotatoSQLParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1409);
      expr(0);
      setState(1414);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1411);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1410);
          match(PotatoSQLParser::K_AS);
        }
        setState(1413);
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
  enterRule(_localctx, 100, PotatoSQLParser::RuleTable_or_subquery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1484);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 211, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1421);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 198, _ctx)) {
      case 1: {
        setState(1418);
        schema_name();
        setState(1419);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1423);
      table_name();
      setState(1428);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1425);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1424);
          match(PotatoSQLParser::K_AS);
        }
        setState(1427);
        table_alias();
      }
      setState(1435);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case PotatoSQLParser::K_INDEXED: {
          setState(1430);
          match(PotatoSQLParser::K_INDEXED);
          setState(1431);
          match(PotatoSQLParser::K_BY);
          setState(1432);
          index_name();
          break;
        }

        case PotatoSQLParser::K_NOT: {
          setState(1433);
          match(PotatoSQLParser::K_NOT);
          setState(1434);
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
      setState(1440);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx)) {
      case 1: {
        setState(1437);
        schema_name();
        setState(1438);
        match(PotatoSQLParser::DOT);
        break;
      }

      default:
        break;
      }
      setState(1442);
      table_function_name();
      setState(1443);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1452);
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
        setState(1444);
        expr(0);
        setState(1449);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1445);
          match(PotatoSQLParser::COMMA);
          setState(1446);
          expr(0);
          setState(1451);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1454);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1459);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1456);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1455);
          match(PotatoSQLParser::K_AS);
        }
        setState(1458);
        table_alias();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1461);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1471);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx)) {
      case 1: {
        setState(1462);
        table_or_subquery();
        setState(1467);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1463);
          match(PotatoSQLParser::COMMA);
          setState(1464);
          table_or_subquery();
          setState(1469);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(1470);
        join_clause();
        break;
      }

      default:
        break;
      }
      setState(1473);
      match(PotatoSQLParser::CLOSE_PAR);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1475);
      match(PotatoSQLParser::OPEN_PAR);
      setState(1476);
      select_stmt();
      setState(1477);
      match(PotatoSQLParser::CLOSE_PAR);
      setState(1482);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == PotatoSQLParser::OPEN_PAR

      || _la == PotatoSQLParser::K_AS || _la == PotatoSQLParser::IDENTIFIER

      || _la == PotatoSQLParser::STRING_LITERAL) {
        setState(1479);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_AS) {
          setState(1478);
          match(PotatoSQLParser::K_AS);
        }
        setState(1481);
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
  enterRule(_localctx, 102, PotatoSQLParser::RuleJoin_clause);
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
    setState(1486);
    table_or_subquery();
    setState(1493);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == PotatoSQLParser::COMMA

    || _la == PotatoSQLParser::K_CROSS || ((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (PotatoSQLParser::K_INNER - 87))
      | (1ULL << (PotatoSQLParser::K_JOIN - 87))
      | (1ULL << (PotatoSQLParser::K_LEFT - 87))
      | (1ULL << (PotatoSQLParser::K_NATURAL - 87)))) != 0)) {
      setState(1487);
      join_operator();
      setState(1488);
      table_or_subquery();
      setState(1489);
      join_constraint();
      setState(1495);
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
  enterRule(_localctx, 104, PotatoSQLParser::RuleJoin_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1509);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(1496);
        match(PotatoSQLParser::COMMA);
        break;
      }

      case PotatoSQLParser::K_CROSS:
      case PotatoSQLParser::K_INNER:
      case PotatoSQLParser::K_JOIN:
      case PotatoSQLParser::K_LEFT:
      case PotatoSQLParser::K_NATURAL: {
        enterOuterAlt(_localctx, 2);
        setState(1498);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_NATURAL) {
          setState(1497);
          match(PotatoSQLParser::K_NATURAL);
        }
        setState(1506);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case PotatoSQLParser::K_LEFT: {
            setState(1500);
            match(PotatoSQLParser::K_LEFT);
            setState(1502);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == PotatoSQLParser::K_OUTER) {
              setState(1501);
              match(PotatoSQLParser::K_OUTER);
            }
            break;
          }

          case PotatoSQLParser::K_INNER: {
            setState(1504);
            match(PotatoSQLParser::K_INNER);
            break;
          }

          case PotatoSQLParser::K_CROSS: {
            setState(1505);
            match(PotatoSQLParser::K_CROSS);
            break;
          }

          case PotatoSQLParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(1508);
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
  enterRule(_localctx, 106, PotatoSQLParser::RuleJoin_constraint);
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
    setState(1525);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_ON: {
        setState(1511);
        match(PotatoSQLParser::K_ON);
        setState(1512);
        expr(0);
        break;
      }

      case PotatoSQLParser::K_USING: {
        setState(1513);
        match(PotatoSQLParser::K_USING);
        setState(1514);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1515);
        column_name();
        setState(1520);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1516);
          match(PotatoSQLParser::COMMA);
          setState(1517);
          column_name();
          setState(1522);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1523);
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
  enterRule(_localctx, 108, PotatoSQLParser::RuleSelect_core);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1601);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1527);
        match(PotatoSQLParser::K_SELECT);
        setState(1529);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 219, _ctx)) {
        case 1: {
          setState(1528);
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
        setState(1531);
        result_column();
        setState(1536);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1532);
          match(PotatoSQLParser::COMMA);
          setState(1533);
          result_column();
          setState(1538);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1551);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_FROM) {
          setState(1539);
          match(PotatoSQLParser::K_FROM);
          setState(1549);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 222, _ctx)) {
          case 1: {
            setState(1540);
            table_or_subquery();
            setState(1545);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == PotatoSQLParser::COMMA) {
              setState(1541);
              match(PotatoSQLParser::COMMA);
              setState(1542);
              table_or_subquery();
              setState(1547);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(1548);
            join_clause();
            break;
          }

          default:
            break;
          }
        }
        setState(1555);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_WHERE) {
          setState(1553);
          match(PotatoSQLParser::K_WHERE);
          setState(1554);
          expr(0);
        }
        setState(1571);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == PotatoSQLParser::K_GROUP) {
          setState(1557);
          match(PotatoSQLParser::K_GROUP);
          setState(1558);
          match(PotatoSQLParser::K_BY);
          setState(1559);
          expr(0);
          setState(1564);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1560);
            match(PotatoSQLParser::COMMA);
            setState(1561);
            expr(0);
            setState(1566);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1569);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == PotatoSQLParser::K_HAVING) {
            setState(1567);
            match(PotatoSQLParser::K_HAVING);
            setState(1568);
            expr(0);
          }
        }
        break;
      }

      case PotatoSQLParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(1573);
        match(PotatoSQLParser::K_VALUES);
        setState(1574);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1575);
        expr(0);
        setState(1580);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1576);
          match(PotatoSQLParser::COMMA);
          setState(1577);
          expr(0);
          setState(1582);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1583);
        match(PotatoSQLParser::CLOSE_PAR);
        setState(1598);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == PotatoSQLParser::COMMA) {
          setState(1584);
          match(PotatoSQLParser::COMMA);
          setState(1585);
          match(PotatoSQLParser::OPEN_PAR);
          setState(1586);
          expr(0);
          setState(1591);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == PotatoSQLParser::COMMA) {
            setState(1587);
            match(PotatoSQLParser::COMMA);
            setState(1588);
            expr(0);
            setState(1593);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1594);
          match(PotatoSQLParser::CLOSE_PAR);
          setState(1600);
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
  enterRule(_localctx, 110, PotatoSQLParser::RuleCompound_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1608);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 232, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1603);
      match(PotatoSQLParser::K_UNION);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1604);
      match(PotatoSQLParser::K_UNION);
      setState(1605);
      match(PotatoSQLParser::K_ALL);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1606);
      match(PotatoSQLParser::K_INTERSECT);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1607);
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
  enterRule(_localctx, 112, PotatoSQLParser::RuleSigned_number);
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
    setState(1611);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PotatoSQLParser::PLUS

    || _la == PotatoSQLParser::MINUS) {
      setState(1610);
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
    setState(1613);
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
  enterRule(_localctx, 114, PotatoSQLParser::RuleLiteral_value);
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
    setState(1615);
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


PotatoSQLParser::Unary_operatorContext* PotatoSQLParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 116, PotatoSQLParser::RuleUnary_operator);
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


PotatoSQLParser::Error_messageContext* PotatoSQLParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 118, PotatoSQLParser::RuleError_message);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1619);
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
  enterRule(_localctx, 120, PotatoSQLParser::RuleModule_argument);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1623);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 234, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1621);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1622);
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
  enterRule(_localctx, 122, PotatoSQLParser::RuleColumn_alias);
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
    setState(1625);
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


PotatoSQLParser::KeywordContext* PotatoSQLParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 124, PotatoSQLParser::RuleKeyword);
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
    setState(1627);
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


PotatoSQLParser::NameContext* PotatoSQLParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 126, PotatoSQLParser::RuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1629);
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
  enterRule(_localctx, 128, PotatoSQLParser::RuleFunction_name);

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
  enterRule(_localctx, 130, PotatoSQLParser::RuleDatabase_name);

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
  enterRule(_localctx, 132, PotatoSQLParser::RuleSchema_name);

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
  enterRule(_localctx, 134, PotatoSQLParser::RuleTable_function_name);

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
  enterRule(_localctx, 136, PotatoSQLParser::RuleTable_name);

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
  enterRule(_localctx, 138, PotatoSQLParser::RuleTable_or_index_name);

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
  enterRule(_localctx, 140, PotatoSQLParser::RuleNew_table_name);

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
  enterRule(_localctx, 142, PotatoSQLParser::RuleColumn_name);

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
  enterRule(_localctx, 144, PotatoSQLParser::RuleCollation_name);

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
  enterRule(_localctx, 146, PotatoSQLParser::RuleForeign_table);

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
  enterRule(_localctx, 148, PotatoSQLParser::RuleIndex_name);

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


PotatoSQLParser::Trigger_nameContext* PotatoSQLParser::trigger_name() {
  Trigger_nameContext *_localctx = _tracker.createInstance<Trigger_nameContext>(_ctx, getState());
  enterRule(_localctx, 150, PotatoSQLParser::RuleTrigger_name);

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


PotatoSQLParser::View_nameContext* PotatoSQLParser::view_name() {
  View_nameContext *_localctx = _tracker.createInstance<View_nameContext>(_ctx, getState());
  enterRule(_localctx, 152, PotatoSQLParser::RuleView_name);

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


PotatoSQLParser::Module_nameContext* PotatoSQLParser::module_name() {
  Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, getState());
  enterRule(_localctx, 154, PotatoSQLParser::RuleModule_name);

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
  enterRule(_localctx, 156, PotatoSQLParser::RulePragma_name);

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
  enterRule(_localctx, 158, PotatoSQLParser::RuleSavepoint_name);

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
  enterRule(_localctx, 160, PotatoSQLParser::RuleTable_alias);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1669);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1663);
        match(PotatoSQLParser::IDENTIFIER);
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1664);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 3);
        setState(1665);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1666);
        table_alias();
        setState(1667);
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


PotatoSQLParser::Transaction_nameContext* PotatoSQLParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 162, PotatoSQLParser::RuleTransaction_name);

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
  enterRule(_localctx, 164, PotatoSQLParser::RuleAny_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(1680);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PotatoSQLParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(1673);
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
        setState(1674);
        keyword();
        break;
      }

      case PotatoSQLParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(1675);
        match(PotatoSQLParser::STRING_LITERAL);
        break;
      }

      case PotatoSQLParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(1676);
        match(PotatoSQLParser::OPEN_PAR);
        setState(1677);
        any_name();
        setState(1678);
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
    case 39: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

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
  "insert_stmt", "pragma_stmt", "reindex_stmt", "release_stmt", "rollback_stmt", 
  "savepoint_stmt", "simple_select_stmt", "select_stmt", "select_or_values", 
  "update_stmt", "update_stmt_limited", "vacuum_stmt", "column_def", "type_name", 
  "column_constraint", "conflict_clause", "expr", "foreign_key_clause", 
  "raise_function", "indexed_column", "table_constraint", "with_clause", 
  "qualified_table_name", "ordering_term", "pragma_value", "common_table_expression", 
  "result_column", "table_or_subquery", "join_clause", "join_operator", 
  "join_constraint", "select_core", "compound_operator", "signed_number", 
  "literal_value", "unary_operator", "error_message", "module_argument", 
  "column_alias", "keyword", "name", "function_name", "database_name", "schema_name", 
  "table_function_name", "table_name", "table_or_index_name", "new_table_name", 
  "column_name", "collation_name", "foreign_table", "index_name", "trigger_name", 
  "view_name", "module_name", "pragma_name", "savepoint_name", "table_alias", 
  "transaction_name", "any_name"
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
       0x3, 0x9f, 0x695, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xab, 
       0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xae, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x7, 0x4, 0xb6, 0xa, 0x4, 
       0xc, 0x4, 0xe, 0x4, 0xb9, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 
       0xbd, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0xbe, 0x3, 0x4, 0x7, 0x4, 0xc2, 
       0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xc5, 0xb, 0x4, 0x3, 0x4, 0x7, 0x4, 
       0xc8, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xcb, 0xb, 0x4, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x5, 0x5, 0xd0, 0xa, 0x5, 0x5, 0x5, 0xd2, 0xa, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xf2, 0xa, 0x5, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xf9, 
       0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x5, 0x6, 0x101, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x104, 0xa, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x5, 0x7, 0x10d, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x111, 
       0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
       0x9, 0x5, 0x9, 0x119, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x11d, 
       0xa, 0x9, 0x5, 0x9, 0x11f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
       0x5, 0xa, 0x124, 0xa, 0xa, 0x5, 0xa, 0x126, 0xa, 0xa, 0x3, 0xb, 0x5, 
       0xb, 0x129, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x12e, 
       0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x132, 0xa, 0xb, 0x3, 0xb, 
       0x6, 0xb, 0x135, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0x136, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x13e, 0xa, 0xb, 0xc, 
       0xb, 0xe, 0xb, 0x141, 0xb, 0xb, 0x5, 0xb, 0x143, 0xa, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x149, 0xa, 0xb, 0x5, 0xb, 
       0x14b, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x14f, 0xa, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x155, 0xa, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x15a, 0xa, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
       0x163, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x166, 0xb, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x5, 0xc, 0x16b, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 
       0xd, 0x16f, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
       0xd, 0x175, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x17a, 
       0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
       0xd, 0x181, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x184, 0xb, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x7, 0xd, 0x188, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x18b, 0xb, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x190, 0xa, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x5, 0xd, 0x194, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 
       0xe, 0x198, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
       0xe, 0x19e, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1a3, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
       0xe, 0x1aa, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x1b3, 0xa, 0xe, 0xc, 0xe, 0xe, 
       0xe, 0x1b6, 0xb, 0xe, 0x5, 0xe, 0x1b8, 0xa, 0xe, 0x5, 0xe, 0x1ba, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1c0, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1c6, 
       0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1ca, 0xa, 0xe, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x1d1, 0xa, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0x1d5, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 
       0x1d6, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1dd, 0xa, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1e3, 0xa, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x1e8, 0xa, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1f4, 0xa, 0x10, 0x3, 
       0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x1f9, 0xa, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x7, 0x10, 0x202, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x205, 0xb, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x209, 0xa, 0x10, 0x3, 0x11, 0x5, 
       0x11, 0x20c, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x5, 0x11, 0x213, 0xa, 0x11, 0x3, 0x12, 0x5, 0x12, 0x216, 
       0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x5, 0x12, 0x21d, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x7, 0x12, 0x224, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
       0x227, 0xb, 0x12, 0x5, 0x12, 0x229, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x22f, 0xa, 0x12, 0x5, 0x12, 0x231, 
       0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x235, 0xa, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
       0x14, 0x23d, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
       0x242, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x5, 0x15, 0x24a, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x5, 0x15, 0x24f, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x257, 0xa, 0x16, 
       0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x25c, 0xa, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 
       0x17, 0x264, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 
       0x269, 0xa, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x5, 0x18, 0x26e, 
       0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 
       0x274, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x277, 0xb, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x27e, 0xa, 
       0x18, 0xc, 0x18, 0xe, 0x18, 0x281, 0xb, 0x18, 0x5, 0x18, 0x283, 0xa, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x289, 
       0xa, 0x18, 0x5, 0x18, 0x28b, 0xa, 0x18, 0x3, 0x19, 0x5, 0x19, 0x28e, 
       0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x5, 0x19, 0x2a1, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
       0x19, 0x5, 0x19, 0x2a7, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x2ae, 0xa, 0x19, 0xc, 0x19, 0xe, 
       0x19, 0x2b1, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x2b5, 0xa, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 
       0x19, 0x2bc, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x2bf, 0xb, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 
       0x19, 0x2c7, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x2ca, 0xb, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x7, 0x19, 0x2ce, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
       0x2d1, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x2d6, 
       0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 
       0x2dc, 0xa, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
       0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x2e5, 0xa, 0x1a, 0x3, 0x1b, 
       0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x2ec, 0xa, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x2f0, 0xa, 0x1b, 0x5, 0x1b, 
       0x2f2, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x2f6, 0xa, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
       0x2fd, 0xa, 0x1d, 0x5, 0x1d, 0x2ff, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
       0x5, 0x1d, 0x303, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x306, 0xa, 0x1d, 
       0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x5, 0x1f, 0x30c, 0xa, 
       0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
       0x1f, 0x7, 0x1f, 0x314, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x317, 0xb, 
       0x1f, 0x5, 0x1f, 0x319, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x1f, 0x5, 0x1f, 0x31f, 0xa, 0x1f, 0x5, 0x1f, 0x321, 0xa, 0x1f, 
       0x3, 0x20, 0x5, 0x20, 0x324, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x3, 0x20, 0x7, 0x20, 0x32a, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
       0x32d, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
       0x20, 0x7, 0x20, 0x334, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x337, 0xb, 
       0x20, 0x5, 0x20, 0x339, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x5, 0x20, 0x33f, 0xa, 0x20, 0x5, 0x20, 0x341, 0xa, 0x20, 
       0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x345, 0xa, 0x21, 0x3, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x7, 0x21, 0x34a, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
       0x34d, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 
       0x21, 0x353, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x356, 0xb, 0x21, 0x3, 
       0x21, 0x5, 0x21, 0x359, 0xa, 0x21, 0x5, 0x21, 0x35b, 0xa, 0x21, 0x3, 
       0x21, 0x3, 0x21, 0x5, 0x21, 0x35f, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x366, 0xa, 0x21, 0xc, 
       0x21, 0xe, 0x21, 0x369, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
       0x36d, 0xa, 0x21, 0x5, 0x21, 0x36f, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x376, 0xa, 0x21, 0xc, 
       0x21, 0xe, 0x21, 0x379, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
       0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x381, 0xa, 0x21, 0xc, 
       0x21, 0xe, 0x21, 0x384, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 
       0x388, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x38b, 0xb, 0x21, 0x5, 0x21, 
       0x38d, 0xa, 0x21, 0x3, 0x22, 0x5, 0x22, 0x390, 0xa, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
       0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x39d, 0xa, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x3a9, 
       0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x3ac, 0xb, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x5, 0x22, 0x3b0, 0xa, 0x22, 0x3, 0x23, 0x5, 0x23, 0x3b3, 0xa, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 
       0x23, 0x3c0, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x7, 0x23, 0x3cc, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x3cf, 0xb, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x3d3, 0xa, 0x23, 0x3, 0x23, 0x3, 
       0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x3da, 0xa, 0x23, 
       0xc, 0x23, 0xe, 0x23, 0x3dd, 0xb, 0x23, 0x5, 0x23, 0x3df, 0xa, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x3e5, 0xa, 
       0x23, 0x5, 0x23, 0x3e7, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 
       0x3, 0x25, 0x5, 0x25, 0x3ed, 0xa, 0x25, 0x3, 0x25, 0x7, 0x25, 0x3f0, 
       0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x3f3, 0xb, 0x25, 0x3, 0x26, 0x6, 
       0x26, 0x3f6, 0xa, 0x26, 0xd, 0x26, 0xe, 0x26, 0x3f7, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
       0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x404, 0xa, 0x26, 0x3, 0x27, 
       0x3, 0x27, 0x5, 0x27, 0x408, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x5, 0x27, 0x40d, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 
       0x411, 0xa, 0x27, 0x3, 0x27, 0x5, 0x27, 0x414, 0xa, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
       0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x426, 0xa, 0x27, 0x3, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x42b, 0xa, 0x27, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x430, 0xa, 0x28, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x438, 
       0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x43d, 0xa, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x5, 0x29, 0x446, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x7, 0x29, 0x44b, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x44e, 
       0xb, 0x29, 0x3, 0x29, 0x5, 0x29, 0x451, 0xa, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x461, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x464, 0xa, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x46c, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x6, 0x29, 0x473, 0xa, 0x29, 0xd, 0x29, 0xe, 
       0x29, 0x474, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x479, 0xa, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x47e, 0xa, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x49b, 0xa, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x5, 0x29, 0x4a0, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
       0x4a9, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x7, 0x29, 0x4b1, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 
       0x4b4, 0xb, 0x29, 0x5, 0x29, 0x4b6, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x4bc, 0xa, 0x29, 0x3, 0x29, 0x5, 
       0x29, 0x4bf, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x5, 0x29, 0x4c6, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
       0x29, 0x3, 0x29, 0x5, 0x29, 0x4cc, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x4d3, 0xa, 0x29, 0x7, 
       0x29, 0x4d5, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x4d8, 0xb, 0x29, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 
       0x2a, 0x4e0, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x4e3, 0xb, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4e7, 0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4f3, 0xa, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x5, 0x2a, 0x4f7, 0xa, 0x2a, 0x7, 0x2a, 0x4f9, 0xa, 0x2a, 0xc, 
       0x2a, 0xe, 0x2a, 0x4fc, 0xb, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4ff, 0xa, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 
       0x2a, 0x506, 0xa, 0x2a, 0x5, 0x2a, 0x508, 0xa, 0x2a, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x510, 
       0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
       0x5, 0x2c, 0x517, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x51a, 0xa, 0x2c, 
       0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x51e, 0xa, 0x2d, 0x3, 0x2d, 0x3, 
       0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x523, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x529, 0xa, 0x2d, 0xc, 0x2d, 0xe, 
       0x2d, 0x52c, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x53c, 0xa, 
       0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x53f, 0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x3, 0x2d, 0x5, 0x2d, 0x544, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 
       0x2e, 0x548, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 
       0x54d, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x550, 0xb, 0x2e, 0x3, 0x2f, 
       0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x555, 0xa, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x55d, 
       0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x562, 0xa, 
       0x30, 0x3, 0x30, 0x5, 0x30, 0x565, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x5, 0x31, 0x56a, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x571, 0xa, 0x32, 0xc, 0x32, 
       0xe, 0x32, 0x574, 0xb, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x578, 
       0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
       0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
       0x3, 0x33, 0x5, 0x33, 0x586, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x589, 
       0xa, 0x33, 0x5, 0x33, 0x58b, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x5, 0x34, 0x590, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 
       0x594, 0xa, 0x34, 0x3, 0x34, 0x5, 0x34, 0x597, 0xa, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x59e, 0xa, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5a3, 0xa, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 
       0x5aa, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x5ad, 0xb, 0x34, 0x5, 0x34, 
       0x5af, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5b3, 0xa, 0x34, 
       0x3, 0x34, 0x5, 0x34, 0x5b6, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
       0x34, 0x3, 0x34, 0x7, 0x34, 0x5bc, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 
       0x5bf, 0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5c2, 0xa, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 
       0x5ca, 0xa, 0x34, 0x3, 0x34, 0x5, 0x34, 0x5cd, 0xa, 0x34, 0x5, 0x34, 
       0x5cf, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x7, 0x35, 0x5d6, 0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x5d9, 0xb, 
       0x35, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x5dd, 0xa, 0x36, 0x3, 0x36, 
       0x3, 0x36, 0x5, 0x36, 0x5e1, 0xa, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 
       0x36, 0x5e5, 0xa, 0x36, 0x3, 0x36, 0x5, 0x36, 0x5e8, 0xa, 0x36, 0x3, 
       0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
       0x37, 0x7, 0x37, 0x5f1, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x5f4, 0xb, 
       0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x5f8, 0xa, 0x37, 0x3, 0x38, 
       0x3, 0x38, 0x5, 0x38, 0x5fc, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x7, 0x38, 0x601, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x604, 0xb, 
       0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x60a, 
       0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x60d, 0xb, 0x38, 0x3, 0x38, 0x5, 
       0x38, 0x610, 0xa, 0x38, 0x5, 0x38, 0x612, 0xa, 0x38, 0x3, 0x38, 0x3, 
       0x38, 0x5, 0x38, 0x616, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x61d, 0xa, 0x38, 0xc, 0x38, 0xe, 
       0x38, 0x620, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x624, 0xa, 
       0x38, 0x5, 0x38, 0x626, 0xa, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x62d, 0xa, 0x38, 0xc, 0x38, 0xe, 
       0x38, 0x630, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 
       0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x638, 0xa, 0x38, 0xc, 0x38, 0xe, 
       0x38, 0x63b, 0xb, 0x38, 0x3, 0x38, 0x3, 0x38, 0x7, 0x38, 0x63f, 0xa, 
       0x38, 0xc, 0x38, 0xe, 0x38, 0x642, 0xb, 0x38, 0x5, 0x38, 0x644, 0xa, 
       0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 
       0x39, 0x64b, 0xa, 0x39, 0x3, 0x3a, 0x5, 0x3a, 0x64e, 0xa, 0x3a, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
       0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x65a, 0xa, 0x3e, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 
       0x3, 0x48, 0x3, 0x48, 0x3, 0x49, 0x3, 0x49, 0x3, 0x4a, 0x3, 0x4a, 
       0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 
       0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 0x3, 0x50, 
       0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 0x3, 0x52, 
       0x3, 0x52, 0x3, 0x52, 0x5, 0x52, 0x688, 0xa, 0x52, 0x3, 0x53, 0x3, 
       0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
       0x54, 0x3, 0x54, 0x5, 0x54, 0x693, 0xa, 0x54, 0x3, 0x54, 0x4, 0x182, 
       0x3f7, 0x3, 0x50, 0x55, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
       0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
       0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 
       0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
       0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
       0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 
       0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0x2, 0x15, 
       0x5, 0x2, 0x3c, 0x3c, 0x47, 0x47, 0x54, 0x54, 0x4, 0x2, 0x31, 0x31, 
       0x44, 0x44, 0x4, 0x2, 0x7, 0x7, 0x6c, 0x6c, 0x3, 0x2, 0x85, 0x86, 
       0x4, 0x2, 0x1f, 0x1f, 0x40, 0x40, 0x4, 0x2, 0x24, 0x24, 0x3e, 0x3e, 
       0x7, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x53, 0x53, 0x7c, 0x7c, 0x7f, 0x7f, 
       0x4, 0x2, 0x9, 0x9, 0xe, 0xf, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0x10, 
       0x13, 0x3, 0x2, 0x14, 0x17, 0x4, 0x2, 0x8, 0x8, 0x18, 0x1a, 0x6, 
       0x2, 0x4f, 0x4f, 0x63, 0x63, 0x65, 0x65, 0x78, 0x78, 0x4, 0x2, 0x3d, 
       0x3d, 0x8d, 0x8d, 0x5, 0x2, 0x1b, 0x1b, 0x4a, 0x4a, 0x7f, 0x7f, 0x6, 
       0x2, 0x36, 0x38, 0x6a, 0x6a, 0x98, 0x98, 0x9a, 0x9b, 0x4, 0x2, 0xa, 
       0xc, 0x68, 0x68, 0x4, 0x2, 0x97, 0x97, 0x9a, 0x9a, 0x3, 0x2, 0x1b, 
       0x96, 0x2, 0x793, 0x2, 0xac, 0x3, 0x2, 0x2, 0x2, 0x4, 0xb1, 0x3, 
       0x2, 0x2, 0x2, 0x6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x8, 0xd1, 0x3, 0x2, 
       0x2, 0x2, 0xa, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xc, 0x105, 0x3, 0x2, 0x2, 
       0x2, 0xe, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x116, 0x3, 0x2, 0x2, 
       0x2, 0x12, 0x120, 0x3, 0x2, 0x2, 0x2, 0x14, 0x128, 0x3, 0x2, 0x2, 
       0x2, 0x16, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16c, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x195, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1da, 0x3, 0x2, 0x2, 
       0x2, 0x1e, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x20, 0x20b, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0x215, 0x3, 0x2, 0x2, 0x2, 0x24, 0x232, 0x3, 0x2, 0x2, 
       0x2, 0x26, 0x238, 0x3, 0x2, 0x2, 0x2, 0x28, 0x245, 0x3, 0x2, 0x2, 
       0x2, 0x2a, 0x252, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x25f, 0x3, 0x2, 0x2, 
       0x2, 0x2e, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x28d, 0x3, 0x2, 0x2, 
       0x2, 0x32, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e6, 0x3, 0x2, 0x2, 
       0x2, 0x36, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x2f9, 0x3, 0x2, 0x2, 
       0x2, 0x3a, 0x307, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x30b, 0x3, 0x2, 0x2, 
       0x2, 0x3e, 0x323, 0x3, 0x2, 0x2, 0x2, 0x40, 0x38c, 0x3, 0x2, 0x2, 
       0x2, 0x42, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x44, 0x3b2, 0x3, 0x2, 0x2, 
       0x2, 0x46, 0x3e8, 0x3, 0x2, 0x2, 0x2, 0x48, 0x3ea, 0x3, 0x2, 0x2, 
       0x2, 0x4a, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x407, 0x3, 0x2, 0x2, 
       0x2, 0x4e, 0x42f, 0x3, 0x2, 0x2, 0x2, 0x50, 0x47d, 0x3, 0x2, 0x2, 
       0x2, 0x52, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x509, 0x3, 0x2, 0x2, 
       0x2, 0x56, 0x513, 0x3, 0x2, 0x2, 0x2, 0x58, 0x51d, 0x3, 0x2, 0x2, 
       0x2, 0x5a, 0x545, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x554, 0x3, 0x2, 0x2, 
       0x2, 0x5e, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x569, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x64, 0x58a, 0x3, 0x2, 0x2, 
       0x2, 0x66, 0x5ce, 0x3, 0x2, 0x2, 0x2, 0x68, 0x5d0, 0x3, 0x2, 0x2, 
       0x2, 0x6a, 0x5e7, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x5f7, 0x3, 0x2, 0x2, 
       0x2, 0x6e, 0x643, 0x3, 0x2, 0x2, 0x2, 0x70, 0x64a, 0x3, 0x2, 0x2, 
       0x2, 0x72, 0x64d, 0x3, 0x2, 0x2, 0x2, 0x74, 0x651, 0x3, 0x2, 0x2, 
       0x2, 0x76, 0x653, 0x3, 0x2, 0x2, 0x2, 0x78, 0x655, 0x3, 0x2, 0x2, 
       0x2, 0x7a, 0x659, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x65b, 0x3, 0x2, 0x2, 
       0x2, 0x7e, 0x65d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x65f, 0x3, 0x2, 0x2, 
       0x2, 0x82, 0x661, 0x3, 0x2, 0x2, 0x2, 0x84, 0x663, 0x3, 0x2, 0x2, 
       0x2, 0x86, 0x665, 0x3, 0x2, 0x2, 0x2, 0x88, 0x667, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x669, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x66b, 0x3, 0x2, 0x2, 
       0x2, 0x8e, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x66f, 0x3, 0x2, 0x2, 
       0x2, 0x92, 0x671, 0x3, 0x2, 0x2, 0x2, 0x94, 0x673, 0x3, 0x2, 0x2, 
       0x2, 0x96, 0x675, 0x3, 0x2, 0x2, 0x2, 0x98, 0x677, 0x3, 0x2, 0x2, 
       0x2, 0x9a, 0x679, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x67b, 0x3, 0x2, 0x2, 
       0x2, 0x9e, 0x67d, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x67f, 0x3, 0x2, 0x2, 
       0x2, 0xa2, 0x687, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x689, 0x3, 0x2, 0x2, 
       0x2, 0xa6, 0x692, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xab, 0x5, 0x6, 0x4, 
       0x2, 0xa9, 0xab, 0x5, 0x4, 0x3, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 
       0xaa, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 
       0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 
       0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 
       0x2, 0x2, 0x3, 0xb0, 0x3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x9f, 
       0x2, 0x2, 0xb2, 0xb3, 0x8, 0x3, 0x1, 0x2, 0xb3, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0xb4, 0xb6, 0x7, 0x3, 0x2, 0x2, 0xb5, 0xb4, 0x3, 0x2, 0x2, 0x2, 
       0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 
       0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 
       0x3, 0x2, 0x2, 0x2, 0xba, 0xc3, 0x5, 0x8, 0x5, 0x2, 0xbb, 0xbd, 0x7, 
       0x3, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 
       0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 
       0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x8, 0x5, 0x2, 
       0xc1, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc3, 
       0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc9, 
       0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc8, 0x7, 
       0x3, 0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 
       0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 
       0x2, 0xca, 0x7, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 
       0xcc, 0xcf, 0x7, 0x49, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x74, 0x2, 0x2, 
       0xce, 0xd0, 0x7, 0x71, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 
       0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 
       0xcc, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xf1, 
       0x3, 0x2, 0x2, 0x2, 0xd3, 0xf2, 0x5, 0xa, 0x6, 0x2, 0xd4, 0xf2, 0x5, 
       0xc, 0x7, 0x2, 0xd5, 0xf2, 0x5, 0xe, 0x8, 0x2, 0xd6, 0xf2, 0x5, 0x10, 
       0x9, 0x2, 0xd7, 0xf2, 0x5, 0x12, 0xa, 0x2, 0xd8, 0xf2, 0x5, 0x14, 
       0xb, 0x2, 0xd9, 0xf2, 0x5, 0x16, 0xc, 0x2, 0xda, 0xf2, 0x5, 0x18, 
       0xd, 0x2, 0xdb, 0xf2, 0x5, 0x1a, 0xe, 0x2, 0xdc, 0xf2, 0x5, 0x1c, 
       0xf, 0x2, 0xdd, 0xf2, 0x5, 0x1e, 0x10, 0x2, 0xde, 0xf2, 0x5, 0x20, 
       0x11, 0x2, 0xdf, 0xf2, 0x5, 0x22, 0x12, 0x2, 0xe0, 0xf2, 0x5, 0x24, 
       0x13, 0x2, 0xe1, 0xf2, 0x5, 0x26, 0x14, 0x2, 0xe2, 0xf2, 0x5, 0x28, 
       0x15, 0x2, 0xe3, 0xf2, 0x5, 0x2a, 0x16, 0x2, 0xe4, 0xf2, 0x5, 0x2c, 
       0x17, 0x2, 0xe5, 0xf2, 0x5, 0x2e, 0x18, 0x2, 0xe6, 0xf2, 0x5, 0x30, 
       0x19, 0x2, 0xe7, 0xf2, 0x5, 0x32, 0x1a, 0x2, 0xe8, 0xf2, 0x5, 0x34, 
       0x1b, 0x2, 0xe9, 0xf2, 0x5, 0x36, 0x1c, 0x2, 0xea, 0xf2, 0x5, 0x38, 
       0x1d, 0x2, 0xeb, 0xf2, 0x5, 0x3a, 0x1e, 0x2, 0xec, 0xf2, 0x5, 0x3c, 
       0x1f, 0x2, 0xed, 0xf2, 0x5, 0x3e, 0x20, 0x2, 0xee, 0xf2, 0x5, 0x42, 
       0x22, 0x2, 0xef, 0xf2, 0x5, 0x44, 0x23, 0x2, 0xf0, 0xf2, 0x5, 0x46, 
       0x24, 0x2, 0xf1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd4, 0x3, 0x2, 
       0x2, 0x2, 0xf1, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd6, 0x3, 0x2, 0x2, 
       0x2, 0xf1, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd8, 0x3, 0x2, 0x2, 0x2, 
       0xf1, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xda, 0x3, 0x2, 0x2, 0x2, 0xf1, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdd, 
       0x3, 0x2, 0x2, 0x2, 0xf1, 0xde, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xdf, 0x3, 
       0x2, 0x2, 0x2, 0xf1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe1, 0x3, 0x2, 
       0x2, 0x2, 0xf1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe3, 0x3, 0x2, 0x2, 
       0x2, 0xf1, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe5, 0x3, 0x2, 0x2, 0x2, 
       0xf1, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf1, 
       0xe8, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xea, 
       0x3, 0x2, 0x2, 0x2, 0xf1, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xec, 0x3, 
       0x2, 0x2, 0x2, 0xf1, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 
       0x2, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 
       0x2, 0xf2, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x20, 0x2, 0x2, 
       0xf4, 0xf8, 0x7, 0x84, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x84, 0x43, 0x2, 
       0xf6, 0xf7, 0x7, 0x4, 0x2, 0x2, 0xf7, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf8, 
       0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
       0x3, 0x2, 0x2, 0x2, 0xfa, 0x103, 0x5, 0x8a, 0x46, 0x2, 0xfb, 0xfc, 
       0x7, 0x7b, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x88, 0x2, 0x2, 0xfd, 0x104, 
       0x5, 0x8e, 0x48, 0x2, 0xfe, 0x100, 0x7, 0x1d, 0x2, 0x2, 0xff, 0x101, 
       0x7, 0x30, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
       0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 
       0x5, 0x48, 0x25, 0x2, 0x103, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x103, 0xfe, 
       0x3, 0x2, 0x2, 0x2, 0x104, 0xb, 0x3, 0x2, 0x2, 0x2, 0x105, 0x10c, 
       0x7, 0x21, 0x2, 0x2, 0x106, 0x10d, 0x5, 0x84, 0x43, 0x2, 0x107, 0x10d, 
       0x5, 0x8c, 0x47, 0x2, 0x108, 0x109, 0x5, 0x84, 0x43, 0x2, 0x109, 
       0x10a, 0x7, 0x4, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x8c, 0x47, 0x2, 0x10b, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x106, 0x3, 0x2, 0x2, 0x2, 0x10c, 
       0x107, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10c, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x10e, 
       0x110, 0x7, 0x25, 0x2, 0x2, 0x10f, 0x111, 0x7, 0x39, 0x2, 0x2, 0x110, 
       0x10f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 
       0x112, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x5, 0x50, 0x29, 0x2, 0x113, 
       0x114, 0x7, 0x23, 0x2, 0x2, 0x114, 0x115, 0x5, 0x84, 0x43, 0x2, 0x115, 
       0xf, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 0x7, 0x28, 0x2, 0x2, 0x117, 
       0x119, 0x9, 0x2, 0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x118, 
       0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11a, 
       0x11c, 0x7, 0x89, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0xa4, 0x53, 0x2, 0x11c, 
       0x11b, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 
       0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11e, 
       0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x120, 
       0x125, 0x9, 0x3, 0x2, 0x2, 0x121, 0x123, 0x7, 0x89, 0x2, 0x2, 0x122, 
       0x124, 0x5, 0xa4, 0x53, 0x2, 0x123, 0x122, 0x3, 0x2, 0x2, 0x2, 0x123, 
       0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 0x126, 0x3, 0x2, 0x2, 0x2, 0x125, 
       0x121, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 
       0x13, 0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x5, 0x5a, 0x2e, 0x2, 0x128, 
       0x127, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 
       0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x134, 0x5, 0x6e, 0x38, 0x2, 0x12b, 
       0x12d, 0x7, 0x8b, 0x2, 0x2, 0x12c, 0x12e, 0x7, 0x1f, 0x2, 0x2, 0x12d, 
       0x12c, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12e, 
       0x132, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x132, 0x7, 0x5c, 0x2, 0x2, 0x130, 
       0x132, 0x7, 0x46, 0x2, 0x2, 0x131, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x131, 
       0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 
       0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 0x5, 0x6e, 0x38, 0x2, 0x134, 
       0x131, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 
       0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 
       0x142, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x7, 0x6f, 0x2, 0x2, 0x139, 
       0x13a, 0x7, 0x2a, 0x2, 0x2, 0x13a, 0x13f, 0x5, 0x5e, 0x30, 0x2, 0x13b, 
       0x13c, 0x7, 0x7, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x5e, 0x30, 0x2, 0x13d, 
       0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 
       0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
       0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 
       0x138, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 
       0x14a, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x7, 0x64, 0x2, 0x2, 0x145, 
       0x148, 0x5, 0x50, 0x29, 0x2, 0x146, 0x147, 0x9, 0x4, 0x2, 0x2, 0x147, 
       0x149, 0x5, 0x50, 0x29, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 
       0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14a, 
       0x144, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 
       0x15, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x7, 0x34, 0x2, 0x2, 0x14d, 
       0x14f, 0x7, 0x8c, 0x2, 0x2, 0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14e, 
       0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
       0x154, 0x7, 0x56, 0x2, 0x2, 0x151, 0x152, 0x7, 0x52, 0x2, 0x2, 0x152, 
       0x153, 0x7, 0x68, 0x2, 0x2, 0x153, 0x155, 0x7, 0x48, 0x2, 0x2, 0x154, 
       0x151, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 
       0x159, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x5, 0x84, 0x43, 0x2, 0x157, 
       0x158, 0x7, 0x4, 0x2, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x159, 
       0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15a, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 0x5, 0x96, 0x4c, 0x2, 0x15c, 
       0x15d, 0x7, 0x6d, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x8a, 0x46, 0x2, 0x15e, 
       0x15f, 0x7, 0x5, 0x2, 0x2, 0x15f, 0x164, 0x5, 0x56, 0x2c, 0x2, 0x160, 
       0x161, 0x7, 0x7, 0x2, 0x2, 0x161, 0x163, 0x5, 0x56, 0x2c, 0x2, 0x162, 
       0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 0x166, 0x3, 0x2, 0x2, 0x2, 0x164, 
       0x162, 0x3, 0x2, 0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 
       0x16a, 0x7, 0x6, 0x2, 0x2, 0x168, 0x169, 0x7, 0x94, 0x2, 0x2, 0x169, 
       0x16b, 0x5, 0x50, 0x29, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 
       0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x16c, 
       0x16e, 0x7, 0x34, 0x2, 0x2, 0x16d, 0x16f, 0x9, 0x5, 0x2, 0x2, 0x16e, 
       0x16d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 
       0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x174, 0x7, 0x84, 0x2, 0x2, 0x171, 
       0x172, 0x7, 0x52, 0x2, 0x2, 0x172, 0x173, 0x7, 0x68, 0x2, 0x2, 0x173, 
       0x175, 0x7, 0x48, 0x2, 0x2, 0x174, 0x171, 0x3, 0x2, 0x2, 0x2, 0x174, 
       0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x179, 0x3, 0x2, 0x2, 0x2, 0x176, 
       0x177, 0x5, 0x84, 0x43, 0x2, 0x177, 0x178, 0x7, 0x4, 0x2, 0x2, 0x178, 
       0x17a, 0x3, 0x2, 0x2, 0x2, 0x179, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 
       0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 
       0x193, 0x5, 0x8a, 0x46, 0x2, 0x17c, 0x17d, 0x7, 0x5, 0x2, 0x2, 0x17d, 
       0x182, 0x5, 0x48, 0x25, 0x2, 0x17e, 0x17f, 0x7, 0x7, 0x2, 0x2, 0x17f, 
       0x181, 0x5, 0x48, 0x25, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x182, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x183, 0x189, 0x3, 0x2, 0x2, 0x2, 0x184, 
       0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x7, 0x7, 0x2, 0x2, 0x186, 
       0x188, 0x5, 0x58, 0x2d, 0x2, 0x187, 0x185, 0x3, 0x2, 0x2, 0x2, 0x188, 
       0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18b, 
       0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18f, 0x7, 0x6, 0x2, 0x2, 0x18d, 
       0x18e, 0x7, 0x96, 0x2, 0x2, 0x18e, 0x190, 0x7, 0x97, 0x2, 0x2, 0x18f, 
       0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 
       0x194, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x23, 0x2, 0x2, 0x192, 
       0x194, 0x5, 0x3e, 0x20, 0x2, 0x193, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x193, 
       0x191, 0x3, 0x2, 0x2, 0x2, 0x194, 0x19, 0x3, 0x2, 0x2, 0x2, 0x195, 
       0x197, 0x7, 0x34, 0x2, 0x2, 0x196, 0x198, 0x9, 0x5, 0x2, 0x2, 0x197, 
       0x196, 0x3, 0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 
       0x199, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19d, 0x7, 0x8a, 0x2, 0x2, 0x19a, 
       0x19b, 0x7, 0x52, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x68, 0x2, 0x2, 0x19c, 
       0x19e, 0x7, 0x48, 0x2, 0x2, 0x19d, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19d, 
       0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x19f, 
       0x1a0, 0x5, 0x84, 0x43, 0x2, 0x1a0, 0x1a1, 0x7, 0x4, 0x2, 0x2, 0x1a1, 
       0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1a2, 
       0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a4, 
       0x1a9, 0x5, 0x98, 0x4d, 0x2, 0x1a5, 0x1aa, 0x7, 0x27, 0x2, 0x2, 0x1a6, 
       0x1aa, 0x7, 0x1e, 0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x5b, 0x2, 0x2, 0x1a8, 
       0x1aa, 0x7, 0x6b, 0x2, 0x2, 0x1a9, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1ab, 
       0x1ba, 0x7, 0x3d, 0x2, 0x2, 0x1ac, 0x1ba, 0x7, 0x5a, 0x2, 0x2, 0x1ad, 
       0x1b7, 0x7, 0x8d, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x6b, 0x2, 0x2, 0x1af, 
       0x1b4, 0x5, 0x90, 0x49, 0x2, 0x1b0, 0x1b1, 0x7, 0x7, 0x2, 0x2, 0x1b1, 
       0x1b3, 0x5, 0x90, 0x49, 0x2, 0x1b2, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 
       0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 
       0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b6, 
       0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1b7, 
       0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1b9, 
       0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1b9, 
       0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bb, 
       0x1bf, 0x7, 0x6d, 0x2, 0x2, 0x1bc, 0x1bd, 0x5, 0x84, 0x43, 0x2, 0x1bd, 
       0x1be, 0x7, 0x4, 0x2, 0x2, 0x1be, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1bf, 
       0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c0, 
       0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c5, 0x5, 0x8a, 0x46, 0x2, 0x1c2, 
       0x1c3, 0x7, 0x4b, 0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x42, 0x2, 0x2, 0x1c4, 
       0x1c6, 0x7, 0x80, 0x2, 0x2, 0x1c5, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
       0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
       0x1c8, 0x7, 0x93, 0x2, 0x2, 0x1c8, 0x1ca, 0x5, 0x50, 0x29, 0x2, 0x1c9, 
       0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 
       0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1d4, 0x7, 0x28, 0x2, 0x2, 0x1cc, 
       0x1d1, 0x5, 0x42, 0x22, 0x2, 0x1cd, 0x1d1, 0x5, 0x30, 0x19, 0x2, 
       0x1ce, 0x1d1, 0x5, 0x20, 0x11, 0x2, 0x1cf, 0x1d1, 0x5, 0x3e, 0x20, 
       0x2, 0x1d0, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cd, 0x3, 0x2, 0x2, 
       0x2, 0x1d0, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 
       0x2, 0x1d1, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d3, 0x7, 0x3, 0x2, 
       0x2, 0x1d3, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d0, 0x3, 0x2, 0x2, 
       0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d4, 0x3, 0x2, 0x2, 
       0x2, 0x1d6, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 
       0x2, 0x1d8, 0x1d9, 0x7, 0x44, 0x2, 0x2, 0x1d9, 0x1b, 0x3, 0x2, 0x2, 
       0x2, 0x1da, 0x1dc, 0x7, 0x34, 0x2, 0x2, 0x1db, 0x1dd, 0x9, 0x5, 0x2, 
       0x2, 0x1dc, 0x1db, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x3, 0x2, 0x2, 
       0x2, 0x1dd, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1e2, 0x7, 0x91, 0x2, 
       0x2, 0x1df, 0x1e0, 0x7, 0x52, 0x2, 0x2, 0x1e0, 0x1e1, 0x7, 0x68, 
       0x2, 0x2, 0x1e1, 0x1e3, 0x7, 0x48, 0x2, 0x2, 0x1e2, 0x1df, 0x3, 0x2, 
       0x2, 0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e7, 0x3, 0x2, 
       0x2, 0x2, 0x1e4, 0x1e5, 0x5, 0x84, 0x43, 0x2, 0x1e5, 0x1e6, 0x7, 
       0x4, 0x2, 0x2, 0x1e6, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e4, 0x3, 
       0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e9, 0x3, 
       0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x9a, 0x4e, 0x2, 0x1ea, 0x1eb, 
       0x7, 0x23, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x3e, 0x20, 0x2, 0x1ec, 0x1d, 
       0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x34, 0x2, 0x2, 0x1ee, 0x1ef, 
       0x7, 0x92, 0x2, 0x2, 0x1ef, 0x1f3, 0x7, 0x84, 0x2, 0x2, 0x1f0, 0x1f1, 
       0x7, 0x52, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x68, 0x2, 0x2, 0x1f2, 0x1f4, 
       0x7, 0x48, 0x2, 0x2, 0x1f3, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 
       0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 
       0x5, 0x84, 0x43, 0x2, 0x1f6, 0x1f7, 0x7, 0x4, 0x2, 0x2, 0x1f7, 0x1f9, 
       0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f9, 
       0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 
       0x5, 0x8a, 0x46, 0x2, 0x1fb, 0x1fc, 0x7, 0x8e, 0x2, 0x2, 0x1fc, 0x208, 
       0x5, 0x9c, 0x4f, 0x2, 0x1fd, 0x1fe, 0x7, 0x5, 0x2, 0x2, 0x1fe, 0x203, 
       0x5, 0x7a, 0x3e, 0x2, 0x1ff, 0x200, 0x7, 0x7, 0x2, 0x2, 0x200, 0x202, 
       0x5, 0x7a, 0x3e, 0x2, 0x201, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x202, 0x205, 
       0x3, 0x2, 0x2, 0x2, 0x203, 0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 
       0x3, 0x2, 0x2, 0x2, 0x204, 0x206, 0x3, 0x2, 0x2, 0x2, 0x205, 0x203, 
       0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0x7, 0x6, 0x2, 0x2, 0x207, 0x209, 
       0x3, 0x2, 0x2, 0x2, 0x208, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x208, 0x209, 
       0x3, 0x2, 0x2, 0x2, 0x209, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20c, 
       0x5, 0x5a, 0x2e, 0x2, 0x20b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20c, 
       0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 
       0x7, 0x3d, 0x2, 0x2, 0x20e, 0x20f, 0x7, 0x4d, 0x2, 0x2, 0x20f, 0x212, 
       0x5, 0x5c, 0x2f, 0x2, 0x210, 0x211, 0x7, 0x94, 0x2, 0x2, 0x211, 0x213, 
       0x5, 0x50, 0x29, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 
       0x3, 0x2, 0x2, 0x2, 0x213, 0x21, 0x3, 0x2, 0x2, 0x2, 0x214, 0x216, 
       0x5, 0x5a, 0x2e, 0x2, 0x215, 0x214, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 
       0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 
       0x7, 0x3d, 0x2, 0x2, 0x218, 0x219, 0x7, 0x4d, 0x2, 0x2, 0x219, 0x21c, 
       0x5, 0x5c, 0x2f, 0x2, 0x21a, 0x21b, 0x7, 0x94, 0x2, 0x2, 0x21b, 0x21d, 
       0x5, 0x50, 0x29, 0x2, 0x21c, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21d, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x230, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 
       0x7, 0x6f, 0x2, 0x2, 0x21f, 0x220, 0x7, 0x2a, 0x2, 0x2, 0x220, 0x225, 
       0x5, 0x5e, 0x30, 0x2, 0x221, 0x222, 0x7, 0x7, 0x2, 0x2, 0x222, 0x224, 
       0x5, 0x5e, 0x30, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 0x224, 0x227, 
       0x3, 0x2, 0x2, 0x2, 0x225, 0x223, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 
       0x3, 0x2, 0x2, 0x2, 0x226, 0x229, 0x3, 0x2, 0x2, 0x2, 0x227, 0x225, 
       0x3, 0x2, 0x2, 0x2, 0x228, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 
       0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 
       0x7, 0x64, 0x2, 0x2, 0x22b, 0x22e, 0x5, 0x50, 0x29, 0x2, 0x22c, 0x22d, 
       0x9, 0x4, 0x2, 0x2, 0x22d, 0x22f, 0x5, 0x50, 0x29, 0x2, 0x22e, 0x22c, 
       0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x231, 
       0x3, 0x2, 0x2, 0x2, 0x230, 0x228, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 
       0x3, 0x2, 0x2, 0x2, 0x231, 0x23, 0x3, 0x2, 0x2, 0x2, 0x232, 0x234, 
       0x7, 0x3f, 0x2, 0x2, 0x233, 0x235, 0x7, 0x39, 0x2, 0x2, 0x234, 0x233, 
       0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 0x235, 0x236, 
       0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x5, 0x84, 0x43, 0x2, 0x237, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x238, 0x239, 0x7, 0x41, 0x2, 0x2, 0x239, 0x23c, 
       0x7, 0x56, 0x2, 0x2, 0x23a, 0x23b, 0x7, 0x52, 0x2, 0x2, 0x23b, 0x23d, 
       0x7, 0x48, 0x2, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 
       0x3, 0x2, 0x2, 0x2, 0x23d, 0x241, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 
       0x5, 0x84, 0x43, 0x2, 0x23f, 0x240, 0x7, 0x4, 0x2, 0x2, 0x240, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x241, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 
       0x3, 0x2, 0x2, 0x2, 0x242, 0x243, 0x3, 0x2, 0x2, 0x2, 0x243, 0x244, 
       0x5, 0x96, 0x4c, 0x2, 0x244, 0x27, 0x3, 0x2, 0x2, 0x2, 0x245, 0x246, 
       0x7, 0x41, 0x2, 0x2, 0x246, 0x249, 0x7, 0x84, 0x2, 0x2, 0x247, 0x248, 
       0x7, 0x52, 0x2, 0x2, 0x248, 0x24a, 0x7, 0x48, 0x2, 0x2, 0x249, 0x247, 
       0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x24e, 
       0x3, 0x2, 0x2, 0x2, 0x24b, 0x24c, 0x5, 0x84, 0x43, 0x2, 0x24c, 0x24d, 
       0x7, 0x4, 0x2, 0x2, 0x24d, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24b, 
       0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x250, 
       0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x5, 0x8a, 0x46, 0x2, 0x251, 0x29, 
       0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 0x7, 0x41, 0x2, 0x2, 0x253, 0x256, 
       0x7, 0x8a, 0x2, 0x2, 0x254, 0x255, 0x7, 0x52, 0x2, 0x2, 0x255, 0x257, 
       0x7, 0x48, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 
       0x3, 0x2, 0x2, 0x2, 0x257, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x258, 0x259, 
       0x5, 0x84, 0x43, 0x2, 0x259, 0x25a, 0x7, 0x4, 0x2, 0x2, 0x25a, 0x25c, 
       0x3, 0x2, 0x2, 0x2, 0x25b, 0x258, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25c, 
       0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 
       0x5, 0x98, 0x4d, 0x2, 0x25e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x260, 
       0x7, 0x41, 0x2, 0x2, 0x260, 0x263, 0x7, 0x91, 0x2, 0x2, 0x261, 0x262, 
       0x7, 0x52, 0x2, 0x2, 0x262, 0x264, 0x7, 0x48, 0x2, 0x2, 0x263, 0x261, 
       0x3, 0x2, 0x2, 0x2, 0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x268, 
       0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x5, 0x84, 0x43, 0x2, 0x266, 0x267, 
       0x7, 0x4, 0x2, 0x2, 0x267, 0x269, 0x3, 0x2, 0x2, 0x2, 0x268, 0x265, 
       0x3, 0x2, 0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 
       0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x5, 0x9a, 0x4e, 0x2, 0x26b, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x26c, 0x26e, 0x5, 0x5a, 0x2e, 0x2, 0x26d, 0x26c, 
       0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x26f, 
       0x3, 0x2, 0x2, 0x2, 0x26f, 0x275, 0x5, 0x6e, 0x38, 0x2, 0x270, 0x271, 
       0x5, 0x70, 0x39, 0x2, 0x271, 0x272, 0x5, 0x6e, 0x38, 0x2, 0x272, 
       0x274, 0x3, 0x2, 0x2, 0x2, 0x273, 0x270, 0x3, 0x2, 0x2, 0x2, 0x274, 
       0x277, 0x3, 0x2, 0x2, 0x2, 0x275, 0x273, 0x3, 0x2, 0x2, 0x2, 0x275, 
       0x276, 0x3, 0x2, 0x2, 0x2, 0x276, 0x282, 0x3, 0x2, 0x2, 0x2, 0x277, 
       0x275, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x7, 0x6f, 0x2, 0x2, 0x279, 
       0x27a, 0x7, 0x2a, 0x2, 0x2, 0x27a, 0x27f, 0x5, 0x5e, 0x30, 0x2, 0x27b, 
       0x27c, 0x7, 0x7, 0x2, 0x2, 0x27c, 0x27e, 0x5, 0x5e, 0x30, 0x2, 0x27d, 
       0x27b, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x281, 0x3, 0x2, 0x2, 0x2, 0x27f, 
       0x27d, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x283, 0x3, 0x2, 0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x282, 
       0x278, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x3, 0x2, 0x2, 0x2, 0x283, 
       0x28a, 0x3, 0x2, 0x2, 0x2, 0x284, 0x285, 0x7, 0x64, 0x2, 0x2, 0x285, 
       0x288, 0x5, 0x50, 0x29, 0x2, 0x286, 0x287, 0x9, 0x4, 0x2, 0x2, 0x287, 
       0x289, 0x5, 0x50, 0x29, 0x2, 0x288, 0x286, 0x3, 0x2, 0x2, 0x2, 0x288, 
       0x289, 0x3, 0x2, 0x2, 0x2, 0x289, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28a, 
       0x284, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28b, 
       0x2f, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28e, 0x5, 0x5a, 0x2e, 0x2, 0x28d, 
       0x28c, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x28e, 
       0x2a0, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x2a1, 0x7, 0x5a, 0x2, 0x2, 0x290, 
       0x2a1, 0x7, 0x7c, 0x2, 0x2, 0x291, 0x292, 0x7, 0x5a, 0x2, 0x2, 0x292, 
       0x293, 0x7, 0x6e, 0x2, 0x2, 0x293, 0x2a1, 0x7, 0x7c, 0x2, 0x2, 0x294, 
       0x295, 0x7, 0x5a, 0x2, 0x2, 0x295, 0x296, 0x7, 0x6e, 0x2, 0x2, 0x296, 
       0x2a1, 0x7, 0x7f, 0x2, 0x2, 0x297, 0x298, 0x7, 0x5a, 0x2, 0x2, 0x298, 
       0x299, 0x7, 0x6e, 0x2, 0x2, 0x299, 0x2a1, 0x7, 0x1b, 0x2, 0x2, 0x29a, 
       0x29b, 0x7, 0x5a, 0x2, 0x2, 0x29b, 0x29c, 0x7, 0x6e, 0x2, 0x2, 0x29c, 
       0x2a1, 0x7, 0x4a, 0x2, 0x2, 0x29d, 0x29e, 0x7, 0x5a, 0x2, 0x2, 0x29e, 
       0x29f, 0x7, 0x6e, 0x2, 0x2, 0x29f, 0x2a1, 0x7, 0x53, 0x2, 0x2, 0x2a0, 
       0x28f, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x290, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
       0x291, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x294, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
       0x297, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
       0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
       0x2a6, 0x7, 0x5d, 0x2, 0x2, 0x2a3, 0x2a4, 0x5, 0x84, 0x43, 0x2, 0x2a4, 
       0x2a5, 0x7, 0x4, 0x2, 0x2, 0x2a5, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
       0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2b4, 0x5, 0x8a, 0x46, 0x2, 0x2a9, 
       0x2aa, 0x7, 0x5, 0x2, 0x2, 0x2aa, 0x2af, 0x5, 0x90, 0x49, 0x2, 0x2ab, 
       0x2ac, 0x7, 0x7, 0x2, 0x2, 0x2ac, 0x2ae, 0x5, 0x90, 0x49, 0x2, 0x2ad, 
       0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2af, 
       0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b0, 
       0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2af, 0x3, 0x2, 0x2, 0x2, 0x2b2, 
       0x2b3, 0x7, 0x6, 0x2, 0x2, 0x2b3, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b4, 
       0x2a9, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b5, 
       0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b7, 0x7, 0x90, 0x2, 0x2, 0x2b7, 
       0x2b8, 0x7, 0x5, 0x2, 0x2, 0x2b8, 0x2bd, 0x5, 0x50, 0x29, 0x2, 0x2b9, 
       0x2ba, 0x7, 0x7, 0x2, 0x2, 0x2ba, 0x2bc, 0x5, 0x50, 0x29, 0x2, 0x2bb, 
       0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
       0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 
       0x2c0, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c0, 
       0x2cf, 0x7, 0x6, 0x2, 0x2, 0x2c1, 0x2c2, 0x7, 0x7, 0x2, 0x2, 0x2c2, 
       0x2c3, 0x7, 0x5, 0x2, 0x2, 0x2c3, 0x2c8, 0x5, 0x50, 0x29, 0x2, 0x2c4, 
       0x2c5, 0x7, 0x7, 0x2, 0x2, 0x2c5, 0x2c7, 0x5, 0x50, 0x29, 0x2, 0x2c6, 
       0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
       0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
       0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cb, 
       0x2cc, 0x7, 0x6, 0x2, 0x2, 0x2cc, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2cd, 
       0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
       0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
       0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d2, 
       0x2d6, 0x5, 0x3e, 0x20, 0x2, 0x2d3, 0x2d4, 0x7, 0x3a, 0x2, 0x2, 0x2d4, 
       0x2d6, 0x7, 0x90, 0x2, 0x2, 0x2d5, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2d5, 
       0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2db, 0x7, 0x72, 0x2, 0x2, 0x2d8, 
       0x2d9, 0x5, 0x84, 0x43, 0x2, 0x2d9, 0x2da, 0x7, 0x4, 0x2, 0x2, 0x2da, 
       0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2db, 
       0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2dd, 
       0x2e4, 0x5, 0x9e, 0x50, 0x2, 0x2de, 0x2df, 0x7, 0x8, 0x2, 0x2, 0x2df, 
       0x2e5, 0x5, 0x60, 0x31, 0x2, 0x2e0, 0x2e1, 0x7, 0x5, 0x2, 0x2, 0x2e1, 
       0x2e2, 0x5, 0x60, 0x31, 0x2, 0x2e2, 0x2e3, 0x7, 0x6, 0x2, 0x2, 0x2e3, 
       0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2e4, 
       0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e5, 
       0x33, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2f1, 0x7, 0x79, 0x2, 0x2, 0x2e7, 
       0x2f2, 0x5, 0x92, 0x4a, 0x2, 0x2e8, 0x2e9, 0x5, 0x84, 0x43, 0x2, 
       0x2e9, 0x2ea, 0x7, 0x4, 0x2, 0x2, 0x2ea, 0x2ec, 0x3, 0x2, 0x2, 0x2, 
       0x2eb, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ec, 0x3, 0x2, 0x2, 0x2, 
       0x2ec, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2f0, 0x5, 0x8a, 0x46, 
       0x2, 0x2ee, 0x2f0, 0x5, 0x96, 0x4c, 0x2, 0x2ef, 0x2ed, 0x3, 0x2, 
       0x2, 0x2, 0x2ef, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f2, 0x3, 0x2, 
       0x2, 0x2, 0x2f1, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2eb, 0x3, 0x2, 
       0x2, 0x2, 0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0x2f3, 0x2f5, 0x7, 0x7a, 0x2, 0x2, 0x2f4, 0x2f6, 0x7, 0x81, 
       0x2, 0x2, 0x2f5, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f6, 0x3, 0x2, 
       0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x5, 0xa0, 
       0x51, 0x2, 0x2f8, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fe, 0x7, 0x7f, 
       0x2, 0x2, 0x2fa, 0x2fc, 0x7, 0x89, 0x2, 0x2, 0x2fb, 0x2fd, 0x5, 0xa4, 
       0x53, 0x2, 0x2fc, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x3, 0x2, 
       0x2, 0x2, 0x2fd, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fa, 0x3, 0x2, 
       0x2, 0x2, 0x2fe, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x305, 0x3, 0x2, 
       0x2, 0x2, 0x300, 0x302, 0x7, 0x88, 0x2, 0x2, 0x301, 0x303, 0x7, 0x81, 
       0x2, 0x2, 0x302, 0x301, 0x3, 0x2, 0x2, 0x2, 0x302, 0x303, 0x3, 0x2, 
       0x2, 0x2, 0x303, 0x304, 0x3, 0x2, 0x2, 0x2, 0x304, 0x306, 0x5, 0xa0, 
       0x51, 0x2, 0x305, 0x300, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 0x3, 0x2, 
       0x2, 0x2, 0x306, 0x39, 0x3, 0x2, 0x2, 0x2, 0x307, 0x308, 0x7, 0x81, 
       0x2, 0x2, 0x308, 0x309, 0x5, 0xa0, 0x51, 0x2, 0x309, 0x3b, 0x3, 0x2, 
       0x2, 0x2, 0x30a, 0x30c, 0x5, 0x5a, 0x2e, 0x2, 0x30b, 0x30a, 0x3, 
       0x2, 0x2, 0x2, 0x30b, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30d, 0x3, 
       0x2, 0x2, 0x2, 0x30d, 0x318, 0x5, 0x6e, 0x38, 0x2, 0x30e, 0x30f, 
       0x7, 0x6f, 0x2, 0x2, 0x30f, 0x310, 0x7, 0x2a, 0x2, 0x2, 0x310, 0x315, 
       0x5, 0x5e, 0x30, 0x2, 0x311, 0x312, 0x7, 0x7, 0x2, 0x2, 0x312, 0x314, 
       0x5, 0x5e, 0x30, 0x2, 0x313, 0x311, 0x3, 0x2, 0x2, 0x2, 0x314, 0x317, 
       0x3, 0x2, 0x2, 0x2, 0x315, 0x313, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 
       0x3, 0x2, 0x2, 0x2, 0x316, 0x319, 0x3, 0x2, 0x2, 0x2, 0x317, 0x315, 
       0x3, 0x2, 0x2, 0x2, 0x318, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 
       0x3, 0x2, 0x2, 0x2, 0x319, 0x320, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31b, 
       0x7, 0x64, 0x2, 0x2, 0x31b, 0x31e, 0x5, 0x50, 0x29, 0x2, 0x31c, 0x31d, 
       0x9, 0x4, 0x2, 0x2, 0x31d, 0x31f, 0x5, 0x50, 0x29, 0x2, 0x31e, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x321, 
       0x3, 0x2, 0x2, 0x2, 0x320, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 
       0x3, 0x2, 0x2, 0x2, 0x321, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x322, 0x324, 
       0x5, 0x5a, 0x2e, 0x2, 0x323, 0x322, 0x3, 0x2, 0x2, 0x2, 0x323, 0x324, 
       0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 0x3, 0x2, 0x2, 0x2, 0x325, 0x32b, 
       0x5, 0x40, 0x21, 0x2, 0x326, 0x327, 0x5, 0x70, 0x39, 0x2, 0x327, 
       0x328, 0x5, 0x40, 0x21, 0x2, 0x328, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x329, 
       0x326, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32b, 
       0x329, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32c, 
       0x338, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32e, 
       0x32f, 0x7, 0x6f, 0x2, 0x2, 0x32f, 0x330, 0x7, 0x2a, 0x2, 0x2, 0x330, 
       0x335, 0x5, 0x5e, 0x30, 0x2, 0x331, 0x332, 0x7, 0x7, 0x2, 0x2, 0x332, 
       0x334, 0x5, 0x5e, 0x30, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x337, 0x3, 0x2, 0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x336, 0x339, 0x3, 0x2, 0x2, 0x2, 0x337, 
       0x335, 0x3, 0x2, 0x2, 0x2, 0x338, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x338, 
       0x339, 0x3, 0x2, 0x2, 0x2, 0x339, 0x340, 0x3, 0x2, 0x2, 0x2, 0x33a, 
       0x33b, 0x7, 0x64, 0x2, 0x2, 0x33b, 0x33e, 0x5, 0x50, 0x29, 0x2, 0x33c, 
       0x33d, 0x9, 0x4, 0x2, 0x2, 0x33d, 0x33f, 0x5, 0x50, 0x29, 0x2, 0x33e, 
       0x33c, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x3, 0x2, 0x2, 0x2, 0x33f, 
       0x341, 0x3, 0x2, 0x2, 0x2, 0x340, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x340, 
       0x341, 0x3, 0x2, 0x2, 0x2, 0x341, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x342, 
       0x344, 0x7, 0x82, 0x2, 0x2, 0x343, 0x345, 0x9, 0x6, 0x2, 0x2, 0x344, 
       0x343, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x3, 0x2, 0x2, 0x2, 0x345, 
       0x346, 0x3, 0x2, 0x2, 0x2, 0x346, 0x34b, 0x5, 0x64, 0x33, 0x2, 0x347, 
       0x348, 0x7, 0x7, 0x2, 0x2, 0x348, 0x34a, 0x5, 0x64, 0x33, 0x2, 0x349, 
       0x347, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34b, 
       0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 
       0x35a, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34e, 
       0x358, 0x7, 0x4d, 0x2, 0x2, 0x34f, 0x354, 0x5, 0x66, 0x34, 0x2, 0x350, 
       0x351, 0x7, 0x7, 0x2, 0x2, 0x351, 0x353, 0x5, 0x66, 0x34, 0x2, 0x352, 
       0x350, 0x3, 0x2, 0x2, 0x2, 0x353, 0x356, 0x3, 0x2, 0x2, 0x2, 0x354, 
       0x352, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 0x3, 0x2, 0x2, 0x2, 0x355, 
       0x359, 0x3, 0x2, 0x2, 0x2, 0x356, 0x354, 0x3, 0x2, 0x2, 0x2, 0x357, 
       0x359, 0x5, 0x68, 0x35, 0x2, 0x358, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x358, 
       0x357, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35a, 
       0x34e, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35b, 
       0x35e, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x7, 0x94, 0x2, 0x2, 0x35d, 
       0x35f, 0x5, 0x50, 0x29, 0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 
       0x35f, 0x3, 0x2, 0x2, 0x2, 0x35f, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x360, 
       0x361, 0x7, 0x50, 0x2, 0x2, 0x361, 0x362, 0x7, 0x2a, 0x2, 0x2, 0x362, 
       0x367, 0x5, 0x50, 0x29, 0x2, 0x363, 0x364, 0x7, 0x7, 0x2, 0x2, 0x364, 
       0x366, 0x5, 0x50, 0x29, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 0x2, 0x366, 
       0x369, 0x3, 0x2, 0x2, 0x2, 0x367, 0x365, 0x3, 0x2, 0x2, 0x2, 0x367, 
       0x368, 0x3, 0x2, 0x2, 0x2, 0x368, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x369, 
       0x367, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x36b, 0x7, 0x51, 0x2, 0x2, 0x36b, 
       0x36d, 0x5, 0x50, 0x29, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x36c, 
       0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36e, 
       0x360, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36f, 
       0x38d, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x7, 0x90, 0x2, 0x2, 0x371, 
       0x372, 0x7, 0x5, 0x2, 0x2, 0x372, 0x377, 0x5, 0x50, 0x29, 0x2, 0x373, 
       0x374, 0x7, 0x7, 0x2, 0x2, 0x374, 0x376, 0x5, 0x50, 0x29, 0x2, 0x375, 
       0x373, 0x3, 0x2, 0x2, 0x2, 0x376, 0x379, 0x3, 0x2, 0x2, 0x2, 0x377, 
       0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 0x2, 0x2, 0x378, 
       0x37a, 0x3, 0x2, 0x2, 0x2, 0x379, 0x377, 0x3, 0x2, 0x2, 0x2, 0x37a, 
       0x389, 0x7, 0x6, 0x2, 0x2, 0x37b, 0x37c, 0x7, 0x7, 0x2, 0x2, 0x37c, 
       0x37d, 0x7, 0x5, 0x2, 0x2, 0x37d, 0x382, 0x5, 0x50, 0x29, 0x2, 0x37e, 
       0x37f, 0x7, 0x7, 0x2, 0x2, 0x37f, 0x381, 0x5, 0x50, 0x29, 0x2, 0x380, 
       0x37e, 0x3, 0x2, 0x2, 0x2, 0x381, 0x384, 0x3, 0x2, 0x2, 0x2, 0x382, 
       0x380, 0x3, 0x2, 0x2, 0x2, 0x382, 0x383, 0x3, 0x2, 0x2, 0x2, 0x383, 
       0x385, 0x3, 0x2, 0x2, 0x2, 0x384, 0x382, 0x3, 0x2, 0x2, 0x2, 0x385, 
       0x386, 0x7, 0x6, 0x2, 0x2, 0x386, 0x388, 0x3, 0x2, 0x2, 0x2, 0x387, 
       0x37b, 0x3, 0x2, 0x2, 0x2, 0x388, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x389, 
       0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x38a, 
       0x38d, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x389, 0x3, 0x2, 0x2, 0x2, 0x38c, 
       0x342, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x370, 0x3, 0x2, 0x2, 0x2, 0x38d, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x38e, 0x390, 0x5, 0x5a, 0x2e, 0x2, 0x38f, 
       0x38e, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 0x390, 
       0x391, 0x3, 0x2, 0x2, 0x2, 0x391, 0x39c, 0x7, 0x8d, 0x2, 0x2, 0x392, 
       0x393, 0x7, 0x6e, 0x2, 0x2, 0x393, 0x39d, 0x7, 0x7f, 0x2, 0x2, 0x394, 
       0x395, 0x7, 0x6e, 0x2, 0x2, 0x395, 0x39d, 0x7, 0x1b, 0x2, 0x2, 0x396, 
       0x397, 0x7, 0x6e, 0x2, 0x2, 0x397, 0x39d, 0x7, 0x7c, 0x2, 0x2, 0x398, 
       0x399, 0x7, 0x6e, 0x2, 0x2, 0x399, 0x39d, 0x7, 0x4a, 0x2, 0x2, 0x39a, 
       0x39b, 0x7, 0x6e, 0x2, 0x2, 0x39b, 0x39d, 0x7, 0x53, 0x2, 0x2, 0x39c, 
       0x392, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x394, 0x3, 0x2, 0x2, 0x2, 0x39c, 
       0x396, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x398, 0x3, 0x2, 0x2, 0x2, 0x39c, 
       0x39a, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x39d, 
       0x39e, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x39f, 0x5, 0x5c, 0x2f, 0x2, 0x39f, 
       0x3a0, 0x7, 0x83, 0x2, 0x2, 0x3a0, 0x3a1, 0x5, 0x90, 0x49, 0x2, 0x3a1, 
       0x3a2, 0x7, 0x8, 0x2, 0x2, 0x3a2, 0x3aa, 0x5, 0x50, 0x29, 0x2, 0x3a3, 
       0x3a4, 0x7, 0x7, 0x2, 0x2, 0x3a4, 0x3a5, 0x5, 0x90, 0x49, 0x2, 0x3a5, 
       0x3a6, 0x7, 0x8, 0x2, 0x2, 0x3a6, 0x3a7, 0x5, 0x50, 0x29, 0x2, 0x3a7, 
       0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a9, 
       0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3aa, 
       0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3ac, 
       0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3ae, 0x7, 0x94, 0x2, 0x2, 0x3ae, 
       0x3b0, 0x5, 0x50, 0x29, 0x2, 0x3af, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3af, 
       0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3b1, 
       0x3b3, 0x5, 0x5a, 0x2e, 0x2, 0x3b2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b2, 
       0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b4, 
       0x3bf, 0x7, 0x8d, 0x2, 0x2, 0x3b5, 0x3b6, 0x7, 0x6e, 0x2, 0x2, 0x3b6, 
       0x3c0, 0x7, 0x7f, 0x2, 0x2, 0x3b7, 0x3b8, 0x7, 0x6e, 0x2, 0x2, 0x3b8, 
       0x3c0, 0x7, 0x1b, 0x2, 0x2, 0x3b9, 0x3ba, 0x7, 0x6e, 0x2, 0x2, 0x3ba, 
       0x3c0, 0x7, 0x7c, 0x2, 0x2, 0x3bb, 0x3bc, 0x7, 0x6e, 0x2, 0x2, 0x3bc, 
       0x3c0, 0x7, 0x4a, 0x2, 0x2, 0x3bd, 0x3be, 0x7, 0x6e, 0x2, 0x2, 0x3be, 
       0x3c0, 0x7, 0x53, 0x2, 0x2, 0x3bf, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3bf, 
       0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3bf, 
       0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bf, 
       0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c1, 
       0x3c2, 0x5, 0x5c, 0x2f, 0x2, 0x3c2, 0x3c3, 0x7, 0x83, 0x2, 0x2, 0x3c3, 
       0x3c4, 0x5, 0x90, 0x49, 0x2, 0x3c4, 0x3c5, 0x7, 0x8, 0x2, 0x2, 0x3c5, 
       0x3cd, 0x5, 0x50, 0x29, 0x2, 0x3c6, 0x3c7, 0x7, 0x7, 0x2, 0x2, 0x3c7, 
       0x3c8, 0x5, 0x90, 0x49, 0x2, 0x3c8, 0x3c9, 0x7, 0x8, 0x2, 0x2, 0x3c9, 
       0x3ca, 0x5, 0x50, 0x29, 0x2, 0x3ca, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cb, 
       0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3cd, 
       0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
       0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3d0, 
       0x3d1, 0x7, 0x94, 0x2, 0x2, 0x3d1, 0x3d3, 0x5, 0x50, 0x29, 0x2, 0x3d2, 
       0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d3, 
       0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d5, 0x7, 0x6f, 0x2, 0x2, 0x3d5, 
       0x3d6, 0x7, 0x2a, 0x2, 0x2, 0x3d6, 0x3db, 0x5, 0x5e, 0x30, 0x2, 0x3d7, 
       0x3d8, 0x7, 0x7, 0x2, 0x2, 0x3d8, 0x3da, 0x5, 0x5e, 0x30, 0x2, 0x3d9, 
       0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3db, 
       0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
       0x3df, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3de, 
       0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3df, 0x3, 0x2, 0x2, 0x2, 0x3df, 
       0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x7, 0x64, 0x2, 0x2, 0x3e1, 
       0x3e4, 0x5, 0x50, 0x29, 0x2, 0x3e2, 0x3e3, 0x9, 0x4, 0x2, 0x2, 0x3e3, 
       0x3e5, 0x5, 0x50, 0x29, 0x2, 0x3e4, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e4, 
       0x3e5, 0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e6, 
       0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3e7, 0x3, 0x2, 0x2, 0x2, 0x3e7, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3e9, 0x7, 0x8f, 0x2, 0x2, 0x3e9, 
       0x47, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3ec, 0x5, 0x90, 0x49, 0x2, 0x3eb, 
       0x3ed, 0x5, 0x4a, 0x26, 0x2, 0x3ec, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3ec, 
       0x3ed, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3ee, 
       0x3f0, 0x5, 0x4c, 0x27, 0x2, 0x3ef, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x3f0, 
       0x3f3, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3ef, 0x3, 0x2, 0x2, 0x2, 0x3f1, 
       0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x3f3, 
       0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f6, 0x5, 0x80, 0x41, 0x2, 0x3f5, 
       0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f7, 
       0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f5, 0x3, 0x2, 0x2, 0x2, 0x3f8, 
       0x403, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3fa, 0x7, 0x5, 0x2, 0x2, 0x3fa, 
       0x3fb, 0x5, 0x72, 0x3a, 0x2, 0x3fb, 0x3fc, 0x7, 0x6, 0x2, 0x2, 0x3fc, 
       0x404, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fe, 0x7, 0x5, 0x2, 0x2, 0x3fe, 
       0x3ff, 0x5, 0x72, 0x3a, 0x2, 0x3ff, 0x400, 0x7, 0x7, 0x2, 0x2, 0x400, 
       0x401, 0x5, 0x72, 0x3a, 0x2, 0x401, 0x402, 0x7, 0x6, 0x2, 0x2, 0x402, 
       0x404, 0x3, 0x2, 0x2, 0x2, 0x403, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x403, 
       0x3fd, 0x3, 0x2, 0x2, 0x2, 0x403, 0x404, 0x3, 0x2, 0x2, 0x2, 0x404, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x405, 0x406, 0x7, 0x33, 0x2, 0x2, 0x406, 
       0x408, 0x5, 0x80, 0x41, 0x2, 0x407, 0x405, 0x3, 0x2, 0x2, 0x2, 0x407, 
       0x408, 0x3, 0x2, 0x2, 0x2, 0x408, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x409, 
       0x40a, 0x7, 0x73, 0x2, 0x2, 0x40a, 0x40c, 0x7, 0x61, 0x2, 0x2, 0x40b, 
       0x40d, 0x9, 0x7, 0x2, 0x2, 0x40c, 0x40b, 0x3, 0x2, 0x2, 0x2, 0x40c, 
       0x40d, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x3, 0x2, 0x2, 0x2, 0x40e, 
       0x410, 0x5, 0x4e, 0x28, 0x2, 0x40f, 0x411, 0x7, 0x26, 0x2, 0x2, 0x410, 
       0x40f, 0x3, 0x2, 0x2, 0x2, 0x410, 0x411, 0x3, 0x2, 0x2, 0x2, 0x411, 
       0x42b, 0x3, 0x2, 0x2, 0x2, 0x412, 0x414, 0x7, 0x68, 0x2, 0x2, 0x413, 
       0x412, 0x3, 0x2, 0x2, 0x2, 0x413, 0x414, 0x3, 0x2, 0x2, 0x2, 0x414, 
       0x415, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x7, 0x6a, 0x2, 0x2, 0x416, 
       0x42b, 0x5, 0x4e, 0x28, 0x2, 0x417, 0x418, 0x7, 0x8c, 0x2, 0x2, 0x418, 
       0x42b, 0x5, 0x4e, 0x28, 0x2, 0x419, 0x41a, 0x7, 0x2e, 0x2, 0x2, 0x41a, 
       0x41b, 0x7, 0x5, 0x2, 0x2, 0x41b, 0x41c, 0x5, 0x50, 0x29, 0x2, 0x41c, 
       0x41d, 0x7, 0x6, 0x2, 0x2, 0x41d, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x41e, 
       0x425, 0x7, 0x3a, 0x2, 0x2, 0x41f, 0x426, 0x5, 0x72, 0x3a, 0x2, 0x420, 
       0x426, 0x5, 0x74, 0x3b, 0x2, 0x421, 0x422, 0x7, 0x5, 0x2, 0x2, 0x422, 
       0x423, 0x5, 0x50, 0x29, 0x2, 0x423, 0x424, 0x7, 0x6, 0x2, 0x2, 0x424, 
       0x426, 0x3, 0x2, 0x2, 0x2, 0x425, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x425, 
       0x420, 0x3, 0x2, 0x2, 0x2, 0x425, 0x421, 0x3, 0x2, 0x2, 0x2, 0x426, 
       0x42b, 0x3, 0x2, 0x2, 0x2, 0x427, 0x428, 0x7, 0x2f, 0x2, 0x2, 0x428, 
       0x42b, 0x5, 0x92, 0x4a, 0x2, 0x429, 0x42b, 0x5, 0x52, 0x2a, 0x2, 
       0x42a, 0x409, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x413, 0x3, 0x2, 0x2, 0x2, 
       0x42a, 0x417, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x419, 0x3, 0x2, 0x2, 0x2, 
       0x42a, 0x41e, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x427, 0x3, 0x2, 0x2, 0x2, 
       0x42a, 0x429, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x4d, 0x3, 0x2, 0x2, 0x2, 
       0x42c, 0x42d, 0x7, 0x6d, 0x2, 0x2, 0x42d, 0x42e, 0x7, 0x32, 0x2, 
       0x2, 0x42e, 0x430, 0x9, 0x8, 0x2, 0x2, 0x42f, 0x42c, 0x3, 0x2, 0x2, 
       0x2, 0x42f, 0x430, 0x3, 0x2, 0x2, 0x2, 0x430, 0x4f, 0x3, 0x2, 0x2, 
       0x2, 0x431, 0x432, 0x8, 0x29, 0x1, 0x2, 0x432, 0x47e, 0x5, 0x74, 
       0x3b, 0x2, 0x433, 0x47e, 0x7, 0x99, 0x2, 0x2, 0x434, 0x435, 0x5, 
       0x84, 0x43, 0x2, 0x435, 0x436, 0x7, 0x4, 0x2, 0x2, 0x436, 0x438, 
       0x3, 0x2, 0x2, 0x2, 0x437, 0x434, 0x3, 0x2, 0x2, 0x2, 0x437, 0x438, 
       0x3, 0x2, 0x2, 0x2, 0x438, 0x439, 0x3, 0x2, 0x2, 0x2, 0x439, 0x43a, 
       0x5, 0x8a, 0x46, 0x2, 0x43a, 0x43b, 0x7, 0x4, 0x2, 0x2, 0x43b, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x43c, 0x437, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x43d, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x47e, 
       0x5, 0x90, 0x49, 0x2, 0x43f, 0x440, 0x5, 0x76, 0x3c, 0x2, 0x440, 
       0x441, 0x5, 0x50, 0x29, 0x17, 0x441, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x442, 
       0x443, 0x5, 0x82, 0x42, 0x2, 0x443, 0x450, 0x7, 0x5, 0x2, 0x2, 0x444, 
       0x446, 0x7, 0x40, 0x2, 0x2, 0x445, 0x444, 0x3, 0x2, 0x2, 0x2, 0x445, 
       0x446, 0x3, 0x2, 0x2, 0x2, 0x446, 0x447, 0x3, 0x2, 0x2, 0x2, 0x447, 
       0x44c, 0x5, 0x50, 0x29, 0x2, 0x448, 0x449, 0x7, 0x7, 0x2, 0x2, 0x449, 
       0x44b, 0x5, 0x50, 0x29, 0x2, 0x44a, 0x448, 0x3, 0x2, 0x2, 0x2, 0x44b, 
       0x44e, 0x3, 0x2, 0x2, 0x2, 0x44c, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x44c, 
       0x44d, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x451, 0x3, 0x2, 0x2, 0x2, 0x44e, 
       0x44c, 0x3, 0x2, 0x2, 0x2, 0x44f, 0x451, 0x7, 0x9, 0x2, 0x2, 0x450, 
       0x445, 0x3, 0x2, 0x2, 0x2, 0x450, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x450, 
       0x451, 0x3, 0x2, 0x2, 0x2, 0x451, 0x452, 0x3, 0x2, 0x2, 0x2, 0x452, 
       0x453, 0x7, 0x6, 0x2, 0x2, 0x453, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x454, 
       0x455, 0x7, 0x5, 0x2, 0x2, 0x455, 0x456, 0x5, 0x50, 0x29, 0x2, 0x456, 
       0x457, 0x7, 0x6, 0x2, 0x2, 0x457, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x458, 
       0x459, 0x7, 0x2d, 0x2, 0x2, 0x459, 0x45a, 0x7, 0x5, 0x2, 0x2, 0x45a, 
       0x45b, 0x5, 0x50, 0x29, 0x2, 0x45b, 0x45c, 0x7, 0x23, 0x2, 0x2, 0x45c, 
       0x45d, 0x5, 0x4a, 0x26, 0x2, 0x45d, 0x45e, 0x7, 0x6, 0x2, 0x2, 0x45e, 
       0x47e, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x461, 0x7, 0x68, 0x2, 0x2, 0x460, 
       0x45f, 0x3, 0x2, 0x2, 0x2, 0x460, 0x461, 0x3, 0x2, 0x2, 0x2, 0x461, 
       0x462, 0x3, 0x2, 0x2, 0x2, 0x462, 0x464, 0x7, 0x48, 0x2, 0x2, 0x463, 
       0x460, 0x3, 0x2, 0x2, 0x2, 0x463, 0x464, 0x3, 0x2, 0x2, 0x2, 0x464, 
       0x465, 0x3, 0x2, 0x2, 0x2, 0x465, 0x466, 0x7, 0x5, 0x2, 0x2, 0x466, 
       0x467, 0x5, 0x3e, 0x20, 0x2, 0x467, 0x468, 0x7, 0x6, 0x2, 0x2, 0x468, 
       0x47e, 0x3, 0x2, 0x2, 0x2, 0x469, 0x46b, 0x7, 0x2c, 0x2, 0x2, 0x46a, 
       0x46c, 0x5, 0x50, 0x29, 0x2, 0x46b, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x46b, 
       0x46c, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x472, 0x3, 0x2, 0x2, 0x2, 0x46d, 
       0x46e, 0x7, 0x93, 0x2, 0x2, 0x46e, 0x46f, 0x5, 0x50, 0x29, 0x2, 0x46f, 
       0x470, 0x7, 0x87, 0x2, 0x2, 0x470, 0x471, 0x5, 0x50, 0x29, 0x2, 0x471, 
       0x473, 0x3, 0x2, 0x2, 0x2, 0x472, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x473, 
       0x474, 0x3, 0x2, 0x2, 0x2, 0x474, 0x472, 0x3, 0x2, 0x2, 0x2, 0x474, 
       0x475, 0x3, 0x2, 0x2, 0x2, 0x475, 0x478, 0x3, 0x2, 0x2, 0x2, 0x476, 
       0x477, 0x7, 0x43, 0x2, 0x2, 0x477, 0x479, 0x5, 0x50, 0x29, 0x2, 0x478, 
       0x476, 0x3, 0x2, 0x2, 0x2, 0x478, 0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 
       0x47a, 0x3, 0x2, 0x2, 0x2, 0x47a, 0x47b, 0x7, 0x44, 0x2, 0x2, 0x47b, 
       0x47e, 0x3, 0x2, 0x2, 0x2, 0x47c, 0x47e, 0x5, 0x54, 0x2b, 0x2, 0x47d, 
       0x431, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x433, 0x3, 0x2, 0x2, 0x2, 0x47d, 
       0x43c, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x47d, 
       0x442, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x454, 0x3, 0x2, 0x2, 0x2, 0x47d, 
       0x458, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x463, 0x3, 0x2, 0x2, 0x2, 0x47d, 
       0x469, 0x3, 0x2, 0x2, 0x2, 0x47d, 0x47c, 0x3, 0x2, 0x2, 0x2, 0x47e, 
       0x4d6, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x480, 0xc, 0x16, 0x2, 0x2, 0x480, 
       0x481, 0x7, 0xd, 0x2, 0x2, 0x481, 0x4d5, 0x5, 0x50, 0x29, 0x17, 0x482, 
       0x483, 0xc, 0x15, 0x2, 0x2, 0x483, 0x484, 0x9, 0x9, 0x2, 0x2, 0x484, 
       0x4d5, 0x5, 0x50, 0x29, 0x16, 0x485, 0x486, 0xc, 0x14, 0x2, 0x2, 
       0x486, 0x487, 0x9, 0xa, 0x2, 0x2, 0x487, 0x4d5, 0x5, 0x50, 0x29, 
       0x15, 0x488, 0x489, 0xc, 0x13, 0x2, 0x2, 0x489, 0x48a, 0x9, 0xb, 
       0x2, 0x2, 0x48a, 0x4d5, 0x5, 0x50, 0x29, 0x14, 0x48b, 0x48c, 0xc, 
       0x12, 0x2, 0x2, 0x48c, 0x48d, 0x9, 0xc, 0x2, 0x2, 0x48d, 0x4d5, 0x5, 
       0x50, 0x29, 0x13, 0x48e, 0x48f, 0xc, 0x11, 0x2, 0x2, 0x48f, 0x490, 
       0x9, 0xd, 0x2, 0x2, 0x490, 0x4d5, 0x5, 0x50, 0x29, 0x12, 0x491, 0x492, 
       0xc, 0xf, 0x2, 0x2, 0x492, 0x493, 0x7, 0x22, 0x2, 0x2, 0x493, 0x4d5, 
       0x5, 0x50, 0x29, 0x10, 0x494, 0x495, 0xc, 0xe, 0x2, 0x2, 0x495, 0x496, 
       0x7, 0x6e, 0x2, 0x2, 0x496, 0x4d5, 0x5, 0x50, 0x29, 0xf, 0x497, 0x498, 
       0xc, 0x7, 0x2, 0x2, 0x498, 0x49a, 0x7, 0x5e, 0x2, 0x2, 0x499, 0x49b, 
       0x7, 0x68, 0x2, 0x2, 0x49a, 0x499, 0x3, 0x2, 0x2, 0x2, 0x49a, 0x49b, 
       0x3, 0x2, 0x2, 0x2, 0x49b, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x4d5, 
       0x5, 0x50, 0x29, 0x8, 0x49d, 0x49f, 0xc, 0x6, 0x2, 0x2, 0x49e, 0x4a0, 
       0x7, 0x68, 0x2, 0x2, 0x49f, 0x49e, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x4a0, 
       0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 
       0x7, 0x29, 0x2, 0x2, 0x4a2, 0x4a3, 0x5, 0x50, 0x29, 0x2, 0x4a3, 0x4a4, 
       0x7, 0x22, 0x2, 0x2, 0x4a4, 0x4a5, 0x5, 0x50, 0x29, 0x7, 0x4a5, 0x4d5, 
       0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a8, 0xc, 0x10, 0x2, 0x2, 0x4a7, 0x4a9, 
       0x7, 0x68, 0x2, 0x2, 0x4a8, 0x4a7, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a9, 
       0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4be, 
       0x7, 0x55, 0x2, 0x2, 0x4ab, 0x4b5, 0x7, 0x5, 0x2, 0x2, 0x4ac, 0x4b6, 
       0x5, 0x3e, 0x20, 0x2, 0x4ad, 0x4b2, 0x5, 0x50, 0x29, 0x2, 0x4ae, 
       0x4af, 0x7, 0x7, 0x2, 0x2, 0x4af, 0x4b1, 0x5, 0x50, 0x29, 0x2, 0x4b0, 
       0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4b1, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b2, 
       0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b3, 
       0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b5, 
       0x4ac, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4b5, 
       0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b7, 
       0x4bf, 0x7, 0x6, 0x2, 0x2, 0x4b8, 0x4b9, 0x5, 0x84, 0x43, 0x2, 0x4b9, 
       0x4ba, 0x7, 0x4, 0x2, 0x2, 0x4ba, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bb, 
       0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4bb, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bc, 
       0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4bf, 0x5, 0x8a, 0x46, 0x2, 0x4be, 
       0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4bf, 
       0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4c0, 0x4c1, 0xc, 0xa, 0x2, 0x2, 0x4c1, 
       0x4c2, 0x7, 0x2f, 0x2, 0x2, 0x4c2, 0x4d5, 0x5, 0x92, 0x4a, 0x2, 0x4c3, 
       0x4c5, 0xc, 0x9, 0x2, 0x2, 0x4c4, 0x4c6, 0x7, 0x68, 0x2, 0x2, 0x4c5, 
       0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c6, 0x3, 0x2, 0x2, 0x2, 0x4c6, 
       0x4c7, 0x3, 0x2, 0x2, 0x2, 0x4c7, 0x4c8, 0x9, 0xe, 0x2, 0x2, 0x4c8, 
       0x4cb, 0x5, 0x50, 0x29, 0x2, 0x4c9, 0x4ca, 0x7, 0x45, 0x2, 0x2, 0x4ca, 
       0x4cc, 0x5, 0x50, 0x29, 0x2, 0x4cb, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4cb, 
       0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4cd, 
       0x4d2, 0xc, 0x8, 0x2, 0x2, 0x4ce, 0x4d3, 0x7, 0x5f, 0x2, 0x2, 0x4cf, 
       0x4d3, 0x7, 0x69, 0x2, 0x2, 0x4d0, 0x4d1, 0x7, 0x68, 0x2, 0x2, 0x4d1, 
       0x4d3, 0x7, 0x6a, 0x2, 0x2, 0x4d2, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4d2, 
       0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d3, 
       0x4d5, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x482, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x485, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x488, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x48e, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x491, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x494, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x497, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x49d, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4a6, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x4c0, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4d4, 
       0x4cd, 0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4d6, 
       0x4d4, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d7, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0x4d8, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d9, 
       0x4da, 0x7, 0x77, 0x2, 0x2, 0x4da, 0x4e6, 0x5, 0x94, 0x4b, 0x2, 0x4db, 
       0x4dc, 0x7, 0x5, 0x2, 0x2, 0x4dc, 0x4e1, 0x5, 0x90, 0x49, 0x2, 0x4dd, 
       0x4de, 0x7, 0x7, 0x2, 0x2, 0x4de, 0x4e0, 0x5, 0x90, 0x49, 0x2, 0x4df, 
       0x4dd, 0x3, 0x2, 0x2, 0x2, 0x4e0, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e1, 
       0x4df, 0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4e2, 0x3, 0x2, 0x2, 0x2, 0x4e2, 
       0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4e1, 0x3, 0x2, 0x2, 0x2, 0x4e4, 
       0x4e5, 0x7, 0x6, 0x2, 0x2, 0x4e5, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e6, 
       0x4db, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e7, 
       0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4e9, 0x7, 0x6d, 0x2, 0x2, 0x4e9, 
       0x4f2, 0x9, 0xf, 0x2, 0x2, 0x4ea, 0x4eb, 0x7, 0x83, 0x2, 0x2, 0x4eb, 
       0x4f3, 0x7, 0x6a, 0x2, 0x2, 0x4ec, 0x4ed, 0x7, 0x83, 0x2, 0x2, 0x4ed, 
       0x4f3, 0x7, 0x3a, 0x2, 0x2, 0x4ee, 0x4f3, 0x7, 0x2b, 0x2, 0x2, 0x4ef, 
       0x4f3, 0x7, 0x7d, 0x2, 0x2, 0x4f0, 0x4f1, 0x7, 0x67, 0x2, 0x2, 0x4f1, 
       0x4f3, 0x7, 0x1c, 0x2, 0x2, 0x4f2, 0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4f2, 
       0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4f2, 
       0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4f0, 0x3, 0x2, 0x2, 0x2, 0x4f3, 
       0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4f5, 0x7, 0x65, 0x2, 0x2, 0x4f5, 
       0x4f7, 0x5, 0x80, 0x41, 0x2, 0x4f6, 0x4e8, 0x3, 0x2, 0x2, 0x2, 0x4f6, 
       0x4f4, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4f9, 0x3, 0x2, 0x2, 0x2, 0x4f8, 
       0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fa, 
       0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fb, 
       0x507, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fa, 0x3, 0x2, 0x2, 0x2, 0x4fd, 
       0x4ff, 0x7, 0x68, 0x2, 0x2, 0x4fe, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x4fe, 
       0x4ff, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x500, 0x3, 0x2, 0x2, 0x2, 0x500, 
       0x505, 0x7, 0x3b, 0x2, 0x2, 0x501, 0x502, 0x7, 0x58, 0x2, 0x2, 0x502, 
       0x506, 0x7, 0x3c, 0x2, 0x2, 0x503, 0x504, 0x7, 0x58, 0x2, 0x2, 0x504, 
       0x506, 0x7, 0x54, 0x2, 0x2, 0x505, 0x501, 0x3, 0x2, 0x2, 0x2, 0x505, 
       0x503, 0x3, 0x2, 0x2, 0x2, 0x505, 0x506, 0x3, 0x2, 0x2, 0x2, 0x506, 
       0x508, 0x3, 0x2, 0x2, 0x2, 0x507, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x507, 
       0x508, 0x3, 0x2, 0x2, 0x2, 0x508, 0x53, 0x3, 0x2, 0x2, 0x2, 0x509, 
       0x50a, 0x7, 0x75, 0x2, 0x2, 0x50a, 0x50f, 0x7, 0x5, 0x2, 0x2, 0x50b, 
       0x510, 0x7, 0x53, 0x2, 0x2, 0x50c, 0x50d, 0x9, 0x10, 0x2, 0x2, 0x50d, 
       0x50e, 0x7, 0x7, 0x2, 0x2, 0x50e, 0x510, 0x5, 0x78, 0x3d, 0x2, 0x50f, 
       0x50b, 0x3, 0x2, 0x2, 0x2, 0x50f, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x510, 
       0x511, 0x3, 0x2, 0x2, 0x2, 0x511, 0x512, 0x7, 0x6, 0x2, 0x2, 0x512, 
       0x55, 0x3, 0x2, 0x2, 0x2, 0x513, 0x516, 0x5, 0x90, 0x49, 0x2, 0x514, 
       0x515, 0x7, 0x2f, 0x2, 0x2, 0x515, 0x517, 0x5, 0x92, 0x4a, 0x2, 0x516, 
       0x514, 0x3, 0x2, 0x2, 0x2, 0x516, 0x517, 0x3, 0x2, 0x2, 0x2, 0x517, 
       0x519, 0x3, 0x2, 0x2, 0x2, 0x518, 0x51a, 0x9, 0x7, 0x2, 0x2, 0x519, 
       0x518, 0x3, 0x2, 0x2, 0x2, 0x519, 0x51a, 0x3, 0x2, 0x2, 0x2, 0x51a, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x51b, 0x51c, 0x7, 0x33, 0x2, 0x2, 0x51c, 
       0x51e, 0x5, 0x80, 0x41, 0x2, 0x51d, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x51d, 
       0x51e, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x543, 0x3, 0x2, 0x2, 0x2, 0x51f, 
       0x520, 0x7, 0x73, 0x2, 0x2, 0x520, 0x523, 0x7, 0x61, 0x2, 0x2, 0x521, 
       0x523, 0x7, 0x8c, 0x2, 0x2, 0x522, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x522, 
       0x521, 0x3, 0x2, 0x2, 0x2, 0x523, 0x524, 0x3, 0x2, 0x2, 0x2, 0x524, 
       0x525, 0x7, 0x5, 0x2, 0x2, 0x525, 0x52a, 0x5, 0x56, 0x2c, 0x2, 0x526, 
       0x527, 0x7, 0x7, 0x2, 0x2, 0x527, 0x529, 0x5, 0x56, 0x2c, 0x2, 0x528, 
       0x526, 0x3, 0x2, 0x2, 0x2, 0x529, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52a, 
       0x528, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52b, 0x3, 0x2, 0x2, 0x2, 0x52b, 
       0x52d, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x52d, 
       0x52e, 0x7, 0x6, 0x2, 0x2, 0x52e, 0x52f, 0x5, 0x4e, 0x28, 0x2, 0x52f, 
       0x544, 0x3, 0x2, 0x2, 0x2, 0x530, 0x531, 0x7, 0x2e, 0x2, 0x2, 0x531, 
       0x532, 0x7, 0x5, 0x2, 0x2, 0x532, 0x533, 0x5, 0x50, 0x29, 0x2, 0x533, 
       0x534, 0x7, 0x6, 0x2, 0x2, 0x534, 0x544, 0x3, 0x2, 0x2, 0x2, 0x535, 
       0x536, 0x7, 0x4c, 0x2, 0x2, 0x536, 0x537, 0x7, 0x61, 0x2, 0x2, 0x537, 
       0x538, 0x7, 0x5, 0x2, 0x2, 0x538, 0x53d, 0x5, 0x90, 0x49, 0x2, 0x539, 
       0x53a, 0x7, 0x7, 0x2, 0x2, 0x53a, 0x53c, 0x5, 0x90, 0x49, 0x2, 0x53b, 
       0x539, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x53f, 0x3, 0x2, 0x2, 0x2, 0x53d, 
       0x53b, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53e, 0x3, 0x2, 0x2, 0x2, 0x53e, 
       0x540, 0x3, 0x2, 0x2, 0x2, 0x53f, 0x53d, 0x3, 0x2, 0x2, 0x2, 0x540, 
       0x541, 0x7, 0x6, 0x2, 0x2, 0x541, 0x542, 0x5, 0x52, 0x2a, 0x2, 0x542, 
       0x544, 0x3, 0x2, 0x2, 0x2, 0x543, 0x522, 0x3, 0x2, 0x2, 0x2, 0x543, 
       0x530, 0x3, 0x2, 0x2, 0x2, 0x543, 0x535, 0x3, 0x2, 0x2, 0x2, 0x544, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x545, 0x547, 0x7, 0x95, 0x2, 0x2, 0x546, 
       0x548, 0x7, 0x76, 0x2, 0x2, 0x547, 0x546, 0x3, 0x2, 0x2, 0x2, 0x547, 
       0x548, 0x3, 0x2, 0x2, 0x2, 0x548, 0x549, 0x3, 0x2, 0x2, 0x2, 0x549, 
       0x54e, 0x5, 0x62, 0x32, 0x2, 0x54a, 0x54b, 0x7, 0x7, 0x2, 0x2, 0x54b, 
       0x54d, 0x5, 0x62, 0x32, 0x2, 0x54c, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x54d, 
       0x550, 0x3, 0x2, 0x2, 0x2, 0x54e, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54e, 
       0x54f, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x550, 
       0x54e, 0x3, 0x2, 0x2, 0x2, 0x551, 0x552, 0x5, 0x84, 0x43, 0x2, 0x552, 
       0x553, 0x7, 0x4, 0x2, 0x2, 0x553, 0x555, 0x3, 0x2, 0x2, 0x2, 0x554, 
       0x551, 0x3, 0x2, 0x2, 0x2, 0x554, 0x555, 0x3, 0x2, 0x2, 0x2, 0x555, 
       0x556, 0x3, 0x2, 0x2, 0x2, 0x556, 0x55c, 0x5, 0x8a, 0x46, 0x2, 0x557, 
       0x558, 0x7, 0x57, 0x2, 0x2, 0x558, 0x559, 0x7, 0x2a, 0x2, 0x2, 0x559, 
       0x55d, 0x5, 0x96, 0x4c, 0x2, 0x55a, 0x55b, 0x7, 0x68, 0x2, 0x2, 0x55b, 
       0x55d, 0x7, 0x57, 0x2, 0x2, 0x55c, 0x557, 0x3, 0x2, 0x2, 0x2, 0x55c, 
       0x55a, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55d, 
       0x5d, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x561, 0x5, 0x50, 0x29, 0x2, 0x55f, 
       0x560, 0x7, 0x2f, 0x2, 0x2, 0x560, 0x562, 0x5, 0x92, 0x4a, 0x2, 0x561, 
       0x55f, 0x3, 0x2, 0x2, 0x2, 0x561, 0x562, 0x3, 0x2, 0x2, 0x2, 0x562, 
       0x564, 0x3, 0x2, 0x2, 0x2, 0x563, 0x565, 0x9, 0x7, 0x2, 0x2, 0x564, 
       0x563, 0x3, 0x2, 0x2, 0x2, 0x564, 0x565, 0x3, 0x2, 0x2, 0x2, 0x565, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x566, 0x56a, 0x5, 0x72, 0x3a, 0x2, 0x567, 
       0x56a, 0x5, 0x80, 0x41, 0x2, 0x568, 0x56a, 0x7, 0x9a, 0x2, 0x2, 0x569, 
       0x566, 0x3, 0x2, 0x2, 0x2, 0x569, 0x567, 0x3, 0x2, 0x2, 0x2, 0x569, 
       0x568, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x61, 0x3, 0x2, 0x2, 0x2, 0x56b, 
       0x577, 0x5, 0x8a, 0x46, 0x2, 0x56c, 0x56d, 0x7, 0x5, 0x2, 0x2, 0x56d, 
       0x572, 0x5, 0x90, 0x49, 0x2, 0x56e, 0x56f, 0x7, 0x7, 0x2, 0x2, 0x56f, 
       0x571, 0x5, 0x90, 0x49, 0x2, 0x570, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x571, 
       0x574, 0x3, 0x2, 0x2, 0x2, 0x572, 0x570, 0x3, 0x2, 0x2, 0x2, 0x572, 
       0x573, 0x3, 0x2, 0x2, 0x2, 0x573, 0x575, 0x3, 0x2, 0x2, 0x2, 0x574, 
       0x572, 0x3, 0x2, 0x2, 0x2, 0x575, 0x576, 0x7, 0x6, 0x2, 0x2, 0x576, 
       0x578, 0x3, 0x2, 0x2, 0x2, 0x577, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x577, 
       0x578, 0x3, 0x2, 0x2, 0x2, 0x578, 0x579, 0x3, 0x2, 0x2, 0x2, 0x579, 
       0x57a, 0x7, 0x23, 0x2, 0x2, 0x57a, 0x57b, 0x7, 0x5, 0x2, 0x2, 0x57b, 
       0x57c, 0x5, 0x3e, 0x20, 0x2, 0x57c, 0x57d, 0x7, 0x6, 0x2, 0x2, 0x57d, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x58b, 0x7, 0x9, 0x2, 0x2, 0x57f, 
       0x580, 0x5, 0x8a, 0x46, 0x2, 0x580, 0x581, 0x7, 0x4, 0x2, 0x2, 0x581, 
       0x582, 0x7, 0x9, 0x2, 0x2, 0x582, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x583, 
       0x588, 0x5, 0x50, 0x29, 0x2, 0x584, 0x586, 0x7, 0x23, 0x2, 0x2, 0x585, 
       0x584, 0x3, 0x2, 0x2, 0x2, 0x585, 0x586, 0x3, 0x2, 0x2, 0x2, 0x586, 
       0x587, 0x3, 0x2, 0x2, 0x2, 0x587, 0x589, 0x5, 0x7c, 0x3f, 0x2, 0x588, 
       0x585, 0x3, 0x2, 0x2, 0x2, 0x588, 0x589, 0x3, 0x2, 0x2, 0x2, 0x589, 
       0x58b, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x57e, 0x3, 0x2, 0x2, 0x2, 0x58a, 
       0x57f, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x583, 0x3, 0x2, 0x2, 0x2, 0x58b, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58d, 0x5, 0x86, 0x44, 0x2, 0x58d, 
       0x58e, 0x7, 0x4, 0x2, 0x2, 0x58e, 0x590, 0x3, 0x2, 0x2, 0x2, 0x58f, 
       0x58c, 0x3, 0x2, 0x2, 0x2, 0x58f, 0x590, 0x3, 0x2, 0x2, 0x2, 0x590, 
       0x591, 0x3, 0x2, 0x2, 0x2, 0x591, 0x596, 0x5, 0x8a, 0x46, 0x2, 0x592, 
       0x594, 0x7, 0x23, 0x2, 0x2, 0x593, 0x592, 0x3, 0x2, 0x2, 0x2, 0x593, 
       0x594, 0x3, 0x2, 0x2, 0x2, 0x594, 0x595, 0x3, 0x2, 0x2, 0x2, 0x595, 
       0x597, 0x5, 0xa2, 0x52, 0x2, 0x596, 0x593, 0x3, 0x2, 0x2, 0x2, 0x596, 
       0x597, 0x3, 0x2, 0x2, 0x2, 0x597, 0x59d, 0x3, 0x2, 0x2, 0x2, 0x598, 
       0x599, 0x7, 0x57, 0x2, 0x2, 0x599, 0x59a, 0x7, 0x2a, 0x2, 0x2, 0x59a, 
       0x59e, 0x5, 0x96, 0x4c, 0x2, 0x59b, 0x59c, 0x7, 0x68, 0x2, 0x2, 0x59c, 
       0x59e, 0x7, 0x57, 0x2, 0x2, 0x59d, 0x598, 0x3, 0x2, 0x2, 0x2, 0x59d, 
       0x59b, 0x3, 0x2, 0x2, 0x2, 0x59d, 0x59e, 0x3, 0x2, 0x2, 0x2, 0x59e, 
       0x5cf, 0x3, 0x2, 0x2, 0x2, 0x59f, 0x5a0, 0x5, 0x86, 0x44, 0x2, 0x5a0, 
       0x5a1, 0x7, 0x4, 0x2, 0x2, 0x5a1, 0x5a3, 0x3, 0x2, 0x2, 0x2, 0x5a2, 
       0x59f, 0x3, 0x2, 0x2, 0x2, 0x5a2, 0x5a3, 0x3, 0x2, 0x2, 0x2, 0x5a3, 
       0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a5, 0x5, 0x88, 0x45, 0x2, 0x5a5, 
       0x5ae, 0x7, 0x5, 0x2, 0x2, 0x5a6, 0x5ab, 0x5, 0x50, 0x29, 0x2, 0x5a7, 
       0x5a8, 0x7, 0x7, 0x2, 0x2, 0x5a8, 0x5aa, 0x5, 0x50, 0x29, 0x2, 0x5a9, 
       0x5a7, 0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ad, 0x3, 0x2, 0x2, 0x2, 0x5ab, 
       0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5ab, 0x5ac, 0x3, 0x2, 0x2, 0x2, 0x5ac, 
       0x5af, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ab, 0x3, 0x2, 0x2, 0x2, 0x5ae, 
       0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5af, 0x3, 0x2, 0x2, 0x2, 0x5af, 
       0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5b5, 0x7, 0x6, 0x2, 0x2, 0x5b1, 
       0x5b3, 0x7, 0x23, 0x2, 0x2, 0x5b2, 0x5b1, 0x3, 0x2, 0x2, 0x2, 0x5b2, 
       0x5b3, 0x3, 0x2, 0x2, 0x2, 0x5b3, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b4, 
       0x5b6, 0x5, 0xa2, 0x52, 0x2, 0x5b5, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b5, 
       0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b6, 0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5b7, 
       0x5c1, 0x7, 0x5, 0x2, 0x2, 0x5b8, 0x5bd, 0x5, 0x66, 0x34, 0x2, 0x5b9, 
       0x5ba, 0x7, 0x7, 0x2, 0x2, 0x5ba, 0x5bc, 0x5, 0x66, 0x34, 0x2, 0x5bb, 
       0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5bd, 
       0x5bb, 0x3, 0x2, 0x2, 0x2, 0x5bd, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x5be, 
       0x5c2, 0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5c0, 
       0x5c2, 0x5, 0x68, 0x35, 0x2, 0x5c1, 0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5c1, 
       0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c3, 
       0x5c4, 0x7, 0x6, 0x2, 0x2, 0x5c4, 0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5c5, 
       0x5c6, 0x7, 0x5, 0x2, 0x2, 0x5c6, 0x5c7, 0x5, 0x3e, 0x20, 0x2, 0x5c7, 
       0x5cc, 0x7, 0x6, 0x2, 0x2, 0x5c8, 0x5ca, 0x7, 0x23, 0x2, 0x2, 0x5c9, 
       0x5c8, 0x3, 0x2, 0x2, 0x2, 0x5c9, 0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5ca, 
       0x5cb, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5cd, 0x5, 0xa2, 0x52, 0x2, 0x5cc, 
       0x5c9, 0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5cd, 
       0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x5ce, 
       0x5a2, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5b7, 0x3, 0x2, 0x2, 0x2, 0x5ce, 
       0x5c5, 0x3, 0x2, 0x2, 0x2, 0x5cf, 0x67, 0x3, 0x2, 0x2, 0x2, 0x5d0, 
       0x5d7, 0x5, 0x66, 0x34, 0x2, 0x5d1, 0x5d2, 0x5, 0x6a, 0x36, 0x2, 
       0x5d2, 0x5d3, 0x5, 0x66, 0x34, 0x2, 0x5d3, 0x5d4, 0x5, 0x6c, 0x37, 
       0x2, 0x5d4, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x5d1, 0x3, 0x2, 0x2, 
       0x2, 0x5d6, 0x5d9, 0x3, 0x2, 0x2, 0x2, 0x5d7, 0x5d5, 0x3, 0x2, 0x2, 
       0x2, 0x5d7, 0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5d8, 0x69, 0x3, 0x2, 0x2, 
       0x2, 0x5d9, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5da, 0x5e8, 0x7, 0x7, 0x2, 
       0x2, 0x5db, 0x5dd, 0x7, 0x66, 0x2, 0x2, 0x5dc, 0x5db, 0x3, 0x2, 0x2, 
       0x2, 0x5dc, 0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5dd, 0x5e4, 0x3, 0x2, 0x2, 
       0x2, 0x5de, 0x5e0, 0x7, 0x62, 0x2, 0x2, 0x5df, 0x5e1, 0x7, 0x70, 
       0x2, 0x2, 0x5e0, 0x5df, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5e1, 0x3, 0x2, 
       0x2, 0x2, 0x5e1, 0x5e5, 0x3, 0x2, 0x2, 0x2, 0x5e2, 0x5e5, 0x7, 0x59, 
       0x2, 0x2, 0x5e3, 0x5e5, 0x7, 0x35, 0x2, 0x2, 0x5e4, 0x5de, 0x3, 0x2, 
       0x2, 0x2, 0x5e4, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e4, 0x5e3, 0x3, 0x2, 
       0x2, 0x2, 0x5e4, 0x5e5, 0x3, 0x2, 0x2, 0x2, 0x5e5, 0x5e6, 0x3, 0x2, 
       0x2, 0x2, 0x5e6, 0x5e8, 0x7, 0x60, 0x2, 0x2, 0x5e7, 0x5da, 0x3, 0x2, 
       0x2, 0x2, 0x5e7, 0x5dc, 0x3, 0x2, 0x2, 0x2, 0x5e8, 0x6b, 0x3, 0x2, 
       0x2, 0x2, 0x5e9, 0x5ea, 0x7, 0x6d, 0x2, 0x2, 0x5ea, 0x5f8, 0x5, 0x50, 
       0x29, 0x2, 0x5eb, 0x5ec, 0x7, 0x8e, 0x2, 0x2, 0x5ec, 0x5ed, 0x7, 
       0x5, 0x2, 0x2, 0x5ed, 0x5f2, 0x5, 0x90, 0x49, 0x2, 0x5ee, 0x5ef, 
       0x7, 0x7, 0x2, 0x2, 0x5ef, 0x5f1, 0x5, 0x90, 0x49, 0x2, 0x5f0, 0x5ee, 
       0x3, 0x2, 0x2, 0x2, 0x5f1, 0x5f4, 0x3, 0x2, 0x2, 0x2, 0x5f2, 0x5f0, 
       0x3, 0x2, 0x2, 0x2, 0x5f2, 0x5f3, 0x3, 0x2, 0x2, 0x2, 0x5f3, 0x5f5, 
       0x3, 0x2, 0x2, 0x2, 0x5f4, 0x5f2, 0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5f6, 
       0x7, 0x6, 0x2, 0x2, 0x5f6, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5e9, 
       0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5eb, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f8, 
       0x3, 0x2, 0x2, 0x2, 0x5f8, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x5f9, 0x5fb, 
       0x7, 0x82, 0x2, 0x2, 0x5fa, 0x5fc, 0x9, 0x6, 0x2, 0x2, 0x5fb, 0x5fa, 
       0x3, 0x2, 0x2, 0x2, 0x5fb, 0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fc, 0x5fd, 
       0x3, 0x2, 0x2, 0x2, 0x5fd, 0x602, 0x5, 0x64, 0x33, 0x2, 0x5fe, 0x5ff, 
       0x7, 0x7, 0x2, 0x2, 0x5ff, 0x601, 0x5, 0x64, 0x33, 0x2, 0x600, 0x5fe, 
       0x3, 0x2, 0x2, 0x2, 0x601, 0x604, 0x3, 0x2, 0x2, 0x2, 0x602, 0x600, 
       0x3, 0x2, 0x2, 0x2, 0x602, 0x603, 0x3, 0x2, 0x2, 0x2, 0x603, 0x611, 
       0x3, 0x2, 0x2, 0x2, 0x604, 0x602, 0x3, 0x2, 0x2, 0x2, 0x605, 0x60f, 
       0x7, 0x4d, 0x2, 0x2, 0x606, 0x60b, 0x5, 0x66, 0x34, 0x2, 0x607, 0x608, 
       0x7, 0x7, 0x2, 0x2, 0x608, 0x60a, 0x5, 0x66, 0x34, 0x2, 0x609, 0x607, 
       0x3, 0x2, 0x2, 0x2, 0x60a, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x609, 
       0x3, 0x2, 0x2, 0x2, 0x60b, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x60c, 0x610, 
       0x3, 0x2, 0x2, 0x2, 0x60d, 0x60b, 0x3, 0x2, 0x2, 0x2, 0x60e, 0x610, 
       0x5, 0x68, 0x35, 0x2, 0x60f, 0x606, 0x3, 0x2, 0x2, 0x2, 0x60f, 0x60e, 
       0x3, 0x2, 0x2, 0x2, 0x610, 0x612, 0x3, 0x2, 0x2, 0x2, 0x611, 0x605, 
       0x3, 0x2, 0x2, 0x2, 0x611, 0x612, 0x3, 0x2, 0x2, 0x2, 0x612, 0x615, 
       0x3, 0x2, 0x2, 0x2, 0x613, 0x614, 0x7, 0x94, 0x2, 0x2, 0x614, 0x616, 
       0x5, 0x50, 0x29, 0x2, 0x615, 0x613, 0x3, 0x2, 0x2, 0x2, 0x615, 0x616, 
       0x3, 0x2, 0x2, 0x2, 0x616, 0x625, 0x3, 0x2, 0x2, 0x2, 0x617, 0x618, 
       0x7, 0x50, 0x2, 0x2, 0x618, 0x619, 0x7, 0x2a, 0x2, 0x2, 0x619, 0x61e, 
       0x5, 0x50, 0x29, 0x2, 0x61a, 0x61b, 0x7, 0x7, 0x2, 0x2, 0x61b, 0x61d, 
       0x5, 0x50, 0x29, 0x2, 0x61c, 0x61a, 0x3, 0x2, 0x2, 0x2, 0x61d, 0x620, 
       0x3, 0x2, 0x2, 0x2, 0x61e, 0x61c, 0x3, 0x2, 0x2, 0x2, 0x61e, 0x61f, 
       0x3, 0x2, 0x2, 0x2, 0x61f, 0x623, 0x3, 0x2, 0x2, 0x2, 0x620, 0x61e, 
       0x3, 0x2, 0x2, 0x2, 0x621, 0x622, 0x7, 0x51, 0x2, 0x2, 0x622, 0x624, 
       0x5, 0x50, 0x29, 0x2, 0x623, 0x621, 0x3, 0x2, 0x2, 0x2, 0x623, 0x624, 
       0x3, 0x2, 0x2, 0x2, 0x624, 0x626, 0x3, 0x2, 0x2, 0x2, 0x625, 0x617, 
       0x3, 0x2, 0x2, 0x2, 0x625, 0x626, 0x3, 0x2, 0x2, 0x2, 0x626, 0x644, 
       0x3, 0x2, 0x2, 0x2, 0x627, 0x628, 0x7, 0x90, 0x2, 0x2, 0x628, 0x629, 
       0x7, 0x5, 0x2, 0x2, 0x629, 0x62e, 0x5, 0x50, 0x29, 0x2, 0x62a, 0x62b, 
       0x7, 0x7, 0x2, 0x2, 0x62b, 0x62d, 0x5, 0x50, 0x29, 0x2, 0x62c, 0x62a, 
       0x3, 0x2, 0x2, 0x2, 0x62d, 0x630, 0x3, 0x2, 0x2, 0x2, 0x62e, 0x62c, 
       0x3, 0x2, 0x2, 0x2, 0x62e, 0x62f, 0x3, 0x2, 0x2, 0x2, 0x62f, 0x631, 
       0x3, 0x2, 0x2, 0x2, 0x630, 0x62e, 0x3, 0x2, 0x2, 0x2, 0x631, 0x640, 
       0x7, 0x6, 0x2, 0x2, 0x632, 0x633, 0x7, 0x7, 0x2, 0x2, 0x633, 0x634, 
       0x7, 0x5, 0x2, 0x2, 0x634, 0x639, 0x5, 0x50, 0x29, 0x2, 0x635, 0x636, 
       0x7, 0x7, 0x2, 0x2, 0x636, 0x638, 0x5, 0x50, 0x29, 0x2, 0x637, 0x635, 
       0x3, 0x2, 0x2, 0x2, 0x638, 0x63b, 0x3, 0x2, 0x2, 0x2, 0x639, 0x637, 
       0x3, 0x2, 0x2, 0x2, 0x639, 0x63a, 0x3, 0x2, 0x2, 0x2, 0x63a, 0x63c, 
       0x3, 0x2, 0x2, 0x2, 0x63b, 0x639, 0x3, 0x2, 0x2, 0x2, 0x63c, 0x63d, 
       0x7, 0x6, 0x2, 0x2, 0x63d, 0x63f, 0x3, 0x2, 0x2, 0x2, 0x63e, 0x632, 
       0x3, 0x2, 0x2, 0x2, 0x63f, 0x642, 0x3, 0x2, 0x2, 0x2, 0x640, 0x63e, 
       0x3, 0x2, 0x2, 0x2, 0x640, 0x641, 0x3, 0x2, 0x2, 0x2, 0x641, 0x644, 
       0x3, 0x2, 0x2, 0x2, 0x642, 0x640, 0x3, 0x2, 0x2, 0x2, 0x643, 0x5f9, 
       0x3, 0x2, 0x2, 0x2, 0x643, 0x627, 0x3, 0x2, 0x2, 0x2, 0x644, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x645, 0x64b, 0x7, 0x8b, 0x2, 0x2, 0x646, 0x647, 
       0x7, 0x8b, 0x2, 0x2, 0x647, 0x64b, 0x7, 0x1f, 0x2, 0x2, 0x648, 0x64b, 
       0x7, 0x5c, 0x2, 0x2, 0x649, 0x64b, 0x7, 0x46, 0x2, 0x2, 0x64a, 0x645, 
       0x3, 0x2, 0x2, 0x2, 0x64a, 0x646, 0x3, 0x2, 0x2, 0x2, 0x64a, 0x648, 
       0x3, 0x2, 0x2, 0x2, 0x64a, 0x649, 0x3, 0x2, 0x2, 0x2, 0x64b, 0x71, 
       0x3, 0x2, 0x2, 0x2, 0x64c, 0x64e, 0x9, 0xa, 0x2, 0x2, 0x64d, 0x64c, 
       0x3, 0x2, 0x2, 0x2, 0x64d, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x64e, 0x64f, 
       0x3, 0x2, 0x2, 0x2, 0x64f, 0x650, 0x7, 0x98, 0x2, 0x2, 0x650, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x651, 0x652, 0x9, 0x11, 0x2, 0x2, 0x652, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0x653, 0x654, 0x9, 0x12, 0x2, 0x2, 0x654, 0x77, 
       0x3, 0x2, 0x2, 0x2, 0x655, 0x656, 0x7, 0x9a, 0x2, 0x2, 0x656, 0x79, 
       0x3, 0x2, 0x2, 0x2, 0x657, 0x65a, 0x5, 0x50, 0x29, 0x2, 0x658, 0x65a, 
       0x5, 0x48, 0x25, 0x2, 0x659, 0x657, 0x3, 0x2, 0x2, 0x2, 0x659, 0x658, 
       0x3, 0x2, 0x2, 0x2, 0x65a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x65c, 
       0x9, 0x13, 0x2, 0x2, 0x65c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x65d, 0x65e, 
       0x9, 0x14, 0x2, 0x2, 0x65e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x65f, 0x660, 
       0x5, 0xa6, 0x54, 0x2, 0x660, 0x81, 0x3, 0x2, 0x2, 0x2, 0x661, 0x662, 
       0x5, 0xa6, 0x54, 0x2, 0x662, 0x83, 0x3, 0x2, 0x2, 0x2, 0x663, 0x664, 
       0x5, 0xa6, 0x54, 0x2, 0x664, 0x85, 0x3, 0x2, 0x2, 0x2, 0x665, 0x666, 
       0x5, 0xa6, 0x54, 0x2, 0x666, 0x87, 0x3, 0x2, 0x2, 0x2, 0x667, 0x668, 
       0x5, 0xa6, 0x54, 0x2, 0x668, 0x89, 0x3, 0x2, 0x2, 0x2, 0x669, 0x66a, 
       0x5, 0xa6, 0x54, 0x2, 0x66a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66c, 
       0x5, 0xa6, 0x54, 0x2, 0x66c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x66e, 
       0x5, 0xa6, 0x54, 0x2, 0x66e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x66f, 0x670, 
       0x5, 0xa6, 0x54, 0x2, 0x670, 0x91, 0x3, 0x2, 0x2, 0x2, 0x671, 0x672, 
       0x5, 0xa6, 0x54, 0x2, 0x672, 0x93, 0x3, 0x2, 0x2, 0x2, 0x673, 0x674, 
       0x5, 0xa6, 0x54, 0x2, 0x674, 0x95, 0x3, 0x2, 0x2, 0x2, 0x675, 0x676, 
       0x5, 0xa6, 0x54, 0x2, 0x676, 0x97, 0x3, 0x2, 0x2, 0x2, 0x677, 0x678, 
       0x5, 0xa6, 0x54, 0x2, 0x678, 0x99, 0x3, 0x2, 0x2, 0x2, 0x679, 0x67a, 
       0x5, 0xa6, 0x54, 0x2, 0x67a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67c, 
       0x5, 0xa6, 0x54, 0x2, 0x67c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x67d, 0x67e, 
       0x5, 0xa6, 0x54, 0x2, 0x67e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x67f, 0x680, 
       0x5, 0xa6, 0x54, 0x2, 0x680, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x681, 0x688, 
       0x7, 0x97, 0x2, 0x2, 0x682, 0x688, 0x7, 0x9a, 0x2, 0x2, 0x683, 0x684, 
       0x7, 0x5, 0x2, 0x2, 0x684, 0x685, 0x5, 0xa2, 0x52, 0x2, 0x685, 0x686, 
       0x7, 0x6, 0x2, 0x2, 0x686, 0x688, 0x3, 0x2, 0x2, 0x2, 0x687, 0x681, 
       0x3, 0x2, 0x2, 0x2, 0x687, 0x682, 0x3, 0x2, 0x2, 0x2, 0x687, 0x683, 
       0x3, 0x2, 0x2, 0x2, 0x688, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x689, 0x68a, 
       0x5, 0xa6, 0x54, 0x2, 0x68a, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x693, 
       0x7, 0x97, 0x2, 0x2, 0x68c, 0x693, 0x5, 0x7e, 0x40, 0x2, 0x68d, 0x693, 
       0x7, 0x9a, 0x2, 0x2, 0x68e, 0x68f, 0x7, 0x5, 0x2, 0x2, 0x68f, 0x690, 
       0x5, 0xa6, 0x54, 0x2, 0x690, 0x691, 0x7, 0x6, 0x2, 0x2, 0x691, 0x693, 
       0x3, 0x2, 0x2, 0x2, 0x692, 0x68b, 0x3, 0x2, 0x2, 0x2, 0x692, 0x68c, 
       0x3, 0x2, 0x2, 0x2, 0x692, 0x68d, 0x3, 0x2, 0x2, 0x2, 0x692, 0x68e, 
       0x3, 0x2, 0x2, 0x2, 0x693, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xef, 0xaa, 
       0xac, 0xb7, 0xbe, 0xc3, 0xc9, 0xcf, 0xd1, 0xf1, 0xf8, 0x100, 0x103, 
       0x10c, 0x110, 0x118, 0x11c, 0x11e, 0x123, 0x125, 0x128, 0x12d, 0x131, 
       0x136, 0x13f, 0x142, 0x148, 0x14a, 0x14e, 0x154, 0x159, 0x164, 0x16a, 
       0x16e, 0x174, 0x179, 0x182, 0x189, 0x18f, 0x193, 0x197, 0x19d, 0x1a2, 
       0x1a9, 0x1b4, 0x1b7, 0x1b9, 0x1bf, 0x1c5, 0x1c9, 0x1d0, 0x1d6, 0x1dc, 
       0x1e2, 0x1e7, 0x1f3, 0x1f8, 0x203, 0x208, 0x20b, 0x212, 0x215, 0x21c, 
       0x225, 0x228, 0x22e, 0x230, 0x234, 0x23c, 0x241, 0x249, 0x24e, 0x256, 
       0x25b, 0x263, 0x268, 0x26d, 0x275, 0x27f, 0x282, 0x288, 0x28a, 0x28d, 
       0x2a0, 0x2a6, 0x2af, 0x2b4, 0x2bd, 0x2c8, 0x2cf, 0x2d5, 0x2db, 0x2e4, 
       0x2eb, 0x2ef, 0x2f1, 0x2f5, 0x2fc, 0x2fe, 0x302, 0x305, 0x30b, 0x315, 
       0x318, 0x31e, 0x320, 0x323, 0x32b, 0x335, 0x338, 0x33e, 0x340, 0x344, 
       0x34b, 0x354, 0x358, 0x35a, 0x35e, 0x367, 0x36c, 0x36e, 0x377, 0x382, 
       0x389, 0x38c, 0x38f, 0x39c, 0x3aa, 0x3af, 0x3b2, 0x3bf, 0x3cd, 0x3d2, 
       0x3db, 0x3de, 0x3e4, 0x3e6, 0x3ec, 0x3f1, 0x3f7, 0x403, 0x407, 0x40c, 
       0x410, 0x413, 0x425, 0x42a, 0x42f, 0x437, 0x43c, 0x445, 0x44c, 0x450, 
       0x460, 0x463, 0x46b, 0x474, 0x478, 0x47d, 0x49a, 0x49f, 0x4a8, 0x4b2, 
       0x4b5, 0x4bb, 0x4be, 0x4c5, 0x4cb, 0x4d2, 0x4d4, 0x4d6, 0x4e1, 0x4e6, 
       0x4f2, 0x4f6, 0x4fa, 0x4fe, 0x505, 0x507, 0x50f, 0x516, 0x519, 0x51d, 
       0x522, 0x52a, 0x53d, 0x543, 0x547, 0x54e, 0x554, 0x55c, 0x561, 0x564, 
       0x569, 0x572, 0x577, 0x585, 0x588, 0x58a, 0x58f, 0x593, 0x596, 0x59d, 
       0x5a2, 0x5ab, 0x5ae, 0x5b2, 0x5b5, 0x5bd, 0x5c1, 0x5c9, 0x5cc, 0x5ce, 
       0x5d7, 0x5dc, 0x5e0, 0x5e4, 0x5e7, 0x5f2, 0x5f7, 0x5fb, 0x602, 0x60b, 
       0x60f, 0x611, 0x615, 0x61e, 0x623, 0x625, 0x62e, 0x639, 0x640, 0x643, 
       0x64a, 0x64d, 0x659, 0x687, 0x692, 
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
