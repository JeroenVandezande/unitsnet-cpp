#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class MolarMassUnit : std::uint8_t
    {
        GramsPerMole,
        NanogramsPerMole,
        MicrogramsPerMole,
        MilligramsPerMole,
        CentigramsPerMole,
        DecigramsPerMole,
        DecagramsPerMole,
        HectogramsPerMole,
        KilogramsPerMole,
        KilogramsPerKilomole,
        PoundsPerMole,
        KilopoundsPerMole,
        MegapoundsPerMole,
    };

    /// <summary>In chemistry, the molar mass M is a physical property defined as the mass of a given substance (chemical element or chemical compound) divided by the amount of substance.</summary>
    class MolarMass : public UnitsNetBase
    {
    public:
        constexpr explicit MolarMass(
            const un_scalar_t value,
            const MolarMassUnit unit = MolarMassUnit::KilogramsPerMole)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == MolarMassUnit::KilogramsPerMole)
            {
                base_value_ = value;
                base_value_exists_ = true;
            }
            else
            {
                base_value_ = 0;
                base_value_exists_ = false;
            }
        }
        
        constexpr void create_base_value_if_needed() const noexcept
        {
            if(!base_value_exists_)
            {
                base_value_ = convert_to_base(value_, value_unit_type_);
                base_value_exists_ = true;
            }
        }
                
        [[nodiscard]] constexpr un_scalar_t base_value() const noexcept
        {
            create_base_value_if_needed();    
            return base_value_;    
        }

        [[nodiscard]] constexpr un_scalar_t value(const MolarMassUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr MolarMass operator+(const MolarMass& other) const noexcept
        {
            return MolarMass(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr MolarMass operator-(const MolarMass& other)const noexcept
        {
            return MolarMass(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr MolarMass operator*(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(base_value() * scalar);
        }

        [[nodiscard]] constexpr MolarMass operator/(const un_scalar_t scalar) const noexcept
        {
            return MolarMass(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const MolarMass& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const MolarMass& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const MolarMass& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        [[nodiscard]] constexpr un_scalar_t grams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::GramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_grams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::GramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t nanograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::NanogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_nanograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::NanogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t micrograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MicrogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_micrograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MicrogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t milligrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MilligramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_milligrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MilligramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t centigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::CentigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_centigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::CentigramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t decigrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecigramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decigrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecigramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t decagrams_per_mole() const
        {
            return convert_from_base(MolarMassUnit::DecagramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_decagrams_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::DecagramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t hectograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::HectogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_hectograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::HectogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilograms_per_kilomole() const
        {
            return convert_from_base(MolarMassUnit::KilogramsPerKilomole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilograms_per_kilomole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilogramsPerKilomole);
        }


        [[nodiscard]] constexpr un_scalar_t pounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::PoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_pounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::PoundsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t kilopounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::KilopoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_kilopounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::KilopoundsPerMole);
        }


        [[nodiscard]] constexpr un_scalar_t megapounds_per_mole() const
        {
            return convert_from_base(MolarMassUnit::MegapoundsPerMole);
        }

        [[nodiscard]] static constexpr MolarMass from_megapounds_per_mole(const un_scalar_t value)
        {
            return MolarMass(value, MolarMassUnit::MegapoundsPerMole);
        }


        [[nodiscard]] static constexpr MolarMass from_invalid()
        {
            return MolarMass(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, MolarMassUnit unit)
        {
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return value / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::NanogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-9)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MicrogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-6)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MilligramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::CentigramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-2)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::DecigramsPerMole:
                return (value * static_cast<un_scalar_t>(1e-1)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::DecagramsPerMole:
                return (value * static_cast<un_scalar_t>(1e1)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::HectogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e2)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramsPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramsPerKilomole:
                return value / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::PoundsPerMole:
                return value * static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::KilopoundsPerMole:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::MegapoundsPerMole:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(0.45359237);

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const MolarMassUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case MolarMassUnit::GramsPerMole:
                return base_value_ * static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::NanogramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-9);

            case MolarMassUnit::MicrogramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-6);

            case MolarMassUnit::MilligramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-3);

            case MolarMassUnit::CentigramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-2);

            case MolarMassUnit::DecigramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e-1);

            case MolarMassUnit::DecagramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e1);

            case MolarMassUnit::HectogramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e2);

            case MolarMassUnit::KilogramsPerMole:
                return (base_value_ * static_cast<un_scalar_t>(1e3)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::KilogramsPerKilomole:
                return base_value_ * static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::PoundsPerMole:
                return base_value_ / static_cast<un_scalar_t>(0.45359237);

            case MolarMassUnit::KilopoundsPerMole:
                return (base_value_ / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e3);

            case MolarMassUnit::MegapoundsPerMole:
                return (base_value_ / static_cast<un_scalar_t>(0.45359237)) / static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown MolarMass unit.");
        }

        un_scalar_t value_;
        MolarMassUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
