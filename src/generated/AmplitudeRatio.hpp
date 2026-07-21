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
    enum class AmplitudeRatioUnit : std::uint8_t
    {
        DecibelVolt,
        DecibelMicrovolt,
        DecibelMillivolt,
        DecibelUnloaded,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of AmplitudeRatio.</summary>
    class AmplitudeRatioDto
    {
    public:
        constexpr AmplitudeRatioDto() noexcept
            : value{}, unit(AmplitudeRatioUnit::DecibelVolt)
        {
        }

        constexpr AmplitudeRatioDto(
            const un_scalar_t value,
            const AmplitudeRatioUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        AmplitudeRatioUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr AmplitudeRatioUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<AmplitudeRatioUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit name.");
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
        [[nodiscard]] static AmplitudeRatioDto from_json(const nlohmann::json& json)
        {
            return AmplitudeRatioDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>The strength of a signal expressed in decibels (dB) relative to one volt RMS.</summary>
    class AmplitudeRatio : public UnitsNetBase
    {
    public:
        constexpr explicit AmplitudeRatio(
            const un_scalar_t value,
            const AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolt)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const AmplitudeRatioUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr AmplitudeRatioDto to_dto(
            const AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolt) const
        {
            return AmplitudeRatioDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr AmplitudeRatio from_dto(const AmplitudeRatioDto& dto)
        {
            return AmplitudeRatio(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const AmplitudeRatioUnit unit = AmplitudeRatioUnit::DecibelVolt) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static AmplitudeRatio from_json(const nlohmann::json& json)
        {
            return from_dto(AmplitudeRatioDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr AmplitudeRatio operator+(const AmplitudeRatio& other) const noexcept
        {
            return AmplitudeRatio(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr AmplitudeRatio operator-(const AmplitudeRatio& other)const noexcept
        {
            return AmplitudeRatio(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr AmplitudeRatio operator*(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(base_value() * scalar);
        }

        [[nodiscard]] constexpr AmplitudeRatio operator/(const un_scalar_t scalar) const noexcept
        {
            return AmplitudeRatio(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const AmplitudeRatio& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const AmplitudeRatio& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const AmplitudeRatio& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t decibel_volts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelVolt);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_volts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelVolt);
        }

        [[nodiscard]] constexpr un_scalar_t decibel_microvolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMicrovolt);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_microvolts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMicrovolt);
        }

        [[nodiscard]] constexpr un_scalar_t decibel_millivolts() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelMillivolt);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibel_millivolts(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelMillivolt);
        }

        [[nodiscard]] constexpr un_scalar_t decibels_unloaded() const
        {
            return convert_from_base(AmplitudeRatioUnit::DecibelUnloaded);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_decibels_unloaded(const un_scalar_t value)
        {
            return AmplitudeRatio(value, AmplitudeRatioUnit::DecibelUnloaded);
        }

        [[nodiscard]] static constexpr AmplitudeRatio from_invalid()
        {
            return AmplitudeRatio(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, AmplitudeRatioUnit unit)
        {
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolt:
                return value;

            case AmplitudeRatioUnit::DecibelMicrovolt:
                return value - static_cast<un_scalar_t>(120);

            case AmplitudeRatioUnit::DecibelMillivolt:
                return value - static_cast<un_scalar_t>(60);

            case AmplitudeRatioUnit::DecibelUnloaded:
                return value - static_cast<un_scalar_t>(2.218487499);

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const AmplitudeRatioUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case AmplitudeRatioUnit::DecibelVolt:
                return base_value;

            case AmplitudeRatioUnit::DecibelMicrovolt:
                return base_value + static_cast<un_scalar_t>(120);

            case AmplitudeRatioUnit::DecibelMillivolt:
                return base_value + static_cast<un_scalar_t>(60);

            case AmplitudeRatioUnit::DecibelUnloaded:
                return base_value + static_cast<un_scalar_t>(2.218487499);

            }

            throw std::invalid_argument("Unknown AmplitudeRatio unit.");
        }

        un_scalar_t value_;
        AmplitudeRatioUnit value_unit_type_;       
    };
}
