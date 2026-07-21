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
    enum class PressureChangeRateUnit : std::uint8_t
    {
        PascalPerSecond,
        KilopascalPerSecond,
        MegapascalPerSecond,
        PascalPerMinute,
        KilopascalPerMinute,
        MegapascalPerMinute,
        MillimeterOfMercuryPerSecond,
        AtmospherePerSecond,
        PoundForcePerSquareInchPerSecond,
        KilopoundForcePerSquareInchPerSecond,
        MegapoundForcePerSquareInchPerSecond,
        PoundForcePerSquareInchPerMinute,
        KilopoundForcePerSquareInchPerMinute,
        MegapoundForcePerSquareInchPerMinute,
        BarPerSecond,
        MillibarPerSecond,
        BarPerMinute,
        MillibarPerMinute,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of PressureChangeRate.</summary>
    class PressureChangeRateDto
    {
    public:
        constexpr PressureChangeRateDto() noexcept
            : value{}, unit(PressureChangeRateUnit::PascalPerSecond)
        {
        }

        constexpr PressureChangeRateDto(
            const un_scalar_t value,
            const PressureChangeRateUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        PressureChangeRateUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr PressureChangeRateUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<PressureChangeRateUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown PressureChangeRate unit name.");
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
        [[nodiscard]] static PressureChangeRateDto from_json(const nlohmann::json& json)
        {
            return PressureChangeRateDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Pressure change rate is the ratio of the pressure change to the time during which the change occurred (value of pressure changes per unit time).</summary>
    class PressureChangeRate : public UnitsNetBase
    {
    public:
        constexpr explicit PressureChangeRate(
            const un_scalar_t value,
            const PressureChangeRateUnit unit = PressureChangeRateUnit::PascalPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PressureChangeRateUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr PressureChangeRateDto to_dto(
            const PressureChangeRateUnit unit = PressureChangeRateUnit::PascalPerSecond) const
        {
            return PressureChangeRateDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr PressureChangeRate from_dto(const PressureChangeRateDto& dto)
        {
            return PressureChangeRate(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const PressureChangeRateUnit unit = PressureChangeRateUnit::PascalPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static PressureChangeRate from_json(const nlohmann::json& json)
        {
            return from_dto(PressureChangeRateDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr PressureChangeRate operator+(const PressureChangeRate& other) const noexcept
        {
            return PressureChangeRate(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PressureChangeRate operator-(const PressureChangeRate& other)const noexcept
        {
            return PressureChangeRate(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PressureChangeRate operator*(const un_scalar_t scalar) const noexcept
        {
            return PressureChangeRate(base_value() * scalar);
        }

        [[nodiscard]] constexpr PressureChangeRate operator/(const un_scalar_t scalar) const noexcept
        {
            return PressureChangeRate(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PressureChangeRate& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PressureChangeRate& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PressureChangeRate& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t pascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PascalPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PascalPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilopascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopascalPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopascalPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapascals_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapascalPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapascals_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapascalPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millimeters_of_mercury_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillimeterOfMercuryPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millimeters_of_mercury_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillimeterOfMercuryPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t atmospheres_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::AtmospherePerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_atmospheres_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::AtmospherePerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_force_per_square_inch_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundForcePerSquareInchPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::PoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_pounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::PoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t kilopounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::KilopoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_kilopounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::KilopoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_force_per_square_inch_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MegapoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_megapounds_force_per_square_inch_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MegapoundForcePerSquareInchPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t bars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::BarPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millibars_per_second() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarPerSecond);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_second(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t bars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::BarPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_bars_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::BarPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t millibars_per_minute() const
        {
            return convert_from_base(PressureChangeRateUnit::MillibarPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_millibars_per_minute(const un_scalar_t value)
        {
            return PressureChangeRate(value, PressureChangeRateUnit::MillibarPerMinute);
        }

        [[nodiscard]] static constexpr PressureChangeRate from_invalid()
        {
            return PressureChangeRate(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PressureChangeRateUnit unit)
        {
            switch (unit)
            {

            case PressureChangeRateUnit::PascalPerSecond:
                return value;

            case PressureChangeRateUnit::KilopascalPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case PressureChangeRateUnit::MegapascalPerSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case PressureChangeRateUnit::PascalPerMinute:
                return value / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopascalPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MegapascalPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillimeterOfMercuryPerSecond:
                return value * static_cast<un_scalar_t>(133.322387415);

            case PressureChangeRateUnit::AtmospherePerSecond:
                return value * static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::PoundForcePerSquareInchPerSecond:
                return value * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::KilopoundForcePerSquareInchPerSecond:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::MegapoundForcePerSquareInchPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516);

            case PressureChangeRateUnit::PoundForcePerSquareInchPerMinute:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopoundForcePerSquareInchPerMinute:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MegapoundForcePerSquareInchPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516)) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::BarPerSecond:
                return value * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::MillibarPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::BarPerMinute:
                return value * static_cast<un_scalar_t>(1e5) / static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillibarPerMinute:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e5) / static_cast<un_scalar_t>(60);

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PressureChangeRateUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PressureChangeRateUnit::PascalPerSecond:
                return base_value;

            case PressureChangeRateUnit::KilopascalPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapascalPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::PascalPerMinute:
                return base_value * static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::KilopascalPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapascalPerMinute:
                return (base_value * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::MillimeterOfMercuryPerSecond:
                return base_value / static_cast<un_scalar_t>(133.322387415);

            case PressureChangeRateUnit::AtmospherePerSecond:
                return base_value / (static_cast<un_scalar_t>(1.01325) * static_cast<un_scalar_t>(1e5));

            case PressureChangeRateUnit::PoundForcePerSquareInchPerSecond:
                return base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605);

            case PressureChangeRateUnit::KilopoundForcePerSquareInchPerSecond:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapoundForcePerSquareInchPerSecond:
                return (base_value * static_cast<un_scalar_t>(0.00064516) / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::PoundForcePerSquareInchPerMinute:
                return base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516));

            case PressureChangeRateUnit::KilopoundForcePerSquareInchPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516))) / static_cast<un_scalar_t>(1e3);

            case PressureChangeRateUnit::MegapoundForcePerSquareInchPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(0.00064516))) / static_cast<un_scalar_t>(1e6);

            case PressureChangeRateUnit::BarPerSecond:
                return base_value / static_cast<un_scalar_t>(1e5);

            case PressureChangeRateUnit::MillibarPerSecond:
                return (base_value / static_cast<un_scalar_t>(1e5)) / static_cast<un_scalar_t>(1e-3);

            case PressureChangeRateUnit::BarPerMinute:
                return base_value / static_cast<un_scalar_t>(1e5) * static_cast<un_scalar_t>(60);

            case PressureChangeRateUnit::MillibarPerMinute:
                return (base_value / static_cast<un_scalar_t>(1e5) * static_cast<un_scalar_t>(60)) / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown PressureChangeRate unit.");
        }

        un_scalar_t value_;
        PressureChangeRateUnit value_unit_type_;       
    };
}
