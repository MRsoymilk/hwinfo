// Copyright Leon Freist
// Author Leon Freist <freist@informatik.uni-freiburg.de>

#include "hwinfo/platform.h"

#ifdef HWINFO_UNIX

#include <fstream>

#include "hwinfo/battery.h"

namespace hwinfo {

static std::string base_path = "/sys/class/power_supply/";

// =====================================================================================================================
// _____________________________________________________________________________________________________________________
std::string Battery::getVendor() {
  if (_id < 0) {
    return "<unknown>";
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "manufacturer");
  std::string vendor;
  if (vendor_file.is_open()) {
    getline(vendor_file, vendor);
    return vendor;
  }
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string Battery::getModel() {
  if (_id < 0) {
    return "<unknown>";
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "model_name");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return value;
  }
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string Battery::getSerialNumber() {
  if (_id < 0) {
    return "<unknown>";
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "serial_number");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return value;
  }
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
std::string Battery::getTechnology() {
  if (_id < 0) {
    return "<unknown>";
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "technology");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return value;
  }
  return "<unknown>";
}

// _____________________________________________________________________________________________________________________
uint32_t Battery::getEnergyFull() {
  if (_id < 0) {
    return 0;
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "energy_full");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return std::stoi(value);
  }
  return 0;
}

// _____________________________________________________________________________________________________________________
uint32_t Battery::energyNow() {
  if (_id < 0) {
    return 0;
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "energy_now");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return std::stoi(value);
  }
  return 0;
}

// _____________________________________________________________________________________________________________________
bool Battery::charging() {
  if (_id < 0) {
    return false;
  }
  std::ifstream vendor_file(base_path + "BAT" + std::to_string(_id) + "/" + "status");
  std::string value;
  if (vendor_file.is_open()) {
    getline(vendor_file, value);
    return value == "Charging";
  }
  return false;
}

// _____________________________________________________________________________________________________________________
bool Battery::discharging() {
  return !charging();
}

// =====================================================================================================================
// _____________________________________________________________________________________________________________________
std::optional<Battery> getAllBatteries() {
  // TODO: implement
  return {};
}

}  // namespace hwinfo

#endif