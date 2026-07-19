#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class HeatTransferCoefficientUnit : std::uint8_t
    {
        WattsPerSquareMeterKelvin,
        WattsPerSquareMeterCelsius,
        BtusPerHourSquareFootDegreeFahrenheit,
        BtusPerSecondSquareInchDegreeFahrenheit,
        CaloriesPerHourSquareMeterDegreeCelsius,
        KilocaloriesPerHourSquareMeterDegreeCelsius,
    };

    /// <summary>The heat transfer coefficient or film coefficient, or film effectiveness, in thermodynamics and in mechanics is the proportionality constant between the heat flux and the thermodynamic driving force for the flow of heat (i.e., the temperature difference, ΔT)</summary>
    class HeatTransferCoefficient : public UnitsNetBase
    {
    public:
        constexpr explicit HeatTransferCoefficient(
            const un_scalar_t value,
            const HeatTransferCoefficientUnit unit = HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin)
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
            if(base_value_exists_)
            {
                return;
            }
            else
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
                return;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const HeatTransferCoefficientUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator+(const HeatTransferCoefficient& other) const noexcept
        {
            return HeatTransferCoefficient(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator-(const HeatTransferCoefficient& other)const noexcept
        {
            return HeatTransferCoefficient(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator*(const un_scalar_t scalar) const noexcept
        {
            return HeatTransferCoefficient(base_value() * scalar);
        }

        [[nodiscard]] constexpr HeatTransferCoefficient operator/(const un_scalar_t scalar) const noexcept
        {
            return HeatTransferCoefficient(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const HeatTransferCoefficient& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter_kelvin() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_kelvin(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t watts_per_square_meter_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_watts_per_square_meter_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_hour_square_foot_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_hour_square_foot_degree_fahrenheit(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_second_square_inch_degree_fahrenheit() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_btus_per_second_square_inch_degree_fahrenheit(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit);
        }


        [[nodiscard]] constexpr un_scalar_t calories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_calories_per_hour_square_meter_degree_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories_per_hour_square_meter_degree_celsius() const
        {
            return convert_from_base(HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr HeatTransferCoefficient from_kilocalories_per_hour_square_meter_degree_celsius(const un_scalar_t value)
        {
            return HeatTransferCoefficient(value, HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius);
        }


        [[nodiscard]] static constexpr HeatTransferCoefficient from_invalid()
        {
            return HeatTransferCoefficient(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, HeatTransferCoefficientUnit unit)
        {
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin:
                return value;

            case HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius:
                return value;

            case HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit:
                return value * ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(3600);

            case HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius:
                return ((value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184)) / static_cast<un_scalar_t>(3600);

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const HeatTransferCoefficientUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case HeatTransferCoefficientUnit::WattsPerSquareMeterKelvin:
                return base_value_;

            case HeatTransferCoefficientUnit::WattsPerSquareMeterCelsius:
                return base_value_;

            case HeatTransferCoefficientUnit::BtusPerHourSquareFootDegreeFahrenheit:
                return base_value_ / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(0.3048) * static_cast<un_scalar_t>(3600))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::BtusPerSecondSquareInchDegreeFahrenheit:
                return base_value_ / ((static_cast<un_scalar_t>(1055.05585262) / (static_cast<un_scalar_t>(2.54e-2) * static_cast<un_scalar_t>(2.54e-2))) * static_cast<un_scalar_t>(1.8));

            case HeatTransferCoefficientUnit::CaloriesPerHourSquareMeterDegreeCelsius:
                return (base_value_ / static_cast<un_scalar_t>(4.184)) * static_cast<un_scalar_t>(3600);

            case HeatTransferCoefficientUnit::KilocaloriesPerHourSquareMeterDegreeCelsius:
                return ((base_value_ / static_cast<un_scalar_t>(4.184)) * static_cast<un_scalar_t>(3600)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown HeatTransferCoefficient unit.");
        }

        un_scalar_t value_;
        HeatTransferCoefficientUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
