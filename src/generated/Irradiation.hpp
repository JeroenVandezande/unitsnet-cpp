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
    enum class IrradiationUnit : std::uint8_t
    {
        JoulePerSquareMeter,
        KilojoulePerSquareMeter,
        JoulePerSquareCentimeter,
        MillijoulePerSquareCentimeter,
        JoulePerSquareMillimeter,
        WattHourPerSquareMeter,
        KilowattHourPerSquareMeter,
        BtuPerSquareFoot,
        KilobtuPerSquareFoot,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Irradiation.</summary>
    class IrradiationDto
    {
    public:
        constexpr IrradiationDto() noexcept
            : value{}, unit(IrradiationUnit::JoulePerSquareMeter)
        {
        }

        constexpr IrradiationDto(
            const un_scalar_t value,
            const IrradiationUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        IrradiationUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr IrradiationUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<IrradiationUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Irradiation unit name.");
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
        [[nodiscard]] static IrradiationDto from_json(const nlohmann::json& json)
        {
            return IrradiationDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Irradiation is the process by which an object is exposed to radiation. The exposure can originate from various sources, including natural sources.</summary>
    class Irradiation : public UnitsNetBase
    {
    public:
        constexpr explicit Irradiation(
            const un_scalar_t value,
            const IrradiationUnit unit = IrradiationUnit::JoulePerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const IrradiationUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr IrradiationDto to_dto(
            const IrradiationUnit unit = IrradiationUnit::JoulePerSquareMeter) const
        {
            return IrradiationDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Irradiation from_dto(const IrradiationDto& dto)
        {
            return Irradiation(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const IrradiationUnit unit = IrradiationUnit::JoulePerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Irradiation from_json(const nlohmann::json& json)
        {
            return from_dto(IrradiationDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Irradiation operator+(const Irradiation& other) const noexcept
        {
            return Irradiation(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Irradiation operator-(const Irradiation& other)const noexcept
        {
            return Irradiation(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Irradiation operator*(const un_scalar_t scalar) const noexcept
        {
            return Irradiation(base_value() * scalar);
        }

        [[nodiscard]] constexpr Irradiation operator/(const un_scalar_t scalar) const noexcept
        {
            return Irradiation(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Irradiation& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Irradiation& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Irradiation& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::JoulePerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::KilojoulePerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_kilojoules_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilojoulePerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_square_centimeter() const
        {
            return convert_from_base(IrradiationUnit::JoulePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t millijoules_per_square_centimeter() const
        {
            return convert_from_base(IrradiationUnit::MillijoulePerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_millijoules_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::MillijoulePerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_square_millimeter() const
        {
            return convert_from_base(IrradiationUnit::JoulePerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_millimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulePerSquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::WattHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_watt_hours_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::WattHourPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::KilowattHourPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_kilowatt_hours_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilowattHourPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t btus_per_square_foot() const
        {
            return convert_from_base(IrradiationUnit::BtuPerSquareFoot);
        }

        [[nodiscard]] static constexpr Irradiation from_btus_per_square_foot(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::BtuPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilobtus_per_square_foot() const
        {
            return convert_from_base(IrradiationUnit::KilobtuPerSquareFoot);
        }

        [[nodiscard]] static constexpr Irradiation from_kilobtus_per_square_foot(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilobtuPerSquareFoot);
        }

        [[nodiscard]] static constexpr Irradiation from_invalid()
        {
            return Irradiation(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IrradiationUnit unit)
        {
            switch (unit)
            {

            case IrradiationUnit::JoulePerSquareMeter:
                return value;

            case IrradiationUnit::KilojoulePerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case IrradiationUnit::JoulePerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::MillijoulePerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::JoulePerSquareMillimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case IrradiationUnit::WattHourPerSquareMeter:
                return value * static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::KilowattHourPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::BtuPerSquareFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(9.290304e-2);

            case IrradiationUnit::KilobtuPerSquareFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Irradiation unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IrradiationUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case IrradiationUnit::JoulePerSquareMeter:
                return base_value;

            case IrradiationUnit::KilojoulePerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case IrradiationUnit::JoulePerSquareCentimeter:
                return base_value / static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::MillijoulePerSquareCentimeter:
                return (base_value / static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            case IrradiationUnit::JoulePerSquareMillimeter:
                return base_value / static_cast<un_scalar_t>(1e6);

            case IrradiationUnit::WattHourPerSquareMeter:
                return base_value / static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::KilowattHourPerSquareMeter:
                return (base_value / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e3);

            case IrradiationUnit::BtuPerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(1055.05585262);

            case IrradiationUnit::KilobtuPerSquareFoot:
                return (base_value * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown Irradiation unit.");
        }

        un_scalar_t value_;
        IrradiationUnit value_unit_type_;       
    };
}
