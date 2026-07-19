#pragma once

#include <cstdint>
#include <numbers>
#include <stdexcept>
#include "UnitsNetConfig.h"
#include "UnitsNetBase.h"

namespace unitsnet_cpp
{
    enum class RadioactivityUnit : std::uint8_t
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
    class Radioactivity : public UnitsNetBase
    {
    public:
        constexpr explicit Radioactivity(
            const un_scalar_t value,
            const RadioactivityUnit unit = RadioactivityUnit::Becquerels)
        {
            value_ = value;
            value_unit_type_ = unit;
            if(unit == RadioactivityUnit::Becquerels)
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

        [[nodiscard]] constexpr un_scalar_t value(const RadioactivityUnit unit) const
        {
            return convert_from_base(unit);
        }

        [[nodiscard]] constexpr Radioactivity operator+(const Radioactivity& other) const noexcept
        {
            return Radioactivity(base_value() + other.base_value());
        }

        [[nodiscard]] constexpr Radioactivity operator-(const Radioactivity& other)const noexcept
        {
            return Radioactivity(base_value() - other.base_value());
        }

        [[nodiscard]] constexpr Radioactivity operator*(const un_scalar_t scalar) const noexcept
        {
            return Radioactivity(base_value() * scalar);
        }

        [[nodiscard]] constexpr Radioactivity operator/(const un_scalar_t scalar) const noexcept
        {
            return Radioactivity(base_value() / scalar);
        }

        [[nodiscard]] constexpr bool operator==(const Radioactivity& other) const noexcept
        {
            return base_value() == other.base_value();
        }

        [[nodiscard]] constexpr bool operator<(const Radioactivity& other) const noexcept
        {
            return base_value() < other.base_value();
        }
        
        [[nodiscard]] constexpr bool operator>(const Radioactivity& other) const noexcept
        {
            return base_value() > other.base_value();
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t becquerels() const
        {
            return convert_from_base(RadioactivityUnit::Becquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_becquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Becquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t picobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Picobecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_picobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picobecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t nanobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Nanobecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_nanobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanobecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t microbecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Microbecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_microbecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microbecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millibecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Millibecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_millibecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millibecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilobecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Kilobecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_kilobecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilobecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t megabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Megabecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_megabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megabecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t gigabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Gigabecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_gigabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigabecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t terabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Terabecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_terabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Terabecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t petabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Petabecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_petabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Petabecquerels);
        }


        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] constexpr un_scalar_t exabecquerels() const
        {
            return convert_from_base(RadioactivityUnit::Exabecquerels);
        }

        /// <summary>Activity of a quantity of radioactive material in which one nucleus decays per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_exabecquerels(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Exabecquerels);
        }


        [[nodiscard]] constexpr un_scalar_t curies() const
        {
            return convert_from_base(RadioactivityUnit::Curies);
        }

        [[nodiscard]] static constexpr Radioactivity from_curies(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Curies);
        }


        [[nodiscard]] constexpr un_scalar_t picocuries() const
        {
            return convert_from_base(RadioactivityUnit::Picocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_picocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picocuries);
        }


        [[nodiscard]] constexpr un_scalar_t nanocuries() const
        {
            return convert_from_base(RadioactivityUnit::Nanocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_nanocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanocuries);
        }


        [[nodiscard]] constexpr un_scalar_t microcuries() const
        {
            return convert_from_base(RadioactivityUnit::Microcuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_microcuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microcuries);
        }


        [[nodiscard]] constexpr un_scalar_t millicuries() const
        {
            return convert_from_base(RadioactivityUnit::Millicuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_millicuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millicuries);
        }


        [[nodiscard]] constexpr un_scalar_t kilocuries() const
        {
            return convert_from_base(RadioactivityUnit::Kilocuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_kilocuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilocuries);
        }


        [[nodiscard]] constexpr un_scalar_t megacuries() const
        {
            return convert_from_base(RadioactivityUnit::Megacuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_megacuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megacuries);
        }


        [[nodiscard]] constexpr un_scalar_t gigacuries() const
        {
            return convert_from_base(RadioactivityUnit::Gigacuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_gigacuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigacuries);
        }


        [[nodiscard]] constexpr un_scalar_t teracuries() const
        {
            return convert_from_base(RadioactivityUnit::Teracuries);
        }

