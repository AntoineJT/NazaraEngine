// Copyright (C) 2020 Jérôme Leclercq
// This file is part of the "Nazara Engine - OpenGL Renderer"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_OPENGLRENDERER_VKFRAMEBUFFER_HPP
#define NAZARA_OPENGLRENDERER_VKFRAMEBUFFER_HPP

#include <Nazara/Prerequisites.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/DeviceObject.hpp>

namespace Nz 
{
	namespace Vk
	{
		class Framebuffer : public DeviceObject<Framebuffer, VkFramebuffer, VkFramebufferCreateInfo, VK_OBJECT_TYPE_FRAMEBUFFER>
		{
			friend DeviceObject;

			public:
				Framebuffer() = default;
				Framebuffer(const Framebuffer&) = delete;
				Framebuffer(Framebuffer&&) = default;
				~Framebuffer() = default;

				Framebuffer& operator=(const Framebuffer&) = delete;
				Framebuffer& operator=(Framebuffer&&) = delete;

			private:
				static inline VkResult CreateHelper(Device& device, const VkFramebufferCreateInfo* createInfo, const VkAllocationCallbacks* allocator, VkFramebuffer* handle);
				static inline void DestroyHelper(Device& device, VkFramebuffer handle, const VkAllocationCallbacks* allocator);
		};
	}
}

#include <Nazara/OpenGLRenderer/Wrapper/Framebuffer.inl>

#endif // NAZARA_OPENGLRENDERER_VKFRAMEBUFFER_HPP