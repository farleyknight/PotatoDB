////////////////////////////////////////////////////////////////////////////////
// SQL Parser grammar
////////////////////////////////////////////////////////////////////////////////

grammar PotatoSQL;

main
    : (sql_stmt_list)* EOF
    ;


////////////////////////////////////////////////////////////////////////////////
// SQL Statment list
////////////////////////////////////////////////////////////////////////////////

sql_stmt_list
    : ';'* sql_stmt ( ';'+ sql_stmt )* ';'*
    ;

sql_stmt
    : alter_table_stmt
    | begin_stmt
    | commit_stmt
    | create_index_stmt
    | compound_select_stmt
    | create_table_stmt
    | drop_table_stmt
    | delete_stmt
    | drop_index_stmt
    | drop_table_stmt
    | factored_select_stmt
    | insert_stmt
    | pragma_stmt
    | rollback_stmt
    | simple_select_stmt
    | update_stmt
    | update_stmt_limited
    ;


////////////////////////////////////////////////////////////////////////////////
// Statements
////////////////////////////////////////////////////////////////////////////////

alter_table_stmt
    : K_ALTER K_TABLE ( database_name '.' )? table_name
    ( K_RENAME K_TO new_table_name
    | K_ADD K_COLUMN? column_def
    )
    ;

begin_stmt
    : K_BEGIN
    ;

commit_stmt
    : ( K_COMMIT | K_END )
    ;

compound_select_stmt
    : with_clause?
        select_core ( ( K_UNION K_ALL? | K_INTERSECT | K_EXCEPT ) select_core )+
        ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
        ( K_LIMIT expr ( ( K_OFFSET | ',' ) expr )? )?
    ;

create_index_stmt
    : K_CREATE K_UNIQUE? K_INDEX ( K_IF K_NOT K_EXISTS )?
        ( database_name '.' )? index_name K_ON table_name '(' indexed_column ( ',' indexed_column )* ')'
        ( K_WHERE expr )?
    ;

create_table_stmt
    : K_CREATE ( K_TEMP | K_TEMPORARY )? K_TABLE ( K_IF K_NOT K_EXISTS )?
        ( database_name '.' )? table_name
        ( '(' column_def ( ',' column_def )*? ( ',' table_constraint )* ')' ( K_WITHOUT IDENTIFIER )?
        | K_AS select_stmt
        )
    ;

delete_stmt
    : with_clause? K_DELETE K_FROM qualified_table_name
        ( K_WHERE expr )?
    ;

delete_stmt_limited
    : with_clause? K_DELETE K_FROM qualified_table_name
        ( K_WHERE expr )?
        ( ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
            K_LIMIT expr ( ( K_OFFSET | ',' ) expr )?
        )?
    ;

drop_index_stmt
    : K_DROP K_INDEX ( K_IF K_EXISTS )? ( database_name '.' )? index_name
    ;

drop_table_stmt
    : K_DROP K_TABLE ( K_IF K_EXISTS )? ( database_name '.' )? table_name
    ;

factored_select_stmt
    : with_clause?
        select_core ( compound_operator select_core )*
        ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
        ( K_LIMIT expr ( ( K_OFFSET | ',' ) expr )? )?
    ;

insert_stmt
    : with_clause? ( K_INSERT
        | K_REPLACE
        | K_INSERT K_OR K_REPLACE
        | K_INSERT K_OR K_ROLLBACK
        | K_INSERT K_OR K_ABORT
        | K_INSERT K_OR K_FAIL
        | K_INSERT K_OR K_IGNORE ) K_INTO
        ( database_name '.' )? table_name ( '(' column_name ( ',' column_name )* ')' )?
        ( K_VALUES '(' expr ( ',' expr )* ')' ( ',' '(' expr ( ',' expr )* ')' )*
        | select_stmt
        | K_DEFAULT K_VALUES
        )
    ;


pragma_stmt
    : K_PRAGMA ( database_name '.' )? pragma_name ( '=' pragma_value
                                                  | '(' pragma_value ')' )?
    ;

rollback_stmt
    : K_ROLLBACK ( K_TRANSACTION transaction_name? )? ( K_TO K_SAVEPOINT? savepoint_name )?
    ;

