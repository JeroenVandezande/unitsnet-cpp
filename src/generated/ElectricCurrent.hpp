#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class ElectricCurrentUnit : std::uint8_t
    {
        Amperes,
        Femtoamperes,
        Picoamperes,
        Nanoamperes,
        Microamperes,
        Milliamperes,
        Centiamperes,
        Kiloamperes,
        Megaamperes,
    };

    /// <summary>An electric current is a flow of electric charge. In electric circuits this charge is often carried by moving electrons in a wire. It can also be carried by ions in an electrolyte, or by both ions and electrons such as in a plasma.</summary>
    class ElectricCurrent
    {
    public:
        constexpr explicit ElectricCurrent(
            const un_scalar_t value,
            const ElectricCurrentUnit unit = ElectricCurrentUnit::Amperes)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit ElectricCurrent(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const ElectricCurrentUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr ElectricCurrent operator+(const ElectricCurrent other) const noexcept
        {
            return ElectricCurrent(value_ + other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrent operator-(const ElectricCurrent other) const noexcept
        {
            return ElectricCurrent(value_ - other.value_);
        }

        [[nodiscard]] constexpr ElectricCurrent operator*(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrent(value_ * scalar);
        }

        [[nodiscard]] constexpr ElectricCurrent operator/(const un_scalar_t scalar) const noexcept
        {
            return ElectricCurrent(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const ElectricCurrent other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const ElectricCurrent other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const ElectricCurrent other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t amperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Amperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_amperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Amperes);
        }


        [[nodiscard]] constexpr un_scalar_t femtoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Femtoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_femtoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Femtoamperes);
        }


        [[nodiscard]] constexpr un_scalar_t picoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Picoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_picoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Picoamperes);
        }


        [[nodiscard]] constexpr un_scalar_t nanoamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Nanoamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_nanoamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Nanoamperes);
        }


        [[nodiscard]] constexpr un_scalar_t microamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Microamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_microamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Microamperes);
        }


        [[nodiscard]] constexpr un_scalar_t milliamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Milliamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_milliamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Milliamperes);
        }


        [[nodiscard]] constexpr un_scalar_t centiamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Centiamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_centiamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Centiamperes);
        }


        [[nodiscard]] constexpr un_scalar_t kiloamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Kiloamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_kiloamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Kiloamperes);
        }


        [[nodiscard]] constexpr un_scalar_t megaamperes() const
        {
            return convert_from_base(ElectricCurrentUnit::Megaamperes);
        }

        [[nodiscard]] static constexpr ElectricCurrent from_megaamperes(const un_scalar_t value)
        {
            return ElectricCurrent(value, ElectricCurrentUnit::Megaamperes);
        }


        [[nodiscard]] static constexpr ElectricCurrent from_invalid()
        {
            return ElectricCurrent(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, ElectricCurrentUnit unit)
        {
            switch (unit)
            {

            case ElectricCurrentUnit::Amperes:
                return value;

            case ElectricCurrentUnit::Femtoamperes:
                return (value * static_cast<un_scalar_t>(1e-15));

            case ElectricCurrentUnit::Picoamperes:
                return (value * static_cast<un_scalar_t>(1e-12));

            case ElectricCurrentUnit::Nanoamperes:
                return (value * static_cast<un_scalar_t>(1e-9));

            case ElectricCurrentUnit::Microamperes:
                return (value * static_cast<un_scalar_t>(1e-6));

            case ElectricCurrentUnit::Milliamperes:
                return (value * static_cast<un_scalar_t>(1e-3));

            case ElectricCurrentUnit::Centiamperes:
                return (value * static_cast<un_scalar_t>(1e-2));

            case ElectricCurrentUnit::Kiloamperes:
                return (value * static_cast<un_scalar_t>(1e3));

            case ElectricCurrentUnit::Megaamperes:
                return (value * static_cast<un_scalar_t>(1e6));

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const ElectricCurrentUnit unit) const
        {
            switch (unit)
            {

            case ElectricCurrentUnit::Amperes:
                return value_;

            case ElectricCurrentUnit::Femtoamperes:
                return (value_) / static_cast<un_scalar_t>(1e-15);

            case ElectricCurrentUnit::Picoamperes:
                return (value_) / static_cast<un_scalar_t>(1e-12);

            case ElectricCurrentUnit::Nanoamperes:
                return (value_) / static_cast<un_scalar_t>(1e-9);

            case ElectricCurrentUnit::Microamperes:
                return (value_) / static_cast<un_scalar_t>(1e-6);

            case ElectricCurrentUnit::Milliamperes:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case ElectricCurrentUnit::Centiamperes:
                return (value_) / static_cast<un_scalar_t>(1e-2);

            case ElectricCurrentUnit::Kiloamperes:
                return (value_) / static_cast<un_scalar_t>(1e3);

            case ElectricCurrentUnit::Megaamperes:
                return (value_) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown ElectricCurrent unit.");
        }

        un_scalar_t value_;
    };
}
