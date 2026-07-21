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
    enum class ThermalInsulanceUnit : std::uint8_t
    {
        SquareMeterKelvinPerKilowatt,
        SquareMeterKelvinPerWatt,
        SquareMeterDegreeCelsiusPerWatt,
        SquareCentimeterKelvinPerWatt,
        SquareMillimeterKelvinPerWatt,
        SquareCentimeterHourDegreeCelsiusPerKilocalorie,
        HourSquareFeetDegreeFahrenheitPerBtu,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of ThermalInsulance.</summary>
    class ThermalInsulanceDto
    {
    public:
        constexpr ThermalInsulanceDto() noexcept
            : value{}, unit(ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt)
        {
        }

        constexpr ThermalInsulanceDto(
            const un_scalar_t value,
            const ThermalInsulanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ThermalInsulanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ThermalInsulanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ThermalInsulanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown ThermalInsulance unit name.");
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
        [[nodiscard]] static ThermalInsulanceDto from_json(const nlohmann::json& json)
        {
            return ThermalInsulanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Thermal insulance (R-value) is a measure of a material's resistance to the heat current. It quantifies how effectively a material can resist the transfer of heat through conduction, convection, and radiation. It has the units square metre kelvins per watt (m2⋅K/W) in SI units or square foot degree Fahrenheit–hours per British thermal unit (ft2⋅°F⋅h/Btu) in imperial units. The higher the thermal insulance, the better a material insulates against heat transfer. It is commonly used in construction to assess the insulation properties of materials such as walls, roofs, and insulation products.</summary>
    class ThermalInsulance : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalInsulance(
            const un_scalar_t value,
            const ThermalInsulanceUnit unit = ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ThermalInsulanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ThermalInsulanceDto to_dto(
            const ThermalInsulanceUnit unit = ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt) const
        {
            return ThermalInsulanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr ThermalInsulance from_dto(const ThermalInsulanceDto& dto)
        {
            return ThermalInsulance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ThermalInsulanceUnit unit = ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static ThermalInsulance from_json(const nlohmann::json& json)
        {
            return from_dto(ThermalInsulanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr ThermalInsulance operator+(const ThermalInsulance& other) const noexcept
        {
            return ThermalInsulance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalInsulance operator-(const ThermalInsulance& other)const noexcept
        {
            return ThermalInsulance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalInsulance operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalInsulance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalInsulance operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalInsulance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalInsulance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalInsulance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalInsulance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t square_meter_kelvins_per_kilowatt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_kilowatt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt);
        }

        [[nodiscard]] constexpr un_scalar_t square_meter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinPerWatt);
        }

        [[nodiscard]] constexpr un_scalar_t square_meter_degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterDegreeCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_degrees_celsius_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterDegreeCelsiusPerWatt);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterKelvinPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterKelvinPerWatt);
        }

        [[nodiscard]] constexpr un_scalar_t square_millimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMillimeterKelvinPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_millimeter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMillimeterKelvinPerWatt);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeter_hour_degrees_celsius_per_kilocalorie() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterHourDegreeCelsiusPerKilocalorie);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_hour_degrees_celsius_per_kilocalorie(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterHourDegreeCelsiusPerKilocalorie);
        }

        [[nodiscard]] constexpr un_scalar_t hour_square_feet_degrees_fahrenheit_per_btu() const
        {
            return convert_from_base(ThermalInsulanceUnit::HourSquareFeetDegreeFahrenheitPerBtu);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_hour_square_feet_degrees_fahrenheit_per_btu(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::HourSquareFeetDegreeFahrenheitPerBtu);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_invalid()
        {
            return ThermalInsulance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalInsulanceUnit unit)
        {
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt:
                return value;

            case ThermalInsulanceUnit::SquareMeterKelvinPerWatt:
                return value * static_cast<un_scalar_t>(1000);

            case ThermalInsulanceUnit::SquareMeterDegreeCelsiusPerWatt:
                return value * static_cast<un_scalar_t>(1000.0);

            case ThermalInsulanceUnit::SquareCentimeterKelvinPerWatt:
                return value * static_cast<un_scalar_t>(0.1);

            case ThermalInsulanceUnit::SquareMillimeterKelvinPerWatt:
                return value * static_cast<un_scalar_t>(0.001);

            case ThermalInsulanceUnit::SquareCentimeterHourDegreeCelsiusPerKilocalorie:
                return value * (static_cast<un_scalar_t>(0.0001) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(4.184);

            case ThermalInsulanceUnit::HourSquareFeetDegreeFahrenheitPerBtu:
                return value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600)) / (static_cast<un_scalar_t>(1055.05585262) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalInsulanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinPerKilowatt:
                return base_value;

            case ThermalInsulanceUnit::SquareMeterKelvinPerWatt:
                return base_value / static_cast<un_scalar_t>(1000);

            case ThermalInsulanceUnit::SquareMeterDegreeCelsiusPerWatt:
                return base_value / static_cast<un_scalar_t>(1000.0);

            case ThermalInsulanceUnit::SquareCentimeterKelvinPerWatt:
                return base_value / static_cast<un_scalar_t>(0.1);

            case ThermalInsulanceUnit::SquareMillimeterKelvinPerWatt:
                return base_value / static_cast<un_scalar_t>(0.001);

            case ThermalInsulanceUnit::SquareCentimeterHourDegreeCelsiusPerKilocalorie:
                return base_value * static_cast<un_scalar_t>(4.184) / (static_cast<un_scalar_t>(0.0001) * static_cast<un_scalar_t>(3600));

            case ThermalInsulanceUnit::HourSquareFeetDegreeFahrenheitPerBtu:
                return base_value * (static_cast<un_scalar_t>(1055.05585262) * static_cast<un_scalar_t>(1.8)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        un_scalar_t value_;
        ThermalInsulanceUnit value_unit_type_;       
    };
}
