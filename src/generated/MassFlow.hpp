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
    enum class MassFlowUnit : std::uint8_t
    {
        GramPerSecond,
        NanogramPerSecond,
        MicrogramPerSecond,
        MilligramPerSecond,
        CentigramPerSecond,
        DecigramPerSecond,
        DecagramPerSecond,
        HectogramPerSecond,
        KilogramPerSecond,
        GramPerDay,
        NanogramPerDay,
        MicrogramPerDay,
        MilligramPerDay,
        CentigramPerDay,
        DecigramPerDay,
        DecagramPerDay,
        HectogramPerDay,
        KilogramPerDay,
        MegagramPerDay,
        GramPerHour,
        KilogramPerHour,
        KilogramPerMinute,
        TonnePerHour,
        PoundPerDay,
        MegapoundPerDay,
        PoundPerHour,
        MegapoundPerHour,
        PoundPerMinute,
        MegapoundPerMinute,
        PoundPerSecond,
        MegapoundPerSecond,
        TonnePerDay,
        ShortTonPerHour,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of MassFlow.</summary>
    class MassFlowDto
    {
    public:
        constexpr MassFlowDto() noexcept
            : value{}, unit(MassFlowUnit::GramPerSecond)
        {
        }

        constexpr MassFlowDto(
            const un_scalar_t value,
            const MassFlowUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        MassFlowUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr MassFlowUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<MassFlowUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown MassFlow unit name.");
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
        [[nodiscard]] static MassFlowDto from_json(const nlohmann::json& json)
        {
            return MassFlowDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Mass flow is the ratio of the mass change to the time during which the change occurred (value of mass changes per unit time).</summary>
    class MassFlow : public UnitsNetBase
    {
    public:
        constexpr explicit MassFlow(
            const un_scalar_t value,
            const MassFlowUnit unit = MassFlowUnit::GramPerSecond)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MassFlowUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr MassFlowDto to_dto(
            const MassFlowUnit unit = MassFlowUnit::GramPerSecond) const
        {
            return MassFlowDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr MassFlow from_dto(const MassFlowDto& dto)
        {
            return MassFlow(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const MassFlowUnit unit = MassFlowUnit::GramPerSecond) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static MassFlow from_json(const nlohmann::json& json)
        {
            return from_dto(MassFlowDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr MassFlow operator+(const MassFlow& other) const noexcept
        {
            return MassFlow(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MassFlow operator-(const MassFlow& other)const noexcept
        {
            return MassFlow(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MassFlow operator*(const un_scalar_t scalar) const noexcept
        {
            return MassFlow(base_value() * scalar);
        }

        [[nodiscard]] constexpr MassFlow operator/(const un_scalar_t scalar) const noexcept
        {
            return MassFlow(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MassFlow& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MassFlow& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MassFlow& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_second() const
        {
            return convert_from_base(MassFlowUnit::GramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::NanogramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::NanogramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::MicrogramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::MilligramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MilligramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::CentigramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::CentigramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecigramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecigramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_second() const
        {
            return convert_from_base(MassFlowUnit::DecagramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecagramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::HectogramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::HectogramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_second() const
        {
            return convert_from_base(MassFlowUnit::KilogramPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_day() const
        {
            return convert_from_base(MassFlowUnit::GramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t nanograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::NanogramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_nanograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::NanogramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t micrograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::MicrogramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_micrograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MicrogramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t milligrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MilligramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_milligrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MilligramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t centigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::CentigramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_centigrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::CentigramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t decigrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecigramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decigrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecigramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t decagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::DecagramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_decagrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::DecagramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t hectograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::HectogramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_hectograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::HectogramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_day() const
        {
            return convert_from_base(MassFlowUnit::KilogramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megagrams_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegagramPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megagrams_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegagramPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t grams_per_hour() const
        {
            return convert_from_base(MassFlowUnit::GramPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_grams_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::GramPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_hour() const
        {
            return convert_from_base(MassFlowUnit::KilogramPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t kilograms_per_minute() const
        {
            return convert_from_base(MassFlowUnit::KilogramPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_kilograms_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::KilogramPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_hour() const
        {
            return convert_from_base(MassFlowUnit::TonnePerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::TonnePerHour);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::PoundPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_day() const
        {
            return convert_from_base(MassFlowUnit::MegapoundPerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundPerDay);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::PoundPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_hour() const
        {
            return convert_from_base(MassFlowUnit::MegapoundPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundPerHour);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::PoundPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_minute() const
        {
            return convert_from_base(MassFlowUnit::MegapoundPerMinute);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_minute(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundPerMinute);
        }

        [[nodiscard]] constexpr un_scalar_t pounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::PoundPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_pounds_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::PoundPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t megapounds_per_second() const
        {
            return convert_from_base(MassFlowUnit::MegapoundPerSecond);
        }

        [[nodiscard]] static constexpr MassFlow from_megapounds_per_second(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::MegapoundPerSecond);
        }

        [[nodiscard]] constexpr un_scalar_t tonnes_per_day() const
        {
            return convert_from_base(MassFlowUnit::TonnePerDay);
        }

        [[nodiscard]] static constexpr MassFlow from_tonnes_per_day(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::TonnePerDay);
        }

        [[nodiscard]] constexpr un_scalar_t short_tons_per_hour() const
        {
            return convert_from_base(MassFlowUnit::ShortTonPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_short_tons_per_hour(const un_scalar_t value)
        {
            return MassFlow(value, MassFlowUnit::ShortTonPerHour);
        }

        [[nodiscard]] static constexpr MassFlow from_invalid()
        {
            return MassFlow(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MassFlowUnit unit)
        {
            switch (unit)
            {

            case MassFlowUnit::GramPerSecond:
                return value;

            case MassFlowUnit::NanogramPerSecond:
                return (value * static_cast<un_scalar_t>(1e-9));

            case MassFlowUnit::MicrogramPerSecond:
                return (value * static_cast<un_scalar_t>(1e-6));

            case MassFlowUnit::MilligramPerSecond:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MassFlowUnit::CentigramPerSecond:
                return (value * static_cast<un_scalar_t>(1e-2));

            case MassFlowUnit::DecigramPerSecond:
                return (value * static_cast<un_scalar_t>(1e-1));

            case MassFlowUnit::DecagramPerSecond:
                return (value * static_cast<un_scalar_t>(1e1));

            case MassFlowUnit::HectogramPerSecond:
                return (value * static_cast<un_scalar_t>(1e2));

            case MassFlowUnit::KilogramPerSecond:
                return (value * static_cast<un_scalar_t>(1e3));

            case MassFlowUnit::GramPerDay:
                return value / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::NanogramPerDay:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MicrogramPerDay:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MilligramPerDay:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::CentigramPerDay:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::DecigramPerDay:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::DecagramPerDay:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::HectogramPerDay:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::KilogramPerDay:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MegagramPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::GramPerHour:
                return value / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::KilogramPerHour:
                return value / static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::KilogramPerMinute:
                return value / static_cast<un_scalar_t>(0.06);

            case MassFlowUnit::TonnePerHour:
                return value * static_cast<un_scalar_t>(1000) / static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::PoundPerDay:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::MegapoundPerDay:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(86400);

            case MassFlowUnit::PoundPerHour:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::MegapoundPerHour:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(3600);

            case MassFlowUnit::PoundPerMinute:
                return value * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(60);

            case MassFlowUnit::MegapoundPerMinute:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237) / static_cast<un_scalar_t>(60);

            case MassFlowUnit::PoundPerSecond:
                return value * static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundPerSecond:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::TonnePerDay:
                return value / static_cast<un_scalar_t>(0.0864000);

            case MassFlowUnit::ShortTonPerHour:
                return value * static_cast<un_scalar_t>(907.18474) / static_cast<un_scalar_t>(3.6);

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MassFlowUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case MassFlowUnit::GramPerSecond:
                return base_value;

            case MassFlowUnit::NanogramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case MassFlowUnit::MicrogramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case MassFlowUnit::MilligramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case MassFlowUnit::CentigramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case MassFlowUnit::DecigramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case MassFlowUnit::DecagramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e1);

            case MassFlowUnit::HectogramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e2);

            case MassFlowUnit::KilogramPerSecond:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case MassFlowUnit::GramPerDay:
                return base_value * static_cast<un_scalar_t>(86400);

            case MassFlowUnit::NanogramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-9);

            case MassFlowUnit::MicrogramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-6);

            case MassFlowUnit::MilligramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-3);

            case MassFlowUnit::CentigramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-2);

            case MassFlowUnit::DecigramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e-1);

            case MassFlowUnit::DecagramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e1);

            case MassFlowUnit::HectogramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e2);

            case MassFlowUnit::KilogramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e3);

            case MassFlowUnit::MegagramPerDay:
                return (base_value * static_cast<un_scalar_t>(86400)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::GramPerHour:
                return base_value * static_cast<un_scalar_t>(3600);

            case MassFlowUnit::KilogramPerHour:
                return base_value * static_cast<un_scalar_t>(3.6);

            case MassFlowUnit::KilogramPerMinute:
                return base_value * static_cast<un_scalar_t>(0.06);

            case MassFlowUnit::TonnePerHour:
                return base_value * static_cast<un_scalar_t>(3.6) / static_cast<un_scalar_t>(1000);

            case MassFlowUnit::PoundPerDay:
                return base_value * static_cast<un_scalar_t>(86400) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundPerDay:
                return (base_value * static_cast<un_scalar_t>(86400) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundPerHour:
                return base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundPerHour:
                return (base_value * static_cast<un_scalar_t>(3600) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundPerMinute:
                return base_value * static_cast<un_scalar_t>(60) / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundPerMinute:
                return (base_value * static_cast<un_scalar_t>(60) / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::PoundPerSecond:
                return base_value / static_cast<un_scalar_t>(453.59237);

            case MassFlowUnit::MegapoundPerSecond:
                return (base_value / static_cast<un_scalar_t>(453.59237)) / static_cast<un_scalar_t>(1e6);

            case MassFlowUnit::TonnePerDay:
                return base_value * static_cast<un_scalar_t>(0.0864000);

            case MassFlowUnit::ShortTonPerHour:
                return base_value * static_cast<un_scalar_t>(3.6) / static_cast<un_scalar_t>(907.18474);

            }

            throw std::invalid_argument("Unknown MassFlow unit.");
        }

        un_scalar_t value_;
        MassFlowUnit value_unit_type_;       
    };
}
