#include <vma/vk_mem_alloc.h>

static auto CreateAllocator(const VmaAllocatorCreateInfo& vmaAllocatorCreateInfo, VmaAllocator& allocator) -> VkResult
{
	return vmaCreateAllocator(&vmaAllocatorCreateInfo, &allocator);
}

static auto DestroyAllocator(VmaAllocator allocator) -> void
{
	vmaDestroyAllocator(allocator);
}

static auto CreateBuffer(VmaAllocator                   allocator,
                         const VkBufferCreateInfo&      bufferCreateInfo,
                         const VmaAllocationCreateInfo& allocationCreateInfo,
                         VkBuffer&                      buffer,
                         VmaAllocation&                 allocation,
                         VmaAllocationInfo              allocationInfo) -> VkResult
{
	return vmaCreateBuffer(allocator, &bufferCreateInfo, &allocationCreateInfo, &buffer, &allocation, &allocationInfo);
}

static auto DestroyBuffer(VmaAllocator allocator, VkBuffer buffer, VmaAllocation allocation) -> void
{
	vmaDestroyBuffer(allocator, buffer, allocation);
}

static auto CreateImage(VmaAllocator                   allocator,
                        const VkImageCreateInfo&       imageCreateInfo,
                        const VmaAllocationCreateInfo& allocationCreateInfo,
                        VkImage&                       image,
                        VmaAllocation&                 allocation,
                        VmaAllocationInfo              allocationInfo) -> VkResult
{
	return vmaCreateImage(allocator, &imageCreateInfo, &allocationCreateInfo, &image, &allocation, &allocationInfo);
}

static auto DestroyImage(VmaAllocator allocator, VkImage image, VmaAllocation allocation) -> void
{
	vmaDestroyImage(allocator, image, allocation);
}

static auto MapMemory(VmaAllocator allocator, VmaAllocation allocation, void** ppData) -> VkResult
{
	return vmaMapMemory(allocator, allocation, ppData);
}

static auto UnmapMemory(VmaAllocator allocator, VmaAllocation allocation) -> void
{
	vmaUnmapMemory(allocator, allocation);
}