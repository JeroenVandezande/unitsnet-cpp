#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include <string>
#include <string_view>
#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
#include <magic_enum/magic_enum.hpp>
#endif
#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
#include <nlohmann/json.hpp>
#endif
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PorousMediumPermeabilityUnit : std::uint8_t
    {
        Darcy,
        Microdarcy,
        Millidarcy,
        SquareMeter,
        SquareCentimeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of PorousMediumPermeability.</summary>
    class PorousMediumPermeabilityDto
    {
    public:
        constexpr PorousMediumPermeabilityDto() noexcept
            : value{}, unit(PorousMediumPermeabilityUnit::SquareMeter)
        {
        }

        constexpr PorousMediumPermeabilityDto(
            const un_scalar_t value,
            const PorousMediumPermeabilityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PorousMediumPermeabilityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeabilityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PorousMediumPermeabilityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit name.");
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this DTO to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json() const
        {
            return nlohmann::json{
                {"value", value},
                {"unit", unit_name()}
            };
        }

        /// <summary>Creates a DTO from a nlohmann JSON object.</summary>
        [[nodiscard]] static PorousMediumPermeabilityDto from_json(const nlohmann::json& json)
        {
            return PorousMediumPermeabilityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class PorousMediumPermeability : public UnitsNetBase
    {
    public:
        constexpr explicit PorousMediumPermeability(
            const un_scalar_t value,
            const PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PorousMediumPermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PorousMediumPermeabilityDto to_dto(
            const PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeter) const
        {
            return PorousMediumPermeabilityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_dto(const PorousMediumPermeabilityDto& dto)
        {
            return PorousMediumPermeability(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static PorousMediumPermeability from_json(const nlohmann::json& json)
        {
            return from_dto(PorousMediumPermeabilityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr PorousMediumPermeability operator+(const PorousMediumPermeability& other) const noexcept
        {
            return PorousMediumPermeability(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator-(const PorousMediumPermeability& other)const noexcept
        {
            return PorousMediumPermeability(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator*(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(base_value() * scalar);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator/(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t darcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Darcy);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_darcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Darcy);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t microdarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Microdarcy);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_microdarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Microdarcy);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t millidarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Millidarcy);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_millidarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Millidarcy);
        }

        [[nodiscard]] constexpr un_scalar_t square_meters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareMeter);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_meters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareCentimeter);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_centimeters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareCentimeter);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_invalid()
        {
            return PorousMediumPermeability(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PorousMediumPermeabilityUnit unit)
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcy:
                return value * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcy:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Millidarcy:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::SquareMeter:
                return value;

            case PorousMediumPermeabilityUnit::SquareCentimeter:
                return value * static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PorousMediumPermeabilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcy:
                return base_value / static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcy:
                return (base_value / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-6);

            case PorousMediumPermeabilityUnit::Millidarcy:
                return (base_value / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-3);

            case PorousMediumPermeabilityUnit::SquareMeter:
                return base_value;

            case PorousMediumPermeabilityUnit::SquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        un_scalar_t value_;
        PorousMediumPermeabilityUnit value_unit_type_;       
    };
}