simple_select_stmt
    : with_clause?
        select_core ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
        ( K_LIMIT expr ( ( K_OFFSET | ',' ) expr )? )?
    ;

select_stmt
    : with_clause?
        select_or_values ( compound_operator select_or_values )*
        ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
        ( K_LIMIT expr ( ( K_OFFSET | ',' ) expr )? )?
    ;

select_or_values
    : K_SELECT ( K_DISTINCT | K_ALL )? result_column ( ',' result_column )*
        ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
        ( K_WHERE expr )?
        ( K_GROUP K_BY expr ( ',' expr )* ( K_HAVING expr )? )?
    | K_VALUES '(' expr ( ',' expr )* ')' ( ',' '(' expr ( ',' expr )* ')' )*
    ;

update_stmt
    : with_clause? K_UPDATE ( K_OR K_ROLLBACK
        | K_OR K_ABORT
        | K_OR K_REPLACE
        | K_OR K_FAIL
        | K_OR K_IGNORE )? qualified_table_name
        K_SET column_name '=' expr ( ',' column_name '=' expr )* ( K_WHERE expr )?
    ;

update_stmt_limited
    : with_clause? K_UPDATE ( K_OR K_ROLLBACK
        | K_OR K_ABORT
        | K_OR K_REPLACE
        | K_OR K_FAIL
        | K_OR K_IGNORE )? qualified_table_name
        K_SET column_name '=' expr ( ',' column_name '=' expr )* ( K_WHERE expr )?
        ( ( K_ORDER K_BY ordering_term ( ',' ordering_term )* )?
            K_LIMIT expr ( ( K_OFFSET | ',' ) expr )?
        )?
    ;

////////////////////////////////////////////////////////////////////////////////
// Expressions / Factors
////////////////////////////////////////////////////////////////////////////////

column_def
    : column_name type_name? column_constraint*
    ;

type_name
    : name+? ( '(' signed_number ')'
        | '(' signed_number ',' signed_number ')' )?
    ;

column_constraint
    : ( K_CONSTRAINT name )?
        ( K_PRIMARY K_KEY ( K_ASC | K_DESC )? conflict_clause K_AUTOINCREMENT?
        | K_NOT? K_NULL conflict_clause
        | K_UNIQUE conflict_clause
        | K_CHECK '(' expr ')'
        | K_DEFAULT (signed_number | literal_value | '(' expr ')')
        | K_COLLATE collation_name
        | foreign_key_clause
        )
    ;

conflict_clause
    : ( K_ON K_CONFLICT ( K_ROLLBACK
            | K_ABORT
            | K_FAIL
            | K_IGNORE
            | K_REPLACE
            )
        )?
    ;

expr
    : literal_value
    | BIND_PARAMETER
    | ( ( database_name '.' )? table_name '.' )? column_name
    | unary_operator expr
    | expr PIPE2 expr
    | expr ( '*' | '/' | '%' ) expr
    | expr ( '+' | '-' ) expr
    | expr ( LT2 | GT2 | '&' | '|' ) expr
    | expr ( '<' | LT_EQ | '>' | GT_EQ ) expr
    | expr ( '=' | EQ | NOT_EQ1 | NOT_EQ2 ) expr
    | expr K_NOT? K_IN ( '(' ( select_stmt
            | expr ( ',' expr )*
            )? 
            ')'
        | ( database_name '.' )? table_name )
    | expr K_AND expr
    | expr K_OR expr
    | function_name '(' ( K_DISTINCT? expr ( ',' expr )* | '*' )? ')'
    | '(' expr ')'
    | K_CAST '(' expr K_AS type_name ')'
    | expr K_COLLATE collation_name
    | expr K_NOT? ( K_LIKE | K_GLOB | K_REGEXP | K_MATCH ) expr ( K_ESCAPE expr )?
    | expr ( K_ISNULL | K_NOTNULL | K_NOT K_NULL )
    | expr K_IS K_NOT? expr
    | expr K_NOT? K_BETWEEN expr K_AND expr
    | ( ( K_NOT )? K_EXISTS )? '(' select_stmt ')'
    | K_CASE expr? ( K_WHEN expr K_THEN expr )+ ( K_ELSE expr )? K_END
    | raise_function
    ;


