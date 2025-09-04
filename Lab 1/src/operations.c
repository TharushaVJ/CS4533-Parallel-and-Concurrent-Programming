#include <stdlib.h>
#include "operations.h"
// Shuffle the operations array using Fisher-Yates algorithm
void ops_shuffle(operation_t* ops, size_t count, unsigned int *seed) {
	if (!ops || count < 2) return;
	for (size_t i = count - 1; i > 0; --i) {
		size_t j = rand_r(seed) % (i + 1);
		operation_t temp = ops[i];
		ops[i] = ops[j];
		ops[j] = temp;
	}
}

// Generate m operations with given proportions and seed
operation_t* ops_generate(size_t m, double p_member, double p_insert, double p_delete, unsigned int *seed) {
	if (m == 0 || p_member + p_insert + p_delete <= 0.0) return NULL;
	operation_t* ops = malloc(m * sizeof(operation_t));
	if (!ops) return NULL;

	size_t n_member = (size_t)(m * p_member);
	size_t n_insert = (size_t)(m * p_insert);
	size_t n_delete = (size_t)(m * p_delete);
	size_t total = n_member + n_insert + n_delete;
	// Fill remaining slots if rounding caused shortage
	for (; total < m; ++total) {
		if (n_member < m * p_member) ++n_member;
		else if (n_insert < m * p_insert) ++n_insert;
		else ++n_delete;
	}

	size_t idx = 0;
	for (size_t i = 0; i < n_member; ++i, ++idx) {
		ops[idx].type = OP_MEMBER;
		ops[idx].value = rand_r(seed) % 65536;
	}
	for (size_t i = 0; i < n_insert; ++i, ++idx) {
		ops[idx].type = OP_INSERT;
		ops[idx].value = rand_r(seed) % 65536;
	}
	for (size_t i = 0; i < n_delete; ++i, ++idx) {
		ops[idx].type = OP_DELETE;
		ops[idx].value = rand_r(seed) % 65536;
	}

	// Shuffle the operations
	ops_shuffle(ops, m, seed);
	return ops;
}


