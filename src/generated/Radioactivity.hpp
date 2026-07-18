#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>

namespace unitsnet_cpp
{
    enum class RadioactivityUnit : std::uint16_t
    {
        Becquerels,
        Picobecquerels,
        Nanobecquerels,
        Microbecquerels,
        Millibecquerels,
        Kilobecquerels,
        Megabecquerels,
        Gigabecquerels,
        Terabecquerels,
        Petabecquerels,
        Exabecquerels,
        Curies,
        Picocuries,
        Nanocuries,
        Microcuries,
        Millicuries,
        Kilocuries,
        Megacuries,
        Gigacuries,
        Teracuries,
        Rutherfords,
        Picorutherfords,
        Nanorutherfords,
        Microrutherfords,
        Millirutherfords,
        Kilorutherfords,
        Megarutherfords,
        Gigarutherfords,
        Terarutherfords,
    };

    /// <summary>Amount of ionizing radiation released when an element spontaneously emits energy as a result of the radioactive decay of an unstable atom per unit time.</summary>
    class Radioactivity
    {
    public:
        constexpr explicit Radioactivity(
            double value,
            RadioactivityUnit unit = RadioactivityUnit::Becquerels)
            : value_(convert_to_base(value, unit))
        {
        }

        [[nodiscard]] constexpr double base_value() const noexcept
        {
            return value_;
        }

        [[nodiscard]] constexpr double value(RadioactivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Radioactivity operator+(Radioactivity other) const noexcept
        {
            return Radioactivity(value_ + other.value_);
        }

        [[nodiscard]] constexpr Radioactivity operator-(Radioactivity other) const noexcept
        {
            return Radioactivity(value_ - other.value_);
        }

        [[nodiscard]] constexpr Radioactivity operator*(double scalar) const noexcept
        {
            return Radioactivity(value_ * scalar);
        }

        [[nodiscard]] constexpr Radioactivity operator/(double scalar) const noexcept
        {
            return Radioactivity(value_ / scalar);
        }

        [[nodiscard]] constexpr bool operator==(Radioactivity other) const noexcept
        {
            return value_ == other.value_;
        }

        [[nodiscard]] constexpr bool operator<(Radioactivity other) const noexcept
        {
            return value_ < other.value_;
        }


        [[nodiscard]] constexpr double becquerels() const
        {
            return convert_from_base(RadioactivityUnit::Becquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_becquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Becquerels);
        }


        [[nodiscard]] constexpr double picobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Picobecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_picobecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Picobecquerels);
        }


