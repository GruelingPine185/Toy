#pragma once

typedef enum TokenType {
	//types
	TOKEN_NULL,
	TOKEN_BOOLEAN,
	TOKEN_INTEGER,
	TOKEN_FLOAT,
	TOKEN_STRING,
	TOKEN_ARRAY,
	TOKEN_DICTIONARY,
	TOKEN_FUNCTION,
	TOKEN_OPAQUE,
	TOKEN_ANY,

	//keywords and reserved words
	TOKEN_AS,
	TOKEN_ASSERT,
	TOKEN_BREAK,
	TOKEN_CLASS,
	TOKEN_CONST,
	TOKEN_CONTINUE,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_EXPORT,
	TOKEN_FOR,
	TOKEN_FOREACH,
	TOKEN_IF,
	TOKEN_IMPORT,
	TOKEN_IN,
	TOKEN_OF,
	TOKEN_PRINT,
	TOKEN_RETURN,
	TOKEN_TYPE,
	TOKEN_ASTYPE,
	TOKEN_TYPEOF,
	TOKEN_VAR,
	TOKEN_WHILE,

	//literal values
	TOKEN_IDENTIFIER,
	TOKEN_LITERAL_TRUE,
	TOKEN_LITERAL_FALSE,
	TOKEN_LITERAL_INTEGER,
	TOKEN_LITERAL_FLOAT,
	TOKEN_LITERAL_STRING,

	//math operators
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_MODULO,
	TOKEN_PLUS_ASSIGN,
	TOKEN_MINUS_ASSIGN,
	TOKEN_MULTIPLY_ASSIGN,
	TOKEN_DIVIDE_ASSIGN,
	TOKEN_MODULO_ASSIGN,
	TOKEN_PLUS_PLUS,
	TOKEN_MINUS_MINUS,
	TOKEN_ASSIGN,

	//logical operators
	TOKEN_PAREN_LEFT,
	TOKEN_PAREN_RIGHT,
	TOKEN_BRACKET_LEFT,
	TOKEN_BRACKET_RIGHT,
	TOKEN_BRACE_LEFT,
	TOKEN_BRACE_RIGHT,
	TOKEN_NOT,
	TOKEN_NOT_EQUAL,
	TOKEN_EQUAL,
	TOKEN_LESS,
	TOKEN_GREATER,
	TOKEN_LESS_EQUAL,
	TOKEN_GREATER_EQUAL,
	TOKEN_AND,
	TOKEN_OR,

	//other operators
	TOKEN_COLON,
	TOKEN_SEMICOLON,
	TOKEN_COMMA,
	TOKEN_DOT,
	TOKEN_PIPE,
	TOKEN_REST,

	//meta tokens
	TOKEN_PASS,
	TOKEN_ERROR,
	TOKEN_EOF,
} TokenType;
