#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class ThermalInsulanceUnit : std::uint8_t
    {
        SquareMeterKelvinsPerKilowatt,
        SquareMeterKelvinsPerWatt,
        SquareMeterDegreesCelsiusPerWatt,
        SquareCentimeterKelvinsPerWatt,
        SquareMillimeterKelvinsPerWatt,
        SquareCentimeterHourDegreesCelsiusPerKilocalorie,
        HourSquareFeetDegreesFahrenheitPerBtu,
    };

    /// <summary>Thermal insulance (R-value) is a measure of a material's resistance to the heat current. It quantifies how effectively a material can resist the transfer of heat through conduction, convection, and radiation. It has the units square metre kelvins per watt (m2⋅K/W) in SI units or square foot degree Fahrenheit–hours per British thermal unit (ft2⋅°F⋅h/Btu) in imperial units. The higher the thermal insulance, the better a material insulates against heat transfer. It is commonly used in construction to assess the insulation properties of materials such as walls, roofs, and insulation products.</summary>
    class ThermalInsulance : public UnitsNetBase
    {
    public:
        constexpr explicit ThermalInsulance(
            const un_scalar_t value,
            const ThermalInsulanceUnit unit = ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const ThermalInsulanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ThermalInsulance operator+(const ThermalInsulance& other) const noexcept
        {
            return ThermalInsulance(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr ThermalInsulance operator-(const ThermalInsulance& other)const noexcept
        {
            return ThermalInsulance(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr ThermalInsulance operator*(const un_scalar_t scalar) const noexcept
        {
            return ThermalInsulance(base_value() * scalar);
        }

        [[nodiscard]] constexpr ThermalInsulance operator/(const un_scalar_t scalar) const noexcept
        {
            return ThermalInsulance(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ThermalInsulance& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const ThermalInsulance& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const ThermalInsulance& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t square_meter_kelvins_per_kilowatt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_kilowatt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt);
        }


        [[nodiscard]] constexpr un_scalar_t square_meter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr un_scalar_t square_meter_degrees_celsius_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_meter_degrees_celsius_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt);
        }


        [[nodiscard]] constexpr un_scalar_t square_centimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr un_scalar_t square_millimeter_kelvins_per_watt() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_millimeter_kelvins_per_watt(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt);
        }


        [[nodiscard]] constexpr un_scalar_t square_centimeter_hour_degrees_celsius_per_kilocalorie() const
        {
            return convert_from_base(ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_square_centimeter_hour_degrees_celsius_per_kilocalorie(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie);
        }


        [[nodiscard]] constexpr un_scalar_t hour_square_feet_degrees_fahrenheit_per_btu() const
        {
            return convert_from_base(ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu);
        }

        [[nodiscard]] static constexpr ThermalInsulance from_hour_square_feet_degrees_fahrenheit_per_btu(const un_scalar_t value)
        {
            return ThermalInsulance(value, ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu);
        }


        [[nodiscard]] static constexpr ThermalInsulance from_invalid()
        {
            return ThermalInsulance(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ThermalInsulanceUnit unit)
        {
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt:
                return value;

            case ThermalInsulanceUnit::SquareMeterKelvinsPerWatt:
                return value * static_cast<un_scalar_t>(1000);

            case ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt:
                return value * static_cast<un_scalar_t>(1000.0);

            case ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt:
                return value * static_cast<un_scalar_t>(0.1);

            case ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt:
                return value * static_cast<un_scalar_t>(0.001);

            case ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie:
                return value * (static_cast<un_scalar_t>(0.0001) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(4.184);

            case ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu:
                return value * (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600)) / (static_cast<un_scalar_t>(1055.05585262) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ThermalInsulanceUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case ThermalInsulanceUnit::SquareMeterKelvinsPerKilowatt:
                return base_value_;

            case ThermalInsulanceUnit::SquareMeterKelvinsPerWatt:
                return base_value_ / static_cast<un_scalar_t>(1000);

            case ThermalInsulanceUnit::SquareMeterDegreesCelsiusPerWatt:
                return base_value_ / static_cast<un_scalar_t>(1000.0);

            case ThermalInsulanceUnit::SquareCentimeterKelvinsPerWatt:
                return base_value_ / static_cast<un_scalar_t>(0.1);

            case ThermalInsulanceUnit::SquareMillimeterKelvinsPerWatt:
                return base_value_ / static_cast<un_scalar_t>(0.001);

            case ThermalInsulanceUnit::SquareCentimeterHourDegreesCelsiusPerKilocalorie:
                return base_value_ * static_cast<un_scalar_t>(4.184) / (static_cast<un_scalar_t>(0.0001) * static_cast<un_scalar_t>(3600));

            case ThermalInsulanceUnit::HourSquareFeetDegreesFahrenheitPerBtu:
                return base_value_ * (static_cast<un_scalar_t>(1055.05585262) * static_cast<un_scalar_t>(1.8)) / (static_cast<un_scalar_t>(1000) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600));

            }

            throw std::invalid_argument("Unknown ThermalInsulance unit.");
        }

        un_scalar_t value_;
        ThermalInsulanceUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
