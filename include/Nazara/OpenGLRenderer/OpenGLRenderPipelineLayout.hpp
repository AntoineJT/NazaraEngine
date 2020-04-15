// Copyright (C) 2020 Jérôme Leclercq
// This file is part of the "Nazara Engine - Renderer module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINELAYOUT_HPP
#define NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINELAYOUT_HPP

#include <Nazara/Prerequisites.hpp>
#include <Nazara/Core/Bitset.hpp>
#include <Nazara/Renderer/RenderPipelineLayout.hpp>
#include <Nazara/OpenGLRenderer/Config.hpp>
#include <Nazara/OpenGLRenderer/OpenGLShaderBinding.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/Device.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/DescriptorPool.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/DescriptorSet.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/DescriptorSetLayout.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/PipelineLayout.hpp>
#include <memory>
#include <type_traits>
#include <vector>

namespace Nz
{
	class NAZARA_OPENGLRENDERER_API OpenGLRenderPipelineLayout : public RenderPipelineLayout
	{
		friend OpenGLShaderBinding;

		public:
			OpenGLRenderPipelineLayout() = default;
			~OpenGLRenderPipelineLayout();

			ShaderBindingPtr AllocateShaderBinding() override;

			bool Create(Vk::Device& device, RenderPipelineLayoutInfo layoutInfo);

			inline Vk::Device* GetDevice() const;

			inline const Vk::DescriptorSetLayout& GetDescriptorSetLayout() const;
			inline const Vk::PipelineLayout& GetPipelineLayout() const;

		private:
			struct DescriptorPool;

			DescriptorPool& AllocatePool();
			ShaderBindingPtr AllocateFromPool(std::size_t poolIndex);
			void Release(ShaderBinding& binding);
			inline void TryToShrink();

			struct DescriptorPool
			{
				using BindingStorage = std::aligned_storage_t<sizeof(OpenGLShaderBinding), alignof(OpenGLShaderBinding)>;

				Bitset<UInt64> freeBindings;
				Vk::DescriptorPool descriptorPool;
				std::unique_ptr<BindingStorage[]> storage;
			};

			MovablePtr<Vk::Device> m_device;
			std::vector<DescriptorPool> m_descriptorPools;
			Vk::DescriptorSetLayout m_descriptorSetLayout;
			Vk::PipelineLayout m_pipelineLayout;
			RenderPipelineLayoutInfo m_layoutInfo;
	};
}

#include <Nazara/OpenGLRenderer/OpenGLRenderPipelineLayout.inl>

#endif // NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINE_HPP
