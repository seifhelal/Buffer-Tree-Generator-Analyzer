/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LBRACE = 258,
     RBRACE = 259,
     LPAREN = 260,
     RPAREN = 261,
     COLON = 262,
     SEMICOLON = 263,
     COMMA = 264,
     INDEX_1 = 265,
     INDEX_2 = 266,
     INDEX_3 = 267,
     PIN = 268,
     LIBRARY = 269,
     CELL_LEAKAGE_POWER = 270,
     CELL_FOOTPRINT = 271,
     AREA = 272,
     LEAKAGE_POWER = 273,
     FUNCTION = 274,
     CAPACITANCE = 275,
     MAX_CAPACITANCE = 276,
     WHEN = 277,
     DIRECTION = 278,
     VALUE = 279,
     LIBRARY_FEATURES = 280,
     CAPACITIVE_LOAD_UNIT = 281,
     OPERATING_CONDITIONS = 282,
     OUTPUT_VOLTAGE = 283,
     INPUT_VOLTAGE = 284,
     WIRE_LOAD = 285,
     CELL = 286,
     INTERNAL_POWER = 287,
     TIMING = 288,
     INPUT = 289,
     OUTPUT = 290,
     RISE_POWER = 291,
     FALL_POWER = 292,
     TIMING_SENSE = 293,
     POSITIVE_UNATE = 294,
     NEGATIVE_UNATE = 295,
     NON_UNATE = 296,
     CELL_RISE = 297,
     CELL_FALL = 298,
     RISE_TRANSITION = 299,
     FALL_TRANSITION = 300,
     SDF_COND = 301,
     VALUES = 302,
     RELATED_PIN = 303,
     PROCESS = 304,
     TEMPERATURE = 305,
     VOLTAGE = 306,
     TREE_TYPE = 307,
     VARIABLE_1 = 308,
     VARIABLE_2 = 309,
     VARIABLE_3 = 310,
     VOL = 311,
     VOH = 312,
     VOMIN = 313,
     VOMAX = 314,
     VIL = 315,
     VIH = 316,
     VIMIN = 317,
     VIMAX = 318,
     RESISTANCE = 319,
     SLOPE = 320,
     FANOUT_LENGTH = 321,
     EQUAL_OR_OPPOSITE_OUTPUT = 322,
     TIMING_TYPE = 323,
     RISE_CONSTRAINT = 324,
     FALL_CONSTRAINT = 325,
     CLOCK = 326,
     TRUE = 327,
     FALSE = 328,
     MAX_TRANSITION = 329,
     MIN_PULSE_WIDTH_HIGH = 330,
     MIN_PULSE_WIDTH_LOW = 331,
     FF = 332,
     LATCH = 333,
     DRIVER_TYPE = 334,
     DONT_TOUCH = 335,
     DONT_USE = 336,
     THREE_STATE = 337,
     POWER = 338,
     SIGNAL_TYPE = 339,
     TEST_CELL = 340,
     INOUT = 341,
     CLOCK_GATING_INTEGRATED_CELL = 342,
     CLOCK_GATE_ENABLE_PIN = 343,
     CLOCK_GATE_CLOCK_PIN = 344,
     CLOCK_GATE_OUT_PIN = 345,
     CLOCK_GATE_TEST_PIN = 346,
     STATETABLE = 347,
     STATE_FUNCTION = 348,
     TABLE = 349,
     INTERNAL_NODE = 350,
     INTERNAL = 351,
     INTEGER = 352,
     DECIMAL = 353,
     STRING = 354,
     QUOTED_STRING = 355
   };
#endif
#define LBRACE 258
#define RBRACE 259
#define LPAREN 260
#define RPAREN 261
#define COLON 262
#define SEMICOLON 263
#define COMMA 264
#define INDEX_1 265
#define INDEX_2 266
#define INDEX_3 267
#define PIN 268
#define LIBRARY 269
#define CELL_LEAKAGE_POWER 270
#define CELL_FOOTPRINT 271
#define AREA 272
#define LEAKAGE_POWER 273
#define FUNCTION 274
#define CAPACITANCE 275
#define MAX_CAPACITANCE 276
#define WHEN 277
#define DIRECTION 278
#define VALUE 279
#define LIBRARY_FEATURES 280
#define CAPACITIVE_LOAD_UNIT 281
#define OPERATING_CONDITIONS 282
#define OUTPUT_VOLTAGE 283
#define INPUT_VOLTAGE 284
#define WIRE_LOAD 285
#define CELL 286
#define INTERNAL_POWER 287
#define TIMING 288
#define INPUT 289
#define OUTPUT 290
#define RISE_POWER 291
#define FALL_POWER 292
#define TIMING_SENSE 293
#define POSITIVE_UNATE 294
#define NEGATIVE_UNATE 295
#define NON_UNATE 296
#define CELL_RISE 297
#define CELL_FALL 298
#define RISE_TRANSITION 299
#define FALL_TRANSITION 300
#define SDF_COND 301
#define VALUES 302
#define RELATED_PIN 303
#define PROCESS 304
#define TEMPERATURE 305
#define VOLTAGE 306
#define TREE_TYPE 307
#define VARIABLE_1 308
#define VARIABLE_2 309
#define VARIABLE_3 310
#define VOL 311
#define VOH 312
#define VOMIN 313
#define VOMAX 314
#define VIL 315
#define VIH 316
#define VIMIN 317
#define VIMAX 318
#define RESISTANCE 319
#define SLOPE 320
#define FANOUT_LENGTH 321
#define EQUAL_OR_OPPOSITE_OUTPUT 322
#define TIMING_TYPE 323
#define RISE_CONSTRAINT 324
#define FALL_CONSTRAINT 325
#define CLOCK 326
#define TRUE 327
#define FALSE 328
#define MAX_TRANSITION 329
#define MIN_PULSE_WIDTH_HIGH 330
#define MIN_PULSE_WIDTH_LOW 331
#define FF 332
#define LATCH 333
#define DRIVER_TYPE 334
#define DONT_TOUCH 335
#define DONT_USE 336
#define THREE_STATE 337
#define POWER 338
#define SIGNAL_TYPE 339
#define TEST_CELL 340
#define INOUT 341
#define CLOCK_GATING_INTEGRATED_CELL 342
#define CLOCK_GATE_ENABLE_PIN 343
#define CLOCK_GATE_CLOCK_PIN 344
#define CLOCK_GATE_OUT_PIN 345
#define CLOCK_GATE_TEST_PIN 346
#define STATETABLE 347
#define STATE_FUNCTION 348
#define TABLE 349
#define INTERNAL_NODE 350
#define INTERNAL 351
#define INTEGER 352
#define DECIMAL 353
#define STRING 354
#define QUOTED_STRING 355




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 54 "parser.yy"
typedef union YYSTYPE {
int integer;
double decimal;
char *string;
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 243 "parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