        [[nodiscard]] constexpr double nanobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Nanobecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_nanobecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanobecquerels);
        }


        [[nodiscard]] constexpr double microbecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Microbecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_microbecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Microbecquerels);
        }


        [[nodiscard]] constexpr double millibecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Millibecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_millibecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Millibecquerels);
        }


        [[nodiscard]] constexpr double kilobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Kilobecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_kilobecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilobecquerels);
        }


        [[nodiscard]] constexpr double megabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Megabecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_megabecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Megabecquerels);
        }


        [[nodiscard]] constexpr double gigabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Gigabecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_gigabecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigabecquerels);
        }


        [[nodiscard]] constexpr double terabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Terabecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_terabecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Terabecquerels);
        }


        [[nodiscard]] constexpr double petabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Petabecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_petabecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Petabecquerels);
        }


        [[nodiscard]] constexpr double exabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Exabecquerels);
        }

        [[nodiscard]] static constexpr Radioactivity from_exabecquerels(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Exabecquerels);
        }


        [[nodiscard]] constexpr double curies() const
        {
            return convert_from_base(RadioactivityUnit::Curies);
        }

        [[nodiscard]] static constexpr Radioactivity from_curies(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Curies);
        }


        [[nodiscard]] constexpr double picocuries() const
        {
            return convert_from_base(RadioactivityUnit::Picocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_picocuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Picocuries);
        }


        [[nodiscard]] constexpr double nanocuries() const
        {
            return convert_from_base(RadioactivityUnit::Nanocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_nanocuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanocuries);
        }


        [[nodiscard]] constexpr double microcuries() const
        {
            return convert_from_base(RadioactivityUnit::Microcuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_microcuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Microcuries);
        }


        [[nodiscard]] constexpr double millicuries() const
        {
            return convert_from_base(RadioactivityUnit::Millicuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_millicuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Millicuries);
        }


        [[nodiscard]] constexpr double kilocuries() const
        {
            return convert_from_base(RadioactivityUnit::Kilocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_kilocuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilocuries);
        }


        [[nodiscard]] constexpr double megacuries() const
        {
            return convert_from_base(RadioactivityUnit::Megacuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_megacuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Megacuries);
        }


        [[nodiscard]] constexpr double gigacuries() const
        {
            return convert_from_base(RadioactivityUnit::Gigacuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_gigacuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigacuries);
        }


        [[nodiscard]] constexpr double teracuries() const
        {
            return convert_from_base(RadioactivityUnit::Teracuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_teracuries(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Teracuries);
        }


        [[nodiscard]] constexpr double rutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Rutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_rutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Rutherfords);
        }


        [[nodiscard]] constexpr double picorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Picorutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_picorutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Picorutherfords);
        }


        [[nodiscard]] constexpr double nanorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Nanorutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_nanorutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanorutherfords);
        }


        [[nodiscard]] constexpr double microrutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Microrutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_microrutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Microrutherfords);
        }


        [[nodiscard]] constexpr double millirutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Millirutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_millirutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Millirutherfords);
        }


        [[nodiscard]] constexpr double kilorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Kilorutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_kilorutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilorutherfords);
        }


        [[nodiscard]] constexpr double megarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Megarutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_megarutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Megarutherfords);
        }


        [[nodiscard]] constexpr double gigarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Gigarutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_gigarutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigarutherfords);
        }


        [[nodiscard]] constexpr double terarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Terarutherfords);
        }

        [[nodiscard]] static constexpr Radioactivity from_terarutherfords(double value)
        {
            return Radioactivity(value, RadioactivityUnit::Terarutherfords);
        }


    private:
        [[nodiscard]] static constexpr double convert_to_base(double value, RadioactivityUnit unit)
        {
            switch (unit)
            {

            case RadioactivityUnit::Becquerels:
                return value;

            case RadioactivityUnit::Picobecquerels:
                return (value * 1e-12);

            case RadioactivityUnit::Nanobecquerels:
                return (value * 1e-9);

            case RadioactivityUnit::Microbecquerels:
                return (value * 1e-6);

            case RadioactivityUnit::Millibecquerels:
                return (value * 1e-3);

            case RadioactivityUnit::Kilobecquerels:
                return (value * 1e3);

            case RadioactivityUnit::Megabecquerels:
                return (value * 1e6);

            case RadioactivityUnit::Gigabecquerels:
                return (value * 1e9);

            case RadioactivityUnit::Terabecquerels:
                return (value * 1e12);

            case RadioactivityUnit::Petabecquerels:
                return (value * 1e15);

            case RadioactivityUnit::Exabecquerels:
                return (value * 1e18);

            case RadioactivityUnit::Curies:
                return value * 3.7e10;

            case RadioactivityUnit::Picocuries:
                return (value * 1e-12) * 3.7e10;

            case RadioactivityUnit::Nanocuries:
                return (value * 1e-9) * 3.7e10;

            case RadioactivityUnit::Microcuries:
                return (value * 1e-6) * 3.7e10;

            case RadioactivityUnit::Millicuries:
                return (value * 1e-3) * 3.7e10;

            case RadioactivityUnit::Kilocuries:
                return (value * 1e3) * 3.7e10;

            case RadioactivityUnit::Megacuries:
                return (value * 1e6) * 3.7e10;

            case RadioactivityUnit::Gigacuries:
                return (value * 1e9) * 3.7e10;

            case RadioactivityUnit::Teracuries:
                return (value * 1e12) * 3.7e10;

            case RadioactivityUnit::Rutherfords:
                return value * 1e6;

            case RadioactivityUnit::Picorutherfords:
                return (value * 1e-12) * 1e6;

            case RadioactivityUnit::Nanorutherfords:
                return (value * 1e-9) * 1e6;

            case RadioactivityUnit::Microrutherfords:
                return (value * 1e-6) * 1e6;

            case RadioactivityUnit::Millirutherfords:
                return (value * 1e-3) * 1e6;

            case RadioactivityUnit::Kilorutherfords:
                return (value * 1e3) * 1e6;

            case RadioactivityUnit::Megarutherfords:
                return (value * 1e6) * 1e6;

            case RadioactivityUnit::Gigarutherfords:
                return (value * 1e9) * 1e6;

            case RadioactivityUnit::Terarutherfords:
                return (value * 1e12) * 1e6;

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        [[nodiscard]] constexpr double convert_from_base(RadioactivityUnit unit) const
        {
            switch (unit)
            {

            case RadioactivityUnit::Becquerels:
                return value_;

            case RadioactivityUnit::Picobecquerels:
                return (value_) / 1e-12;

            case RadioactivityUnit::Nanobecquerels:
                return (value_) / 1e-9;

            case RadioactivityUnit::Microbecquerels:
                return (value_) / 1e-6;

            case RadioactivityUnit::Millibecquerels:
                return (value_) / 1e-3;

            case RadioactivityUnit::Kilobecquerels:
                return (value_) / 1e3;

            case RadioactivityUnit::Megabecquerels:
                return (value_) / 1e6;

            case RadioactivityUnit::Gigabecquerels:
                return (value_) / 1e9;

            case RadioactivityUnit::Terabecquerels:
                return (value_) / 1e12;

            case RadioactivityUnit::Petabecquerels:
                return (value_) / 1e15;

            case RadioactivityUnit::Exabecquerels:
                return (value_) / 1e18;

            case RadioactivityUnit::Curies:
                return value_ / 3.7e10;

            case RadioactivityUnit::Picocuries:
                return (value_ / 3.7e10) / 1e-12;

            case RadioactivityUnit::Nanocuries:
                return (value_ / 3.7e10) / 1e-9;

            case RadioactivityUnit::Microcuries:
                return (value_ / 3.7e10) / 1e-6;

            case RadioactivityUnit::Millicuries:
                return (value_ / 3.7e10) / 1e-3;

            case RadioactivityUnit::Kilocuries:
                return (value_ / 3.7e10) / 1e3;

            case RadioactivityUnit::Megacuries:
                return (value_ / 3.7e10) / 1e6;

            case RadioactivityUnit::Gigacuries:
                return (value_ / 3.7e10) / 1e9;

            case RadioactivityUnit::Teracuries:
                return (value_ / 3.7e10) / 1e12;

            case RadioactivityUnit::Rutherfords:
                return value_ / 1e6;

            case RadioactivityUnit::Picorutherfords:
                return (value_ / 1e6) / 1e-12;

            case RadioactivityUnit::Nanorutherfords:
                return (value_ / 1e6) / 1e-9;

            case RadioactivityUnit::Microrutherfords:
                return (value_ / 1e6) / 1e-6;

            case RadioactivityUnit::Millirutherfords:
                return (value_ / 1e6) / 1e-3;

            case RadioactivityUnit::Kilorutherfords:
                return (value_ / 1e6) / 1e3;

            case RadioactivityUnit::Megarutherfords:
                return (value_ / 1e6) / 1e6;

            case RadioactivityUnit::Gigarutherfords:
                return (value_ / 1e6) / 1e9;

            case RadioactivityUnit::Terarutherfords:
                return (value_ / 1e6) / 1e12;

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        double value_;
    };
}
