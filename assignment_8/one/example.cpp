#include <iomanip>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <sstream>
#include <string>
#include <iostream>

// Note: C-style casts, for instance (int), are used to simplify the source code.
//       C++ casts, such as static_cast and reinterpret_cast, should otherwise
//       be used in modern C++.

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/// Limited C++ bindings for the OpenSSL Crypto functions.
class Crypto {
public:
    /// Return hex string from bytes in input string.
    static std::string hex(const std::string &input) {
        std::stringstream hex_stream;
        hex_stream << std::hex << std::internal << std::setfill('0');
        for (auto &byte : input)
            hex_stream << std::setw(2) << (int) (unsigned char) byte;
        return hex_stream.str();
    }

    /// Return key from the Password-Based Key Derivation Function 2 (PBKDF2).
    static std::string
    pbkdf2(const std::string &password, const std::string &salt, int iterations = 4096, int key_length_in_bits = 256) {
        auto key_length_in_bytes = key_length_in_bits / 8;
        std::string key;
        key.resize(key_length_in_bytes);
        auto success = PKCS5_PBKDF2_HMAC_SHA1(password.data(), password.size(),
                                              (const unsigned char *) salt.data(), salt.size(), iterations,
                                              key_length_in_bytes, (unsigned char *) key.data());
        if (!success)
            throw std::runtime_error("openssl: error calling PBKCS5_PBKDF2_HMAC_SHA1");
        return key;
    }

    static void cracker(const std::string &password, const std::string &hash, const std::string &salt, size_t size = 1, size_t position = 0) {

        if (position < size) {
            for (char ch : alphabet) {
                cracker(password + ch, hash, salt, size, position + 1);
            }
        } else {
            std::cout << password << std::endl;
            std::string wow = hex(pbkdf2(password, salt, 2048, 160));
            if (wow == hash) {
                std::cout << "Password found!: "<< password << std::endl;
                exit(0);
            }
        }
    }

};




int main() {

    std::string hash_to_crack = "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6";
    std::string hash_salt = "Saltet til Ola";
    std::string password;

    size_t size = 3;
    size_t max_size = 5;

    do {
    Crypto::cracker(password, hash_to_crack, hash_salt, size);
        size++;
    } while(size < max_size);

    return 0;
}