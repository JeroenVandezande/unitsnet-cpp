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
    enum class ImpulseUnit : std::uint8_t
    {
        KilogramMeterPerSecond,
        NewtonSecond,
        NanonewtonSecond,
        MicronewtonSecond,
        MillinewtonSecond,
        CentinewtonSecond,
        DecinewtonSecond,
        DecanewtonSecond,
        KilonewtonSecond,
        MeganewtonSecond,
        PoundFootPerSecond,
        PoundForceSecond,
        SlugFootPerSecond,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Impulse.</summary>
    class ImpulseDto
    {
    public:
        constexpr ImpulseDto() noexcept
            : value{}, unit(ImpulseUnit::NewtonSecond)
        {
        }

        constexpr ImpulseDto(
            const un_scalar_t value,
            const ImpulseUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ImpulseUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ImpulseUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ImpulseUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Impulse unit name.");
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
        [[nodiscard]] static ImpulseDto from_json(const nlohmann::json& json)
        {
            return ImpulseDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In classical mechanics, impulse is the integral of a force, F, over the time interval, t, for which it acts. Impulse applied to an object produces an equivalent vector change in its linear momentum, also in the resultant direction.</summary>
    class Impulse : public UnitsNetBase
    {
    public:
        constexpr explicit Impulse(
            const un_scalar_t value,
            const ImpulseUnit unit = ImpulseUnit::NewtonSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ImpulseUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ImpulseDto to_dto(
            const ImpulseUnit unit = ImpulseUnit::NewtonSecond) const
        {
            return ImpulseDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Impulse from_dto(const ImpulseDto& dto)
        {
            return Impulse(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ImpulseUnit unit = ImpulseUnit::NewtonSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Impulse from_json(const nlohmann::json& json)
        {
            return from_dto(ImpulseDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Impulse operator+(const Impulse& other) const noexcept
        {
            return Impulse(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Impulse operator-(const Impulse& other)const noexcept
        {
            return Impulse(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Impulse operator*(const un_scalar_t scalar) const noexcept
        {
            return Impulse(base_value() * scalar);
        }

        [[nodiscard]] constexpr Impulse operator/(const un_scalar_t scalar) const noexcept
        {
            return Impulse(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Impulse& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Impulse& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Impulse& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_meters_per_second() const
        {
            return convert_from_base(ImpulseUnit::KilogramMeterPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_kilogram_meters_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::KilogramMeterPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t newton_seconds() const
        {
            return convert_from_base(ImpulseUnit::NewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_newton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::NewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanonewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::NanonewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_nanonewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::NanonewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micronewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MicronewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_micronewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MicronewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t millinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MillinewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_millinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MillinewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::CentinewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_centinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::CentinewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decinewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::DecinewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_decinewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::DecinewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decanewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::DecanewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_decanewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::DecanewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::KilonewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_kilonewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::KilonewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_seconds() const
        {
            return convert_from_base(ImpulseUnit::MeganewtonSecond);
        }

        [[nodiscard]] static constexpr Impulse from_meganewton_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::MeganewtonSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pound_feet_per_second() const
        {
            return convert_from_base(ImpulseUnit::PoundFootPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_pound_feet_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::PoundFootPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_seconds() const
        {
            return convert_from_base(ImpulseUnit::PoundForceSecond);
        }

        [[nodiscard]] static constexpr Impulse from_pound_force_seconds(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::PoundForceSecond);
        }

        [[nodiscard]] constexpr un_scalar_t slug_feet_per_second() const
        {
            return convert_from_base(ImpulseUnit::SlugFootPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_slug_feet_per_second(const un_scalar_t value)
        {
            return Impulse(value, ImpulseUnit::SlugFootPerSecond);
        }

        [[nodiscard]] static constexpr Impulse from_invalid()
        {
            return Impulse(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ImpulseUnit unit)
        {
            switch (unit)
            {

            case ImpulseUnit::KilogramMeterPerSecond:
                return value;

            case ImpulseUnit::NewtonSecond:
                return value;

            case ImpulseUnit::NanonewtonSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ImpulseUnit::MicronewtonSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ImpulseUnit::MillinewtonSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ImpulseUnit::CentinewtonSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ImpulseUnit::DecinewtonSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case ImpulseUnit::DecanewtonSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case ImpulseUnit::KilonewtonSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case ImpulseUnit::MeganewtonSecond:
                return (value * static_cast<un_scalar_t>(1e6));

            case ImpulseUnit::PoundFootPerSecond:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.3048));

            case ImpulseUnit::PoundForceSecond:
                return value * static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665);

            case ImpulseUnit::SlugFootPerSecond:
                return value * (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown Impulse unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ImpulseUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ImpulseUnit::KilogramMeterPerSecond:
                return base_value;

            case ImpulseUnit::NewtonSecond:
                return base_value;

            case ImpulseUnit::NanonewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ImpulseUnit::MicronewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ImpulseUnit::MillinewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ImpulseUnit::CentinewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case ImpulseUnit::DecinewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case ImpulseUnit::DecanewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case ImpulseUnit::KilonewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ImpulseUnit::MeganewtonSecond:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ImpulseUnit::PoundFootPerSecond:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(0.3048));

            case ImpulseUnit::PoundForceSecond:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            case ImpulseUnit::SlugFootPerSecond:
                return base_value / (static_cast<un_scalar_t>(0.45359237) * static_cast<un_scalar_t>(9.80665));

            }

            throw std::invalid_argument("Unknown Impulse unit.");
        }

        un_scalar_t value_;
        ImpulseUnit value_unit_type_;       
    };
}
