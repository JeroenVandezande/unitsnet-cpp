#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class VolumetricHeatCapacityUnit : std::uint8_t
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
            const un_scalar_t value,
            const VolumetricHeatCapacityUnit unit = VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit VolumetricHeatCapacity(const bool isValid)
        {
            _isInvalid = !isValid;
        }
        
        void SetValueAsInvalid()
        {
            _isInvalid = true;
        }
        
        void SetValueAsValid()
        {
            _isInvalid = false;
        }
        
        [[nodiscard]] bool GetValueIsValid() const
        {
            return _isInvalid;
        }

        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr un_scalar_t value(const VolumetricHeatCapacityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator+(const VolumetricHeatCapacity other) const noexcept
        {
            return VolumetricHeatCapacity(value_ + other.value_);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator-(const VolumetricHeatCapacity other) const noexcept
        {
            return VolumetricHeatCapacity(value_ - other.value_);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator*(const un_scalar_t scalar) const noexcept
        {
            return VolumetricHeatCapacity(value_ * scalar);
        }

        [[nodiscard]] constexpr VolumetricHeatCapacity operator/(const un_scalar_t scalar) const noexcept
        {
            return VolumetricHeatCapacity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const VolumetricHeatCapacity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const VolumetricHeatCapacity other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const VolumetricHeatCapacity other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter_kelvin() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_kelvin(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin);
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_joules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilojoules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t megajoules_per_cubic_meter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_megajoules_per_cubic_meter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t calories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_calories_per_cubic_centimeter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t kilocalories_per_cubic_centimeter_degree_celsius() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_kilocalories_per_cubic_centimeter_degree_celsius(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_cubic_foot_degree_fahrenheit() const
        {
            return convert_from_base(VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit);
        }

        [[nodiscard]] static constexpr VolumetricHeatCapacity from_btus_per_cubic_foot_degree_fahrenheit(const un_scalar_t value)
        {
            return VolumetricHeatCapacity(value, VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit);
        }


        [[nodiscard]] static constexpr VolumetricHeatCapacity from_invalid()
        {
            return VolumetricHeatCapacity(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, VolumetricHeatCapacityUnit unit)
        {
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin:
                return (value * static_cast<un_scalar_t>(1e6));

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius:
                return value;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3));

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e6));

            case VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius:
                return value * static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit:
                return value * (static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.028316846592)) * static_cast<un_scalar_t>(1.8);

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const VolumetricHeatCapacityUnit unit) const
        {
            switch (unit)
            {

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterKelvin:
                return value_;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterKelvin:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterKelvin:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case VolumetricHeatCapacityUnit::JoulesPerCubicMeterDegreeCelsius:
                return value_;

            case VolumetricHeatCapacityUnit::KilojoulesPerCubicMeterDegreeCelsius:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::MegajoulesPerCubicMeterDegreeCelsius:
                return (value_) / static_cast<un_scalar_t>(1e6);

            case VolumetricHeatCapacityUnit::CaloriesPerCubicCentimeterDegreeCelsius:
                return value_ / static_cast<un_scalar_t>(4.184e6);

            case VolumetricHeatCapacityUnit::KilocaloriesPerCubicCentimeterDegreeCelsius:
                return (value_ / static_cast<un_scalar_t>(4.184e6)) / static_cast<un_scalar_t>(1e3);

            case VolumetricHeatCapacityUnit::BtusPerCubicFootDegreeFahrenheit:
                return value_ / ((static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(0.028316846592)) * static_cast<un_scalar_t>(1.8));

            }

            throw std::invalid_argument("Unknown VolumetricHeatCapacity unit.");
        }

        un_scalar_t value_;
    };
}
