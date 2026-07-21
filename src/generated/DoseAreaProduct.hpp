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
    enum class DoseAreaProductUnit : std::uint8_t
    {
        GraySquareMeter,
        MicrograySquareMeter,
        MilligraySquareMeter,
        CentigraySquareMeter,
        DecigraySquareMeter,
        GraySquareDecimeter,
        MicrograySquareDecimeter,
        MilligraySquareDecimeter,
        CentigraySquareDecimeter,
        DecigraySquareDecimeter,
        GraySquareCentimeter,
        MicrograySquareCentimeter,
        MilligraySquareCentimeter,
        CentigraySquareCentimeter,
        DecigraySquareCentimeter,
        GraySquareMillimeter,
        MicrograySquareMillimeter,
        MilligraySquareMillimeter,
        CentigraySquareMillimeter,
        DecigraySquareMillimeter,
        GraySquareMicrometer,
        MicrograySquareMicrometer,
        MilligraySquareMicrometer,
        CentigraySquareMicrometer,
        DecigraySquareMicrometer,
    };

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
    /// <summary>A data-transfer representation of DoseAreaProduct.</summary>
    class DoseAreaProductDto
    {
    public:
        constexpr DoseAreaProductDto() noexcept
            : value{}, unit(DoseAreaProductUnit::GraySquareMeter)
        {
        }

        constexpr DoseAreaProductDto(
            const un_scalar_t value,
            const DoseAreaProductUnit unit) noexcept
            : value(value), unit(unit)
        {
        }

        /// <summary>The numeric value of the quantity.</summary>
        un_scalar_t value;

        /// <summary>The unit in which value is expressed.</summary>
        DoseAreaProductUnit unit;

        /// <summary>The stable UnitsNet name used for cross-language serialization.</summary>
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept
        {
            return magic_enum::enum_name(unit);
        }

        /// <summary>Converts a stable UnitsNet unit name to its strongly typed enum.</summary>
        [[nodiscard]] static constexpr DoseAreaProductUnit unit_from_name(const std::string_view name)
        {
            const auto unit = magic_enum::enum_cast<DoseAreaProductUnit>(name);
            if (unit.has_value())
            {
                return *unit;
            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit name.");
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
        [[nodiscard]] static DoseAreaProductDto from_json(const nlohmann::json& json)
        {
            return DoseAreaProductDto(
                json.at("value").get<un_scalar_t>(),
                unit_from_name(json.at("unit").get<std::string>()));
        }
#endif
    };
#endif

    /// <summary>It is defined as the absorbed dose multiplied by the area irradiated.</summary>
    class DoseAreaProduct : public UnitsNetBase
    {
    public:
        constexpr explicit DoseAreaProduct(
            const un_scalar_t value,
            const DoseAreaProductUnit unit = DoseAreaProductUnit::GraySquareMeter)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const DoseAreaProductUnit unit) const
        {
            return convert_from_base(unit);
        }

#if defined(UNITSNET_ENABLE_DTO) || defined(UNITSNET_ENABLE_NLOHMANN_JSON)
        /// <summary>Creates a DTO, expressed in the requested unit.</summary>
        [[nodiscard]] constexpr DoseAreaProductDto to_dto(
            const DoseAreaProductUnit unit = DoseAreaProductUnit::GraySquareMeter) const
        {
            return DoseAreaProductDto(value(unit), unit);
        }

        /// <summary>Creates a quantity from its DTO representation.</summary>
        [[nodiscard]] static constexpr DoseAreaProduct from_dto(const DoseAreaProductDto& dto)
        {
            return DoseAreaProduct(dto.value, dto.unit);
        }

#ifdef UNITSNET_ENABLE_NLOHMANN_JSON
        /// <summary>Serializes this quantity to a nlohmann JSON object.</summary>
        [[nodiscard]] nlohmann::json to_json(
            const DoseAreaProductUnit unit = DoseAreaProductUnit::GraySquareMeter) const
        {
            return to_dto(unit).to_json();
        }

        /// <summary>Creates a quantity from a nlohmann JSON object.</summary>
        [[nodiscard]] static DoseAreaProduct from_json(const nlohmann::json& json)
        {
            return from_dto(DoseAreaProductDto::from_json(json));
        }
#endif
#endif

        [[nodiscard]] constexpr DoseAreaProduct operator+(const DoseAreaProduct& other) const noexcept
        {
            return DoseAreaProduct(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr DoseAreaProduct operator-(const DoseAreaProduct& other)const noexcept
        {
            return DoseAreaProduct(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr DoseAreaProduct operator*(const un_scalar_t scalar) const noexcept
        {
            return DoseAreaProduct(base_value() * scalar);
        }

        [[nodiscard]] constexpr DoseAreaProduct operator/(const un_scalar_t scalar) const noexcept
        {
            return DoseAreaProduct(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const DoseAreaProduct& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const DoseAreaProduct& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const DoseAreaProduct& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t gray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microgray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decigray_square_meters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_meters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t gray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareDecimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microgray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareDecimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareDecimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareDecimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decigray_square_decimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareDecimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_decimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareDecimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareCentimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microgray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareCentimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareCentimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareCentimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decigray_square_centimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareCentimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_centimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMillimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microgray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMillimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milligray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMillimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t centigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMillimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t decigray_square_millimeters() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMillimeter);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_millimeters(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMillimeter);
        }

        [[nodiscard]] constexpr un_scalar_t gray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::GraySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_gray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::GraySquareMicrometer);
        }

        [[nodiscard]] constexpr un_scalar_t microgray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MicrograySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_microgray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MicrograySquareMicrometer);
        }

        [[nodiscard]] constexpr un_scalar_t milligray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::MilligraySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_milligray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::MilligraySquareMicrometer);
        }

        [[nodiscard]] constexpr un_scalar_t centigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::CentigraySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_centigray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::CentigraySquareMicrometer);
        }

        [[nodiscard]] constexpr un_scalar_t decigray_square_micrometers() const
        {
            return convert_from_base(DoseAreaProductUnit::DecigraySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_decigray_square_micrometers(const un_scalar_t value)
        {
            return DoseAreaProduct(value, DoseAreaProductUnit::DecigraySquareMicrometer);
        }

        [[nodiscard]] static constexpr DoseAreaProduct from_invalid()
        {
            return DoseAreaProduct(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, DoseAreaProductUnit unit)
        {
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeter:
                return value;

            case DoseAreaProductUnit::MicrograySquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case DoseAreaProductUnit::MilligraySquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case DoseAreaProductUnit::CentigraySquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case DoseAreaProductUnit::DecigraySquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case DoseAreaProductUnit::GraySquareDecimeter:
                return value / static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::MicrograySquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::MilligraySquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::CentigraySquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::DecigraySquareDecimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::GraySquareCentimeter:
                return value / static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::MicrograySquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::MilligraySquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::CentigraySquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::DecigraySquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::GraySquareMillimeter:
                return value / static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::MicrograySquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::MilligraySquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::CentigraySquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::DecigraySquareMillimeter:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::GraySquareMicrometer:
                return value / static_cast<un_scalar_t>(1000000000000);

            case DoseAreaProductUnit::MicrograySquareMicrometer:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1000000000000);

            case DoseAreaProductUnit::MilligraySquareMicrometer:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1000000000000);

            case DoseAreaProductUnit::CentigraySquareMicrometer:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1000000000000);

            case DoseAreaProductUnit::DecigraySquareMicrometer:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1000000000000);

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const DoseAreaProductUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case DoseAreaProductUnit::GraySquareMeter:
                return base_value;

            case DoseAreaProductUnit::MicrograySquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareDecimeter:
                return base_value * static_cast<un_scalar_t>(100);

            case DoseAreaProductUnit::MicrograySquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareDecimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareCentimeter:
                return base_value * static_cast<un_scalar_t>(10000);

            case DoseAreaProductUnit::MicrograySquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(10000)) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(10000)) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(10000)) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareCentimeter:
                return (base_value * static_cast<un_scalar_t>(10000)) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareMillimeter:
                return base_value * static_cast<un_scalar_t>(1000000);

            case DoseAreaProductUnit::MicrograySquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000000)) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000000)) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000000)) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMillimeter:
                return (base_value * static_cast<un_scalar_t>(1000000)) / static_cast<un_scalar_t>(1e-1);

            case DoseAreaProductUnit::GraySquareMicrometer:
                return base_value * static_cast<un_scalar_t>(1000000000000);

            case DoseAreaProductUnit::MicrograySquareMicrometer:
                return (base_value * static_cast<un_scalar_t>(1000000000000)) / static_cast<un_scalar_t>(1e-6);

            case DoseAreaProductUnit::MilligraySquareMicrometer:
                return (base_value * static_cast<un_scalar_t>(1000000000000)) / static_cast<un_scalar_t>(1e-3);

            case DoseAreaProductUnit::CentigraySquareMicrometer:
                return (base_value * static_cast<un_scalar_t>(1000000000000)) / static_cast<un_scalar_t>(1e-2);

            case DoseAreaProductUnit::DecigraySquareMicrometer:
                return (base_value * static_cast<un_scalar_t>(1000000000000)) / static_cast<un_scalar_t>(1e-1);

            }

            throw std::invalid_argument("Unknown DoseAreaProduct unit.");
        }

        un_scalar_t value_;
        DoseAreaProductUnit value_unit_type_;       
    };
}
