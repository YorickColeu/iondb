/******************************************************************************/
/**
@file		test_cpp_wrapper3.cpp
@author		Eric Huang, Dana Klamut
@brief		Unit test for the C++ Wrapper
@todo		These tests need to be fully fleshed out.
@copyright	Copyright 2017
			The University of British Columbia,
			IonDB Project Contributors (see AUTHORS.md)
@par Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

@par 1.Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.

@par 2.Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.

@par 3.Neither the name of the copyright holder nor the names of its contributors
	may be used to endorse or promote products derived from this software without
	specific prior written permission.

@par THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
/******************************************************************************/

#include "test_cpp_wrapper3.h"

#define NULL_VALUE 999	/** Value arbitrarily chosen to represent NULL */

/**
@brief	This function performs an open and close on a dictionary.
*/
void
cpp_wrapper_open_close(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict,
	int key,
	int value
) {
	ion_err_t				error;
	ion_dictionary_id_t		gdict_id	= dict->dict.instance->id;
	ion_key_size_t			key_size	= dict->dict.instance->record.key_size;
	ion_value_size_t		val_size	= dict->dict.instance->record.value_size;
	ion_key_type_t			key_type	= dict->dict.instance->key_type;
	ion_dictionary_size_t	dict_size	= dict->dict_size;
	ion_dictionary_type_t	dict_type	= dict->dict.instance->type;

	/* Insert test record so we can check data integrity after we close/open */
	cpp_wrapper_insert(tc, dict, key, value, boolean_false);

	/* Check the test record */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);

	error = dict->close();

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, error);

	ion_dictionary_config_info_t config = {
		gdict_id, 0, key_type, key_size, val_size, dict_size, dict_type
	};

	error = dict->open(config);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, error);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.key_size, key_size);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.value_size, val_size);

	/* Check the test record */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);
}

