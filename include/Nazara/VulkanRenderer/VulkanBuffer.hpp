// Copyright (C) 2015 Jérôme Leclercq
// This file is part of the "Nazara Engine - Vulkan Renderer"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_VULKANRENDERER_BUFFER_HPP
#define NAZARA_VULKANRENDERER_BUFFER_HPP

#include <Nazara/Prerequisites.hpp>
#include <Nazara/Utility/AbstractBuffer.hpp>
#include <Nazara/VulkanRenderer/Config.hpp>
#include <Nazara/VulkanRenderer/Wrapper/Buffer.hpp>
#include <Nazara/VulkanRenderer/Wrapper/DeviceMemory.hpp>
#include <Nazara/VulkanRenderer/Wrapper/Fence.hpp>
#include <memory>
#include <vector>

namespace Nz
{
	class NAZARA_VULKANRENDERER_API VulkanBuffer : public AbstractBuffer
	{
		public:
			inline VulkanBuffer(Vk::Device& device, BufferType type);
			VulkanBuffer(const VulkanBuffer&) = delete;
			VulkanBuffer(VulkanBuffer&&) = delete; ///TODO
			virtual ~VulkanBuffer();

			bool Fill(const void* data, UInt32 offset, UInt32 size) override;

			inline Nz::Vk::Buffer& GetBufferHandle();
			bool Initialize(UInt32 size, BufferUsageFlags usage) override;

			DataStorage GetStorage() const override;

			void* Map(BufferAccess access, UInt32 offset, UInt32 size) override;
			bool Unmap() override;

			VulkanBuffer& operator=(const VulkanBuffer&) = delete;
			VulkanBuffer& operator=(VulkanBuffer&&) = delete; ///TODO

		private:
			Vk::Buffer m_stagingBuffer;
			Vk::DeviceMemory m_stagingMemory;
			BufferType m_type;
			BufferUsageFlags m_usage;
			UInt32 m_size;
			Vk::Buffer m_buffer;
			Vk::Fence m_stagingFence;
			Vk::Device& m_device;
			Vk::DeviceMemory m_memory;
	};
}

#include <Nazara/VulkanRenderer/VulkanBuffer.inl>

#endif // NAZARA_VULKANRENDERER_BUFFER_HPP
