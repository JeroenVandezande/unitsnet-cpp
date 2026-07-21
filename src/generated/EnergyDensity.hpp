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
    enum class EnergyDensityUnit : std::uint8_t
    {
        JoulePerCubicMeter,
        KilojoulePerCubicMeter,
        MegajoulePerCubicMeter,
        GigajoulePerCubicMeter,
        TerajoulePerCubicMeter,
        PetajoulePerCubicMeter,
        WattHourPerCubicMeter,
        KilowattHourPerCubicMeter,
        MegawattHourPerCubicMeter,
        GigawattHourPerCubicMeter,
        TerawattHourPerCubicMeter,
        PetawattHourPerCubicMeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of EnergyDensity.</summary>
    class EnergyDensityDto
    {
    public:
        constexpr EnergyDensityDto() noexcept
            : value{}, unit(EnergyDensityUnit::JoulePerCubicMeter)
        {
        }

        constexpr EnergyDensityDto(
            const un_scalar_t value,
            const EnergyDensityUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        EnergyDensityUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr EnergyDensityUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<EnergyDensityUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown EnergyDensity unit name.");
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
        [[nodiscard]] static EnergyDensityDto from_json(const nlohmann::json& json)
        {
            return EnergyDensityDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class EnergyDensity : public UnitsNetBase
    {
    public:
        constexpr explicit EnergyDensity(
            const un_scalar_t value,
            const EnergyDensityUnit unit = EnergyDensityUnit::JoulePerCubicMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const EnergyDensityUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr EnergyDensityDto to_dto(
            const EnergyDensityUnit unit = EnergyDensityUnit::JoulePerCubicMeter) const
        {
            return EnergyDensityDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr EnergyDensity from_dto(const EnergyDensityDto& dto)
        {
            return EnergyDensity(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const EnergyDensityUnit unit = EnergyDensityUnit::JoulePerCubicMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static EnergyDensity from_json(const nlohmann::json& json)
        {
            return from_dto(EnergyDensityDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr EnergyDensity operator+(const EnergyDensity& other) const noexcept
        {
            return EnergyDensity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr EnergyDensity operator-(const EnergyDensity& other)const noexcept
        {
            return EnergyDensity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr EnergyDensity operator*(const un_scalar_t scalar) const noexcept
        {
            return EnergyDensity(base_value() * scalar);
        }

        [[nodiscard]] constexpr EnergyDensity operator/(const un_scalar_t scalar) const noexcept
        {
            return EnergyDensity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const EnergyDensity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const EnergyDensity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const EnergyDensity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::JoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_joules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::JoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilojoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilojoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilojoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegajoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegajoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigajoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigajoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t terajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerajoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerajoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t petajoules_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetajoulePerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petajoules_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetajoulePerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::WattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_watt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::WattHourPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::KilowattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_kilowatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::KilowattHourPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::MegawattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_megawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::MegawattHourPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::GigawattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_gigawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::GigawattHourPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::TerawattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_terawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::TerawattHourPerCubicMeter);
        }

        [[nodiscard]] constexpr un_scalar_t petawatt_hours_per_cubic_meter() const
        {
            return convert_from_base(EnergyDensityUnit::PetawattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_petawatt_hours_per_cubic_meter(const un_scalar_t value)
        {
            return EnergyDensity(value, EnergyDensityUnit::PetawattHourPerCubicMeter);
        }

        [[nodiscard]] static constexpr EnergyDensity from_invalid()
        {
            return EnergyDensity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, EnergyDensityUnit unit)
        {
            switch (unit)
            {

            case EnergyDensityUnit::JoulePerCubicMeter:
                return value;

            case EnergyDensityUnit::KilojoulePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case EnergyDensityUnit::MegajoulePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case EnergyDensityUnit::GigajoulePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9));

            case EnergyDensityUnit::TerajoulePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12));

            case EnergyDensityUnit::PetajoulePerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e15));

            case EnergyDensityUnit::WattHourPerCubicMeter:
                return value * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::KilowattHourPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::MegawattHourPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::GigawattHourPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::TerawattHourPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::PetawattHourPerCubicMeter:
                return (value * static_cast<un_scalar_t>(1e15)) * static_cast<un_scalar_t>(3.6e+3);

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const EnergyDensityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case EnergyDensityUnit::JoulePerCubicMeter:
                return base_value;

            case EnergyDensityUnit::KilojoulePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case EnergyDensityUnit::MegajoulePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case EnergyDensityUnit::GigajoulePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e9);

            case EnergyDensityUnit::TerajoulePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e12);

            case EnergyDensityUnit::PetajoulePerCubicMeter:
                return (base_value) / static_cast<un_scalar_t>(1e15);

            case EnergyDensityUnit::WattHourPerCubicMeter:
                return base_value / static_cast<un_scalar_t>(3.6e+3);

            case EnergyDensityUnit::KilowattHourPerCubicMeter:
                return (base_value / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e3);

            case EnergyDensityUnit::MegawattHourPerCubicMeter:
                return (base_value / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e6);

            case EnergyDensityUnit::GigawattHourPerCubicMeter:
                return (base_value / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e9);

            case EnergyDensityUnit::TerawattHourPerCubicMeter:
                return (base_value / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e12);

            case EnergyDensityUnit::PetawattHourPerCubicMeter:
                return (base_value / static_cast<un_scalar_t>(3.6e+3)) / static_cast<un_scalar_t>(1e15);

            }

            throw std::invalid_argument("Unknown EnergyDensity unit.");
        }

        un_scalar_t value_;
        EnergyDensityUnit value_unit_type_;       
    };
}