/**
@brief	This function performs an open and close on a dictionary.
*/
void
cpp_wrapper_static_open_close(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict,
	int key,
	int value
) {
	ion_err_t				error;
	ion_dictionary_id_t		gdict_id	= dict->dict.instance->id;
	ion_key_size_t			key_size	= dict->dict.instance->record.key_size;
	ion_value_size_t		val_size	= dict->dict.instance->record.value_size;
	ion_key_type_t			key_type	= dict->dict.instance->key_type;
	ion_dictionary_size_t	dict_size	= dict->dict_size;
	ion_dictionary_type_t	dict_type	= dict->dict.instance->type;

	/* Insert test record so we can check data integrity after we close/open */
	cpp_wrapper_insert(tc, dict, key, value, boolean_false);

	/* Check the test record */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);

	error = dict->close();

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, error);

	ion_dictionary_config_info_t config = {
		gdict_id, 0, key_type, key_size, val_size, dict_size, dict_type
	};

	int type = 0;

	switch (dict_type) {
		case dictionary_type_bpp_tree_t: {
			dict = BppTree<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_flat_file_t: {
			dict = FlatFile<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_skip_list_t: {
			dict = SkipList<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_hash_t: {
			dict = OpenAddressHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_file_hash_t: {
			dict = OpenAddressFileHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_linear_hash_t: {
			dict = LinearHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_error_t: {
			dict					= SkipList<int, int>::openDictionary(config, type, type);
			dict->last_status.error = err_uninitialized;
			break;
		}
	}

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, dict->last_status.error);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.key_size, key_size);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.value_size, val_size);

	/* Check the test record */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);

	delete dict;
}

/**
@brief	This function performs an open and close on a dictionary in addition
		to performing inserts, updates, and deletes.
*/
void
cpp_wrapper_static_open_close_complex(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict,
	int key,
	int value
) {
	ion_err_t				error;
	ion_dictionary_id_t		gdict_id	= dict->dict.instance->id;
	ion_key_size_t			key_size	= dict->dict.instance->record.key_size;
	ion_value_size_t		val_size	= dict->dict.instance->record.value_size;
	ion_key_type_t			key_type	= dict->dict.instance->key_type;
	ion_dictionary_size_t	dict_size	= dict->dict_size;
	ion_dictionary_type_t	dict_type	= dict->dict.instance->type;

	/* Insert test records so we can check data integrity after we close/open */
	cpp_wrapper_insert(tc, dict, key, value, boolean_false);
	cpp_wrapper_insert(tc, dict, key + 10, value + 10, boolean_false);

	/* Check the test records */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);
	cpp_wrapper_get(tc, dict, key + 10, value + 10, err_ok, 1);
	cpp_wrapper_get(tc, dict, key - 10, value - 10, err_item_not_found, 0);

	error = dict->close();

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, error);

	ion_dictionary_config_info_t config = {
		gdict_id, 0, key_type, key_size, val_size, dict_size, dict_type
	};

	int type = 0;

	switch (dict_type) {
		case dictionary_type_bpp_tree_t: {
			dict = BppTree<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_flat_file_t: {
			dict = FlatFile<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_skip_list_t: {
			dict = SkipList<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_hash_t: {
			dict = OpenAddressHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_file_hash_t: {
			dict = OpenAddressFileHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_linear_hash_t: {
			dict = LinearHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_error_t: {
			dict					= SkipList<int, int>::openDictionary(config, type, type);
			dict->last_status.error = err_uninitialized;
			break;
		}
	}

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, dict->last_status.error);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.key_size, key_size);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.value_size, val_size);

	/* Check the test records */
	cpp_wrapper_get(tc, dict, key, value, err_ok, 1);
	cpp_wrapper_get(tc, dict, key + 10, value + 10, err_ok, 1);

	/* Update one test record */
	cpp_wrapper_update(tc, dict, key, value + 1, err_ok, 1, boolean_true);

	/* Try and update a record that does not exist. We expect an upsert to occur. */
	cpp_wrapper_update(tc, dict, key - 10, value - 10, err_ok, 1, boolean_true);

	/* Close dictionary again. */
	error = dict->close();

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, error);

	switch (dict_type) {
		case dictionary_type_bpp_tree_t: {
			dict = BppTree<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_flat_file_t: {
			dict = FlatFile<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_skip_list_t: {
			dict = SkipList<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_hash_t: {
			dict = OpenAddressHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_open_address_file_hash_t: {
			dict = OpenAddressFileHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_linear_hash_t: {
			dict = LinearHash<int, int>::openDictionary(config, type, type);
			break;
		}

		case dictionary_type_error_t: {
			dict					= SkipList<int, int>::openDictionary(config, type, type);
			dict->last_status.error = err_uninitialized;
			break;
		}
	}

	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, err_ok, dict->last_status.error);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.key_size, key_size);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, dict->dict.instance->record.value_size, val_size);

	/* Check the test records. */
	/* Check the test records */
	cpp_wrapper_get(tc, dict, key, value + 1, err_ok, 1);
	cpp_wrapper_get(tc, dict, key + 10, value + 10, err_ok, 1);
	cpp_wrapper_get(tc, dict, key - 10, value - 10, err_ok, 1);

	delete dict;
}

/* =================================================== TEST CASES =================================================== */

/**
@brief	Aggregate test to test equality cursor query on all dictionary implementations.
*/
void
test_static_equality(
	planck_unit_test_t	*tc,
	int					key
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 20, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_equality_duplicates(tc, dict, key);
	delete dict;

	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_equality_duplicates(tc, dict, key);
	delete dict;

	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_equality_no_duplicates(tc, dict, key);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_equality_no_duplicates(tc, dict, key);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_equality_no_duplicates(tc, dict, key);
	delete dict;
}

/**
@brief	Aggregate test to test equality cursor query on all dictionary implementations.
*/
void
test_cpp_wrapper_equality_all(
	planck_unit_test_t *tc
) {
	test_cpp_wrapper_equality(tc, 10);
	test_cpp_wrapper_equality(tc, 4);
	test_cpp_wrapper_equality(tc, 3);
	test_cpp_wrapper_equality(tc, 6);
}

/**
@brief	Aggregate test to test equality cursor query on all dictionary implementations.
*/
void
test_static_equality_all(
	planck_unit_test_t *tc
) {
	test_static_equality(tc, 10);
	test_static_equality(tc, 4);
	test_static_equality(tc, 3);
	test_static_equality(tc, 6);
}

/**
@brief	This function tests an equality cursor query on an empty dictionary for a key
		that doesn't exist.
*/
void
test_cpp_wrapper_equality_nonexist_empty(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int values[1] = { 0 };

	cpp_wrapper_setup(tc, dict, ion_fill_none);
	cpp_wrapper_equality(tc, dict, NULL_VALUE, values, 0, boolean_false);
}

/**
@brief	Aggregate test to test equality cursor query on an empty dictionary
		for a key that doesn't exist on all dictionary implementations.
*/
void
test_cpp_wrapper_equality_nonexist_empty_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_equality_nonexist_empty(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_equality_nonexist_empty(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_equality_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_equality_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_equality_nonexist_empty(tc, dict);
	delete dict;
}

/**
@brief	Tests an insertion and then attempts to perform an equality cursor query
		when the desired key is not present.
*/
void
test_cpp_wrapper_equality_nonexist(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	for (int i = 0; i < 10; i++) {
		cpp_wrapper_insert(tc, dict, i, i * 2, boolean_false);
	}

	int values[1] = { NULL_VALUE };

	cpp_wrapper_equality(tc, dict, 20, values, 0, boolean_false);
}

/**
@brief	Aggregate test to test equality cursor query when the desired key is not
		present on all dictionary implementations.
*/
void
test_cpp_wrapper_equality_nonexist_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_equality_nonexist(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_equality_nonexist(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_equality_nonexist(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_equality_nonexist(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_equality_nonexist(tc, dict);
	delete dict;
}

/**
@brief	Aggregate test to test small range cursor query on all dictionary implementations.
*/
void
test_cpp_wrapper_range_single_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_range(tc, dict, 5, 6);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range(tc, dict, 1, 2);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range(tc, dict, 17, 18);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_range(tc, dict, 30, 31);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 15);
	test_cpp_wrapper_range(tc, dict, 6, 7);
	delete dict;
}

/**
@brief	Aggregate test to test large range cursor query on all dictionary implementations.
*/
void
test_cpp_wrapper_range_multiple_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_range(tc, dict, 5, 10);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range(tc, dict, 1, 7);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range(tc, dict, 13, 18);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_range(tc, dict, 30, 39);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range(tc, dict, 6, 23);
	delete dict;
}

/**
@brief	Tests a range cursor on an empty dictionary where clearly no keys within
		the range exist.
*/
void
test_cpp_wrapper_range_nonexist_empty(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int values[1] = { NULL_VALUE };

	cpp_wrapper_setup(tc, dict, ion_fill_none);
	cpp_wrapper_range(tc, dict, 0, 50, values, 0, boolean_false);
}

/**
@brief	Aggregate test to test a range cursor query on an empty dictionary on all
		dictionary implementations.
*/
void
test_cpp_wrapper_range_nonexist_empty_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	/* This test has been excluded as the BppTree range query functionality */
	/* needs to be revised. */

/*	dict = new BppTree<int, int>(key_type_numeric_signed, sizeof(int), sizeof(int)); */
/*	test_cpp_wrapper_range_nonexist_empty(tc, dict); */
/*	delete dict; */

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range_nonexist_empty(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_range_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_range_nonexist_empty(tc, dict);
	delete dict;
}

/**
@brief	Tests an insertion and then attempts to perform a range cursor query
		on range values not present in dictionary.
*/
void
test_cpp_wrapper_range_nonexist(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int records[5]		= { 3, 10, 25, 50, 70 };
	int records_length	= sizeof(records) / sizeof(int);

	for (int i = 0; i < records_length; i++) {
		cpp_wrapper_insert(tc, dict, records[i], records[i], boolean_true);
	}

	cpp_wrapper_range(tc, dict, -1000, 0, records, 0, boolean_false);
}

/**
@brief	Aggregate test to test range cursor query of nonexistent values on all
		implementations.
*/
void
test_cpp_wrapper_range_nonexist_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_range_nonexist(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range_nonexist(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range_nonexist(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_range_nonexist(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 15);
	test_cpp_wrapper_range_nonexist(tc, dict);
	delete dict;
}

/**
@brief	Tests an insertion and then attempts to perform an equality cursor query
		where the desired records are in the middle of the dictionary.
*/
void
test_cpp_wrapper_range_exist_single(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int records[5]			= { 3, 10, 25, 50, 70 };
	int expected_records[2] = { 25, 50 };
	int records_length		= sizeof(records) / sizeof(int);

	for (int i = 0; i < records_length; i++) {
		cpp_wrapper_insert(tc, dict, records[i], records[i], boolean_true);
	}

	cpp_wrapper_range(tc, dict, 15, 55, expected_records, 2, boolean_true);
}

/**
@brief	Aggregate test to test small range cursor query on all dictionary implementations.
*/
void
test_cpp_wrapper_range_exist_single_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_range_exist_single(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range_exist_single(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range_exist_single(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_range_exist_single(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 15);
	test_cpp_wrapper_range_exist_single(tc, dict);
	delete dict;
}

/**
@brief	Tests an insertion and then attempts to perform an equality cursor query
		where range query includes all records present in the dictionary.
*/
void
test_cpp_wrapper_range_all(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int records[5]		= { 1, 2, 3, 4, 5 };
	int records_length	= sizeof(records) / sizeof(int);

	for (int i = 0; i < records_length; i++) {
		cpp_wrapper_insert(tc, dict, records[i], records[i], boolean_true);
	}

	cpp_wrapper_range(tc, dict, 1, 5, records, records_length, boolean_true);
}

/**
@brief	Aggregate test to test range cursor query of entire dictionary on all
		dictionary implementations.
*/
void
test_cpp_wrapper_range_all_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 15);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;
}

/**
@brief	Aggregate test to test an all records cursor query on all dictionary
		implementations.
*/
void
test_cpp_wrapper_all_records_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_all_records(tc, dict, 10);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	test_cpp_wrapper_all_records(tc, dict, 4);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_all_records(tc, dict, 13);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_all_records(tc, dict, 5);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_all_records(tc, dict, 8);
	delete dict;
}

/**
@brief	Tests an all records cursor on an empty dictionary.
*/
void
test_cpp_wrapper_all_records_nonexist_empty(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int values[1] = { NULL_VALUE };

	cpp_wrapper_setup(tc, dict, ion_fill_none);
	cpp_wrapper_all_records(tc, dict, values, 0, boolean_false);
}

/**
@brief	Aggregate test to test an all records cursor query of an empty dictionary
		on all dictionary implementations.
*/
void
test_cpp_wrapper_all_records_nonexist_empty_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_all_records_nonexist_empty(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 10);
	test_cpp_wrapper_all_records_nonexist_empty(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_all_records_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_all_records_nonexist_empty(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_all_records_nonexist_empty(tc, dict);
	delete dict;
}

/**
@brief	Tests an all records cursor query where the keys are sparsely inserted.
*/
void
test_cpp_wrapper_all_records_populated(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int records[5]		= { 3, 10, 25, 50, 70 };
	int records_length	= sizeof(records) / sizeof(int);

	for (int i = 0; i < records_length; i++) {
		cpp_wrapper_insert(tc, dict, records[i], records[i], boolean_true);
	}

	cpp_wrapper_all_records(tc, dict, records, records_length, boolean_true);
}

/**
@brief	Aggregate test to test all records cursor query of a sparsely populated
		dictionary on all dictionary implementations.
*/
void
test_cpp_wrapper_all_records_populated_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_all_records_populated(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	test_cpp_wrapper_all_records_populated(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_all_records_populated(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_all_records_populated(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_all_records_populated(tc, dict);
	delete dict;
}

/**
@brief	Tests an all records cursor query where keys are not inserted in
		increasing order and include a wide range.
*/
void
test_cpp_wrapper_all_records_random(
	planck_unit_test_t *tc,
	Dictionary<int, int> *dict
) {
	int records[5]		= { -111, 113, 5, 50, -225 };
	int records_length	= sizeof(records) / sizeof(int);

	for (int i = 0; i < records_length; i++) {
		cpp_wrapper_insert(tc, dict, records[i], records[i], boolean_true);
	}

	cpp_wrapper_all_records(tc, dict, records, records_length, boolean_true);
}

/**
@brief	Aggregate test to test an all records cursor query on all dictionary implementations
		where keys are not inserted in increasing order and include a wide range.
*/
void
test_cpp_wrapper_all_records_random_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 20);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;
}

/**
@brief	Aggregate test to test open/close functionality on all dictionary implementations.
*/
void
test_cpp_wrapper_open_close_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	dict = new BppTree<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int));
	cpp_wrapper_open_close(tc, dict, 66, 12);
	delete dict;

	dict = new FlatFile<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 15);
	cpp_wrapper_open_close(tc, dict, 45, 14);
	delete dict;

	dict = new OpenAddressHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	cpp_wrapper_open_close(tc, dict, 3, 15);
	delete dict;

	dict = new OpenAddressFileHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	cpp_wrapper_open_close(tc, dict, 5, 12);
	delete dict;

	dict = new SkipList<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	cpp_wrapper_open_close(tc, dict, 1, 13);
	delete dict;

/*	dict = new LinearHash<int, int>(0, key_type_numeric_signed, sizeof(int), sizeof(int), 7); */
/*	cpp_wrapper_open_close(tc, dict, 2, 22); */
/*	delete dict; */
}

/**
@brief	This function tests whether or not we can build and a dictionary
		on all dictionary implementations.
*/
void
test_static_setup_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 20, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_setup(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_setup(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_setup(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_setup(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_setup(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/* */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_setup(tc, dict); */
/*	delete dict; */
}

/**
@brief	This function tests multiple insertions into a dictionary on all
		dictionary implementations.
*/
void
test_static_insert_multiple_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 20, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_insert_multiple(tc, dict);
	delete dict;

	config.dictionary_size	= 7;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_insert_multiple(tc, dict);
	delete dict;

	config.dictionary_size	= 30;
	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_insert_multiple(tc, dict);
	delete dict;

	config.dictionary_size	= 50;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_insert_multiple(tc, dict);
	delete dict;

	config.dictionary_size	= 50;
	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_insert_multiple(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 50, */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_insert_multiple(tc, dict); */
/*	delete dict; */
}

/**
@brief	This function tests retrieval on a dictionary with a whole bunch of
		records in it on all dictionary implementations.
*/
void
test_static_get_lots_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 20, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_lots(tc, dict);
	delete dict;

	config.dictionary_size	= 7;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_lots(tc, dict);
	delete dict;

	config.dictionary_size	= 30;
	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_lots(tc, dict);
	delete dict;

	config.dictionary_size	= 50;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_lots(tc, dict);
	delete dict;

	config.dictionary_size	= 50;
	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_lots(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 50, */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_get_lots(tc, dict); */
/*	delete dict; */
}

/**
@brief	This function tests retrieval on a dictionary for many keys that don't
		exist on all dictionary implementations.
*/
void
test_static_get_nonexist_many_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_nonexist_many(tc, dict);
	delete dict;

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_nonexist_many(tc, dict);
	delete dict;

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_nonexist_many(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_nonexist_many(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_get_nonexist_many(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 100; */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_get_nonexist_many(tc, dict); */
/*	delete dict; */
}

/**
@brief	This function tests an update on a dictionary that has many elements,
		which includes the one we are looking for on all dictionary implementations.
*/
void
test_static_update_exist_in_many_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_update_exist_in_many(tc, dict);
	delete dict;

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_update_exist_in_many(tc, dict);
	delete dict;

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_update_exist_in_many(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_update_exist_in_many(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_update_exist_in_many(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 100; */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_update_exist_in_many(tc, dict); */
/*	delete dict; */
}

/**
@brief	Aggregate test to test range cursor query of entire dictionary on all
		dictionary implementations.
*/
void
test_static_range_all_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_range_all(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 100; */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_range_all(tc, dict); */
/*	delete dict; */
}

/**
@brief	Aggregate test to test an all records cursor query on all dictionary implementations
		where keys are not inserted in increasing order and include a wide range.
*/
void
test_static_all_records_random_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dict;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dict = BppTree<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_skip_list_t;

	dict					= SkipList<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_flat_file_t;

	dict					= FlatFile<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dict					= OpenAddressHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dict					= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	test_cpp_wrapper_all_records_random(tc, dict);
	delete dict;

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_size = 100; */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dict = LinearHash<int, int>::openDictionary(config, type, type); */
/*	test_cpp_wrapper_all_records_random(tc, dict); */
/*	delete dict; */
}

/**
@brief Tests opening a dictionary using the static open method on all dictionary
		implementations.
*/
void
test_static_open_close_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dictionary;

	dictionary = new BppTree<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int));
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 66, 12);

	dictionary = new FlatFile<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 45, 14);

	dictionary = new OpenAddressHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 3, 15);

	dictionary = new OpenAddressFileHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 5, 12);

	dictionary = new SkipList<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 1, 13);

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	dictionary = new LinearHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 7); */
/*	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status); */
/*	cpp_wrapper_static_open_close(tc, dictionary, 2, 22); */
}

/**
@brief Tests opening a dictionary using the static open method on all dictionary
		implementations.
*/
void
test_static_create_open_close_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dictionary;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dictionary = BppTree<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 66, 12);

	config.dictionary_type	= dictionary_type_flat_file_t;

	dictionary				= FlatFile<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 45, 14);

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dictionary				= OpenAddressHash<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 3, 15);

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dictionary				= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 5, 12);

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dictionary				= SkipList<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close(tc, dictionary, 1, 13);

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dictionary = LinearHash<int, int>::openDictionary(config, type, type); */
/*	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status); */
/*	cpp_wrapper_static_open_close(tc, dictionary, 2, 22); */
}