        [[nodiscard]] static constexpr Radioactivity from_teracuries(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Teracuries);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t rutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Rutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_rutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Rutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t picorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Picorutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_picorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Picorutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t nanorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Nanorutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_nanorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Nanorutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t microrutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Microrutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_microrutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Microrutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t millirutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Millirutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_millirutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Millirutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t kilorutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Kilorutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_kilorutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Kilorutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t megarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Megarutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_megarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Megarutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t gigarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Gigarutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_gigarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Gigarutherfords);
        }


        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] constexpr un_scalar_t terarutherfords() const
        {
            return convert_from_base(RadioactivityUnit::Terarutherfords);
        }

        /// <summary>Activity of a quantity of radioactive material in which one million nuclei decay per second.</summary>
        [[nodiscard]] static constexpr Radioactivity from_terarutherfords(const un_scalar_t value)
        {
            return Radioactivity(value, RadioactivityUnit::Terarutherfords);
        }


        [[nodiscard]] static constexpr Radioactivity from_invalid()
        {
            return Radioactivity(false);
        }
    private:
            
        [[nodiscard]] static constexpr un_scalar_t convert_to_base(un_scalar_t value, RadioactivityUnit unit)
        {
            switch (unit)
            {

            case RadioactivityUnit::Becquerels:
                return value;

            case RadioactivityUnit::Picobecquerels:
                return (value * static_cast<un_scalar_t>(1e-12));

            case RadioactivityUnit::Nanobecquerels:
                return (value * static_cast<un_scalar_t>(1e-9));

            case RadioactivityUnit::Microbecquerels:
                return (value * static_cast<un_scalar_t>(1e-6));

            case RadioactivityUnit::Millibecquerels:
                return (value * static_cast<un_scalar_t>(1e-3));

            case RadioactivityUnit::Kilobecquerels:
                return (value * static_cast<un_scalar_t>(1e3));

            case RadioactivityUnit::Megabecquerels:
                return (value * static_cast<un_scalar_t>(1e6));

            case RadioactivityUnit::Gigabecquerels:
                return (value * static_cast<un_scalar_t>(1e9));

            case RadioactivityUnit::Terabecquerels:
                return (value * static_cast<un_scalar_t>(1e12));

            case RadioactivityUnit::Petabecquerels:
                return (value * static_cast<un_scalar_t>(1e15));

            case RadioactivityUnit::Exabecquerels:
                return (value * static_cast<un_scalar_t>(1e18));

            case RadioactivityUnit::Curies:
                return value * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Picocuries:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Nanocuries:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Microcuries:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Millicuries:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Kilocuries:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Megacuries:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Gigacuries:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Teracuries:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Rutherfords:
                return value * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Picorutherfords:
                return (value * static_cast<un_scalar_t>(1e-12)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Nanorutherfords:
                return (value * static_cast<un_scalar_t>(1e-9)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Microrutherfords:
                return (value * static_cast<un_scalar_t>(1e-6)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Millirutherfords:
                return (value * static_cast<un_scalar_t>(1e-3)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Kilorutherfords:
                return (value * static_cast<un_scalar_t>(1e3)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Megarutherfords:
                return (value * static_cast<un_scalar_t>(1e6)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigarutherfords:
                return (value * static_cast<un_scalar_t>(1e9)) * static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Terarutherfords:
                return (value * static_cast<un_scalar_t>(1e12)) * static_cast<un_scalar_t>(1e6);

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        [[nodiscard]] constexpr un_scalar_t convert_from_base(const RadioactivityUnit unit) const
        {
            if(unit == value_unit_type_)
            {
                return value_;
            }
            
            create_base_value_if_needed();
            
            switch (unit)
            {

            case RadioactivityUnit::Becquerels:
                return base_value_;

            case RadioactivityUnit::Picobecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanobecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microbecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millibecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilobecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megabecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigabecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Terabecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e12);

            case RadioactivityUnit::Petabecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e15);

            case RadioactivityUnit::Exabecquerels:
                return (base_value_) / static_cast<un_scalar_t>(1e18);

            case RadioactivityUnit::Curies:
                return base_value_ / static_cast<un_scalar_t>(3.7e10);

            case RadioactivityUnit::Picocuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanocuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microcuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millicuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilocuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megacuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigacuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Teracuries:
                return (base_value_ / static_cast<un_scalar_t>(3.7e10)) / static_cast<un_scalar_t>(1e12);

            case RadioactivityUnit::Rutherfords:
                return base_value_ / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Picorutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-12);

            case RadioactivityUnit::Nanorutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-9);

            case RadioactivityUnit::Microrutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-6);

            case RadioactivityUnit::Millirutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e-3);

            case RadioactivityUnit::Kilorutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e3);

            case RadioactivityUnit::Megarutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e6);

            case RadioactivityUnit::Gigarutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e9);

            case RadioactivityUnit::Terarutherfords:
                return (base_value_ / static_cast<un_scalar_t>(1e6)) / static_cast<un_scalar_t>(1e12);

            }

            throw std::invalid_argument("Unknown Radioactivity unit.");
        }

        un_scalar_t value_;
        RadioactivityUnit value_unit_type_;
        mutable un_scalar_t base_value_;
        mutable bool base_value_exists_ = false;
       
    };
}
