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
    enum class LuminanceUnit : std::uint8_t
    {
        CandelaPerSquareMeter,
        NanocandelaPerSquareMeter,
        MicrocandelaPerSquareMeter,
        MillicandelaPerSquareMeter,
        CenticandelaPerSquareMeter,
        DecicandelaPerSquareMeter,
        KilocandelaPerSquareMeter,
        CandelaPerSquareFoot,
        CandelaPerSquareInch,
        Nit,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Luminance.</summary>
    class LuminanceDto
    {
    public:
        constexpr LuminanceDto() noexcept
            : value{}, unit(LuminanceUnit::CandelaPerSquareMeter)
        {
        }

        constexpr LuminanceDto(
            const un_scalar_t value,
            const LuminanceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        LuminanceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr LuminanceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<LuminanceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Luminance unit name.");
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
        [[nodiscard]] static LuminanceDto from_json(const nlohmann::json& json)
        {
            return LuminanceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary></summary>
    class Luminance : public UnitsNetBase
    {
    public:
        constexpr explicit Luminance(
            const un_scalar_t value,
            const LuminanceUnit unit = LuminanceUnit::CandelaPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr LuminanceDto to_dto(
            const LuminanceUnit unit = LuminanceUnit::CandelaPerSquareMeter) const
        {
            return LuminanceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Luminance from_dto(const LuminanceDto& dto)
        {
            return Luminance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const LuminanceUnit unit = LuminanceUnit::CandelaPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Luminance from_json(const nlohmann::json& json)
        {
            return from_dto(LuminanceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Luminance operator+(const Luminance& other) const noexcept
        {
            return Luminance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Luminance operator-(const Luminance& other)const noexcept
        {
            return Luminance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Luminance operator*(const un_scalar_t scalar) const noexcept
        {
            return Luminance(base_value() * scalar);
        }

        [[nodiscard]] constexpr Luminance operator/(const un_scalar_t scalar) const noexcept
        {
            return Luminance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Luminance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Luminance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Luminance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t candelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::NanocandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_nanocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::NanocandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microcandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MicrocandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_microcandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MicrocandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t millicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MillicandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_millicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MillicandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CenticandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_centicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CenticandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::DecicandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_decicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::DecicandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::KilocandelaPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_kilocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::KilocandelaPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t candelas_per_square_foot() const
        {
            return convert_from_base(LuminanceUnit::CandelaPerSquareFoot);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_foot(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelaPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t candelas_per_square_inch() const
        {
            return convert_from_base(LuminanceUnit::CandelaPerSquareInch);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_inch(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelaPerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t nits() const
        {
            return convert_from_base(LuminanceUnit::Nit);
        }

        [[nodiscard]] static constexpr Luminance from_nits(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::Nit);
        }

        [[nodiscard]] static constexpr Luminance from_invalid()
        {
            return Luminance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, LuminanceUnit unit)
        {
            switch (unit)
            {

            case LuminanceUnit::CandelaPerSquareMeter:
                return value;

            case LuminanceUnit::NanocandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LuminanceUnit::MicrocandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LuminanceUnit::MillicandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LuminanceUnit::CenticandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case LuminanceUnit::DecicandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LuminanceUnit::KilocandelaPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LuminanceUnit::CandelaPerSquareFoot:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            case LuminanceUnit::CandelaPerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            case LuminanceUnit::Nit:
                return value;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const LuminanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case LuminanceUnit::CandelaPerSquareMeter:
                return base_value;

            case LuminanceUnit::NanocandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case LuminanceUnit::MicrocandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case LuminanceUnit::MillicandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LuminanceUnit::CenticandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case LuminanceUnit::DecicandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case LuminanceUnit::KilocandelaPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LuminanceUnit::CandelaPerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2);

            case LuminanceUnit::CandelaPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            case LuminanceUnit::Nit:
                return base_value;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        un_scalar_t value_;
        LuminanceUnit value_unit_type_;       
    };
}