/**
@brief Tests opening a dictionary using the static open method on all dictionary
		implementations.
*/
void
test_static_open_close_complex_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dictionary;

	dictionary = new BppTree<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int));
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 66, 12);

	dictionary = new FlatFile<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 30);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 45, 14);

	dictionary = new OpenAddressHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 3, 15);

	dictionary = new OpenAddressFileHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 50);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 5, 12);

	dictionary = new SkipList<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 7);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 1, 13);

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	dictionary = new LinearHash<int, int>(1, key_type_numeric_signed, sizeof(int), sizeof(int), 7); */
/*	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status); */
/*	cpp_wrapper_static_open_close(tc, dictionary, 2, 22); */
}

/**
@brief Tests opening a dictionary using the static open method on all dictionary
		implementations.
*/
void
test_static_create_open_close_complex_all(
	planck_unit_test_t *tc
) {
	Dictionary<int, int> *dictionary;

	ion_dictionary_config_info_t config = {
		.id = 1, .use_type = 0, .type = key_type_numeric_signed, .key_size = sizeof(int), .value_size = sizeof(int), .dictionary_size = 100, .dictionary_type = dictionary_type_bpp_tree_t, .dictionary_status = err_ok
	};

	int type = 0;

	dictionary = BppTree<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 66, 12);

	config.dictionary_type	= dictionary_type_flat_file_t;

	dictionary				= FlatFile<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 45, 14);

	config.dictionary_size	= 160;
	config.dictionary_type	= dictionary_type_open_address_hash_t;

	dictionary				= OpenAddressHash<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 3, 15);

	config.dictionary_type	= dictionary_type_open_address_file_hash_t;

	dictionary				= OpenAddressFileHash<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 5, 12);

	config.dictionary_size	= 100;
	config.dictionary_type	= dictionary_type_skip_list_t;

	dictionary				= SkipList<int, int>::openDictionary(config, type, type);
	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status);
	cpp_wrapper_static_open_close_complex(tc, dictionary, 1, 13);

	/* Uncomment when LinearHash dictionary open memory issue fixed. */
