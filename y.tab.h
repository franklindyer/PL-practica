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
     LISTA_UNARIO_PREFIJO = 269,
     LISTA_UNARIO_POSTFIJO = 270,
     OP_TERN_PRIM_UN = 271,
     OP_TERN_SEG = 272,
     OP_UN_BIN = 273,
     OP_UNARIO = 274,
     OP_BINARIO_OR_LOG = 275,
     OP_BINARIO_AND_LOG = 276,
     OP_BINARIO_XOR = 277,
     OP_BINARIO_IG = 278,
     OP_BINARIO_COMP = 279,
     OP_BINARIO_MULT = 280,
     IDENTIFICADOR = 281,
     CADENA = 282,
     CONSTANTE = 283,
     PARIZQ = 284,
     PARDER = 285,
     CORIZQ = 286,
     CORDER = 287,
     LLAVIZQ = 288,
     LLAVDER = 289,
     COMA = 290,
     PYC = 291,
     ASIGN = 292,
     MARCA_INI_DECLAR_VARIABLES = 293,
     MARCA_FIN_DECLAR_VARIABLES = 294,
     OP_BINARIO_ASTAST = 295
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
#define LISTA_UNARIO_PREFIJO 269
#define LISTA_UNARIO_POSTFIJO 270
#define OP_TERN_PRIM_UN 271
#define OP_TERN_SEG 272
#define OP_UN_BIN 273
#define OP_UNARIO 274
#define OP_BINARIO_OR_LOG 275
#define OP_BINARIO_AND_LOG 276
#define OP_BINARIO_XOR 277
#define OP_BINARIO_IG 278
#define OP_BINARIO_COMP 279
#define OP_BINARIO_MULT 280
#define IDENTIFICADOR 281
#define CADENA 282
#define CONSTANTE 283
#define PARIZQ 284
#define PARDER 285
#define CORIZQ 286
#define CORDER 287
#define LLAVIZQ 288
#define LLAVDER 289
#define COMA 290
#define PYC 291
#define ASIGN 292
#define MARCA_INI_DECLAR_VARIABLES 293
#define MARCA_FIN_DECLAR_VARIABLES 294
#define OP_BINARIO_ASTAST 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

