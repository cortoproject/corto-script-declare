/* declare.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CORTO_SCRIPT_DECLARE_H
#define CORTO_SCRIPT_DECLARE_H

#include <corto/corto.h>
#include <corto/script/declare/_project.h>
#include <corto/script/ast/c/c.h>
#include <corto/c/c.h>
#include <corto/script/ast/ast.h>

/* $header() */
/* Definitions that are required by package headers (native types) go here. */
/* $end */

#include <corto/script/declare/_type.h>
#include <corto/script/declare/_interface.h>
#include <corto/script/declare/_load.h>
#include <corto/script/declare/_binding.h>
#include <corto/script/declare/c/_api.h>

/* $body() */
#ifdef __cplusplus
extern "C" {
#endif

CORTO_SCRIPT_DECLARE_EXPORT
int16_t cortoscript_ast_declare(
    corto_object from,
    const char *file,
    ast_Node ast);

CORTO_SCRIPT_DECLARE_EXPORT
int16_t cortoscript_parse_expr(
    corto_object from,
    const char *input,
    corto_value *out);

#ifdef __cplusplus
}
#endif
/* $end */

#endif