raise_function
    : K_RAISE '(' ( K_IGNORE 
               | ( K_ROLLBACK | K_ABORT | K_FAIL ) ',' error_message )
           ')'
     ;

foreign_key_clause
    : K_REFERENCES foreign_table ( '(' column_name ( ',' column_name )* ')' )?
        ( ( K_ON ( K_DELETE | K_UPDATE ) ( K_SET K_NULL
                | K_SET K_DEFAULT
                | K_CASCADE
                | K_RESTRICT
                | K_NO K_ACTION )
            | K_MATCH name
            ) 
        )*
        ( K_NOT? K_DEFERRABLE ( K_INITIALLY K_DEFERRED | K_INITIALLY K_IMMEDIATE )? )?
    ;

indexed_column
    : column_name ( K_COLLATE collation_name )? ( K_ASC | K_DESC )?
    ;

table_constraint
    : ( K_CONSTRAINT name )?
        ( ( K_PRIMARY K_KEY | K_UNIQUE ) '(' indexed_column ( ',' indexed_column )* ')' conflict_clause
        | K_CHECK '(' expr ')'
        | K_FOREIGN K_KEY '(' column_name ( ',' column_name )* ')' foreign_key_clause
        )
    ;


with_clause
    : K_WITH K_RECURSIVE? common_table_expression ( ',' common_table_expression )*
    ;

qualified_table_name
 : ( database_name '.' )? table_name ( K_INDEXED K_BY index_name
                                     | K_NOT K_INDEXED )?
 ;

ordering_term
 : expr ( K_COLLATE collation_name )? ( K_ASC | K_DESC )?
 ;

pragma_value
 : signed_number
 | name
 | STRING_LITERAL
 ;

common_table_expression
 : table_name ( '(' column_name ( ',' column_name )* ')' )? K_AS '(' select_stmt ')'
 ;

result_column
 : '*'
 | table_name '.' '*'
 | expr ( K_AS? column_alias )?
 ;

table_or_subquery
 : ( schema_name '.' )? table_name ( K_AS? table_alias )?
   ( K_INDEXED K_BY index_name
   | K_NOT K_INDEXED )?
 | ( schema_name '.' )? table_function_name '(' ( expr ( ',' expr )* )? ')' ( K_AS? table_alias )?
 | '(' ( table_or_subquery ( ',' table_or_subquery )*
       | join_clause )
   ')'
 | '(' select_stmt ')' ( K_AS? table_alias )?
 ;

join_clause
 : table_or_subquery ( join_operator table_or_subquery join_constraint )*
 ;

join_operator
 : ','
 | K_NATURAL? ( K_LEFT K_OUTER? | K_INNER | K_CROSS )? K_JOIN
 ;

join_constraint
 : ( K_ON expr
   | K_USING '(' column_name ( ',' column_name )* ')' )?
 ;

select_core
 : K_SELECT ( K_DISTINCT | K_ALL )? result_column ( ',' result_column )*
   ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
   ( K_WHERE expr )?
   ( K_GROUP K_BY expr ( ',' expr )* ( K_HAVING expr )? )?
 | K_VALUES '(' expr ( ',' expr )* ')' ( ',' '(' expr ( ',' expr )* ')' )*
 ;

compound_operator
 : K_UNION
 | K_UNION K_ALL
 | K_INTERSECT
 | K_EXCEPT
 ;

signed_number
 : ( '+' | '-' )? NUMERIC_LITERAL
 ;

literal_value
 : NUMERIC_LITERAL
 | STRING_LITERAL
 | BLOB_LITERAL

 | K_NULL
 | K_CURRENT_TIME
 | K_CURRENT_DATE
 | K_CURRENT_TIMESTAMP
 ;

unary_operator
 : '-'
 | '+'
 | '~'
 | K_NOT
 ;

error_message
    : STRING_LITERAL
    ;

module_argument
    : expr
    | column_def
    ;

column_alias
    : IDENTIFIER
    | STRING_LITERAL
    ;

////////////////////////////////////////////////////////////////////////////////
// Identifiers
////////////////////////////////////////////////////////////////////////////////

