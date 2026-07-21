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
    enum class SpecificEnergyUnit : std::uint8_t
    {
        JoulePerKilogram,
        KilojoulePerKilogram,
        MegajoulePerKilogram,
        MegajoulePerTonne,
        CaloriePerGram,
        KilocaloriePerGram,
        WattHourPerKilogram,
        KilowattHourPerKilogram,
        MegawattHourPerKilogram,
        GigawattHourPerKilogram,
        WattDayPerKilogram,
        KilowattDayPerKilogram,
        MegawattDayPerKilogram,
        GigawattDayPerKilogram,
        TerawattDayPerKilogram,
        WattDayPerTonne,
        KilowattDayPerTonne,
        MegawattDayPerTonne,
        GigawattDayPerTonne,
        TerawattDayPerTonne,
        WattDayPerShortTon,
        KilowattDayPerShortTon,
        MegawattDayPerShortTon,
        GigawattDayPerShortTon,
        TerawattDayPerShortTon,
        WattHourPerPound,
        KilowattHourPerPound,
        MegawattHourPerPound,
        GigawattHourPerPound,
        BtuPerPound,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of SpecificEnergy.</summary>
    class SpecificEnergyDto
    {
    public:
        constexpr SpecificEnergyDto() noexcept
            : value{}, unit(SpecificEnergyUnit::JoulePerKilogram)
        {
        }

        constexpr SpecificEnergyDto(
            const un_scalar_t value,
            const SpecificEnergyUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        SpecificEnergyUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr SpecificEnergyUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<SpecificEnergyUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown SpecificEnergy unit name.");
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
        [[nodiscard]] static SpecificEnergyDto from_json(const nlohmann::json& json)
        {
            return SpecificEnergyDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The SpecificEnergy</summary>
    class SpecificEnergy : public UnitsNetBase
    {
    public:
        constexpr explicit SpecificEnergy(
            const un_scalar_t value,
            const SpecificEnergyUnit unit = SpecificEnergyUnit::JoulePerKilogram)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const SpecificEnergyUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr SpecificEnergyDto to_dto(
            const SpecificEnergyUnit unit = SpecificEnergyUnit::JoulePerKilogram) const
        {
            return SpecificEnergyDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr SpecificEnergy from_dto(const SpecificEnergyDto& dto)
        {
            return SpecificEnergy(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const SpecificEnergyUnit unit = SpecificEnergyUnit::JoulePerKilogram) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static SpecificEnergy from_json(const nlohmann::json& json)
        {
            return from_dto(SpecificEnergyDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr SpecificEnergy operator+(const SpecificEnergy& other) const noexcept
        {
            return SpecificEnergy(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr SpecificEnergy operator-(const SpecificEnergy& other)const noexcept
        {
            return SpecificEnergy(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr SpecificEnergy operator*(const un_scalar_t scalar) const noexcept
        {
            return SpecificEnergy(base_value() * scalar);
        }

        [[nodiscard]] constexpr SpecificEnergy operator/(const un_scalar_t scalar) const noexcept
        {
            return SpecificEnergy(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const SpecificEnergy& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const SpecificEnergy& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const SpecificEnergy& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t joules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::JoulePerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_joules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::JoulePerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilojoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilojoulePerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilojoules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilojoulePerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulePerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulePerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megajoules_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegajoulePerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megajoules_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegajoulePerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t calories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::CaloriePerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_calories_per_gram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::CaloriePerGram);
        }

        [[nodiscard]] constexpr un_scalar_t kilocalories_per_gram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilocaloriePerGram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilocalories_per_gram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilocaloriePerGram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHourPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHourPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHourPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHourPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHourPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHourPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHourPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHourPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDayPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDayPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDayPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDayPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDayPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDayPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDayPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDayPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_kilogram() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDayPerKilogram);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_kilogram(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDayPerKilogram);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDayPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDayPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDayPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDayPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDayPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDayPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDayPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDayPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_tonne() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDayPerTonne);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_tonne(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDayPerTonne);
        }

        [[nodiscard]] constexpr un_scalar_t watt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::WattDayPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattDayPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattDayPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattDayPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattDayPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattDayPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattDayPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattDayPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t terawatt_days_per_short_ton() const
        {
            return convert_from_base(SpecificEnergyUnit::TerawattDayPerShortTon);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_terawatt_days_per_short_ton(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::TerawattDayPerShortTon);
        }

        [[nodiscard]] constexpr un_scalar_t watt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::WattHourPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_watt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::WattHourPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::KilowattHourPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_kilowatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::KilowattHourPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t megawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::MegawattHourPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_megawatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::MegawattHourPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t gigawatt_hours_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::GigawattHourPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_gigawatt_hours_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::GigawattHourPerPound);
        }

        [[nodiscard]] constexpr un_scalar_t btu_per_pound() const
        {
            return convert_from_base(SpecificEnergyUnit::BtuPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_btu_per_pound(const un_scalar_t value)
        {
            return SpecificEnergy(value, SpecificEnergyUnit::BtuPerPound);
        }

        [[nodiscard]] static constexpr SpecificEnergy from_invalid()
        {
            return SpecificEnergy(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, SpecificEnergyUnit unit)
        {
            switch (unit)
            {

            case SpecificEnergyUnit::JoulePerKilogram:
                return value;

            case SpecificEnergyUnit::KilojoulePerKilogram:
                return (value * static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::MegajoulePerKilogram:
                return (value * static_cast<un_scalar_t>(1e6));

            case SpecificEnergyUnit::MegajoulePerTonne:
                return value * static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::CaloriePerGram:
                return value * static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::KilocaloriePerGram:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::WattHourPerKilogram:
                return value * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::KilowattHourPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::MegawattHourPerKilogram:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::GigawattHourPerKilogram:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::WattDayPerKilogram:
                return value * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::KilowattDayPerKilogram:
                return (value * static_cast<un_scalar_t>(1e3)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::MegawattDayPerKilogram:
                return (value * static_cast<un_scalar_t>(1e6)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::GigawattDayPerKilogram:
                return (value * static_cast<un_scalar_t>(1e9)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::TerawattDayPerKilogram:
                return (value * static_cast<un_scalar_t>(1e12)) * (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::WattDayPerTonne:
                return value * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::KilowattDayPerTonne:
                return (value * static_cast<un_scalar_t>(1e3)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::MegawattDayPerTonne:
                return (value * static_cast<un_scalar_t>(1e6)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::GigawattDayPerTonne:
                return (value * static_cast<un_scalar_t>(1e9)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::TerawattDayPerTonne:
                return (value * static_cast<un_scalar_t>(1e12)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::WattDayPerShortTon:
                return value * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::KilowattDayPerShortTon:
                return (value * static_cast<un_scalar_t>(1e3)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::MegawattDayPerShortTon:
                return (value * static_cast<un_scalar_t>(1e6)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::GigawattDayPerShortTon:
                return (value * static_cast<un_scalar_t>(1e9)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::TerawattDayPerShortTon:
                return (value * static_cast<un_scalar_t>(1e12)) * ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::WattHourPerPound:
                return value * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::KilowattHourPerPound:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::MegawattHourPerPound:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::GigawattHourPerPound:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::BtuPerPound:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const SpecificEnergyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case SpecificEnergyUnit::JoulePerKilogram:
                return base_value;

            case SpecificEnergyUnit::KilojoulePerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegajoulePerKilogram:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::MegajoulePerTonne:
                return base_value / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::CaloriePerGram:
                return base_value / static_cast<un_scalar_t>(4.184e3);

            case SpecificEnergyUnit::KilocaloriePerGram:
                return (base_value / static_cast<un_scalar_t>(4.184e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::WattHourPerKilogram:
                return base_value / static_cast<un_scalar_t>(3.6e3);

            case SpecificEnergyUnit::KilowattHourPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattHourPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattHourPerKilogram:
                return (base_value / static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::WattDayPerKilogram:
                return base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3));

            case SpecificEnergyUnit::KilowattDayPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDayPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDayPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDayPerKilogram:
                return (base_value / (static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattDayPerTonne:
                return base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3));

            case SpecificEnergyUnit::KilowattDayPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDayPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDayPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDayPerTonne:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(1e3))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattDayPerShortTon:
                return base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2));

            case SpecificEnergyUnit::KilowattDayPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattDayPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattDayPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::TerawattDayPerShortTon:
                return (base_value / ((static_cast<un_scalar_t>(24) * static_cast<un_scalar_t>(3.6e3)) / static_cast<un_scalar_t>(9.0718474e2))) / static_cast<un_scalar_t>(1e12);

            case SpecificEnergyUnit::WattHourPerPound:
                return base_value / static_cast<un_scalar_t>(7.93664e3);

            case SpecificEnergyUnit::KilowattHourPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e3);

            case SpecificEnergyUnit::MegawattHourPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e6);

            case SpecificEnergyUnit::GigawattHourPerPound:
                return (base_value / static_cast<un_scalar_t>(7.93664e3)) / static_cast<un_scalar_t>(1e9);

            case SpecificEnergyUnit::BtuPerPound:
                return base_value * static_cast<un_scalar_t>(0.45359237) / static_cast<un_scalar_t>(1055.05585262);

            }

            throw std::invalid_argument("Unknown SpecificEnergy unit.");
        }

        un_scalar_t value_;
        SpecificEnergyUnit value_unit_type_;       
    };
}
