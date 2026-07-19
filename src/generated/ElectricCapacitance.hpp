#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricCapacitanceUnit : std::uint8_t
    {
        Farads,
        Picofarads,
        Nanofarads,
        Microfarads,
        Millifarads,
        Kilofarads,
        Megafarads,
    };

    /// <summary>Capacitance is the capacity of a material object or device to store electric charge.</summary>
    class ElectricCapacitance
    {
    public:
        constexpr explicit ElectricCapacitance(
            const un_scalar_t value,
            const ElectricCapacitanceUnit unit = ElectricCapacitanceUnit::Farads)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricCapacitance(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCapacitanceUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator+(const ElectricCapacitance other) const noexcept
        {
            return ElectricCapacitance(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator-(const ElectricCapacitance other) const noexcept
        {
            return ElectricCapacitance(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCapacitance operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCapacitance(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCapacitance other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCapacitance other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCapacitance other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t farads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Farads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_farads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Farads);
        }


        [[nodiscard]] constexpr un_scalar_t picofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Picofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_picofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Picofarads);
        }


        [[nodiscard]] constexpr un_scalar_t nanofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Nanofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_nanofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Nanofarads);
        }


        [[nodiscard]] constexpr un_scalar_t microfarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Microfarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_microfarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Microfarads);
        }


        [[nodiscard]] constexpr un_scalar_t millifarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Millifarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_millifarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Millifarads);
        }


        [[nodiscard]] constexpr un_scalar_t kilofarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Kilofarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_kilofarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Kilofarads);
        }


        [[nodiscard]] constexpr un_scalar_t megafarads() const
        {
            return convert_from_base(ElectricCapacitanceUnit::Megafarads);
        }

        [[nodiscard]] static constexpr ElectricCapacitance from_megafarads(const un_scalar_t value)
        {
            return ElectricCapacitance(value, ElectricCapacitanceUnit::Megafarads);
        }


        [[nodiscard]] static constexpr ElectricCapacitance from_invalid()
        {
            return ElectricCapacitance(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCapacitanceUnit unit)
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return value;

            case ElectricCapacitanceUnit::Picofarads:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricCapacitanceUnit::Nanofarads:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricCapacitanceUnit::Microfarads:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricCapacitanceUnit::Millifarads:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCapacitanceUnit::Kilofarads:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricCapacitanceUnit::Megafarads:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCapacitanceUnit unit) const
        {
            switch (unit)
            {

            case ElectricCapacitanceUnit::Farads:
                return value_;

            case ElectricCapacitanceUnit::Picofarads:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case ElectricCapacitanceUnit::Nanofarads:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricCapacitanceUnit::Microfarads:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricCapacitanceUnit::Millifarads:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricCapacitanceUnit::Kilofarads:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricCapacitanceUnit::Megafarads:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCapacitance unit.");
        }

        un_scalar_t value_;
    };
}
