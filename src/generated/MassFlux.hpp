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
    enum class MassFluxUnit : std::uint8_t
    {
        GramPerSecondPerSquareMeter,
        KilogramPerSecondPerSquareMeter,
        GramPerSecondPerSquareCentimeter,
        KilogramPerSecondPerSquareCentimeter,
        GramPerSecondPerSquareMillimeter,
        KilogramPerSecondPerSquareMillimeter,
        GramPerHourPerSquareMeter,
        KilogramPerHourPerSquareMeter,
        GramPerHourPerSquareCentimeter,
        KilogramPerHourPerSquareCentimeter,
        GramPerHourPerSquareMillimeter,
        KilogramPerHourPerSquareMillimeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MassFlux.</summary>
    class MassFluxDto
    {
    public:
        constexpr MassFluxDto() noexcept
            : value{}, unit(MassFluxUnit::KilogramPerSecondPerSquareMeter)
        {
        }

        constexpr MassFluxDto(
            const un_scalar_t value,
            const MassFluxUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassFluxUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassFluxUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassFluxUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MassFlux unit name.");
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
        [[nodiscard]] static MassFluxDto from_json(const nlohmann::json& json)
        {
            return MassFluxDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Mass flux is the mass flow rate per unit area.</summary>
    class MassFlux : public UnitsNetBase
    {
    public:
        constexpr explicit MassFlux(
            const un_scalar_t value,
            const MassFluxUnit unit = MassFluxUnit::KilogramPerSecondPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFluxUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassFluxDto to_dto(
            const MassFluxUnit unit = MassFluxUnit::KilogramPerSecondPerSquareMeter) const
        {
            return MassFluxDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MassFlux from_dto(const MassFluxDto& dto)
        {
            return MassFlux(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassFluxUnit unit = MassFluxUnit::KilogramPerSecondPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MassFlux from_json(const nlohmann::json& json)
        {
            return from_dto(MassFluxDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MassFlux operator+(const MassFlux& other) const noexcept
        {
            return MassFlux(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassFlux operator-(const MassFlux& other)const noexcept
        {
            return MassFlux(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassFlux operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFlux(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassFlux operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFlux(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFlux& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassFlux& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassFlux& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::GramPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerSecondPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerSecondPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerSecondPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::GramPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerSecondPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_second_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::GramPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_second_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_second_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_second_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerSecondPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::GramPerHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerHourPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_meter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_meter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerHourPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::GramPerHourPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerHourPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_centimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerHourPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_centimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerHourPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_hour_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::GramPerHourPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_grams_per_hour_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::GramPerHourPerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour_per_square_millimeter() const
        {
            return convert_from_base(MassFluxUnit::KilogramPerHourPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_kilograms_per_hour_per_square_millimeter(const un_scalar_t value)
        {
            return MassFlux(value, MassFluxUnit::KilogramPerHourPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr MassFlux from_invalid()
        {
            return MassFlux(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFluxUnit unit)
        {
            switch (unit)
            {

            case MassFluxUnit::GramPerSecondPerSquareMeter:
                return value / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::KilogramPerSecondPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerSecondPerSquareCentimeter:
                return value / static_cast<un_scalar_t>(1e-1);

            case MassFluxUnit::KilogramPerSecondPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MassFluxUnit::GramPerSecondPerSquareMillimeter:
                return value / static_cast<un_scalar_t>(1e-3);

            case MassFluxUnit::KilogramPerSecondPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MassFluxUnit::GramPerHourPerSquareMeter:
                return value / static_cast<un_scalar_t>(3.6e6);

            case MassFluxUnit::KilogramPerHourPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3.6e6);

            case MassFluxUnit::GramPerHourPerSquareCentimeter:
                return value / static_cast<un_scalar_t>(3.6e2);

            case MassFluxUnit::KilogramPerHourPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3.6e2);

            case MassFluxUnit::GramPerHourPerSquareMillimeter:
                return value / static_cast<un_scalar_t>(3.6e0);

            case MassFluxUnit::KilogramPerHourPerSquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(3.6e0);

            }

            throw std::invalid_argument("Unknown MassFlux unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFluxUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassFluxUnit::GramPerSecondPerSquareMeter:
                return base_value * static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::KilogramPerSecondPerSquareMeter:
                return (base_value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerSecondPerSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(1e-1);

            case MassFluxUnit::KilogramPerSecondPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerSecondPerSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1e-3);

            case MassFluxUnit::KilogramPerSecondPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerHourPerSquareMeter:
                return base_value * static_cast<un_scalar_t>(3.6e6);

            case MassFluxUnit::KilogramPerHourPerSquareMeter:
                return (base_value * static_cast<un_scalar_t>(3.6e6)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerHourPerSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(3.6e2);

            case MassFluxUnit::KilogramPerHourPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(3.6e2)) / static_cast<un_scalar_t>(1e3);

            case MassFluxUnit::GramPerHourPerSquareMillimeter:
                return base_value * static_cast<un_scalar_t>(3.6e0);

            case MassFluxUnit::KilogramPerHourPerSquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(3.6e0)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown MassFlux unit.");
        }

        un_scalar_t value_;
        MassFluxUnit value_unit_type_;       
    };
}
