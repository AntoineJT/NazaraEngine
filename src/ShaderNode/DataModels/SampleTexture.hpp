#pragma once

#ifndef NAZARA_SHADERNODES_SAMPLETEXTURE_HPP
#define NAZARA_SHADERNODES_SAMPLETEXTURE_HPP

#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <ShaderNode/ShaderGraph.hpp>
#include <ShaderNode/DataModels/ShaderNode.hpp>
#include <ShaderNode/DataModels/VecValue.hpp>
#include <array>

class SampleTexture : public ShaderNode
{
	public:
		SampleTexture(ShaderGraph& graph);
		~SampleTexture() = default;

		void BuildNodeEdition(QVBoxLayout* layout) override;

		Nz::ShaderAst::ExpressionPtr GetExpression(Nz::ShaderAst::ExpressionPtr* /*expressions*/, std::size_t count) const override;

		QString caption() const override { return "Sample texture"; }
		QString name() const override { return "SampleTexture"; }

		unsigned int nPorts(QtNodes::PortType portType) const override;

		QtNodes::NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

		QString portCaption(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

		bool portCaptionVisible(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;

		std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override;

		void setInData(std::shared_ptr<QtNodes::NodeData> value, int index) override;

	protected:
		bool ComputePreview(QPixmap& pixmap) override;
		void OnTextureListUpdate();
		void UpdateOutput();

		NazaraSlot(ShaderGraph, OnTextureListUpdate, m_onTextureListUpdateSlot);
		NazaraSlot(ShaderGraph, OnTexturePreviewUpdate, m_onTexturePreviewUpdateSlot);

		std::optional<std::size_t> m_currentTextureIndex;
		std::shared_ptr<Vec2Data> m_uv;
		std::shared_ptr<Vec4Data> m_output;
		std::string m_currentTextureText;
};

#include <ShaderNode/DataModels/SampleTexture.inl>

#endif