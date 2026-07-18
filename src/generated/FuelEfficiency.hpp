#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class FuelEfficiencyUnit : std::uint16_t
    {
        LitersPer100Kilometers,
        MilesPerUsGallon,
        MilesPerUkGallon,
        KilometersPerLiter,
    };

    /// <summary>In the context of transport, fuel economy is the energy efficiency of a particular vehicle, given as a ratio of distance traveled per unit of fuel consumed. In most countries, using the metric system, fuel economy is stated as "fuel consumption" in liters per 100 kilometers (L/100 km) or kilometers per liter (km/L or kmpl). In countries using non-metric system, fuel economy is expressed in miles per gallon (mpg) (imperial galon or US galon).</summary>
    class FuelEfficiency
    {
    public:
        constexpr explicit FuelEfficiency(
            double value,
            FuelEfficiencyUnit unit = FuelEfficiencyUnit::KilometersPerLiter)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(FuelEfficiencyUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr FuelEfficiency operator+(FuelEfficiency other) const noexcept
        {
            return FuelEfficiency(value_ + other.value_);
        }

        [[nodiscard]] constexpr FuelEfficiency operator-(FuelEfficiency other) const noexcept
        {
            return FuelEfficiency(value_ - other.value_);
        }

        [[nodiscard]] constexpr FuelEfficiency operator*(double scalar) const noexcept
        {
            return FuelEfficiency(value_ * scalar);
        }

        [[nodiscard]] constexpr FuelEfficiency operator/(double scalar) const noexcept
        {
            return FuelEfficiency(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(FuelEfficiency other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(FuelEfficiency other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double liters_per100_kilometers() const
        {
            return convert_from_base(FuelEfficiencyUnit::LitersPer100Kilometers);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_liters_per100_kilometers(double value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::LitersPer100Kilometers);
        }


        [[nodiscard]] constexpr double miles_per_us_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilesPerUsGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_us_gallon(double value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilesPerUsGallon);
        }


        [[nodiscard]] constexpr double miles_per_uk_gallon() const
        {
            return convert_from_base(FuelEfficiencyUnit::MilesPerUkGallon);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_miles_per_uk_gallon(double value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::MilesPerUkGallon);
        }


        [[nodiscard]] constexpr double kilometers_per_liter() const
        {
            return convert_from_base(FuelEfficiencyUnit::KilometersPerLiter);
        }

        [[nodiscard]] static constexpr FuelEfficiency from_kilometers_per_liter(double value)
        {
            return FuelEfficiency(value, FuelEfficiencyUnit::KilometersPerLiter);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, FuelEfficiencyUnit unit)
        {
            switch (unit)
            {

            case FuelEfficiencyUnit::LitersPer100Kilometers:
                return 100 / value;

            case FuelEfficiencyUnit::MilesPerUsGallon:
                return value * 1.609344 / 3.785411784;

            case FuelEfficiencyUnit::MilesPerUkGallon:
                return value * 1.609344 / 4.54609;

            case FuelEfficiencyUnit::KilometersPerLiter:
                return value;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(FuelEfficiencyUnit unit) const
        {
            switch (unit)
            {

            case FuelEfficiencyUnit::LitersPer100Kilometers:
                return 100 / value_;

            case FuelEfficiencyUnit::MilesPerUsGallon:
                return value_ * 3.785411784 / 1.609344;

            case FuelEfficiencyUnit::MilesPerUkGallon:
                return value_ * 4.54609 / 1.609344;

            case FuelEfficiencyUnit::KilometersPerLiter:
                return value_;

            }

            throw std::invalid_argument("Unknown FuelEfficiency unit.");
        }

        double value_;
    };
}
