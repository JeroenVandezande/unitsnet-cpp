#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ElectricResistivityUnit : std::uint8_t
    {
        OhmMeters,
        PicoohmMeters,
        NanoohmMeters,
        MicroohmMeters,
        MilliohmMeters,
        KiloohmMeters,
        MegaohmMeters,
        OhmsCentimeter,
        PicoohmsCentimeter,
        NanoohmsCentimeter,
        MicroohmsCentimeter,
        MilliohmsCentimeter,
        KiloohmsCentimeter,
        MegaohmsCentimeter,
    };

    /// <summary>Electrical resistivity (also known as resistivity, specific electrical resistance, or volume resistivity) is a fundamental property that quantifies how strongly a given material opposes the flow of electric current.</summary>
    class ElectricResistivity : public UnitsNetBase
    {
    public:
        constexpr explicit ElectricResistivity(
            const un_scalar_t value,
            const ElectricResistivityUnit unit = ElectricResistivityUnit::OhmMeters)
        {
            value_ = value;
            value_unit_type_ = unit;
        }
        
        [[nodiscard]] constexpr un_scalar_t stored_value() const noexcept override
        {
           return value_; 
        }
        
        [[nodiscard]] constexpr std::string_view quantity_name() const noexcept override
        {
           return "ElectricResistivity"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case ElectricResistivityUnit::OhmMeters:
                return "OhmMeters";

            case ElectricResistivityUnit::PicoohmMeters:
                return "PicoohmMeters";

            case ElectricResistivityUnit::NanoohmMeters:
                return "NanoohmMeters";

            case ElectricResistivityUnit::MicroohmMeters:
                return "MicroohmMeters";

            case ElectricResistivityUnit::MilliohmMeters:
                return "MilliohmMeters";

            case ElectricResistivityUnit::KiloohmMeters:
                return "KiloohmMeters";

            case ElectricResistivityUnit::MegaohmMeters:
                return "MegaohmMeters";

            case ElectricResistivityUnit::OhmsCentimeter:
                return "OhmsCentimeter";

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return "PicoohmsCentimeter";

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return "NanoohmsCentimeter";

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return "MicroohmsCentimeter";

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return "MilliohmsCentimeter";

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return "KiloohmsCentimeter";

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return "MegaohmsCentimeter";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ElectricResistivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricResistivity operator+(const ElectricResistivity& other) const noexcept
        {
            return ElectricResistivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistivity operator-(const ElectricResistivity& other)const noexcept
        {
            return ElectricResistivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ElectricResistivity operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr ElectricResistivity operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricResistivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricResistivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ElectricResistivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricResistivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t ohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t picoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t microohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t milliohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t megaohm_meters() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmMeters);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohm_meters(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmMeters);
        }

        [[nodiscard]] constexpr un_scalar_t ohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::OhmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_ohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::OhmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t picoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::PicoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_picoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::PicoohmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanoohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::NanoohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_nanoohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::NanoohmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t microohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MicroohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_microohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MicroohmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t milliohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MilliohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_milliohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MilliohmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t kiloohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::KiloohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_kiloohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::KiloohmsCentimeter);
        }

        [[nodiscard]] constexpr un_scalar_t megaohms_centimeter() const
        {
            return convert_from_base(ElectricResistivityUnit::MegaohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_megaohms_centimeter(const un_scalar_t value)
        {
            return ElectricResistivity(value, ElectricResistivityUnit::MegaohmsCentimeter);
        }

        [[nodiscard]] static constexpr ElectricResistivity from_invalid()
        {
            return ElectricResistivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricResistivityUnit unit)
        {
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return value;

            case ElectricResistivityUnit::PicoohmMeters:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricResistivityUnit::NanoohmMeters:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricResistivityUnit::MicroohmMeters:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricResistivityUnit::MilliohmMeters:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricResistivityUnit::KiloohmMeters:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricResistivityUnit::MegaohmMeters:
                return (value * static_cast<un_scalar_t>(1e6));

            case ElectricResistivityUnit::OhmsCentimeter:
                return value / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-12)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (value * static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(100);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricResistivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case ElectricResistivityUnit::OhmMeters:
                return base_value;

            case ElectricResistivityUnit::PicoohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmMeters:
                return (base_value) / static_cast<un_scalar_t>(1e6);

            case ElectricResistivityUnit::OhmsCentimeter:
                return base_value * static_cast<un_scalar_t>(100);

            case ElectricResistivityUnit::PicoohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-12);

            case ElectricResistivityUnit::NanoohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-9);

            case ElectricResistivityUnit::MicroohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-6);

            case ElectricResistivityUnit::MilliohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e-3);

            case ElectricResistivityUnit::KiloohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e3);

            case ElectricResistivityUnit::MegaohmsCentimeter:
                return (base_value * static_cast<un_scalar_t>(100)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricResistivity unit.");
        }

        un_scalar_t value_;
        ElectricResistivityUnit value_unit_type_;       
    };
}
