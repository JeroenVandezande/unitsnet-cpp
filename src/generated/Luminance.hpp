#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class LuminanceUnit : std::uint8_t
    {
        CandelasPerSquareMeter,
        NanocandelasPerSquareMeter,
        MicrocandelasPerSquareMeter,
        MillicandelasPerSquareMeter,
        CenticandelasPerSquareMeter,
        DecicandelasPerSquareMeter,
        KilocandelasPerSquareMeter,
        CandelasPerSquareFoot,
        CandelasPerSquareInch,
        Nits,
    };

    /// <summary></summary>
    class Luminance : public UnitsNetBase
    {
    public:
        constexpr explicit Luminance(
            const un_scalar_t value,
            const LuminanceUnit unit = LuminanceUnit::CandelasPerSquareMeter)
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
           return "Luminance"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case LuminanceUnit::CandelasPerSquareMeter:
                return "CandelasPerSquareMeter";

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return "NanocandelasPerSquareMeter";

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return "MicrocandelasPerSquareMeter";

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return "MillicandelasPerSquareMeter";

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return "CenticandelasPerSquareMeter";

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return "DecicandelasPerSquareMeter";

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return "KilocandelasPerSquareMeter";

            case LuminanceUnit::CandelasPerSquareFoot:
                return "CandelasPerSquareFoot";

            case LuminanceUnit::CandelasPerSquareInch:
                return "CandelasPerSquareInch";

            case LuminanceUnit::Nits:
                return "Nits";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const LuminanceUnit unit) const
        {
            return convert_from_base(unit);
        }

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
            return convert_from_base(LuminanceUnit::CandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t nanocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::NanocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_nanocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::NanocandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t microcandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MicrocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_microcandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MicrocandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t millicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::MillicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_millicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::MillicandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t centicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::CenticandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_centicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CenticandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t decicandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::DecicandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_decicandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::DecicandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t kilocandelas_per_square_meter() const
        {
            return convert_from_base(LuminanceUnit::KilocandelasPerSquareMeter);
        }

        [[nodiscard]] static constexpr Luminance from_kilocandelas_per_square_meter(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::KilocandelasPerSquareMeter);
        }

        [[nodiscard]] constexpr un_scalar_t candelas_per_square_foot() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareFoot);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_foot(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareFoot);
        }

        [[nodiscard]] constexpr un_scalar_t candelas_per_square_inch() const
        {
            return convert_from_base(LuminanceUnit::CandelasPerSquareInch);
        }

        [[nodiscard]] static constexpr Luminance from_candelas_per_square_inch(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::CandelasPerSquareInch);
        }

        [[nodiscard]] constexpr un_scalar_t nits() const
        {
            return convert_from_base(LuminanceUnit::Nits);
        }

        [[nodiscard]] static constexpr Luminance from_nits(const un_scalar_t value)
        {
            return Luminance(value, LuminanceUnit::Nits);
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

            case LuminanceUnit::CandelasPerSquareMeter:
                return value;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-9));

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-6));

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-3));

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-2));

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e-1));

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case LuminanceUnit::CandelasPerSquareFoot:
                return value / static_cast<un_scalar_t>(9.290304e-2);

            case LuminanceUnit::CandelasPerSquareInch:
                return value / static_cast<un_scalar_t>(0.00064516);

            case LuminanceUnit::Nits:
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

            case LuminanceUnit::CandelasPerSquareMeter:
                return base_value;

            case LuminanceUnit::NanocandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-9);

            case LuminanceUnit::MicrocandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-6);

            case LuminanceUnit::MillicandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-3);

            case LuminanceUnit::CenticandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-2);

            case LuminanceUnit::DecicandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e-1);

            case LuminanceUnit::KilocandelasPerSquareMeter:
                return (base_value) / static_cast<un_scalar_t>(1e3);

            case LuminanceUnit::CandelasPerSquareFoot:
                return base_value * static_cast<un_scalar_t>(9.290304e-2);

            case LuminanceUnit::CandelasPerSquareInch:
                return base_value * static_cast<un_scalar_t>(0.00064516);

            case LuminanceUnit::Nits:
                return base_value;

            }

            throw std::invalid_argument("Unknown Luminance unit.");
        }

        un_scalar_t value_;
        LuminanceUnit value_unit_type_;       
    };
}
