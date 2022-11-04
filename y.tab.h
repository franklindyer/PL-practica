/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUBPROG_CLAVE = 258,
     CABECERA_PROGRAMA = 259,
     TIPO_PRIM = 260,
     TIPO_LISTA = 261,
     NOMB_IF = 262,
     NOMB_THEN = 263,
     NOMB_ELSE = 264,
     NOMB_WHILE = 265,
     NOMB_FOR = 266,
     NOMB_ENTRADA = 267,
     NOMB_SALIDA = 268,
     LISTA_SENT = 269,
     OP_TERN_PRIM_UN = 270,
     OP_TERN_SEG = 271,
     OP_UN_BIN = 272,
     OP_UNARIO = 273,
     OP_BINARIO = 274,
     IDENTIFICADOR = 275,
     CADENA = 276,
     CONSTANTE = 277,
     PARIZQ = 278,
     PARDER = 279,
     CORIZQ = 280,
     CORDER = 281,
     LLAVIZQ = 282,
     LLAVDER = 283,
     COMA = 284,
     PYC = 285,
     ASIGN = 286,
     MARCA_INI_DECLAR_VARIABLES = 287,
     MARCA_FIN_DECLAR_VARIABLES = 288
   };
#endif
/* Tokens.  */
#define SUBPROG_CLAVE 258
#define CABECERA_PROGRAMA 259
#define TIPO_PRIM 260
#define TIPO_LISTA 261
#define NOMB_IF 262
#define NOMB_THEN 263
#define NOMB_ELSE 264
#define NOMB_WHILE 265
#define NOMB_FOR 266
#define NOMB_ENTRADA 267
#define NOMB_SALIDA 268
#define LISTA_SENT 269
#define OP_TERN_PRIM_UN 270
#define OP_TERN_SEG 271
#define OP_UN_BIN 272
#define OP_UNARIO 273
#define OP_BINARIO 274
#define IDENTIFICADOR 275
#define CADENA 276
#define CONSTANTE 277
#define PARIZQ 278
#define PARDER 279
#define CORIZQ 280
#define CORDER 281
#define LLAVIZQ 282
#define LLAVDER 283
#define COMA 284
#define PYC 285
#define ASIGN 286
#define MARCA_INI_DECLAR_VARIABLES 287
#define MARCA_FIN_DECLAR_VARIABLES 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

