/*
 * Python object definition of the libbde key protection types
 *
 * Copyright (C) 2011-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pybde_key_protection_types.h"
#include "pybde_libbde.h"
#include "pybde_python.h"
#include "pybde_unused.h"

PyTypeObject pybde_key_protection_types_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pybde.key_protection_types",
	/* tp_basicsize */
	sizeof( pybde_key_protection_types_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pybde_key_protection_types_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pybde key_protection types object (wraps LIBBDE_KEY_PROTECTION_TYPES)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pybde_key_protection_types_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pybde_key_protection_types_init_type(
     PyTypeObject *type_object )
{
	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "CLEAR_KEY",
	     PyInt_FromLong(
	      LIBBDE_KEY_PROTECTION_TYPE_CLEAR_KEY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "TPM",
	     PyInt_FromLong(
	      LIBBDE_KEY_PROTECTION_TYPE_TPM ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "STARTUP_KEY",
	     PyInt_FromLong(
	      LIBBDE_KEY_PROTECTION_TYPE_STARTUP_KEY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "RECOVERY_PASSWORD",
	     PyInt_FromLong(
	      LIBBDE_KEY_PROTECTION_TYPE_RECOVERY_PASSWORD ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "PASSWORD",
	     PyInt_FromLong(
	      LIBBDE_KEY_PROTECTION_TYPE_PASSWORD ) ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new key protection types object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pybde_key_protection_types_new(
           void )
{
	pybde_key_protection_types_t *pybde_key_protection_types = NULL;
	static char *function                                    = "pybde_key_protection_types_new";

	pybde_key_protection_types = PyObject_New(
	                              struct pybde_key_protection_types,
	                              &pybde_key_protection_types_type_object );

	if( pybde_key_protection_types == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize key protection types.",
		 function );

		goto on_error;
	}
	if( pybde_key_protection_types_init(
	     pybde_key_protection_types ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize key protection types.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pybde_key_protection_types );

on_error:
	if( pybde_key_protection_types != NULL )
	{
		Py_DecRef(
		 (PyObject *) pybde_key_protection_types );
	}
	return( NULL );
}

/* Intializes a key protection types object
 * Returns 0 if successful or -1 on error
 */
int pybde_key_protection_types_init(
     pybde_key_protection_types_t *pybde_key_protection_types )
{
	static char *function = "pybde_key_protection_types_init";

	if( pybde_key_protection_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid key protection types.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees a key protection types object
 */
void pybde_key_protection_types_free(
      pybde_key_protection_types_t *pybde_key_protection_types )
{
	static char *function = "pybde_key_protection_types_free";

	if( pybde_key_protection_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid key protection types.",
		 function );

		return;
	}
	if( pybde_key_protection_types->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid key protection types - missing ob_type.",
		 function );

		return;
	}
	if( pybde_key_protection_types->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid key protection types - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	pybde_key_protection_types->ob_type->tp_free(
	 (PyObject*) pybde_key_protection_types );
}

