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
    enum class ForceUnit : std::uint8_t
    {
        Dyn,
        GramForce,
        KilogramForce,
        TonneForce,
        Newton,
        Micronewton,
        Millinewton,
        Decanewton,
        Kilonewton,
        Meganewton,
        Kilopond,
        Poundal,
        PoundForce,
        KilopoundForce,
        OunceForce,
        ShortTonForce,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Force.</summary>
    class ForceDto
    {
    public:
        constexpr ForceDto() noexcept
            : value{}, unit(ForceUnit::Newton)
        {
        }

        constexpr ForceDto(
            const un_scalar_t value,
            const ForceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        ForceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr ForceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<ForceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Force unit name.");
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
        [[nodiscard]] static ForceDto from_json(const nlohmann::json& json)
        {
            return ForceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>In physics, a force is any influence that causes an object to undergo a certain change, either concerning its movement, direction, or geometrical construction. In other words, a force can cause an object with mass to change its velocity (which includes to begin moving from a state of rest), i.e., to accelerate, or a flexible object to deform, or both. Force can also be described by intuitive concepts such as a push or a pull. A force has both magnitude and direction, making it a vector quantity. It is measured in the SI unit of newtons and represented by the symbol F.</summary>
    class Force : public UnitsNetBase
    {
    public:
        constexpr explicit Force(
            const un_scalar_t value,
            const ForceUnit unit = ForceUnit::Newton)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ForceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr ForceDto to_dto(
            const ForceUnit unit = ForceUnit::Newton) const
        {
            return ForceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Force from_dto(const ForceDto& dto)
        {
            return Force(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const ForceUnit unit = ForceUnit::Newton) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Force from_json(const nlohmann::json& json)
        {
            return from_dto(ForceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Force operator+(const Force& other) const noexcept
        {
            return Force(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Force operator-(const Force& other)const noexcept
        {
            return Force(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Force operator*(const un_scalar_t scalar) const noexcept
        {
            return Force(base_value() * scalar);
        }

        [[nodiscard]] constexpr Force operator/(const un_scalar_t scalar) const noexcept
        {
            return Force(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Force& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Force& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Force& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>One dyne is equal to 10 micronewtons, 10e−5 N or to 10 nsn (nanosthenes) in the old metre–tonne–second system of units.</summary>
        [[nodiscard]] constexpr un_scalar_t dyne() const
        {
            return convert_from_base(ForceUnit::Dyn);
        }

        /// <summary>One dyne is equal to 10 micronewtons, 10e−5 N or to 10 nsn (nanosthenes) in the old metre–tonne–second system of units.</summary>
        [[nodiscard]] static constexpr Force from_dyne(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Dyn);
        }

        /// <summary>The gram-force is a unit of force equal to the magnitude of force exerted by a gram of mass in standard gravity (9.80665 m/s²). It is equal to 9.80665 × 10⁻³ N.</summary>
        [[nodiscard]] constexpr un_scalar_t grams_force() const
        {
            return convert_from_base(ForceUnit::GramForce);
        }

        /// <summary>The gram-force is a unit of force equal to the magnitude of force exerted by a gram of mass in standard gravity (9.80665 m/s²). It is equal to 9.80665 × 10⁻³ N.</summary>
        [[nodiscard]] static constexpr Force from_grams_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::GramForce);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kilograms_force() const
        {
            return convert_from_base(ForceUnit::KilogramForce);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] static constexpr Force from_kilograms_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilogramForce);
        }

        /// <summary>The tonne-force, metric ton-force, megagram-force, and megapond (Mp) are each 1000 kilograms-force.</summary>
        [[nodiscard]] constexpr un_scalar_t tonnes_force() const
        {
            return convert_from_base(ForceUnit::TonneForce);
        }

        /// <summary>The tonne-force, metric ton-force, megagram-force, and megapond (Mp) are each 1000 kilograms-force.</summary>
        [[nodiscard]] static constexpr Force from_tonnes_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::TonneForce);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t newtons() const
        {
            return convert_from_base(ForceUnit::Newton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_newtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Newton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t micronewtons() const
        {
            return convert_from_base(ForceUnit::Micronewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_micronewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Micronewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millinewtons() const
        {
            return convert_from_base(ForceUnit::Millinewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_millinewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Millinewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t decanewtons() const
        {
            return convert_from_base(ForceUnit::Decanewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_decanewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Decanewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilonewtons() const
        {
            return convert_from_base(ForceUnit::Kilonewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_kilonewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kilonewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] constexpr un_scalar_t meganewtons() const
        {
            return convert_from_base(ForceUnit::Meganewton);
        }

        /// <summary>The newton (symbol: N) is the unit of force in the International System of Units (SI). It is defined as 1 kg⋅m/s2, the force which gives a mass of 1 kilogram an acceleration of 1 metre per second per second.</summary>
        [[nodiscard]] static constexpr Force from_meganewtons(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Meganewton);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kiloponds() const
        {
            return convert_from_base(ForceUnit::Kilopond);
        }

        /// <summary>The kilogram-force, or kilopond, is equal to the magnitude of the force exerted on one kilogram of mass in a 9.80665 m/s2 gravitational field (standard gravity). Therefore, one kilogram-force is by definition equal to 9.80665 N.</summary>
        [[nodiscard]] static constexpr Force from_kiloponds(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Kilopond);
        }

        /// <summary>The poundal is defined as the force necessary to accelerate 1 pound-mass at 1 foot per second per second. 1 pdl = 0.138254954376 N exactly.</summary>
        [[nodiscard]] constexpr un_scalar_t poundals() const
        {
            return convert_from_base(ForceUnit::Poundal);
        }

        /// <summary>The poundal is defined as the force necessary to accelerate 1 pound-mass at 1 foot per second per second. 1 pdl = 0.138254954376 N exactly.</summary>
        [[nodiscard]] static constexpr Force from_poundals(const un_scalar_t value)
        {
            return Force(value, ForceUnit::Poundal);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] constexpr un_scalar_t pounds_force() const
        {
            return convert_from_base(ForceUnit::PoundForce);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] static constexpr Force from_pounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::PoundForce);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] constexpr un_scalar_t kilopounds_force() const
        {
            return convert_from_base(ForceUnit::KilopoundForce);
        }

        /// <summary>The standard values of acceleration of the standard gravitational field (gn) and the international avoirdupois pound (lb) result in a pound-force equal to 4.4482216152605 N.</summary>
        [[nodiscard]] static constexpr Force from_kilopounds_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::KilopoundForce);
        }

        /// <summary>An ounce-force is 1⁄16 of a pound-force, or about 0.2780139 newtons.</summary>
        [[nodiscard]] constexpr un_scalar_t ounce_force() const
        {
            return convert_from_base(ForceUnit::OunceForce);
        }

        /// <summary>An ounce-force is 1⁄16 of a pound-force, or about 0.2780139 newtons.</summary>
        [[nodiscard]] static constexpr Force from_ounce_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::OunceForce);
        }

        /// <summary>The short ton-force is a unit of force equal to 2,000 pounds-force (907.18474 kgf), that is most commonly used in the United States – known there simply as the ton or US ton.</summary>
        [[nodiscard]] constexpr un_scalar_t short_tons_force() const
        {
            return convert_from_base(ForceUnit::ShortTonForce);
        }

        /// <summary>The short ton-force is a unit of force equal to 2,000 pounds-force (907.18474 kgf), that is most commonly used in the United States – known there simply as the ton or US ton.</summary>
        [[nodiscard]] static constexpr Force from_short_tons_force(const un_scalar_t value)
        {
            return Force(value, ForceUnit::ShortTonForce);
        }

        [[nodiscard]] static constexpr Force from_invalid()
        {
            return Force(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ForceUnit unit)
        {
            switch (unit)
            {

            case ForceUnit::Dyn:
                return value / static_cast<un_scalar_t>(1e5);

            case ForceUnit::GramForce:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case ForceUnit::KilogramForce:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForceUnit::TonneForce:
                return value * (static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(1000));

            case ForceUnit::Newton:
                return value;

            case ForceUnit::Micronewton:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ForceUnit::Millinewton:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ForceUnit::Decanewton:
                return (value * static_cast<un_scalar_t>(1e1));

            case ForceUnit::Kilonewton:
                return (value * static_cast<un_scalar_t>(1e3));

            case ForceUnit::Meganewton:
                return (value * static_cast<un_scalar_t>(1e6));

            case ForceUnit::Kilopond:
                return value * static_cast<un_scalar_t>(9.80665);

            case ForceUnit::Poundal:
                return value * static_cast<un_scalar_t>(0.138254954376);

            case ForceUnit::PoundForce:
                return value * static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::KilopoundForce:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::OunceForce:
                return value * (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(16));

            case ForceUnit::ShortTonForce:
                return value * (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2000));

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ForceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ForceUnit::Dyn:
                return base_value * static_cast<un_scalar_t>(1e5);

            case ForceUnit::GramForce:
                return base_value / static_cast<un_scalar_t>(9.80665e-3);

            case ForceUnit::KilogramForce:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::TonneForce:
                return base_value / (static_cast<un_scalar_t>(9.80665) * static_cast<un_scalar_t>(1000));

            case ForceUnit::Newton:
                return base_value;

            case ForceUnit::Micronewton:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ForceUnit::Millinewton:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ForceUnit::Decanewton:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case ForceUnit::Kilonewton:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::Meganewton:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ForceUnit::Kilopond:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case ForceUnit::Poundal:
                return base_value / static_cast<un_scalar_t>(0.138254954376);

            case ForceUnit::PoundForce:
                return base_value / static_cast<un_scalar_t>(4.4482216152605);

            case ForceUnit::KilopoundForce:
                return (base_value / static_cast<un_scalar_t>(4.4482216152605)) / static_cast<un_scalar_t>(1e3);

            case ForceUnit::OunceForce:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) / static_cast<un_scalar_t>(16));

            case ForceUnit::ShortTonForce:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2000));

            }

            throw std::invalid_argument("Unknown Force unit.");
        }

        un_scalar_t value_;
        ForceUnit value_unit_type_;       
    };
}
