#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"

namespace unitsnet_cpp
{
    enum class MolalityUnit : std::uint8_t
    {
        MolesPerKilogram,
        MillimolesPerKilogram,
        MolesPerGram,
    };

    /// <summary>Molality is a measure of the amount of solute in a solution relative to a given mass of solvent.</summary>
    class Molality
    {
    public:
        constexpr explicit Molality(
            const un_scalar_t value,
            const MolalityUnit unit = MolalityUnit::MolesPerKilogram)
            : value_(convert_to_base(value, unit))
        {
        }
        
        constexpr explicit Molality(const bool isValid)
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

        [[nodiscard]] constexpr un_scalar_t value(const MolalityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Molality operator+(const Molality other) const noexcept
        {
            return Molality(value_ + other.value_);
        }

        [[nodiscard]] constexpr Molality operator-(const Molality other) const noexcept
        {
            return Molality(value_ - other.value_);
        }

        [[nodiscard]] constexpr Molality operator*(const un_scalar_t scalar) const noexcept
        {
            return Molality(value_ * scalar);
        }

        [[nodiscard]] constexpr Molality operator/(const un_scalar_t scalar) const noexcept
        {
            return Molality(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Molality other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(const Molality other) const noexcept
        {
            return value_ < other.value_;
        }
        
        [[nodiscard]] constexpr bool operator>(const Molality other) const noexcept
        {
            return value_ > other.value_;
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolesPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t millimoles_per_kilogram() const
        {
            return convert_from_base(MolalityUnit::MillimolesPerKilogram);
        }

        [[nodiscard]] static constexpr Molality from_millimoles_per_kilogram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MillimolesPerKilogram);
        }


        [[nodiscard]] constexpr un_scalar_t moles_per_gram() const
        {
            return convert_from_base(MolalityUnit::MolesPerGram);
        }

        [[nodiscard]] static constexpr Molality from_moles_per_gram(const un_scalar_t value)
        {
            return Molality(value, MolalityUnit::MolesPerGram);
        }


        [[nodiscard]] static constexpr Molality from_invalid()
        {
            return Molality(false);
        }
    private:
        bool _isInvalid = false;
    
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolalityUnit unit)
        {
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return value;

            case MolalityUnit::MillimolesPerKilogram:
                return (value * static_cast<un_scalar_t>(1e-3));

            case MolalityUnit::MolesPerGram:
                return value / static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolalityUnit unit) const
        {
            switch (unit)
            {

            case MolalityUnit::MolesPerKilogram:
                return value_;

            case MolalityUnit::MillimolesPerKilogram:
                return (value_) / static_cast<un_scalar_t>(1e-3);

            case MolalityUnit::MolesPerGram:
                return value_ * static_cast<un_scalar_t>(1e-3);

            }

            throw std::invalid_argument("Unknown Molality unit.");
        }

        un_scalar_t value_;
    };
}
