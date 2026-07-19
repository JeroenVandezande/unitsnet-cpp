#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class PorousMediumPermeabilityUnit : std::uint8_t
    {
        Darcys,
        Microdarcys,
        Millidarcys,
        SquareMeters,
        SquareCentimeters,
    };

    /// <summary></summary>
    class PorousMediumPermeability : public UnitsNetBase
    {
    public:
        constexpr explicit PorousMediumPermeability(
            const un_scalar_t value,
            const PorousMediumPermeabilityUnit unit = PorousMediumPermeabilityUnit::SquareMeters)
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
           return "PorousMediumPermeability"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return "Darcys";

            case PorousMediumPermeabilityUnit::Microdarcys:
                return "Microdarcys";

            case PorousMediumPermeabilityUnit::Millidarcys:
                return "Millidarcys";

            case PorousMediumPermeabilityUnit::SquareMeters:
                return "SquareMeters";

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return "SquareCentimeters";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const PorousMediumPermeabilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator+(const PorousMediumPermeability& other) const noexcept
        {
            return PorousMediumPermeability(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator-(const PorousMediumPermeability& other)const noexcept
        {
            return PorousMediumPermeability(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator*(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(base_value() * scalar);
        }

        [[nodiscard]] constexpr PorousMediumPermeability operator/(const un_scalar_t scalar) const noexcept
        {
            return PorousMediumPermeability(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const PorousMediumPermeability& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t darcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Darcys);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_darcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Darcys);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t microdarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Microdarcys);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_microdarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Microdarcys);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] constexpr un_scalar_t millidarcys() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::Millidarcys);
        }

        /// <summary>The darcy (or darcy unit) and millidarcy (md or mD) are units of permeability, named after Henry Darcy. They are not SI units, but they are widely used in petroleum engineering and geology.</summary>
        [[nodiscard]] static constexpr PorousMediumPermeability from_millidarcys(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::Millidarcys);
        }

        [[nodiscard]] constexpr un_scalar_t square_meters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareMeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_meters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareMeters);
        }

        [[nodiscard]] constexpr un_scalar_t square_centimeters() const
        {
            return convert_from_base(PorousMediumPermeabilityUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_square_centimeters(const un_scalar_t value)
        {
            return PorousMediumPermeability(value, PorousMediumPermeabilityUnit::SquareCentimeters);
        }

        [[nodiscard]] static constexpr PorousMediumPermeability from_invalid()
        {
            return PorousMediumPermeability(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, PorousMediumPermeabilityUnit unit)
        {
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return value * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::SquareMeters:
                return value;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return value * static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const PorousMediumPermeabilityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case PorousMediumPermeabilityUnit::Darcys:
                return base_value / static_cast<un_scalar_t>(9.869233e-13);

            case PorousMediumPermeabilityUnit::Microdarcys:
                return (base_value / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-6);

            case PorousMediumPermeabilityUnit::Millidarcys:
                return (base_value / static_cast<un_scalar_t>(9.869233e-13)) / static_cast<un_scalar_t>(1e-3);

            case PorousMediumPermeabilityUnit::SquareMeters:
                return base_value;

            case PorousMediumPermeabilityUnit::SquareCentimeters:
                return base_value / static_cast<un_scalar_t>(1e-4);

            }

            throw std::invalid_argument("Unknown PorousMediumPermeability unit.");
        }

        un_scalar_t value_;
        PorousMediumPermeabilityUnit value_unit_type_;       
    };
}