/*	config.dictionary_type = dictionary_type_linear_hash_t; */
/*  */
/*	dictionary = LinearHash<int, int>::openDictionary(config, type, type); */
/*	PLANCK_UNIT_ASSERT_INT_ARE_EQUAL(tc, ion_dictionary_status_ok, dictionary->dict.status); */
/*	cpp_wrapper_static_open_close_complex(tc, dictionary, 2, 22); */
}

/**
@brief		Creates the suite to test.
@return		Pointer to a test suite.
*/
planck_unit_suite_t *
cpp_wrapper3_getsuite_1(
) {
	planck_unit_suite_t *suite = planck_unit_new_suite();

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_equality_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_equality_nonexist_empty_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_equality_nonexist_all);

	return suite;
}

/**
@brief		Creates the suite to test.
@return		Pointer to a test suite.
*/
planck_unit_suite_t *
cpp_wrapper3_getsuite_2(
) {
	planck_unit_suite_t *suite = planck_unit_new_suite();

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_single_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_multiple_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_nonexist_empty_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_nonexist_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_exist_single_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_range_all_all);

	return suite;
}

/**
@brief		Creates the suite to test.
@return		Pointer to a test suite.
*/
planck_unit_suite_t *
cpp_wrapper3_getsuite_3(
) {
	planck_unit_suite_t *suite = planck_unit_new_suite();

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_all_records_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_all_records_nonexist_empty_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_all_records_populated_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_all_records_random_all);

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_cpp_wrapper_open_close_all);

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_setup_all);

	return suite;
}