name
    : any_name
    ;

function_name
    : any_name
    ;

database_name
    : any_name
    ;

schema_name
    : any_name
    ;

table_function_name
    : any_name
    ;

table_name 
    : any_name
    ;

table_or_index_name 
    : any_name
    ;

new_table_name 
    : any_name
    ;

column_name 
    : any_name
    ;

collation_name 
    : any_name
    ;

foreign_table 
    : any_name
    ;

index_name
    : any_name
    ;

pragma_name 
    : any_name
    ;

savepoint_name 
    : any_name
    ;

transaction_name
    : any_name
    ;

table_alias
    : IDENTIFIER
    | STRING_LITERAL
    | '(' table_alias ')'
    ;

any_name
    : IDENTIFIER
    | keyword
    | STRING_LITERAL
    | '(' any_name ')'
    ;

////////////////////////////////////////////////////////////////////////////////
// Symbols
////////////////////////////////////////////////////////////////////////////////

SCOL : ';';
DOT : '.';
OPEN_PAR : '(';
CLOSE_PAR : ')';
COMMA : ',';
ASSIGN : '=';
STAR : '*';
PLUS : '+';
MINUS : '-';
TILDE : '~';
PIPE2 : '||';
DIV : '/';
MOD : '%';
LT2 : '<<';
GT2 : '>>';
AMP : '&';
PIPE : '|';
LT : '<';
LT_EQ : '<=';
GT : '>';
GT_EQ : '>=';
EQ : '==';
NOT_EQ1 : '!=';
NOT_EQ2 : '<>';

////////////////////////////////////////////////////////////////////////////////
// Keywords
////////////////////////////////////////////////////////////////////////////////

keyword
    : K_ALTER
    | K_AND
    | K_BEGIN
    | K_CASE
    ;


K_AND : A N D;
K_AS : A S;
K_ASC : A S C;

K_BEGIN : B E G I N;

K_GROUP : G R O U P;
K_JOIN : J O I N;
K_LIMIT : L I M I T;
K_NOT : N O T;

K_ON : O N;
K_OR : O R;
K_ORDER : O R D E R;
K_OUTER : O U T E R;


////////////////////////////////////////////////////////////////////////////////
// Identifiers
////////////////////////////////////////////////////////////////////////////////


IDENTIFIER
    : '"' (~'"' | '""')* '"'
    | '`' (~'`' | '``')* '`'
    | '[' ~']'* ']'
    | [a-zA-Z_] [a-zA-Z_0-9]* // TODO check: needs more chars in set
    ;

NUMERIC_LITERAL
    : DIGIT+ ( '.' DIGIT* )? ( E [-+]? DIGIT+ )?
    | '.' DIGIT+ ( E [-+]? DIGIT+ )?
    ;

STRING_LITERAL
    : '\'' ( ~'\'' | '\'\'' )* '\''
    ;

BLOB_LITERAL
    : X STRING_LITERAL
    ;

SINGLE_LINE_COMMENT
    : '--' ~[\r\n]* -> channel(HIDDEN)
    ;

MULTILINE_COMMENT
    : '/*' .*? ( '*/' | EOF ) -> channel(HIDDEN)
    ;

SPACES
    : [ \u000B\t\r\n] -> channel(HIDDEN)
    ;

UNEXPECTED_CHAR
    : .
    ;

////////////////////////////////////////////////////////////////////////////////
// Lexer Tokens
////////////////////////////////////////////////////////////////////////////////

fragment DIGIT : [0-9];

fragment A : [aA];
fragment B : [bB];
fragment C : [cC];
fragment D : [dD];
fragment E : [eE];
fragment F : [fF];
fragment G : [gG];
fragment H : [hH];
fragment I : [iI];
fragment J : [jJ];
fragment K : [kK];
fragment L : [lL];
fragment M : [mM];
fragment N : [nN];
fragment O : [oO];
fragment P : [pP];
fragment Q : [qQ];
fragment R : [rR];
fragment S : [sS];
fragment T : [tT];
fragment U : [uU];
fragment V : [vV];
fragment W : [wW];
fragment X : [xX];
fragment Y : [yY];
fragment Z : [zZ];
