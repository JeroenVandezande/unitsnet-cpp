#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class CompressibilityUnit : std::uint16_t
    {
        InversePascals,
        InverseKilopascals,
        InverseMegapascals,
        InverseAtmospheres,
        InverseMillibars,
        InverseBars,
        InversePoundsForcePerSquareInch,
    };

    /// <summary></summary>
    class Compressibility
    {
    public:
        constexpr explicit Compressibility(
            double value,
            CompressibilityUnit unit = CompressibilityUnit::InversePascals)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(CompressibilityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Compressibility operator+(Compressibility other) const noexcept
        {
            return Compressibility(value_ + other.value_);
        }

        [[nodiscard]] constexpr Compressibility operator-(Compressibility other) const noexcept
        {
            return Compressibility(value_ - other.value_);
        }

        [[nodiscard]] constexpr Compressibility operator*(double scalar) const noexcept
        {
            return Compressibility(value_ * scalar);
        }

        [[nodiscard]] constexpr Compressibility operator/(double scalar) const noexcept
        {
            return Compressibility(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Compressibility other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Compressibility other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double inverse_pascals() const
        {
            return convert_from_base(CompressibilityUnit::InversePascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pascals(double value)
        {
            return Compressibility(value, CompressibilityUnit::InversePascals);
        }


        [[nodiscard]] constexpr double inverse_kilopascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseKilopascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_kilopascals(double value)
        {
            return Compressibility(value, CompressibilityUnit::InverseKilopascals);
        }


        [[nodiscard]] constexpr double inverse_megapascals() const
        {
            return convert_from_base(CompressibilityUnit::InverseMegapascals);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_megapascals(double value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMegapascals);
        }


        [[nodiscard]] constexpr double inverse_atmospheres() const
        {
            return convert_from_base(CompressibilityUnit::InverseAtmospheres);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_atmospheres(double value)
        {
            return Compressibility(value, CompressibilityUnit::InverseAtmospheres);
        }


        [[nodiscard]] constexpr double inverse_millibars() const
        {
            return convert_from_base(CompressibilityUnit::InverseMillibars);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_millibars(double value)
        {
            return Compressibility(value, CompressibilityUnit::InverseMillibars);
        }


        [[nodiscard]] constexpr double inverse_bars() const
        {
            return convert_from_base(CompressibilityUnit::InverseBars);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_bars(double value)
        {
            return Compressibility(value, CompressibilityUnit::InverseBars);
        }


        [[nodiscard]] constexpr double inverse_pounds_force_per_square_inch() const
        {
            return convert_from_base(CompressibilityUnit::InversePoundsForcePerSquareInch);
        }

        [[nodiscard]] static constexpr Compressibility from_inverse_pounds_force_per_square_inch(double value)
        {
            return Compressibility(value, CompressibilityUnit::InversePoundsForcePerSquareInch);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, CompressibilityUnit unit)
        {
            switch (unit)
            {

            case CompressibilityUnit::InversePascals:
                return value;

            case CompressibilityUnit::InverseKilopascals:
                return value * 1e3;

            case CompressibilityUnit::InverseMegapascals:
                return value * 1e6;

            case CompressibilityUnit::InverseAtmospheres:
                return value * 101325;

            case CompressibilityUnit::InverseMillibars:
                return value * 100;

            case CompressibilityUnit::InverseBars:
                return value * 1e5;

            case CompressibilityUnit::InversePoundsForcePerSquareInch:
                return value * 6.894757293168361e3;

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(CompressibilityUnit unit) const
        {
            switch (unit)
            {

            case CompressibilityUnit::InversePascals:
                return value_;

            case CompressibilityUnit::InverseKilopascals:
                return value_ / 1e3;

            case CompressibilityUnit::InverseMegapascals:
                return value_ / 1e6;

            case CompressibilityUnit::InverseAtmospheres:
                return value_ / 101325;

            case CompressibilityUnit::InverseMillibars:
                return value_ / 100;

            case CompressibilityUnit::InverseBars:
                return value_ / 1e5;

            case CompressibilityUnit::InversePoundsForcePerSquareInch:
                return value_ / 6.894757293168361e3;

            }

            throw std::invalid_argument("Unknown Compressibility unit.");
        }

        double value_;
    };
}
