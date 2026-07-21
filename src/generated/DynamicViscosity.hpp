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
    enum class DynamicViscosityUnit : std::uint8_t
    {
        NewtonSecondPerMeterSquared,
        PascalSecond,
        MillipascalSecond,
        MicropascalSecond,
        Poise,
        Centipoise,
        Reyn,
        PoundForceSecondPerSquareInch,
        PoundForceSecondPerSquareFoot,
        PoundPerFootSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of DynamicViscosity.</summary>
    class DynamicViscosityDto
    {
    public:
        constexpr DynamicViscosityDto() noexcept
            : value{}, unit(DynamicViscosityUnit::NewtonSecondPerMeterSquared)
        {
        }

        constexpr DynamicViscosityDto(
            const un_scalar_t value,
            const DynamicViscosityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        DynamicViscosityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr DynamicViscosityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<DynamicViscosityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown DynamicViscosity unit name.");
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
        [[nodiscard]] static DynamicViscosityDto from_json(const nlohmann::json& json)
        {
            return DynamicViscosityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The dynamic (shear) viscosity of a fluid expresses its resistance to shearing flows, where adjacent layers move parallel to each other with different speeds</summary>
    class DynamicViscosity : public UnitsNetBase
    {
    public:
        constexpr explicit DynamicViscosity(
            const un_scalar_t value,
            const DynamicViscosityUnit unit = DynamicViscosityUnit::NewtonSecondPerMeterSquared)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const DynamicViscosityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr DynamicViscosityDto to_dto(
            const DynamicViscosityUnit unit = DynamicViscosityUnit::NewtonSecondPerMeterSquared) const
        {
            return DynamicViscosityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr DynamicViscosity from_dto(const DynamicViscosityDto& dto)
        {
            return DynamicViscosity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const DynamicViscosityUnit unit = DynamicViscosityUnit::NewtonSecondPerMeterSquared) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static DynamicViscosity from_json(const nlohmann::json& json)
        {
            return from_dto(DynamicViscosityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr DynamicViscosity operator+(const DynamicViscosity& other) const noexcept
        {
            return DynamicViscosity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr DynamicViscosity operator-(const DynamicViscosity& other)const noexcept
        {
            return DynamicViscosity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr DynamicViscosity operator*(const un_scalar_t scalar) const noexcept
        {
            return DynamicViscosity(base_value() * scalar);
        }

        [[nodiscard]] constexpr DynamicViscosity operator/(const un_scalar_t scalar) const noexcept
        {
            return DynamicViscosity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const DynamicViscosity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const DynamicViscosity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const DynamicViscosity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newton_seconds_per_meter_squared() const
        {
            return convert_from_base(DynamicViscosityUnit::NewtonSecondPerMeterSquared);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_newton_seconds_per_meter_squared(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::NewtonSecondPerMeterSquared);
        }

        [[nodiscard]] constexpr un_scalar_t pascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::PascalSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PascalSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millipascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::MillipascalSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_millipascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::MillipascalSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micropascal_seconds() const
        {
            return convert_from_base(DynamicViscosityUnit::MicropascalSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_micropascal_seconds(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::MicropascalSecond);
        }

        [[nodiscard]] constexpr un_scalar_t poise() const
        {
            return convert_from_base(DynamicViscosityUnit::Poise);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_poise(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Poise);
        }

        [[nodiscard]] constexpr un_scalar_t centipoise() const
        {
            return convert_from_base(DynamicViscosityUnit::Centipoise);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_centipoise(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Centipoise);
        }

        [[nodiscard]] constexpr un_scalar_t reyns() const
        {
            return convert_from_base(DynamicViscosityUnit::Reyn);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_reyns(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::Reyn);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_second_per_square_inch() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundForceSecondPerSquareInch);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_force_second_per_square_inch(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundForceSecondPerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_second_per_square_foot() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundForceSecondPerSquareFoot);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_force_second_per_square_foot(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundForceSecondPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_foot_second() const
        {
            return convert_from_base(DynamicViscosityUnit::PoundPerFootSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_pounds_per_foot_second(const un_scalar_t value)
        {
            return DynamicViscosity(value, DynamicViscosityUnit::PoundPerFootSecond);
        }

        [[nodiscard]] static constexpr DynamicViscosity from_invalid()
        {
            return DynamicViscosity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DynamicViscosityUnit unit)
        {
            switch (unit)
            {

            case DynamicViscosityUnit::NewtonSecondPerMeterSquared:
                return value;

            case DynamicViscosityUnit::PascalSecond:
                return value;

            case DynamicViscosityUnit::MillipascalSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DynamicViscosityUnit::MicropascalSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DynamicViscosityUnit::Poise:
                return value / static_cast<un_scalar_t>(10);

            case DynamicViscosityUnit::Centipoise:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(10);

            case DynamicViscosityUnit::Reyn:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case DynamicViscosityUnit::PoundForceSecondPerSquareInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case DynamicViscosityUnit::PoundForceSecondPerSquareFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(9.290304e-2);

            case DynamicViscosityUnit::PoundPerFootSecond:
                return value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(0.3048);

            }

            throw std::invalid_argument("Unknown DynamicViscosity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DynamicViscosityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case DynamicViscosityUnit::NewtonSecondPerMeterSquared:
                return base_value;

            case DynamicViscosityUnit::PascalSecond:
                return base_value;

            case DynamicViscosityUnit::MillipascalSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case DynamicViscosityUnit::MicropascalSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case DynamicViscosityUnit::Poise:
                return base_value * static_cast<un_scalar_t>(10);

            case DynamicViscosityUnit::Centipoise:
                return (base_value * static_cast<un_scalar_t>(10)) / static_cast<un_scalar_t>(1e-2);

            case DynamicViscosityUnit::Reyn:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case DynamicViscosityUnit::PoundForceSecondPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case DynamicViscosityUnit::PoundForceSecondPerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(4.4482216152605);

            case DynamicViscosityUnit::PoundPerFootSecond:
                return base_value * static_cast<un_scalar_t>(0.3048) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown DynamicViscosity unit.");
        }

        un_scalar_t value_;
        DynamicViscosityUnit value_unit_type_;       
    };
}
