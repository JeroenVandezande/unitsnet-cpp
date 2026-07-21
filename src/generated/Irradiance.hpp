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
    enum class IrradianceUnit : std::uint8_t
    {
        WattPerSquareMeter,
        PicowattPerSquareMeter,
        NanowattPerSquareMeter,
        MicrowattPerSquareMeter,
        MilliwattPerSquareMeter,
        KilowattPerSquareMeter,
        MegawattPerSquareMeter,
        WattPerSquareCentimeter,
        PicowattPerSquareCentimeter,
        NanowattPerSquareCentimeter,
        MicrowattPerSquareCentimeter,
        MilliwattPerSquareCentimeter,
        KilowattPerSquareCentimeter,
        MegawattPerSquareCentimeter,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of Irradiance.</summary>
    class IrradianceDto
    {
    public:
        constexpr IrradianceDto() noexcept
            : value{}, unit(IrradianceUnit::WattPerSquareMeter)
        {
        }

        constexpr IrradianceDto(
            const un_scalar_t value,
            const IrradianceUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        IrradianceUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr IrradianceUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<IrradianceUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown Irradiance unit name.");
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
        [[nodiscard]] static IrradianceDto from_json(const nlohmann::json& json)
        {
            return IrradianceDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>Irradiance is the intensity of ultraviolet (UV) or visible light incident on a surface.</summary>
    class Irradiance : public UnitsNetBase
    {
    public:
        constexpr explicit Irradiance(
            const un_scalar_t value,
            const IrradianceUnit unit = IrradianceUnit::WattPerSquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const IrradianceUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr IrradianceDto to_dto(
            const IrradianceUnit unit = IrradianceUnit::WattPerSquareMeter) const
        {
            return IrradianceDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr Irradiance from_dto(const IrradianceDto& dto)
        {
            return Irradiance(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const IrradianceUnit unit = IrradianceUnit::WattPerSquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static Irradiance from_json(const nlohmann::json& json)
        {
            return from_dto(IrradianceDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr Irradiance operator+(const Irradiance& other) const noexcept
        {
            return Irradiance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Irradiance operator-(const Irradiance& other)const noexcept
        {
            return Irradiance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Irradiance operator*(const un_scalar_t scalar) const noexcept
        {
            return Irradiance(base_value() * scalar);
        }

        [[nodiscard]] constexpr Irradiance operator/(const un_scalar_t scalar) const noexcept
        {
            return Irradiance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Irradiance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Irradiance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Irradiance& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::WattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::WattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::PicowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::PicowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::NanowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::NanowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::KilowattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::KilowattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_square_meter() const
        {
            return convert_from_base(IrradianceUnit::MegawattPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_meter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MegawattPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t watts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::WattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_watts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::WattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t picowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::PicowattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_picowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::PicowattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::NanowattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_nanowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::NanowattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MicrowattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_microwatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MicrowattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliwatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MilliwattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_milliwatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MilliwattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilowatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::KilowattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_kilowatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::KilowattPerSquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megawatts_per_square_centimeter() const
        {
            return convert_from_base(IrradianceUnit::MegawattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_megawatts_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiance(value, IrradianceUnit::MegawattPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiance from_invalid()
        {
            return Irradiance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IrradianceUnit unit)
        {
            switch (unit)
            {

            case IrradianceUnit::WattPerSquareMeter:
                return value;

            case IrradianceUnit::PicowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-12));

            case IrradianceUnit::NanowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case IrradianceUnit::MicrowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case IrradianceUnit::MilliwattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case IrradianceUnit::KilowattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case IrradianceUnit::MegawattPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e6));

            case IrradianceUnit::WattPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::PicowattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::NanowattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MicrowattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MilliwattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::KilowattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(10000);

            case IrradianceUnit::MegawattPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(10000);

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IrradianceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case IrradianceUnit::WattPerSquareMeter:
                return base_value;

            case IrradianceUnit::PicowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case IrradianceUnit::NanowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case IrradianceUnit::MicrowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case IrradianceUnit::MilliwattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case IrradianceUnit::KilowattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case IrradianceUnit::MegawattPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case IrradianceUnit::WattPerSquareCentimeter:
                return base_value * static_cast<un_scalar_t>(0.0001);

            case IrradianceUnit::PicowattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-12);

            case IrradianceUnit::NanowattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-9);

            case IrradianceUnit::MicrowattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-6);

            case IrradianceUnit::MilliwattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e-3);

            case IrradianceUnit::KilowattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e3);

            case IrradianceUnit::MegawattPerSquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(0.0001)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Irradiance unit.");
        }

        un_scalar_t value_;
        IrradianceUnit value_unit_type_;       
    };
}
