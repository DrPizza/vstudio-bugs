#include "stdafx.h"

volatile std::atomic<size_t> global = 0;

int main()
{
	static const     size_t  sc_count = 2ULL;
	       constexpr size_t  ce_count = 2ULL;
	static constexpr size_t sce_count = 2ULL;
	       const     size_t   c_count = 2ULL;
	
	size_t  sc_result_direct =              global.load(std::memory_order_acquire) %  sc_count; // and reg, 1
	size_t  ce_result_direct =              global.load(std::memory_order_acquire) %  ce_count; // and reg, 1
	size_t sce_result_direct =              global.load(std::memory_order_acquire) % sce_count; // and reg, 1
	size_t   c_result_direct =              global.load(std::memory_order_acquire) %   c_count; // and reg, 1

	size_t  sc_result_lambda = [&] { return global.load(std::memory_order_acquire) %  sc_count; }(); // and reg, 1
	size_t  ce_result_lambda = [&] { return global.load(std::memory_order_acquire) %  ce_count; }(); // div
	size_t sce_result_lambda = [&] { return global.load(std::memory_order_acquire) % sce_count; }(); // and reg, 1
	size_t   c_result_lambda = [&] { return global.load(std::memory_order_acquire) %   c_count; }(); // div


	std::cout << sc_result_direct << " " << ce_result_direct << " " << sce_result_direct << " " << c_result_direct << std::endl;
	std::cout << sc_result_lambda << " " << ce_result_lambda << " " << sce_result_lambda << " " << c_result_lambda << std::endl;

	return 0;
}
