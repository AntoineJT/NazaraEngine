// Copyright (C) 2019 Jérôme Leclercq
// This file is part of the "Nazara Engine - Utility module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Utility/FieldOffsets.hpp>
#include <memory>
#include <Nazara/Utility/Debug.hpp>

namespace Nz
{
	inline FieldOffsets::FieldOffsets(StructLayout layout) :
	m_offset(0),
	m_previousType(StructFieldType_None),
	m_layout(layout)
	{
	}

	inline std::size_t FieldOffsets::GetSize() const
	{
		return m_offset + GetSize(m_previousType);
	}

	inline std::size_t FieldOffsets::GetAlignement(StructLayout layout, StructFieldType fieldType)
	{
		switch (layout)
		{
			case StructLayout_Packed:
				return 1;

			case StructLayout_Std140:
			{
				switch (fieldType)
				{
					case StructFieldType_Bool1:
					case StructFieldType_Float1:
					case StructFieldType_Int1:
					case StructFieldType_UInt1:
						return 4;

					case StructFieldType_Bool2:
					case StructFieldType_Float2:
					case StructFieldType_Int2:
					case StructFieldType_UInt2:
						return 2 * 4;

					case StructFieldType_Bool3:
					case StructFieldType_Float3:
					case StructFieldType_Int3:
					case StructFieldType_UInt3:
					case StructFieldType_Bool4:
					case StructFieldType_Float4:
					case StructFieldType_Int4:
					case StructFieldType_UInt4:
						return 4 * 4;

					case StructFieldType_Float3x3:
						return 3*3 * 4;

					case StructFieldType_Float4x4:
						return 4*4 * 4;
				
					case StructFieldType_Double1:
						return 8;

					case StructFieldType_Double2:
						return 2 * 8;

					case StructFieldType_Double3:
					case StructFieldType_Double4:
						return 4 * 8;

					case StructFieldType_Double3x3:
						return 3 * 3 * 8;

					case StructFieldType_Double4x4:
						return 4 * 4 * 8;
				}
			}
		}

		return 0;
	}

	inline std::size_t FieldOffsets::GetSize(StructFieldType fieldType)
	{
		switch (fieldType)
		{
			case StructFieldType_Bool1:
			case StructFieldType_Float1:
			case StructFieldType_Int1:
			case StructFieldType_UInt1:
				return 4;

			case StructFieldType_Bool2:
			case StructFieldType_Float2:
			case StructFieldType_Int2:
			case StructFieldType_UInt2:
				return 2 * 4;

			case StructFieldType_Bool3:
			case StructFieldType_Float3:
			case StructFieldType_Int3:
			case StructFieldType_UInt3:
				return 3 * 4;

			case StructFieldType_Bool4:
			case StructFieldType_Float4:
			case StructFieldType_Int4:
			case StructFieldType_UInt4:
				return 4 * 4;

			case StructFieldType_Float3x3:
				return 3*3 * 4;

			case StructFieldType_Float4x4:
				return 4*4 * 4;
				
			case StructFieldType_Double1:
				return 8;

			case StructFieldType_Double2:
				return 2 * 8;

			case StructFieldType_Double3:
				return 3 * 8;

			case StructFieldType_Double3x3:
				return 3 * 3 * 8;

			case StructFieldType_Double4:
				return 4 * 8;

			case StructFieldType_Double4x4:
				return 4 * 4 * 8;

			case StructFieldType_None:
				return 0;
		}

		return 0;
	}
}

#include <Nazara/Utility/DebugOff.hpp>