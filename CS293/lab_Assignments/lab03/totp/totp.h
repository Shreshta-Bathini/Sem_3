#ifndef TOTP_H
#define TOTP_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <sstream>
#include <iomanip>

// --- Function Declarations ---

/**
 * @brief Computes the SHA-1 hash of a given message.
 * @param message The input message as a vector of bytes.
 * @return A 20-byte vector representing the SHA-1 digest.
 */
std::vector<uint8_t> sha1(const std::vector<uint8_t>& message);

/**
 * @brief Computes the HMAC-SHA1 of a message.
 * @param key The secret key.
 * @param msg The message to authenticate.
 * @return A 20-byte vector representing the HMAC-SHA1 digest.
 */
std::vector<uint8_t> hmac_sha1(std::vector<uint8_t> key, const std::vector<uint8_t>& msg);

/**
 * @brief Generates a 6-digit T-OTP code.
 * @param secret_key_str The shared secret key as an ASCII string.
 * @param time_step The time-step value (T).
 * @return A 6-digit T-OTP code as a string.
 */
std::string generate_totp(const std::string& secret_key_str, uint64_t time_step);
#endif