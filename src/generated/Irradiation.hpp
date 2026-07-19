#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class IrradiationUnit : std::uint8_t
    {
        JoulesPerSquareMeter,
        KilojoulesPerSquareMeter,
        JoulesPerSquareCentimeter,
        MillijoulesPerSquareCentimeter,
        JoulesPerSquareMillimeter,
        WattHoursPerSquareMeter,
        KilowattHoursPerSquareMeter,
        BtusPerSquareFoot,
        KilobtusPerSquareFoot,
    };

    /// <summary>Irradiation is the process by which an object is exposed to radiation. The exposure can originate from various sources, including natural sources.</summary>
    class Irradiation
    {
    public:
        constexpr explicit Irradiation(
            const un_scalar_t value,
            const IrradiationUnit unit = IrradiationUnit::JoulesPerSquareMeter)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Irradiation(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const IrradiationUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Irradiation operator+(const Irradiation other) const noexcept
        {
            return Irradiation(value_ + other.value_);
        }

        [[nodiscard]] constexpr Irradiation operator-(const Irradiation other) const noexcept
        {
            return Irradiation(value_ - other.value_);
        }

        [[nodiscard]] constexpr Irradiation operator*(const un_scalar_t scalar) const noexcept
        {
            return Irradiation(value_ * scalar);
        }

        [[nodiscard]] constexpr Irradiation operator/(const un_scalar_t scalar) const noexcept
        {
            return Irradiation(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Irradiation other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Irradiation other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Irradiation other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::JoulesPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulesPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilojoules_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::KilojoulesPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_kilojoules_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilojoulesPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_square_centimeter() const
        {
            return convert_from_base(IrradiationUnit::JoulesPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulesPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t millijoules_per_square_centimeter() const
        {
            return convert_from_base(IrradiationUnit::MillijoulesPerSquareCentimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_millijoules_per_square_centimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::MillijoulesPerSquareCentimeter);
        }


        [[nodiscard]] constexpr un_scalar_t joules_per_square_millimeter() const
        {
            return convert_from_base(IrradiationUnit::JoulesPerSquareMillimeter);
        }

        [[nodiscard]] static constexpr Irradiation from_joules_per_square_millimeter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::JoulesPerSquareMillimeter);
        }


        [[nodiscard]] constexpr un_scalar_t watt_hours_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::WattHoursPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_watt_hours_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::WattHoursPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t kilowatt_hours_per_square_meter() const
        {
            return convert_from_base(IrradiationUnit::KilowattHoursPerSquareMeter);
        }

        [[nodiscard]] static constexpr Irradiation from_kilowatt_hours_per_square_meter(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilowattHoursPerSquareMeter);
        }


        [[nodiscard]] constexpr un_scalar_t btus_per_square_foot() const
        {
            return convert_from_base(IrradiationUnit::BtusPerSquareFoot);
        }

        [[nodiscard]] static constexpr Irradiation from_btus_per_square_foot(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::BtusPerSquareFoot);
        }


        [[nodiscard]] constexpr un_scalar_t kilobtus_per_square_foot() const
        {
            return convert_from_base(IrradiationUnit::KilobtusPerSquareFoot);
        }

        [[nodiscard]] static constexpr Irradiation from_kilobtus_per_square_foot(const un_scalar_t value)
        {
            return Irradiation(value, IrradiationUnit::KilobtusPerSquareFoot);
        }


        [[nodiscard]] static constexpr Irradiation from_invalid()
        {
            return Irradiation(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, IrradiationUnit unit)
        {
            switch (unit)
            {

            case IrradiationUnit::JoulesPerSquareMeter:
                return value;

            case IrradiationUnit::KilojoulesPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3));

            case IrradiationUnit::JoulesPerSquareCentimeter:
                return value * static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::MillijoulesPerSquareCentimeter:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::JoulesPerSquareMillimeter:
                return value * static_cast<un_scalar_t>(1e6);

            case IrradiationUnit::WattHoursPerSquareMeter:
                return value * static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::KilowattHoursPerSquareMeter:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::BtusPerSquareFoot:
                return value * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(9.290304e-2);

            case IrradiationUnit::KilobtusPerSquareFoot:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1055.05585262) / static_cast<un_scalar_t>(9.290304e-2);

            }

            throw std::invalid_argument("Unknown Irradiation unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const IrradiationUnit unit) const
        {
            switch (unit)
            {

            case IrradiationUnit::JoulesPerSquareMeter:
                return value_;

            case IrradiationUnit::KilojoulesPerSquareMeter:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case IrradiationUnit::JoulesPerSquareCentimeter:
                return value_ / static_cast<un_scalar_t>(1e4);

            case IrradiationUnit::MillijoulesPerSquareCentimeter:
                return (value_ / static_cast<un_scalar_t>(1e4)) / static_cast<un_scalar_t>(1e-3);

            case IrradiationUnit::JoulesPerSquareMillimeter:
                return value_ / static_cast<un_scalar_t>(1e6);

            case IrradiationUnit::WattHoursPerSquareMeter:
                return value_ / static_cast<un_scalar_t>(3600.0);

            case IrradiationUnit::KilowattHoursPerSquareMeter:
                return (value_ / static_cast<un_scalar_t>(3600.0)) / static_cast<un_scalar_t>(1e3);

            case IrradiationUnit::BtusPerSquareFoot:
                return value_ * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(1055.05585262);

            case IrradiationUnit::KilobtusPerSquareFoot:
                return (value_ * static_cast<un_scalar_t>(9.290304e-2) / static_cast<un_scalar_t>(1055.05585262)) / static_cast<un_scalar_t>(1e3);

            }

            throw std::invalid_argument("Unknown Irradiation unit.");
        }

        un_scalar_t value_;
    };
}
