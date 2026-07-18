#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class VolumetricHeatCapacityUnit : std::uint16_t
    {
        JoulesPerCubicMeterKelvin,
        KilojoulesPerCubicMeterKelvin,
        MegajoulesPerCubicMeterKelvin,
        JoulesPerCubicMeterDegreeCelsius,
        KilojoulesPerCubicMeterDegreeCelsius,
        MegajoulesPerCubicMeterDegreeCelsius,
        CaloriesPerCubicCentimeterDegreeCelsius,
        KilocaloriesPerCubicCentimeterDegreeCelsius,
        BtusPerCubicFootDegreeFahrenheit,
    };

    /// <summary>The volumetric heat capacity is the amount of energy that must be added, in the form of heat, to one unit of volume of the material in order to cause an increase of one unit in its temperature.</summary>
    class VolumetricHeatCapacity
    {
    public:
        constexpr explicit VolumetricHeatCapacity(
            double value,
            VolumetricHeatCapacityUnit unit = VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(VolumetricHeatCapacityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator+(VolumetricHeatCapacity other) const noexcept
        {
            return VolumetricHeatCapacity(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator-(VolumetricHeatCapacity other) const noexcept
        {
            return VolumetricHeatCapacity(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator*(double scalar) const noexcept
        {
            return VolumetricHeatCapacity(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator/(double scalar) const noexcept
        {
            return VolumetricHeatCapacity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(VolumetricHeatCapacity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(VolumetricHeatCapacity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double joules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_kelvin(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr double kilojoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_kelvin(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr double megajoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_kelvin(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr double joules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_degree_celsius(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double kilojoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_degree_celsius(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double megajoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_degree_celsius(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double calories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_calories_per_cubic_centimeter_degree_celsius(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double kilocalories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilocalories_per_cubic_centimeter_degree_celsius(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius);
        }


        [[nodiscard]] constexpr double btus_per_cubic_foot_degree_fahrenheit() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_btus_per_cubic_foot_degree_fahrenheit(double value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, VolumetricHeatCapacityUnit unit)
        {
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin:
                return (value * 1e3);

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin:
                return (value * 1e6);

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius:
                return (value * 1e3);

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius:
                return (value * 1e6);

            case VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius:
                return value * 4.184e6;

            case VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius:
                return (value * 1e3) * 4.184e6;

            case VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit:
                return value * (1055.05585262 / 0.028316846592) * 1.8;

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(VolumetricHeatCapacityUnit unit) const
        {
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin:
                return value_;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin:
                return (value_) / 1e3;

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin:
                return (value_) / 1e6;

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius:
                return value_;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius:
                return (value_) / 1e3;

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius:
                return (value_) / 1e6;

            case VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius:
                return value_ / 4.184e6;

            case VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius:
                return (value_ / 4.184e6) / 1e3;

            case VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit:
                return value_ / ((1055.05585262 / 0.028316846592) * 1.8);

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        double value_;
    };
}
