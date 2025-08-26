#include "totp.h"
#include "common.h"
// --- Helper Functions ---

// Performs a circular left shift on a 32-bit integer.
uint32_t rotate_left(uint32_t value, size_t count) {
    return (value << count) | (value >> (32 - count));
}

// Converts a 32-bit integer from host byte order to big-endian.
// On little-endian systems (most common), this will swap the byte order.
// On big-endian systems, this will do nothing.
uint32_t to_big_endian(uint32_t value) {
    uint8_t bytes[4];
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

// --- Part 1: SHA-1 Implementation ---

/**
 * @brief Computes the SHA-1 hash of a given message.
 * @param message The input message as a vector of bytes.
 * @return A 20-byte vector representing the SHA-1 digest.
 */
std::vector<uint8_t> sha1(const std::vector<uint8_t>& message) {
    // STUDENT IMPLEMENTATION - PART 1
    // Follow the steps of the SHA-1 algorithm:

    // 1. Initialize variables (the five 32-bit H registers)
    //    h0 = 0x67452301, h1 = 0xEFCDAB89, etc.

    // 2. Pre-processing (Padding):
    //    a. Start with the original message.
    //    b. Append the bit '1' (which is the byte 0x80).
    //    c. Append '0' bits (0x00 bytes) until the message length in bits is
    //       congruent to 448 (mod 512). This means the length in bytes should be
    //       congruent to 56 (mod 64).
    //    d. Append the original message length (in bits) as a 64-bit big-endian integer.

    // 3. Process the message in successive 512-bit (64-byte) chunks:
    //    For each chunk:
    //    a. Break the chunk into sixteen 32-bit big-endian words w[0] to w[15].
    //    b. Extend the sixteen 32-bit words into eighty 32-bit words (w[16] to w[79]):
    //       w[i] = rotate_left(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1)
    //    c. Initialize hash value for this chunk (a, b, c, d, e = h0, h1, h2, h3, h4).
    //    d. Main loop (80 rounds):
    //       - Calculate f and k based on the round number (i).
    //       - Calculate: temp = rotate_left(a, 5) + f + e + k + w[i]
    //       - Update variables: e = d, d = c, c = rotate_left(b, 30), b = a, a = temp
    //    e. Add this chunk's hash to the result so far (h0 += a, h1 += b, etc.).

    // 4. Produce the final hash value:
    //    Concatenate the 32-bit h values (h0, h1, h2, h3, h4) in big-endian format.
    //    The result should be a 20-byte vector.

    // Return a vector of the correct size to allow the program to compile.
    return std::vector<uint8_t>(20, 0);
}


// --- Part 2: HMAC-SHA1 Implementation ---

/**
 * @brief Computes the HMAC-SHA1 of a message.
 * @param key The secret key.
 * @param msg The message to authenticate.
 * @return A 20-byte vector representing the HMAC-SHA1 digest.
 */
std::vector<uint8_t> hmac_sha1(std::vector<uint8_t> key, const std::vector<uint8_t>& msg) {
    // STUDENT IMPLEMENTATION - PART 2
    // Follow the steps of the HMAC algorithm:

    /* Uncomment line below for you implementation */
    // const size_t block_size = 64; // Block size for SHA-1

    // 1. Adjust the key size:
    //    a. If the key is longer than the block size, hash the key with SHA-1.
    //    b. If the key is shorter than the block size, pad it with 0x00 bytes to the right.

    // 2. Create o_key_pad and i_key_pad:
    //    - o_key_pad = key XOR 0x5C (repeated for the block size)
    //    - i_key_pad = key XOR 0x36 (repeated for the block size)

    // 3. Perform the inner hash:
    //    - hash(i_key_pad + message)
    //    - The '+' here means concatenation.

    // 4. Perform the outer hash:
    //    - hash(o_key_pad + inner_hash_result)
    //    - This is the final HMAC result.

    // Return a vector of the correct size to allow the program to compile.
    return std::vector<uint8_t>(20, 0);
}


// --- Part 3: T-OTP Implementation ---

/**
 * @brief Generates a 6-digit T-OTP code.
 * @param secret_key_str The shared secret key as an ASCII string.
 * @param time_step The time-step value (T).
 * @return A 6-digit T-OTP code as a string.
 */
std::string generate_totp(const std::string& secret_key_str, uint64_t time_step) {
    // STUDENT IMPLEMENTATION - PART 3
    // Follow the steps of the TOTP algorithm:

    // 1. Convert inputs to byte vectors:
    //    a. Convert the secret_key_str to a vector of bytes.
    //    b. Convert the 64-bit time_step to a big-endian 8-byte vector.

    // 2. Compute the HMAC-SHA1 hash using the secret key and the time step bytes.
    //    - Call the hmac_sha1 function you implemented in Part 2.

    // 3. Dynamic Truncation:
    //    a. Get the last byte of the HMAC hash.
    //    b. Get the last 4 bits of this byte: offset = hash.back() & 0x0F.
    //    c. Use this offset to find a 4-byte slice in the hash.
    //    d. Combine these 4 bytes into a 32-bit integer.
    //    e. Remove the most significant bit: truncated_hash = combined_bytes & 0x7FFFFFFF.

    // 4. Compute the 6-digit OTP:
    //    - otp_code = truncated_hash % 1000000

    // 5. Format the code as a 6-digit string (with leading zeros if necessary).
    //    - Use std::stringstream, std::setw, and std::setfill.

    // Return a string of the correct format to allow the program to compile.
    return "000000";
}




