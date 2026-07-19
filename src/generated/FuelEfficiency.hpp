#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class FuelEfficiencyUnit : std::uint8_t
    {
        LitersPer100Kilometers,
        MilesPerUsGallon,
        MilesPerUkGallon,
        KilometersPerLiter,
    };

    /// <summary>In the context of transport, fuel economy is the energy efficiency of a particular vehicle, given as a ratio of distance traveled per unit of fuel consumed. In most countries, using the metric system, fuel economy is stated as "fuel consumption" in liters per 100 kilometers (L/100 km) or kilometers per liter (km/L or kmpl). In countries using non-metric system, fuel economy is expressed in miles per gallon (mpg) (imperial galon or US galon).</summary>
    class FuelEfficiency : public UnitsNetBase
    {
    public:
        constexpr explicit FuelEfficiency(
            const un_scalar_t value,
            const FuelEfficiencyUnit unit = FuelEfficiencyUnit::KilometersPerLiter)
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
           return "FuelEfficiency"; 
        }
        
        [[nodiscard]] constexpr std::string_view unit_name() const noexcept override
        {
            switch (value_unit_type_)
            {

            case FuelEfficiencyUnit::LitersPer100Kilometers:
                return "LitersPer100Kilometers";

            case FuelEfficiencyUnit::MilesPerUsGallon:
                return "MilesPerUsGallon";

            case FuelEfficiencyUnit::MilesPerUkGallon:
                return "MilesPerUkGallon";

            case FuelEfficiencyUnit::KilometersPerLiter:
                return "KilometersPerLiter";

            }
            
            return {};
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return convert_to_base(value_, value_unit_type_);    
        }

        [[nodiscard]] constexpr un_scalar_t value(const FuelEfficiencyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr FuelEfficiency operator+(const FuelEfficiency& other) const noexcept
        {
            return FuelEfficiency(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr FuelEfficiency operator-(const FuelEfficiency& other)const noexcept
        {
            return FuelEfficiency(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr FuelEfficiency operator*(const un_scalar_t scalar) const noexcept
        {
            return FuelEfficiency(base_value() * scalar);
        }

        [[nodiscard]] constexpr FuelEfficiency operator/(const un_scalar_t scalar) const noexcept
        {
            return FuelEfficiency(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const FuelEfficiency& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const FuelEfficiency& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const FuelEfficiency& other) const noexcept
        {
            return base_value() > other.base_value();
        }

        [[nodiscard]] constexpr un_scalar_t liters_per100_kilometers() const
        {
            return convert_from_base(FuelEfficiencyUnit::LitersPer100Kilometers);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_liters_per100_kilometers(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::LitersPer100Kilometers);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_us_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilesPerUsGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_us_gallon(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilesPerUsGallon);
        }

        [[nodiscard]] constexpr un_scalar_t miles_per_uk_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilesPerUkGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_uk_gallon(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilesPerUkGallon);
        }

        [[nodiscard]] constexpr un_scalar_t kilometers_per_liter() const
        {
            return convert_from_base(FuelEfficiencyUnit::KilometersPerLiter);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_kilometers_per_liter(const un_scalar_t value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::KilometersPerLiter);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_invalid()
        {
            return FuelEfficiency(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, FuelEfficiencyUnit unit)
        {
            switch (unit)
            {

            case FuelEfficiencyUnit::LitersPer100Kilometers:
                return static_cast<un_scalar_t>(100) / value;

            case FuelEfficiencyUnit::MilesPerUsGallon:
                return value * static_cast<un_scalar_t>(1.609344) / static_cast<un_scalar_t>(3.785411784);

            case FuelEfficiencyUnit::MilesPerUkGallon:
                return value * static_cast<un_scalar_t>(1.609344) / static_cast<un_scalar_t>(4.54609);

            case FuelEfficiencyUnit::KilometersPerLiter:
                return value;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const FuelEfficiencyUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            auto base_value = convert_to_base(value_, value_unit_type_);
            
            switch (unit)
            {

            case FuelEfficiencyUnit::LitersPer100Kilometers:
                return static_cast<un_scalar_t>(100) / base_value;

            case FuelEfficiencyUnit::MilesPerUsGallon:
                return base_value * static_cast<un_scalar_t>(3.785411784) / static_cast<un_scalar_t>(1.609344);

            case FuelEfficiencyUnit::MilesPerUkGallon:
                return base_value * static_cast<un_scalar_t>(4.54609) / static_cast<un_scalar_t>(1.609344);

            case FuelEfficiencyUnit::KilometersPerLiter:
                return base_value;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        un_scalar_t value_;
        FuelEfficiencyUnit value_unit_type_;       
    };
}
