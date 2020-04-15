// Copyright (C) 2020 Jérôme Leclercq
// This file is part of the "Nazara Engine - Renderer module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINE_HPP
#define NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINE_HPP

#include <Nazara/Prerequisites.hpp>
#include <Nazara/Core/MovablePtr.hpp>
#include <Nazara/Renderer/RenderPipeline.hpp>
#include <Nazara/OpenGLRenderer/Config.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/Device.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/Pipeline.hpp>
#include <Nazara/OpenGLRenderer/Wrapper/RenderPass.hpp>
#include <vector>

namespace Nz
{
	class NAZARA_OPENGLRENDERER_API OpenGLRenderPipeline : public RenderPipeline
	{
		public:
			struct CreateInfo;

			OpenGLRenderPipeline(Vk::Device& device, RenderPipelineInfo pipelineInfo);
			~OpenGLRenderPipeline() = default;

			VkPipeline Get(const Vk::RenderPass& renderPass) const;

			static std::vector<VkPipelineColorBlendAttachmentState> BuildColorBlendAttachmentStateList(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineColorBlendStateCreateInfo BuildColorBlendInfo(const RenderPipelineInfo& pipelineInfo, const std::vector<VkPipelineColorBlendAttachmentState>& attachmentState);
			static VkPipelineDepthStencilStateCreateInfo BuildDepthStencilInfo(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineDynamicStateCreateInfo BuildDynamicStateInfo(const RenderPipelineInfo& pipelineInfo, const std::vector<VkDynamicState>& dynamicStates);
			static std::vector<VkDynamicState> BuildDynamicStateList(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineInputAssemblyStateCreateInfo BuildInputAssemblyInfo(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineMultisampleStateCreateInfo BuildMultisampleInfo(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineRasterizationStateCreateInfo BuildRasterizationInfo(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineViewportStateCreateInfo BuildViewportInfo(const RenderPipelineInfo& pipelineInfo);
			static VkStencilOpState BuildStencilOp(const RenderPipelineInfo& pipelineInfo, bool front);
			static std::vector<VkPipelineShaderStageCreateInfo> BuildShaderStageInfo(const RenderPipelineInfo& pipelineInfo);
			static std::vector<VkVertexInputAttributeDescription> BuildVertexAttributeDescription(const RenderPipelineInfo& pipelineInfo);
			static std::vector<VkVertexInputBindingDescription> BuildVertexBindingDescription(const RenderPipelineInfo& pipelineInfo);
			static VkPipelineVertexInputStateCreateInfo BuildVertexInputInfo(const RenderPipelineInfo& pipelineInfo, const std::vector<VkVertexInputAttributeDescription>& vertexAttributes, const std::vector<VkVertexInputBindingDescription>& bindingDescription);

			static CreateInfo BuildCreateInfo(const RenderPipelineInfo& pipelineInfo);

			struct CreateInfo
			{
				struct StateData
				{
					VkPipelineColorBlendStateCreateInfo colorBlendState;
					VkPipelineDepthStencilStateCreateInfo depthStencilState;
					VkPipelineDynamicStateCreateInfo dynamicState;
					VkPipelineMultisampleStateCreateInfo multiSampleState;
					VkPipelineInputAssemblyStateCreateInfo inputAssemblyState;
					VkPipelineRasterizationStateCreateInfo rasterizationState;
					VkPipelineVertexInputStateCreateInfo vertexInputState;
					VkPipelineViewportStateCreateInfo viewportState;
				};

				std::vector<VkPipelineColorBlendAttachmentState> colorBlendAttachmentState;
				std::vector<VkDynamicState> dynamicStates;
				std::vector<VkPipelineShaderStageCreateInfo> shaderStages;
				std::vector<VkVertexInputAttributeDescription> vertexAttributesDescription;
				std::vector<VkVertexInputBindingDescription> vertexBindingDescription;
				std::unique_ptr<StateData> stateData;
				VkGraphicsPipelineCreateInfo pipelineInfo;
			};

		private:
			mutable std::unordered_map<VkRenderPass, Vk::Pipeline> m_pipelines;
			MovablePtr<Vk::Device> m_device;
			CreateInfo m_pipelineCreateInfo;
			RenderPipelineInfo m_pipelineInfo;
	};
}

#include <Nazara/OpenGLRenderer/OpenGLRenderPipeline.inl>

#endif // NAZARA_OPENGLRENDERER_OPENGLRENDERPIPELINE_HPP
