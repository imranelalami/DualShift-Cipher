# DualShift Cipher  

## 🔹 Overview  
DualShift Cipher is a **custom encryption algorithm** that combines:  
1. **Atbash Cipher** (letter mirroring)  
2. **Fixed shifting** (+3 shift for all letters)  
3. **Position-based shifting** (index-dependent shift)  

This makes it **stronger than simple ciphers like Caesar or Atbash alone** while remaining fully reversible.

## 🔹 How It Works  

### **Encryption Steps**  
1. **Atbash Transformation** → Flips each letter to its opposite (A ↔ Z, B ↔ Y, etc.).  
2. **Fixed Shift (+3)** → Adds 3 to each flipped letter.  
3. **Position-Based Shift** → Each letter is shifted **further by (3 + i % 5)**, where `i` is the character’s index.  

### **Decryption Steps**  
1. **Subtract position-based shift `(3 + i % 5)`**  
2. **Subtract the fixed shift (+3)**  
3. **Apply Atbash again** to restore the original text.  

## 🔹 Example  
```sh
$ ./dualshift "HELLO"
Encrypted: XXXXXX   # (Example output)

$ ./dualshift "XXXXXX"
Decrypted: HELLO
