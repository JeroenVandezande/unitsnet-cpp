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
    enum class TorqueUnit : std::uint8_t
    {
        NewtonMillimeter,
        KilonewtonMillimeter,
        MeganewtonMillimeter,
        NewtonCentimeter,
        KilonewtonCentimeter,
        MeganewtonCentimeter,
        NewtonMeter,
        KilonewtonMeter,
        MeganewtonMeter,
        PoundalFoot,
        PoundForceInch,
        KilopoundForceInch,
        MegapoundForceInch,
        PoundForceFoot,
        KilopoundForceFoot,
        MegapoundForceFoot,
        GramForceMillimeter,
        GramForceCentimeter,
        GramForceMeter,
        KilogramForceMillimeter,
        KilogramForceCentimeter,
        KilogramForceMeter,
        TonneForceMillimeter,
        TonneForceCentimeter,
        TonneForceMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Torque.</summary>
    class TorqueDto
    {
    public:
        constexpr TorqueDto() noexcept
            : value{}, unit(TorqueUnit::NewtonMeter)
        {
        }

        constexpr TorqueDto(
            const un_scalar_t value,
            const TorqueUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        TorqueUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr TorqueUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<TorqueUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Torque unit name.");
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
        [[nodiscard]] static TorqueDto from_json(const nlohmann::json& json)
        {
            return TorqueDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Torque, moment or moment of force (see the terminology below), is the tendency of a force to rotate an object about an axis,[1] fulcrum, or pivot. Just as a force is a push or a pull, a torque can be thought of as a twist to an object. Mathematically, torque is defined as the cross product of the lever-arm distance and force, which tends to produce rotation. Loosely speaking, torque is a measure of the turning force on an object such as a bolt or a flywheel. For example, pushing or pulling the handle of a wrench connected to a nut or bolt produces a torque (turning force) that loosens or tightens the nut or bolt.</summary>
    class Torque : public UnitsNetBase
    {
    public:
        constexpr explicit Torque(
            const un_scalar_t value,
            const TorqueUnit unit = TorqueUnit::NewtonMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const TorqueUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr TorqueDto to_dto(
            const TorqueUnit unit = TorqueUnit::NewtonMeter) const
        {
            return TorqueDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Torque from_dto(const TorqueDto& dto)
        {
            return Torque(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const TorqueUnit unit = TorqueUnit::NewtonMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Torque from_json(const nlohmann::json& json)
        {
            return from_dto(TorqueDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Torque operator+(const Torque& other) const noexcept
        {
            return Torque(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Torque operator-(const Torque& other)const noexcept
        {
            return Torque(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Torque operator*(const un_scalar_t scalar) const noexcept
        {
            return Torque(base_value() * scalar);
        }

        [[nodiscard]] constexpr Torque operator/(const un_scalar_t scalar) const noexcept
        {
            return Torque(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Torque& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Torque& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Torque& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t newton_millimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_newton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_millimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newton_centimeters() const
        {
            return convert_from_base(TorqueUnit::NewtonCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_newton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_centimeters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t newton_meters() const
        {
            return convert_from_base(TorqueUnit::NewtonMeter);
        }

        [[nodiscard]] static constexpr Torque from_newton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::NewtonMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilonewton_meters() const
        {
            return convert_from_base(TorqueUnit::KilonewtonMeter);
        }

        [[nodiscard]] static constexpr Torque from_kilonewton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilonewtonMeter);
        }

        [[nodiscard]] constexpr un_scalar_t meganewton_meters() const
        {
            return convert_from_base(TorqueUnit::MeganewtonMeter);
        }

        [[nodiscard]] static constexpr Torque from_meganewton_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MeganewtonMeter);
        }

        [[nodiscard]] constexpr un_scalar_t poundal_feet() const
        {
            return convert_from_base(TorqueUnit::PoundalFoot);
        }

        [[nodiscard]] static constexpr Torque from_poundal_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundalFoot);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_inches() const
        {
            return convert_from_base(TorqueUnit::PoundForceInch);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundForceInch);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_inches() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceInch);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilopoundForceInch);
        }

        [[nodiscard]] constexpr un_scalar_t megapound_force_inches() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceInch);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_inches(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MegapoundForceInch);
        }

        [[nodiscard]] constexpr un_scalar_t pound_force_feet() const
        {
            return convert_from_base(TorqueUnit::PoundForceFoot);
        }

        [[nodiscard]] static constexpr Torque from_pound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::PoundForceFoot);
        }

        [[nodiscard]] constexpr un_scalar_t kilopound_force_feet() const
        {
            return convert_from_base(TorqueUnit::KilopoundForceFoot);
        }

        [[nodiscard]] static constexpr Torque from_kilopound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilopoundForceFoot);
        }

        [[nodiscard]] constexpr un_scalar_t megapound_force_feet() const
        {
            return convert_from_base(TorqueUnit::MegapoundForceFoot);
        }

        [[nodiscard]] static constexpr Torque from_megapound_force_feet(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::MegapoundForceFoot);
        }

        [[nodiscard]] constexpr un_scalar_t gram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::GramForceCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gram_force_meters() const
        {
            return convert_from_base(TorqueUnit::GramForceMeter);
        }

        [[nodiscard]] static constexpr Torque from_gram_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::GramForceMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilogram_force_meters() const
        {
            return convert_from_base(TorqueUnit::KilogramForceMeter);
        }

        [[nodiscard]] static constexpr Torque from_kilogram_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::KilogramForceMeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_force_millimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMillimeter);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_millimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_force_centimeters() const
        {
            return convert_from_base(TorqueUnit::TonneForceCentimeter);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_centimeters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t tonne_force_meters() const
        {
            return convert_from_base(TorqueUnit::TonneForceMeter);
        }

        [[nodiscard]] static constexpr Torque from_tonne_force_meters(const un_scalar_t value)
        {
            return Torque(value, TorqueUnit::TonneForceMeter);
        }

        [[nodiscard]] static constexpr Torque from_invalid()
        {
            return Torque(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, TorqueUnit unit)
        {
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeter:
                return value * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::KilonewtonMillimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::MeganewtonMillimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.001);

            case TorqueUnit::NewtonCentimeter:
                return value * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::KilonewtonCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::MeganewtonCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.01);

            case TorqueUnit::NewtonMeter:
                return value;

            case TorqueUnit::KilonewtonMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case TorqueUnit::MeganewtonMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case TorqueUnit::PoundalFoot:
                return value * static_cast<un_scalar_t>(0.138254954376) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::PoundForceInch:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::KilopoundForceInch:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::MegapoundForceInch:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2);

            case TorqueUnit::PoundForceFoot:
                return value * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::KilopoundForceFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::MegapoundForceFoot:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048);

            case TorqueUnit::GramForceMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e-6);

            case TorqueUnit::GramForceCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e-5);

            case TorqueUnit::GramForceMeter:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceMillimeter:
                return value * static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e-2);

            case TorqueUnit::KilogramForceMeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceMillimeter:
                return value * static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceCentimeter:
                return value * static_cast<un_scalar_t>(9.80665e1);

            case TorqueUnit::TonneForceMeter:
                return value * static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const TorqueUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case TorqueUnit::NewtonMillimeter:
                return base_value * static_cast<un_scalar_t>(1000);

            case TorqueUnit::KilonewtonMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000)) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::NewtonCentimeter:
                return base_value * static_cast<un_scalar_t>(100);

            case TorqueUnit::KilonewtonCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::NewtonMeter:
                return base_value;

            case TorqueUnit::KilonewtonMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MeganewtonMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::PoundalFoot:
                return base_value / (static_cast<un_scalar_t>(0.138254954376) * static_cast<un_scalar_t>(0.3048));

            case TorqueUnit::PoundForceInch:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2));

            case TorqueUnit::KilopoundForceInch:
                return (base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2))) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MegapoundForceInch:
                return (base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(2.54e-2))) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::PoundForceFoot:
                return base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048));

            case TorqueUnit::KilopoundForceFoot:
                return (base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048))) / static_cast<un_scalar_t>(1e3);

            case TorqueUnit::MegapoundForceFoot:
                return (base_value / (static_cast<un_scalar_t>(4.4482216152605) * static_cast<un_scalar_t>(0.3048))) / static_cast<un_scalar_t>(1e6);

            case TorqueUnit::GramForceMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-6);

            case TorqueUnit::GramForceCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-5);

            case TorqueUnit::GramForceMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-3);

            case TorqueUnit::KilogramForceCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e-2);

            case TorqueUnit::KilogramForceMeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceMillimeter:
                return base_value / static_cast<un_scalar_t>(9.80665);

            case TorqueUnit::TonneForceCentimeter:
                return base_value / static_cast<un_scalar_t>(9.80665e1);

            case TorqueUnit::TonneForceMeter:
                return base_value / static_cast<un_scalar_t>(9.80665e3);

            }

            throw std::invalid_argument("Unknown Torque unit.");
        }

        un_scalar_t value_;
        TorqueUnit value_unit_type_;       
    };
}
