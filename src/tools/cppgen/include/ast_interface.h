/*

COPYRIGHT

Copyright 1992, 1993, 1994 Sun Microsystems, Inc.  Printed in the United
States of America.  All Rights Reserved.

This product is protected by copyright and distributed under the following
license restricting its use.

The Interface Definition Language Compiler Front End (CFE) is made
available for your use provided that you include this license and copyright
notice on all media and documentation and the software program in which
this product is incorporated in whole or part. You may copy and extend
functionality (but may not remove functionality) of the Interface
Definition Language CFE without charge, but you are not authorized to
license or distribute it to anyone else except as part of a product or
program developed by you or with the express written consent of Sun
Microsystems, Inc. ("Sun").

The names of Sun Microsystems, Inc. and any of its subsidiaries or
affiliates may not be used in advertising or publicity pertaining to
distribution of Interface Definition Language CFE as permitted herein.

This license is effective until terminated by Sun for failure to comply
with this license.  Upon termination, you shall destroy or return all code
and documentation for the Interface Definition Language CFE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED AS IS WITH NO WARRANTIES OF
ANY KIND INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS
FOR A PARTICULAR PURPOSE, NONINFRINGEMENT, OR ARISING FROM A COURSE OF
DEALING, USAGE OR TRADE PRACTICE.

INTERFACE DEFINITION LANGUAGE CFE IS PROVIDED WITH NO SUPPORT AND WITHOUT
ANY OBLIGATION ON THE PART OF Sun OR ANY OF ITS SUBSIDIARIES OR AFFILIATES
TO ASSIST IN ITS USE, CORRECTION, MODIFICATION OR ENHANCEMENT.

SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES SHALL HAVE NO LIABILITY WITH
RESPECT TO THE INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY
INTERFACE DEFINITION LANGUAGE CFE OR ANY PART THEREOF.

IN NO EVENT WILL SUN OR ANY OF ITS SUBSIDIARIES OR AFFILIATES BE LIABLE FOR
ANY LOST REVENUE OR PROFITS OR OTHER SPECIAL, INDIRECT AND CONSEQUENTIAL
DAMAGES, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

Use, duplication, or disclosure by the government is subject to
restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
Technical Data and Computer Software clause at DFARS 252.227-7013 and FAR
52.227-19.

Sun, Sun Microsystems and the Sun logo are trademarks or registered
trademarks of Sun Microsystems, Inc.

SunSoft, Inc.  
2550 Garcia Avenue 
Mountain View, California  94043

NOTE:

SunOS, SunSoft, Sun, Solaris, Sun Microsystems or the Sun logo are
trademarks or registered trademarks of Sun Microsystems, Inc.

*/

#ifndef _AST_INTERFACE_AST_INTERFACE_HH
#define _AST_INTERFACE_AST_INTERFACE_HH


// Representation of interface:
//
// NOTE: add(AST_EnumValue *) is defined here because enums can
// be defined manifest locally; the constants defined in these
// enums are inserted in the enclosing scope.

/*
** DEPENDENCIES: ast_type.hh, utl_scope.hh, ast_decl.hh, utl_strlist.hh
**
** USE: Included from ast.hh
*/

#include <idl_fwd.h>
#include <idl_narrow.h>
#include <ast_type.h>
#include <utl_scope.h>
#include <ast_decl.h>


class AST_Interface : public virtual AST_Type, public virtual UTL_Scope
{
public:

   AST_Interface ();
   AST_Interface
   (
      bool local,
      bool abstract,
      UTL_ScopedName *n,
      AST_Interface **ih,
      long nih,
      const UTL_Pragmas &p
   );
   virtual ~AST_Interface() {}

   AST_Interface **inherits();
   void set_inherits(AST_Interface **i);
   long n_inherits();
   void set_n_inherits(long i);

   // Is this interface defined? This predicate returns FALSE when an
   // interface was forward declared but not defined yet, and TRUE in
   // all other cases.

   bool is_defined()
   {
      return (pd_n_inherits < 0) ? false : true;
   }

   DEF_NARROW_METHODS2(AST_Interface, AST_Type, UTL_Scope);
   DEF_NARROW_FROM_DECL(AST_Interface);
   DEF_NARROW_FROM_SCOPE(AST_Interface);

   virtual void dump(ostream &o);

protected:

    virtual void virt_set_gen_any (void);

private:
   // Data
   AST_Interface **pd_inherits; // Inherited interfaces
   // This is an array of pointers
   // to the inherited interfaces
   long pd_n_inherits; // How many of them? (-1 flags not defined)

   // Scope Management Protocol
   friend int yyparse();

   virtual AST_Constant *fe_add_constant(AST_Constant *c);
   virtual AST_Exception *fe_add_exception(AST_Exception *e);
   virtual AST_Attribute *fe_add_attribute(AST_Attribute *a);
   virtual AST_Operation *fe_add_operation(AST_Operation *o);
   virtual AST_Union *fe_add_union(AST_Union *u);
   virtual AST_Structure *fe_add_structure(AST_Structure *s);
   virtual AST_Enum *fe_add_enum(AST_Enum *e);
   virtual AST_EnumVal *fe_add_enum_val(AST_EnumVal *v);
   virtual AST_Typedef *fe_add_typedef(AST_Typedef *t);
   virtual AST_Opaque *fe_add_opaque(AST_Opaque *o);
   virtual AST_Value *fe_add_valuetype(AST_Value *v);
   virtual AST_BoxedValue *fe_add_boxed_valuetype(AST_BoxedValue *b);

};

#endif
