#include <bearssl/bearssl.h>  // BearSSL library for HMAC functions

class HAMC_SHA256 {
    public: 
        /// @brief get hmac hash of a message and secret key using HMAC-SHA-256 algorithm 
        /// @param message message to be used in hashing
        /// @param secretKey secretkey to be used in hashing
        /// @return String containing the HMAC hash in lowercase hexadecimal format
        String GET_HMAC_SHA_256_HASH(const String message, const char* secretKey) {
            uint8_t hmacResult[32];
            hmacSHA256((const uint8_t*)secretKey, strlen(secretKey), (const uint8_t*)message.c_str(), message.length(), hmacResult);

            // Convert the HMAC result to an uppercase hexadecimal string
            String hashHex;
            for (int i = 0; i < 32; i++) {
                if (hmacResult[i] < 16) hashHex += "0";  // Zero-padding for single hex digits
                hashHex += String(hmacResult[i], HEX);
            }
            return hashHex;
        }

    private:
        ///@brief get hmac hash of a message using HMAC-SHA-256 algorithm
        ///@param key Key for HMAC calculation
        ///@param keyLength Length of the key
        ///@param message Message used for HMAC calculation
        ///@param messageLength Length of the message
        ///@param output Output buffer for the HMAC result
        ///@note This function should only be called by GET_HMAC_SHA_256_HASH function
        void hmacSHA256(const uint8_t* key, size_t keyLength, const uint8_t* message, size_t messageLength, uint8_t* output) {
            br_hmac_key_context keyContext;
            br_hmac_context hmacContext;

            // Initialize HMAC with SHA-256
            br_hmac_key_init(&keyContext, &br_sha256_vtable, key, keyLength);
            br_hmac_init(&hmacContext, &keyContext, 0);

            // Update HMAC with the message
            br_hmac_update(&hmacContext, message, messageLength);

            // Output the HMAC result
            br_hmac_out(&hmacContext, output);
        }
};