/**
@brief		Creates the suite to test.
@return		Pointer to a test suite.
*/
planck_unit_suite_t *
cpp_wrapper3_getsuite_4(
) {
	planck_unit_suite_t *suite = planck_unit_new_suite();

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_insert_multiple_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_get_lots_all);

	return suite;
}

/**
@brief		Creates the suite to test.
@return		Pointer to a test suite.
*/
planck_unit_suite_t *
cpp_wrapper3_getsuite_5(
) {
	planck_unit_suite_t *suite = planck_unit_new_suite();

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_get_nonexist_many_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_update_exist_in_many_all);

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_equality_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_range_all_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_all_records_random_all);

	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_open_close_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_create_open_close_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_open_close_complex_all);
	PLANCK_UNIT_ADD_TO_SUITE(suite, test_static_create_open_close_complex_all);

	return suite;
}

/**
@brief	  Runs all C++ Related related tests and outputs the result.
*/
void
runalltests_cpp_wrapper3(
) {
	fdeleteall();

	planck_unit_suite_t *suite1 = cpp_wrapper3_getsuite_1();

	planck_unit_run_suite(suite1);
	planck_unit_destroy_suite(suite1);

	planck_unit_suite_t *suite2 = cpp_wrapper3_getsuite_2();

	planck_unit_run_suite(suite2);
	planck_unit_destroy_suite(suite2);

	planck_unit_suite_t *suite3 = cpp_wrapper3_getsuite_3();

	planck_unit_run_suite(suite3);
	planck_unit_destroy_suite(suite3);

	planck_unit_suite_t *suite4 = cpp_wrapper3_getsuite_4();

	planck_unit_run_suite(suite4);
	planck_unit_destroy_suite(suite4);

	planck_unit_suite_t *suite5 = cpp_wrapper3_getsuite_5();

	planck_unit_run_suite(suite5);
	planck_unit_destroy_suite(suite5);
}
