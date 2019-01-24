/* declare.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CORTO_SCRIPT_DECLARE_H
#define CORTO_SCRIPT_DECLARE_H

#include "bake_config.h"

#define CORTO_SCRIPT_DECLARE_ETC ut_locate("corto.script.declare", NULL, UT_LOCATE_ETC)

/* $header() */
/* Definitions that are required by package headers (native types) go here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <corto.script.declare.c>

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

