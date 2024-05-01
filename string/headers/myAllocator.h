#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H

class myAllocator {
public:
	constexpr myAllocator() noexcept = default;
	constexpr myAllocator(const myAllocator& other) noexcept = default;
	~myAllocator() = default;
public:
	constexpr char* allocate(size_t n);
	void deallocate(char* p, size_t n);
};

#endif // MYALLOCATOR_H
